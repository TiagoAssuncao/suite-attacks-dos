#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

int set_baseline(char* program, char** arg_list)
{
    pid_t child_pid;
    child_pid = fork ();
    if (child_pid != 0){
        sleep(5);
        kill(child_pid, SIGTERM);
        return child_pid;
    }
    else {
        execvp (program, arg_list);
        fprintf (stderr, "an error occurred in execvp\n");
        abort ();
    }
}

int main(int argc, const char *argv[])
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    strcat(cwd, "/loic");

    char* arg_list[] = {cwd, "162.243.111.72", "-r", "100", NULL};

    printf("Setting baseline\n");
    set_baseline(cwd, arg_list);
    return 0;
}
