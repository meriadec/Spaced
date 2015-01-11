/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.accesors.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 13:09:24 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/11 13:14:19 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Level.class.hpp"

unsigned int Level::getNb (void) const
{
  return this->_nb;
}

std::string const & Level::getTitle (void) const
{
  return this->_title;
}

Unit * Level::getUnits (void) const
{
  return this->_units;
}
