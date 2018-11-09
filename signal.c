#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void signalhandler(int signo){
  if(signo == SIGINT){
    int file = open("sig.txt",O_CREAT | O_APPEND | O_RDWR,S_IRUSR|S_IWUSR);
    write(file,"program exit due to SIGINT\n",27);
    close(file);
    exit(0);
  }
  if(signo == SIGUSR1){
    printf("parent PID: %d\n",getppid());
  }
}

int main(){
  signal(SIGINT,signalhandler);
  signal(SIGUSR1,signalhandler);
  while(1){
    printf("process ID: %d\n",getpid());
    sleep(1);
  }
  return 0;
}
