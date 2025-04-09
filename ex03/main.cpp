/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:59:29 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/09 16:01:29 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(){
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());//minventory[0] = ice
	src->learnMateria(new Cure());//minventory[1] = cure
	//std::cout << "inventary type: " << minventory[i]->getType() << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	//std::cout << "DEBUGGER" << std::endl; 
	tmp = src->createMateria("ice");
	//std::cout << "tmp type: " << tmp->getType() << std::endl;
	me->equip(tmp);
	//std::cout << "inventory[0] type: " << me->getInventory(0)->getType() << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	//std::cout << "inventory[1] type: " << me->getInventory(1)->getType() << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}