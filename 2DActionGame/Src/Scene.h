#ifndef SCENE_H
#define SCENE_H

enum SceneID
{
	SceneID_Title,			// タイトル
	SceneID_Game,			// ゲーム
	SceneID_Result,			// リザルト
};

enum SceneStep
{
	Init,
	Run,
	Finish
};

void SceneUpdate01();

#endif // !SCENE_H
