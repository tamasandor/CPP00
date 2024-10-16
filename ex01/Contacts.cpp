/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:03:53 by atamas            #+#    #+#             */
/*   Updated: 2024/10/15 17:33:25 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include <iomanip>

Contact::Contact(void) {
}

Contact::~Contact() {
}

void Contact::printModified(std::string &str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << std::setw(10) << str;
}

void Contact::printFormatted()
{
	std::cout << '|';
	std::cout << std::setw(10) << index;
	std::cout << '|';
	printModified(m_firstname);
	std::cout << '|';
	printModified(m_lastname);
	std::cout << '|';
	printModified(m_nickname);
	std::cout << '|' << '\n';
}

std::string Contact::getFirstName() const {
	return (m_firstname);
}

std::string Contact::getLastName() const {
	return (m_lastname);
}

std::string Contact::getNickname() const {
	return (m_nickname);
}

std::string Contact::getPhoneNumber() const {
	return (m_phone_number);
}

std::string Contact::getDarkestSecret() const {
	return (m_darkest_secret);
}

void Contact::setFirstName(const std::string &firstname) {
	m_firstname = firstname;
}

void Contact::setLastName(const std::string &lastname) {
	m_lastname = lastname;
}

void Contact::setNickname(const std::string &nickname) {
	m_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phone_number) {
	m_phone_number = phone_number;
}

void Contact::setDarkestSecret(const std::string &darkest_secret) {
	m_darkest_secret = darkest_secret;
}