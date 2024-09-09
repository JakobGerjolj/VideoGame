#include "staroselec.h"
#include <cmath>

bool CollDettect2(Rect rect1, Rect rect2) {
	if (rect1._x < rect2._x + rect2._w &&
		rect1._x + rect1._w > rect2._x&&
		rect1._y < rect2._y + rect2._h &&
		rect1._y + rect1._h > rect2._y) {


		return 1;// collision detected!
	}
	else return 0;


}
float XYdoXY(int x1, int y1, int x2, int y2) {

	return sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));

}

staroselec::staroselec(int x, int y) {
	Rect hit(250, 250, x - 100, y - 100, 255, 255, 255, 255);
	hitbox = hit;
	isRect = true;
	_r = 255;
	_g = 255;
	_b = 0;
	_w = 50;
	_h = 50;
	_a = 255;
	_x = x;
	_y = y;
}

void staroselec::moveRandomly(int time) {

	int ra = (rand() % 4) + 1;
	

	if (!seeFire) {
		if (time % 100 == 0) {
			if (ra == 1) {
				_x += 30;
				hitbox._x += 30;

			}
			else if (ra == 2) {
				_x -= 30;
				hitbox._x -= 30;
			}
			else if (ra == 3) {
				_y -= 30;
				hitbox._y -= 30;

			}
			else if (ra == 4) {
				_y += 30;
				hitbox._y += 30;

			}
		}
	}
	else {
		if (time % 100 == 0 ) {
			bool useMove = 0;
			if (_x>Xnaj and !(_x<(Xnaj+50)) and useMove == 0) {
				_x -= 30;
				hitbox._x -= 30;
				useMove = 1;
			}
			else if (_x<Xnaj and !(_x>(Xnaj-50))  and useMove == 0) {
				_x += 30;
				hitbox._x += 30;
				useMove = 1;
			}
			if (Ynaj < _y and useMove == 0) {
				_y -= 30;
				hitbox._y -= 30;
				useMove = 1;
			}
			else if (Ynaj > _y and useMove == 0) {
				_y += 30;
				hitbox._y += 30;
				useMove = 1;

			}
			

			

		}

	}
}

void staroselec::draw_hit() {
	
	hitbox.draw();
	this->draw();
	
}

void staroselec::check_hit() {
	if (_x <= 0) {
		_x = 0;
		hitbox._x = -100;

	}
	if ((_x + _w) >= (800 - 1)) {
		_x = (800) - _w;
		hitbox._x = 800 -150;

	}
	if (_y <= 0) {
		_y = 0;
		hitbox._y = -100;

	}
	if ((_y + _h) >= 600) {
		_y = (600) - _h;
		hitbox._y = 600 - 100;

	}

}

void staroselec::checkAllFires(MainFires a) {

	



}

void staroselec::AssumeControl() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_LEFT) {
				_x -= 30;
				hitbox._x -= 30;
			}
			if (event.key.keysym.sym == SDLK_RIGHT) {
				_x += 30;
				hitbox._x += 30;
			}
			if (event.key.keysym.sym == SDLK_UP) {
				_y -= 30;
				hitbox._y -= 30;
			}
			if (event.key.keysym.sym == SDLK_DOWN) {
				_y += 30;
				hitbox._y += 30;
			}


		}

	}

}

void staroselec::checkEveryFire(MainFires a,bool &yes, int &a1, int &b1,vector<Rect> &posekanost) {
	Rect c,k;
	c._x = a1;
	c._y = b1;
	c._w = 50;
	c._h = 50;
	k._x = _x;
	k._y = _y;
	k._w = 50;
	k._h = 50;
	
	if (!yes) {
		for (int k = 0; k < a.fires.size();k++) {
			
			for (int k1 = 0; k1 < a.fires[k].FireVector.size(); k1++) {
				
				if (CollDettect2(a.fires[k].FireVector[k1], hitbox) and a.fires[k].FireVector[k1].isRect==1) {
					a1 = a.fires[k].FireVector[k1]._x; b1 = a.fires[k].FireVector[k1]._y;
					Xnaj= a.fires[k].FireVector[k1]._x;Ynaj = a.fires[k].FireVector[k1]._y;
					seeFire = 1;
					yes = 1;
					break;

				}

			}
			if (yes) {
				break;
			}
		
		}


	}
	if (CollDettect2(c, k) or !CollDettect2(c, hitbox)) {
		Xnaj = 0; Ynaj = 0;
		seeFire = 0;
		yes = 0;

	}
	if (!yes) {
		for (int k = 0; k < posekanost.size(); k++) {
			if (CollDettect2(posekanost[k], hitbox)and posekanost[k].isRect==1) {
				a1 = posekanost[k]._x;
				b1 = posekanost[k]._y;
				Xnaj= posekanost[k]._x;
				Ynaj = posekanost[k]._y;
				seeFire = 1;
				yes = 1;

			}

		}

	}
	if (CollDettect2(c, k) or !CollDettect2(c, hitbox)) {
		Xnaj = 0; Ynaj = 0;
		seeFire = 0;
		yes = 0;

	}
	


}


staroselec::staroselec(int x, int y, string MultiNacionalke) {
	isRect = 1;
	_r = 0;
	_g = 0;
	_b = 0;

	_a = 255;
	_x = x;
	_y = y;
	_w = 50;
	_h = 50;
	seeFire = 0;
	 Xnaj = 0;
	 Ynaj = 0;


}

void staroselec::DestroyTrees(int time, vector<Rect>& a) {
	Rect kur;

	if (isRect == 1) {
		if (time % 200 == 0) {
			kur.isRect = 1;
			kur._x = _x;
			kur._y = _y;
			kur._w = 50;
			kur._h = 50;
			kur._r = 139;
			kur._g = 69;
			kur._b = 19;

			a.push_back(kur);
		}
	}
}
