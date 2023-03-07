#include"Camera.h"
#include "../../main.h"



Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
	Size = glm::vec3(2.0f, 2.0f, 2.0f);	
	Velocity = Vec30;
}

void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform)
{
	glm::mat4 view = Mat4ID;
	glm::mat4 projection = Mat4ID;

	view = glm::lookAt(Position-Vec30_5, Position - Vec30_5 + Direction, Y);
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}



void Camera::Inputs(GLFWwindow* window)
{
	Velocity = Vec30;
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Velocity += speed * Direction;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Velocity += speed * -glm::normalize(glm::cross(Direction, Y));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Velocity += speed * -Direction;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Velocity += speed * glm::normalize(glm::cross(Direction, Y));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		Velocity += speed * Y;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		Velocity += speed * -Y;
	}

	for (size_t i_x = 0; i_x < 5; i_x++)
	{
		for (size_t i_y = 0; i_y < 6; i_y++)
		{
			for (size_t i_z = 0; i_z < 5; i_z++)
			{
				AABBalgo(Position.x + i_x-2, Position.y +i_y-2, Position.z + i_z-2);
			}
		}
	}
	//if (bap != 0 && Velocity.x > 0)
	//	Velocity.x = 0;
	//if (bap != 0 && Velocity.y > 0)
	//	Velocity.y = 0;
	//if (bap != 0 && Velocity.z > 0)
	//	Velocity.z = 0;


	//if (GetBlockAbs(Position.x - Size.x, Position.y, Position.z) != 0 && Velocity.x < 0)
	//	Velocity.x = 0;
	//if (GetBlockAbs(Position.x, Position.y - Size.y, Position.z) != 0 && Velocity.y < 0)
	//	Velocity.y = 0;
	//if (GetBlockAbs(Position.x, Position.y, Position.z - Size.z) != 0 && Velocity.z < 0)
	//	Velocity.z = 0;

	Position += Velocity;


	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDisable(GL_CULL_FACE);
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_CULL_FACE);
	}




	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firstClick)
		{
			glfwSetCursorPos(window, (width / 2), (height / 2));
			firstClick = false;
		}

		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		float rotX = sens * (float)(mouseY - (height / 2)) / height;
		float rotY = sens * (float)(mouseX - (width / 2)) / width;

		glm::vec3 newDirection = glm::rotate(Direction, glm::radians(-rotX), glm::normalize(glm::cross(Direction, Y)));

		Direction = newDirection;

		Direction = glm::rotate(Direction, glm::radians(-rotY), Y);
		glfwSetCursorPos(window, (width / 2), (height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
	}
}