/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.accesors.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:08:16 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 12:00:20 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"

WINDOW * Game::getWin (void) const
{
  return this->_win;
}

int Game::getWidth (void) const
{
  return this->_width;
}

int Game::getHeight (void) const
{
  return this->_height;
}

Player & Game::getPlayer (void)
{
  return this->_player;
}
