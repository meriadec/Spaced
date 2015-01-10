/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:07:29 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 19:46:07 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "Game.class.hpp"
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

int main (void)
{
  Player    player;
  Game      game(player);

  signal(SIGWINCH, resize);
  signal(SIGSEGV, segv);

  game.loop();

  return (0);
}
