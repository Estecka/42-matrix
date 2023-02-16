/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:01:54 by abaur             #+#    #+#             */
/*   Updated: 2023/02/16 18:13:46 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector.hpp"
#include "Format.hpp"

#include <cstdlib>


namespace ft
{
	template <class K, int N>
	class	VectorTestSuit {
	public:
		typedef Vector<K,N>	Vector;

		static int	main(int argc, char** argv);

		static int	Add(const Vector&, const Vector&);
		static int	Sub(const Vector&, const Vector&);
		static int	Scl(const Vector&, K);

		static int	linear_combination(const char* argvU, const char* argvCoef);
	};
}

/* ************************************************************************** */
/* # Implementation                                                           */
/* ************************************************************************** */


namespace ft
{
	template <class K, int N>
	int	VectorTestSuit<K,N>::main(int argc, char** argv){
		if (argc < 3){
			std::cerr << "Not enough arguments" << std::endl;
			return EXIT_FAILURE;
		}

		std::string subcmd = argv[0];
		if (subcmd == "add")
			return Add(Vector::StrToVec(argv[1]), Vector::StrToVec(argv[2]));
		if (subcmd == "sub")
			return Sub(Vector::StrToVec(argv[1]), Vector::StrToVec(argv[2]));
		if (subcmd == "scl")
			return Scl(Vector::StrToVec(argv[1]), std::atof(argv[2]));
		if (subcmd == "fma")
			return linear_combination(argv[1], argv[2]);

		std::cerr << "Unsupported command: " << subcmd << std::endl;
		return EXIT_FAILURE;
	}


/* ************************************************************************** */
/* ## Ex00                                                                    */
/* ************************************************************************** */

	template <class K, int N>
	int	VectorTestSuit<K,N>::Add(const Vector& a, const Vector& b){
		Vector r = a;
		r.add(b);

		PrintVVV("+ ", a, b, r);
		return EXIT_SUCCESS;
	}


	template <class K, int N>
	int	VectorTestSuit<K,N>::Sub(const Vector& a, const Vector& b){
		Vector r = a;
		r.sub(b);

		PrintVVV("- ", a, b, r);
		return EXIT_SUCCESS;
	}


	template <class K, int N>
	int	VectorTestSuit<K,N>::Scl(const Vector& a, K b){
		Vector r = a;
		r.scl(b);

		PrintVKV("* ", a, b, r);
		return EXIT_SUCCESS;
	}


/* ************************************************************************** */
/* ## Ex01                                                                    */
/* ************************************************************************** */

	template <class K, int N>
	int	VectorTestSuit<K,N>::linear_combination(const char* argvU, const char* argvCoef){
		std::vector<Vector>	u;
		std::vector<K>	coefs;
		Vector result;

		do {
			u.push_back(Vector::StrToVec(argvU, &argvU));
		} while(*argvU == ';' && *(++argvU));
		if (*argvU)
			throw std::invalid_argument("Invalid vector array argument");

		do {
			coefs.push_back(std::strtof(argvCoef, (char**)&argvCoef));
		} while(*argvCoef == ';' && *(++argvCoef));
		if (*argvCoef)
			throw std::invalid_argument("Invalid coefficient array argument");

		result = Vector::linear_combination(u, coefs);
		PrintFMA(u, coefs, result);
		return EXIT_SUCCESS;
	};
}
