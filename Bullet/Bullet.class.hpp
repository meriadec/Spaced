/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 16:38:55 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 18:18:31 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS
# define BULLET_CLASS

# include "IObject.class.hpp"

class Bullet : public IObject {

  public:

    Bullet (void);
    Bullet (Bullet const & ref);
    ~Bullet (void);

    Bullet & operator= (Bullet const & ref);

    int          getDamage   (void) const;
    int          isActive    (void) const;
    char         getChar     (void) const;
    float        getX        (void) const;
    float        getY        (void) const;
    float        getLastX    (void) const;
    float        getLastY    (void) const;
    unsigned int getVelocity (void) const;
    int          getDX       (void) const;
    int          getColor    (void) const;

    unsigned int     getWidth    (void) const;
    unsigned int     getHeight   (void) const;
    char **          getGeometry (void) const;

    void setActive      (int active);
    void setDX          (int dx);
    void setLastX       (int x);
    void setLastY       (int y);
    void setCoordinates (float x, float y);

    void move (float const x, float const y);
    bool isCollisioned (IObject const & other) const;

  private:

    int            _damage;
    int            _active;
    char           _c;
    unsigned int   _vel;
    float          _x;
    float          _y;
    int            _lastX;
    int            _lastY;
    int            _dX;
    int            _color;

};

#endif
