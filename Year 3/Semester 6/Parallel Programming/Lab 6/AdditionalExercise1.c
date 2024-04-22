#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CL/cl.h>

#define MAX_SOURCE_SIZE (0x100000)

const char *kernelSource = 
"__kernel void repeatString(__global const char *input_string, const int N, __global char *output_string) {\n"
"    int index = get_global_id(0);\n"
"    int str_length = strlen(input_string);\n"
"    for (int i = 0; i < N; i++) {\n"
"        for (int j = 0; j < str_length; j++) {\n"
"            output_string[index * str_length + i * str_length + j] = input_string[j];\n"
"        }\n"
"    }\n"
"}\n";

int main() {
    // Get user input for string and repetition count
    char str[100];
    int N;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character from input
    printf("Enter number of repetitionns: ");
    scanf("%d", &N);
    printf("Output String:\n");
	for(int i=0;i<N;i++){
    printf("%s", str);
}
printf("\n");

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

    // Create memory buffers on the device for each string
    cl_mem mem_str = clCreateBuffer(context, CL_MEM_READ_ONLY,
                                     strlen(str) * sizeof(char), NULL, &ret);
    cl_mem mem_output = clCreateBuffer(context, CL_MEM_WRITE_ONLY,
                                        N * strlen(str) * sizeof(char), NULL, &ret);

    // Copy the string to their respective memory buffers
    ret = clEnqueueWriteBuffer(command_queue, mem_str, CL_TRUE, 0,
                               strlen(str) * sizeof(char), str, 0, NULL, NULL);

    // Create a program from the kernel source
    cl_program program = clCreateProgramWithSource(context, 1,
                                                    &kernelSource, NULL, &ret);

    // Build the program
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    // Create the OpenCL kernel
    cl_kernel kernel = clCreateKernel(program, "repeatString", &ret);

    // Set the arguments of the kernel
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&mem_str);
    ret = clSetKernelArg(kernel, 1, sizeof(cl_int), (void *)&N);
    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&mem_output);

    // Execute the OpenCL kernel on the list
    size_t global_item_size = N; // Process the entire string N times
    size_t local_item_size = 1;  // Process one string per work item
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL,
                                 &global_item_size, &local_item_size, 0, NULL, NULL);

    // Read the memory buffer output_string on the device to the local variable output_string
    char *output_string = (char *)malloc(N * strlen(str) * sizeof(char));
    ret = clEnqueueReadBuffer(command_queue, mem_output, CL_TRUE, 0,
                              N * strlen(str) * sizeof(char), output_string, 0, NULL, NULL);

// Output the result
   // printf("Output String: %s\n", output_string);

    // Clean up
    ret = clFlush(command_queue);
    ret = clFinish(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(mem_str);
    ret = clReleaseMemObject(mem_output);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);
    free(output_string);
    return 0;
}
