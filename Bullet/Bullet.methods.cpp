/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.methods.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 18:39:07 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 20:02:22 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"
#include "Spaced.hpp"

void Bullet::move (float const x, float const y)
{
  (void) x;
  (void) y;
}

bool Bullet::isCollisioned (IObject const & other) const
{
  mvwprintw(getGame()->getWin(), getGame()->getHeight() - 10, 0, "[X: %d, Y: %f])", int(this->_x), this->_y);
  if (this->_x >= other.getX() && this->_x < (other.getX() + other.getWidth())
      && this->_y >= other.getY() && this->_y < (other.getY() + other.getHeight())) {
    return true;
  }
  return false;
}
