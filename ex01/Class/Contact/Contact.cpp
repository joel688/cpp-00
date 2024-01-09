/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:29:41 by joakoeni          #+#    #+#             */
/*   Updated: 2024/01/09 16:47:28 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
    {
      first_name = "NULL";
      last_name = "NULL";
      nickname = "NULL";
      darkest_secret = "NULL";
      phone_number = "NULL";
	  index = 0;
    }

void Contact::display_info()
    {
		std::cout << std::setw(10) << index << "|";
		if(first_name.length() <= 10)
			std::cout << std::setw(10) << first_name << "|";
		else
			std::cout << std::setw(9) << first_name << ".|";
		if(last_name.length() <= 10)
			std::cout << std::setw(10) << last_name << "|";
		else
			std::cout << std::setw(9) << last_name << ".|";
		if(nickname.length() <= 10)
			std::cout << std::setw(10) << nickname << "|";
		else
			std::cout << std::setw(9) << nickname << ".|";
		if(phone_number.length() <= 10)
			std::cout << std::setw(10) << phone_number << std::endl;
		else
			std::cout << std::setw(9) << phone_number << ".|";
    }

void Contact::ft_add_contact()
{
	system("clear");
    std::cout << "You choose to add contact. Remember, your phonebook can't contain more than 8 contacts, and will replace the older contact you have when it is full."<< std::endl;

    if(num <= 7)
    {
		std::cout << "Enter new contact first name: " << std::endl;
        std::cin >> nb_contact[num].first_name;
        std::cout << "Enter new contact last name: " << std::endl;
        std::cin >> nb_contact[num].last_name;
        std::cout << "Enter new contact nickname: " << std::endl;
        std::cin >> nb_contact[num].nickname;
		std::cout << "Enter new contact darkest secret: " << std::endl;
        std::cin >> nb_contact[num].darkest_secret;
		std::cout << "Enter new contact number: " << std::endl;
        std::cin >> nb_contact[num].phone_number;
		nb_contact[num].index = num;
    }
	else
    {
			//remplacer plus vieux
    }
	std::cout << "Contact added successfully! (great sucessssss)" << std::endl;
	num = 0;
}

void Contact::ft_search_contact()
{
	system("clear");
    std::string to_search;
    if(nb_contact[0].first_name == "NULL")
		std::cout << "The phonebook is empty." << std::endl;
    else
    {
		while(num <= 7)
			nb_contact[num++].display_info();
        std::cout << "You want to search a contact, give me a index." << std::endl;
        std::cin >> to_search;
        while(num <= 7 && (nb_contact[num].first_name != to_search || nb_contact[num].last_name != to_search))
          num++;
        system("clear");
        nb_contact[num].display_info();
    }
    num = 0;
}

void Contact::ft_show_all()
{
	system("clear");
	while(num <= 7)
	{
		if(nb_contact[num].first_name != "NULL")
			nb_contact[num].display_info();
        num++;
    }
}
