/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.constructors.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:56:44 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 14:01:07 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Game.class.hpp"

Game::Game (void)
{
  if (!initscr()) {
    exit(1);
  }

  this->_win = newwin(MAX_HEIGHT, MAX_WIDTH, 0, 0);

  noecho();
  nodelay(this->_win, true);
  keypad(this->_win, true);
  wmove(this->_win, 0, 0);
}

Game::Game (Game const & ref)
{
  *this = ref;
}

Game::~Game (void)
{
  delwin(this->_win);
  endwin();
  wrefresh(this->_win);
}

Game & Game::operator= (Game const & ref)
{
  (void) ref;
  return *this;
}


