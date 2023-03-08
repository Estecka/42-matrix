/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:35 by abaur             #+#    #+#             */
/*   Updated: 2023/03/08 14:16:50 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Imaginary.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "TestFactory.hpp"
#include "vector_tester.hpp"
#include "matrix_tester.hpp"
#include "nmp_tester.hpp"
#include "number_tester.hpp"

#include "logutil/logutil.hpp"

#include <iostream>
#include <cstring>
#include <exception>

#define N_MAX	5
#define M_MAX	5
#define P_MAX	5

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

template <class K>
static ft::TesterType	GetTest(std::string mode, const char* dimensions){
	int n, m, p;
	GetDimensions(dimensions, n, m, p);

	if (mode == "num")
		return ft::NumberTestSuit<K>::main;
	if (mode == "vec")
		return ft::TestFactoryN<ft::VectorTestSuit, K, N_MAX>::GetTest(n);
	if (mode == "mx")
		return ft::TestFactoryNM<ft::MatrixTestSuit, K, N_MAX, M_MAX>::GetTest(n, m);
	if (mode == "nmp")
		return ft::TestFactoryNMP<ft::NMPTestSuit, K, N_MAX, M_MAX, P_MAX>::GetTest(n, m, p);

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
	argc--, argv++;

	bool isImaginary = false;
	if (argc < 1){
		std::cerr << "Not enough arguments" << std::endl;
		return EXIT_FAILURE;
	}
	if (!std::strcmp(argv[0], "i")){
		isImaginary = true;
		argc--, argv++;
	}


	if (argc < 2){
		std::cerr << "Not enough arguments" << std::endl;
		return EXIT_FAILURE;
	}

	ft::TesterType	tester;
	if (isImaginary)
		tester = GetTest<ft::Imaginary<float>>(argv[0], argv[1]);
	else
		tester = GetTest<float>(argv[0], argv[1]);
	argc -= 2;
	argv += 2;

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