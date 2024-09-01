/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:50:11 by AleXwern          #+#    #+#             */
/*   Updated: 2024/09/02 01:12:48 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <string.h>

void Stagemap::create_stagemap()
{
	uint32_t layer = width * depth;

	tiles = (s_tile*)malloc(sizeof(s_tile) * width * height * depth);
	memset(tiles,			  			0x0101, sizeof(s_tile) * layer);
	memset(tiles + coordToVal(0, 1, 0),	0x0000, sizeof(s_tile) * layer);
	memset(tiles + coordToVal(0, 2, 0), 0x0101, sizeof(s_tile) * layer);
	
	for (uint32_t i = 0; i < width; i++)
	{
		tiles[coordToVal(i , 0, 0)].type = TILE_WALL;
		tiles[coordToVal(i , 0, 24)].type = TILE_WALL;
	}
	for (uint32_t i = 0; i < height; i++)
	{
		tiles[coordToVal(0 , 0, i)].type = TILE_WALL;
		tiles[coordToVal(24 , 0, i)].type = TILE_WALL;
	}
}
