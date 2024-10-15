/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:42:33 by atamas            #+#    #+#             */
/*   Updated: 2024/10/15 22:20:48 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <stdlib.h>
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

void	displayContactInfo(PhoneBook &book, int index)
{
	if (index > book.size)
	{
		std::cout << "Contact doesn't exist\n";
		return ;
	}
	std::cout << "First name: " << book.contacts[index - 1].getFirstName() << '\n';
	std::cout << "Last name: " << book.contacts[index - 1].getLastName() << '\n';
	std::cout << "Nick name: " << book.contacts[index - 1].getNickname() << '\n';
	std::cout <<  "Phone number: "<< book.contacts[index - 1].getPhoneNumber() << '\n';
	std::cout <<  "Darkest secret: "<< book.contacts[index - 1].getDarkestSecret() << '\n';
}

void	searchForContact(PhoneBook &book)
{
	std::string	temp;
	int			integer;

	if (book.size == 0)
	{
		std::cout << "Contact list is empty!\n";
		return ;
	}
	std::cout << "---------------------------------------------" << '\n';
	std::cout << "|     Index|First name| Last Name| Nick Name|" << '\n';
	std::cout << "|----------|----------|----------|----------|" << '\n';
	std::cout << std::right;
	for (int i = 0; i < book.size; i++)
	{
		book.contacts[i].printFormatted();
	}
	std::cout << "---------------------------------------------" << '\n';
	std::cout << std::left;
	std::cout << "Please enter the index of the contact you want to see: ";
	if (!getline(std::cin, temp))
		return ;
	if (temp.empty())
	{
		std::cout << "Input cannot be empty!\n";
		return ;
	}
	integer = atoi(temp.c_str());
	if (integer < 1 || integer > 8)
		std::cout << "The index can only be between 1 and 8";
	else
		displayContactInfo(book, integer);
}

void	addToContactArray(PhoneBook &book, Contact &new_contact)
{
	Contact	temp;
	int		i;

	if (book.size < 8)
		i = book.size;
	else
		i = 7;
	while (i > 0)
	{
		book.contacts[i] = book.contacts[i - 1];
		book.contacts[i].index = i + 1;
		i--;
	}
	book.contacts[0] = new_contact;
	book.contacts[0].index = 1;
	if (book.size < 8)
		book.size++;
}

void	createContact(PhoneBook &book)
{
	bool			filled = false;
	Contact			tmp;
	std::string		firstname;
	std::string		lastname;
	std::string		nickname;
	std::string		phone_number;
	std::string		darkest_secret;

	std::cout << "First name: ";
	if (!std::getline(std::cin, firstname))
		return ;
	std::cout << "Last name: ";
	if (!std::getline(std::cin, lastname))
		return ;
	std::cout << "Nickname: ";
	if (!std::getline(std::cin, nickname))
		return ;
	std::cout << "Phone number: ";
	if (!std::getline(std::cin, phone_number))
		return ;
	std::cout << "Darkest secret: ";
	if (!std::getline(std::cin, darkest_secret))
		return ;

	if ((firstname.empty() == 0 || !isOnlyWhitespace(firstname)) && (lastname.empty() == 0 || !isOnlyWhitespace(lastname))
		&& (nickname.empty() == 0 || !isOnlyWhitespace(nickname)) && (phone_number.empty() == 0 || !isOnlyWhitespace(phone_number))
			 && isOnlyNumbers(phone_number) && (darkest_secret.empty() == 0 || !isOnlyWhitespace(darkest_secret)))
				filled = true;
	if (filled == true)
	{
		tmp.setFirstName(firstname);
		tmp.setLastName(lastname);
		tmp.setNickname(nickname);
		tmp.setPhoneNumber(phone_number);
		tmp.setDarkestSecret(darkest_secret);
		tmp.index = 1;
		addToContactArray(book, tmp);
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
		if (!std::getline(std::cin, command))
			return (1);
		if (command.compare("EXIT") == 0)
			exit = true;
		else if (command.compare("ADD") == 0)
			createContact(book);
		else if (command.compare("SEARCH") == 0)
			searchForContact(book);
	}
}