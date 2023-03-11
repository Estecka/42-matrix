/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:55:41 by abaur             #+#    #+#             */
/*   Updated: 2023/03/11 15:48:28 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Imaginary.hpp"

#include <cmath>

namespace ft
{
	template <class K>	inline K	abs(const Imaginary<K>&);
	template <class K>	inline K	abs(const K&);

	template <class K>	inline K	abssqr(const Imaginary<K>&);
	template <class K>	inline K	abssqr(const K&);
}


/* ************************************************************************** */
/* # Implementation                                                           */
/* ************************************************************************** */

namespace ft
{
	template <class K>
	inline K	abs(const Imaginary<K>&n) {
		return std::pow(abssqr(n) , 0.5f);
	}
	template <class K>
	inline K	abs(const K& n){
		return (n < 0) ? -n : n;
	}

	template <class K>
	inline K	abssqr(const Imaginary<K>& n){
		return (n.r*n.r) + (n.i*n.i);
	}
	template <class K>
	inline K	abssqr(const K& n){
		return (n * n);
	}
}
