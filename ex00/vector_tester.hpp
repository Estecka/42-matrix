/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:01:54 by abaur             #+#    #+#             */
/*   Updated: 2023/02/13 18:54:31 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Vector.hpp"

#include <iostream>


namespace ft
{
	template <class K, int N>
	class	VectorTestSuit {
	public:
		typedef Vector<K,N>	Vector;

		static int	main(int argc, char** argv);

		static int	Add(const Vector&, const Vector&);
		static int	Sub(const Vector&, const Vector&);
		static int	Scl(const Vector&, K);
	};
}

/* ************************************************************************** */
/* # Implementation                                                           */
/* ************************************************************************** */


namespace ft
{
	template <class K, int N>
	int	VectorTestSuit<K,N>::main(int, char**){
		std::cout << "Test suit: " << N << std::endl;
		return EXIT_SUCCESS;
	}

	template <class K, int N>
	int	VectorTestSuit<K,N>::Add(const Vector& a, const Vector& b){
		Vector r = a;
		r.add(b);

		return EXIT_SUCCESS;
	}


	template <class K, int N>
	int	VectorTestSuit<K,N>::Sub(const Vector&, const Vector&){
		return EXIT_SUCCESS;
	}


	template <class K, int N>
	int	VectorTestSuit<K,N>::Scl(const Vector&, K){
		return EXIT_SUCCESS;
	}
}
