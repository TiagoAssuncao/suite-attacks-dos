#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>

int set_baseline(char* program, char** arg_list)
{
    pid_t child_pid;
    child_pid = fork ();
    if (child_pid != 0)
        return child_pid;
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
