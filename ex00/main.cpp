/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:35 by abaur             #+#    #+#             */
/*   Updated: 2023/02/14 22:26:12 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "../TestFactory.hpp"
#include "vector_tester.hpp"

#include "../logutil/logutil.hpp"

#include <iostream>
#include <cstring>
#include <exception>

#define N_MAX	4
#define M_MAX	4

static ft::TesterType	GetTest(const std::string& mode, const std::string& subcmd, int n, int m){
	(void)m;
	ft::TesterMap testmap;
	ft::TestFactory<ft::VectorTestSuit, float, N_MAX>(testmap);
	return testmap[n];
}

extern int main(int argc, char** argv){

	if (argc < 5){
		std::cerr << "Not enough arguments" << std::endl;
		return EXIT_FAILURE;
	}

	std::string mode = argv[1];
	std::string subcmd = argv[2];
	int n = std::atoi(argv[3]);
	int m = 0;

	ft::TesterType	tester = GetTest(mode, subcmd, n, m);

	if (tester == NULL){
		std::cerr << "Test not implemented" << std::endl;
		return EXIT_FAILURE;
	}
	else try
	{
		tester(argc, argv);
	}
	catch(std::exception& e)
	{
		ft::clog << ft::log::error << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}