#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

#define MAX_SOURCE_SIZE (0x100000)

const char *kernelSource = 
"__kernel void selectionSort(__global int *arr, const int size) {\n"
"    int i, j, min_idx;\n"
"    for (i = 0; i < size - 1; i++) {\n"
"        min_idx = i;\n"
"        for (j = i + 1; j < size; j++) {\n"
"            if (arr[j] < arr[min_idx]) {\n"
"                min_idx = j;\n"
"            }\n"
"        }\n"
"        if (min_idx != i) {\n"
"            int temp = arr[min_idx];\n"
"            arr[min_idx] = arr[i];\n"
"            arr[i] = temp;\n"
"        }\n"
"    }\n"
"}\n";

int main() {
    // Define the array to be sorted
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Get platform and device information
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;
    cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1,
                         &device_id, &ret_num_devices);

    // Create an OpenCL context
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

    // Create a command queue
    cl_command_queue command_queue = clCreateCommandQueueWithProperties(context, device_id, NULL, &ret);

    // Create memory buffers on the device for the input and output arrays
    cl_mem mem_arr = clCreateBuffer(context, CL_MEM_READ_WRITE,
                                     size * sizeof(int), NULL, &ret);

    // Copy the array to the memory buffer
    ret = clEnqueueWriteBuffer(command_queue, mem_arr, CL_TRUE, 0,
                               size * sizeof(int), arr, 0, NULL, NULL);

    // Create a program from the kernel source
    cl_program program = clCreateProgramWithSource(context, 1,
                                                    &kernelSource, NULL, &ret);

    // Build the program
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    // Create the OpenCL kernel
    cl_kernel kernel = clCreateKernel(program, "selectionSort", &ret);

    // Set the arguments of the kernel
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&mem_arr);
    ret = clSetKernelArg(kernel, 1, sizeof(int), (void *)&size);

    // Execute the OpenCL kernel
    size_t global_item_size = size; // Process the entire array
    size_t local_item_size = 1;     // Process one element per work item
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL,
                                 &global_item_size, &local_item_size, 0, NULL, NULL);

    // Read the memory buffer back to the host
    ret = clEnqueueReadBuffer(command_queue, mem_arr, CL_TRUE, 0,
                              size * sizeof(int), arr, 0, NULL, NULL);

    // Output the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Clean up
    ret = clFlush(command_queue);
    ret = clFinish(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(mem_arr);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);
    return 0;
}
