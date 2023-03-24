/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:24:51 by abaur             #+#    #+#             */
/*   Updated: 2023/03/23 16:28:22 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proj.hpp"

namespace ft
{
	Matrix<float,4,4>	projection(float fov, float ratio, float near, float far){
		Matrix <float,4,4> result;
		result[3][3] = 1;

		return result;
	}
}
