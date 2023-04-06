/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.proj.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:39:17 by abaur             #+#    #+#             */
/*   Updated: 2023/04/06 11:28:49 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proj.hpp"
#include "Frustrum.hpp"
#include "BoundingBox.hpp"
#include "Remap.hpp"
#include "Format.hpp"

#include <iostream>

static void	AnalyseMx(const ft::Matrix4f& pmx, const ft::Frustrum& frus){
	ft::Vector4f	vertices[2][2][2];
	ft::Vector4f	ndc[2][2][2];

	ft::Vector3f& min = (ft::Vector3f&)ndc[0][0][0];
	ft::Vector3f& max = (ft::Vector3f&)ndc[1][1][1];

	for (int x=0; x<2; x++)
	for (int y=0; y<2; y++)
	for (int z=0; z<2; z++){
		vertices[x][y][z] = (ft::Vector4f)frus.getPoint({{(float)x, (float)y, (float)z}});
		vertices[x][y][z][3] = 1;

		ndc[x][y][z] = pmx.mul_vec(vertices[x][y][z]);
		ndc[x][y][z] /= ndc[x][y][z][3];

		std::cerr << LOG_CYAN "ndc"<<x<<y<<z << " = " << (ft::Vector3f)ndc[x][y][z] << LOG_CLEAR;
		if (z)
			std::cerr << std::endl;
		else
			std::cerr << '\t';
	}

	std::cerr << "The matrix's NDC is        "
	             LOG_BOLD_YELLOW "[" << (ft::Vector3f)min << "] to [" << (ft::Vector3f)max << "]"
	             LOG_CLEAR << std::endl;
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
	bool transpose = false;
	if (argc >= 7 && !std::strcmp(argv[6], "-t"))
		transpose = true;
 
	frustrum = ft::Frustrum::FromPinhole(fov, aspect, near, far);
	ft::BBox3f& fAsBbox = *(ft::BBox3f*)&frustrum;
	std::cerr << "The frustrum dimensions are [" << fAsBbox.min << "] to [" << fAsBbox.max << "]" << std::endl;
	std::cerr << "The frustrum's corners are  [" << frustrum.getMin() << "] to [" << frustrum.getMax() << "]" << std::endl;

	projMx = frustrum.projection(ndc);
	AnalyseMx(projMx, frustrum);
	ft::PrintM(projMx, std::cerr);

	if (transpose)
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
