#ifndef ESTUDANTE_H_
#define ESTUDANTE_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_NOME 50
#define MAX_STR_MAT  11
#define MAX_STR_DATA 11

/*
 *
 */
typedef struct {
     char nome[MAX_STR_NOME];
     char matricula[MAX_STR_MAT];
     char data_nasc[MAX_STR_DATA];
     int  ano_ingresso;
} Estudante;


void       Estudante_Imprime(Estudante *func);

// Cria Estudante. Lembrar de usar free(funcionario)
Estudante* Estudante_Create(const char *nome, const char *matricula, const char *data_nascimento, int ano_ingresso);

// Salva Estudante no arquivo out, na posicao atual do cursor
void       Estudante_Save(Estudante *func, FILE *out);

// Le um Estudante do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
Estudante* Estudante_Read(FILE *in);

// Retorna tamanho do Estudante em bytes
int        Estudante_Size();

#endif /* ESTUDANTE_H_ */

