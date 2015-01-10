/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.methods.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

void Player::move (float const x, float const y)
{
  if (x < 0) {
    this->_x = 0;
    return ;
  }
  if (y < 0) {
    this->_y = 0;
    return ;
  }
  if (x + this->_height >= MAX_HEIGHT) {
    return ;
  }
  if (y + this->_width >= MAX_WIDTH) {
    return ;
  }

  this->_x = x;
  this->_y = y;
}
