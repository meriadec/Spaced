/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.accesors.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:02:48 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 15:22:41 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unit.class.hpp"

char ** Unit::getGeometry (void) const
{
  return this->_geometry;
}

unsigned int Unit::getWidth (void) const
{
  return this->_height;
}

unsigned int Unit::getHeight (void) const
{
  return this->_width;
}

unsigned int Unit::getY (void) const
{
  return this->_y;
}

unsigned int Unit::getX (void) const
{
  return this->_x;
}
