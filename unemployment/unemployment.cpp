
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 800, "ai", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGL();
	float verts[8] = {
		-1,-1,
		1,-1,
		1,1,
		-1,1
	};
	float index[6] = {
	0,1,2,
	0,2,3
	};
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glCreateBuffers(1, &ebo);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(vbo, 32, verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(vbo, 24, verts, GL_STATIC_DRAW);
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}
