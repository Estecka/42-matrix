/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:24:51 by abaur             #+#    #+#             */
/*   Updated: 2023/03/27 15:28:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proj.hpp"

#include <cmath>

namespace ft
{
	Matrix<float,4,4>	projection(float fov, float ratio, float near, float far){
		float	width  = 2 * std::tan(fov);
		float	height = width / ratio;
		float	depth  = far - near;


		return Matrix<float,4,4>({
			{ 2*near/width,             0,                0,                0 },
			{            0, 2*near/height,                0,                0 },
			{            0,             0, (near+far)/depth, 2*near*far/depth },
			{            0,             0,               -1,                0 },
		});
	}
}
