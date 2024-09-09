#include "window.h"
#include "rect.h"
#include "rand.h"
#include "fireGroup.h"
#include "GroupOfGroupFires.h"
#include "text.h"

#include "staroselec.h"
#include<vector>
#include <iostream>
using namespace std;

const int framerate = 60;

int freq = 4;

bool CollDettect1(Rect rect1, Rect rect2) {
	if (rect1._x < rect2._x + rect2._w &&
		rect1._x + rect1._w > rect2._x&&
		rect1._y < rect2._y + rect2._h &&
		rect1._y + rect1._h > rect2._y) {


		return 1;// collision detected!
	}
	else return 0;


}




int main(int argc, char** argv) {
	bool DrugaStopnja = 0;
	int sumTimeEnd = 0;
	int VsiOgnji=0;
	int startFrame, endFrame, sum = 0;
	int a1, b1; bool ksd1=0;
	int a2, b2; bool ksd2 = 0;
	int a3, b3; bool ksd3 = 0;
	srand(time(NULL));
	Window window("Resevanje gozda", 800, 600);
	//staroselci staroselec;
	vector<Rect> deadTrees;
	vector<Rect> deadTrees1;
	vector <Rect> deadTrees2;
	staroselec starobelec1(600, 300);
	staroselec starobelec2(300,150);
	staroselec starobelec3(150, 75);
	MainFires ro;
	ro.add();
	staroselec MultiNac(300, 300, "Multinacionalka");
	staroselec MultiNac1(300, 300, "lol");
	staroselec MultiNac2(400, 400, "ne pa ne");
	vectorFire c;
	Text text1(window._renderer, "arial.ttf", 30, "prva stopnja", { 255,0,0,255 });
	Text text2(window._renderer, "arial.ttf", 30, "druga stopnja", { 255,0,0,255 });
	Text text3(window._renderer, "arial.ttf", 50, "ZACETEK DRUGE STOPNJE", { 255,0,0,255 });
	Text text4(window._renderer, "arial.ttf", 50, "BRAVO ZMAGAL SI!!!", { 255,0,0,255 });
	
	Rect player(50, 50, 0, 0, 255, 20, 147, 255);
	bool isVsiOgnji2=0;
	bool isVsiOgnji1 = 0;
	//Rect l(1, a, b);
	//Rect kri(1, a, b);
	vectorFire m;
	int sumText=0;
	bool sumTimeIs = 0;
	bool isDrugaOnce=0;
	bool shuffled1 = 0;
	while (!window.isClosed()) {
		if (DrugaStopnja and !isDrugaOnce) {
			MultiNac.isRect = true;
			MultiNac1.isRect = true;
			MultiNac2.isRect = true;
			isDrugaOnce = 1;

		}
		if (!DrugaStopnja) {
			MultiNac1.isRect = false;
			MultiNac2.isRect = false;

		}
		
		
		startFrame = SDL_GetTicks();

		player.pollEvents();
		MultiNac.moveRandomly(sum);
		MultiNac1.moveRandomly(sum);
		MultiNac2.moveRandomly(sum);
		starobelec1.moveRandomly(sum);
		starobelec2.moveRandomly(sum);
		starobelec3.moveRandomly(sum);
		
		player.checkBorders();
		starobelec1.check_hit();
		starobelec2.check_hit();
		starobelec3.check_hit();
		starobelec1.playerCheckBorders(player);
		starobelec2.playerCheckBorders(player);
		starobelec3.playerCheckBorders(player);
		ro.checkAll(player);
		ro.checkAll(starobelec1);
		ro.checkAll(starobelec2);
		ro.checkAll(starobelec3);
		ro.spawnAll(sum);

		MultiNac1.FirecheckBorders(player);
		MultiNac1.FirecheckBorders(starobelec1);
		MultiNac1.FirecheckBorders(starobelec2);
		MultiNac1.FirecheckBorders(starobelec3);

		MultiNac2.FirecheckBorders(player);
		MultiNac2.FirecheckBorders(starobelec1);
		MultiNac2.FirecheckBorders(starobelec2);
		MultiNac2.FirecheckBorders(starobelec3);


		MultiNac.FirecheckBorders(player);
		MultiNac.FirecheckBorders(starobelec1);
		MultiNac.FirecheckBorders(starobelec2);
		MultiNac.FirecheckBorders(starobelec3);
		for (int mor = 0; mor < deadTrees.size(); mor++) {
			deadTrees[mor].FirecheckBorders(player);
			deadTrees[mor].FirecheckBorders(starobelec1);
			deadTrees[mor].FirecheckBorders(starobelec2);
			deadTrees[mor].FirecheckBorders(starobelec3);

		}
		if (DrugaStopnja) {
			for (int mor = 0; mor < deadTrees1.size(); mor++) {
				deadTrees1[mor].FirecheckBorders(player);
				deadTrees1[mor].FirecheckBorders(starobelec1);
				deadTrees1[mor].FirecheckBorders(starobelec2);
				deadTrees1[mor].FirecheckBorders(starobelec3);

			}
			for (int mor = 0; mor < deadTrees2.size(); mor++) {
				deadTrees2[mor].FirecheckBorders(player);
				deadTrees2[mor].FirecheckBorders(starobelec1);
				deadTrees2[mor].FirecheckBorders(starobelec2);
				deadTrees2[mor].FirecheckBorders(starobelec3);

			}
		}

	
		if (sum % 100 == 0) {
			if (rand() % 4 == 0) {
				ro.add();
				if (DrugaStopnja) {
					ro.add();

				}
			}

		}

		if (DrugaStopnja) {
			MultiNac2.DestroyTrees(sum, deadTrees2);
			MultiNac1.DestroyTrees(sum, deadTrees1);
		}
		
		MultiNac.DestroyTrees(sum, deadTrees);
		
		if (sum % 100 == 0) {
			for (int k1i = 0; k1i < ro.fires.size(); k1i++) {
				for (int k2i = 0; k2i < ro.fires[k1i].FireVector.size(); k2i++) {
					if (ro.fires[k1i].FireVector[k2i].isRect == 1 and ro.fires[k1i].FireVector[k2i].AliPrestet==0) {
						VsiOgnji++;
						ro.fires[k1i].FireVector[k2i].AliPrestet = 1;
					}
					if (ro.fires[k1i].FireVector[k2i].isRect == 0 and ro.fires[k1i].FireVector[k2i].AliPrestet == 1 and ro.fires[k1i].FireVector[k2i].AliPrestetMinus==0) {
						VsiOgnji--;
						ro.fires[k1i].FireVector[k2i].AliPrestetMinus = 1;

					}
					


				}


			}
		}
		
		starobelec1.checkEveryFire(ro,ksd1,a1,b1,deadTrees);
		starobelec2.checkEveryFire(ro, ksd2, a2, b2, deadTrees);
		starobelec3.checkEveryFire(ro, ksd3, a3, b3, deadTrees);
		starobelec1.checkEveryFire(ro, ksd1, a1, b1, deadTrees1);
		starobelec2.checkEveryFire(ro, ksd2, a2, b2, deadTrees1);
		starobelec3.checkEveryFire(ro, ksd3, a3, b3, deadTrees1);
		starobelec1.checkEveryFire(ro, ksd1, a1, b1, deadTrees2);
		starobelec2.checkEveryFire(ro, ksd2, a2, b2, deadTrees2);
		starobelec3.checkEveryFire(ro, ksd3, a3, b3, deadTrees2);
	

		//starobelec1.draw_hit();
		//starobelec2.draw_hit();
		//starobelec3.draw_hit();
		
		for (int mor = 0; mor < deadTrees.size(); mor++) {
			deadTrees[mor].draw();

		}
		for (int mor = 0; mor < deadTrees1.size(); mor++) {
			deadTrees1[mor].draw();

		}
		for (int mor = 0; mor < deadTrees2.size(); mor++) {
			deadTrees2[mor].draw();

		}
		starobelec1.draw();
		starobelec2.draw();
		starobelec3.draw();
		ro.drawAll ();
		if (DrugaStopnja) {
			MultiNac1.draw();
			MultiNac2.draw();
		}
		MultiNac.draw();
		player.draw();
		if (!DrugaStopnja) {
			text1.display(20, 20, Window::_renderer);
		}
		else text2.display(20, 20, Window::_renderer);

		
		if (isVsiOgnji1 == 1 and VsiOgnji == 4 and DrugaStopnja==true and sumText>299 and sumTimeIs) {
			isVsiOgnji2 = 1;
			text4.display(200, 150, window._renderer);
			sumTimeEnd++;
			if (sumTimeEnd > 200) {
				delete& window;

			}


		}


		if (VsiOgnji == 0 and sum > 1000 and sumText<300) {
			DrugaStopnja = true;
			//ro.ClearAll();
			text3.display(200, 150, window._renderer);
			isVsiOgnji1 = true;
			if (sumText > 250) {
				sumTimeIs = true;

			}
			sumText++;
		}
		if (VsiOgnji > 55) {
			cout << "Lost";
			delete& window;

		}
		window.pollEvents();
		window.clear();
		endFrame = SDL_GetTicks();
		
		//ro.ClearAll();
			sum++;
	
		//	cout << "\nx od staroselca: " << starobelec._x << "\n";
			//cout << "\nNaj x je: " << starobelec.Xnaj << " \n";
			//cout << "\nNaj y je: " << starobelec.Ynaj << " \n";
			//cout << "\nAli vidim ogenj: " << starobelec.seeFire << "\n";
			cout << "\nMultinac:: "<<MultiNac.isRect<<"\n";
			cout << "\nVsi ognji:: "<<VsiOgnji<< "\n";
		cout << sum << "\n";
	}

	return 0;
}