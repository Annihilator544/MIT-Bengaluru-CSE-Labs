#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CL/cl.h>

#define M 5 // Number of connected routers
#define N 10 // Number of devices per router
#define IP_SIZE 16 // Size of IP address string including null terminator

const char *kernelSource = "\
__kernel void forwardPacket(__global int *forwardTable, __global const char *packetIP, __global int *destRouter) {\n\
    int routerIndex = get_global_id(0);\n\
    int packetLastOctet = atoi(&packetIP[12]);\n\
    for (int i = 0; i < N; ++i) {\n\
        if (forwardTable[routerIndex * N + i] == packetLastOctet) {\n\
            destRouter[0] = routerIndex;\n\
            break;\n\
        }\n\
    }\n\
}\n";

int main() {
    cl_int err;

    // Initialize the OpenCL environment
    cl_platform_id platformId = NULL;
    cl_device_id deviceID = NULL;
    cl_uint retNumDevices;
    cl_uint retNumPlatforms;
    err = clGetPlatformIDs(1, &platformId, &retNumPlatforms);
    err = clGetDeviceIDs(platformId, CL_DEVICE_TYPE_GPU, 1, &deviceID, &retNumDevices);
    cl_context context = clCreateContext(NULL, 1, &deviceID, NULL, NULL, &err);
    cl_command_queue commandQueue = clCreateCommandQueueWithProperties(context, deviceID, NULL, &err);

    // Initialize forward table and packet IP
    int forwardTable[M][N];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            forwardTable[i][j] = rand() % 256; // Random last octet (0-255)
        }
    }
    char packetIP[IP_SIZE];
    snprintf(packetIP, IP_SIZE, "192.168.1.%d", rand() % 256); // Random packet IP address

    // Create memory buffers on the device
    cl_mem forwardTableMemObj = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, M * N * sizeof(int), forwardTable, &err);
    cl_mem packetIPMemObj = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, IP_SIZE * sizeof(char), packetIP, &err);
    cl_mem destRouterMemObj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int), NULL, &err);

    // Create a program from the kernel source
    cl_program program = clCreateProgramWithSource(context, 1, (const char **)&kernelSource, NULL, &err);
    err = clBuildProgram(program, 1, &deviceID, NULL, NULL, NULL);

    // Create the OpenCL kernel
    cl_kernel kernel = clCreateKernel(program, "forwardPacket", &err);

    // Set the arguments of the kernel
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&forwardTableMemObj);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&packetIPMemObj);
    err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&destRouterMemObj);

    // Execute the OpenCL kernel on the list
    size_t globalSize = M;
    err = clEnqueueNDRangeKernel(commandQueue, kernel, 1, NULL, &globalSize, NULL, 0, NULL, NULL);

    // Read the memory buffer destRouterMemObj on the device to the local variable destRouter
    int destRouter;
    err = clEnqueueReadBuffer(commandQueue, destRouterMemObj, CL_TRUE, 0, sizeof(int), &destRouter, 0, NULL, NULL);

    // Display the result
    printf("Packet with IP address %s should be forwarded to router %d\n", packetIP, destRouter);

    // Clean up
    clReleaseMemObject(forwardTableMemObj);
    clReleaseMemObject(packetIPMemObj);
    clReleaseMemObject(destRouterMemObj);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(commandQueue);
    clReleaseContext(context);

    return 0;
}
