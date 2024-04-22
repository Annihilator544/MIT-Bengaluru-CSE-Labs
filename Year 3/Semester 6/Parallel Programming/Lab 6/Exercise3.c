#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

#define N 10

const char *kernelSource1 = 
"__kernel void oddSort(__global int* arr, const int n)\n"
"{\n"
"    int i = get_global_id(0);\n"
"    if ((i % 2 == 1) && (i < n - 1))\n"
"    {\n"
"        if (arr[i] > arr[i + 1])\n"
"        {\n"
"            int temp = arr[i];\n"
"            arr[i] = arr[i + 1];\n"
"            arr[i + 1] = temp;\n"
"        }\n"
"    }\n"
"}\n";

const char *kernelSource2 = 
"__kernel void evenSort(__global int* arr, const int n)\n"
"{\n"
"    int i = get_global_id(0);\n"
"    if ((i % 2 == 0) && (i < n - 1))\n"
"    {\n"
"        if (arr[i] > arr[i + 1])\n"
"        {\n"
"            int temp = arr[i];\n"
"            arr[i] = arr[i + 1];\n"
"            arr[i + 1] = temp;\n"
"        }\n"
"    }\n"
"}\n";

int main()
{
    cl_int err;

    // Create an OpenCL context
    cl_context context = clCreateContext(NULL, 1, NULL, NULL, NULL, &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating OpenCL context\n");
        return 1;
    }

    // Create a command queue
    cl_command_queue queue = clCreateCommandQueue(context, NULL, 0, &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating command queue\n");
        return 1;
    }

    // Create memory buffers on the device
    cl_mem buffer = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int) * N, NULL, &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating buffer\n");
        return 1;
    }

    // Initialize input data
    int arr[N] = {5, 2, 7, 3, 9, 1, 8, 4, 6, 0};

    // Write data to the buffer
    err = clEnqueueWriteBuffer(queue, buffer, CL_TRUE, 0, sizeof(int) * N, arr, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error writing to buffer\n");
        return 1;
    }

    // Create OpenCL programs from source code
    cl_program program1 = clCreateProgramWithSource(context, 1, &kernelSource1, NULL, &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating program1\n");
        return 1;
    }

    cl_program program2 = clCreateProgramWithSource(context, 1, &kernelSource2, NULL, &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating program2\n");
        return 1;
    }

    // Build the programs
    err = clBuildProgram(program1, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error building program1\n");
        return 1;
    }

    err = clBuildProgram(program2, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error building program2\n");
        return 1;
    }

    // Create OpenCL kernels
    cl_kernel kernel1 = clCreateKernel(program1, "oddSort", &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating kernel1\n");
        return 1;
    }

    cl_kernel kernel2 = clCreateKernel(program2, "evenSort", &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating kernel2\n");
        return 1;
    }

    // Set kernel arguments
    err = clSetKernelArg(kernel1, 0, sizeof(cl_mem), &buffer);
    err |= clSetKernelArg(kernel1, 1, sizeof(int), &N);
    if (err != CL_SUCCESS)
    {
        printf("Error setting kernel1 arguments\n");
        return 1;
    }

    err = clSetKernelArg(kernel2, 0, sizeof(cl_mem), &buffer);
    err |= clSetKernelArg(kernel2, 1, sizeof(int), &N);
    if (err != CL_SUCCESS)
    {
        printf("Error setting kernel2 arguments\n");
        return 1;
    }

    // Execute the kernels
    size_t globalSize = N;
    err = clEnqueueNDRangeKernel(queue, kernel1, 1, NULL, &globalSize, NULL, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error executing kernel1\n");
        return 1;
    }

    err = clEnqueueNDRangeKernel(queue, kernel2, 1, NULL, &globalSize, NULL, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error executing kernel2\n");
        return 1;
    }

    // Read the result buffer back to host memory
    err = clEnqueueReadBuffer(queue, buffer, CL_TRUE, 0, sizeof(int) * N, arr, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error reading buffer\n");
        return 1;
    }

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Release OpenCL resources
    clReleaseMemObject(buffer);
    clReleaseKernel(kernel1);
    clReleaseKernel(kernel2);
    clReleaseProgram(program1);
    clReleaseProgram(program2);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    return 0;
}
