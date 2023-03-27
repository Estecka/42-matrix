/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:23:33 by abaur             #+#    #+#             */
/*   Updated: 2023/03/27 15:50:01 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Matrix.hpp"

namespace ft
{
	Matrix<float,4,4>	projection(float fov, float ratio, float near, float far);
	Matrix<float,4,4>	frustrum(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax);
}
