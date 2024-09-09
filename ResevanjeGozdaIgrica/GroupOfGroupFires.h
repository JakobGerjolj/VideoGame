#pragma once
#include "fireGroup.h"


class MainFires {
public:
	vector<vectorFire> fires;
	MainFires();
	void drawAll();
	void spawnAll(int time);
	void add();
	void checkAll(Rect player);
	void checkAllDead(int time);
	void delAllDed();
	void ClearAll();

};
