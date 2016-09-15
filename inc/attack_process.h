#ifndef ATTACK_PROCESS_H
#define ATTACK_PROCESS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

extern int PROGRAM_PATH;
extern int IP;
extern int RATE_FLAG;
extern int RATE_NUMBER;
extern int FINAL_ARG;
extern int SIZE_PATH;

int call_attack(char* program, char** arg_list, int time_to_live);

char* get_loic_path(char* cwd);

#endif
