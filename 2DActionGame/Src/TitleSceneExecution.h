#ifndef TITLESCENEEXECUTION_H
#define TITLESCENEEXECUTION_H

class TiteleSceneExecution
{
public:
	TiteleSceneExecution();
	~TiteleSceneExecution();

private:
	void InitTitleScene();
	void RunTitleScene();
	void FinishTitleScene();

public:
	void TitleSceneUpdate();

private:
	bool Push;
};





#endif // !TITLESCENEEXECUTION_H
