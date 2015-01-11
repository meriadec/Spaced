/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.constructors.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:23:22 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/11 10:45:24 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Level.class.hpp"

Level::Level (void)
{
}

Level::Level (std::string title, unsigned int nb, unsigned int nbSprites, std::string sprites[]) : _title(title), _nb(nb)
{
  std::string geo;

  this->_units = new Unit[nb];
  for (unsigned int i = 0; i < nb; i++) {
    geo = sprites[std::rand() % nbSprites];
    this->_units[i].setGeometry(geo);
    this->_units[i].setVelocity(10 + (std::rand() % nbSprites));
  }
}

Level::Level (Level const & ref)
{
  *this = ref;
}

Level::~Level (void)
{
}

Level & Level::operator= (Level const & ref)
{
  (void) ref;
  return *this;
}
