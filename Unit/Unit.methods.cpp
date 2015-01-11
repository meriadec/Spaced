/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.methods.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:08:43 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 11:58:17 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "Unit.class.hpp"
#include "Spaced.hpp"

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

bool Unit::isCollisioned (IObject const & other) const
{
  if (this->getX() < (other.getX() + other.getWidth()) &&
      (this->getX() + this->getWidth()) > other.getX() &&
      this->getY() < (other.getY() + other.getHeight()) &&
      (this->getY() + this->getHeight()) > other.getY()) {
    return true;
  } else {
    // TODO handle specific geometry
    return false;
  }
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
