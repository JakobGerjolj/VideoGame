	#include "fireGroup.h"


bool CollDettect(Rect rect1, Rect rect2) {
	if (rect1._x < rect2._x + rect2._w &&
		rect1._x + rect1._w > rect2._x&&
		rect1._y < rect2._y + rect2._h &&
		rect1._y + rect1._h > rect2._y) {


		return 1;// collision detected!
	}
	else return 0;


}


void vectorFire::drawFires() {

	if (is) {
		for (int k = 0; k < FireVector.size(); k++) {
			FireVector[k].draw();

		}
	}
}

vectorFire::vectorFire() {
	
	Rect r(1, numfire, smer);
	FireVector.push_back(r);
	is = true;
}

void vectorFire::add() {
	FireVector.push_back(FireVector[FireVector.size()-1].addFire(FireVector[FireVector.size()-1],numfire,smer));
	
}

void vectorFire::spawn(int time) {

	if (time != 0) {
		if (time % (rand() % 300 + 100) == 0) {
			this->add();
			didSpawn = true;
		}

	}
}

void vectorFire::checkAllBorders(Rect player){
	for(int k = 0; k < FireVector.size(); k++) {
		FireVector[k].FirecheckBorders(player);

	}

}

void vectorFire::checkIfDead(int time) {
	int sum = 0;
	if (time>200) {
		for (int k = 0; k < FireVector.size(); k++) {
			if (FireVector[k].isRect == 1) {
				sum++;
				
			}

		}
		if (sum == 0 and (FireVector.size()>0)) is = false; else is = true;
	}
	else is = true;



}


Rect vrniCOORD(vector<Rect> c,Rect x) {
	Rect m;
	
	for (int k = 0; k < c.size(); k++) {
		if (CollDettect(c[k], x)) {

			return c[k];
		}

	}

}

