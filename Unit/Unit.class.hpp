/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unit.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:56:13 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 10:57:22 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_CLASS
# define UNIT_CLASS

# include <iostream>
# include <string>

# include "IObject.class.hpp"
# include "Bullet.class.hpp"

# define MAX_HEIGHT 89
# define MAX_WIDTH 364

class Unit : public IObject {

  public:

    Unit (void);
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
    int              getHealth   (void) const;
    char **          getGeometry (void) const;
    unsigned int     getVelocity (void) const;
    Bullet *         getBullets  (void) const;

    void             setX         (float x);
    void             setY         (float y);
    void             setXV        (int xv);
    void             setYV        (int yv);
    void             setLastX     (int x);
    void             setLastY     (int y);
    void             setVelocity  (unsigned int v);

    void            setGeometry (std::string const filename);
    bool            isCollisioned (IObject const & other) const;
    void            move (float const x, float const y);
    void            shoot (int dX);

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
    int              _health;
    Bullet *         _bullets;

};

#endif
