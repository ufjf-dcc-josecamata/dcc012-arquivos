#include <stdlib.h>
#include <stdio.h> 

#include "estudante_io.h"

int main(int argc, char** argv) {
    //declara ponteiro para arquivo
    FILE *out;
    //abre arquivo
    if ((out = fopen("estudante.dat", "w+b")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    else {
        // Insere Estudantes no arquivo.
        Cadastra_Estudantes(out);

        //volta ao início do arquivo e lê os estudante inseridos
        LerRegistrosEstudantes(out);

        //volta ao início do arquivo e lê o segundo estudante
        ImprimeDadosRegistro(out, 2);

        //grava mais um estudante no final do arquivo.
        AdicionaNovoRegistroEstudante(out);

        //sobrescreve quarto Estudante
        SobreescreveRegistroEstudante(out, 4);

        //lendo o arquivo todo novamente
        LerRegistrosEstudantes(out);

        //fecha arquivo
        fclose(out);
    }
}

