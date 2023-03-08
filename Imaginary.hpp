/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Imaginary.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:48:49 by abaur             #+#    #+#             */
/*   Updated: 2023/03/08 14:44:53 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ostream>
#include <sstream>

namespace ft
{
	template <class K>
	struct Imaginary
	{
		K	r, i;

		Imaginary(void);
		Imaginary(const K&);
		Imaginary(const K& r, const K& i);
		Imaginary(const Imaginary&);

		Imaginary&	operator=(const K&);
		Imaginary&	operator=(const Imaginary&);

		explicit operator K() const;
		operator bool()const;
		bool	operator !()const;

		bool	operator==(const K&) const;
		bool	operator==(const Imaginary&) const;
		bool	operator!=(const K&) const;
		bool	operator!=(const Imaginary&) const;


		Imaginary&	operator+() const;
		Imaginary 	operator-() const;

		Imaginary	operator+(const Imaginary&) const;
		Imaginary	operator-(const Imaginary&) const;
		Imaginary	operator*(const Imaginary&) const;
		Imaginary	operator/(const Imaginary&) const;
		Imaginary	operator+(const K&) const;
		Imaginary	operator-(const K&) const;
		Imaginary	operator*(const K&) const;
		Imaginary	operator/(const K&) const;

		Imaginary&	operator+=(const Imaginary&);
		Imaginary&	operator-=(const Imaginary&);
		Imaginary&	operator*=(const Imaginary&);
		Imaginary&	operator/=(const Imaginary&);
		Imaginary&	operator+=(const K&);
		Imaginary&	operator-=(const K&);
		Imaginary&	operator*=(const K&);
		Imaginary&	operator/=(const K&);

		std::string	ToString() const;
	};

	template <class K>
	std::ostream&	operator<<(std::ostream&, const Imaginary<K>&);
}


/******************************************************************************/
/* # Implementations                                                          */
/******************************************************************************/


namespace ft
{
/******************************************************************************/
/* ## Constructors                                                            */
/******************************************************************************/
	template<class K>
	Imaginary<K>::Imaginary(void)
	: r(), i()
	{}
	template<class K>
	Imaginary<K>::Imaginary(const K& _r) 
	: r(_r), i()
	{}
	template<class K>
	Imaginary<K>::Imaginary(const K& _r, const K& _i) 
	: r(_r), i(_i)
	{}
	template<class K>
	Imaginary<K>::Imaginary(const Imaginary& other) 
	: r(other.r), i(other.i)
	{}


/******************************************************************************/
/* ## Assignation                                                             */
/******************************************************************************/

	template<class K>
	Imaginary<K>& Imaginary<K>::operator=(const K& other) { 
		return *new(this) Imaginary(other);
	}
	template<class K>
	Imaginary<K>& Imaginary<K>::operator=(const Imaginary& other) { 
		return *new(this) Imaginary(other);
	}


/******************************************************************************/
/* ## Cast                                                                    */
/******************************************************************************/

	template<class K>
	Imaginary<K>::operator K() const { 
		return this->r;
	}
	template<class K>
	Imaginary<K>::operator bool() const { 
		return r || i;
	}
	template<class K>
	bool	Imaginary<K>::operator !() const { 
		return !r && !i;
	}


/******************************************************************************/
/* ## Comparison                                                              */
/******************************************************************************/

	template<class K>
	bool	Imaginary<K>::operator==(const K& other) const { 
		return this->r==other && this->i==0;
	}
	template<class K>
	bool	Imaginary<K>::operator==(const Imaginary& other) const { 
		return this->r==other.r && this->i==other.i;
	}
	template<class K>
	bool	Imaginary<K>::operator!=(const K& other) const { 
		return this->r!=other || this->i!=0;
	}
	template<class K>
	bool	Imaginary<K>::operator!=(const Imaginary& other) const { 
		return this->r!=other.r || this->i!=other.i;
	}


/******************************************************************************/
/* ## Arithmetic                                                              */
/******************************************************************************/

	template<class K>
	Imaginary<K>&	Imaginary<K>::operator+() const {
		return *this;
	}
	template<class K>
	Imaginary<K>	Imaginary<K>::operator-() const {
		return {
			-this->r,
			-this->i,
		};
	}

	template<class K>
	Imaginary<K>	Imaginary<K>::operator+(const Imaginary& other) const { 
		return {
			this->r + other.r,
			this->i + other.i,
		};
	}
	template<class K>
	Imaginary<K>	Imaginary<K>::operator-(const Imaginary& other) const {
		return {
			this->r - other.r,
			this->i - other.i,
		};
	}
	template<class K>
	Imaginary<K>	Imaginary<K>::operator*(const Imaginary& other) const {
		return {
			this->r * other.r + this->i * other.i,
			2 * other.r * this->r,
		};
	}
	template<class K>
	Imaginary<K>	Imaginary<K>::operator/(const Imaginary& other) const {
		K divisor = 1 / (other.r * other.r - other.i * other.i);
		return {
			divisor * (this->r * other.r - this->i * other.i),
			divisor * (this->i * other.r - this->r * other.i),
		};
	}

	template<class K>
	Imaginary<K>	Imaginary<K>::operator+(const K& other) const { 
		return {
			this->r + other,
			this->i,
		};
	}
	template<class K>
	Imaginary<K>	Imaginary<K>::operator-(const K& other) const {
		return {
			this->r - other,
			this->i,
		};
	}
	template<class K>
	Imaginary<K>	Imaginary<K>::operator*(const K& other) const {
		return {
			this->r * other,
			this->i * other,
		};
	}
	template<class K>
	Imaginary<K>	Imaginary<K>::operator/(const K& other) const {
		return {
			this->r / other,
			this->i / other,
		};
	}

	template<class K> Imaginary<K>&	Imaginary<K>::operator+=(const Imaginary& other) { return *this = *this + other; }
	template<class K> Imaginary<K>&	Imaginary<K>::operator-=(const Imaginary& other) { return *this = *this - other; }
	template<class K> Imaginary<K>&	Imaginary<K>::operator*=(const Imaginary& other) { return *this = *this * other; }
	template<class K> Imaginary<K>&	Imaginary<K>::operator/=(const Imaginary& other) { return *this = *this / other; }
	template<class K> Imaginary<K>&	Imaginary<K>::operator+=(const K& other) { return *this = *this + other; }
	template<class K> Imaginary<K>&	Imaginary<K>::operator-=(const K& other) { return *this = *this - other; }
	template<class K> Imaginary<K>&	Imaginary<K>::operator*=(const K& other) { return *this = *this * other; }
	template<class K> Imaginary<K>&	Imaginary<K>::operator/=(const K& other) { return *this = *this / other; }


/******************************************************************************/
/* ## Strings                                                                 */
/******************************************************************************/

	template<class K>
	std::string	Imaginary<K>::ToString() const {
		std::stringstream cout;
		cout << *this;
		return cout.str();
	}

	template<class K>
	std::ostream&	operator<<(std::ostream& cout, const ft::Imaginary<K>& n) {
		if (n.r)
			cout << n.r;
		if (n.r && n.i)
			cout << " + ";
		if (n.i)
			cout << n.i << "i";
		if (!n.r && !n.i)
			cout << '0';

		return cout;
	}
}

