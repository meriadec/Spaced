/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.methods.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:11:09 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 11:09:44 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <stdlib.h>
#include "Game.class.hpp"

void Game::init (void)
{
  if (!initscr()) {
    exit(1);
  }

  int h, w;

  getmaxyx(stdscr, h, w);
  this->_height = h;
  this->_width = w;

  this->_win = newwin(h, w, 0, 0);

  noecho();
  nodelay(stdscr, 1);
  keypad(stdscr, 1);
  wmove(this->_win, 0, 0);
  curs_set(0);
}

void Game::destroy (void)
{
  delwin(this->_win);
  endwin();
  wrefresh(this->_win);
}

void Game::loop (void)
{
  double    t   = 0.0;
  double    dt  = 1.0 / 10.0;

  while (1) {
    this->acquire();
    this->update(t, dt);
    this->render();
    t += dt;
  }
}

void Game::acquire (void)
{
  int ch;

  if ((ch = getch()) != ERR) {
    if (ch == KEY_UP) {
      this->_player.setYV(-1);
    } else if (ch == KEY_DOWN) {
      this->_player.setYV(1);
    } else if (ch == KEY_RIGHT) {
      this->_player.setXV(1);
    } else if (ch == KEY_LEFT) {
      this->_player.setXV(-1);
    }
  }
}

void Game::update (double t, double dt)
{
  (void)t;

  if (this->_player.getYV() == 1) {
    this->_player.move(this->_player.getX() + dt * this->_player.getVelocity(), this->_player.getY());
  } else if (this->_player.getXV() == 1) {
    this->_player.move(this->_player.getX(), this->_player.getY() + dt * this->_player.getVelocity());
  } else if (this->_player.getYV() == -1) {
    this->_player.move(this->_player.getX() - dt * this->_player.getVelocity(), this->_player.getY());
  } else if (this->_player.getXV() == -1) {
    this->_player.move(this->_player.getX(), this->_player.getY() - dt * this->_player.getVelocity());
  }

  this->_player.setXV(0);
  this->_player.setYV(0);
}

void Game::render (void)
{
  this->draw(this->_player);
  this->drawStats();
  wrefresh(this->_win);
}

void Game::draw (Unit & unit)
{
  unsigned int  i     = 0;
  unsigned int  j;
  unsigned int  x     = int(unit.getX());
  unsigned int  y     = int(unit.getY());
  char **       geo   = unit.getGeometry();

  while (i < unit.getHeight()) {
    j = 0;
    while (j < unit.getWidth()) {
      mvwaddch(this->_win, i + unit.getLastX(), j + unit.getLastY(), ' ');
      ++j;
    }
    ++i;
  }

  i = 0;
  while (i < unit.getHeight()) {
    j = 0;
    while (j < unit.getWidth()) {
      mvwaddch(this->_win, i + x, j + y, geo[i][j]);
      ++j;
    }
    ++i;
  }

  unit.setLastX(x);
  unit.setLastY(y);
}

void Game::drawStats (void)
{
  mvwprintw(this->_win, this->_height - 1, 0, "[%d, %d] ",
      int(this->_player.getX()),
      int(this->_player.getY()));
}
