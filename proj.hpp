/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:23:33 by abaur             #+#    #+#             */
/*   Updated: 2023/04/06 15:40:24 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Matrix.hpp"

namespace ft
{
	/**
	 * @brief	The projection function as required in the subject.
	 * Assumes a NDC of [-1,-1, 0][ 1, 1, 1]
	 * 
	 * @param fov	The horizontal field of view.
	 * @param aspect	The width/height ratio  of the screen.
	 */
	Matrix<float,4,4>	projection(float fov, float aspect, float near, float far);
}
