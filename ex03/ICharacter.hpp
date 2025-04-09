/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:27:59 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/08 14:48:12 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class AMateria;

class ICharacter{
	public:
		virtual ~ICharacter(){}
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx)  = 0;
		virtual void use(int idx, ICharacter &target) = 0;
		virtual AMateria *getInventory(int) const = 0;
};