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
#include <sstream>
#include "Spaced.hpp"
#include "Level.class.hpp"
#include "Game.class.hpp"
#include "Bullet.class.hpp"

void Level::start (void)
{
  int ch;
  Game * game = getGame();

  std::string s1 ("[ SPACED ]");
  std::string s2 (" Welcome to " + this->_title + "! ");
  std::string s3 ("Please press space.");
  std::ostringstream ss;
  ss << PLYR.getLifes();
  std::string s4 ("You got " + ss.str() + " lifes left.");

  for (unsigned int i = 0; i < this->_nb; i++) {
    this->_units[i].setX(getGame()->getWidth());
  }

  PLYR.setX(4);
  PLYR.setY(4);

  while (1) {

    mvwprintw(game->getWin(), game->getHeight() / 2 - 5, game->getWidth() / 2 - s1.length() / 2, s1.c_str());
    wattrset(game->getWin(), COLOR_PAIR(4));
    mvwprintw(game->getWin(), game->getHeight() / 2, game->getWidth() / 2 - s2.length() / 2, s2.c_str());
    wattroff(game->getWin(), COLOR_PAIR(4));
    mvwprintw(game->getWin(), game->getHeight() / 2 + 2, game->getWidth() / 2 - s3.length() / 2, s3.c_str());
    mvwprintw(game->getWin(), game->getHeight() / 2 + 3, game->getWidth() / 2 - s4.length() / 2, s4.c_str());

    wrefresh(game->getWin());
    if ((ch = getch()) != ERR) {
      if (ch == ' ') {
        werase(game->getWin());
        break ;
      }
    }
  }
}

void Level::over (void)
{
  int ch;
  Game * game = getGame();
  std::string s1 ("[ SPACED ]");
  std::string s2 ("You loose!");
  std::string s3 ("Please press space to quit.");

  mvwprintw(game->getWin(), game->getHeight() / 2 - 5, game->getWidth() / 2 - s1.length() / 2, s1.c_str());
  wattrset(game->getWin(), COLOR_PAIR(4));
  mvwprintw(game->getWin(), game->getHeight() / 2, game->getWidth() / 2 - s2.length() / 2, s2.c_str());
  wattroff(game->getWin(), COLOR_PAIR(4));
  mvwprintw(game->getWin(), game->getHeight() / 2 + 2, game->getWidth() / 2 - s3.length() / 2, s3.c_str());

  wrefresh(game->getWin());
  while (1) {
    if ((ch = getch()) != ERR) {
      if (ch == ' ') {
        game->destroy();
        exit(0);
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
    if (this->update(t, dt) == 1) {
      break ;
    }
    this->render();
    t += dt;
  }
  if (PLYR.getLifes() > 0) {
    this->start();
    this->loop();
  } else if (PLYR.getLifes() == 0) {
    this->over();
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
    else if (ch == ' ') { PLYR.shoot(1); }
  }
}

int Level::update (double t, double dt)
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


  Unit * unit;

  // Moving bullets
  // --------------

  Bullet * bullets = PLYR.getBullets();
  double redBull;
  for (unsigned int i = 0; i < 30; i++) {

    if (bullets[i].getX() > getGame()->getWidth()) {
      bullets[i].setCoordinates(0, 0);
      bullets[i].setActive(0);
    }

    redBull = (bullets[i].getDX() == -1 ? -dt : dt);
    bullets[i].setCoordinates(bullets[i].getX() + redBull * this->_speed * bullets[i].getVelocity(), bullets[i].getY());

    if (bullets[i].isActive()) {
      // check intersect with all the ennemies
      for (unsigned int i = 0; i < this->getNb(); i++) {
        unit = &((this->getUnits())[i]);

        if (bullets[i].isCollisioned(*unit)) {
          unit->takeDamage(bullets[i].getDamage());
          bullets[i].setActive(0);
          bullets[i].setCoordinates(0, 0);
        }
      }
    }
  }

  // Moving enemies
  // --------------

  for (unsigned int i = 0; i < this->getNb(); i++) {

    unit = &((this->getUnits())[i]);

    if (unit->getHealth() <= 0) {
      continue ;
    }

    if (unit->getX() + unit->getWidth() <= 0)   { unit->setX(getGame()->getWidth()); }
    if (unit->getX() == getGame()->getWidth())  { unit->setY(std::rand() % getGame()->getHeight()); }

    unit->setX(unit->getX() - dt * this->_speed * unit->getVelocity());

    if (PLYR.isCollisioned(*unit)) {
      PLYR.die();
      return (1);
    }

  }
  return (0);
}

void Level::render (void)
{
  Game * game = getGame();

  this->draw(game->getPlayer(), 3);

  Bullet * bullets = PLYR.getBullets();
  for (unsigned int i = 0; i < 30; i++) {
    this->draw(bullets[i]);
  }

  Unit * units = this->getUnits();

  for (unsigned int i = 0; i < this->getNb(); i++) {
    if (units[i].getHealth() > 0) {
      this->draw(units[i], 0);
    }
  }

  this->drawStats();
  wrefresh(game->getWin());
}

void Level::draw (Unit & unit, int color)
{
  Game * game = getGame();

  unsigned int  j   = 0;
  unsigned int  i   = 0;
  unsigned int  x   = int(unit.getX());
  unsigned int  y   = int(unit.getY());
  char **       geo = unit.getGeometry();

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
      mvwaddch(game->getWin(), j + y, i + x, geo[j][i] | COLOR_PAIR(color));
      ++i;
    }
    ++j;
  }

  unit.setLastX(x);
  unit.setLastY(y);
}

void Level::draw (Bullet & unit)
{

  int  x = int(unit.getX());
  int  y = int(unit.getY());
  Game * game = getGame();

  mvwaddch(game->getWin(), unit.getLastY(), unit.getLastX(), ' ');

  if (!unit.isActive()) {
    return ;
  }

  mvwaddch(game->getWin(), y, x, unit.getChar() | COLOR_PAIR(unit.getColor()));

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
