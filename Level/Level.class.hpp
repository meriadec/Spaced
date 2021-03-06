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

    Level (std::string title, float speed, unsigned int nb, unsigned int nbSprites, std::string sprites[]);
    Level (Level const & ref);
    ~Level (void);

    Level & operator= (Level const & ref);

    void  start     (void);
    void  loop      (void);
    void  acquire   (void);
    int   update    (double t, double dt);
    void  render    (void);
    void  draw      (Unit & unit, int color);
    void  draw      (Bullet & unit);
    void  drawStats (void);
    void  over      (void);

    unsigned int        getNb     (void) const;
    Unit *              getUnits  (void) const;
    std::string const & getTitle  (void) const;
    int                 getRemainingNumber (void) const;
    void                setBoss(void);

  private:

    Level (void);

    std::string     _title;
    unsigned int    _nb;
    Unit *          _units;
    float           _speed;

};

#endif
