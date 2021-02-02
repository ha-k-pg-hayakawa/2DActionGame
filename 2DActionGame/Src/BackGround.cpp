#include "BackGround.h"
#include "Camera.h"
#include "DxLib.h"

extern Camera g_Camera;

BackGround::BackGround()
{
	Position = Vec2(0.0f, 0.0f);
}

BackGround::~BackGround()
{

}

void BackGround::Draw()
{
	Vec2 Screen_Pos = g_Camera.Update(Position);

	LoadGraphScreen(Screen_Pos.X, Screen_Pos.Y, "Res/BackGround.png", true);
}