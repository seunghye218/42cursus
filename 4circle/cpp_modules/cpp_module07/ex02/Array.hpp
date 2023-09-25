/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:47:04 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/24 17:21:14 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

template <typename T>
class   Array
{
	private:
		T		*arr;
		int		siz;
	public:
		Array(void) : arr(new T[0]), siz(0) {}

		Array(unsigned int n) : arr(new T[n]()), siz(n) {}

		Array(const Array& A) : arr(0)
		{
			*this = A;
		}

		Array& operator=(const Array& A)
		{
			if (this != &A)
			{
				delete [] arr;
				siz = A.siz;
				arr = new T[siz];
				for (int i = 0; i < A.siz; ++i)
					arr[i] = A.arr[i];
			}
			return *this;
		}

		~Array(void) {delete [] arr;}

		T&	operator[](int i)
		{
			if (i < 0 || i >= siz)
				throw std::out_of_range("out_of_range exception");
			return arr[i];
		}

		const T&	operator[](int i) const
		{
			if (i < 0 || i >= siz)
				throw std::out_of_range("out_of_range exception");
			return arr[i];
		}

		size_t	size(void) const
		{
			return (siz);
		}
};
