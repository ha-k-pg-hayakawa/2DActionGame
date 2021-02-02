#ifndef PLAYER_H
#define PLAYER_H

#include "Common/Vec.h"

class Player
{
public:
	Player();
	~Player();

	Vec2& GetPlayerPos();

public:
	void Init();
	void Update();
	void Draw();

	void StartJump();
	bool HitBox(Vec2 pos0, int width0, int height0, Vec2 pos1, int width1, int height1);
	
private:
	Vec2 Position;
	Vec2 Speed;
	float Gravity;
	
	bool CanJump;
};

#endif // !PLAYER_H
