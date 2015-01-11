/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.accesors.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:02:48 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 10:44:00 by mpillet          ###   ########.fr       */
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

int Unit::getHealth (void) const
{
  return this->_health;
}

int Unit::getLastX (void) const
{
  return this->_lastX;
}

int Unit::getLastY (void) const
{
  return this->_lastY;
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

void Unit::setVelocity (unsigned int v)
{
  this->_vel = v;
}

void Unit::setX (float x)
{
  this->_x = x;
}

void Unit::setY (float y)
{
  this->_y = y;
}

void Unit::setXV (int xv)
{
  this->_xV = xv;
}

void Unit::setYV (int yv)
{
  this->_yV = yv;
}

void Unit::setLastX (int x)
{
  this->_lastX = x;
}

void Unit::setLastY (int y)
{
  this->_lastY = y;
}
