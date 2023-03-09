/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atok.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:25:23 by abaur             #+#    #+#             */
/*   Updated: 2023/03/09 15:37:31 by abaur            ###   ########.fr       */
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
			if (cursor != endPtr) {
				if (*endPtr == 'i')
					result.i += n, endPtr++;
				else
					result.r += n;
			}
			else if (*cursor == 'i')
				result.i += 1, endPtr++;
			else if (cursor[0]=='+' && cursor[1]=='i')
				result.i += 1, endPtr+=2;
			else if (cursor[0]=='-' && cursor[1]=='i')
				result.i -= 1, endPtr+=2;
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
