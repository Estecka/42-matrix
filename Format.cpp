/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:56:31 by abaur             #+#    #+#             */
/*   Updated: 2023/02/23 19:10:35 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Format.hpp"

namespace ft 
{
	extern int	max(int a, int b){
		return (a>b) ? a : b;
	}
	extern int	min(int a, int b){
		return (a<b) ? a : b;
	}

	extern int	VLen(int width, int lmax){
		return 2 + lmax*width + 2*(width-1) + 2;
	}
}
