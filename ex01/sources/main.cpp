/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:04:21 by joakoeni          #+#    #+#             */
/*   Updated: 2024/01/09 11:12:28 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
      while(PB.num <= 8 && PB.nb_contact[PB.num].first_name != "NULL")
        PB.num++;
      PB.ft_add_contact();
      PB.num = 0;
    }
    if (command == "SEARCH")
      PB.ft_search_contact();
    if (command == "SHALL")
      PB.ft_show_all();
  }
}
