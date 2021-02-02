#include "Slider.h"
#include "DxLib.h"
#include "Scene.h"

extern SceneID g_SceneID;
extern SceneStep g_SceneStep;

Slider::Slider()
{
	Position = Vec2(0.0f, 0.0f);
	Size = Vec2(640, 20);
	MinValue = 0.0f;		// 最小値
	MaxValue = 600.0f;      //最大値
    CurrentValue = 0.0f;	// 現在値
	Counter = 0;
}

Slider::~Slider()
{

}

Vec2 Slider::GetSliderPos()
{
	return Position;
}

void Slider::Init()
{
	MinValue = 0.0f;		//最小値
	MaxValue = 600.0f;      //最大値
	CurrentValue = 0.0f;	//現在値
	Counter = 0;
}

void Slider::Update()
{

}

void Slider::Draw()
{
	Counter++;
	CurrentValue = (Counter - MinValue) / (MaxValue - MinValue);
	if (Counter >= 600)
	{
		g_SceneID = SceneID::SceneID_Game;
		g_SceneStep = SceneStep::Finish;
	}
	
	//画像をロード
	int Slider = LoadGraph("Res/Slider.png");
	DrawRectGraph(Position.X, Position.Y, 0, 0, (Size.X * (1.0 - CurrentValue)), Size.Y, Slider, TRUE, FALSE);
}