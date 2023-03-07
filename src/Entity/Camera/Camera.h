#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include "../../Graphics/Shaders/Shader.h"

class Camera {
public:
	glm::vec3 Size;
	glm::vec3 Position;
	glm::vec3 Direction = glm::vec3(-1, 0, -1);
	glm::vec3 Velocity;

	int width;
	int height;
	float speed = 0.1;
	float sens = 100;
	bool firstClick = true;

	Camera(int width, int height, glm::vec3 position);
	void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);
	void Inputs(GLFWwindow* window);

	void AABBalgo(int X, int Y, int Z) {
		//if (GetBlockAbs(X, Y, Z) != 0) {
			//if (Position.x + Velocity.x > X + 1 && Position.x + Velocity.x - Size.x < X) Velocity.x = 0;
			//if (Position.y + Velocity.y > Y + 1 && Position.y + Velocity.y - Size.y < Y) Velocity.y = 0;
			//if (Position.z + Velocity.z > Z + 1 && Position.z + Velocity.z - Size.z < Z) Velocity.z = 0;
		//}
	}
};