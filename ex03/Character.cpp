/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:58:00 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/08 13:08:48 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){
	for (int i = 0; i < 4; i++){
		inventory[i] = NULL;
	}
}

Character::Character(const std::string &n){
	name = n;
	for (int i = 0; i < 4; i++){
		inventory[i] = NULL;
	}
}

/* Character::Character(const Character &other){
	name = other.getName();
	for (int i = 0; i < 4; i++){
		inventory[i] = other.inventory[i]->clone();
	}
} */

Character::Character(const Character &other){
	*this = other;
}

Character::~Character(){
	for (int i = 0;  i < 4; i++){
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

Character &Character::operator=(const Character &other){
	this->name = other.getName();
	for(int i = 0; i < 4; i++){
		if (inventory[i] != NULL)
			this->setInventory(other.getInventory(i), i);
		else
			this->inventory[i] = NULL;
	}
	return *this;
}

void Character::setName(const std::string n){
	name = n;
}

const std::string &Character::getName() const{
	return (name);
}

void Character::setInventory(AMateria *mat, int i){
	if (i >= 0 && i < 4){
		if (inventory[i] != NULL)
			delete inventory[i];
		inventory[i] = mat->clone();
	}
	else
		std::cout << "setInventory: slot not valid" << std::endl;
}

AMateria *Character::getInventory(int i) const{
	if (i >= 0 && i < 4)
		return (inventory[i]);
	std::cout << "getInventory: slot not valid" << std::endl;
	return (NULL);
}

void Character::equip(AMateria *m){
	for (int i = 0; i < 4; i++){
		if (inventory[i] == NULL){
			inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int i){
	//k coño hago con las desequipadas
	if (inventory[i] != NULL){
		delete inventory[i];//seguramente no
		inventory[i] = NULL;
	}
	else
		std::cout << "Nothing to unequip" << std::endl; 
}

void Character::use(int i, ICharacter &c){
	if (i < 0 || i > 3){
		std::cout << "Use: not a valid inventory slot " << std::endl;
	}
	else{
		if (inventory[i] != NULL)
			inventory[i]->use(c);
		else
			std::cout << "No materia to use" << std::endl;
	}
}