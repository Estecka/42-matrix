/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:01:54 by abaur             #+#    #+#             */
/*   Updated: 2023/03/11 16:55:05 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector.hpp"
#include "Format.hpp"
#include "atok.hpp"

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
		static int	lerp(const Vector&, const Vector&, float);
		static int	dot(const Vector&, const Vector&);
		static int	norm(const Vector&);
		static int	cos(const Vector&, const Vector&);
		static int	cross(const ft::Vector<K,3>&, const ft::Vector<K,3>&);
	};
}

/* ************************************************************************** */
/* # Implementation                                                           */
/* ************************************************************************** */


namespace ft
{
	template <class K, int N>
	int	VectorTestSuit<K,N>::main(int argc, char** argv){
		if (argc < 2){
			std::cerr << "Not enough arguments" << std::endl;
			return EXIT_FAILURE;
		}

		std::string subcmd = argv[0];
		if (subcmd == "norm")
			return norm(Vector::StrToVec(argv[1]));

		if (argc < 3){
			std::cerr << "Not enough arguments" << std::endl;
			return EXIT_FAILURE;
		}

		if (subcmd == "add")
			return Add(Vector::StrToVec(argv[1]), Vector::StrToVec(argv[2]));
		if (subcmd == "sub")
			return Sub(Vector::StrToVec(argv[1]), Vector::StrToVec(argv[2]));
		if (subcmd == "scl")
			return Scl(Vector::StrToVec(argv[1]), ft::atok<K>(argv[2]));
		if (subcmd == "fma")
			return linear_combination(argv[1], argv[2]);
		if (subcmd == "dot")
			return dot(Vector::StrToVec(argv[1]), Vector::StrToVec(argv[2]));
		if (subcmd == "cos")
			return cos(Vector::StrToVec(argv[1]), Vector::StrToVec(argv[2]));
		if (subcmd == "cross")
			return cross(ft::Vector<K,3>::StrToVec(argv[1]), ft::Vector<K,3>::StrToVec(argv[2]));

		if (argc < 4){
			std::cerr << "Not enough arguments" << std::endl;
			return EXIT_FAILURE;
		}
		
		if (subcmd == "lerp")
			return lerp(Vector::StrToVec(argv[1]), Vector::StrToVec(argv[2]), std::atof(argv[3]));

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

		PrintVVV("+", a, b, r);
		return EXIT_SUCCESS;
	}


	template <class K, int N>
	int	VectorTestSuit<K,N>::Sub(const Vector& a, const Vector& b){
		Vector r = a;
		r.sub(b);

		PrintVVV("-", a, b, r);
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
			coefs.push_back(ft::strtok<K>(argvCoef, (char**)&argvCoef));
		} while(*argvCoef == ';' && *(++argvCoef));
		if (*argvCoef)
			throw std::invalid_argument("Invalid coefficient array argument");

		result = Vector::linear_combination(u, coefs);
		PrintFMA(u, coefs, result);
		return EXIT_SUCCESS;
	};


/* ************************************************************************** */
/* ## Ex02                                                                    */
/* ************************************************************************** */

	template <class K, int N>
	int	VectorTestSuit<K,N>::lerp(const Vector& a, const Vector& b, float t){
		Vector result = Vector::lerp(a, b, t);
		std::string op = "lerp";
		op += t;

		PrintFMA({a, b}, {1-t, t}, result);
		return EXIT_SUCCESS;
	};


/* ************************************************************************** */
/* ## Ex02                                                                    */
/* ************************************************************************** */

	template <class K, int N>
	int	VectorTestSuit<K,N>::dot(const Vector& a, const Vector& b){
		K result = a.dot(b);

		PrintVVK("dot", a, b, result);
		return EXIT_SUCCESS;
	};


/* ************************************************************************** */
/* ## Ex02                                                                    */
/* ************************************************************************** */

	template <class K, int N>
	int	VectorTestSuit<K,N>::norm(const Vector& v){
		float n1 = v.norm_1();
		float n2 = v.norm();
		float ni = v.norm_inf();

		PrintVNorm(v, n1, n2, ni);
		return EXIT_SUCCESS;
	};


/* ************************************************************************** */
/* ## Ex05                                                                    */
/* ************************************************************************** */

	template <class K, int N>
	int	VectorTestSuit<K,N>::cos(const Vector& a, const Vector& b){
		K result = Vector::angle_cos(a, b);

		PrintVVK("cos", a, b, result);
		return EXIT_SUCCESS;
	};


/* ************************************************************************** */
/* ## Ex06                                                                    */
/* ************************************************************************** */

	template <class K, int N>
	int	VectorTestSuit<K,N>::cross(const ft::Vector<K,3>& a, const ft::Vector<K,3>& b){
		ft::Vector<K,3> r = ft::Vector<K,3>::cross_product(a, b);

		PrintVVV("cross", a, b, r);
		return EXIT_SUCCESS;
	};
}
