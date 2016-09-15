#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

#define PROGRAM_PATH 0
#define IP 1
#define RATE_FLAG 2
#define RATE_NUMBER 3
#define FINAL_ARG 4
#define SIZE_PATH 1024

int set_baseline(char* program, char** arg_list, int time_to_live){
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

char* get_loic_path(char* cwd){
    getcwd(cwd, SIZE_PATH * sizeof(char));
    strcat(cwd, "/bin/loic");

    return cwd;
}

int main(int argc, const char *argv[]){
    char* cwd = malloc(SIZE_PATH * sizeof(char));
    cwd = get_loic_path(cwd);

    char** arg_list = malloc(5 * sizeof(char*));
    int time_to_live;

    arg_list[PROGRAM_PATH] = cwd;
    arg_list[IP] = "162.243.111.72";
    arg_list[RATE_FLAG] = "-r";
    arg_list[RATE_NUMBER] = "100";
    arg_list[FINAL_ARG] = NULL;
    time_to_live = 5;

    printf("Setting baseline\n");
    set_baseline(cwd, arg_list, time_to_live);

    return 0;
}
