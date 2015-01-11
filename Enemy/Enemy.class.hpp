/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:46:54 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/11 11:02:50 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS
# define ENEMY_CLASS

# include "Unit.class.hpp"

class Enemy : public Unit {

  public:

    Enemy (void);
    Enemy (Enemy const & ref);
    ~Enemy (void);

    Enemy & operator= (Enemy const & ref);

};

#endif
