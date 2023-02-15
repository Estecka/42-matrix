/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:39:35 by abaur             #+#    #+#             */
/*   Updated: 2023/02/15 16:17:58 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "logutil/logutil.hpp"
#include "Vector.hpp"

#include <sstream>
#include <iostream>
#include <iomanip>

namespace ft
{
	extern int	max(int a, int b);

	/**
	 * Precomputes pretty formatting data for a Vector
	 * @param array	An array representing vector to format.
	 * @param outFormat	String representation of the vector's components.
	 * @return	The length of the longest string component.
	 */
	template <class K, int S>
	extern int	Preformat(const K (&array)[S], std::string (&outFormat)[S]);
	template <class K, int N, int M>
	extern int	Preformat(const K (&array)[N][M], std::string (&outFormat)[N][M]);


	template <int S>
	extern void	PrintV(const std::string (&v)[S], int padwidth);

	template <class K, int S>
	extern void	PrintVVV(const std::string& op, const Vector<K,S>& a, const Vector<K,S>& b, const Vector<K,S>& r);
	template <class K, int S>
	extern void	PrintVKV(const std::string& op, const Vector<K,S>& a, const K& b, const Vector<K,S>& r);
}


/******************************************************************************/
/* # Implementations                                                          */
/******************************************************************************/

namespace ft 
{
	template <class K, int S>
	extern int	Preformat(const K (&array)[S], std::string (&outFormat)[S]){
		return Preformat<K,1,S>(
			(const K(&)[1][S])array,
			(std::string(&)[1][S])outFormat
		);
	}
	template <class K, int N, int M>
	extern int	Preformat(const K (&array)[N][M], std::string (&outFormat)[N][M]){
		std::stringstream cout;
		int	lmax = 0;

		for (int x=0; x<N; x++)
		for (int y=0; y<M; y++)
		{
			cout.str("");
			cout.clear();
			cout << array[x][y];
			outFormat[x][y] = cout.str();
			lmax = max(lmax, outFormat[x][y].size());
		}
		return lmax;
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
		std::string stra[S], strb[1], strr[S];
		int lmax = 0;

		lmax = max(lmax, Preformat<K,S>(a, stra));
		lmax = max(lmax, Preformat<K>((K(&)[1])b, strb));
		lmax = max(lmax, Preformat<K,S>(r, strr));

		std::cout << "  " << LOG_BOLD_CLEAR; PrintV(stra, lmax); 
		std::cout << ' ' << op << LOG_BOLD_CLEAR << strb[0] << LOG_CLEAR << std::endl;
		std::cout << "= " << LOG_BOLD_CYAN;  PrintV(strr, lmax); std::cout << LOG_CLEAR << std::endl;
	}
}
