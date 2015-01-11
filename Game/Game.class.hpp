/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:55:30 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 11:01:38 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS
# define GAME_CLASS

# include <iostream>
# include <string>
# include <ncurses.h>
# include "Unit.class.hpp"
# include "Player.class.hpp"
# include "List.class.hpp"

class Game {

  public:

    Game  (void);
    ~Game (void);

    WINDOW * getWin (void) const;
    int      getWidth (void) const;
    int      getHeight (void) const;

    void  loop      (void);
    void  update    (double t, double dt);
    void  render    (void);
    void  draw      (Unit & unit);
    void  drawStats (void);
    void  acquire   (void);
    void  init      (void);
    void  destroy   (void);

  private:

    Game & operator= (Game const & ref);
    Game (Game const & ref);

    WINDOW *  _win;
    List *    _enemies;
    Player    _player;
    int       _height;
    int       _width;

};

#endif
