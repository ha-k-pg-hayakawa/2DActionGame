#include "Scene.h"
#include "ResultSceneExecution.h"
#include "DxLib.h"

extern SceneID g_SceneID;
extern SceneStep g_SceneStep;

ResultSceneExecution::ResultSceneExecution()
{
}

ResultSceneExecution::~ResultSceneExecution()
{
}

void ResultSceneExecution::InitResultScene()
{
	g_SceneStep = SceneStep::Run;
}

void ResultSceneExecution::RunResultScene()
{
	//画像をロード
	int GameOver = LoadGraph("Res/GameOver.jpg");
	// 読みこんだグラフィックを拡大描画
	DrawExtendGraph(0, 0, 640, 480, GameOver, TRUE);

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		g_SceneID = SceneID::SceneID_Title;
		g_SceneStep = SceneStep::Init;
	}
}

void ResultSceneExecution::FinishResultScene()
{
	//画像をロード
	int CLEAR = LoadGraph("Res/CLEAR.png");
	// 読みこんだグラフィックを拡大描画
	DrawExtendGraph(0, 100, 640, 380, CLEAR, TRUE);

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		g_SceneID = SceneID::SceneID_Title;
		g_SceneStep = SceneStep::Init;
	}
}

void ResultSceneExecution::ResultSceneUpdate()
{
	switch (g_SceneStep)
	{
	case SceneStep::Init: InitResultScene(); break;
	case SceneStep::Run: RunResultScene();  break;
	case SceneStep::Finish: FinishResultScene(); break;
	}
}