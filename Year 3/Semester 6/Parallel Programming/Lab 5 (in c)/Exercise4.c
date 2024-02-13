#define CL_TARGET_OPENCL_VERSION 300
#include <CL/cl.h>
#include <stdio.h>

// Define the input array size
#define N 10
// Input data (example values)
int inputArray[N] = {1010, 1100, 1111, 1001, 1011, 1101, 1110, 1000, 1010, 1100};

int main() {
    // Initialize OpenCL
    cl_platform_id platform;
    clGetPlatformIDs(1, &platform, NULL);

    cl_device_id device;
    clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);

    cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, NULL);
    cl_command_queue queue = clCreateCommandQueueWithProperties(context, device, NULL, NULL);

    // Create buffers for input and output arrays
    cl_mem inputBuffer = clCreateBuffer(context, CL_MEM_READ_ONLY, N * sizeof(int), NULL, NULL);
    cl_mem outputBuffer = clCreateBuffer(context, CL_MEM_WRITE_ONLY, N * sizeof(int), NULL, NULL);

    // Load and compile the OpenCL kernel
    const char* kernelSource = "__kernel void binaryToDecimal(__global const int* input, __global int* output) {\n"
                              "    int gid = get_global_id(0);\n"
                              "    int binary = input[gid];\n"
                              "    int decimal = 0, base = 1, rem;\n"
                              "    while (binary > 0) {\n"
                              "        rem = binary % 10;\n"
                              "        decimal = decimal + rem * base;\n"
                              "        binary = binary / 10 ;\n"
                              "        base = base * 2;\n"
                              "    }\n"
                              "    output[gid] = decimal;\n"
                              "}\n";

    cl_program program = clCreateProgramWithSource(context, 1, &kernelSource, NULL, NULL);
    clBuildProgram(program, 1, &device, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(program, "binaryToDecimal", NULL);

    // Set kernel arguments
    clSetKernelArg(kernel, 0, sizeof(cl_mem), &inputBuffer);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), &outputBuffer);

    // Write input data to the input buffer
    clEnqueueWriteBuffer(queue, inputBuffer, CL_TRUE, 0, N * sizeof(int), inputArray, 0, NULL, NULL);

    // Execute the kernel
    size_t globalSize = N;
    clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, NULL, 0, NULL, NULL);
    clFinish(queue);

    // Read the results back to the host
    int outputArray[N];
    clEnqueueReadBuffer(queue, outputBuffer, CL_TRUE, 0, N * sizeof(int), outputArray, 0, NULL, NULL);

    // Print the decimal values
    printf("Decimal values:\n");
    for (int i = 0; i < N; ++i) {
        printf("%d (Binary) -> %d (Decimal)\n", inputArray[i], outputArray[i]);
    }

    // Cleanup
    clReleaseMemObject(inputBuffer);
    clReleaseMemObject(outputBuffer);
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    return 0;
}
