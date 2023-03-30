/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:24:51 by abaur             #+#    #+#             */
/*   Updated: 2023/03/30 12:23:29 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proj.hpp"

#include <cmath>

namespace ft
{
	Matrix<float,4,4>	projection(float fov, float ratio, float near, float far){
		float	width  = 2 * std::tan(fov/2);
		float	height = width / ratio;
		float	depth  = far - near;

		// The matrix here appear as transposed
		return Matrix<float,4,4>({
			{ 2*near/width,             0,                 0,  0 },
			{            0, 2*near/height,                 0,  0 },
			{            0,             0, -(near+far)/depth, -1 },
			{            0,             0, -2*near*far/depth,  0 },
		});
	}

	Matrix<float,4,4>	frustrum(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax){
		float	width  = xMax - xMin;
		float	height = yMax - yMin;
		float	depth  = zMax - zMin;

		// The matrix here appear as transposed
		return Matrix<float,4,4>({
			{ 2*-zMax/width,                  0,  (xMin+xMax)/width,  0 },
			{             0,     2*-zMax/height,                  0,  0 },
			{             0, (yMin+yMax)/height,  (zMax+zMin)/depth, -1 },
			{             0,                  0, -2*zMax*zMin/depth,  0 },
		});
	}
}
