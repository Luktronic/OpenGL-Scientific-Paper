#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Input.h"
#include "Window.h"

using namespace OpenGLTestProject;


const int windowWidth = 1280;
const int windowHeigth = 720;
const char* windowTitle = "OpenGL Test Project";
const bool windowedFullscreen = false;
const bool isFullscreen = false; //If this is true, window is always fullscreen (overrides windowedFullscreen)

int exitWithError(const char* msg) {
	printf(msg);
	glfwTerminate();
	return -1;
}

int main() {
	
	if (!glfwInit()) {
		return exitWithError("GLFW initialization failed\n");
	}

	Window* window = Window::createWindow(windowWidth, windowHeigth, windowTitle, windowedFullscreen, isFullscreen);
	if (window == nullptr)
		return exitWithError("Couldn't initialize window");
	window->initializeCallbacks();

	//Makes sure glad loads result into GLFW window
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return exitWithError("Couldn't initialize glad!\n");
	}

	//Sets which part of the Window OpenGL is drawing to
	glViewport(0, 0, windowWidth, windowHeigth);

	printf("Window initialized successfully!\n");
	while (!glfwWindowShouldClose(window->glfwWindow)) {

		//Sets the pixels to this color value when clearing the buffers with glClear()
		glClearColor(111.0f / 255.0f, 84.0f / 255.0f, 76.0f / 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		if (Input::isKeyPressed(GLFW_KEY_ESCAPE))
		{
			window->closeWindow();
		}

		if (Input::isKeyPressed(GLFW_KEY_W)) {
			printf("w has been pressed\n");
		}

		glfwSwapBuffers(window->glfwWindow);
		glfwPollEvents();
	}

	Window::freeWindow(window);
	glfwTerminate();
	return 0;
}
