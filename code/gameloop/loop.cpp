/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:56:15 by AleXwern          #+#    #+#             */
/*   Updated: 2024/09/02 01:28:52 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.hpp"
#include "map.hpp"
#include "render.hpp"

void gameloop(Stagemap &map, Window &window)
{
	SDL_Event event;

	Uint32 colour = SDL_MapRGB(window.getSurface()->format, 0, 0, 0);
	Uint8 bit = 0;

	while (1)
	{
		(void)map;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				break;
		}
		bit += 0xf;
		colour = SDL_MapRGB(window.getSurface()->format, bit, bit, bit);
		window.fill_texture(NULL, colour);
		render_walls(map, window);
		window.updateScreen();
	}
}
