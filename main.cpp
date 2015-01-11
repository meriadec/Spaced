/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:07:29 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 11:11:03 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>

#include "Game.class.hpp"
#include "Level.class.hpp"
#include "Unit.class.hpp"

void resize (int sig)
{
  (void) sig;
  printw("No resize...");
}

void segv (int sig)
{
  (void) sig;
  std::cout << "SEGFAULT BITCH, RESETTING..." << std::endl;
  endwin();
}

Game * getGame (void)
{
  static Game * out = NULL;

  if (!out) {
    out = new Game();
  }

  return out;
}

int main (void)
{
  Game    * game = getGame();

  game->init();

  std::srand(time(NULL));
  signal(SIGWINCH, resize);
  signal(SIGSEGV, segv);

  game->loop();

  game->destroy();

  delete game;

  return (0);
}
