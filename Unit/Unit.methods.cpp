/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.methods.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:08:43 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 20:08:19 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstdlib>
#include "Unit.class.hpp"
#include "Spaced.hpp"

void Unit::takeDamage (int dmg)
{
  unsigned int  j = 0;
  unsigned int  i = 0;

  this->_health -= dmg;
  if (this->_health <= 0) {

    while (j < this->getHeight()) {
      i = 0;
      while (i < this->getWidth()) {
        mvwaddch(getGame()->getWin(), j + this->getLastY(), i + this->getLastX(), ' ');
        ++i;
      }
      ++j;
    }

    this->setX(getGame()->getWidth());
    this->setY(std::rand() % getGame()->getHeight());
  }
}

void Unit::setGeometry (std::string const filename)
{
  int           y = 0;
  std::string   line;
  size_t        length;
  std::ifstream file (("sprites/" + filename).c_str());

  this->_height = 0;
  this->_width = 0;

  if (file.is_open()) {
    while (getline(file, line)) {

      length = line.length();

      this->_geometry[y] = new char[line.length()];
      std::copy(line.begin(), line.end(), this->_geometry[y]);
      this->_geometry[y][length] = '\0';

      this->_height++;
      if (length > this->_width) {
        this->_width = length;
      }
      ++y;
    }
    file.close();
  }
}

int max (int a, int b) {
  return a > b ? a : b;
}

int min (int a, int b) {
  return a < b ? a : b;
}

bool Unit::isCollisioned (IObject const & other) const
{
  int x11 = this->getX();
  int y11 = this->getY();
  int x12 = x11 + this->getWidth();
  int y12 = y11 + this->getHeight();
  int x21 = other.getX();
  int y21 = other.getY();
  int x22 = x21 + other.getWidth();
  int y22 = y21 + other.getHeight();
  int x_overlap = max(0, min(x12, x22) - max(x11, x21));
  int y_overlap = max(0, min(y12, y22) - max(y11, y21));

  if (!x_overlap || !y_overlap) { return false; }

  return true;
}

void Unit::move (float const x, float const y)
{
  if (x < 0) {
    this->_x = 0;
    return ;
  }
  if (y < 0) {
    this->_y = 0;
    return ;
  }
  if (y + this->_height >= getGame()->getHeight()) {
    return ;
  }
  if (x + this->_width >= getGame()->getWidth()) {
    return ;
  }

  this->_x = x;
  this->_y = y;
}

void Unit::shoot (int dX)
{
  bool isPlayer = (dX == 1);

  for (unsigned int i = 0; i < 30; i++) {
    if (!this->_bullets[i].isActive()) {
      (void)isPlayer;
      this->_bullets[i].setCoordinates(this->_x + this->_width + 1, (this->_y + this->_height / 2));
      this->_bullets[i].setDX(dX);
      this->_bullets[i].setActive(1);
      return ;
    }
  }

}
