/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.constructors.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:56:44 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 10:39:24 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"

Game::Game (void)
{
}

Game::Game (Game const & ref)
{
  *this = ref;
}

Game::~Game (void)
{
}

Game & Game::operator= (Game const & ref)
{
  (void) ref;
  return *this;
}
