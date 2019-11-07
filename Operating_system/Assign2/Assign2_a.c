#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>

/*
Write a C program using signal() system call to handle the reception of SIGINT
signal which allows to execute a designated (user) function. Here the function is
responsible for creating a child process by using fork() system call and then you
have to display the PROCESS ID and PARENT PROCESS ID from the parent
process as well as from the child process.
*/

int user_funct(int a)
{
	int child;
	child = fork();
	if(child == 0)
	{
		printf("\nChild pid: %d\n",getpid());
		printf("\nParent pid:%d\n",getppid());
		printf("\nSum is:%d\n",a);
	}
}

int main()
{
	while(1)
	{
		printf("\nWaiting for interrupt signal\n");
		//user_funct(2);
		signal(SIGINT,user_funct(2));
		//user_funct(2);
		sleep(1);
	}
}
