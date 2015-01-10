/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.methods.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:08:43 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 16:28:28 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "Unit.class.hpp"

void Unit::setGeometry (std::string const filename)
{
  int           i = 0;
  std::string   line;
  size_t        length;
  std::ifstream file (filename.c_str());

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

bool Unit::areCollisioned (Unit const & one, Unit const & two) const
{
  unsigned int i = 0;
  unsigned int j;
  char ** geoOne = one.getGeometry();
  char ** geoTwo = two.getGeometry();

  while (i < one.getHeight() && i < two.getHeight()) {
    j = 0;
    while (j < one.getWidth() && i < two.getWidth()) {
      if (geoOne[i][j] != ' ' && geoTwo[i][j] != ' ') {
        return true;
      }
      ++j;
    }
    ++i;
  }
  return false;
}
