/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atok.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:25:23 by abaur             #+#    #+#             */
/*   Updated: 2023/03/08 16:05:38 by abaur            ###   ########.fr       */
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
	inline Imaginary<K>	atoik(const char* nptr){
		return ft::strtoik<K>(nptr, NULL);
	}

	template <class K>
	Imaginary<K>	strtoik(const char* __restrict__ cursor, char** __restrict__ outEnd){
		Imaginary<K>	result = 0;
		char*	endPtr;
		
		do {
			K n = ft::strtok<K>(cursor, &endPtr);
			if (*endPtr == 'i'){
				result.i += (endPtr==cursor) ? 1 : n; // "i" alone shall be interpreted as 1*i, not 0*i
				endPtr++;
			}
			else
				result.r += n;
		}
		while ((endPtr != cursor)
			&& (cursor = endPtr)
			&& (*endPtr=='-' || *endPtr=='+')
		);
		
		if (outEnd)
			*outEnd = endPtr;
		return result;
	}
} 


/* ************************************************************************** */
/* # Specialisation                                                           */
/* ************************************************************************** */

namespace ft
{
	template<> inline float	atok<float>  (const char* nptr){ return std::atof(nptr); }
	template<> inline float	strtok<float>(const char* nptr, char** endptr){ return std::strtof(nptr, endptr); }

	template<> inline Imaginary<float>	atok<Imaginary<float>>(const char* nptr){ return ft::strtoik<float>(nptr, NULL); }
	template<> inline Imaginary<float>	strtok<Imaginary<float>>(const char* nptr, char** endptr){ return ft::strtoik<float>(nptr, endptr); }
}
