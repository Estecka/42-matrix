/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frustrum.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:07:12 by abaur             #+#    #+#             */
/*   Updated: 2023/04/01 15:48:17 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Frustrum.hpp"
#include "Remap.hpp"
#include <cmath>

namespace ft
{
	static const BBox3f	default_NDC = {
		{{ -1.0f, -1.0f, -1.0f }},
		{{  1.0f,  1.0f,  1.0f }},
	};

	Frustrum	Frustrum::FromPinhole(float fov, float aspect, float near, float far){
		Frustrum	r;

		r.near = -near;
		r.far  = -far;

		r.right = std::tan(fov/2);
		r.left  = -r.right;

		r.top    = r.right / aspect;
		r.bottom = -r.top;

		return r;
	}

	Vector3f	Frustrum::getMin() const{
		return Vector3f({
			left   * near / far,
			bottom * near / far,
			near,
		});
	}

	Vector3f	Frustrum::getMax() const{
		return Vector3f({
			right, 
			top,
			far,
		});
	}

	Matrix4f	Frustrum::projection() const {
		float	width  = right - left;
		float	height = top - bottom;
		float	depth  = far - near;

		// The matrix here appear as transposed
		return Matrix<float,4,4>({
			{ 2*-far/width,                   0,  (left+right)/width,  0 },
			{            0,       2*-far/height,                   0,  0 },
			{            0, (bottom+top)/height,   -(near+far)/depth, -1 },
			{            0,                   0,    2*near*far/depth,  0 },
		});
	}

	Matrix4f	Frustrum::projection(const BBox3f& ndc) const {
		return Remap(default_NDC, ndc).mul_mat(this->projection());
	}

}
