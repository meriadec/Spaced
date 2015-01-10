/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:56:13 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 14:53:49 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_CLASS
# define UNIT_CLASS

# include <iostream>
# include <string>
# include "Game.class.hpp"

class Unit {

  public:

    Unit (std::string const filename);
    Unit (Unit const & ref);
    ~Unit (void);

    Unit & operator= (Unit const & ref);

    unsigned int     getWidth    (void) const;
    unsigned int     getHeight   (void) const;
    char **          getGeometry (void) const;

    void    setGeometry (std::string const filename);

  private:

    Unit (void);

    unsigned int     _width;
    unsigned int     _height;
    char **          _geometry;

};

#endif
