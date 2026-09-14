#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int i;
    pid_t pid;
    int num = 4;

    printf("Processo Pai principal com PID %d.\n\n\n", getpid());
    for(i = 0; i < num; i++){
        pid = fork();
        if(pid < 0){
            fprintf(stderr, "Falha no fork");
            return 1;
        }
        else if(pid == 0){
            printf("Eu sou o processo filho %d, meu pid é %d e o pid do meu pai é %d.\n\n\n", i, getpid(), getppid());
            exit(0);
        }
    }   

    for(i = 0; i < num; i++){
    //    wait(NULL);
    }
    printf("Todos os filhos terminaram. O processo pai vai encerrar.\n\n\n");

    return 0;
}