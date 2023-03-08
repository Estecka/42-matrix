/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_tester.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:00:22 by abaur             #+#    #+#             */
/*   Updated: 2023/03/08 15:29:32 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "lerp.hpp"
#include "Format.hpp"
#include "atok.hpp"

#include <cstdlib>


namespace ft
{
	template <class K>
	class	NumberTestSuit {
	public:
		static int	main(int argc, char** argv);

		static int	lerp(const K&, const K&, float);
	};
}

/* ************************************************************************** */
/* # Implementation                                                           */
/* ************************************************************************** */


namespace ft
{
	template <class K>
	int	NumberTestSuit<K>::main(int argc, char** argv){
		if (argc < 4){
			std::cerr << "Not enough arguments" << std::endl;
			return EXIT_FAILURE;
		}
		std::string subcmd = argv[0];
		if (subcmd == "lerp")	return lerp(ft::atok<K>(argv[1]), ft::atok<K>(argv[2]), std::atof(argv[3]));

		std::cerr << "Unsupported command: " << subcmd << std::endl;
		return EXIT_FAILURE;
	}


/* ************************************************************************** */
/* ## Ex02                                                                    */
/* ************************************************************************** */

	template <class K>
	int	NumberTestSuit<K>::lerp(const K& a, const K& b, float t){
		K r = ft::lerp(a, b, t);
		PrintKLerp(a, b, t, r);
		return EXIT_SUCCESS;
	}
}
