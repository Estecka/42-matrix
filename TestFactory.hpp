/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestFactory.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:52:44 by abaur             #+#    #+#             */
/*   Updated: 2023/02/14 20:50:02 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>

namespace ft
{
	typedef int (*TesterType)(int, char**);
	typedef std::map<int, TesterType>	TesterMap;


	template <template <class,int> class T, class K, int N>
	class TestFactory {
	public:
		static void	CreateTests(TesterMap& outMap){
			outMap[N] = T<K, N>::main;
			TestFactory<T, K, N-1>::CreateTests(outMap);
		}
	};

	template <template <class,int> class T, class K>
	class TestFactory<T, K,0> {
	public:
		static void	CreateTests(TesterMap&){};
	};
}
