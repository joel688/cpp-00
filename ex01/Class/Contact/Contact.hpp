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
	public:
		Contact();
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string darkest_secret;
		std::string phone_number;
		int index;

		void display_info();
		void ft_add_contact();
		void ft_search_contact();
		void ft_show_all();
};

#endif
