/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:16:22 by padam             #+#    #+#             */
/*   Updated: 2024/02/05 13:50:37 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <signal.h>
#include <unistd.h>

/**
 * @brief stops the programm cleanly
 * @param message the message to print before exiting
 */
static void	stop_client(char *message)
{
	ft_printf("%s\n", message);
	exit(0);
}

/**
 * @brief sends one char to the server via signals
 * @param c the char to send
 * @param pid the server's pid
 */
static void	send_char(char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(15);
		if (c & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				stop_client("Error: could not send signal");
		}
		else if (kill(pid, SIGUSR2) == -1)
			stop_client("Error: could not send signal");
		pause();
		c >>= 1;
		i++;
	}
}

static void	do_nothing(int signal)
{
	(void)signal;
}

static void	set_signal_action(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = do_nothing;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		stop_client("Error: could not set signal action");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		stop_client("Error: could not set signal action");
}

/**
 * @brief Sends a message to the server. Usage: ./client [server PID] [message]
 * @param pid the server's pid
 * @param message the message to send
 */
int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3 || ft_strlen(argv[1]) > 8 || !ft_isnumber(argv[1]))
		stop_client("Usage: ./client [server PID] [message]");
	set_signal_action();
	pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		send_char(*argv[2], pid);
		argv[2]++;
	}
	stop_client("Message sent");
	return (0);
}
