/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:22:09 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/08 18:02:04 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){
	type = "default";
}

AMateria::AMateria(std::string const &t){
	type = t;
}

std::string const &AMateria::getType() const{
	return (type);
}

AMateria &AMateria::operator=(const AMateria &other){
	if (this != &other)
		type = other.getType();
	return (*this);
}

/* void AMateria::use(ICharacter &){

} */