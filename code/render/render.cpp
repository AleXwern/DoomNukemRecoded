/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:28:35 by AleXwern          #+#    #+#             */
/*   Updated: 2024/09/02 01:30:15 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.hpp"

void	render_walls(Stagemap &stagemap, Window &window)
{
	//uint32_t	color = 0;
	t_dimint	pixel;
	
	for (pixel.x = 0; pixel.x < window.getScreenWidth(); pixel.x++)
	{
		for (pixel.y = 0; pixel.y < window.getScreenHeight(); pixel.y++)
		{
			Camera camera(pixel, stagemap.getPlayer());
			camera.castRay(stagemap);
		}
	}
}

void	Camera::castRay(Stagemap &stagemap)
{
	shootRay(stagemap);
}

void	Camera::shootRay(Stagemap &stagemap)
{
	bool	hit = 0;

	while (!hit)
	{
		if (stagemap.isOOB(map.x, map.y, map.z))
			return;
		hit = true;
	}
}
