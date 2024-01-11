#include "PhoneBook.hpp"

// ----------Constructors----------

PhoneBook::PhoneBook()
{
  this->num = 0;
  this->older = 0;
  this->Execution();
  return ;
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

// -----------Utils----------

void  PhoneBook::PrintHelp()
{
  std::cout << "Type ADD    to Add a contact." << std::endl;
  std::cout << "Type SEARCH to Search a contact." << std::endl;
  std::cout << "Type Exit   to Exit the phonebook." << std::endl;
  return ;
}

void  PhoneBook::AddContact(void)
{
  Contact new_contact;

  std::system("clear");
  std::cout << "You choose to add contact. Remember, your phonebook can't contain more than 8 contacts, and will replace the older contact you have when it is full."<< std::endl;
  this->AddFirstName(new_contact);
	std::cout << "Contact added successfully! (great sucessssss)" << std::endl;
  return ;
}

void PhoneBook::AddFirstName(Contact new_contact)
{
  std::string input;

  std::system("clear");
  std::cout << "Enter new contact first name: " << std::endl;
  std::getline(std::cin, input);
  if(input == "")
    this->AddFirstName(new_contact);
  else
    new_contact.SetFirstName(input);
  this->AddLastName(new_contact);
  return ;
}

void PhoneBook::AddLastName(Contact new_contact)
{
  std::string input;

  std::system("clear");
  std::cout << "Enter new contact last name: " << std::endl;
  std::getline(std::cin, input);
  if(input == "")
    this->AddLastName(new_contact);
  else
    new_contact.SetLastName(input);
  this->AddNickname(new_contact);
  return ;
}

void PhoneBook::AddNickname(Contact new_contact)
{
  std::string input;

  std::system("clear");
  std::cout << "Enter new contact nickname: " << std::endl;
  std::getline(std::cin, input);
  if(input == "")
    this->AddNickname(new_contact);
  else
    new_contact.SetNickname(input);
  this->AddDarkestSecret(new_contact);
  return ;
}

void PhoneBook::AddDarkestSecret(Contact new_contact)
{
  std::string input;

  std::system("clear");
  std::cout << "Enter new contact darkest secret: " << std::endl;
  std::getline(std::cin, input);
  if(input == "")
    this->AddDarkestSecret(new_contact);
  else
    new_contact.SetDarkestSecret(input);
  this->AddPhoneNumber(new_contact);
  return ;
}

void PhoneBook::AddPhoneNumber(Contact new_contact)
{
  std::string input;

  std::system("clear");
  std::cout << "Enter new contact phone number: " << std::endl;
  std::getline(std::cin, input);
  if(input == "")
    this->AddPhoneNumber(new_contact);
  else
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
    std::system("clear");
    std::cout << "Index out of range u stupid..." << std::endl;
    this->SearchContact();
  }
  if(index_to_search <= (MAX_CONTACT - 1) && contact_list[index_to_search].GetFirstName() == "")
  {
    std::system("clear");
		std::cout << "No contact at this index." << std::endl;
    this->SearchContact();
  }
  this->DisplayContactInfo(index_to_search);
  printf("lol\n");
  return ;
}

void  PhoneBook::DisplayInfo(void)
{
  int i = 0;
  while(this->contact_list[i].GetFirstName() != "" && i <= (MAX_CONTACT - 1))
  {
    std::cout << std::setw(10) << this->contact_list[i].GetIndex() << "|";
    if(this->contact_list[i].GetFirstName().length() <= 10)
      std::cout << std::setw(10) << this->contact_list[i].GetFirstName() << "|";
    else
      std::cout << std::setw(9) << this->contact_list[i].GetFirstName() << ".|";
    if(contact_list[i].GetLastName().length() <= 10)
      std::cout << std::setw(10) << this->contact_list[i].GetLastName() << "|";
    else
      std::cout << std::setw(9) << this->contact_list[i].GetLastName() << ".|";
    if(this->contact_list[i].GetNickname().length() <= 10)
      std::cout << std::setw(10) << this->contact_list[i].GetNickname() << "|";
    else
      std::cout << std::setw(9) << this->contact_list[i].GetNickname() << ".|";
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

void  PhoneBook::Execution(void)
{
  std::string  command;
  while(command != "EXIT")
  {
	  std::cout << "Please type : ADD to add contact, SEARCH to search contact, and EXIT to exit" << std::endl;
    std::getline(std::cin, command);
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
  return ;
}
