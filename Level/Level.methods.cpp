/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.methods.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 12:11:24 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/11 12:47:34 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "Spaced.hpp"
#include "Level.class.hpp"
#include "Game.class.hpp"

void Level::start (void)
{
  int ch;
  Game * game = getGame();

  std::string s1 ("[ SPACED ]");
  std::string s2 ("Welcome to " + this->_title + "!");
  std::string s3 ("Please press enter.");

  while (1) {

    mvwprintw(game->getWin(), game->getHeight() / 2 - 5, game->getWidth() / 2 - s1.length() / 2, s1.c_str());
    wattrset(game->getWin(), COLOR_PAIR(3));
    mvwprintw(game->getWin(), game->getHeight() / 2, game->getWidth() / 2 - s2.length() / 2, s2.c_str());
    wattroff(game->getWin(), COLOR_PAIR(3));
    mvwprintw(game->getWin(), game->getHeight() / 2 + 2, game->getWidth() / 2 - s3.length() / 2, s3.c_str());

    wrefresh(game->getWin());
    if ((ch = getch()) != ERR) {
      if (ch == ' ') {
        werase(game->getWin());
        break ;
      }
    }
  }
}

void Level::loop (void)
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

void Level::acquire (void)
{
  int ch;

  if ((ch = getch()) != ERR) {
    if      (ch == KEY_DOWN)  { PLYR.setYV(1);  }
    else if (ch == KEY_UP)    { PLYR.setYV(-1); }
    else if (ch == KEY_RIGHT) { PLYR.setXV(1);  }
    else if (ch == KEY_LEFT)  { PLYR.setXV(-1); }
  }
}

void Level::update (double t, double dt)
{

  (void) t;

  // Moving player
  // -------------

  if (PLYR.getXV() == 1) {
    PLYR.move(PLYR.getX() + dt * PLYR.getVelocity(), PLYR.getY());
  } else if (PLYR.getYV() == 1) {
    PLYR.move(PLYR.getX(), PLYR.getY() + dt * PLYR.getVelocity());
  } else if (PLYR.getXV() == -1) {
    PLYR.move(PLYR.getX() - dt * PLYR.getVelocity(), PLYR.getY());
  } else if (PLYR.getYV() == -1) {
    PLYR.move(PLYR.getX(), PLYR.getY() - dt * PLYR.getVelocity());
  }

  PLYR.setXV(0);
  PLYR.setYV(0);

  // Moving enemies
  // --------------

  Unit * unit;

  // boucle dans ennemis
  // si xmin, xmax
  // si xmax, on fait un rand y
  // deplacement vers la gauche en fonction de vitesse
  for (unsigned int i = 0; i < this->getNb(); i++) {

    unit = &((this->getUnits())[i]);

    if (unit->getX() <= 0)                      { unit->setX(getGame()->getWidth()); }
    if (unit->getX() == getGame()->getWidth())  { unit->setY(std::rand() % getGame()->getHeight()); }

    unit->setX(unit->getX() - dt * this->_speed * unit->getVelocity());

  }
}

void Level::render (void)
{
  Game * game = getGame();

  this->draw(game->getPlayer());

  // boucle dans ennemis
  // draw
  Unit * units = this->getUnits();

  for (unsigned int i = 0; i < this->getNb(); i++) {
    this->draw(units[i]);
  }

  this->drawStats();
  wrefresh(game->getWin());
}

void Level::draw (Unit & unit)
{
  Game * game = getGame();

  unsigned int  j     = 0;
  unsigned int  i     = 0;
  unsigned int  x     = int(unit.getX());
  unsigned int  y     = int(unit.getY());
  char **       geo   = unit.getGeometry();

  while (j < unit.getHeight()) {
    i = 0;
    while (i < unit.getWidth()) {
      mvwaddch(game->getWin(), j + unit.getLastY(), i + unit.getLastX(), ' ');
      ++i;
    }
    ++j;
  }

  j = 0;
  while (j < unit.getHeight()) {
    i = 0;
    while (i < unit.getWidth()) {
      mvwaddch(game->getWin(), j + y, i + x, geo[j][i] | COLOR_PAIR(1));
      ++i;
    }
    ++j;
  }

  unit.setLastX(x);
  unit.setLastY(y);
}

void Level::drawStats (void)
{
  Game * game = getGame();

  mvwprintw(game->getWin(), game->getHeight() - 1, 0, "GAME (w:%d h:%d) == [Y: %d, X: %d] (width: %d, height: %d)",
      game->getWidth(),
      game->getHeight(),
      int(game->getPlayer().getY()),
      int(game->getPlayer().getX()),
      game->getPlayer().getWidth(),
      game->getPlayer().getHeight());
}
