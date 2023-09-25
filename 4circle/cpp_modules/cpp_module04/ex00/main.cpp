/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:29:22 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 18:14:46 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl; 
		std::cout << i->getType() << " " << std::endl; 
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete j;
		delete i;
		delete meta;
	}
	std::cout << "\n< Worng Test Case> \n\n";
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		
		std::cout << i->getType() << " " << std::endl; 
		i->makeSound();
		meta->makeSound();
		
		delete i;
		delete meta;
	}
	return 0; 
}
