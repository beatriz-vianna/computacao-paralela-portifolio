#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();

    if(pid < 0){
        fprintf(stderr, "Falha no fork");
        return 1;
    }
    else if(pid == 0){
        printf("Eu sou o processo filho, meu pid é %d e o pid do meu pai é %d.\n", getpid(), getppid());
    }
    else{
        printf("Eu sou o processo pai, meu pid é %d e o pid do meu filho é %d.", getpid(), pid);
        wait(NULL);
        printf("Agora que meu filho terminou, posso terminar.");
    }
    return 0;
}