/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:38:25 by AleXwern          #+#    #+#             */
/*   Updated: 2024/09/02 01:24:05 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <stdlib.h>

#include "entity.hpp"

struct s_tile
{
	uint16_t	type;
};

class Stagemap
{
public:
	Stagemap():
		player(1280.0, 720.0)
	{
		width = 25;
		height = 3;
		depth = 25;
	}

	Stagemap(uint32_t w, uint32_t h, uint32_t d):
		player(1280.0, 720.0)
	{
		width = w;
		height = h;
		depth = d;
	}

	void setWidth(uint32_t newWidth)
	{
		width = newWidth;
	}
	
	void setHeight(uint32_t newHeight)
	{
		height = newHeight;
	}

	void setDepth(uint32_t newDepth)
	{
		depth = newDepth;
	}

	uint32_t getWidth(void)
	{
		return width;
	}
	
	uint32_t getHeight(void)
	{
		return height;
	}

	uint32_t getDepth(void)
	{
		return depth;
	}

	s_tile	*getMapPointer(void)
	{
		return	tiles;
	}

	uint32_t coordToVal(uint32_t x, uint32_t y, uint32_t z)
	{
		return (y * width * height) + (z * width) + x;
	}

	bool	isOOB(uint32_t x, uint32_t y, uint32_t z)
	{
		return coordToVal(x, y, z) > coordToVal(width, height, depth);
	}

	s_tile	getTile(uint32_t x, uint32_t y, uint32_t z)
	{
		uint32_t pos = x + (y * width) + (z * width * height);
		return tiles[pos];
	}

	Player getPlayer(void)
	{
		return	player;
	}

	void create_stagemap();
	void create_stagemap(char *file);
private:
	// Constants
	enum
	{
		TILE_AIR,
		TILE_WALL
	};

	// Variables
	uint32_t	width;
	uint32_t	height;
	uint32_t	depth;
	s_tile		*tiles;

	Player		player;
};
