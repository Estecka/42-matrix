/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:35 by abaur             #+#    #+#             */
/*   Updated: 2023/02/16 18:48:45 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Matrix.hpp"
#include "TestFactory.hpp"
#include "vector_tester.hpp"
#include "matrix_tester.hpp"

#include "logutil/logutil.hpp"

#include <iostream>
#include <cstring>
#include <exception>

#define N_MAX	4
#define M_MAX	4

static void	GetDimensions(const char* str, int& outn, int& outm, int& outp){
	char* endptr;

	outn = std::strtol(str, &endptr, 10);
	if (!endptr)
		return;
	str = endptr+1;
	outm = std::strtol(str, &endptr, 10);
	if (!endptr)
		return;
	str = endptr+1;
	outp = std::strtol(str, &endptr, 10);

}

static ft::TesterType	GetTest(std::string mode, const char* dimensions){
	int n, m, p;
	GetDimensions(dimensions, n, m, p);

	if (mode == "vec")
		return ft::TestFactoryN<ft::VectorTestSuit, float, N_MAX>::GetTest(n);
	if (mode == "mx")
		return ft::TestFactoryNM<ft::MatrixTestSuit, float, N_MAX, M_MAX>::GetTest(n, m);

	return NULL;
}

static int	UnionTest(){

	size_t v  = sizeof(ft::Vector<float,3>);
	size_t va  = sizeof(float[3]);
	size_t m   = sizeof(ft::Matrix<float,3,4>);
	size_t ma  = sizeof(ft::Vector<float,3>[4]);
	size_t mva = sizeof(float[3][4]);

	std::cout << "Vector<float,3>: "  << v << std::endl;
	std::cout << "float[3]:        "  << va << std::endl;
	std::cout << "Matrix<float,3,4>:  " << m << std::endl;
	std::cout << "Vector<float,3>[4]: " << mva << std::endl;
	std::cout << "float[3][4]:        " << ma << std::endl;

	bool ok = (v == va) && (m == ma) && (m == mva);
	std::cout << (ok ? "Types are unionizable" : "Types are not unionizable") << std::endl;
	return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}

extern int main(int argc, char** argv){
	if (argc <= 1){
		return UnionTest();
	}

	if (argc < 3){
		std::cerr << "Not enough arguments" << std::endl;
		return EXIT_FAILURE;
	}

	ft::TesterType	tester = GetTest(argv[1], argv[2]);
	argc -= 3;
	argv += 3;

	if (tester == NULL){
		std::cerr << "Test not implemented" << std::endl;
		return EXIT_FAILURE;
	}
	else try
	{
		return tester(argc, argv);
	}
	catch(std::exception& e)
	{
		ft::clog << ft::log::error << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}