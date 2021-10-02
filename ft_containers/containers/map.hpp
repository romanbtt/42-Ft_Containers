/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:43:45 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/02 11:55:56 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

# include <memory>
#include <map>
# include "../utils/less.hpp"

namespace ft
{
	std::map<int, int> test;
	template <class Key, class T, class Compare = ft::less<Key>, class Allloc = std::allocator<ft::pair<const Key, T>
} // namespace ft

#endif
