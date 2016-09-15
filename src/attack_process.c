#include "attack_process.h"

int PROGRAM_PATH = 0;
int IP = 1;
int RATE_FLAG = 2;
int RATE_NUMBER = 3;
int FINAL_ARG = 4;
int SIZE_PATH = 1024;

int call_attack(char* program, char** arg_list, int time_to_live){
    pid_t child_pid;
    child_pid = fork ();
    if (child_pid != 0){
        sleep(time_to_live);
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
