/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:04:21 by joakoeni          #+#    #+#             */
/*   Updated: 2024/01/03 14:22:34 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main (void)
{
  PhoneBook PB;
  std::string  command;
  PB.num = 0;

  while(command != "4")
  {
		std::cout << "Please type : 1 to add contact, 2 to search contact, 3 to show all contact, and 4 to exit" << std::endl;
    std::cin >>  command;

    if (command == "1")
    {
      while(PB.num <= 8 && PB.nb_contact[PB.num].name != "NULL")
        PB.num++;
      PB.ft_add_contact();
      PB.num = 0;
    }
    if (command == "2")
      PB.ft_search_contact();
    if (command == "3")
      PB.ft_show_all();
  }
}
