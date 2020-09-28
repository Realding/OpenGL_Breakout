#pragma once
#include <glad/glad.h>
#include <vector>
#include "game_level.h"
#include "particle_generator.h"


// ö����Ϸ״̬����
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

// ö�����ֿ��ܵ���ײ����
enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

// ������ײʱ������
typedef std::tuple<GLboolean, Direction, glm::vec2> Collision; // <�Ƿ���ײ?, ����?, difference vector center - closest point>


// ��ʼ������Ĵ�С
const glm::vec2 PLAYER_SIZE(100, 20);
// ��ʼ�����������
const GLfloat PLAYER_VELOCITY(500.0f);

// ��ʼ������ٶ�
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// ��İ뾶
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
	// ��Ϸѭ��
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
	void ResetLevel();
	void ResetPlayer();
	void DoCollisions();
};

