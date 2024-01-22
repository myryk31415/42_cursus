/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:15:29 by padam             #+#    #+#             */
/*   Updated: 2024/01/22 13:18:29 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <signal.h>
#include <unistd.h>
// #include <asm-generic/siginfo.h>
// #include <asm-generic/signal-defs.h>

/**
 * @brief stops the programm cleanly
 * @param message the message to print before exiting
 */
static void	stop_server(char *message)
{
	ft_printf("%s\n", message);
	exit(0);
}

/**
 * @brief decode the signal received and prints the char
 * @param signal the signal received
 * @param info the info about the signal
 * @param context the context of the signal
 */
static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char		c = 0;
	static int		i = 0;
	static pid_t	pid = 0;

	context = NULL;
	i++;
	if (signal == SIGUSR1)
		c |= 1 << (i - 1);
	else if (signal == SIGUSR2)
		c |= 0 << (i - 1);
	if (i == 8)
	{
		ft_putchar(c);
		c = 0;
		i = 0;
	}
	if (info->si_pid > 0)
		pid = info->si_pid;
	usleep(20);
	if (kill(pid, SIGUSR1) == -1)
		stop_server("Error: could not send signal to client");
}

/**
 * @brief sets the signal action for SIGUSR1 and SIGUSR2
 */
static void	set_signal_action(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		stop_server("Error: could not set signal action");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		stop_server("Error: could not set signal action");
}

/**
 * @brief server prints the message it receives via signals
 */
int	main(void)
{
	int	i;

	i = 0;
	ft_printf("%d\n", getpid());
	set_signal_action();
	while (i == 0)
		i = 0;
	return (0);
}
