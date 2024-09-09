#include "rect.h"


Rect::Rect(int w, int h, int x, int y, int r, int g, int b, int a) :
	_w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{
	isRect = true;

}

void Rect::draw() {
	if (isRect) {
		SDL_Rect rect;
		rect.w = _w;
		rect.h = _h;
		rect.x = _x;
		rect.y = _y;

		SDL_SetRenderDrawColor(Window::_renderer, _r, _g, _b, 255);
		SDL_RenderFillRect(Window::_renderer, &rect);
	}
}

void Rect::pollEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_LEFT) {
				_x -= 30;
			}
			if (event.key.keysym.sym == SDLK_RIGHT) {
				_x += 30;
			}
			if (event.key.keysym.sym == SDLK_UP) {
				_y -= 30;
			}
			if (event.key.keysym.sym == SDLK_DOWN) {
				_y += 30;
			}

			
		}

	}

}

void Rect::checkBorders() {
	if (_x <= 0) {
		_x = 0;

	}
	if ((_x + _w) >= (800 - 1)) {
		_x = (800)-_w;

	}
	if (_y <= 0) {
		_y = 0;

	}
	if ((_y + _h) >= 600) {
		_y = (600)-_h;

	}

}

Rect::Rect( bool isBoss, int& numfire, int& smer) 
	

{
	_w = 50;
	_h = 50;
	_r = 255;
	_g = 140;
	_b = 0;
	_a = 255;
	if (isBoss) {
		_x = rand() % (800 - 50);
		_y = rand() % (600 - 50);

	}
	if (_x >= 0 and _y + 200 <= 600) {
		smer = 1;

	}
	else if ((_x - 150) >= 0 and (_y + 200) <= 600) {
		smer = 2;

	}
	else if (_x  >= 0 and _y+50 <= 600) {
		smer = 3;

	}
	else smer = 4;
	isRect = true;
	numfire++;
}

Rect Rect::addFire(const Rect& a, int& numFire, int smer) {
	Rect c;
	c.isRect = 1;
	c._w = 50;
	c._h = 50;
	c._r = 255;
	c._g = 140;
	c._b = 0;
	c._a = 255;
	c._x = a._x;
	c._y = a._y - 50;

	if (smer==1) {
		if (numFire < 4) {
			c._y = a._y + 50;
			c._x = a._x;

			numFire++;
			return c;
		}
		else if (numFire == 4) {
			c._x = a._x + 50;
			c._y = a._y;
			numFire++;
			return c;
		}
		else if (numFire < 8) {
			c._x = a._x;
			c._y = a._y - 50;
			numFire++;
			return c;
		}
		else if (numFire == 8) {
			c._x = a._x + 50;
			c._y = a._y;
			numFire++;
			return c;

		}
		else if (numFire < 12) {
			c._x = a._x;
			c._y = a._y + 50;
			numFire++;
			return c;

		}

	}
	else if (smer == 2) {
		if (numFire < 4) {
			c._y = a._y + 50;
			c._x = a._x;

			numFire++;
			return c;
		}
		else if (numFire == 4) {
			c._x = a._x - 50;
			c._y = a._y;
			numFire++;
			return c;
		}
		else if (numFire < 8) {
			c._x = a._x;
			c._y = a._y - 50;
			numFire++;
			return c;
		}
		else if (numFire == 8) {
			c._x = a._x - 50;
			c._y = a._y;
			numFire++;
			return c;

		}
		else if (numFire < 12) {
			c._x = a._x;
			c._y = a._y + 50;
			numFire++;
			return c;

		}

	}
	else if (smer == 3) {
		if (numFire < 4) {
			c._y = a._y - 50;
			c._x = a._x;

			numFire++;
			return c;
		}
		else if (numFire == 4) {
			c._x = a._x + 50;
			c._y = a._y;
			numFire++;
			return c;
		}
		else if (numFire < 8) {
			c._x = a._x;
			c._y = a._y + 50;
			numFire++;
			return c;
		}
		else if (numFire == 8) {
			c._x = a._x + 50;
			c._y = a._y;
			numFire++;
			return c;

		}
		else if (numFire < 12) {
			c._x = a._x;
			c._y = a._y - 50;
			numFire++;
			return c;

		}







	}
	else if (smer == 4) {
		if (numFire < 4) {
			c._y = a._y - 50;
			c._x = a._x;

			numFire++;
			return c;
		}
		else if (numFire == 4) {
			c._x = a._x - 50;
			c._y = a._y;
			numFire++;
			return c;
		}
		else if (numFire < 8) {
			c._x = a._x;
			c._y = a._y + 50;
			numFire++;
			return c;
		}
		else if (numFire == 8) {
			c._x = a._x - 50;
			c._y = a._y;
			numFire++;
			return c;

		}
		else if (numFire < 12) {
			c._x = a._x;
			c._y = a._y - 50;
			numFire++;
			return c;

		}



		
	}else return c;
}

void Rect::FirecheckBorders(Rect player) {
	if (_x < player._x + player._w && _x + _w > player._x && _y < player._y + player._h && _y + _h > player._y) {
		isRect = false;
		
	}

}



void Rect::playerCheckBorders(Rect &player) {

	if ((_x < player._x + player._w )&&( _x + _w) > (player._x )&&( _y) <( player._y + player._h) && (_y + _h )> (player._y)) {
		
		int lol=_x + 50 - player._x + 50 -100;
		player._x = player._x - lol;
		cout << "\ncollision " << lol<<endl;
	}



}

void Rect::checkIfFire(Rect fire,bool &is123) {
	if (isRect) {
		if (_x < fire._x + fire._w && _x + _w > fire._x&& _y < fire._y + fire._h && _y + _h > fire._y) {
			is123 = true;

		}
	}
}

void Rect::checkFire(int& a, int& b, Rect fire,bool &c) {
	bool yes=1;

	if (isRect == 1) {
		if (_x < fire._x + fire._w && _x + _w > fire._x&& _y < fire._y + fire._h && _y + _h > fire._y) {
			c = true;
			a = _x; b = _y;
			
		}
		
	}


}

Rect::Rect(int x, int y, string MultiNacionalke) {
	isRect = 1;
	_r = 0;
	_g = 0;
	_b = 0;
	
	_a = 255;
	_x = x;
	_y = y;
	_w = 50;
	_h = 50;



}

Rect::Rect(string cutTrees, int x, int y) {
	isRect = 1;
	_w = 50;
	_h = 50;
	_x = x;
	_y = y;
	_r = 139;
	_g = 69;
	_b = 19;
	_a = 255;


}


void Rect::ShuffleLocation(Window c){
	_x = rand() % (c._width - 50);
	_y = rand() % (c._height - 50);


}