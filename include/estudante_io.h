#ifndef ESTUDANTE_IO_H__
#define ESTUDANTE_IO_H__

#include "estudante.h"

int  ObterNumeroRegistrosEstudantes(FILE *arq);

void Cadastra_Estudantes(FILE *out);

void LerRegistrosEstudantes(FILE *in);

void ImprimeDadosRegistro(FILE *in, int ireg);

void AdicionaNovoRegistroEstudante(FILE *in);

void SobreescreveRegistroEstudante(FILE *in, int ireg);


#endif
