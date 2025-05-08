#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
  int i;
  int pid;
  setnice(getpid(), 15);
  for (i = 0; i < 10; i++) {
    pid = fork();
    if (pid == 0) {
      // child
      setnice(getpid(), 21 - i * 2);
      int j;
      for (j = 0; j < 300000000; j++) {
        // some cpu-bound work
        asm volatile("");
      }
      printf(1, "Child %d finished\n", getpid());
      exit();
    }
  }

  // parent도 같이 CPU-bound 작업
  int k;
  for (k = 0; k < 300000000; k++) {
    if(k % 30000000 == 0){
        // ps(0);
        printf(1, "\n");
    }
    asm volatile("");
  }
  for(i = 0; i < 10; i++){
    wait();
    ps(0);
  } // 자식들 기다리기
  printf(1, "Parent %d finished\n", getpid());

  // ps 호출해서 vruntime 확인
  ps(0);

  exit();
}
