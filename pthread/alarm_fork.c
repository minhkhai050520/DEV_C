#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int status;
    char line[128];
    int seconds;
    pid_t pid;
    char message[64];

    while(1)
    {
        printf("Alarm> ");
        if(fgets(line, sizeof(line), stdin) == NULL) exit(0);

        if(strlen(line) <= 1) continue;

        /*
        * Parse input line into seconds (%d) and a message
        * (%64[A\n]), consisting of up to 64 characters
        * separated from the seconds by whitespace.
        */

        if(sscanf(line, "%d %64[^\n]", &seconds, message) < 2)
        {
            fprintf(stderr, "Bad command\n");
        }
        else
        {
            pid = fork();
            if(pid == (pid_t)-1)
            {
                fprintf(stderr, "fork failed\n");
            }
            
            if(pid == (pid_t)0)
            {
                /*
                * In the child, wait and then print a message
                */
                sleep(seconds);
                printf("(%d) %s\n", seconds, message);
                exit(0);
            }
            else
            {
                /*
                * In the parent, call waitpid() to collect children
                * that have already terminated.
                */
               do{
                    pid = waitpid((pid_t)-1, NULL, WNOHANG);
                    if(pid == (pid_t)-1)
                        fprintf(stderr, "wait for child\n");
               }while(pid != (pid_t)0);
            }
        }
    }
    return 0;
}
