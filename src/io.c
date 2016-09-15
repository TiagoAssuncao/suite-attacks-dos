#include "io.h"

char *get_ip(const unsigned int argc, char *argv[]) {
    char* ip;
    int option = 0, server = -1, help = -1;

    while ((option = getopt(argc, argv,"s:h:")) != -1) {
        switch (option) {
            case 's' :
                ip = optarg;
                server = 0;
                       break;
            case 'h' : help = 0;
                       break;
            default: print_usage();
                     exit(EXIT_FAILURE);
        }
    }
    if (server && help) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    if(!help){
        print_usage();
        exit(EXIT_FAILURE);
    }

    return ip;
}

void print_usage() {
    printf("Usage: run -s ip_dest\n");
    printf("Usage: run -h\n");
}

void print_attack(){
    printf("Attacking...\n");
}

void print_set_baseline(){
    printf("Setting baseline...\n");
}
