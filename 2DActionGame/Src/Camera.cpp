#include "Camera.h"
#include "DxLib.h"
#include "Player.h"

//static Vec2 Position = Vec2(0.0f, 0.0f);
static Player g_Player;

Camera::Camera()
{
	Position = Vec2(0.0f, 0.0f) ;
}

Camera::~Camera()
{

}

Vec2 Camera::Update(Vec2 pos)
{
	Vec2 Orizin_Pos = Vec2(Position.X - (640 / 2), Position.Y - (480 / 2));
	Vec2 Screen_Pos = Vec2(pos.X - Orizin_Pos.X, pos.Y - Orizin_Pos.Y);

	return Screen_Pos;
}

void Camera::CameraUpdate(Vec2 pos1)
{
	Vec2 window_half
	{
		640 / 2.0f,
		480 / 2.0f
	};

	// 座標更新
	Position = pos1;

	// X軸のステージの内外判定
	if (Position.X - window_half.X <= 0.0f)
	{
		Position.X = window_half.X;
	}
	else if (Position.X + window_half.X >= FIELD_WIDTH)
	{
		Position.X = FIELD_WIDTH - window_half.X;
	}

	// Y軸のステージの内外判定
	if (Position.Y - window_half.Y <= 0.0f)
	{
		Position.Y = window_half.Y;
	}
	else if (Position.Y + window_half.Y >= FIELD_HEIGHT)
	{
		Position.Y = FIELD_HEIGHT - window_half.Y;
	}
}