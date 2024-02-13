
#define CL_TARGET_OPENCL_VERSION 300
#include <CL/cl.h>
#include <stdio.h>

// Define the input array size
#define N 10
// Input data (example values)
int inputArray[N] = {123, 456, 789, 101, 202, 303, 404, 505, 606, 707};

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
    const char* kernelSource = "__kernel void convertToOctal(__global const int* input, __global int* output) {\n"
                          "    int gid = get_global_id(0);\n"
                          "    int decimal = input[gid];\n"
                          "    int octal = 0, ctr = 0, temp;\n"
                          "    while (decimal != 0) {\n"
                          "        temp = decimal % 8;\n"
                          "        decimal /= 8;\n"
                          "        int pow=1;\n"
                          "        for(int i=1; i<=ctr;i++){\n"
                          "        pow*=10;\n"
                          "        }\n"
                          "        octal += temp * pow;\n"
                          "        ctr++;\n"
                          "    }\n"
                          "    output[gid] = octal;\n"
                          "}\n";


    cl_program program = clCreateProgramWithSource(context, 1, &kernelSource, NULL, NULL);
    clBuildProgram(program, 1, &device, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(program, "convertToOctal", NULL);

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

    // Print the octal values
    printf("Octal values:\n");
    for (int i = 0; i < N; ++i) {
        printf("%d (Decimal) -> %o (Octal)\n", inputArray[i], outputArray[i]);
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
