#include "MapChip.h"
#include "DxLib.h"
#include "Camera.h"
#include "Player.h"

extern Camera g_Camera;
 Player g_Player;

// マップチップ配列 
int MapChipList[MAP_CHIP_MAX_Y][MAP_CHIP_MAX_X]
{
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

MapChip::MapChip()
{
    //マップチップ画像読み込み
	LoadDivGraph("Res/MapChip.png", MAP_CHIP_ALL, MAP_CHIP_X, MAP_CHIP_Y, SIZE_MAP_X, SIZE_MAP_Y, MapChipDate);
	Chip_size = Vec2(64.0f, 64.0f);
	Position = Vec2(0.0f, 0.0f);
	isActive = true;
	//g_Position = Vec2(0.0f, 0.0f);
}

MapChip::~MapChip()
{

}

void MapChip::Draw()
{
	for (int y = 0; y < MAP_CHIP_MAX_Y; y++)
	{
		for (int x = 0; x < MAP_CHIP_MAX_X; x++)
		{
			// チップ番号取得
			int chip_id = MapChipList[y][x];

			// 無効な値かをチェック
			if (chip_id == 0)
			{
				continue;
			}
			
			//描画座標を算出
			Position = Vec2(x * Chip_size.X, y * Chip_size.Y);

			Vec2 Screen_Pos = g_Camera.Update(Position);
			
			if (isActive == true)
			{
				switch (chip_id)
				{
				case 0:                                                                           break;
				case 1:  DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[OneBlock],	  true);  break;
				case 2:  DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[TwoBlock],	  true);  break;
				case 3:  DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[ThreeBlock],   true);  break;
				case 4:  DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[FourBlock],	  true);  break;
				case 5:  DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[FiveBlock],	  true);  break;
				case 6:  DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[SixBlock],	  true);  break;
				case 7:  DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[SevenBlock],   true);  break;
				case 8:  DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[EightBlock],   true);  break;
				case 9:  DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[NineBlock],	  true);  break;
				case 10: DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[TenBlock],	  true);  break;
				case 11: DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[ElevenBlock],  true);  break;
				case 12: DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[TwelveBlock],  true);  break;
				case 13: DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[ThirteenBlock],true);  break;
				case 14: DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[FourteenBlock],true);  break;
				case 15: DrawGraph(Screen_Pos.X, Screen_Pos.Y, MapChipDate[FifteenBlock], true);  break;
				}
			}
		}
	}
}

bool MapChip::OncollisionRectAndMapChip(Vec2 obj_pos, Vec2 obj_size, int Number)
{
	Vec2 vertices[] =
	{
		// 左上
		obj_pos,
		// 右上
		Vec2(obj_pos.X + obj_size.X, obj_pos.Y),
		// 右下
		Vec2(obj_pos.X + obj_size.X, obj_pos.Y + obj_size.Y),
		// 左下
		Vec2(obj_pos.X, obj_pos.Y + obj_size.Y),
	};

	int vertex_mapchip_ids_w[4];
	int vertex_mapchip_ids_h[4];

	for (int i = 0; i < 4; i++)
	{
		vertex_mapchip_ids_w[i] = vertices[i].X / 64.0f;
		vertex_mapchip_ids_h[i] = vertices[i].Y / 64.0f;
	}

	for (int i = 0; i < 4; i++)
	{
		int w = vertex_mapchip_ids_w[i];
		int h = vertex_mapchip_ids_h[i];

		// 配列の番号が有効な値かどうかをチェック
		if ((w < 0 || w >= MAP_CHIP_MAX_X) &&
			(h < 0 || h >= MAP_CHIP_MAX_Y))
		{
			continue;
		}

		// 0以外は有効番号 => 有効番号 == マップチップが配置されている
		if (MapChipList[h][w] == Number)
		{
			isActive = false;
			// 当たり
			return true;
		}
	}

	// 当たっていない
	return false;
}