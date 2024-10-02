/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:38:56 by atamas            #+#    #+#             */
/*   Updated: 2024/10/02 10:30:56 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	int			i;
	int			j;
	std::string	temp;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			temp = argv[i];
			while (temp[j])
			{
				temp[j] = toupper(temp[j]);
				j++;
			}
			std::cout << temp;
			i++;
		}
		std::cout << '\n';
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
}