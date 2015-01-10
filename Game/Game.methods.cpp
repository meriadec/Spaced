/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.methods.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:11:09 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 19:56:58 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Game.class.hpp"

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
    if (ch == 65) {
      this->_player.setYV(-1);
    } else if (ch == 66) {
      this->_player.setYV(1);
    } else if (ch == 67) {
      this->_player.setXV(1);
    } else if (ch == 68) {
      this->_player.setXV(-1);
    }
  }
}

void Game::update (double t, double dt)
{
  (void)t;

  if (this->_player.getXV() == 1) {
    this->_player.move(this->_player.getX() + dt * this->_player.getVelocity(), this->_player.getY());
  } else if (this->_player.getYV() == 1) {
    this->_player.move(this->_player.getX(), this->_player.getY() + dt * this->_player.getVelocity());
  } else if (this->_player.getXV() == -1) {
    this->_player.move(this->_player.getX() - dt * this->_player.getVelocity(), this->_player.getY());
  } else if (this->_player.getYV() == -1) {
    this->_player.move(this->_player.getX(), this->_player.getY() - dt * this->_player.getVelocity());
  }

  this->_player.setXV(0);
  this->_player.setYV(0);
}

void Game::render (void)
{
  wclear(this->_win);

  this->draw(this->_player);

  wrefresh(this->_win);
}

void Game::draw (Unit const & unit)
{
  unsigned int i = 0;
  unsigned int j;
  char ** geo = unit.getGeometry();

  while (i < unit.getHeight() && (i + unit.getY()) < MAX_HEIGHT) {
    j = 0;
    while (j < unit.getWidth() && (j + unit.getX()) < MAX_WIDTH) {
      mvwaddch(this->_win, int(i + unit.getY()), int(j + unit.getX()), geo[i][j]);
      ++j;
    }
    ++i;
  }
}
