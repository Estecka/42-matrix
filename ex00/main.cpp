/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:35 by abaur             #+#    #+#             */
/*   Updated: 2023/02/13 18:56:37 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector.hpp"
#include "../Matrix.hpp"

#include "vector_tester.hpp"

#include <iostream>
#include <map>

#define N_MAX	4
#define M_MAX	4

typedef int (*TesterType)(int, char**);
typedef std::map<int, TesterType>	TesterMap;


template <class K, int N, template <class,int> class T>
class TestFactory {
public:
	static void	CreateTests(TesterMap& outMap){
		outMap[N] = T<K, N>::main;
		TestFactory<K, N-1, T>::CreateTests(outMap);
	}
};
template <class K, template <class,int> class T>
class TestFactory<K,0,T> {
public:
	static void	CreateTests(TesterMap&){};
};


extern int main(int argc, char** argv){
	if (argc < 3){
		std::cerr << "Not enough arguments" << std::endl;
		return EXIT_FAILURE;
	}

	TesterMap	vectorTesters;
	TestFactory<float, N_MAX, ft::VectorTestSuit>::CreateTests(vectorTesters);

	int n = std::atoi(argv[1]);
	vectorTesters.at(n)(argc, argv);
}