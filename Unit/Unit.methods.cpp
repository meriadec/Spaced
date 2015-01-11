/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.methods.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:08:43 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 11:11:19 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "Unit.class.hpp"
#include "Spaced.hpp"

void Unit::setGeometry (std::string const filename)
{
  int           i = 0;
  std::string   line;
  size_t        length;
  std::ifstream file (("sprites/" + filename).c_str());

  this->_height = 0;
  this->_width = 0;

  if (file.is_open()) {
    while (getline(file, line)) {

      length = line.length();

      std::copy(line.begin(), line.end(), this->_geometry[i]);
      this->_geometry[i][length] = '\0';

      this->_height++;
      if (length > this->_width) {
        this->_width = length;
      }
      ++i;
    }
    file.close();
  }
}

bool Unit::areCollisioned (IObject const & one, IObject const & two) const
{
  unsigned int i = 0;
  unsigned int j;
  char ** geoOne = one.getGeometry();
  char ** geoTwo = two.getGeometry();

  // TODO handle specific geometry
  (void)geoOne;
  (void)geoTwo;
  (void)i;
  (void)j;


  return false;
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
  if (x + this->_height >= getGame()->getHeight()) {
    return ;
  }
  if (y + this->_width >= getGame()->getWidth()) {
    return ;
  }

  this->_x = x;
  this->_y = y;
}
