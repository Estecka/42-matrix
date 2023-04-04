/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frustrum.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:07:12 by abaur             #+#    #+#             */
/*   Updated: 2023/04/04 15:15:30 by abaur            ###   ########.fr       */
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

	Matrix4f	Frustrum::projection(const BBox3f& ndc) const {
		Matrix<float,4,4> m;

		m[0][0] = far * (near*ndc.min[0] - far*ndc.max[0]) / (far*right - near*left  );
		m[1][1] = far * (near*ndc.min[1] - far*ndc.max[1]) / (far*top   - near*bottom);
		m[2][2] =       (near*ndc.min[2] - far*ndc.max[2]) / (far       - near       );

		m[3][0] = near*far * (  left*ndc.max[0] - right*ndc.min[0]) / (far*right - near*left  );
		m[3][1] = near*far * (bottom*ndc.max[1] -   top*ndc.min[1]) / (far*top   - near*bottom);
		m[3][2] = near*far * (       ndc.max[2] -       ndc.min[2]) / (far       - near       );

		m[2][3] = -1;

		return m;
	}

}
