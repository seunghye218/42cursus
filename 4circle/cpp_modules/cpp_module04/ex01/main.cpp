/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:29:22 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/18 14:07:46 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl;

		delete j;//should not create a leak 
		delete i;
	}
	std::cout << "\n< Animal Array >\n\n";
	{
		Animal *arr[4];

		arr[0] = new Cat();
		arr[1] = new Cat();
		arr[2] = new Dog();
		arr[3] = new Dog();
		for (int i = 0; i < 4; ++i)
			arr[i]->makeSound();
		for (int i = 0; i < 4; ++i)
			delete arr[i];
	}
	std::cout << "\n< deep copy >\n\n";
	{
		Cat*	cat1 = new Cat;
		Cat*	cat2 = new Cat;

		std::cout << cat1->getBrain()->getIdea(0) << std::endl;

		cat2->getBrain()->setIdea(0, "cat2");
		std::cout << cat2->getBrain()->getIdea(0) << std::endl;

		*cat1 = *cat2;
		std::cout << cat1->getBrain()->getIdea(0) << std::endl;

		delete cat1;
		delete cat2;
	}
	return 0; 
}
