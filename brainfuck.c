/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:54:19 by agrimald          #+#    #+#             */
/*   Updated: 2023/10/17 22:01:56 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_brainfuck(char *str)
{
	char bytes[2048] = {0};
	char *ptr;
	int loop;

	ptr = bytes;
	loop = 0;
	while (*str)
	{
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			++(*ptr);
		else if (*str == '-')
			--(*ptr);
		else if (*str == '.' && *ptr != '\n')
			write(1, ptr, 1);
		else if (*str == '[' && *ptr == 0)
		{
			loop = 1;
			while (loop > 0)
			{
				str++;
				if (*str == '[')
					loop++;
				else if (*str == ']')
					loop--;
			}
		}
		else if (*str == ']' && *ptr != 0)
		{
			loop = 1;
			while (loop > 0)
			{
				str--;
				if (*str == ']')
					loop++;
				else if (*str == '[')
					loop--;
			}
		}
		str++;
	}
}
int main(int argc, char **argv)
{
	if (argc == 2)
		ft_brainfuck(argv[1]);
	write(1, "\n", 1);
	return (0);
}
