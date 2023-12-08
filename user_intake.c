#include "s_sh.h"
/**
 * userintake - this function takes in user input
 * @command: parameter
 * Return: always 0
 */

void userintake(char *command, size_t bufsize)
{
	size_t length;
	
	if (fgets(command, bufsize, stdin) == NULL)
	{
		printf("\n");
		return;

            	if (feof(stdin))
		    {
			    printf("End of file reached.\n");
			    return;
		    }
		    else if (ferror(stdin))
		    {
			    perror("Error reading from stdin");
			    return;
		    }
		    else
		    {
			    printf("unknown command error\n");
			    return;
		    }
		    return;
	    }
	    
	    length = strlen(command);
	    
	    if (length > 0 && command[length - 1] == '\n')
	    {
		    command[length - 1] = '\0';
	    }
	    if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0)
	    {
		    printf("Exiting...\n");
		    return;
	    }
	    /*userintake(command, sizeof(command));*/
}
