/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:24:46 by abaur             #+#    #+#             */
/*   Updated: 2023/02/11 20:50:14 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template <class K, int SIZE> 
	struct Vector
	{
		typedef K	array_type[SIZE];

		Vector(void);
		Vector(array_type);
		Vector(const Vector&);

		array_type	array;


		K&	operator[](int);
		K 	operator[](int) const;

		Vector&	operator+=(const Vector&);
		Vector&	operator-=(const Vector&);
		Vector&	operator*=(K);

		// Ex 00
		Vector&	add(const Vector&);
		Vector&	sub(const Vector&);
		Vector&	scl(K);
	};
}
