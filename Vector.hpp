/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:24:46 by abaur             #+#    #+#             */
/*   Updated: 2023/02/16 16:09:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <sstream>
#include <stdexcept>
#include <cstring>

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

		operator const array_type&() const;

		/**
		 * Parse a vector formatted as "x,y,z,..."
		 * @param str	The string to Parse
		 * @param outEnd	Outputs the character following the parsed text
		 * @throw	The string does not contain a valid vector.
		 */
		static Vector	StrToVec(const char* str, char** outend = NULL);
		std::string	ToString() const;

		// Ex 00
		Vector&	operator+=(const Vector&);
		Vector&	operator-=(const Vector&);
		Vector&	operator*=(K);
		Vector&	add(const Vector&);
		Vector&	sub(const Vector&);
		Vector&	scl(K);

		// Ex 01
		/**
		 * If arrays are not of equal size, extraneous data is ignored.
		 * This is equivalent to backfilling the shorter array with zero's.
		 */
		static Vector	linear_combination(const std::vector<const Vector&>&, const std::vector<K>&);
	};
}

template<class K, int S>
std::ostream&	operator<<(std::ostream&, const ft::Vector<K,S>&);



/******************************************************************************/
/* # Implementations                                                          */
/******************************************************************************/

namespace ft 
{
	template <class K, int S>
	Vector<K,S>::Vector(void) {
		bzero(&this->array, sizeof(this->array));
	}
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

	template <class K, int S>
	Vector<K,S>::operator const array_type&() const {
		return this->array;
	}

	template <class K, int S>
	Vector<K,S>	Vector<K,S>::StrToVec(const char* str, char** outEnd){
		Vector result;

		for (int i=0; i<S; i++){
			if (i){
				if(*str==',')
					str++;
				else
					throw std::invalid_argument("Argument vector is invalid");
			}
			result[i] = std::strtof(str, (char**)&str);
		}

		if (outEnd != NULL)
			outEnd = (char**)str;
		return result;
	}
	template <class K, int S>
	std::string	Vector<K,S>::ToString() const {
		std::stringstream cout;
		cout << *this;
		return cout.str();
	}; 

}


template<class K, int S>
std::ostream&	operator<<(std::ostream& cout, const ft::Vector<K,S>& vec){
	for (int i=0; i<S; i++) {
		if (i)
			cout << ',';
		cout << vec[i];
	}
	return cout;
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


/******************************************************************************/
/* ## Exercice 01                                                             */
/******************************************************************************/

namespace ft
{
	template <class K, int S> 
	Vector<K,S>	Vector<K,S>::linear_combination(const std::vector<const Vector&>& u, const std::vector<K>& coefs){
		Vector result;
		int nmax = (u.size() < coefs.size()) ? u.size() : coefs.size();

		for (int i=0; i<S;    i++)
		for (int n=0; n<nmax; n++)
			result[i] += u[n][i] * coefs[n];

		return result;
	};
}
