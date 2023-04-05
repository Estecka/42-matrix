/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.proj.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:39:17 by abaur             #+#    #+#             */
/*   Updated: 2023/04/05 09:52:24 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proj.hpp"
#include "Frustrum.hpp"
#include "BoundingBox.hpp"
#include "Remap.hpp"
#include "Format.hpp"

#include <iostream>

static ft::BBox4f	AnalyseMx(const ft::Matrix4f& pmx, const ft::Frustrum& frus){
	ft::BBox4f clip = {
		.min = (ft::Vector4f)frus.getMin(),
		.max = (ft::Vector4f)frus.getMax(),
	};
	clip.min[3] = 1;
	clip.max[3] = 1;

	clip.min = pmx.mul_vec(clip.min);
	clip.max = pmx.mul_vec(clip.max);

	// std::cerr << LOG_BLUE << pmx << LOG_CLEAR << std::endl;
	std::cerr << "The matrix's clip space is "
	             LOG_BOLD_MAGENTA "[" << clip.min << "] to [" << clip.max << "]"
	             LOG_CLEAR << std::endl;

	ft::BBox4f ndc = clip;
	ndc.min /= ndc.min[3];
	ndc.max /= ndc.max[3];
	std::cerr << "The matrix's NDC is        "
	             LOG_BOLD_YELLOW "[" << (ft::Vector3f)ndc.min << "] to [" << (ft::Vector3f)ndc.max << "]"
	             LOG_CLEAR << std::endl;

	return clip;
}

static ft::Matrix4f	CorrectNDC(const ft::Matrix4f& projMx, const ft::BBox4f& srcClip, const ft::BBox3f& dstNDC){
	ft::BBox4f dstClip;
	dstClip.min = (ft::Vector4f)dstNDC.min;
	dstClip.max = (ft::Vector4f)dstNDC.max;
	dstClip.min *= srcClip.min[3];
	dstClip.max *= srcClip.max[3];
	dstClip.min[3] = srcClip.min[3];
	dstClip.max[3] = srcClip.max[3];

	ft::Matrix<float,5,4> correctionMx = (ft::Matrix<float,5,4>)ft::Remap(srcClip, dstClip);
	std::cerr << "\nNDC correction matrix:" << std::endl;
	// std::cerr << LOG_BLUE << correctionMx << LOG_CLEAR << std::endl;
	ft::PrintM(correctionMx, std::cerr);	
	
	ft::Matrix<float,4,5> proj5 = (ft::Matrix<float,4,5>)projMx;
	proj5[3][4] = 1; // Bottom right cell
		
	return correctionMx.mul_mat(proj5);
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
	if (argc < 6){
		std::cerr << "Not enough arguments" << std::endl;
		return EXIT_FAILURE;
	}

	ft::Matrix4f	projMx;
	ft::Frustrum	frustrum;

	float fov    = GetArgF(argv[1]);
	float aspect = GetArgF(argv[2]);
	float near   = GetArgF(argv[3]);
	float far    = GetArgF(argv[4]);
	ft::BBox3f ndc = GetNDC(argv[5]);
 
	frustrum = ft::Frustrum::FromPinhole(fov, aspect, near, far);
	ft::BBox3f& fAsBbox = *(ft::BBox3f*)&frustrum;
	std::cerr << "The frustrum dimensions are [" << fAsBbox.min << "] to [" << fAsBbox.max << "]" << std::endl;

	projMx = frustrum.projection(ndc);
	AnalyseMx(projMx, frustrum);
	ft::PrintM(projMx, std::cerr);

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
