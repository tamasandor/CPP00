/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:53:09 by atamas            #+#    #+#             */
/*   Updated: 2024/10/11 17:32:16 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contacts.hpp"


class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook();
		Contact	contacts[7];
		int		size;
};

// PhoneBook::PhoneBook(void);
// PhoneBook::~PhoneBook();


#endif

