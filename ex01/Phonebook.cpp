/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:42:33 by atamas            #+#    #+#             */
/*   Updated: 2024/10/11 18:18:59 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>

#include "Phonebook.hpp"

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook()
{
}

bool	isOnlyWhitespace(const	std::string &str)
{
	std::string::size_type i = 0;
	while (i < str.size())
	{
		if (!isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	isOnlyNumbers(const	std::string &str)
{
	std::string::size_type i = 0;
	while (i < str.size())
	{
		if (str[i] > '9' || str[i] < '0')
			return (false);
		i++;
	}
	return (true);
}

void	add_contact(PhoneBook &book)
{
	bool			filled = false;
	Contact			tmp;
	std::string		firstname;
	std::string		lastname;
	std::string		nickname;
	std::string		phone_number;
	std::string		darkest_secret;

	std::cout << "First name: ";
	std::getline(std::cin, firstname);
	std::cout << "Last name: ";
	std::getline(std::cin, lastname);
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin, phone_number);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkest_secret);

	if ((firstname.empty() == 0 || !isOnlyWhitespace(firstname)) && (lastname.empty() == 0 || !isOnlyWhitespace(lastname))
		&& (nickname.empty() == 0 || !isOnlyWhitespace(nickname)) && (phone_number.empty() == 0 || !isOnlyWhitespace(phone_number))
			 && isOnlyNumbers(phone_number) && (darkest_secret.empty() == 0 || !isOnlyWhitespace(darkest_secret)))
				filled = true;
	if (filled == true)
	{
		if (book.size < 8)
		{
			tmp.setFirstName(firstname);
			tmp.setLastName(lastname);
			tmp.setNickname(nickname);
			tmp.setPhoneNumber(phone_number);
			tmp.setDarkestSecret(darkest_secret);
			tmp.id = book.size;
			book.size += 1;
			book.contacts[book.size] = tmp;
		}
	}
}

int	main(void)
{
	PhoneBook	book;
	bool		exit = false;
	std::string	command;

	book.size = 0;
	while (exit == false)
	{
		command.clear();
		std::cout << "Write your command here: ";
		std::getline(std::cin, command);
		if (command.compare("EXIT") == 0)
			exit = true;
		else if (command.compare("ADD") == 0)
			add_contact(book);
		else if (command.compare("SEARCH") == 0)
			break;
	}
	std::cout << book.contacts[0].getFirstName() << '\n';
}