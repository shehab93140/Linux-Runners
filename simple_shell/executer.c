#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
char buf[100];
char *cmd[20];
char first_command[20];
int main()
{
	while (1)
	{
		printf("Ana Gahz Ya Basha >> ");
		fflush(stdin);
		fgets(buf, 100, stdin);
		int len = strlen(buf);
		buf[len - 1] = 0;
		char *args = strtok(buf, " ");
		strcpy(first_command, args);
		char i = 0;
		while (args != NULL)
		{
			cmd[i] = args;
			args = strtok(NULL, " ");
			i++;
		}
		if (strlen(buf) == 0)
		{
			continue;
		}
		int ret_pid = fork();
		if (ret_pid < 0)
			printf("Fork Failed \n");
		else if (ret_pid > 0)
		{
			int status;
			wait(&status);
			// printf("The last commad exit status = %d\n",WEXITSTATUS(status));
		}
		else if (ret_pid == 0)
		{
			char *envp[] = {NULL};
			char *argv[] = {"", NULL};
			if (buf == "clear")
				system("clear");
			execvp(first_command, cmd); /// the first arg , the full command
			printf("exec is failed \n");
			return -1;
		}
	}

	return 0;
}