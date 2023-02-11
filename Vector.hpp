/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:24:46 by abaur             #+#    #+#             */
/*   Updated: 2023/02/11 22:17:50 by abaur            ###   ########.fr       */
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
		Vector(const Vector&);
		Vector(const array_type&);
		Vector&	operator=(const Vector&);
		Vector&	operator=(const array_type&);

		array_type	array;


		K&	operator[](int);
		K 	operator[](int) const;

		// Ex 00
		Vector&	operator+=(const Vector&);
		Vector&	operator-=(const Vector&);
		Vector&	operator*=(K);
		Vector&	add(const Vector&);
		Vector&	sub(const Vector&);
		Vector&	scl(K);
	};
}


/******************************************************************************/
/* # Implementations                                                          */
/******************************************************************************/

namespace ft 
{
	template <class K, int S>
	Vector<K,S>::Vector(void) 
	: array({0}) 
	{}
	template <class K, int S>
	Vector<K,S>::Vector(const Vector& other) 
	: Vector(other.array) 
	{}
	template <class K, int S>
	Vector<K,S>::Vector(const array_type& other) {
		for (int i=0; i<S; i++)
			this->array[i] = other[i];
	};

	template <class K, int S>
	Vector<K,S>&	Vector<K,S>::operator=(const Vector& other) {
		new (this) Vector(other.array);
	};
	template <class K, int S>
	Vector<K,S>&	Vector<K,S>::operator=(const array_type& other) {
		new (this) Vector(other.array);
	};


	template <class K, int S> K&	Vector<K,S>::operator[](int i)       { return this->array[i]; };
	template <class K, int S> K 	Vector<K,S>::operator[](int i) const { return this->array[i]; };
}


/******************************************************************************/
/* ## Exercice 00                                                             */
/******************************************************************************/

namespace ft
{
	template <class K, int S> 
	Vector<K,S>&	Vector<K,S>::operator+=(const Vector& other) {
		for (int i=0; i<S; i++)
			this->array[i] += other.array[i];
		return *this;
	};
	template <class K, int S> 
	Vector<K,S>&	Vector<K,S>::operator-=(const Vector& other) {
		for (int i=0; i<S; i++)
			this->array[i] -= other.array[i];
		return *this;
	};
	template <class K, int S> 
	Vector<K,S>&	Vector<K,S>::operator*=(K scalar) {
		for (int i=0; i<S; i++)
			this->array[i] *= scalar;
		return *this;
	};

	template <class K, int S> Vector<K,S>&	Vector<K,S>::add(const Vector& other) { return *this += other; };
	template <class K, int S> Vector<K,S>&	Vector<K,S>::sub(const Vector& other) { return *this -= other; };
	template <class K, int S> Vector<K,S>&	Vector<K,S>::scl(K scalar) { return *this *= scalar; };
}
