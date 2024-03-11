#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

#define N 100

const char *kernelSource = "\
__kernel void primeCheck(__global int *A, __global int *B) {\n\
    int idx = get_global_id(0);\n\
    int number = A[idx];\n\
    int isPrime = 1;\n\
    for (int i = 2; i <= number / 2; ++i) {\n\
        if (number % i == 0) {\n\
            isPrime = 0;\n\
            break;\n\
        }\n\
    }\n\
    if (isPrime) {\n\
        B[idx] = number;\n\
    } else {\n\
        B[idx] = number * number;\n\
    }\n\
}\n";

int main() {
    int A[N], B[N];
    cl_int err;

    // Initialize A with random numbers
    for (int i = 0; i < N; ++i) {
        A[i] = rand() % 1000; // Generate random integers between 0 and 999
    }

    // Get platform and device information
    cl_platform_id platformId = NULL;
    cl_device_id deviceID = NULL;
    cl_uint retNumDevices;
    cl_uint retNumPlatforms;
    cl_int ret = clGetPlatformIDs(1, &platformId, &retNumPlatforms);
    ret = clGetDeviceIDs(platformId, CL_DEVICE_TYPE_GPU, 1, &deviceID, &retNumDevices);

    // Create an OpenCL context
    cl_context context = clCreateContext(NULL, 1, &deviceID, NULL, NULL, &err);

    // Create a command queue
    cl_command_queue commandQueue = clCreateCommandQueueWithProperties(context, deviceID, NULL, &err);

    // Create memory buffers on the device for each array
    cl_mem aMemObj = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, N * sizeof(int), A, &err);
    cl_mem bMemObj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, N * sizeof(int), NULL, &err);

    // Create a program from the kernel source
    cl_program program = clCreateProgramWithSource(context, 1, (const char **)&kernelSource, NULL, &err);

    // Build the program
    err = clBuildProgram(program, 1, &deviceID, NULL, NULL, NULL);

    // Create the OpenCL kernel
    cl_kernel kernel = clCreateKernel(program, "primeCheck", &err);

    // Set the arguments of the kernel
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&aMemObj);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&bMemObj);

    // Execute the OpenCL kernel on the list
    size_t globalSize = N; // Process the entire array
    err = clEnqueueNDRangeKernel(commandQueue, kernel, 1, NULL, &globalSize, NULL, 0, NULL, NULL);

    // Read the memory buffer B on the device to the local variable B
    err = clEnqueueReadBuffer(commandQueue, bMemObj, CL_TRUE, 0, N * sizeof(int), B, 0, NULL, NULL);

    // Display the result
    printf("Results:\n");
    for (int i = 0; i < N; ++i) {
        printf("%d ", B[i]);
    }
    printf("\n");

    // Clean up
    clReleaseMemObject(aMemObj);
    clReleaseMemObject(bMemObj);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(commandQueue);
    clReleaseContext(context);

    return 0;
}
