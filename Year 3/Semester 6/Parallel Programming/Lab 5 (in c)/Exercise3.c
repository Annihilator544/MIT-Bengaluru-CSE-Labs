#define CL_TARGET_OPENCL_VERSION 300
#include <CL/cl.h>
#include <stdio.h>

// Define the input array size
#define N 10
// Input data (example values)
int inputArray[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    // Initialize OpenCL
    cl_platform_id platform;
    clGetPlatformIDs(1, &platform, NULL);

    cl_device_id device;
    clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);

    cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, NULL);
    cl_command_queue queue = clCreateCommandQueueWithProperties(context, device, NULL, NULL);

    // Create buffers for the array
    cl_mem buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, N * sizeof(int), NULL, NULL);

    // Load and compile the OpenCL kernel
    const char* kernelSource = "__kernel void swapAdjacent(__global int* arr) {\n"
                              "    int gid = get_global_id(0);\n"
                              "    if(gid % 2 == 0) {\n"
                              "        int temp = arr[gid];\n"
                              "        arr[gid] = arr[gid + 1];\n"
                              "        arr[gid + 1] = temp;\n"
                              "    }\n"
                              "}\n";

    cl_program program = clCreateProgramWithSource(context, 1, &kernelSource, NULL, NULL);
    clBuildProgram(program, 1, &device, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(program, "swapAdjacent", NULL);

    // Set kernel arguments
    clSetKernelArg(kernel, 0, sizeof(cl_mem), &buffer);

    // Write input data to the buffer
    clEnqueueWriteBuffer(queue, buffer, CL_TRUE, 0, N * sizeof(int), inputArray, 0, NULL, NULL);

    // Execute the kernel
    size_t globalSize = N;
    clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, NULL, 0, NULL, NULL);
    clFinish(queue);

    // Read the results back to the host
    int outputArray[N];
    clEnqueueReadBuffer(queue, buffer, CL_TRUE, 0, N * sizeof(int), outputArray, 0, NULL, NULL);

    // Print the swapped values
    printf("Swapped values:\n");
    for (int i = 0; i < N; ++i) {
        printf("%d ", outputArray[i]);
    }
    printf("\n");

    // Cleanup
    clReleaseMemObject(buffer);
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    return 0;
}
