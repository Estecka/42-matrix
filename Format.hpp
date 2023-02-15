/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:39:35 by abaur             #+#    #+#             */
/*   Updated: 2023/02/15 19:19:53 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "logutil/logutil.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

#include <sstream>
#include <iostream>
#include <iomanip>

namespace ft
{
	extern int	max(int a, int b);

	/**
	 * Precomputes pretty formatting data for a Vector or Matrix
	 * @param array	An array representing the object to format.
	 * @param outFormat	Outputs the string representation of the each component.
	 * @return	The length of the longest string component.
	 */
	template <class K, int W, int H>
	extern int	Preformat(const K (&array)[W][H], std::string (&outFormat)[W][H]);
	template <class K, int S>
	extern int	Preformat(const K (&array)[S], std::string (&outFormat)[S]);
	template <class K>
	extern int	Preformat(const K &, std::string&);


	/**
	 * Prints a single vector with no newline into stdout.
	 * Can also be used to print rows of a Matrix.
	 * @param v	The preformatted components of the vector.
	 * @param padWith	Padding to be applied to each component.
	 */
	template <int S>
	extern void	PrintV(const std::string (&v)[S], int padwidth);

	/**
	 * Specialized formatting methods, based on an operation's input and output types.
	 * @param op	The string to use to represent the operation's name.
	 */
	template <class K, int S>
	extern void	PrintVVV(const std::string& op, const Vector<K,S>& a, const Vector<K,S>& b, const Vector<K,S>& r);
	template <class K, int S>
	extern void	PrintVKV(const std::string& op, const Vector<K,S>& a, const K& b, const Vector<K,S>& r);
	template<class K, int W, int H>
	extern void	PrintMMM(const std::string& op, const Matrix<K,W,H>& a, const Matrix<K,W,H>& b, const Matrix<K,W,H>& r);
	template<class K, int W, int H>
	extern void	PrintMKM(const std::string& op, const Matrix<K,W,H>& a, const K& b, const Matrix<K,W,H>& r);
}


/******************************************************************************/
/* # Implementations                                                          */
/******************************************************************************/

namespace ft 
{
	template <class K, int W, int H>
	extern int	Preformat(const K (&array)[W][H], std::string (&outFormat)[W][H]){
		std::stringstream cout;
		int	lmax = 0;

		for (int x=0; x<W; x++)
		for (int y=0; y<H; y++)
		{
			cout.str("");
			cout.clear();
			cout << array[x][y];
			outFormat[x][y] = cout.str();
			lmax = max(lmax, outFormat[x][y].size());
		}
		return lmax;
	}
	template <class K, int S>
	extern int	Preformat(const K (&array)[S], std::string (&outFormat)[S]){
		return Preformat<K,1,S>(
			(const K(&)[1][S])array,
			(std::string(&)[1][S])outFormat
		);
	}
	template <class K>
	extern int	Preformat(const K& k, std::string& outFormat){
		return Preformat<K,1,1>(
			(const K(&)[1][1])k,
			(std::string(&)[1][1])outFormat
		);
	}



	template <int S>
	extern void	PrintV(const std::string (&strVec)[S], int padwidth){
		std::cout << "[ ";
		for (int i=0; i<S; i++){
			if (i)
				std::cout << ", ";
			std::cout << std::setw(padwidth) << strVec[i];
		}
		std::cout << " ]";
	}

	template <class K, int S>
	extern void	PrintVVV(const std::string& op, const Vector<K,S>& a, const Vector<K,S>& b, const Vector<K,S>& r){
		std::string stra[S], strb[S], strr[S];
		int lmax = 0;
		int oplen = op.size();

		lmax = max(lmax, Preformat<K,S>(a, stra));
		lmax = max(lmax, Preformat<K,S>(b, strb));
		lmax = max(lmax, Preformat<K,S>(r, strr));

		std::cout << std::setw(oplen) <<  " " << LOG_BOLD_CLEAR; PrintV(stra, lmax); std::cout << LOG_CLEAR << std::endl;
		std::cout << std::setw(oplen) <<   op << LOG_BOLD_CLEAR; PrintV(strb, lmax); std::cout << LOG_CLEAR << std::endl;
		std::cout << std::setw(oplen) << "= " << LOG_BOLD_CYAN;  PrintV(strr, lmax); std::cout << LOG_CLEAR << std::endl;
	}

	template <class K, int S>
	extern void	PrintVKV(const std::string& op, const Vector<K,S>& a, const K& b, const Vector<K,S>& r){
		std::string stra[S], strb, strr[S];
		int lmax = 0;

		lmax = max(lmax, Preformat<K,S>(a, stra));
		lmax = max(lmax, Preformat(b, strb));
		lmax = max(lmax, Preformat<K,S>(r, strr));

		std::cout << "  " << LOG_BOLD_CLEAR; PrintV(stra, lmax); 
		std::cout << ' ' << op << LOG_BOLD_CLEAR << strb << LOG_CLEAR << std::endl;
		std::cout << "= " << LOG_BOLD_CYAN;  PrintV(strr, lmax); std::cout << LOG_CLEAR << std::endl;
	}

	template<class K, int W, int H>
	extern void	PrintMMM(const std::string& op, const Matrix<K,W,H>& a, const Matrix<K,W,H>& b, const Matrix<K,W,H>& r){
		std::string stra[W][H], strb[W][H], strr[W][H];
		int lmax = 0;
		int oplen = op.size();

		lmax = max(lmax, Preformat<K,W,H>(a, stra));
		lmax = max(lmax, Preformat<K,W,H>(b, strb));
		lmax = max(lmax, Preformat<K,W,H>(r, strr));

		for (int x=0; x<W; x++) {
			std::cout << LOG_BOLD_CLEAR; PrintV(stra[x], lmax);
			std::cout << LOG_CLEAR << std::setw(oplen) << ((x==W/2) ?   op : "");
			std::cout << LOG_BOLD_CLEAR; PrintV(strb[x], lmax);
			std::cout << LOG_CLEAR << std::setw(oplen) << ((x==W/2) ? " = " : "");
			std::cout << LOG_BOLD_CYAN;  PrintV(strr[x], lmax);
			std::cout << LOG_CLEAR << std::endl;
		}
	}

	template<class K, int W, int H>
	extern void	PrintMKM(const std::string& op, const Matrix<K,W,H>& a, const K& b, const Matrix<K,W,H>& r){
		std::string stra[W][H], strb, strr[W][H];
		int lmax = 0;
		int oplen = op.size();

		lmax = max(lmax, Preformat<K,W,H>(a, stra));
		lmax = max(lmax, Preformat(b, strb));
		lmax = max(lmax, Preformat<K,W,H>(r, strr));

		for (int x=0; x<W; x++) {
			std::cout << LOG_CLEAR << std::setw(lmax)  << ((x==W/2) ?  strb : "");
			std::cout << LOG_CLEAR << std::setw(oplen) << ((x==W/2) ?    op : "");
			std::cout << LOG_BOLD_CLEAR; PrintV(stra[x], lmax);
			std::cout << LOG_CLEAR << std::setw(oplen) << ((x==W/2) ? " = " : "");
			std::cout << LOG_BOLD_CYAN;  PrintV(strr[x], lmax);
			std::cout << LOG_CLEAR << std::endl;
		}
	}
}
