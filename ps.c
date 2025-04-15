#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char* argv[]){
    if(argc < 2){
        ps(0);
        exit();
    }
    if( argc >= 3 ) {
        printf(1, "[USAGE] ps pid\n");
        exit();
    }
    int pid = (int)(argv[1]) - '0';
    printf(1, "%s\n", argv[1]);
    ps(pid);
    exit();
}