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

// ----------Constructors----------

Contact::Contact()
{
  this->first_name = "";
  this->last_name = "";
  this->nickname = "";
  this->darkest_secret = "";
  this->phone_number = "";
	this->index = 0;
  return ;
}

// ----------Setters----------

void  Contact::SetIndex(int index)
{
  this->index = index;
  return ;
}

void  Contact::SetFirstName(std::string first_name)
{
  this->first_name = first_name;
  return ;
}

void  Contact::SetLastName(std::string last_name)
{
  this->last_name = last_name;
  return ;
}

void  Contact::SetNickname(std::string nickname)
{
  this->nickname = nickname;
  return ;
}

void  Contact::SetPhoneNumber(std::string phone_number)
{
  this->phone_number = phone_number;
  return ;
}

void  Contact::SetDarkestSecret(std::string darkest_secret)
{
  this->darkest_secret = darkest_secret;
  return ;
}

// ----------Getters----------

const std::string& Contact::GetFirstName(void) const
{
  return (this->first_name);
}

const std::string& Contact::GetLastName(void) const
{
  return (this->last_name);
}

const std::string& Contact::GetNickname(void) const
{
  return (this->nickname);
}

const std::string& Contact::GetDarkestSecret(void) const
{
  return (this->darkest_secret);
}

const std::string& Contact::GetPhoneNumber(void) const
{
  return (this->phone_number);
}

const int& Contact::GetIndex(void) const
{
  return(this->index);
}
