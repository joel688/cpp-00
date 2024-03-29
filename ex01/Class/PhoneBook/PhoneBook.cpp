/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:42:36 by joakoeni          #+#    #+#             */
/*   Updated: 2024/01/19 17:43:50 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// ----------Constructors----------

PhoneBook::PhoneBook()
{
  this->num = 0;
  this->older = 0;
  return ;
}

// ----------Destructors----------

PhoneBook::~PhoneBook()
{
  std::cout << "PhoneBook ended" << std::endl;
}

// ----------Setters----------

void  PhoneBook::SetContact(Contact new_contact)
{
  new_contact.SetIndex(this->num);
  if(this->num <= MAX_CONTACT)
    this->contact_list[this->num++] = new_contact;
  else
  {
    if(this->older <= MAX_CONTACT)
      this->contact_list[this->older++] = new_contact;
    else
    {
      this->SetOlder();
      this->contact_list[this->older++] = new_contact;
    }
  }
  if(this->num >= MAX_CONTACT)
    this->SetNum();
  return ;
}

void  PhoneBook::SetNum()
{
  this->num = 0;
  return ;
}

void  PhoneBook::SetOlder()
{
  this->older = 0;
  return ;
}

// -----------Members Functions----------

void  PhoneBook::PrintHelp()
{
  std::cout << "Type ADD    to Add a contact." << std::endl;
  std::cout << "Type SEARCH to Search a contact." << std::endl;
  std::cout << "Type EXIT   to Exit the phonebook." << std::endl;
  return ;
}

void  PhoneBook::AddContact(void)
{
  Contact new_contact;

  std::system("clear");
  std::cout << "You choose to add contact. Remember, your phonebook can't contain more than 8 contacts, and will replace the older contact you have when it is full."<< std::endl;
  this->AddFirstName(new_contact);
  if(std::cin.eof())
    return;
  std::cout << "Contact added successfully! (great sucessssss)" << std::endl;
  return ;
}

void PhoneBook::AddFirstName(Contact new_contact)
{
  std::string input;

  std::system("clear");
  while (input == "")
  {
    std::system("clear");
    std::cout << "Enter new contact first name: " << std::endl;
    std::getline(std::cin, input);
    if(std::cin.eof())
      return;
  }
  new_contact.SetFirstName(input);
  this->AddLastName(new_contact);
  return ;
}

void PhoneBook::AddLastName(Contact new_contact)
{
  std::string input;

  std::system("clear");
  while (input == "")
  {
    std::system("clear");
    std::cout << "Enter new contact last name: " << std::endl;
    std::getline(std::cin, input);
    if(std::cin.eof())
      return;
  }
  new_contact.SetLastName(input);
  this->AddNickname(new_contact);
  return ;
}

void PhoneBook::AddNickname(Contact new_contact)
{
  std::string input;

  std::system("clear");
  while (input == "")
  {
    std::system("clear");
    std::cout << "Enter new contact nickname: " << std::endl;
    std::getline(std::cin, input);
    if(std::cin.eof())
      return;
  }
  new_contact.SetNickname(input);
  this->AddDarkestSecret(new_contact);
  return ;
}

void PhoneBook::AddDarkestSecret(Contact new_contact)
{
  std::string input;

  std::system("clear");
  while (input == "")
  {
    std::system("clear");
    std::cout << "Enter new contact darkest secret: " << std::endl;
    std::getline(std::cin, input);
    if(std::cin.eof())
      return;
  }
  new_contact.SetDarkestSecret(input);
  this->AddPhoneNumber(new_contact);
  return ;
}

void PhoneBook::AddPhoneNumber(Contact new_contact)
{
  std::string input;

  std::system("clear");
  while (input == "")
  {
    std::system("clear");
    std::cout << "Enter new contact phone number: " << std::endl;
    std::getline(std::cin, input);
    if(std::cin.eof())
      return;
  }
  new_contact.SetPhoneNumber(input);
  this->SetContact(new_contact);
  std::system("clear");
  return ;
}

void PhoneBook::SearchContact(void)
{
  int index_to_search;
  if(contact_list[0].GetFirstName() == "")
  {
    std::cout << "The phonebook is empty." << std::endl;
    return;
  }
  this->DisplayInfo();
  std::cout << "You want to search a contact, give me a index between 0 and 7." << std::endl;
  while(!(std::cin >> index_to_search) || index_to_search < 0 || index_to_search > 7)
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Index out of range u stupid... Send an index between 0 and 7." << std::endl;
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if(index_to_search <= (MAX_CONTACT - 1) && contact_list[index_to_search].GetFirstName() == "")
  {
    std::system("clear");
		std::cout << "No contact at this index." << std::endl;
    return ;
  }
  this->DisplayContactInfo(index_to_search);
	if(std::cin.eof())
		return;
  return ;
}

void  PhoneBook::DisplayInfo(void)
{
  int i = 0;
  while(this->contact_list[i].GetFirstName() != "" && i <= (MAX_CONTACT - 1))
  {
    std::cout << std::setw(10) << this->contact_list[i].GetIndex() << "|";
    std::cout << std::setw(10) << TruncateString(this->contact_list[i].GetFirstName()) << "|";
    std::cout << std::setw(10) << TruncateString(this->contact_list[i].GetLastName()) << "|";
    std::cout << std::setw(10) << TruncateString(this->contact_list[i].GetNickname()) << "|";
    std::cout << std::endl;
    i++;
  }
  return ;
}

void  PhoneBook::DisplayContactInfo(int index)
{
  std::system("clear");
  std::cout << this->contact_list[index].GetIndex() << std::endl;
  std::cout << this->contact_list[index].GetFirstName() << std::endl;
  std::cout << this->contact_list[index].GetLastName() << std::endl;
  std::cout << this->contact_list[index].GetNickname() << std::endl;
  std::cout << this->contact_list[index].GetDarkestSecret() << std::endl;
  std::cout << this->contact_list[index].GetPhoneNumber() << std::endl;
  return ;
}

std::string  PhoneBook::TruncateString(const std::string& to_truncate)
{
  if (to_truncate.length() > 10)
    return (to_truncate.substr(0, 10 - 1) + ".");
  return (to_truncate);
}

// ----------Non Members Functions----------

void  Execution(void)
{
  std::string  command;
  PhoneBook PB;
  while(command != "EXIT")
  {
    command = "";
    PB.PrintHelp();
    std::getline(std::cin, command);
    if (command == "ADD")
    {
      std::system("clear");
      PB.AddContact();
    }
    if (command == "SEARCH")
	  {
      std::system("clear");
      PB.SearchContact();
	  }
	if(std::cin.eof())
		return;
  }
  return ;
}
