#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include "fork.h"

int main()
{
    pid_t baseID = getpid();
    printf("Base Process ID: %d, level: 0 \n", baseID);
    int level = 0;
    for (int i = 0; i < 2; i++)
    {
        pid_t pid = fork();
        if (pid == 0)
        { // Child
            pid_t childID = getpid();
            pid_t parentID = getppid();
            level++;
            printf("Process ID: %d, Parent ID: %d, level: %d \n", getpid(), getppid(), level);
            for(int aux = 0; aux < level; aux++) printf("|");
            printf("%d\n",level);
        }
        else
        { // Parent
            wait(NULL);
        }
    }
    return 0;
}

// int main()
// {
//     int status, cont = 0;
//     pid_t idProcesso = fork();

//     if (idProcesso < 0)
//         exit(1);
//     else if (idProcesso != 0)
//     {
//         printf("Processo pai (%d) e vou pesperar pelo filho \n", getpid());
//         wait(&status);
//         printf("Sou o pai(%d) e esperei pelo filho %d\n", getpid(), idProcesso);
//     }
//     else if (idProcesso == 0)
//     {
//         while (cont < 2)
//         {
//             printf("Sou o filho (%d) e meu pai é (%d)\n", getpid(), getppid());
//             sleep(2);
//             idProcesso = fork();
//             cont++;
//         }
//         exit(1);
//     }
//     exit(0);
// }

