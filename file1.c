#include "s_sh.h"
/**
 * show - this is a function to display prompt
 *
 * Return: 0
 */
void show(void)
{
	char *shellname = "MOH & SHAMS> ";

	write(1, shellname, strlen(shellname));
}

/**
 * userintake - this function takes in user input
 * @command: parameter
 * Return: always 0
 */
/*void userintake(char *command)
*/
	/*command[UTTERMOST_LENGTH];*/

	/*size_t length;

	length = strlen(command);
	
	if (fgets(command, UTTERMOST_LENGTH, stdin) != NULL)
        {
                return;
        }
        else
        {
                if (feof(stdin))
                {
                        printf("End of file reached.\n");
                }
                else if (ferror(stdin))
                {
                        perror("Error reading from stdin");
                }
        }
	if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		if (command[length - 1] == '\n')
		{
			command[length - 1] = '\0';
		}
		if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0)
		{
			;
		}
		break;
}*/
void userintake(char *command)
{
	size_t length;
	while (1)
	{
	    if (fgets(command, sizeof(command), stdin) == NULL)
	    {
            /* Handle end-of-file or error*/
		    if (feof(stdin))
		    {
			    printf("End of file reached.\n");
		    }
		    else if (ferror(stdin))
		    {
			    perror("Error reading from stdin");
		    }
		    break;  /*Exit the loop on EOF or error*/
	    }
	    
	    length = strlen(command);
	    
	    if (length > 0 && command[length - 1] == '\n')
	    {
		    command[length - 1] = '\0';
	    }
	    if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0)
	    {
		    printf("Exiting...\n");
		    break;  /* Exit the loop if the user enters "exit" or "quit"*/
	    }

        /* Process the character*/
	    printf("You entered: %s\n", command);
    }
}
