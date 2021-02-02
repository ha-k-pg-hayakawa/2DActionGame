#include "Player.h"
#include "DxLib.h"
#include "Camera.h"
#include "MapChip.h"
#include "Scene.h"

extern SceneID g_SceneID;
extern SceneStep g_SceneStep;

static MapChip g_MapChip;
extern Camera g_Camera;

Player::Player()
{
    CanJump = true;
    Speed = Vec2(4.0f, 0.0f);
    Gravity = 0.98f;
}

Player::~Player()
{
    
}

Vec2& Player::GetPlayerPos()
{
    return Position;
}

void Player::Init()
{
    CanJump = true;
    Position = Vec2(100.0f, 400.0f);
}

void Player::Update()
{
    //Player画像サイズ
    Vec2 size = Vec2(40.0f, 40.0f);
    Vec2 Vector = Vec2(0.0f, 0.0f);

    //移動処理
    if (CheckHitKey(KEY_INPUT_LEFT) != 0)
    {
        Vector.X = -Speed.X;
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
    {
        Vector.X = Speed.X;
    }
    if (CheckHitKey(KEY_INPUT_SPACE) != 0)
    {
        StartJump();
    }

    if (CanJump == false)
    {
        Speed.Y -= Gravity;
        Vector.Y = -Speed.Y;
    }

    if (g_MapChip.OncollisionRectAndMapChip(
        Vec2(Position.X + Vector.X, Position.Y + Vector.Y), size, 0) == true)
    {
        Position.X += Vector.X;
        Position.Y += Vector.Y;
    }

    //Onblockの座標算出
    if (g_MapChip.OncollisionRectAndMapChip(
        Vec2(Position.X + Vector.X, Position.Y + Vector.Y), size, 1) == true)
    {
        CanJump = true;
    }

    if (g_MapChip.OncollisionRectAndMapChip(
        Vec2(Position.X + Vector.X, Position.Y + Vector.Y), size, 2) == true)
    {
        if (Position.X < 100)
        {
            Position.X = Position.X + Speed.X;
        }
        else
        {
            Position.X = Position.X - Speed.X;
        }
    }

    if (g_MapChip.OncollisionRectAndMapChip(Vec2(Position.X + Vector.X, Position.Y + Vector.Y), size, 3) == true)
    {
        g_SceneID = SceneID::SceneID_Result;
        g_SceneStep = SceneStep::Finish;
    }
}

void Player::Draw()
{
    Vec2 Screen_Pos = g_Camera.Update(Position);

    LoadGraphScreen(Screen_Pos.X, Screen_Pos.Y, "Res/Player.png", true);
}

void Player::StartJump()
{
    if (CanJump == true)
    {
        Speed.Y = 20.0f;
        CanJump = false;
    }
}

bool Player::HitBox(Vec2 pos0, int width0, int height0, Vec2 pos1, int width1, int height1)
{
    //オブジェクトの距離
    int x = pos1.X - pos0.X;
    int y = pos1.Y - pos0.Y;

    //abs関数は絶対値を返す
    if (abs(x) < width0 / 2 + width1 / 2 && abs(y) < height0 / 2 + height1 / 2) {
        return true;
    }
    return false;
}