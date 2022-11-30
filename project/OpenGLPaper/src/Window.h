#pragma once
#include <GLFW/glfw3.h>

namespace OpenGLTestProject {
	class Window {

		public:
			GLFWwindow* glfwWindow;

			void initializeCallbacks();
			void closeWindow();

			static Window* createWindow(int width, int height, const char* title, bool windowedFullscreen, bool isFullscreen);
			static void freeWindow(Window* window);

		
	};
}