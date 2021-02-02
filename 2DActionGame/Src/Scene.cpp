#include "Scene.h"
#include "TitleSceneExecution.h"
#include "GameSceneExecution.h"
#include "ResultSceneExecution.h"

SceneID g_SceneID = SceneID::SceneID_Title;
SceneStep g_SceneStep = SceneStep::Init;

static TiteleSceneExecution g_TiteleSceneExecution;
static GameSceneExecution   g_GameSceneExecution;
static ResultSceneExecution g_ResultSceneExecution;

void SceneUpdate01()
{
	switch (g_SceneID)
	{
	case SceneID::SceneID_Title:  g_TiteleSceneExecution.TitleSceneUpdate();  break;
	case SceneID::SceneID_Game:   g_GameSceneExecution.GameSceneUpdate();     break;
	case SceneID::SceneID_Result: g_ResultSceneExecution.ResultSceneUpdate(); break;
	}
}