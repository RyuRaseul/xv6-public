#include "types.h"
#include "user.h"
#include "stat.h"

int main(){
    int i;
    for(i = 1; i < 11; i++) {
        printf(1, "%d: ", i);
        if(getnice(i) == -1){
            printf(1, "Wrong PID\n");
        } else {
            printf(1, "Nicevalue is %d\n", getnice(i));
            if(i == 1){
                for(int j = -10; j < 50; j++){
                    if(setnice(i, j)){
                        printf(1, "Fail to set nicevalue\n");
                    } else {
                        printf(1, "Changed Nicevlaue is %d\n", getnice(i));
                    }
                }
            }
        }
        ps(i);
    }
    ps(0);
    exit();
}