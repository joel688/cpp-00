#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <iomanip>

class Contact
{
    public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string darkest_secret;
    std::string phone_number;

    Contact()
    {
      first_name = "NULL";
      last_name = "NULL";
      nickname = "NULL";
      darkest_secret = "NULL";
      phone_number = "NULL";
    }

    void  display_info()
    {
      std::cout << std::setw(10) << first_name << "|";
      std::cout << std::setw(10) << last_name << "|";
      std::cout << std::setw(10) << nickname << "|";
      std::cout << std::setw(10) << darkest_secret << "|";
      std::cout << std::setw(10) << phone_number << std::endl;
    }
};

class PhoneBook
{
    public:
    Contact nb_contact[8];
    int num;

    void  ft_add_contact()
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
      }
      else
      {
        std::cout << "Enter new contact first name: " << std::endl;
        std::cin >> nb_contact[0].first_name;
        std::cout << "Enter new contact last name: " << std::endl;
        std::cin >> nb_contact[0].last_name;
		std::cout << "Enter new contact nickname: " << std::endl;
        std::cin >> nb_contact[0].nickname;
		std::cout << "Enter new contact darkest secret: " << std::endl;
        std::cin >> nb_contact[0].darkest_secret;
		std::cout << "Enter new contact number: " << std::endl;
        std::cin >> nb_contact[0].phone_number;
      }
      std::cout << "Contact added successfully" << std::endl;
      num = 0;
    }

    void  ft_search_contact()
    {
      system("clear");
      std::string to_search;
      if(nb_contact[0].first_name == "NULL")
        std::cout << "The phonebook is empty." << std::endl;
      else
      {
        std::cout << "You want to search a contact, give me a name." << std::endl;
        std::cin >> to_search;
        while(num <= 7 && (nb_contact[num].first_name != to_search || nb_contact[num].last_name != to_search))
          num++;
        system("clear");
        nb_contact[num].display_info();
      }
      num = 0;
    }
    
    void  ft_show_all()
    {
      system("clear");
      while(num <= 7)
      {
        if(nb_contact[num].first_name != "NULL")
          nb_contact[num].display_info();
        num++;
      }
    }
};

#endif
