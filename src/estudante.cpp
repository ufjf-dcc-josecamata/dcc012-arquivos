#include "estudante.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

// Imprime estionario
void Estudante_Imprime(Estudante *est) {
    printf("**********************************************");
    printf("\nEstudante de Matricula: ");
    printf("%s", est->matricula);
    printf("\nNome: ");
    printf("%s", est->nome);
    printf("\nData de Nascimento: ");
    printf("%s", est->data_nasc);
    printf("\nAno de Ingresso: ");
    printf("%d", est->ano_ingresso);
    printf("\n**********************************************\n");
}

// Cria Estudante. Lembrar de usar free(est)
Estudante* Estudante_Create(const char *nome, const char *matricula, const char *data_nascimento, int ano_ingresso)
{
    Estudante *est = (Estudante *) malloc(sizeof(Estudante));
    
    //inicializa espaço de memória com ZEROS
    if (est) memset(est, 0, sizeof(Estudante));

    //copia valores para os campos de est
    strcpy(est->nome, nome);
    strcpy(est->matricula, matricula);
    strcpy(est->data_nasc, data_nascimento);
    est->ano_ingresso   = ano_ingresso;
    return est;
}

// Salva Estudante no arquivo out, na posicao atual do cursor
void Estudante_Save(Estudante *est, FILE *out) 
{
    
    fwrite(est->nome     , sizeof(char), sizeof(est->nome), out);
    fwrite(est->matricula, sizeof(char), sizeof(est->matricula), out);
    fwrite(est->data_nasc, sizeof(char), sizeof(est->data_nasc), out);
    fwrite(&est->ano_ingresso, sizeof(int), 1, out);
}

// Le um Estudante do arquivo in na posicao atual do cursor
// Retorna um ponteiro para Estudante lido do arquivo
Estudante* Estudante_Read(FILE *in) 
{
    Estudante *est = (Estudante *) malloc(sizeof(Estudante));
    if (0 >= fread(est->nome, sizeof(char), sizeof(est->nome), in)) {
        free(est);
        return NULL;
    }
    fread(est->matricula, sizeof(char), sizeof(est->matricula), in);
    fread(est->data_nasc, sizeof(char), sizeof(est->data_nasc), in);
    fread(&est->ano_ingresso, sizeof(int), 1, in);
    return est;
}

// Retorna tamanho do Estudante em bytes
int Estudante_Size() {
    return  sizeof(char)  * MAX_STR_NOME //nome
           + sizeof(char) * MAX_STR_MAT  // matricula
           + sizeof(char) * MAX_STR_DATA //data_nascimento
           + sizeof(int); // ano de ingresso
}
