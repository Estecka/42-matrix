/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestFactory.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:52:44 by abaur             #+#    #+#             */
/*   Updated: 2023/02/15 19:21:21 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>

namespace ft
{
	typedef int (*TesterType)(int, char**);
	typedef std::map<int, TesterType>	TesterMap;


	template <template <class,int> class T, class K, int N>
	class TestFactoryN {
	public:
		static void	CreateTests(TesterMap& outMap){
			outMap[N] = T<K,N>::main;
			TestFactoryN<T,K,N-1>::CreateTests(outMap);
		}
		static TesterType	GetTest(int n){
			if (n != N)
				return TestFactoryN<T,K,N-1>::GetTest(n);
			else
				return T<K, N>::main;
		}
	};
	template <template <class,int> class T, class K>
	class TestFactoryN<T,K,0> {
	public:
		static void	CreateTests(TesterMap&){};
		static TesterType	GetTest(int){ return NULL; };
	};


	template <template <class,int,int> class T, class K, int N, int M>
	class TestFactoryNM {
	public:
		static TesterType	GetTest(int n, int m){
			if (n != N)
				return TestFactoryNM<T,K,N-1,M>::GetTest(n,m);
			if (m != M)
				return TestFactoryNM<T,K,N,M-1>::GetTest(n,m);
			else
				return T<K,N,M>::main;
		}
	};
	template <template <class,int,int> class T, class K, int N>
	class TestFactoryNM<T, K,N,0> {
	public:
		static TesterType	GetTest(int, int){ return NULL; };
	};
	template <template <class,int,int> class T, class K, int M>
	class TestFactoryNM<T, K,0,M> {
	public:
		static TesterType	GetTest(int, int){ return NULL; };
	};
}
