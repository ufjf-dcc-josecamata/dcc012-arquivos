#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "estudante_io.h"

int ObterNumeroRegistrosEstudantes(FILE *arq) 
{ 
   fseek(arq, 0, SEEK_END); 
   int tam = trunc(ftell(arq)/Estudante_Size()); 
   return tam; 
}

void Cadastra_Estudantes(FILE *out) 
{
    printf("Inserindo 5 estudantes no arquivo...");

    Estudante *e1 = Estudante_Create("Ana",  "0000000000", "01/01/1980", 2018);
    Estudante_Save(e1, out);
    free(e1);

    Estudante *e2 = Estudante_Create("Carlos", "1111111111", "01/01/1990", 2019);
    Estudante_Save(e2, out);
    free(e2);

    Estudante *e3 = Estudante_Create("Fátima", "2222222222", "02/02/1990", 2020);
    Estudante_Save(e3, out);
    free(e3);

    Estudante *e4 = Estudante_Create("João", "3333333333", "03/03/1990", 2019);
    Estudante_Save(e4, out);
    free(e4);

    Estudante *e5 = Estudante_Create("Maria", "4444444444", "04/04/1990", 2018);
    Estudante_Save(e5, out);
    free(e5);

}

void LerRegistrosEstudantes(FILE *in) 
{
    printf("\n\nLendo registros de estudantes do arquivo...\n\n");
    rewind(in);
    Estudante *est;
    while ((est = Estudante_Read(in)) != NULL) 
    {
        Estudante_Imprime(est);
        free(est);
    }
}

void ImprimeDadosRegistro(FILE *in, int ireg) 
{

    printf("\n\nLendo dados do estudante %d do arquivo...\n\n", ireg);
    // Estudante_Size() indica o tamanho, em bytes, que um 
    // registro da estrutura Estudante ocupa.
    //** ATENÇÃO: não usar sizeof(Estudante), pois ele pode 
    //            retornar valor maior que o tamanho ocupado em disco,
    //            devido a alinhamento automático 
    //            (ver https://en.wikipedia.org/wiki/Data_structure_alignment))
    //SEEK_SET indica o início do arquivo
    //ao final, o cursor estará posicionado em 0 + tamanho() + 1

    int EnderecoReg = (ireg-1)*Estudante_Size();

    fseek(in, EnderecoReg, SEEK_SET);
    Estudante *est = Estudante_Read(in);
    if (est != NULL) {
        Estudante_Imprime(est);
        free(est);
    }
}

void AdicionaNovoRegistroEstudante(FILE *in) 
{
    printf("\n\nAdicionando estudante no final do arquivo...\n\n");

    int n_registros = ObterNumeroRegistrosEstudantes(in);
    int n_bytes     = Estudante_Size();
    fseek(in, n_bytes * n_registros, SEEK_SET);
    Estudante *est = Estudante_Create("Bruna", "5555555555", "05/05/1981", 2019);
    Estudante_Save(est, in);
    free(est);

    ImprimeDadosRegistro(in, n_registros+1);
}

void SobreescreveRegistroEstudante(FILE *in, int ireg) 
{
    printf("\n\nSobrescrevendo  registro %d do arquivo...\n\n", ireg);

    int EnderecoReg = (ireg-1)*Estudante_Size();
    //pula primeiros 3 registros para posicionar no início do quarto registro
    fseek(in, EnderecoReg, SEEK_SET);
    Estudante *est = Estudante_Create("Catarina", "6666666666", "06/06/1990", 2020);
    Estudante_Save(est, in);
    free(est);

    ImprimeDadosRegistro(in,ireg);

}