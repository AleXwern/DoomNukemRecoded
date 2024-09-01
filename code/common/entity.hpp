/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:12:51 by AleXwern          #+#    #+#             */
/*   Updated: 2024/09/02 01:18:20 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "common.hpp"

class Player
{
private:
	t_dim	pos;
	t_dim	dir;
	t_dim	plane;
	
public:
	Player(double winh, double winw)
	{
		pos = {4, 4, 1};
		dir = {1, 0, 0};
		plane = {0, 0, 0.5};
		plane.y = 0.5 / winh / winw;
	}

	t_dim	getPosition(void) const
	{
		return pos;
	}

	t_dim	getDirection(void) const
	{
		return dir;
	}

	t_dim	getPlane(void) const
	{
		return plane;
	}
};
