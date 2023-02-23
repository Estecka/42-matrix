/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmp_tester.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:05:01 by abaur             #+#    #+#             */
/*   Updated: 2023/02/21 17:36:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
#include "Format.hpp"

#include <cstdlib>


namespace ft
{
	template <class K, int N, int M, int P>
	class	NMPTestSuit {
	public:
		static int	main(int argc, char** argv);
		static int	mat_mul(const Matrix<K,N,M>&, const Matrix<K,P,N>&);
	};
}

/* ************************************************************************** */
/* # Implementation                                                           */
/* ************************************************************************** */


namespace ft
{
	template <class K, int N, int M, int P>
	int	NMPTestSuit<K,N,M,P>::main(int argc, char** argv){
		if (argc < 3){
			std::cerr << "Not enough arguments" << std::endl;
			return EXIT_FAILURE;
		}

		std::string subcmd = argv[0];
		if (subcmd == "mxm")	return mat_mul(Matrix<K,N,M>::StrToMx(argv[1]), Matrix<K,P,N>::StrToMx(argv[2]));

		std::cerr << "Unsupported command: " << subcmd << std::endl;
		return EXIT_FAILURE;
	}


/* ************************************************************************** */
/* ## Ex07                                                                    */
/* ************************************************************************** */

	template <class K, int N, int M, int P>
	int	NMPTestSuit<K,N,M,P>::mat_mul(const Matrix<K,N,M>& m, const Matrix<K,P,N>& v){
		PrintNMP(m, v, m.mul_mat(v));
		return EXIT_FAILURE;
	}
}
