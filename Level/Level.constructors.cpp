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
#include "Spaced.hpp"

Level::Level (void)
{
}

Level::Level (std::string title, unsigned int nb, unsigned int nbSprites, std::string sprites[]) : _title(title), _nb(nb)
{
  this->_units = new Unit[nb];
  for (unsigned int i = 0; i < nb; i++) {
    this->_units[i].setGeometry(sprites[std::rand() % nbSprites]);
    this->_units[i].setVelocity(10 + (std::rand() % 30));
    this->_units[i].setX(getGame()->getWidth());
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
