/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:56:29 by atamas            #+#    #+#             */
/*   Updated: 2024/10/11 18:09:40 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_CLASS_HPP
#define CONTACTS_CLASS_HPP

#include <iostream>

class Contact
{
	private:
		std::string		m_firstname;
		std::string		m_lastname;
		std::string		m_nickname;
		std::string		m_phone_number;
		std::string		m_darkest_secret;
	public:
		Contact(void);
		~Contact();
		std::string		getFirstName() const;
		std::string		getLastName() const;
		std::string		getNickname() const;
		std::string		getPhoneNumber() const;
		std::string		getDarkestSecret() const;
		int				id;

		void setFirstName(const std::string &firstname);
		void setLastName(const std::string &lastname);
		void setNickname(const std::string &nickname);
		void setPhoneNumber(const std::string &phone_number);
		void setDarkestSecret(const std::string &darkest_secret);
};

#endif