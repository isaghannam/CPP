/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:04:44 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/30 15:50:03 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename InputIterator>
void Span::addNumbers(InputIterator start, InputIterator finish)
{
    if ((_maxSize - static_cast<unsigned int>(_numbers.size())) < std::distance(start, finish))
        throw Span::TooManyNumbersException();
    _numbers.insert(_numbers.end(), start, finish);
};