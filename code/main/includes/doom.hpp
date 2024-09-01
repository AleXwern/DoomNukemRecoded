/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:47:55 by AleXwern          #+#    #+#             */
/*   Updated: 2024/09/02 01:26:49 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SDL.h>
#include <iostream>

#include "common.hpp"

class Window
{
public:
	Window()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING))
			error_out("Init error!");
		if (!(window = SDL_CreateWindow("DoomNukem", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINW, WINH, 0)))
			error_out("Window creation error!");
		if (!(renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)))
			if (!(renderer = SDL_GetRenderer(window)))
				error_out("Renderer creation error!");
		SDL_ShowWindow(window);
		create_canvas();
	}

	void create_canvas()
	{
		if (!(surface = SDL_GetWindowSurface(window)))
			error_out("Could not get window surface!");
		if (!(texture.background = SDL_CreateTextureFromSurface(renderer, surface)))
			error_out("Could not make bg texture!");
		if (!(texture.ui = SDL_CreateTextureFromSurface(renderer, surface)))
			error_out("Could not make ui texture!");
	}

	SDL_Surface *getSurface(void)
	{
		return surface;
	}

	uint32_t	getScreenWidth(void)
	{
		return WINW;
	}

	uint32_t	getScreenHeight(void)
	{
		return WINH;
	}

	void updateScreen(void)
	{
		SDL_UpdateWindowSurface(window);
	}

	void copy_texture(SDL_Texture *tex, SDL_Rect *dest, SDL_Rect *src)
	{
		SDL_RenderCopy(renderer, tex, src, dest);
	}

	void fill_texture(SDL_Rect *src, Uint32 colour)
	{
		SDL_FillRect(surface, src, colour);
	}

private:
	error_out(const char *err)
	{
		std::cout << err << '\n';
		exit(1);
	}

	// Constants

	// Variables

	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*surface;
	struct {
		SDL_Texture		*background;
		SDL_Texture		*ui;
	} texture;
	int dummy;
};
