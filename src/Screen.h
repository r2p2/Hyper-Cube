/*
 * Screen.h
 *
 *  Created on: 04.04.2010
 *      Author: r2p2
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <vector>
#include <string>
#include <curses.h>

class Screen
{
  WINDOW *window;
   
  void init_canvas();
  void free_canvas();
public:
  Screen();
  virtual ~Screen();

  bool is_size_changed();
  void on_size_changed();
  void render();
  
  int key_pressed();

  int width;
  int height;
  std::vector<std::string> canvas;
};

#endif /* SCREEN_H_ */
