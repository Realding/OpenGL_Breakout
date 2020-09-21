#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// 枚举游戏状态类型
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game
{
public:
	GameState State;
	GLboolean Keys[1024];
	GLuint Width, Height;

	Game(GLuint width, GLuint height);
	~Game();

	void Init();
	// 游戏循环
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
};

