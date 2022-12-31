#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Input.h"
#include "Window.h"
#include "Renderer.h"

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

	//tag::set_up_window[]
	Window* window = Window::createWindow(windowWidth, windowHeigth, windowTitle, windowedFullscreen, isFullscreen);
	if (window == nullptr)
		return exitWithError("Couldn't initialize window");
	window->initializeCallbacks();

	//Makes sure glad loads result into GLFW window
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return exitWithError("Couldn't initialize glad!\n");
	}

	printf("Window initialized successfully!\n");
	//end::set_up_window[]

	Renderer::setupRenderer();
	printf("Renderer setup successfully!\n");

	while (!glfwWindowShouldClose(window->glfwWindow)) {

		//Sets the pixels to this color value when clearing the buffers with glClear()
		glClearColor(237.0f / 255.0f, 223.0f / 255.0f, 215.0f / 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		if (Input::isKeyPressed(GLFW_KEY_ESCAPE))
		{
			window->closeWindow();
		}

		if (Input::isKeyPressed(GLFW_KEY_W)) {
			printf("w has been pressed\n");
		}

		Renderer::drawTriangle();

		glfwSwapBuffers(window->glfwWindow);
		glfwPollEvents();
	}

	Window::freeWindow(window);
	glfwTerminate();
	return 0;
}
