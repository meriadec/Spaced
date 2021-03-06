/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:45:43 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/11 09:49:13 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS
# define PLAYER_CLASS

# include "Unit.class.hpp"

class Player : public Unit {

  public:

    Player (void);
    Player (Player const & ref);
    ~Player (void);

    Player & operator= (Player const & ref);

    int   getLifes (void) const;
    void  die (void);

  private:

    int   _lifes;

};

#endif
