#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void signalhandler(int signo){
  if(signo == SIGINT){
    open("sig.txt",O_CREAT | O_RDWR,S_IWUSR);
    write();
    exit(0);
  }
  if(signo == SIGUSR1){
    printf("parent PID: %d\n",getppid());
  }
}

int main(){
  while(1){
    printf("process ID: %d\n",getpid());
    sleep(1);
  }
  return 0;
}
