/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:04:22 by joakoeni          #+#    #+#             */
/*   Updated: 2024/01/18 10:41:37 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string	concat_to_upper(int argc, char **argv, std::string s)
{
	int i = 1;
	int j = 0;
	while(i != argc)
	{
		s += toupper(argv[i][j++]);
		if(argv[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	return (s);
}

int main(int argc, char **argv)
{
	std::string s;
	if(argc == 1)
		s = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		s = concat_to_upper(argc, argv, s);
	std :: cout << s << std :: endl;
	return 0;
}
