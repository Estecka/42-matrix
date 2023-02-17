/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:36:26 by abaur             #+#    #+#             */
/*   Updated: 2023/02/17 18:39:39 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "lerp.hpp"

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
	};
}

template<class K, int W, int H>
std::ostream&	operator<<(std::ostream&, const ft::Matrix<K,W,H>&);

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

		for (int x=0; x<W; x++){
			if (x){
				if(*str==';')
					str++;
				else
					throw std::invalid_argument("Argument matrix is invalid");
			}
			for (int y=0; y<H; y++){
				if (y){
					if(*str==',')
						str++;
					else
						throw std::invalid_argument("Argument matrix is invalid");
				}
				result[x][y] = std::strtof(str, (char**)&str);
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
		for (int x=0; x<W; x++) {
			if (x)
				cout << ';';
			for (int y=0; y<H; y++) {
				if (y)
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
}
