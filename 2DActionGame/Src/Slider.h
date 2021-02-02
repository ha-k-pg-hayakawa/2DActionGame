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
	float MinValue;		// ç≈è¨íl
	float MaxValue;		// ç≈ëÂíl
	float CurrentValue;	// åªç›íl
	int Counter;
};

#endif // !SLIDER_H
