/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:06:35 by AleXwern          #+#    #+#             */
/*   Updated: 2024/09/02 01:25:58 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <math.h>

#include "common.hpp"
#include "entity.hpp"
#include "doom.hpp"
#include "map.hpp"

class Camera
{
private:
	void	shootRay(Stagemap &stagemap);

	t_dim		cam;
	t_dim		raydir;
	t_dimint	map;

	t_dim		deltadir;
	t_dim		side;
	t_dimint	step;

public:
	Camera(const t_dimint pixel, const Player player)
	{
		setDefaults(pixel, player);
		rayPreparation(player);
	}

	void	setDefaults(const t_dimint pixel, const Player player)
	{
		cam.x = 2.0 * pixel.x / (double)WINW - 1.0;
		cam.y = 2.0 * pixel.y / (double)WINH - 1.0;
		raydir.x = player.getDirection().x + player.getPlane().x * cam.x;
		raydir.y = player.getDirection().y + player.getPlane().y * cam.x;
		raydir.z = player.getDirection().z + player.getPlane().z * cam.y;
		map.x = ((int)player.getPosition().x);
		map.y = ((int)player.getPosition().y);
		map.z = ((int)player.getPosition().z);
	}

	void	rayPreparation(const Player player)
	{
		deltadir.x = fabs(1 / raydir.x);
		deltadir.y = fabs(1 / raydir.y);
		deltadir.z = fabs(1 / raydir.z);
		if (raydir.x < 0)
		{
			step.x = -1;
			side.x = (player.getPosition().x - map.x) * deltadir.x;
		}
		else
		{
			step.x = 1;
			side.x = (map.x + 1.0 - player.getPosition().x) * deltadir.x;
		}
		if (raydir.y < 0)
		{
			step.y = -1;
			side.y = (player.getPosition().y - map.y) * deltadir.y;
		}
		else
		{
			step.y = 1;
			side.y = (map.y + 1.0 - player.getPosition().y) * deltadir.y;
		}
		if (raydir.z < 0)
		{
			step.z = -1;
			side.z = (player.getPosition().z - map.z) * deltadir.z;
		}
		else
		{
			step.z = 1;
			side.z = (map.z + 1.0 - player.getPosition().z) * deltadir.z;
		}
	}

	void	castRay(Stagemap &tiles);
};

void	render_walls(Stagemap &stagemap, Window &window);
