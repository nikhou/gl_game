#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "resouces.c"

GLFWwindow* window;

int main()
{
	// Gl init

	if(!glfwInit()){
		printf("Failed to initialize GLFW");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

	window = glfwCreateWindow(640, 480, "WINDOW", NULL, NULL);


	if(!window)
	{
		printf("Failed to create window\n");
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if(GLEW_OK != err){
		printf("GLEW error: %s\n", glewGetErrorString(err));
		return -3;
	}

	// initation end

	float *buffer = malloc(12 * sizeof (float));
	getVertices("triangle.json", buffer, 12);
	free(buffer);

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
