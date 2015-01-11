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
#include "Level.class.hpp"

Level::Level (void)
{
}

Level::Level (std::string & title, unsigned int nb, unsigned int nbSprites, char *sprites[]) : _title(title)
{
  this->_units = new Unit[nb];
  for (unsigned int i = 0; i < nb; i++) {
    this->_units[i].setGeometry(sprites[std::rand() % nbSprites]);
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
