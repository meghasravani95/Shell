#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int cmdexecute(char *arr);
void parsing(char *cmdtopar);

int main(int argc,char* argv[])
{
	 char cmd[513];
	 char *command;
	 int i=0;
    
    if(argc==3 || (argc==2 && strcmp(argv[1],"shell")==0))
    {
    	if(argv[2]==0 && strcmp(argv[1],"shell")==0)
		{
			//printf("interactive mode\n");
			while(1)
			{		
			start:
			printf("Prompt$:");
			fgets(cmd,513,stdin);
			//printf("%lu\n",strlen(cmd));
			if(strlen(cmd)>=512)
			{
				//printf("executed");
				fprintf(stderr,"cmd exceeded 512 characters\n");
				goto start;
			}
        	command=strtok(cmd,"\n");
        	//puts(command);
        	parsing(command);
			}
		}
		else
		{
			//printf("Batch file mode\n");
			int fd=open(argv[2],O_RDONLY);
			int bytecount,p=0,z;
			char *buf=(char *)malloc(100*sizeof(char));
			char *args[10]={0,0,0,0,0,0,0,0,0,0};
		

			if(fd < 0)
			{
           		fprintf(stderr,"Unable to open the file or file doesn't exist\n");
           		exit(0);
			}
			else
			{

          		bytecount=read(fd,buf,512);
          		//printf("%d\n",bytecount);
          		buf[bytecount]='\0';
          		//printf("%s\n",buf);

          		buf=strtok(buf,"\n");
	

				while(buf != 0)
				{
					args[p]=buf;
					//printf("execute:%s\n",args[p]);
				   	p++;
					buf=strtok(0,"\n");
				}
       			
       			for(z=0;z<p;z++)
       			{
                                printf("\nbatchfile Line:%s\n",args[z]);
       	 			parsing(args[z]);
       			}
			}
		}

    }
    else
    {
    	fprintf(stderr,"Incorrect number of arguments at command line or Incorrect format; usage: shell[batchfile]\n");
    	exit(0);
    }
	

	return 0;
}

int cmdexecute(char *arr)
{
	int l,n=0,status;
	 char *argv[10]={0,0,0,0,0,0,0,0,0,0};
	 pid_t pid;
	//puts(arr); 
	arr=strtok(arr," ");
	

	while(arr != 0)
	{
		argv[n]=arr;
		//printf("%s\n",argv[n]);
		n++;
		arr=strtok(0," ");
	}

            
	if(strcmp(argv[0], "quit")!=0)
		
		{
		  //printf("another loop\n");
			
			//int status;
			pid=fork();
			if (pid==-1)
			{
			  fprintf(stderr,"Failure of fork\n");
			} 
			else if(pid== 0)
			{
				// child process
				//printf("child process\n");
				execvp(argv[0],argv);	
				fprintf(stderr,"command doesn't exist\n");	
			}
		}
		return pid;
}

void parsing(char *cmdtopar)
{
     	 char *cmdargs[10]={0,0,0,0,0,0,0,0,0,0},*subcommand;
     	 int j=0,k=0,cid[5],m,count=0,flag;

        	subcommand=strtok(cmdtopar,";");
        	
        	while(subcommand != 0)
			{
                
				cmdargs[j]=subcommand;
				if(strcmp(cmdargs[j],"quit")==0)
					flag=1;
				//printf("%s\n",cmdargs[j]);
				j++;
				subcommand=strtok(0,";");
				count++;
			}
			//printf("%d\n",count);

			if(count==1)
			{
               cmdexecute(cmdargs[0]);
			}
            else
            {
            	 for(k=0;k<count;k++)
            	{
            		//printf("%s\n",cmdargs[k]);
            		cid[k]=cmdexecute(cmdargs[k]);	
            	}
            }

            for(m=0;m<count;m++)
            {
            	//printf("executed");
            	wait(&cid[m]);
            }
            if(flag==1)
            {
            	exit(0);
            }
}

