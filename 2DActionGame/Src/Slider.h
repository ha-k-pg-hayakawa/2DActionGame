#ifndef SLIDER_H
#define SLIDER_H

#include "Common/Vec.h"

class Slider
{
public:
	Slider();
	~Slider();

	Vec2 GetSliderPos();

public:
	void Init();
	void Update();
	void Draw();

private:
	Vec2 Position;		
	Vec2 Size;			
	float MinValue;		// 最小値
	float MaxValue;		// 最大値
	float CurrentValue;	// 現在値
	int Counter;
};

#endif // !SLIDER_H
