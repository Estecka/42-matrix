/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:23:33 by abaur             #+#    #+#             */
/*   Updated: 2023/03/23 16:25:02 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Matrix.hpp"

namespace ft
{
	Matrix<float,4,4>	projection(float fov, float ratio, float near, float far);
}
