#include "s_sh.h"
/**
 * main - this is a function
 *
 * Return: always 0
 */

int main(void)
{
	char *userinput;
    if (setenv("TERM", "xterm", 1) == -1) {
        perror("Error setting TERM variable");
    }

    while (1) {
        show();
        userinput = my_getline(); /*Use my_getline() instead of fgets()*/

        if (userinput == NULL) {
            mr_putchar('\n');
            break;
        }

        if (strcmp(userinput, "exit") == 0 || strcmp(userinput, "quit") == 0) {
		free(userinput);
            shellexit();
            break;
        } else if (strcmp(userinput, "env") == 0) {
            printenv();
        } else {
            process(userinput);
        }

        free(userinput); /*Free dynamically allocated memory for the command*/
    }
    return 0;
}

/*int main(void)
{
	char userinput[UTTERMOST_LENGTH];
	size_t length;
	char *a = "shell closed.";

	if (setenv("TERM", "xterm", 1) == -1)
	{
		perror("Error setting TERM variable");
	}
	while (1)
	{
		show();
		if (fgets(userinput, sizeof(userinput), stdin) == NULL)
		{
			mr_putchar('\n');
			break;
		}
		length = strlen(userinput);
		if (length > 0 && userinput[length - 1] == '\n')
		{
			userinput[length - 1] = '\0';
		}
		if (strcmp(userinput, "exit") == 0 || strcmp(userinput, "quit") == 0)
		{
			shellexit();
			break;
		}
		else if (strcmp(userinput, "env") == 0)
		{
			printenv();
		}
		else
		{
			process(userinput);
		}
	}
	write(1, a, strlen(a));
	mr_putchar('\n');
	return (0);
}*/
