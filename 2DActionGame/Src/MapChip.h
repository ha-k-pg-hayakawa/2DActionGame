#ifndef MAPCHIP_H
#define MAPCHIP_H

#include "Common/Vec.h"

#define MAP_CHIP_ALL   (16)					// マップチップの数
#define MAP_CHIP_X     (4)					// マップチップの横幅の数
#define MAP_CHIP_Y     (4)					// マップチップの縦幅の数
#define SIZE_MAP_X     (64)					// マップチップの縦幅
#define SIZE_MAP_Y     (64)		            // マップチップの縦幅
#define MAP_CHIP_MAX_X (20)		            // ステージの縦幅
#define MAP_CHIP_MAX_Y (8)		            // ステージの横幅

enum MapChipId
{
	OneBlock = 1,
	TwoBlock,
	ThreeBlock,
	FourBlock,
	FiveBlock,
	SixBlock,
	SevenBlock,
	EightBlock,
	NineBlock,
	TenBlock,
	ElevenBlock,
	TwelveBlock,
	ThirteenBlock,
	FourteenBlock,
	FifteenBlock
};

class MapChip
{
public:
	MapChip();
	~MapChip();

public:
	void Draw();

	bool OncollisionRectAndMapChip(Vec2 obj_pos, Vec2 obj_size, int Number);

	bool isActive;
	
private:
	Vec2 Chip_size;
	int MapChipDate[MAP_CHIP_ALL];
	Vec2 Position;
};

#endif // !
