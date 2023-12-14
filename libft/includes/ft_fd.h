/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:54:40 by padam             #+#    #+#             */
/*   Updated: 2023/12/14 23:55:54 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FD_H
# define FT_FD_H

/**
* @brief Prints a character to a file descriptor.
* @param c Character to print.
* @param fd File descriptor to print to.
*/
void	ft_putchar_fd(char c, int fd);

/**
* @brief Prints a character to file descriptor 1.
* @param c Character to print.
*/
void	ft_putchar(char c);

/**
* @brief Prints a string with a newline added to a file descriptor.
* @param s String to print.
* @param fd File descriptor to print to.
*/
void	ft_putendl_fd(char *s, int fd);

/**
* @brief Prints a string with a newline added to file descriptor 1.
* @param s String to print.
*/
void	ft_putendl(char *s);

/**
* @brief Prints a number to a file descriptor.
* @param n Number to print.
* @param fd File descriptor to print to.
*/
void	ft_putnbr_fd(int n, int fd);

/**
* @brief Prints a number to file descriptor 1.
* @param n Number to print.
*/
void	ft_putnbr(int n);

/**
* @brief Prints a string to a file descriptor.
* @param s String to print.
* @param fd File descriptor to print to.
*/
void	ft_putstr_fd(char *s, int fd);

/**
* @brief Prints a string to file descriptor 1.
* @param s String to print.
*/
void	ft_putstr(char *s);

#endif
