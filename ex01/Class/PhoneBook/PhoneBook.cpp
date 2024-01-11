#include "PhoneBook.hpp"

// ----------Constructors----------

PhoneBook::PhoneBook()
{
  this->num = 0;
  this->older = 0;
  Execution();
}

// ----------Setters----------

void  PhoneBook::SetContact(Contact new_contact)
{
  new_contact.SetIndex(num);
  if(num <= 8)
    contact_list[num++] = new_contact;
  else
  {
    if(older <= 8)
      contact_list[older++] = new_contact;
    else
    {
      SetOlder();
      contact_list[older++] = new_contact;
    }
  }
  if(num >= 8)
    SetNum();
	std::cout << "Contact added successfully! (great sucessssss)" << std::endl;
}

void  PhoneBook::SetNum()
{
  this->num = 0;
}

void  PhoneBook::SetOlder()
{
  this->older = 0;
}

// -----------Utils----------

void  PhoneBook::PrintHelp()
{
  std::cout << "Type ADD    to Add a contact." << std::endl;
  std::cout << "Type SEARCH to Search a contact." << std::endl;
  std::cout << "Type Exit   to Exit the phonebook." << std::endl;
}

void  PhoneBook::AddContact(void)
{
  Contact new_contact;
  std::string input;

  std::system("clear");
  std::cout << "You choose to add contact. Remember, your phonebook can't contain more than 8 contacts, and will replace the older contact you have when it is full."<< std::endl;
  
  std::cout << "Enter new contact first name: " << std::endl;
  std::cin >> input;
  new_contact.SetFirstName(input);
  std::cout << "Enter new contact last name: " << std::endl;
  std::cin >> input;
  new_contact.SetLastName(input);
  std::cout << "Enter new contact nickname: " << std::endl;
  std::cin >> input;
    new_contact.SetNickname(input);
	std::cout << "Enter new contact darkest secret: " << std::endl;
  std::cin >> input;
    new_contact.SetDarkestSecret(input);
	std::cout << "Enter new contact number: " << std::endl;
  std::cin >> input;
  new_contact.SetPhoneNumber(input);
  SetContact(new_contact);
}

void PhoneBook::SearchContact(void)
{
  int index_to_search;
  if(contact_list[0].GetFirstName() == "")
  {
    std::cout << "The phonebook is empty." << std::endl;
    return;
  }
  DisplayInfo();
  std::cout << "You want to search a contact, give me a index between 0 and 7." << std::endl;
  while(!(std::cin >> index_to_search) || index_to_search < 0 || index_to_search > 7)
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::system("clear");
    std::cout << "Index out of range u stupid..." << std::endl;
    SearchContact();
  }
  if(index_to_search <= 7 && contact_list[index_to_search].GetFirstName() == "")
  {
    std::system("clear");
		std::cout << "No contact at this index." << std::endl;
    SearchContact();
  }
  DisplayContactInfo(index_to_search);
}

void  PhoneBook::DisplayInfo(void)
{
  int i = 0;
  while(contact_list[i].GetFirstName() != "" && i <= 7)
  {
    std::cout << std::setw(10) << contact_list[i].GetIndex() << "|";
    if(contact_list[i].GetFirstName().length() <= 10)
      std::cout << std::setw(10) << contact_list[i].GetFirstName() << "|";
    else
      std::cout << std::setw(9) << contact_list[i].GetFirstName() << ".|";
    if(contact_list[i].GetLastName().length() <= 10)
      std::cout << std::setw(10) << contact_list[i].GetLastName() << "|";
    else
      std::cout << std::setw(9) << contact_list[i].GetLastName() << ".|";
    if(contact_list[i].GetNickname().length() <= 10)
      std::cout << std::setw(10) << contact_list[i].GetNickname() << "|";
    else
      std::cout << std::setw(9) << contact_list[i].GetNickname() << ".|";
    std::cout << std::endl;
    i++;
  }
}

void  PhoneBook::DisplayContactInfo(int index)
{
  std::system("clear");
  std::cout << contact_list[index].GetIndex() << std::endl;
  std::cout << contact_list[index].GetFirstName() << std::endl;
  std::cout << contact_list[index].GetLastName() << std::endl;
  std::cout << contact_list[index].GetNickname() << std::endl;
  std::cout << contact_list[index].GetDarkestSecret() << std::endl;
  std::cout << contact_list[index].GetPhoneNumber() << std::endl;
}

void  PhoneBook::Execution(void)
{
  std::string  command;
  while(command != "EXIT")
  {
	  std::cout << "Please type : ADD to add contact, SEARCH to search contact, and EXIT to exit" << std::endl;
    std::cin >>  command;
    if (command == "ADD")
    {
      std::system("clear");
      this->AddContact();
    }
    if (command == "SEARCH")
	  {
      std::system("clear");
      this->SearchContact();
	  }
  }
}
