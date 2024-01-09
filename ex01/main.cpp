/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:04:21 by joakoeni          #+#    #+#             */
/*   Updated: 2024/01/09 16:11:02 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class/PhoneBook/Phonebook.hpp"

int main (void)
{
  PhoneBook PB;
  std::string  command;
  PB.num = 0;

  while(command != "EXIT")
  {
	std::cout << "Please type : ADD to add contact, SEARCH to search contact, SHALL to show all contact, and EXIT to exit" << std::endl;
    std::cin >>  command;

    if (command == "ADD")
	{

	}
    if (command == "SEARCH")
	{

	}
    if (command == "SHALL")
	{

	}
  }
}
