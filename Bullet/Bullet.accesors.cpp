/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.accesors.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 16:54:12 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 18:17:19 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"

char ** Bullet::getGeometry (void) const
{
  return 0;
}

unsigned int Bullet::getWidth (void) const
{
  return 1;
}

unsigned int Bullet::getHeight (void) const
{
  return 1;
}

int Bullet::getDamage (void) const
{
  return this->_damage;
}

int Bullet::isActive (void) const
{
  return this->_active;
}

int Bullet::getColor (void) const
{
  return this->_color;
}

char Bullet::getChar (void) const
{
  return this->_c;
}

float Bullet::getX (void) const
{
  return this->_x;
}

float Bullet::getY (void) const
{
  return this->_y;
}

float Bullet::getLastX (void) const
{
  return this->_lastX;
}

float Bullet::getLastY (void) const
{
  return this->_lastY;
}

unsigned int Bullet::getVelocity (void) const
{
  return this->_vel;
}

int Bullet::getDX (void) const
{
  return this->_dX;
}

void Bullet::setActive (int active)
{
  this->_active = active;
}

void Bullet::setCoordinates (float x, float y)
{
  this->_x = x;
  this->_y = y;
}

void Bullet::setDX (int dx)
{
  this->_dX = dx;
}

void Bullet::setLastX (int x)
{
  this->_lastX = x;
}

void Bullet::setLastY (int y)
{
  this->_lastY = y;
}
