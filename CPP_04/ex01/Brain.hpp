/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:50:09 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/16 15:46:26 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
using std::cout;

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(std::string idea);
        ~Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        const std::string *get_ideas() const;
        const std::string get_idea(int i) const;
        void set_idea(int i, const std::string& idea);
};


#endif