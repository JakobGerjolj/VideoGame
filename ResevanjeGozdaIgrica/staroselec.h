#pragma once
#include "rect.h"
#include "GroupOfGroupFires.h"
class staroselec: public Rect {
public:
	staroselec(int x, int y);
	staroselec(){ }
	void moveRandomly(int time);
	void draw_hit();
	void check_hit();
	void checkAllFires(MainFires a);
	void AssumeControl();
	void checkEveryFire(MainFires a,bool &yes, int&, int &,vector<Rect> &posekanost);
	staroselec(int, int, string);
	void DestroyTrees(int time,vector<Rect>& a);

	bool seeFire=0;
	int Xnaj=0;
	int Ynaj=0;

	Rect hitbox;




};