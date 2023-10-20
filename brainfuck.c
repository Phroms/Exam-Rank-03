/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:54:19 by agrimald          #+#    #+#             */
/*   Updated: 2023/10/19 22:03:57 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

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

	/*	Otro tipo de Main	*/

/*

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void ft_brainfuck(char *str);

int main() {
    char hello_world[] = "++++++++[>++++[>++>+++>+++>+<<<<-]>+.-.>++.+++.>++.<<-----.>+.>.+++.------.>-.>+.>.";

    printf("Brainfuck Program: %s\n", hello_world);
    printf("Expected Output: Hello, World!\n");

    // Create a pipe to capture the output of the brainfuck program
    int pipe_fd[2];
    pipe(pipe_fd);

    // Duplicate the standard output file descriptor
    int original_stdout = dup(STDOUT_FILENO);

    // Redirect standard output to the write end of the pipe
    dup2(pipe_fd[1], STDOUT_FILENO);

    // Close the read end of the pipe
    close(pipe_fd[0]);

    // Run the brainfuck program
    ft_brainfuck(hello_world);

    // Restore standard output
    dup2(original_stdout, STDOUT_FILENO);

    // Read the output from the pipe
    char output[100];
    read(pipe_fd[0], output, sizeof(output));

    // Null-terminate the output string
    output[strlen(output)] = '\0';

    // Close the write end of the pipe
    close(pipe_fd[1]);

    // Print the actual output
    printf("Actual Output: %s\n", output);

    // Compare the expected output with the actual output
    if (strcmp(output, "Hello, World!\n") == 0) {
        printf("Test Passed: Brainfuck program produced the expected output.\n");
    } else {
        printf("Test Failed: Brainfuck program did not produce the expected output.\n");
    }

    return 0;
}

*/
