/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atok.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:25:23 by abaur             #+#    #+#             */
/*   Updated: 2023/03/07 16:24:41 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Imaginary.hpp"
#include <cstdlib>

namespace ft
{
	template <class K>
	inline K	atok(const char*);

	template <class K>
	inline K	strtok(const char* __restrict__ nptr, char** __restrict__ enptr);

	template <class K>
	Imaginary<K>	atoik(const char*);

	template <class K>
	Imaginary<K>	strtoik(const char* __restrict__ nptr, char** __restrict__ enptr);
} 


/* ************************************************************************** */
/* # Implementation                                                           */
/* ************************************************************************** */

namespace ft
{
	template <class K>
	Imaginary<K>	atoik(const char* nptr){
		return ft::strtoik<K>(nptr, NULL);
	}

	template <class K>
	Imaginary<K>	strtoik(const char* __restrict__ cursor, char** __restrict__ outEnd){
		Imaginary<K>	result = 0;
		const char*	endPtr = cursor;
		bool negI = false;

		//r
		result.r = ft::strtok<K>(cursor, endPtr);
		cursor = endPtr;

		//+
		if (*cursor == '-')
			negI = true;
		else if (*cursor != '+')
			goto stop;
		cursor++;

		//i
		result.i = ft::strtok<K>(cursor, cursor);
		if (*cursor == 'i')
			endPtr = cursor++;
		else {
			result.i = 0;
			goto stop;
		}
		if (negI)
			result.i *= -1;

		stop:
		if (outEnd)
			*outEnd = (char*)endPtr;
		return result;
	}
} 


/* ************************************************************************** */
/* # Specialisation                                                           */
/* ************************************************************************** */

namespace ft
{
	template<> float	atok<float>  (const char* nptr){ return std::atof(nptr); }
	template<> float	strtok<float>(const char* nptr, char** endptr){ return std::strtof(nptr, endptr); }

	template<> Imaginary<float>	atok<Imaginary<float>>(const char* nptr){ return ft::strtoik<float>(nptr, NULL); }
	template<> Imaginary<float>	strtok<Imaginary<float>>(const char* nptr, char** endptr){ return ft::strtoik<float>(nptr, endptr); }
}
