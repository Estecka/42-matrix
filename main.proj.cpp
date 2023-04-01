/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.proj.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:39:17 by abaur             #+#    #+#             */
/*   Updated: 2023/04/01 15:10:18 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proj.hpp"
#include "Frustrum.hpp"
#include "BoundingBox.hpp"
#include "Remap.hpp"

#include <iostream>

static ft::BBox3f	AnalyseMx(const ft::Matrix4f& pmx, const ft::Frustrum& frus){
	ft::BBox3f clip;
	ft::Vector4f min = (ft::Vector4f)frus.getMin();
	ft::Vector4f max = (ft::Vector4f)frus.getMax();
	min[3] = 1;
	max[3] = 1;

	min = pmx.mul_vec(min);
	max = pmx.mul_vec(max);

	clip.min = (ft::Vector3f)min;
	clip.max = (ft::Vector3f)max;

	min /= min[3];
	max /= max[3];

	std::cerr << "The matrix's clip space is [" << clip.min << "] to [" << clip.max << "]" << std::endl;
	std::cerr << "The matrix's NDC is        [" << (ft::Vector3f)min << "] to [" << (ft::Vector3f)max << "]" << std::endl;

	return clip;
}

static ft::BBox3f	GetNDC(const char* argv){
	ft::BBox3f ndc;

	ndc.min = ft::Vector3f::StrToVec(argv, &argv);
	if (*argv)
		argv++;
	ndc.max = ft::Vector3f::StrToVec(argv, &argv);

	return ndc;
}

static float	GetArgF(const char* argv){
	float r;
	char* endptr;

	r = std::strtof(argv, &endptr);
	if (*endptr){
		std::cerr << "Invalid argument: " << argv << std::endl;
		exit(EXIT_FAILURE);
	}

	return r;
}

extern int	main(int argc, char** argv){
	if (argc < 5){
		std::cerr << "Not enough arguments" << std::endl;
		return EXIT_FAILURE;
	}

	ft::Matrix4f	projMx;
	ft::Frustrum	frustrum;

	float fov    = GetArgF(argv[1]);
	float aspect = GetArgF(argv[2]);
	float near   = GetArgF(argv[3]);
	float far    = GetArgF(argv[4]);
	bool  hasCustomNDC = false;
	ft::BBox3f ndc;
	if (argc >= 6 ){
		hasCustomNDC = true;
		ndc = GetNDC(argv[5]);
	}
 
	frustrum = ft::Frustrum::FromPinhole(fov, aspect, near, far);
	ft::BBox3f& fAsBbox = *(ft::BBox3f*)&frustrum;
	std::cerr << "The frustrum dimensions are [" << fAsBbox.min << "] to [" << fAsBbox.max << "]" << std::endl;

	projMx = frustrum.projection();
	ft::BBox3f srcClip = AnalyseMx(projMx, frustrum);

	if (hasCustomNDC){
		std::cerr << "Changing the matrix NDC." << std::endl;
		projMx = ft::Remap(srcClip, ndc).mul_mat(projMx);
		AnalyseMx(projMx, frustrum);
	}

	projMx = projMx.transpose();
	for (int y=0; y<4; y++){
		for (int x=0; x<4; x++)
		{
			if (x)
				std::cout << ", ";
			std::cout << projMx[x][y];
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}
