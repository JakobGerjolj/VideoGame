#include "window.h"
#include <iostream>
#include <SDL_ttf.h>
using namespace std;

SDL_Renderer* Window::_renderer= nullptr ;

Window::Window(const string& title, int width, int height) :
	_title(title), _width(width), _height(height)
{

	_closed = !init();
}



Window::~Window() 
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	SDL_Quit();

}

bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Faield to initaliese SDL.h\n";
		return 0;
	}
	if (TTF_Init() == -1) {
		cout << "Faield to initaliese TTF\n";
		return 0;

	}

	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height, 0

	);

	if (_window == nullptr) {
		cout << "Failed to create window.\n";
		return 0;

	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (_renderer == nullptr) {
		cout << "Failed to create renderer.\n";
		return 0;

	}


	return true;
}

void Window::pollEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			_closed = true;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				_closed = true;
				break;

			}

		default:
			break;

		}

	}

}

void Window::clear() const {
	SDL_RenderPresent(_renderer);
	SDL_SetRenderDrawColor(_renderer, 34, 139, 34, 255);
	SDL_RenderClear(_renderer);
	
}