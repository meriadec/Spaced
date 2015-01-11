/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:56:13 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 10:22:21 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_CLASS
# define UNIT_CLASS

# include <iostream>
# include <string>

# include "IObject.class.hpp"

# define MAX_HEIGHT 89
# define MAX_WIDTH 364

class Unit : public IObject {

  public:

    Unit (std::string const filename);
    Unit (Unit const & ref);
    ~Unit (void);

    Unit & operator= (Unit const & ref);

    unsigned int     getWidth    (void) const;
    unsigned int     getHeight   (void) const;
    float            getX        (void) const;
    float            getY        (void) const;
    int              getLastX    (void) const;
    int              getLastY    (void) const;
    int              getXV       (void) const;
    int              getYV       (void) const;
    char **          getGeometry (void) const;
    unsigned int     getVelocity (void) const;

    void             setXV        (int xv);
    void             setYV        (int yv);
    void             setLastX     (int x);
    void             setLastY     (int y);

    void            setGeometry (std::string const filename);
    bool            areCollisioned (IObject const & one, IObject const & two) const;
    void            move (float const x, float const y);

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
    int              _lastX;
    int              _lastY;
    char **          _geometry;

};

#endif
