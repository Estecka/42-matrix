/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frustrum.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:02:06 by abaur             #+#    #+#             */
/*   Updated: 2023/04/06 12:12:31 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector.hpp"
#include "Matrix.hpp"
#include "BoundingBox.hpp"

namespace ft
{
	typedef	Vector<float, 3>	Vector3f;
	typedef	Vector<float, 4>	Vector4f;
	typedef	BoundingBox<float, 3>	BBox3f;
	typedef	BoundingBox<float, 4>	BBox4f;
	typedef	Matrix<float, 4,4>	Matrix4f;

	struct	Frustrum 
	{
		// Near and far are the coordinates of the respective planes.
		// Left, right, top and bottom are the bounds of the far plane.
		float	left;
		float	bottom;
		float	near;
		float	right;
		float	top;
		float	far;

		/**
		 * @brief Generates a frustrum based on a pinhole camera's properties,
		 * 	in a right-handed coordinate system. (Forward = Z-)
		 * @param fov	The horizontal field of view
		 * @param aspect	The width/height ratio
		 */
		static Frustrum	FromPinhole(float fov, float aspect, float near, float far);

		/**
		 * @brief Get a point in the frustrum, based on its normalized coordinates.
		 */
		Vector3f	getPoint(const Vector3f& normalized) const;
		/**
		 * @brief Computes the point on the near plane in the bottom left corner
		 * 	of the screen.
		 * This point 
		 */
		Vector3f	getMin() const;
		/**
		 * @brief Computes  the point  on the far plane  in the top right corner
		 * 	of the screen
		 */
		Vector3f	getMax() const;

		/**
		 * @brief Computes the projection matrix for this frustrum.
		 * 	The NDC for this projection is [-1,-1,-1][ 1, 1, 1]
		 */
		Matrix4f	projection() const;
		/**
		 * @brief Computes the projection matrix for this frustrum, adapted to
		 * 	a specific NDC
		 */
		Matrix4f	projection(const BBox3f& ndc) const;
	};
}
