/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix_RowEchelon.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:14:44 by abaur             #+#    #+#             */
/*   Updated: 2023/03/17 16:11:19 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Matrix.hpp"

namespace ft
{
	/**
	 * mx[pivX][pivY] is assumed to be 1
	 */
	template <class K, int W, int H>
	static inline void	Reduce(Matrix<K,W,H>& mx, int pivX, int pivY){
		for (int y=0; y<H; y++)
		if (y != pivY)
		{
			for (int x=pivX+1; x<W; x++)
				mx[x][y] -= mx[pivX][y] * mx[x][pivY];
			mx[pivX][y] = 0;
		}
	}

	template <class K, int W, int H>
	static inline void	RowSwap(Matrix<K,W,H>& mx, int dstY, int srcY, K dstScalar){
		K _swp;

		for (int x=0; x<W; x++){
				_swp = mx[x][srcY];
				mx[x][srcY] = mx[x][dstY];
				mx[x][dstY] = _swp * dstScalar;
		}
	}

	/**
	 * @param pivX	The x coordinate of the desired pivot. All cells below this 
	 * 	coordinate will be assumed to be 0.
	 * @param pivY	The row to start the search from. All rows below this 
	 * 	coordinate will be ignored.
	 */
	template <class K, int W, int H>
	static inline int	FindPivotCandidate(const Matrix<K,W,H>& mx, int pivX, int pivY){
		for (int y=pivY; y<H; y++)
			if (mx[pivX][y])
				return y;

		return -1;
	}

	template <class K, int W, int H> 
	Matrix<K,W,H>	Matrix<K,W,H>::row_echelon() const {
		Matrix<K,W,H>	result = *this;
		int pivX = 0;
		int pivY = 0;

		while (pivY<H && pivX<W) {
			int candidate = FindPivotCandidate(result, pivX, pivY);
			if (candidate < 0){
				pivX++;
				continue;
			}
			else {
				RowSwap(result, pivY, candidate, (K)1/result[pivX][pivY]);
				Reduce(result, pivX, pivY);
				pivX++; pivY++;
			}
		}

		return result;
	}
}
