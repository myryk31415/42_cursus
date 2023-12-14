/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:53:38 by padam             #+#    #+#             */
/*   Updated: 2023/12/14 23:58:59 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

/**
* @brief Checks if a character is alphanumeric.
* @param c Character to test.
* @return 1 if the character is alphanumeric, 0 otherwise.
*/
int	ft_isalnum(int c);

/**
* @brief Checks if a character is alphabetic.
* @param c Character to test.
* @return 1 if the character is alphabetic, 0 otherwise.
*/
int	ft_isalpha(int c);

/**
* @brief Checks if a character is on the ASCII table.
* @param c Character to test.
* @return 1 if the character is on the ASCII table, 0 otherwise.
*/
int	ft_isascii(int c);

/**
* @brief Checks if a character is numeric.
* @param c Character to test.
* @return 1 if the character is numeric, 0 otherwise.
*/
int	ft_isdigit(int c);

/**
* @brief Checks if a character is printable.
* @param c Character to test.
* @return 1 if the character printable, 0 otherwise.
*/
int	ft_isprint(int c);

/**
* @brief Converts a character to lowercase.
* @param c Character to convert.
* @return lowercase character if alphabetical, otherwise the original character.
*/
int	ft_tolower(int c);

/**
* @brief Converts a character to uppercase.
* @param c Character to convert.
* @return uppercase character if alphabetical, otherwise the original character.
*/
int	ft_toupper(int c);

#endif
