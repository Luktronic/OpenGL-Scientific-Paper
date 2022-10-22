#include "Input.h"

namespace OpenGLTestProject {

	namespace Input {

		bool keyStates[GLFW_KEY_LAST] = {}; //Stores the current states of the key (pressed, released, etc)
		bool mouseButtonStates[GLFW_MOUSE_BUTTON_LAST] = {}; //Stores the current states of the mouse buttons (pressed, released, etc)
		double mouseX = 0;
		double mouseY = 0;
		double mouseScrollX = 0;
		double mouseScrollY = 0;

		//Gets called from any key event. Updates the key state
		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			switch (action)
			{
			case GLFW_PRESS:
				keyStates[key] = GLFW_PRESS;
				break;
			case GLFW_RELEASE:
				keyStates[key] = GLFW_RELEASE;
				break;
			default:
				break;
			}
		}

		//Gets called from any mouse button event
		void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
			switch (action)
			{
			case GLFW_PRESS:
				mouseButtonStates[button] = GLFW_PRESS;
				break;
			case GLFW_RELEASE:
				mouseButtonStates[button] = GLFW_RELEASE;
				break;
			default:
				break;
			}
		}

		//Gets called from scroll event. xoffset = scroll on x axis, yoffset = scroll on y axis
		void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
			mouseScrollX = xoffset;
			mouseScrollY = yoffset;
		}

		//Gets called when the mouse cursor moves
		void cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
			mouseX = xpos;
			mouseY = ypos;
		}


		//Checks if a key is pressed
		bool isKeyPressed(int key) {
			return keyStates[key] == GLFW_PRESS;
		}
		

		//Checks if mouse button is pressed
		bool isMouseButtonPressed(int mouseButton) {
			return mouseButtonStates[mouseButton] == GLFW_PRESS;
		}

	}

}