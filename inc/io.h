#ifndef IO_H
#define IO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void print_usage();

char *get_ip(const unsigned int argc, char *argv[]);

void print_attack();

void print_set_baseline();

#endif
