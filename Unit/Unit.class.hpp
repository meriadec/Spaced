/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:56:13 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 16:46:37 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_CLASS
# define UNIT_CLASS

# include <iostream>
# include <string>

# define MAX_HEIGHT 89
# define MAX_WIDTH 364

class Unit {

  public:

    Unit (std::string const filename);
    Unit (Unit const & ref);
    ~Unit (void);

    Unit & operator= (Unit const & ref);

    unsigned int     getWidth    (void) const;
    unsigned int     getHeight   (void) const;
    unsigned int     getX        (void) const;
    unsigned int     getY        (void) const;
    char **          getGeometry (void) const;

    void            setGeometry (std::string const filename);
    bool            areCollisioned (Unit const & one, Unit const & two) const;
    virtual void    move (unsigned int const x, unsigned int const y) = 0;

  private:

    Unit (void);

    unsigned int     _width;
    unsigned int     _height;
    unsigned int     _x;
    unsigned int     _y;
    char **          _geometry;

};

#endif
