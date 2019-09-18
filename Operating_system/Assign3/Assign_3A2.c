#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void interrupt_fun(int mypipfd,int pid,char buffer)
{
	if(pid == 0)
	{
		//Child Process
	int t1=0,t2=0,t3=1;

	close(mypipfd[0]); //Close reading mode
	//Fibonacci series
	for(int i=0; i <= input;i++)
		{
		t1 = t2;
		t2 = t3;
		t3 = t1 + t2;
		sprintf(buffer,"%d",t3);

		write(mypipfd[1],buffer,sizeof(buffer)+1);
		printf("\nchild write: %d\n",t3);
		sleep(2);
		}
	
	}
	else
	{
		//Parent Process
		close(mypipfd[1]);
		for(int j = 0; j<= input;j++)
		{
			read(mypipfd[0],buffer,sizeof(buffer)+1);
			sscanf(buffer,"%d",&t3);
			printf("\nParent Read%d\n",t3 );
		}
	}
}
int main()
{
	pid_t pid;
	int mypipfd[2];// mypipfd[0]: Reading
	int ret;	   // mypipfd[1]: Writing
	char buffer[200];
	int input,t3;

	ret = pipe(mypipfd);
	if(ret == -1)
	{
		perror("\n[-]Pipe Error\n");
		exit(1);
	}
	printf("\nEnter number to generate fibonacci series:");
	scanf("%d",&input);
	pid=fork();
	

	interrupt_fun(mypipfd,pid,buffer);
	//================================
	/*
	if(pid == 0)
	{
		//Child Process
	int t1=0,t2=0,t3=1;
	close(mypipfd[0]); //Close reading mode
	//Fibonacci series
	for(int i=0; i <= input;i++)
		{
		t1 = t2;
		t2 = t3;
		t3 = t1 + t2;
		sprintf(buffer,"%d",t3);

		write(mypipfd[1],buffer,sizeof(buffer)+1);
		printf("\nchild write: %d\n",t3);
		sleep(2);
		}
	
	}
	else
	{
		//Parent Process
		close(mypipfd[1]);
		for(int j = 0; j<= input;j++)
		{
			read(mypipfd[0],buffer,sizeof(buffer)+1);
			sscanf(buffer,"%d",&t3);
			printf("\nParent Read%d\n",t3 );
		}
	}

	*/
	//========================
	return 0;
}