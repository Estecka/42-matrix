/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tester.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:05:01 by abaur             #+#    #+#             */
/*   Updated: 2023/04/07 14:15:13 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
#include "Format.hpp"
#include "Imaginary.hpp"
#include "atok.hpp"

#include <cstdlib>


namespace ft
{

	template <class K>
	static inline bool	approximate(const K& a, const K& b, const K& deltaMax){
		return (a+deltaMax) > b && b > (a - deltaMax);
	}

	template <class K>
	static inline bool	approximate(const Imaginary<K>& a, const Imaginary<K>& b, const K& deltaMax){
		return approximate(a.r, b.r, deltaMax) && approximate(a.i, b.i, deltaMax);
	}

	template <class K, int N, int M>
	class	MatrixTestSuit {
	public:
		typedef ft::Matrix<K,N,M>	Matrix;

		static int	main(int argc, char** argv);

		static int	Add(const Matrix&, const Matrix&);
		static int	Sub(const Matrix&, const Matrix&);
		static int	Scl(const Matrix&, K);
		static int	lerp(const Matrix&, const Matrix&, float);
		static int	vec_mul(const Matrix&, const Vector<K,N>&);
		static int	trace(const Matrix&);
		static int	transpose(const Matrix&);
		static int	rowech(const Matrix&);
		static int	det(const Matrix&);
		static int	inverse(const Matrix&);
		static int	rank(const Matrix&);
	};
}

/* ************************************************************************** */
/* # Implementation                                                           */
/* ************************************************************************** */


namespace ft
{
	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::main(int argc, char** argv){
		if (argc < 2){
			std::cerr << "Not enough arguments" << std::endl;
			return EXIT_FAILURE;
		}

		std::string subcmd = argv[0];
		if (subcmd == "trans")	return transpose(Matrix::StrToMx(argv[1]));
		if (subcmd == "trace")	return trace(Matrix::StrToMx(argv[1]));
		if (subcmd == "rowech")	return rowech(Matrix::StrToMx(argv[1]));
		if (subcmd == "det")	return det(Matrix::StrToMx(argv[1]));
		if (subcmd == "inv")	return inverse(Matrix::StrToMx(argv[1]));
		if (subcmd == "rank")	return rank(Matrix::StrToMx(argv[1]));

		if (argc < 3){
			std::cerr << "Not enough arguments" << std::endl;
			return EXIT_FAILURE;
		}

		if (subcmd == "add")	return Add(Matrix::StrToMx(argv[1]), Matrix::StrToMx(argv[2]));
		if (subcmd == "sub")	return Sub(Matrix::StrToMx(argv[1]), Matrix::StrToMx(argv[2]));
		if (subcmd == "scl")	return Scl(Matrix::StrToMx(argv[1]), ft::atok<K>(argv[2]));
		if (subcmd == "mxv")	return vec_mul(Matrix::StrToMx(argv[1]), Vector<K,N>::StrToVec(argv[2]));

		if (argc < 4){
			std::cerr << "Not enough arguments" << std::endl;
			return EXIT_FAILURE;
		}
		if (subcmd == "lerp")	return lerp(Matrix::StrToMx(argv[1]), Matrix::StrToMx(argv[2]), std::atof(argv[3]));

		std::cerr << "Unsupported command: " << subcmd << std::endl;
		return EXIT_FAILURE;
	}


/* ************************************************************************** */
/* ## Ex00                                                                    */
/* ************************************************************************** */

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


/* ************************************************************************** */
/* ## Ex02                                                                    */
/* ************************************************************************** */

	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::lerp(const Matrix& a, const Matrix& b, float t){
		Matrix r = Matrix::lerp(a, b, t);
		PrintMLerp(a, b, t, r);
		return EXIT_SUCCESS;
	}


/* ************************************************************************** */
/* ## Ex07                                                                    */
/* ************************************************************************** */
	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::vec_mul(const Matrix& m, const Vector<K,N>& v){
		Vector<K,M> r = m.mul_vec(v);
		PrintNMP(m, v, r);
		return EXIT_SUCCESS;
	}


/* ************************************************************************** */
/* ## Ex08                                                                    */
/* ************************************************************************** */
	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::trace(const Matrix& m){
		PrintMK(m, m.trace());
		return EXIT_SUCCESS;
	}


/* ************************************************************************** */
/* ## Ex09                                                                    */
/* ************************************************************************** */
	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::transpose(const Matrix& m){
		PrintMM(m, m.transpose());
		return EXIT_SUCCESS;
	}


/* ************************************************************************** */
/* ## Ex10                                                                    */
/* ************************************************************************** */
	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::rowech(const Matrix& m){
		PrintMM(m, m.row_echelon());
		return EXIT_SUCCESS;
	}


/* ************************************************************************** */
/* ## Ex11                                                                    */
/* ************************************************************************** */
	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::det(const Matrix& m){
		PrintMK(m, m.determinant());
		return EXIT_SUCCESS;
	}


/* ************************************************************************** */
/* ## Ex12                                                                    */
/* ************************************************************************** */
	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::inverse(const Matrix& m){
		Matrix inv;
		try {
			inv = m.inverse();
		}
		catch (std::domain_error& e) {
			PrintM(m);
			std::cout << LOG_BOLD_CYAN << e.what() << std::endl << LOG_CLEAR << std::endl;
			return EXIT_SUCCESS;
		}

		PrintMM(m, inv);
		ft::Matrix<K,M,M> id = inv.mul_mat(*(ft::Matrix<K,M,N>*)&m);

		for (int x=0; x<N; x++)
		for (int y=0; y<M; y++)
		if (!ft::approximate(id[x][y], (K)(x==y), 1e-06f)){
			std::cout << LOG_RED << id <<  LOG_CLEAR << std::endl;
			std::cout << LOG_BOLD_RED "KO" LOG_CLEAR << std::endl;
			return EXIT_SUCCESS;
		}
		
		std::cout << LOG_BOLD_GREEN "OK" LOG_CLEAR << std::endl;
		return EXIT_SUCCESS;
	}


/* ************************************************************************** */
/* ## Ex13                                                                    */
/* ************************************************************************** */
	template <class K, int N, int M>
	int	MatrixTestSuit<K,N,M>::rank(const Matrix& m){
		PrintMK(m, (K)m.rank());
		return EXIT_SUCCESS;
	}
}
