/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frustrum.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:07:12 by abaur             #+#    #+#             */
/*   Updated: 2023/04/06 15:51:58 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Frustrum.hpp"
#include "Remap.hpp"
#include <cmath>

namespace ft
{
	Frustrum	Frustrum::FromPinhole(float fov, float aspect, float _near, float _far){
		Frustrum	r;

		r.near = -_near;
		r.far  = -_far;

		r.right = std::tan(fov/2) * _far;
		r.left  = -r.right;

		r.top    = r.right / aspect;
		r.bottom = -r.top;

		return r;
	}

	Vector3f	Frustrum::getPoint(const Vector3f& norm) const {
		Vector3f p;

		p[2] = ft::lerp(near,   far, norm[2]);
		p[1] = ft::lerp(bottom, top, norm[1]) * p[2]/far;
		p[0] = ft::lerp(left, right, norm[0]) * p[2]/far;

		return p;
	}

	Vector3f	Frustrum::getMin() const{
		return getPoint({{0,0,0}});
	}

	Vector3f	Frustrum::getMax() const{
		return getPoint({{1,1,1}});
	}

	Matrix4f	Frustrum::projection(const BBox3f& ndc) const {
		Matrix<float,4,4> m;

		m[0][0] = -far * (ndc.max[0] - ndc.min[0]) / (right -   left);
		m[1][1] = -far * (ndc.max[1] - ndc.min[1]) / (  top - bottom);

		m[2][0] = -(right*ndc.min[0] -   left*ndc.max[0]) / (right -   left);
		m[2][1] = -(  top*ndc.min[1] - bottom*ndc.max[1]) / (  top - bottom);
		m[2][2] = -(  far*ndc.max[2] -   near*ndc.min[2]) / (  far -   near);

		m[3][2] = -near*far * (ndc.min[2] - ndc.max[2]) / (far - near);

		m[2][3] = -1;

		return m;
	}

}
