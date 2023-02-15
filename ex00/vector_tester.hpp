/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:01:54 by abaur             #+#    #+#             */
/*   Updated: 2023/02/15 16:10:28 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Vector.hpp"
#include "../Format.hpp"

#include <iostream>
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

		std::cerr << "Unsupported command: " << subcmd << std::endl;
		return EXIT_FAILURE;
	}

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
}
