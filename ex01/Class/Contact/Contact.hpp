/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <joakoeni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:52:29 by joakoeni          #+#    #+#             */
/*   Updated: 2024/01/09 16:33:13 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
  private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string darkest_secret;
		std::string phone_number;
		int index;

	public:
		Contact(void);
    void SetFirstName(std::string first_name);
    void SetLastName(std::string last_name);
    void SetNickname(std::string nickname);
    void SetDarkestSecret(std::string darkest_secret);
    void SetPhoneNumber(std::string phone_number);
    void SetIndex(int index);
    const std::string& GetFirstName(void) const;
    const std::string& GetLastName(void) const;
    const std::string& GetNickname(void) const;
    const std::string& GetDarkestSecret(void) const;
    const std::string& GetPhoneNumber(void) const;
    const int& GetIndex(void) const;
};

#endif
