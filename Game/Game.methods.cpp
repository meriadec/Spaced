/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.methods.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:11:09 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 16:25:27 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Game.class.hpp"

void Game::loop (void)
{
  double    t   = 0.0;
  double    dt  = 1.0 / 60.0;

  while (1) {
    this->update(t, dt);
    this->render();
    t += dt;
  }
}

void Game::update (double t, double dt)
{
  std::cout << "updating with time " << t << " and delta time " << dt << std::endl;
}

void Game::render (void)
{
  std::cout << "rendering" << std::endl;
}

void Game::draw (Unit const & unit)
{
  unsigned int i = 0;
  unsigned int j;
  char ** geo = unit.getGeometry();

  while (i < unit.getHeight() && (i + unit.getY()) < MAX_HEIGHT) {
    j = 0;
    while (j < unit.getWidth() && (j + unit.getX()) < MAX_WIDTH) {
      mvwaddch(this->_win, i, j, geo[i][j]);
      ++j;
    }
    ++i;
  }
}
