#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
    int idade;
    int cpf;
    char nome[20];
} Funcionario;    // essa struct é um template pro codigo rodar, depois que o responsavel por todos os itens (funcionarios) terminar eu faço os ajustes

int ler_dados(FILE *arquivo, Funcionario *f) {
    return fscanf(arquivo, "%d,%d,%d,%s", &f->chave, &f->idade, &f->cpf, f->nome);
}

void imprimirFuncionario(Funcionario f) {
    printf("---------------------------\n");
    printf("ID: %d\nNome: %s\nIdade: %d\nCPF: %d\n", f.chave, f.nome, f.idade, f.cpf);
    printf("---------------------------\n");
}

int busca_arquivo(int chave_procurada) {
    FILE *arquivo = fopen("arquivo.csv", "r");
    if (arquivo == NULL) {
        return 0;
    }

    Funcionario A;
    int encontrou = 0;

    while (ler_dados(arquivo, &A) == 4) {
        if (A.chave == chave_procurada) {
            encontrou = 1;
            imprimirFuncionario(A);
            break;
        }
    }

    fclose(arquivo);
    return encontrou;
}

void escrita() {
    FILE *arquivo = fopen("arquivo.csv", "a");
    if (arquivo == NULL) {
        return;
    }

    Funcionario B;
    printf("Novos dados (Idade CPF Nome): ");
    scanf("%d %d %s", &B.idade, &B.cpf, B.nome);
    B.chave = rand() % 1000; 

    fprintf(arquivo, "%d,%d,%d,%s\n", B.chave, B.idade, B.cpf, B.nome);
    fclose(arquivo);
}

void auditoria(int operacao) {
    FILE *arquivo = fopen("log.csv", "a");
    if (arquivo == NULL) return;
    fprintf(arquivo, "Usuario: Admin, Operacao: %d, Status: Sucesso\n", operacao);
    fclose(arquivo);
}

int editar() {
    int key;
    printf("ID para editar: ");
    if (scanf("%d", &key) != 1) return 0;

    if (busca_arquivo(key)) {
        escrita();
        auditoria(1);
        return 1;
    } else {
        printf("Nenhuma chave encontrada.\n");
        return 0;
    }
}

int main() {
    editar();
    return 0;
}