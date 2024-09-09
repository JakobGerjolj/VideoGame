#include "GroupOfGroupFires.h"


MainFires::MainFires() {

}

void MainFires::drawAll() {
	for (int k=0;k<fires.size();k++)
	{
		fires[k].drawFires();

	}

}

void MainFires::spawnAll(int time) {
	for (int k = 0; k < fires.size(); k++) {
		fires[k].spawn(time);

	}

}

void MainFires::add() {
	vectorFire c;
	fires.push_back(c);

}

void MainFires::checkAll(Rect player) {
	for (int k=0; k < fires.size(); k++) {
		fires[k].checkAllBorders(player);

	}

}

void MainFires::delAllDed() {
	for (int k = 0; k < fires.size(); k++) {
		if (fires[k].is == 0) {
			fires.erase(fires.begin() + k);

		}

	}

}

void MainFires::checkAllDead(int time) {
	for (int k = 0; k < fires.size(); k++) {
		fires[k].checkIfDead(time);
		//problem ce se dotaknem prvega vsi njegovi umrejo
	}

}

void MainFires::ClearAll() {
	bool isEmpty;
	int sum = 0;
	for (int k1 = 0; k1 < fires.size(); k1++) {
		for (int k2 = 0; k2 < fires[k1].FireVector.size(); k2++) {
			if (fires[k1].FireVector[k2].isRect == 0) {
				sum++;

			}
			if (sum == 16) {
				fires[k1].FireVector.clear();

			}

		}
		

	}


}