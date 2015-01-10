/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.constructors.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:59:13 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/10 16:08:32 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "List.class.hpp"

List::List (void) : _val(NULL), _next(NULL)
{
}

List::List (void * val) : _val(val), _next(NULL)
{
}

List::List (List const & ref)
{
  *this = ref;
}

List::~List (void)
{
  List * tmp = this->next();
  List * tmp2 = NULL;

  while (tmp) {
    tmp2 = tmp->next();
    delete tmp;
    tmp = tmp2;
  }
}

List & List::operator= (List const & ref)
{
  this->_val = ref.val();
  this->_next = ref.next();
  return *this;
}
