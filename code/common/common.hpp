/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:09:23 by AleXwern          #+#    #+#             */
/*   Updated: 2024/09/02 00:43:38 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

static constexpr uint32_t WINW = 1280;
static constexpr uint32_t WINH = 720;

struct 			t_dim
{
	double		x;
	double		y;
	double		z;
};

struct 			t_dimint
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	z;
};
