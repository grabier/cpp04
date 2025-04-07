/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:58:00 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/07 09:50:20 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat default constructor" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other){
	std::cout << "Cat copy constructor" << std::endl;
	type = other.type;
	brain = other.brain;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat &other){
	if (this != &other){
		type = other.type;
		brain = other.brain;
	}
	return (*this);
}

void Cat::setType(const std::string _type){
	type = _type;
}

std::string const Cat::getType(void) const{
	return (type);
}

void Cat::makeSound(void) const{
	std::cout << type << " says meaw" << std::endl;
}