#pragma once

#include "rect.h"
#include<vector>
class vectorFire {

	
	int smer;

	
public:
	vector<Rect> FireVector;
	
	
	int numfire=0;
	bool is;
	bool didSpawn=0;

public:
	
	void AiCheckAll(int& a, int& b, Rect x, bool& c);
	vectorFire();
	void add();
	void drawFires();
	void spawn(int time);
	void checkAllBorders(Rect player);
	void checkIfDead(int time);


};
