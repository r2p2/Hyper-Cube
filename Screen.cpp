/*
 * Screen.cpp
 *
 *  Created on: 04.04.2010
 *      Author: r2p2
 */

#include "Screen.h"

#include <curses.h>

Screen::Screen()
:width(COLS), height(LINES)
{
	init_canvas();
}

Screen::~Screen()
{
	free_canvas();
}

void Screen::free_canvas()
{
	canvas.clear();
}

void Screen::init_canvas()
{
	for(int i = 0; i < height; i++)
	{
		std::string s(width, ' ');
		canvas.push_back(s);
	}
}

bool Screen::is_size_changed()
{
	return width != COLS || height != LINES;
}

void Screen::on_size_changed()
{
	free_canvas();
	width = COLS;
	height = LINES;
	init_canvas();
}

void Screen::render()
{
	for(unsigned int i = 0; i < canvas.size(); i++)
	{
		mvaddstr(i,0, canvas[i].c_str());
	}
	refresh();
}
