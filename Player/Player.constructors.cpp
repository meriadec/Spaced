/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.constructors.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:48:37 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/10 19:04:05 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player (void) : Unit("player_1")
{
  this->_vel = 1;
}

Player::Player (Player const & ref) : Unit(ref)
{
  *this = ref;
}

Player::~Player (void)
{
}

Player & Player::operator= (Player const & ref)
{
  Unit::operator=(ref);
  return *this;
}
