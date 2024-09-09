#pragma once

#include <string>
using namespace std;
#include<SDL.h>

class Window {
public:

	Window(const string& title, int width, int height);
	~Window();
	Window() { };
	void pollEvents();
	void clear() const;
	inline bool isClosed() const { return _closed; }
private:
	bool init();

private:
	string _title;
public:
	int _width=800;
	int _height=600;
private:
	
	bool _closed = false;

	SDL_Window *_window = nullptr;
public:
	static SDL_Renderer* _renderer;
};