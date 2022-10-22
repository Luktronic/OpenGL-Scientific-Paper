#pragma once
#include <GLFW/glfw3.h>

namespace OpenGLTestProject {

	namespace Input {

		extern bool keyStates[];
		extern bool mouseButtonStates[];
		extern double mouseX;
		extern double mouseY;
		extern double mouseScrollX;
		extern double mouseScrollY;

		//Gets called from any key event. Calls the specific action callbacks (pressed, released, etc)
		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		//Gets called from any mouse button event
		void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		//Gets called from scroll event. xoffset = scroll on x axis, yoffset = scroll on y axis
		void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		//Gets called when the mouse cursor moves
		void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

		bool isKeyPressed(int key);
		bool isMouseButtonPressed(int mouseButton);

		
	}
}