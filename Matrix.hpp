/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:36:26 by abaur             #+#    #+#             */
/*   Updated: 2023/02/11 20:49:38 by abaur            ###   ########.fr       */
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
		Matrix(array_type);
		Matrix(const Matrix&);

		array_type	array;

		column_type&	operator[](int);
		const column_type& 	operator[](int) const;

		Matrix	operator+=(const Matrix);
		Matrix	operator-=(const Matrix);
		Matrix	operator*=(K);

		// Ex 00
		Matrix	add(const Matrix);
		Matrix	sub(const Matrix);
		Matrix	scl(K);
	};
}
