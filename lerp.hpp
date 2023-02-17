/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:54:01 by abaur             #+#    #+#             */
/*   Updated: 2023/02/17 17:47:10 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template <class K>
	extern inline K	lerp(K a, K b, K t){
		return (a * (1-t)) + (b * t);
	}

	template <class K, int S>
	extern inline void	lerp(const K (&a)[S], const K (&b)[S], const K t, K (&out)[S]){
		for (int i=0; i<S; i++)
			out[i] = (a[i] * (1-t)) + (b[i] * t);
	}
}
