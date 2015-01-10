/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:56:13 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/10 18:37:01 by bgronon          ###   ########.fr       */
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
    float            getX        (void) const;
    float            getY        (void) const;
    int              getXV       (void) const;
    int              getYV       (void) const;
    char **          getGeometry (void) const;
    unsigned int     getVelocity (void) const;

    void             setXV (int xv);
    void             setYV (int yv);

    void            setGeometry (std::string const filename);
    bool            areCollisioned (Unit const & one, Unit const & two) const;
    virtual void    move (float const x, float const y) = 0;

  private:

    Unit (void);

  protected:

    unsigned int     _width;
    unsigned int     _height;
    float            _x;
    float            _y;
    int              _xV;
    int              _yV;
    unsigned int     _vel;
    char **          _geometry;

};

#endif
