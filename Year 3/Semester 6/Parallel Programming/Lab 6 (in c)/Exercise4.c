#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CL/cl.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

const char *kernelSource =
"__kernel void reverseWords(__global char* input, __global char* output, const int wordCount, const int maxWordLength)\n"
"{\n"
"    int wordIndex = get_global_id(0);\n"
"    int startIndex = wordIndex * (maxWordLength + 1);\n"
"    int endIndex = startIndex + maxWordLength;\n"
"    for (int i = 0; i < maxWordLength; i++)\n"
"    {\n"
"        output[endIndex - i - 1] = input[startIndex + i];\n"
"    }\n"
"    output[endIndex] = '\\0';\n"
"}\n";

int main()
{
    cl_int err;

    // OpenCL platform and device information
    cl_platform_id platform;
    cl_device_id device;
    cl_uint numPlatforms, numDevices;

    // Get platform information
    err = clGetPlatformIDs(1, &platform, &numPlatforms);
    if (err != CL_SUCCESS)
    {
        printf("Error getting platform IDs\n");
        return 1;
    }

    // Get device information
    err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, &numDevices);
    if (err != CL_SUCCESS)
    {
        printf("Error getting device IDs\n");
        return 1;
    }

    // Create an OpenCL context
    cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating OpenCL context\n");
        return 1;
    }

    // Create a command queue
    cl_command_queue queue = clCreateCommandQueue(context, device, 0, &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating command queue\n");
        return 1;
    }

    // Input string containing N words
    char inputString[MAX_WORDS * (MAX_WORD_LENGTH + 1)] = "Hello OpenCL World";

    // Calculate the number of words and maximum word length
    int wordCount = 0;
    int maxWordLength = 0;
    char *word = strtok(inputString, " ");
    while (word != NULL)
    {
        wordCount++;
        int len = strlen(word);
        if (len > maxWordLength)
            maxWordLength = len;
        word = strtok(NULL, " ");
    }

    // Create memory buffers on the device
    cl_mem inputBuffer = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(char) * (wordCount * (maxWordLength + 1)), inputString, &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating input buffer\n");
        return 1;
    }

    cl_mem outputBuffer = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(char) * (wordCount * (maxWordLength + 1)), NULL, &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating output buffer\n");
        return 1;
    }

    // Create OpenCL program from source code
    cl_program program = clCreateProgramWithSource(context, 1, &kernelSource, NULL, &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating program\n");
        return 1;
    }

    // Build the program
    err = clBuildProgram(program, 1, &device, NULL, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error building program\n");
        return 1;
    }

    // Create the kernel
    cl_kernel kernel = clCreateKernel(program, "reverseWords", &err);
    if (err != CL_SUCCESS)
    {
        printf("Error creating kernel\n");
        return 1;
    }

    // Set kernel arguments
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &inputBuffer);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &outputBuffer);
    err |= clSetKernelArg(kernel, 2, sizeof(int), &wordCount);
    err |= clSetKernelArg(kernel, 3, sizeof(int), &maxWordLength);
    if (err != CL_SUCCESS)
    {
        printf("Error setting kernel arguments\n");
        return 1;
    }

    // Execute the kernel
    size_t globalSize = wordCount;
    err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, NULL, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error executing kernel\n");
        return 1;
    }

    // Read the result buffer back to host memory
    char outputString[MAX_WORDS * (MAX_WORD_LENGTH + 1)];
    err = clEnqueueReadBuffer(queue, outputBuffer, CL_TRUE, 0, sizeof(char) * (wordCount * (maxWordLength + 1)), outputString, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error reading buffer\n");
        return 1;
    }

    // Display the reversed words
    printf("Reversed words:\n");
    printf("%s\n", outputString);

    // Release OpenCL resources
    clReleaseMemObject(inputBuffer);
    clReleaseMemObject(outputBuffer);
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    return 0;
}
