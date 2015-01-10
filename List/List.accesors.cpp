/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.accesors.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:59:16 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/10 15:59:39 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.class.hpp"

void * List::val (void) const
{
  return this->_val;
}

List * List::next (void) const
{
  return this->_next;
}
