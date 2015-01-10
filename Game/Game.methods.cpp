/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.methods.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:11:09 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 14:55:49 by mpillet          ###   ########.fr       */
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
