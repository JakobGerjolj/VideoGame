#pragma once
#include"window.h"
#include <string>
#include <iostream>
using namespace std;

class Rect {
public:
	Rect(int x, int y, string MultiNacionalke);
	Rect(int w,int h, int x, int y, int r, int g, int b, int a);
	void draw();
	void pollEvents();
	void checkBorders();
	Rect(bool, int&, int&);
	Rect addFire(const Rect& a, int& numFire, int smer);
	Rect() {  }
	
	void FirecheckBorders(Rect player);
	
	void playerCheckBorders(Rect &player);
	
	void checkIfFire(Rect,bool &);
	
	void checkFire(int& a, int& b, Rect x, bool& c);
	
	Rect(string cutTrees, int x, int y);

	void ShuffleLocation(Window c);

	bool isRect;

	bool AliPrestet=0;
	bool AliPrestetMinus = 0;
	
	

public:
	
	int _x;
	int _y;
	int _w;
	int _h;
	int _r;
	int _g;
	int _b;
	int _a;

};

