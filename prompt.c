#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
char arg[1024]={};
void prompt(char *arg)
{
    char path[1024],homedir[1024];
    getcwd(path,1024);
    printf("%s\n",path);
    strcpy(homedir,arg);
    if(strcmp(path,homedir) == 0)
    {
        printf("<%s@%s:~>",getenv("USER"),getenv("HOSTNAME"));
    }
    else
    {
        strcat(homedir,"/%[^\n]");
        char arr[1024] = {0};
        sscanf(path,homedir,arr);
        printf("<%s@%s:~/%s>",getenv("USER"),getenv("HOSTNAME"),arr);
    }
}
void handle_signal(int signo)
{
    printf("\n");
    prompt(arg);
    fflush(stdout);
}
void ex()
{
}
int main(int argc, char *argv[])
{
    signal(SIGTSTP, SIG_IGN);
    signal(SIGINT,  handle_signal);
    char command[1024];
    char dir[1024];
    getcwd(arg,1024);
    prompt(arg);
    while(scanf("%[^\n]",command) != EOF) 
    {
        getchar();
        int i=0,j=0;
        char **td=NULL;
        td = calloc(1024,sizeof(char*));
        char* token=strtok(command," \t");
        while(token != NULL)
        {
            td[i] = calloc(1024,sizeof(char));
            strcpy(td[i],token);
            token = strtok(NULL," \t");
            i++;
        }
        if(strcmp(*td,"pid")==0)
        {
            printf("command name: %s process id:%ld\n",argv[0],getpid());
            fflush(stdout);
        }
        else if(strcmp(*td,"cd")==0)
        {
            chdir(td[1]);
            printf("%s\n",get_current_dir_name());
        }
        else
        {
            td[i] = NULL;
            pid_t pid;
            pid=fork();
            if(pid==0)
            {
                if(execvp(td[0],td) != 0)
                {
                    // Print error based on errno, include errno.h
                    exit(errno);
                }
            }
            else
            {
                wait();
            }
            // Don't forget to free as it will cause memory leaks which can
            // in turn cause problems in long runs
            for(j = 0;j < i;j++)
            {
                free(td[i]);
            }
            free(td);
        }
        prompt(arg);
    }

    printf("\n");

    return 0;
}
