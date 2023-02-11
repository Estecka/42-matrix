/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:36:26 by abaur             #+#    #+#             */
/*   Updated: 2023/02/11 22:15:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template <class K, int WIDTH, int HEIGHT> 
	struct Matrix
	{
		typedef K	array_type[WIDTH][HEIGHT];
		typedef K	column_type[HEIGHT];

		Matrix(void);
		Matrix(const Matrix&);
		Matrix(const array_type&);
		Matrix&	operator=(const Matrix&);
		Matrix&	operator=(const array_type&);

		array_type	array;

		column_type&	operator[](int);
		const column_type& 	operator[](int) const;

		// Ex 00
		Matrix&	operator+=(const Matrix&);
		Matrix&	operator-=(const Matrix&);
		Matrix&	operator*=(K);
		Matrix&	add(const Matrix&);
		Matrix&	sub(const Matrix&);
		Matrix&	scl(K);
	};
}


/******************************************************************************/
/* # Implementations                                                          */
/******************************************************************************/

namespace ft 
{
	template <class K, int W, int H>
	Matrix<K,W,H>::Matrix(void) 
	: array({0}) 
	{}
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
}


/******************************************************************************/
/* ## Exercice 00                                                             */
/******************************************************************************/

namespace ft
{
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
}
