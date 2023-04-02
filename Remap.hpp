/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Remap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 10:14:28 by abaur             #+#    #+#             */
/*   Updated: 2023/04/01 15:26:12 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
#include "BoundingBox.hpp"

/*
y = ((x - iMin)/(iMax-iMin) * (oMax-oMin)) + oMin
  = ((x - iMin) * (oMax-oMin)/(iMax-iMin)) + oMin
  = (x(oMax-oMin)/(iMax-iMin) - iMin(oMax-oMin)/(iMax-iMin)) + oMin
  = x(oMax-oMin)/(iMax-iMin) - iMin(oMax-oMin)/(iMax-iMin) + oMin

Let scalar = (oMax-oMin)/(iMax-iMin)

y = x*scalar - iMin*scalar + oMin

f(x) = ax + b
a = scalar
b = -iMin*scalar + oMin
*/

namespace ft
{

	/**
	 * @brief Generates a matrix that remaps vectors from one bounding box 
	 * 	to another.
	 */
	template <class K, int N>
	Matrix<K, N+1, N+1>	Remap(const BoundingBox<K,N>& src, const BoundingBox<K,N>& dst);
	
}



/******************************************************************************/
/* # Implementations                                                          */
/******************************************************************************/

namespace ft
{
	template <class K, int N>
	Matrix<K, N+1, N+1>	Remap(const BoundingBox<K,N>& i, const BoundingBox<K,N>& o) {
		Matrix<K, N+1, N+1>	result;

		for (int n=0; n<N; n++)
		{
			float scalar = (o.max[n] - o.min[n]) / (i.max[n] - i.min[n]);
			result[n][n] = scalar;
			result[N][n] = -i.min[n]*scalar + o.min[n];
		}

		result[N][N] = 1;
		
		return result;
	}
	
}
