/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:36:26 by abaur             #+#    #+#             */
/*   Updated: 2023/03/21 16:08:36 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "atok.hpp"
#include "lerp.hpp"
#include "Vector.hpp"

#include <sstream>
#include <stdexcept>
#include <cstring>

namespace ft
{
	template <class K, int WIDTH, int HEIGHT> 
	struct Matrix
	{
		typedef K	array_type[WIDTH][HEIGHT];
		typedef K	raw_type[WIDTH*HEIGHT];
		typedef K	column_type[HEIGHT];

		Matrix(void);
		Matrix(const Matrix&);
		Matrix(const array_type&);
		Matrix&	operator=(const Matrix&);
		Matrix&	operator=(const array_type&);

		array_type	array;

		column_type&	operator[](int);
		const column_type& 	operator[](int) const;

		operator const array_type&() const;
		operator const raw_type&() const;
		operator array_type&();
		operator raw_type&();

		/**
		 * Parse a matrix formatted as "m00,m01;m10,m11;..."
		 * @param str	The string to Parse
		 * @param outEnd	Outputs the character following the parsed text
		 * @throw	The string does not contain a valid matrix.
		 */
		static Matrix	StrToMx(const char* str, char** outend = NULL);
		std::string	ToString() const;

		// Ex 00
		Matrix&	operator+=(const Matrix&);
		Matrix&	operator-=(const Matrix&);
		Matrix&	operator*=(K);
		Matrix&	add(const Matrix&);
		Matrix&	sub(const Matrix&);
		Matrix&	scl(K);

		// Ex 02
		static Matrix	lerp(const Matrix&, const Matrix&, float);

		// Ex07
		template <int P>
		Matrix<K,P,HEIGHT>	mul_mat(const Matrix<K,P,WIDTH>&) const;
		Vector<K,HEIGHT>  	mul_vec(const Vector<K,WIDTH>&) const;

		// Ex08
		K	trace() const;

		// Ex09
		Matrix<K,HEIGHT,WIDTH>	transpose() const;

		// Ex10
		Matrix<K,WIDTH,HEIGHT> 	row_echelon() const;
		Matrix<K,WIDTH,HEIGHT>&	to_row_echelon();

		// Ex11
		/**
		 * Computes the determinant of a submatrix of this (root) matrix.
		 * @param y	The y offset of the submatrix, relative to the root matrix.
		 * @param w	The width of the submatrix
		 * @param h	The height of the submatrix
		 * @param slice	The X coordinate of the slice within the submatrix, relative to the submatrix.
		 * @param xMap	Array of size `w+1`. It maps a Y coordinate from the 
		 * submatrix's parent to the corresponding Y coordinate in the root 
		 * matrix.
		 */
		K	subdet(int y, int w, int h, int slice, const int* xMap) const;
		K	determinant() const;

		//Ex13
		size_t	rank() const;
	};

	template<class K, int W, int H>
	std::ostream&	operator<<(std::ostream&, const ft::Matrix<K,W,H>&);
}


/******************************************************************************/
/* # Implementations                                                          */
/******************************************************************************/

namespace ft 
{
	template <class K, int W, int H>
	Matrix<K,W,H>::Matrix(void){
		bzero(&this->array, sizeof(this->array));
	}
	template <class K, int W, int H>
	Matrix<K,W,H>::Matrix(const Matrix& other) 
	: Matrix(other.array) 
	{}
	template <class K, int W, int H>
	Matrix<K,W,H>::Matrix(const array_type& other) {
		for (int x=0; x<W; x++)
		for (int y=0; y<H; y++)
			this->array[x][y] = other[x][y];
	};

	template <class K, int W, int H>
	Matrix<K,W,H>&	Matrix<K,W,H>::operator=(const Matrix& other) {
		new (this) Matrix(other.array);
	};
	template <class K, int W, int H>
	Matrix<K,W,H>&	Matrix<K,W,H>::operator=(const array_type& other) {
		new (this) Matrix(other.array);
	};


	template <class K, int W, int H>
	typename Matrix<K,W,H>::column_type&	Matrix<K,W,H>::operator[](int x)
	{ return this->array[x]; };

	template <class K, int W, int H>
	const typename Matrix<K,W,H>::column_type&	Matrix<K,W,H>::operator[](int x) const
	{ return this->array[x]; };

	template <class K, int W, int H> Matrix<K,W,H>::operator const array_type&() const { return this->array; }
	template <class K, int W, int H> Matrix<K,W,H>::operator       array_type&()       { return this->array; }
	template <class K, int W, int H> Matrix<K,W,H>::operator const raw_type&  () const { return (raw_type&)this->array; }
	template <class K, int W, int H> Matrix<K,W,H>::operator       raw_type&  ()       { return (raw_type&)this->array; }

	template <class K, int W, int H>
	Matrix<K,W,H>	Matrix<K,W,H>::StrToMx(const char* str, char** outEnd){
		Matrix result;

		for (int y=0; y<H; y++){
			if (y){
				if(*str==';')
					str++;
				else
					throw std::invalid_argument("Argument matrix is invalid");
			}
			for (int x=0; x<W; x++){
				if (x){
					if(*str==',')
						str++;
					else
						throw std::invalid_argument("Argument matrix is invalid");
				}
				result[x][y] = ft::strtok<K>(str, (char**)&str);
			}
		}

		if (outEnd != NULL)
			outEnd = (char**)str;
		return result;
	}
	template <class K, int W, int H>
	std::string	Matrix<K,W,H>::ToString() const {
		std::stringstream cout;
		cout << *this;
		return cout.str();
	}; 


	template<class K, int W, int H>
	std::ostream&	operator<<(std::ostream& cout, const ft::Matrix<K,W,H>& mx){
		for (int y=0; y<H; y++) {
			if (y)
				cout << ';';
			for (int x=0; x<W; x++) {
				if (x)
					cout << ',';
				cout << mx[x][y];
			}
		}
		return cout;
	}


/******************************************************************************/
/* ## Exercice 00                                                             */
/******************************************************************************/

	template <class K, int W, int H> 
	Matrix<K,W,H>&	Matrix<K,W,H>::operator+=(const Matrix& other) {
		for (int x=0; x<W; x++)
		for (int y=0; y<H; y++)
			this->array[x][y] += other.array[x][y];
		return *this;
	};
	template <class K, int W, int H> 
	Matrix<K,W,H>&	Matrix<K,W,H>::operator-=(const Matrix& other) {
		for (int x=0; x<W; x++)
		for (int y=0; y<H; y++)
			this->array[x][y] -= other.array[x][y];
		return *this;
	};
	template <class K, int W, int H> 
	Matrix<K,W,H>&	Matrix<K,W,H>::operator*=(K scalar) {
		for (int x=0; x<W; x++)
		for (int y=0; y<H; y++)
			this->array[x][y] *= scalar;
		return *this;
	};

	template <class K, int W, int H> Matrix<K,W,H>&	Matrix<K,W,H>::add(const Matrix& other) { return *this += other; };
	template <class K, int W, int H> Matrix<K,W,H>&	Matrix<K,W,H>::sub(const Matrix& other) { return *this -= other; };
	template <class K, int W, int H> Matrix<K,W,H>&	Matrix<K,W,H>::scl(K scalar) { return *this *= scalar; };


/******************************************************************************/
/* ## Exercice 02                                                             */
/******************************************************************************/

	template <class K, int W, int H> 
	Matrix<K,W,H>	Matrix<K,W,H>::lerp(const Matrix& a, const Matrix& b, const float t){
		Matrix result;
		ft::lerp((Matrix::raw_type&)a, (Matrix::raw_type&)b, t, (Matrix::raw_type&)result);
		return result;
	}

/******************************************************************************/
/* ## Exercice 07                                                             */
/******************************************************************************/

	template <class K, int W, int H> 
	template <int P>
	Matrix<K,P,H>	Matrix<K,W,H>::mul_mat(const Matrix<K,P,W>& input) const {
		Matrix<K,P,H> result;

		for (int  x=0;  x<P;  x++) // Iterates over  Input-X and Output-X
		for (int oy=0; oy<H; oy++) // Iterates over Output-Y and Factor-Y
		for (int iy=0; iy<W; iy++) // Iterates over  Input-Y and Factor-X
		{
			result[x][oy] += input[x][iy] * (*this)[iy][oy];
		}

		return result;
	}

	template <class K, int W, int H> 
	Vector<K,H>  	Matrix<K,W,H>::mul_vec(const Vector<K,W>& vector) const {
		Matrix<K,1,H> result = this->mul_mat((const Matrix<K,1,W>&)vector);
		return (Vector<K,H>&)result;
	}

/******************************************************************************/
/* ## Exercice 08                                                             */
/******************************************************************************/

	template <class K, int W, int H> 
	K	Matrix<K,W,H>::trace() const {
		K result = 0;

		for (int i=0; i<W && i<H; i++)
			result += (*this)[i][i];

		return result;
	}

/******************************************************************************/
/* ## Exercice 09                                                             */
/******************************************************************************/

	template <class K, int W, int H> 
	Matrix<K,H,W>	Matrix<K,W,H>::transpose() const {
		Matrix<K,H,W> result;

		for (int x=0; x<W; x++)
		for (int y=0; y<H; y++)
			result[y][x] = (*this)[x][y];

		return result;
	}

/******************************************************************************/
/* ## Exercice 11                                                             */
/******************************************************************************/

	template <class K, int W, int H> 
	K	Matrix<K,W,H>::determinant() const {
		int xMap[W];
		for (int i=0; i<W; i++)
			xMap[i] = i;

		return subdet(0, W, H, W, xMap);
	}

	template <class K, int W, int H> 
	K	Matrix<K,W,H>::subdet(int y, int w, int h, int slice, const int* xMap) const {
		K result = 0;
		int subXMap[w];
		for (int i=0; i<slice; i++)
			subXMap[i] = xMap[i];
		for (int i=slice; i<w; i++)
			subXMap[i] = xMap[i+1];

		if (w==1 || h==1)
			return (*this)[subXMap[0]][y];

		for (int i=0; i<w; i++){
			K sub = subdet(y+1, w-1, h-1, i, subXMap);
			K factor = (*this)[subXMap[i]][y];
			result += factor * (i%2 ? -sub : sub);
		}

		return result;
	}

/******************************************************************************/
/* ## Exercice 13                                                             */
/******************************************************************************/

	template <class K, int W, int H> 
	size_t	Matrix<K,W,H>::rank() const {
		Matrix ech = this->row_echelon();

		int y = 0;
		for (int x=0; x<W && y<H; x++)
			if (ech[x][y])
				y++;

		return y;
	}
}

#include "Matrix_RowEchelon.hpp"
