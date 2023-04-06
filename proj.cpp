/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:24:51 by abaur             #+#    #+#             */
/*   Updated: 2023/04/06 15:52:04 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proj.hpp"
#include "Frustrum.hpp"

namespace ft
{
	static const ft::BBox3f	g_ndc = {
		.min = {{-1, -1, 0}},
		.max = {{ 1,  1, 1}},
	};

	Matrix<float,4,4>	projection(float fov, float aspect, float near, float far){
		return Frustrum::FromPinhole(fov, aspect, near, far).projection(g_ndc);
	}
}
