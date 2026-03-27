/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:10:54 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/26 17:03:53 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
private:
    T* elements;
    unsigned int length;
public:
    Array(): elements(new T[0]), length(0){};
    Array(unsigned int n): elements(new T[n]), length(n){};
    Array(const Array<T> & other): elements(new T[other.size()]), length(other.size())
    {
        for (unsigned int i = 0; i < other.size(); i++)
            this->elements[i] = other[i];
    };
    Array& operator=(const Array<T> & other)
    {
        if (this != &other)
        {
            delete [] this->elements;
            this->elements = new T[other.size()];
            for (unsigned int i = 0; i < other.size(); i++)
                this->elements[i] = other[i];
            this->length = other.size();
        }
        return *this;
    };
    class IndexOutOfBoundsException: public std::exception
    {
        public:
            const char *what() const throw()
            {
                return ("Error in []! Index out of bounds!");
            };
    };
    T& operator[](unsigned int n)
    {
        if (n >= length)
            throw IndexOutOfBoundsException();
        return elements[n];
    };
    const T& operator[](const unsigned int n) const
    {
        if (n >= length)
            throw IndexOutOfBoundsException();
        return elements[n];
    };
    unsigned int size() const { return length; };
    ~Array(){ delete [] elements; };
};

template<typename T>
std::ostream & operator<<(std::ostream &os, const Array<T> &array)
{
    for (unsigned int i = 0; i < array.size(); i++)
        os << array[i] << "  ";
    return os;
};


#endif