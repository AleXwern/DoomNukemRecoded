/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:18:30 by AleXwern          #+#    #+#             */
/*   Updated: 2024/08/31 17:21:05 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "doom.hpp"
#include "map.hpp"
#include "gameloop.hpp"

int WinMain(void)
{
	Window window;
	Stagemap map;
	map.create_stagemap();
	gameloop(map, window);
	return 0;
}
