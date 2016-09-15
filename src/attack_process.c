#include "attack_process.h"

int PROGRAM_PATH = 0;
int IP = 1;
int RATE_FLAG = 2;
int RATE_NUMBER = 3;
int FINAL_ARG = 4;
int SIZE_PATH = 1024;

/* Create a child process and the parent will wait time_to_live seconds */
/* to send the SIGTERM signal to kill him */
int call_attack(
        const unsigned char* program,
        char** arg_list,
        const unsigned int time_to_live
        ){
    pid_t child_pid;

    /* Create a new process */
    child_pid = fork();

    /* If it is the parent process, wait a time_to_live */
    /* and kill the child */
    if (child_pid != 0){
        sleep(time_to_live);
        kill(child_pid, SIGTERM);
        return child_pid;
    }
    else {
        /* Execute the child process (loic) */
        execvp (program, arg_list);
        fprintf (stderr, "an error occurred in execvp\n");
        abort ();
    }
}

/* Get path of loic in the system */
char* get_loic_path(){
    char* cwd;
    cwd = malloc(SIZE_PATH * sizeof(char));
    getcwd(cwd, SIZE_PATH * sizeof(char));
    strcat(cwd, "/bin/loic");

    return cwd;
}

char** alloc_arg_list(){
    char** arg_list = malloc(5 * sizeof(char*));
    return arg_list;
}
