#pragma once
#include <glad/glad.h>
#include <vector>
#include "game_level.h"


// 枚举游戏状态类型
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

// 初始化挡板的大小
const glm::vec2 PLAYER_SIZE(100, 20);
// 初始化挡板的速率
const GLfloat PLAYER_VELOCITY(500.0f);

// 初始化球的速度
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// 球的半径
const GLfloat BALL_RADIUS = 12.5f;

class Game
{
public:
	GameState State;
	GLboolean Keys[1024];
	GLuint Width, Height;
	std::vector<GameLevel> Levels;
	GLuint                 Level;


	Game(GLuint width, GLuint height);
	~Game();

	void Init();
	// 游戏循环
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
};

