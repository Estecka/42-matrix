/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.proj.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:39:17 by abaur             #+#    #+#             */
/*   Updated: 2023/03/30 16:28:14 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proj.hpp"

#include <iostream>

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

	float fov   = GetArgF(argv[1]);
	float ratio = GetArgF(argv[2]);
	float near  = GetArgF(argv[3]);
	float far   = GetArgF(argv[4]);

	ft::Matrix<float,4,4> mx = ft::projection(fov, ratio, near, far);

	mx = mx.transpose();
	
	for (int y=0; y<4; y++){
		for (int x=0; x<4; x++)
		{
			if (x)
				std::cout << ", ";
			std::cout << mx[x][y];
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}
