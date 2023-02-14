/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:35 by abaur             #+#    #+#             */
/*   Updated: 2023/02/14 20:50:26 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "../TestFactory.hpp"
#include "vector_tester.hpp"

#include <iostream>

#define N_MAX	4
#define M_MAX	4

extern int main(int argc, char** argv){
	if (argc < 3){
		std::cerr << "Not enough arguments" << std::endl;
		return EXIT_FAILURE;
	}

	ft::TesterMap	vectorTesters;
	ft::TestFactory<ft::VectorTestSuit, float, N_MAX>::CreateTests(vectorTesters);

	int n = std::atoi(argv[1]);
	vectorTesters.at(n)(argc, argv);
}