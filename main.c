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
    char* arg_list[] = {"ls", "-l", "/", NULL};

    set_baseline("ls", arg_list);
    wait();
    return 0;
}
