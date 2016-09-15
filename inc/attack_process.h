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

// Create processo to attack
int call_attack(
        const unsigned char* program,
        char** arg_list,
        const unsigned int time_to_live
        );

// Get system path of executable loic
char* get_loic_path();

// Allog a arg list to process loic
char** alloc_arg_list();

#endif
