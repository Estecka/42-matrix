/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conjugate.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:01:26 by abaur             #+#    #+#             */
/*   Updated: 2023/03/12 12:12:56 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Imaginary.hpp"

namespace ft
{
	template <class K>	inline Imaginary<K>	conjugate(const Imaginary<K>&);
	template <class K>	inline K           	conjugate(const K&);
}


/* ************************************************************************** */
/* # Implementation                                                           */
/* ************************************************************************** */

namespace ft
{
	template <class K>
	inline Imaginary<K>	conjugate(const Imaginary<K>& n) {
		return {
			 n.r,
			-n.i,
		};
	}
	template <class K>
	inline K	conjugate(const K& n){
		return n;
	}
}
