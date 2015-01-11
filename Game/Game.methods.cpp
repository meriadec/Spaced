/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.methods.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:11:09 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 11:59:33 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <stdlib.h>
#include "Game.class.hpp"
#include "Level.class.hpp"

void Game::init (void)
{
  if (!initscr()) {
    std::cout << "Could not init screen." << std::endl;
    exit(1);
  }
  if (!has_colors()) {
    endwin();
    std::cout << "Your term does not support colors." << std::endl;
    exit(1);
  }

  int h, w;

  getmaxyx(stdscr, h, w);
  this->_height = h;
  this->_width = w;

  this->_win = newwin(h, w, 0, 0);

  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_WHITE, COLOR_BLUE);
  init_pair(5, COLOR_RED, COLOR_BLACK);

  noecho();
  nodelay(stdscr, 1);
  keypad(stdscr, 1);
  wmove(this->_win, 0, 0);
  curs_set(0);
}

void Game::destroy (void)
{
  delwin(this->_win);
  delwin(stdscr);
  endwin();
}

void Game::loop (void)
{

  // Level 1
  // -------

  std::string level1_sprites[] = {
    "lv1/enemy1",
    "lv1/enemy2",
    "lv1/enemy3"
  };

  Level level1("Level 1 - Friendly fire", 0.008, 5, 3, level1_sprites);
  level1.start();
  level1.loop();

  // Level 2
  // -------

  std::string level2_sprites[] = {
    "lv2/enemy1",
    "lv2/enemy2",
    "lv2/enemy3"
  };

  Level level2("Level 2 - Mars Attack", 0.01, 10, 3, level2_sprites);
  level2.start();
  level2.loop();

}
