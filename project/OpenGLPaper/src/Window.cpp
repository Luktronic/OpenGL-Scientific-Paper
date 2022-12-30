#include <iostream>
#include "Window.h"
#include "Input.h"

namespace OpenGLTestProject {

	GLFWwindow* glfwWindow;
	int height;
	int width;

	void Window::initializeCallbacks() {
		glfwSetKeyCallback(glfwWindow, Input::keyCallback);
		glfwSetMouseButtonCallback(glfwWindow, Input::mouseButtonCallback);
		glfwSetScrollCallback(glfwWindow, Input::scrollCallback);
		glfwSetCursorPosCallback(glfwWindow, Input::cursorPosCallback);
	}

	void Window::closeWindow() {
		
		if (glfwWindow != nullptr) {
			glfwSetWindowShouldClose(glfwWindow, GLFW_TRUE);
		}

	}

	Window* Window::createWindow(int width, int height, const char* title, bool windowedFullscreen, bool isFullscreen) {

		//Ensure that glfw uses opengl version 4.6
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		//Core profile means we will not use deprecated functions
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		//create window
		Window* window = new Window();

		//If we want windowedFullscreen or Fullscreen, get the primary monitor so we can get the width/heigth
		GLFWmonitor* monitor = (windowedFullscreen || isFullscreen) ? glfwGetPrimaryMonitor() : nullptr;
		
		if (monitor != nullptr && !isFullscreen) {
			const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
			height = vidmode->height;
			width = vidmode->width;
		}

		//If we don't want to have fullscreen, set monitor to null again
		//(Glfw creates a fullscreen window if we specify a monitor)
		if(!(isFullscreen || windowedFullscreen)) monitor = nullptr;

		window->glfwWindow = glfwCreateWindow(width, height, title, monitor, nullptr);

		if (window->glfwWindow == nullptr) {
			printf("Failed to create window!\n");
			glfwTerminate();
			return nullptr;
		}

		//Sets our window as current context
		glfwMakeContextCurrent(window->glfwWindow);

		return window;
	}

	void Window::freeWindow(Window* window) {
		if (window) {
			glfwDestroyWindow(window->glfwWindow);
			delete window;
		}
	}

	
}