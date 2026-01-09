#include <stdio.h>
#include <stdlib.h>
#include <header.h>

void end(char usuario_ativo[]){
    printf("Programa encerrado");
    auditoria(0, usuario_ativo);
    exit(0);

    }
