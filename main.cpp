/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:07:29 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 15:01:57 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "Game.class.hpp"
#include "Unit.class.hpp"

void resize (int sig)
{
  (void) sig;
  std::cout << "RESIZE" << std::endl;
}

void segv (int sig)
{
  (void) sig;
  std::cout << "SEGFAULT BITCH, RESETTING..." << std::endl;
  endwin();
}

int main(void)
{
  Unit u = Unit("ship");

  u.getGeometry();
  return 2;
  Game game;

  signal(SIGWINCH, resize);
  signal(SIGSEGV, segv);

  int ch;
  while (1) {

    wclear(game.getWin());

    if ((ch = getch()) != ERR) {
      waddch(game.getWin(), ch | A_UNDERLINE);
      mvaddch(52, 52, 'A');
    }

    wrefresh(game.getWin());
    usleep(100);
  }

  return (0);
}
