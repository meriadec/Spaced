/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.constructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 16:43:47 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 18:23:29 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"

Bullet::Bullet (void): _damage(10),
                       _active(0),
                       _c('o'),
                       _vel(40),
                       _x(0),
                       _y(0),
                       _dX(0),
                       _color(5)
{
}

Bullet::Bullet (Bullet const & ref)
{
  *this = ref;
}

Bullet::~Bullet (void)
{
}

Bullet & Bullet::operator= (Bullet const & ref)
{
  (void) ref;
  return *this;
}
