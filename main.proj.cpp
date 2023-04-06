/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.proj.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:39:17 by abaur             #+#    #+#             */
/*   Updated: 2023/04/06 17:35:32 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proj.hpp"
#include "Frustrum.hpp"
#include "BoundingBox.hpp"
#include "Remap.hpp"
#include "Format.hpp"

#include <iostream>
#include <stdnoreturn.h>


static float fov, aspect, near, far;
static ft::BBox3f	ndc = {
	{{-1,-1, 0}},
	{{ 1, 1, 1}}
};
static bool	doTranspose = false;
static float	scalar = 1;


static int	Help(const char* argv0){
	std::cout <<
"usage: "<<argv0<<" <fov> <aspect> <near> <far> [-t] [-ndc=<ndc>] [-s=<scalar>]\n"
"\n"
"	-t	Transposes the matrix written on stdout\n"
"	-ndc	Generates a matrix with for a specific NDC. Default: \"-1,-1,0;1,1,1\"\n"
"	-s	Scales the matrix. Default: 1\n"
"		This shouldn't really change the result of the projection.\n"
	<< std::flush;

	return EXIT_SUCCESS;
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
static ft::BBox3f	GetNDC(const char* argv){
	ft::BBox3f ndc;

	try {
		ndc.min = ft::Vector3f::StrToVec(argv, &argv);
		if (*argv)
			argv++;
		ndc.max = ft::Vector3f::StrToVec(argv, &argv);
	}
	catch (std::exception& e) {
		std::cerr << "Invalid NDC: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	return ndc;
}
static void	GetArguments(int argc, const char*const* argv){
	if (argc < 5) {
		std::cerr << "Not enough arguments." << std::endl;
		exit(EXIT_FAILURE);
	}

	fov    = GetArgF(argv[1]);
	aspect = GetArgF(argv[2]);
	near   = GetArgF(argv[3]);
	far    = GetArgF(argv[4]);

	
	for (argc-=5,argv+=5; argc>0; argc--,argv++)
	{
		if (!std::strcmp(*argv, "-t"))
			doTranspose = true;

		else if (std::strcmp(*argv, "-ndc") == '=')
			ndc = GetNDC(*argv + 5);

		else if (std::strcmp(*argv, "-s") == '=')
			scalar = GetArgF(*argv + 3);

		else {
			std::cerr << "Unknown argument: " << *argv << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}


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

		std::cerr << LOG_CYAN "ndc"<<x<<y<<z << " = " << (ft::Vector3f&)ndc[x][y][z] << LOG_CLEAR;
		if (z)
			std::cerr << std::endl;
		else
			std::cerr << '\t';
	}

	std::cerr << "The matrix's NDC is: "
	             LOG_BOLD_YELLOW "[" << (ft::Vector3f&)min << "]" LOG_CLEAR 
	             " to " 
	             LOG_BOLD_YELLOW "[" << (ft::Vector3f&)max << "]" LOG_CLEAR
	          << std::endl;
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

extern int	main(int argc, char** argv){
	if (argc < 2)
		return Help(argv[0]);

	ft::Matrix4f	projMx;
	ft::Frustrum	frustrum;
	ft::BBox3f& 	frAsBbox = (ft::BBox3f&)frustrum;

	GetArguments(argc, argv);

	frustrum = ft::Frustrum::FromPinhole(fov, aspect, near, far);
	std::cerr << "The frustrum's bouding box is       [" << frAsBbox.min      << "] to [" << frAsBbox.max       << "]" << std::endl;
	std::cerr << "The frustrum's extreme corners are  [" << frustrum.getMin() << "] and [" << frustrum.getMax() << "]" << std::endl;

	projMx = frustrum.projection(ndc);
	AnalyseMx(projMx, frustrum);
	ft::PrintM(projMx, std::cerr);

	if (doTranspose)
		projMx = projMx.transpose();
	if (scalar != 1)
		projMx *= scalar;

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
