/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:07:29 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 12:51:23 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "Game.class.hpp"

void resize (int sig)
{
  (void) sig;
  std::cout << "RESIZE" << std::endl;
}


int main(void)
{
  Game game;

  signal(SIGWINCH, resize);

  int i = 0;

  while (1) {
    wmove(game.getWin(), 0, i);
    int ch = getch();
    std::cout << ch << std::endl;
    waddch(game.getWin(), 'X' | A_UNDERLINE);
    wrefresh(game.getWin());
  }

  return (0);
}
