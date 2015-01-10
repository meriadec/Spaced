/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:59:11 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/10 15:59:45 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_CLASS
# define LIST_CLASS

#include <string>

class List {

  public:

    List (void);
    List (void * val);
    List (List const & ref);
    ~List (void);

    List & operator= (List const & ref);

    void *        val     (void) const;
    List *        next    (void) const;
    int           length  (void);

    void          val     (void * val);
    void          next    (void * val);
    void          loop    (void (*f)(List * el));

  private:

    void *        _val;
    List *        _next;

};

#endif
