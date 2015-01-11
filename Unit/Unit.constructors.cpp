/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.constructors.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:57:20 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 10:59:32 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unit.class.hpp"

Unit::Unit (void): _width(0),
                   _height(0),
                   _x(0),
                   _y(0),
                   _xV(0),
                   _yV(0),
                   _vel(5),
                   _lastX(0),
                   _lastY(0)
{
  this->_geometry = new char*[MAX_HEIGHT];
}

Unit::Unit (std::string const filename): _width(0),
                                         _height(0),
                                         _x(0),
                                         _y(0),
                                         _xV(0),
                                         _yV(0),
                                         _vel(5),
                                         _lastX(0),
                                         _lastY(0)
{
  this->_geometry = new char*[MAX_HEIGHT];
  this->setGeometry(filename);
}

Unit::Unit (Unit const & ref)
{
  *this = ref;
}

Unit::~Unit (void)
{
  for (int j = 0; j < MAX_HEIGHT; j++) {
    delete this->_geometry[j];
  }
  delete this->_geometry;
}

Unit & Unit::operator= (Unit const & ref)
{
  this->_height = ref.getHeight();
  this->_width = ref.getWidth();
  this->_x = ref.getX();
  this->_y = ref.getY();
  this->_xV = ref.getXV();
  this->_yV = ref.getYV();
  this->_vel = ref.getVelocity();

  // TODO make sure no deep copy
  this->_geometry = ref.getGeometry();

  return *this;
}
