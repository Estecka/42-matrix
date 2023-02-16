/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tester.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:05:01 by abaur             #+#    #+#             */
/*   Updated: 2023/02/16 17:20:06 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Matrix.hpp"
#include "Format.hpp"

#include <cstdlib>


namespace ft
{
	template <class K, int N, int M>
	class	MatrixTestSuit {
	public:
		typedef Matrix<K,N,M>	Matrix;

		static int	main(int argc, char** argv);

		static int	Add(const Matrix&, const Matrix&);
		static int	Sub(const Matrix&, const Matrix&);
		static int	Scl(const Matrix&, K);
	};
}

/* ************************************************************************** */
/* # Implementation                                                           */
/* ************************************************************************** */


namespace ft
{
	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::main(int argc, char** argv){
		if (argc < 3){
			std::cerr << "Not enough arguments" << std::endl;
			return EXIT_FAILURE;
		}

		std::string subcmd = argv[0];
		if (subcmd == "add")
			return Add(Matrix::StrToMx(argv[1]), Matrix::StrToMx(argv[2]));
		if (subcmd == "sub")
			return Sub(Matrix::StrToMx(argv[1]), Matrix::StrToMx(argv[2]));
		if (subcmd == "scl")
			return Scl(Matrix::StrToMx(argv[1]), std::atof(argv[2]));

		std::cerr << "Unsupported command: " << subcmd << std::endl;
		return EXIT_FAILURE;
	}

	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::Add(const Matrix& a, const Matrix& b){
		Matrix r = a;
		r.add(b);

		PrintMMM(" + ", a, b, r);
		return EXIT_SUCCESS;
	}


	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::Sub(const Matrix& a, const Matrix& b){
		Matrix r = a;
		r.sub(b);

		PrintMMM(" - ", a, b, r);
		return EXIT_SUCCESS;
	}


	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::Scl(const Matrix& a, K b){
		Matrix r = a;
		r.scl(b);

		PrintMKM(" * ", a, b, r);
		return EXIT_SUCCESS;
	}
}
