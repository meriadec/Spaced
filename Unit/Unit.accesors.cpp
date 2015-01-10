/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.accesors.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:02:48 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 18:36:59 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unit.class.hpp"

char ** Unit::getGeometry (void) const
{
  return this->_geometry;
}

unsigned int Unit::getWidth (void) const
{
  return this->_width;
}

unsigned int Unit::getHeight (void) const
{
  return this->_height;
}

float Unit::getX (void) const
{
  return this->_x;
}

float Unit::getY (void) const
{
  return this->_y;
}

int Unit::getXV (void) const
{
  return this->_xV;
}

int Unit::getYV (void) const
{
  return this->_yV;
}

unsigned int Unit::getVelocity (void) const
{
  return this->_vel;
}

void Unit::setXV (int xv)
{
  this->_xV = xv;
}

void Unit::setYV (int yv)
{
  this->_yV = yv;
}

