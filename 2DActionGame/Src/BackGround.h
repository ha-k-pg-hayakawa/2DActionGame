#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Common/Vec.h"

class BackGround
{
public:
	BackGround();
	~BackGround();

public:
	void Draw();

private:
	Vec2 Position;
};

#endif // !BACKGROUND_H
