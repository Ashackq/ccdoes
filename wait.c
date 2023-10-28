#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>




int main()
{
	pid_t num_pid;
	num_pid=fork();
	if(num_pid<0)
		printf("Error in fork execution");
	else
		if(num_pid==0)
		{
			printf("This is the child process id %d\n",getpid());
			
		}
		else
		{	
			sleep(2);	
			system("ps aux")
        	printf("This is the parent process id %d\n",getpid());
				
			wait(NULL);
		}	
	return 0;
}
