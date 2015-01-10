/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:55:30 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 14:56:30 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS
# define GAME_CLASS

# include <iostream>
# include <string>
# include <ncurses.h>

class Game {

  public:

    Game (void);
    ~Game (void);

    WINDOW * getWin (void) const;

    void  loop    (void);
    void  update  (double t, double dt);
    void  render  (void);

  private:

    Game & operator= (Game const & ref);
    Game (Game const & ref);

    WINDOW *  _win;

};

#endif
