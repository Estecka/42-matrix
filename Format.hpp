/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:39:35 by abaur             #+#    #+#             */
/*   Updated: 2023/02/23 16:00:26 by abaur            ###   ########.fr       */
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
	extern int	min(int a, int b);

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
	template <class K, int S>
	extern void	PrintFMA(const std::vector<Vector<K,S>>& a, const std::vector<K>& b, const Vector<K,S>& r);
	template <class K>
	extern void	PrintKLerp(const K& a, const K& b, const K& t, const K& r);
	template <class K, int W, int H>
	extern void	PrintMLerp(const Matrix<K,W,H>& a, const Matrix<K,W,H>& b, const K& t, const Matrix<K,W,H>& r);
	template <class K, int S>
	extern void	PrintVVK(const std::string& op, const Vector<K,S>& a, const Vector<K,S>& b, const K& r);
	template <class K, int S>
	extern void	PrintVNorm(const Vector<K,S>& v, float n1, float n2, float ni);
	template<class K, int IN, int OUT, int P>
	extern void	PrintNMP(const Matrix<K,IN,OUT>& f, const Matrix<K,P,IN>& i, const Matrix<K,P,OUT>& o);
	template<class K, int IN, int OUT>
	extern void	PrintNMP(const Matrix<K,IN,OUT>& f, const Vector<K,IN>& i, const Vector<K,OUT>& o);
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
			lmax = ft::max(lmax, outFormat[x][y].size());
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


/******************************************************************************/
/* ## Ex00                                                                    */
/******************************************************************************/

	template <class K, int S>
	extern void	PrintVVV(const std::string& op, const Vector<K,S>& a, const Vector<K,S>& b, const Vector<K,S>& r){
		std::string stra[S], strb[S], strr[S];
		int lmax = 0;
		int oplen = op.size();

		lmax = ft::max(lmax, Preformat<K,S>(a, stra));
		lmax = ft::max(lmax, Preformat<K,S>(b, strb));
		lmax = ft::max(lmax, Preformat<K,S>(r, strr));

		std::cout << std::setw(oplen) <<  "" << ' ' << LOG_BOLD_CLEAR; PrintV(stra, lmax); std::cout << LOG_CLEAR << std::endl;
		std::cout << std::setw(oplen) <<  op << ' ' << LOG_BOLD_CLEAR; PrintV(strb, lmax); std::cout << LOG_CLEAR << std::endl;
		std::cout << std::setw(oplen) << "=" << ' ' << LOG_BOLD_CYAN;  PrintV(strr, lmax); std::cout << LOG_CLEAR << std::endl;
	}

	template <class K, int S>
	extern void	PrintVKV(const std::string& op, const Vector<K,S>& a, const K& b, const Vector<K,S>& r){
		std::string stra[S], strb, strr[S];
		int lmax = 0;

		lmax = ft::max(lmax, Preformat<K,S>(a, stra));
		lmax = ft::max(lmax, Preformat(b, strb));
		lmax = ft::max(lmax, Preformat<K,S>(r, strr));

		std::cout << "  " << LOG_BOLD_CLEAR; PrintV(stra, lmax); 
		std::cout << ' ' << op << LOG_BOLD_CLEAR << strb << LOG_CLEAR << std::endl;
		std::cout << "= " << LOG_BOLD_CYAN;  PrintV(strr, lmax); std::cout << LOG_CLEAR << std::endl;
	}

	template<class K, int W, int H>
	extern void	PrintMMM(const std::string& op, const Matrix<K,W,H>& a, const Matrix<K,W,H>& b, const Matrix<K,W,H>& r){
		std::string stra[W][H], strb[W][H], strr[W][H];
		int lmax = 0;
		int oplen = op.size();

		lmax = ft::max(lmax, Preformat<K,W,H>(a, stra));
		lmax = ft::max(lmax, Preformat<K,W,H>(b, strb));
		lmax = ft::max(lmax, Preformat<K,W,H>(r, strr));

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

		lmax = ft::max(lmax, Preformat<K,W,H>(a, stra));
		lmax = ft::max(lmax, Preformat(b, strb));
		lmax = ft::max(lmax, Preformat<K,W,H>(r, strr));

		for (int x=0; x<W; x++) {
			std::cout << LOG_CLEAR << std::setw(lmax)  << ((x==W/2) ?  strb : "");
			std::cout << LOG_CLEAR << std::setw(oplen) << ((x==W/2) ?    op : "");
			std::cout << LOG_BOLD_CLEAR; PrintV(stra[x], lmax);
			std::cout << LOG_CLEAR << std::setw(oplen) << ((x==W/2) ? " = " : "");
			std::cout << LOG_BOLD_CYAN;  PrintV(strr[x], lmax);
			std::cout << LOG_CLEAR << std::endl;
		}
	}


/******************************************************************************/
/* ## Ex01                                                                    */
/******************************************************************************/

	template <class K, int S>
	extern void	PrintFMA(const std::vector<Vector<K,S>>& a, const std::vector<K>& b, const Vector<K,S>& r){
		std::vector<std::string>	strb;
		std::string	strr[S];
		int lmax = 0;
		int nmax = ft::min(a.size(), b.size());

		lmax = ft::max(lmax, Preformat<K,S>(r, strr));
		for (int n=0; n<nmax; n++){
			std::string	stra[S];
			strb.push_back("");
			lmax = ft::max(lmax, Preformat<K,S>(a[n], stra));
			lmax = ft::max(lmax, Preformat(b[n], strb[n]));
		}

		for (int n=0; n<nmax; n++){
			std::string	stra[S];
			Preformat<K,S>(a[n], stra);
			std::cout << (n ? "+ " : "  ") << LOG_BOLD_CLEAR; PrintV(stra, lmax); 
			std::cout << LOG_CLEAR " * " LOG_BOLD_CLEAR << strb[n] << LOG_CLEAR << std::endl;
		}
		std::cout << "= " << LOG_BOLD_CYAN; PrintV(strr, lmax); std::cout << LOG_CLEAR << std::endl;
	}

/******************************************************************************/
/* ## Ex02                                                                    */
/******************************************************************************/

	template <class K>
	extern void	PrintKLerp(const K& a, const K& b, const K& t, const K& r) {
		std::string stra, strb, strr;
		int lmax = 0;

		lmax = ft::max(lmax, Preformat<K>(a, stra));
		lmax = ft::max(lmax, Preformat<K>(b, strb));
		lmax = ft::max(lmax, Preformat<K>(r, strr));


		std::cout << "  " LOG_BOLD_CLEAR << std::setw(lmax) << stra << LOG_CLEAR " * " << 1-t << std::endl;
		std::cout << "+ " LOG_BOLD_CLEAR << std::setw(lmax) << strb << LOG_CLEAR " * " << t << std::endl;
		std::cout << "= " LOG_BOLD_CYAN  << std::setw(lmax) << strr << std::endl;
		std::cout << LOG_CLEAR << std::endl;
	}

	template <class K, int W, int H>
	extern void	PrintMLerp(const Matrix<K,W,H>& a, const Matrix<K,W,H>& b, const K& t, const Matrix<K,W,H>& r) {
		std::string stra[W][H], strb[W][H], strr[W][H];
		std::string strt;
		int lmax = 0;

		lmax = ft::max(lmax, Preformat<K,W,H>(a, stra));
		lmax = ft::max(lmax, Preformat<K,W,H>(b, strb));
		lmax = ft::max(lmax, Preformat<K,W,H>(r, strr));
		lmax = ft::max(lmax, Preformat<K>(t, strt));

		int tpad = lmax*H + 4 + 2*(H-1) - 2;

		std::cout << std::setw(tpad) << 1-t << " *   " << std::setw(tpad) << t << " *" << std::endl;
		for (int x=0; x<W; x++) {
			std::cout << LOG_BOLD_CLEAR; PrintV(stra[x], lmax);
			std::cout << LOG_CLEAR << ((x==W/2) ? " + " : "   ");
			std::cout << LOG_BOLD_CLEAR; PrintV(strb[x], lmax);
			std::cout << LOG_CLEAR << ((x==W/2) ? " = " : "   ");
			std::cout << LOG_BOLD_CYAN;  PrintV(strr[x], lmax);
			std::cout << LOG_CLEAR << std::endl;
		}
	}

/******************************************************************************/
/* ## Ex03                                                                    */
/******************************************************************************/

	template <class K, int S>
	extern void	PrintVVK(const std::string& op, const Vector<K,S>& a, const Vector<K,S>& b, const K& r){
		std::string stra[S], strb[S];
		int lmax = 0;
		int oplen = op.size();

		lmax = ft::max(lmax, Preformat<K,S>(a, stra));
		lmax = ft::max(lmax, Preformat<K,S>(b, strb));

		std::cout << std::setw(oplen) <<  "" << ' ' << LOG_BOLD_CLEAR; PrintV(stra, lmax); std::cout << LOG_CLEAR << std::endl;
		std::cout << std::setw(oplen) <<  op << ' ' << LOG_BOLD_CLEAR; PrintV(strb, lmax); std::cout << LOG_CLEAR << std::endl;
		std::cout << std::setw(oplen) << "=" << " " << LOG_BOLD_CYAN << r << LOG_CLEAR << std::endl;
	}

/******************************************************************************/
/* ## Ex04                                                                    */
/******************************************************************************/

	template <class K, int S>
	extern void	PrintVNorm(const Vector<K,S>& v, float n1, float n2, float ni){

		std::cout << LOG_BOLD_CLEAR << "[ " << v << " ]";
		std::cout << LOG_CLEAR ";  Norm_1: "   LOG_BOLD_CYAN << n1;
		std::cout << LOG_CLEAR ";  Norm_2: "   LOG_BOLD_CYAN << n2;
		std::cout << LOG_CLEAR ";  Norm_inf: " LOG_BOLD_CYAN << ni;
		std::cout << LOG_CLEAR << std::endl;
	}

/******************************************************************************/
/* ## Ex07                                                                    */
/******************************************************************************/

	template<class K, int IN, int OUT, int P>
	extern void	PrintNMP(const Matrix<K,IN,OUT>& f, const Matrix<K,P,IN>& i, const Matrix<K,P,OUT>& o){
		std::string strf[IN][OUT];
		std::string stri[P][IN];
		std::string stro[P][OUT];

		int lmax = 0;
		lmax = ft::max(lmax, Preformat<K,IN,OUT>(f, strf));
		lmax = ft::max(lmax, Preformat<K,P,IN>  (i, stri));
		lmax = ft::max(lmax, Preformat<K,P,OUT> (o, stro));

		for (int x=0; x<IN; x++){
			std::cout << LOG_BOLD_CLEAR;
			PrintV(stri[x], lmax);
			std::cout << LOG_CLEAR << std::endl;
		}

		int mlen = 4 + (lmax*P) + 2*(P-1);
		std::cout << std::setw(mlen/2) << '*' << std::endl;

		for (int x=0; x<OUT; x++) {
			std::cout << LOG_BOLD_CLEAR; PrintV(strf[x], lmax);
			std::cout << LOG_CLEAR << ((x==OUT/2) ? " = " : "   ");
			std::cout << LOG_BOLD_CYAN; PrintV(stro[x], lmax);
			std::cout << LOG_CLEAR << std::endl;
		}
	}

	template<class K, int IN, int OUT>
	extern void	PrintNMP(const Matrix<K,IN,OUT>& f, const Vector<K,IN>& i, const Vector<K,OUT>& o){
		std::string strf[IN][OUT];
		std::string stri[IN];
		std::string stro[OUT];

		int lmax = 0;
		lmax = ft::max(lmax, Preformat<K,IN,OUT>(f, strf));
		lmax = ft::max(lmax, Preformat<K,IN>  (i, stri));
		lmax = ft::max(lmax, Preformat<K,OUT> (o, stro));

		for (int x=0; x<IN; x++){
			std::cout << LOG_BOLD_CLEAR; PrintV(strf[x], lmax);
			std::cout << LOG_CLEAR << ((x==OUT/2) ? " * " : "   ");
			std::cout << LOG_BOLD_CLEAR << "[ " << std::setw(lmax) << stri[x] << " ]";
			std::cout << LOG_CLEAR << std::endl;
		}

		std::cout << LOG_CLEAR << " = " << std::endl;
		std::cout << LOG_BOLD_CYAN; PrintV(stro, lmax); std::cout << LOG_CLEAR << std::endl;
	}
}
