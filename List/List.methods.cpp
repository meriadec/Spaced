/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.methods.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:10:40 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/10 15:47:32 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.class.hpp"

void List::val (void * val)
{
  this->_val = val;
}

void List::next (void * val)
{
  this->_next = new List(val);
}

void List::loop (void (*f)(List * el))
{
  List * tmp = this;

  while (tmp) {
    f(tmp);
    tmp = tmp->next();
  }
}

int List::length (void)
{
  List * tmp = this;
  int i = 0;

  while (tmp) {
    i++;
    tmp = tmp->next();
  }
  return (i);
}
