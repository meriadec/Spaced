/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IObject.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 09:28:01 by bgronon           #+#    #+#             */
/*   Updated: 2015/01/11 12:00:48 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOBJECT_CLASS
# define IOBJECT_CLASS

class Unit;

class IObject {

  public:

    virtual ~IObject (void) {};

    virtual char **          getGeometry (void) const = 0;
    virtual float            getX        (void) const = 0;
    virtual float            getY        (void) const = 0;
    virtual unsigned int     getWidth    (void) const = 0;
    virtual unsigned int     getHeight   (void) const = 0;

    virtual void    move (float const x, float const y) = 0;
    virtual bool    areCollisioned (IObject const & one, IObject const & two) const = 0;

};

#endif
