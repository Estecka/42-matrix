/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoundingBox.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:05:15 by abaur             #+#    #+#             */
/*   Updated: 2023/04/07 14:33:09 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Vector.hpp"

namespace ft
{
	template <class K, int N>
	struct BoundingBox
	{
		typedef ft::Vector<K,N>	Vector;

		Vector	min;
		Vector	max;
	};
}
