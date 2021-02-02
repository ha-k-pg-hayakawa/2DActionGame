#include "TitleSceneExecution.h"
#include "Scene.h"
#include "DxLib.h"

extern SceneID g_SceneID;
extern SceneStep g_SceneStep;

TiteleSceneExecution::TiteleSceneExecution()
{
}

TiteleSceneExecution::~TiteleSceneExecution()
{
}

void TiteleSceneExecution::InitTitleScene()
{
	Push = true;
	g_SceneStep = SceneStep::Run;	
}

void TiteleSceneExecution::RunTitleScene()
{
	//DrawString(100, 100, "ActionGame", GetColor(255, 255, 255), 0);
	//画像をロード
	int Title = LoadGraph("Res/START.png");
	// 読みこんだグラフィックを拡大描画
	DrawExtendGraph(0, 0, 640, 480, Title, TRUE);

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		if (Push == false)
		{
			Push = true;
			g_SceneStep = SceneStep::Finish;
		}
	}
	else
	{
		Push = false;
	}
}

void TiteleSceneExecution::FinishTitleScene()
{
	g_SceneID = SceneID::SceneID_Game;
	g_SceneStep = SceneStep::Init;
}

void TiteleSceneExecution::TitleSceneUpdate()
{
	switch (g_SceneStep)
	{
	case SceneStep::Init: InitTitleScene(); break;
	case SceneStep:: Run: RunTitleScene();  break;
	case SceneStep::Finish: FinishTitleScene(); break;
	}
}