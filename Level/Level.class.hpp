/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:22:39 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/11 10:28:45 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_CLASS
# define LEVEL_CLASS

# include "Unit.class.hpp"

class Level {

  public:

    Level (std::string & title, unsigned int nb, unsigned int nbSprites, char *sprites[]);
    Level (Level const & ref);
    ~Level (void);

    Level & operator= (Level const & ref);

  private:

    Level (void);

    Unit *          _units;
    std::string     _title;

};

#endif
