/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:26:43 by joakoeni          #+#    #+#             */
/*   Updated: 2024/01/09 16:25:37 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define MAX_CONTACT 8

#include "../Contact/Contact.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>

class PhoneBook
{
  private:
    Contact contact_list[MAX_CONTACT];
    int num;
    int older;
    void  AddFirstName(Contact);
    void  AddLastName(Contact);
    void  AddNickname(Contact);
    void  AddDarkestSecret(Contact);
    void  AddPhoneNumber(Contact);
    void  SetContact(Contact);
    void  SetNum(void);
    void  SetOlder(void);
  public:
    PhoneBook(void);
    ~PhoneBook(void);
    void  PrintHelp(void);
    void  AddContact(void);
    void  DisplayInfo(void);
    void  DisplayContactInfo(int index);
    void  SearchContact(void);
    std::string TruncateString(const std::string& to_truncate);
};

    void  Execution(void);

#endif
