#include "s_sh.h"
/**
 * main - this is a function
 *
 * Return: always 0
 */
int main(void)
{
	char command[UTTERMOST_LENGTH];
	/*char *argv[MAX_ARGS];*/
	size_t length;
	/*int num_args;*/

	while (1)
	{
		show();
		/*userintake(command, sizeof(command));*/
		
		
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

                if (feof(stdin))
                    {
                            printf("End of file reached.\n");
                            
                    }
                    else if (ferror(stdin))
                    {
                            perror("Error reading from stdin");
                    }              

            length = strlen(command);

            if (length > 0 && command[length - 1] == '\n')
            {
                    command[length - 1] = '\0';
            }
            if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0)
            {
                    printf("Exiting...\n");
                    break;
            }
            /*userintake(command, sizeof(command));*/
	   /* num_args = parse_command(command, argv);

        if (num_args > 0) 
	{
		process();
	}*/
	    process(command);
	}
	return (0);
}
