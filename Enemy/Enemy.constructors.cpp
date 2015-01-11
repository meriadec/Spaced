/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.constructors.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 10:47:19 by mpillet           #+#    #+#             */
/*   Updated: 2015/01/11 11:01:17 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

Enemy::Enemy (void) : Unit()
{
}

Enemy::Enemy (Enemy const & ref) : Unit(ref)
{
  *this = ref;
}

Enemy::~Enemy (void)
{
}

Enemy & Enemy::operator= (Enemy const & ref)
{
  Unit::operator=(ref);
  return *this;
}
