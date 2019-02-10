// =----------------------------------------------------------=
// =                           AVISO:                         =
// =                   MODIFIQUE ESTE ARQUIVO!                =
// = Aqui, você deve implementar, obrigatoriamente, essas     =
// = duas funções:                                            =
// =     - `a_menor_que_b`: deve retornar quando uma string   =
// =        é menor que a outra (ambos com o mesmo tamanho);  =
// =     - `external_sort`: aqui, você deverá implementar o   =
// =        seu trabalho. Ordene os registros em `input_file` =
// =        e escreva-os em `output_file`, usando somente     =
// =        `memory` KB de memória.                           =
// =                                                          =
// = Instruções:                                              =
// =     - use a função `mathias_malloc` ao invés de          =
// =       `malloc`;                                          =
// =     - use a função `mathias_free` ao invés de `free`;    =
// =     - lembre-se que você tem somente `memory` KB de      =
// =       memória;                                           =
// =     - note que a sua implementação de `a_menor_que_b`    =
// =       afetará o resultado da verificação da resposta.    =
// =                                                          =
// = Dicas:                                                   =
// =     - você pode usar a sua função `a_menor_que_b` em     =
// =       sua implementação da função `external_sort`;       =
// =                                                          =
// =                      BOM TRABALHO!                       =
// =----------------------------------------------------------=

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"

// Parâmetros:
//     - a: uma cadeia de caracteres de tamanho `len`;
//     - b: uma cadeia de caracteres de tamanho `len`;
//     - len: o tamanho (quantidade de bytes) de `a` e `b`.
// Essa função deve retornar 1, se `a` é menor que `b` (`a` deve vir antes de `b` no
// arquivo), e 0 caso contrário.
// Ela também é usada para verificação da ordenação! Então, se você implementá-la
// erroneamente, a verificação também estará errada! 
int a_menor_que_b(char* a, char* b, int len) {

	int i = 0;
    for(i = 0; i < len; i++)
    {
        if(a[i] < b[i])
        {
            return 1;
        }

        else if(a[i] > b[i])
        {
            return 0;
        }
    }

    return -1;
}

// Parâmetros:
//     - input_file: o nome do arquivo com os registros de entrada;
//     - output_file: o nome do arquivo com os registros de entrada ordenados;
//     - memory: o limite de memória a ser usado.
// Essa função deverá ler todos registros do arquivo `input_file`, ordená-los e
// escrevê-los em `output_file`, usando memória menor ou igual a `memory`. Lembre-se
// de fechar todos os arquivos que você usar por aqui!!
void external_sort(const char* input_file, const char* output_file, unsigned int memory) {

    FILE *fita1;
    FILE *fita2;
    FILE *fita3;
    FILE *fita4;
    FILE *arq_saida;

    int i = 0;
    int end = 0;
    int size_line = 0;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;
    int aux1 = 0;
    int aux2 = 0;
    int aux3 = 0;
    int aux4 = 0;
    int size_fita1 = 0;
    int size_fita2 = 0;
    int size_fita3 = 0;
    int size_fita4 = 0;

    char *vet1;
    char *vet2;
    char vet_aux[2000];

    //Abertura do Arquivo
    FILE *arq_entrada;

    arq_entrada = fopen(input_file,"r");
    //arq_entrada = fopen("test_010.010_1.txt","r");
    if(arq_entrada == NULL)
    {
        printf("Arquivo não existe ou não tem permissão para leitura\n\n");
        exit(1);
    }

    fita1 = fopen("fita1.txt","w");
    fita2 = fopen("fita2.txt","w");
    fita3 = fopen("fita3.txt","w");
    fita4 = fopen("fita4.txt","w");
    arq_saida = fopen(output_file,"w");

    fgets(vet_aux,2000,arq_entrada);
    size_line = atoi(vet_aux);

    vet1 = mathias_malloc(size_line*sizeof(char));
    vet2 = mathias_malloc(size_line*sizeof(char));


    //Fase de Criacao dos Blocos Ordenados
    while(!feof(arq_entrada))
    {
        i++;

        fgets(vet1,size_line+1,arq_entrada);
        if(*vet1 == '\n')
        {
            fgets(vet1,size_line+1,arq_entrada);
            if(*vet1 == '\n')
            {
                fgets(vet1,size_line+1,arq_entrada);
                break;
            }
            
        }
        vet1[size_line+1] = '\0';

        fgets(vet2,size_line+1,arq_entrada);
        if(*vet2 == '\n')
        {
            fgets(vet2,size_line+1,arq_entrada);
        }

        vet2[size_line+1] = '\0';

        //Strcmp Compara vet1 com o vet2
        //As flags são para verificar os estados das fitas e realizar a intercalacao entre as fitas 1 e 2
        if(strcmp(vet1,vet2) < 0)
        {
            if(flag1 == 0)
            {
                fprintf(fita1,"%s",vet1);
                fprintf(fita1,"%s",vet2);
                fprintf(fita1,"\n");
                flag1 = 1;
                flag2 = 0;

                /*printf("%s",vet1);
                printf("%s",vet2);
                printf("\n");*/
            }
            else if(flag1 == 1 && flag2 == 0)
            {
                fprintf(fita2,"%s",vet1);
                fprintf(fita2,"%s",vet2);
                fprintf(fita2,"\n");
                flag1 = 0;
                flag2 = 1;


               /* printf("%s",vet1);
                printf("%s",vet2);
                printf("\n");*/
            }

        }
        else if(strcmp(vet1,vet2) > 0)
        {
            if(flag1 == 0)
            {
                fprintf(fita1,"%s",vet2);
                fprintf(fita1,"%s",vet1);
                fprintf(fita1,"\n");
                flag1 = 1;
                flag2 = 0;


                /*printf("%s",vet2);
                printf("%s",vet1);
                printf("\n");*/
            }
            else if(flag1 == 1 && flag2 == 0)
            {
                fprintf(fita2,"%s",vet2);
                fprintf(fita2,"%s",vet1);
                fprintf(fita2,"\n");
                flag1 = 0;
                flag2 = 1;


                /*printf("%s",vet2);
                printf("%s",vet1);
                printf("\n");*/
            }

        }
    }

    fclose(fita1);
    fclose(fita2);

    //Fase de Intercalacao
    while(1)
    {

        //Fita 1 e 2 para leitura
        //Fita 3 e 4 para escrita
        fita1 = fopen("fita1.txt","r");
        fita2 = fopen("fita2.txt","r");
        fita3 = fopen("fita3.txt","w");
        fita4 = fopen("fita4.txt","w");

        flag1 = 0;
        flag2 = 0;
        flag3 = 0;
        flag4 = 0;

            //Enquanto a fita1 e fita2 nao forem lidas totalmente
            //As flags são para verificar os estados das fitas e realizar a intercalacao entre as fitas 3 e 4
            while(1)
            {
                fgets(vet1,size_line+1,fita1);
                if(*vet1 == '\n')
                {
                    fgets(vet1,size_line+1,fita1);
                    if(*vet1 == '\n' && *vet2 == '\n')
                    {
                        break;
                    }
                }
                fgets(vet2,size_line+1,fita2);
                if(*vet2 == '\n')
                {
                    fgets(vet2,size_line+1,fita2);
                    if(*vet1 == '\n' && *vet2 == '\n')
                    {
                        break;
                    }

                }
                //Verifica se a fita ta inativa
                aux1 = 1;
                aux2 = 1;

                while(aux1 != 0 && aux2 != 0)
                {

                    // A < C
                    if(strcmp(vet1,vet2) < 0)
                    {
                        if(flag3 == 0)
                        {
                            if(*vet1 != '\n')
                            {
                                fprintf(fita3,"%s",vet1);
                                //printf("%s",vet1);
                                fgets(vet1,size_line+1,fita1);
                            }
                            if(*vet1 == '\n')
                            {
                                aux1 = 0; //Fita1 INATIVA
                                while(*vet2 != '\n')
                                {
                                    fprintf(fita3,"%s",vet2);
                                    //printf("%s",vet2);
                                    fgets(vet2,size_line+1,fita2);
                                }
                                aux2 = 0;
                                fprintf(fita3,"\n");
                                //printf("\n");
                                flag3 = 1;
                                flag4 = 0;
                            }
                        }
                        else if(flag3 == 1 && flag4 == 0)
                        {
                            if(*vet1 != '\n')
                            {
                                fprintf(fita4,"%s",vet1);
                                //printf("%s",vet1);
                                fgets(vet1,size_line+1,fita1);
                            }
                            if(*vet1 == '\n')
                            {
                                aux1 = 0; //Fita1 INATIVA
                                while(*vet2 != '\n')
                                {
                                    fprintf(fita4,"%s",vet2);
                                    //printf("%s",vet2);
                                    fgets(vet2,size_line+1,fita2);
                                }
                                aux2 = 0;
                                fprintf(fita4,"\n");
                                //printf("\n");
                                flag3 = 0;
                                flag4 = 1;
                            }
                        }
                    }
                    // A > C
                    else if(strcmp(vet1,vet2) > 0)
                    {
                        if(flag3 == 0)
                        {
                            if(*vet2 != '\n')
                            {
                                fprintf(fita3,"%s",vet2);
                                //printf("%s",vet2);
                                fgets(vet2,size_line+1,fita2);
                            }
                            if(*vet2 == '\n')
                            {
                                aux2 = 0; //Fita2 INATIVA
                                while(*vet1 != '\n')
                                {
                                    fprintf(fita3,"%s",vet1);
                                    //printf("%s",vet1);
                                    fgets(vet1,size_line+1,fita1);
                                }
                                aux1 = 0;
                                fprintf(fita3,"\n");
                                //printf("\n");
                                flag3 = 1;
                                flag4 = 0;
                            }
                        }
                        else if(flag3 == 1 && flag4 == 0)
                        {
                            if(*vet2 != '\n')
                            {
                                fprintf(fita4,"%s",vet2);
                                //printf("%s",vet2);
                                fgets(vet2,size_line+1,fita2);
                            }
                            if(*vet2 == '\n')
                            {
                                aux2 = 0; //Fita2 INATIVA
                                while(*vet1 != '\n')
                                {
                                    fprintf(fita4,"%s",vet1);
                                    //printf("%s",vet1);
                                    fgets(vet1,size_line+1,fita1);
                                }
                                aux1 = 0;
                                fprintf(fita4,"\n");
                                //printf("\n");
                                flag3 = 0;
                                flag4 = 1;
                            }
                        }
                    }
                }
            }//Termino do laco das fitas 1 e 2 
            size_fita1 = ftell(fita1);
            size_fita2 = ftell(fita2);
            size_fita3 = ftell(fita3);
            size_fita4 = ftell(fita4);


           /* printf("\nTAMANHO\n");
            printf("%d\n",size_fita1);
            printf("%d\n",size_fita2);
            printf("%d\n",size_fita3);
            printf("%d\n",size_fita4);*/

            fclose(fita1);
            fclose(fita2);
            fclose(fita3);
            fclose(fita4);

            //CONDICAO DE PARADA PARA A INTERCALACAO
            if(size_fita4 == 0)
            {
                //printf("\nENTROU AQUI\n");
                end = 3;
                break;
            }

            fita1 = fopen("fita1.txt","w");
            fita2 = fopen("fita2.txt","w");
            fita3 = fopen("fita3.txt","r");
            fita4 = fopen("fita4.txt","r");

            flag1 = 0;
            flag2 = 0;
            flag3 = 0;
            flag4 = 0;

            //INTERCALAÇÂO DAS FITAS 1 e 2
            //As flags são para verificar os estados das fitas e realizar a intercalacao entre as fitas 1 e 2
            while(1)
            {
                fgets(vet1,size_line+1,fita3);
                if(*vet1 == '\n')
                {
                    fgets(vet1,size_line+1,fita3);
                    if(*vet1 == '\n' && *vet2 == '\n')
                    {
                        break;
                    }
                }
                fgets(vet2,size_line+1,fita4);
                if(*vet2 == '\n')
                {
                    fgets(vet2,size_line+1,fita4);
                    if(*vet1 == '\n' && *vet2 == '\n')
                    {
                        break;
                    }

                }

                //Verifica se a fita ta inativa
                aux3 = 1;
                aux4 = 1;

                while(aux3 != 0 && aux4 != 0)
                {
                    // A < C
                    if(strcmp(vet1,vet2) < 0)
                    {
                        if(flag1 == 0)
                        {
                            if(*vet1 != '\n')
                            {
                                fprintf(fita1,"%s",vet1);
                                //printf("%s",vet1);
                                fgets(vet1,size_line+1,fita3);
                            }
                            if(*vet1 == '\n')
                            {
                                aux3 = 0; //Fita3 INATIVA
                                while(*vet2 != '\n')
                                {
                                    fprintf(fita1,"%s",vet2);
                                    //printf("%s",vet2);
                                    fgets(vet2,size_line+1,fita4);
                                }
                                aux4 = 0;
                                fprintf(fita1,"\n");
                                //printf("\n");
                                flag1 = 1;
                                flag2 = 0;
                            }
                        }
                        else if(flag1 == 1 && flag2 == 0)
                        {
                            if(*vet1 != '\n')
                            {
                                fprintf(fita2,"%s",vet1);
                                //printf("%s",vet1);
                                fgets(vet1,size_line+1,fita3);
                            }
                            if(*vet1 == '\n')
                            {
                                aux3 = 0; //Fita3 INATIVA
                                while(*vet2 != '\n')
                                {
                                    fprintf(fita2,"%s",vet2);
                                    //printf("%s",vet2);
                                    fgets(vet2,size_line+1,fita4);
                                }
                                aux4 = 0;
                                fprintf(fita2,"\n");
                                //printf("\n");
                                flag1 = 0;
                                flag2 = 1;
                            }
                        }
                    }
                    // A > C
                    else if(strcmp(vet1,vet2) > 0)
                    {
                        if(flag1 == 0)
                        {
                            if(*vet2 != '\n')
                            {
                                fprintf(fita1,"%s",vet2);
                                //printf("%s",vet2);
                                fgets(vet2,size_line+1,fita4);
                            }
                            if(*vet2 == '\n')
                            {
                                aux4 = 0; //Fita4 INATIVA
                                while(*vet1 != '\n')
                                {
                                    fprintf(fita1,"%s",vet1);
                                    //printf("%s",vet1);
                                    fgets(vet1,size_line+1,fita3);
                                }
                                aux3 = 0;
                                fprintf(fita1,"\n");
                                //printf("\n");
                                flag1 = 1;
                                flag2 = 0;
                            }
                        }
                        else if(flag1 == 1 && flag2 == 0)
                        {
                            if(*vet2 != '\n')
                            {
                                fprintf(fita2,"%s",vet2);
                                //printf("%s",vet2);
                                fgets(vet2,size_line+1,fita4);
                            }
                            if(*vet2 == '\n')
                            {
                                aux4 = 0; //Fita2 INATIVA
                                while(*vet1 != '\n')
                                {
                                    fprintf(fita2,"%s",vet1);
                                    //printf("%s",vet1);
                                    fgets(vet1,size_line+1,fita3);
                                }
                                aux3 = 0;
                                fprintf(fita2,"\n");
                                //printf("\n");
                                flag1 = 0;
                                flag2 = 1;
                            }
                        }
                    }
                }
            }//Termina

            size_fita1 = ftell(fita1);
            size_fita2 = ftell(fita2);
            size_fita3 = ftell(fita3);
            size_fita4 = ftell(fita4);

            /*printf("\nTAMANHO\n");
            printf("%d\n",size_fita1);
            printf("%d\n",size_fita2);
            printf("%d\n",size_fita3);
            printf("%d\n",size_fita4);*/

            //CONDICAO DE PARADA DA INTERCALACAO
            if(size_fita2 == 0)
            {
                end = 1;
                break;
            }

            fclose(fita1);
            fclose(fita2);
            fclose(fita3);
            fclose(fita4);

    }

    size_fita1++;
    size_fita3++;

    fprintf(arq_saida,"%d\n",size_line);
    //printf("%d\n",size_line);

    if(end == 1)
    {
        fclose(fita1);
        //printf("\nentrou na funcao de print\n");
        fita1 = fopen("fita1.txt", "r");
        fgets(vet1,size_line+1 ,fita1);
        if(*vet1 == '\n')
        {
            fgets(vet1,size_line+1,fita1);
        }
        fprintf(arq_saida, "%s\n",vet1);
        //printf("%s\n",vet1);

        while(strcmp(vet1, "\n") != 0)
        {
            fgets(vet1,size_line+1,fita1);
            if(*vet1 == '\n')
            {
                break;
            }
            fprintf(arq_saida, "%s\n", vet1);
            //printf("%s\n",vet1);
        }
        fclose(fita1);
        remove("fita1.txt");

    }
    if(end == 3)
    {
        //printf("\nentrou na funcao de print\n");
        fita3 = fopen("fita3.txt", "r");
        fgets(vet1,size_line+1 ,fita3);
        if(*vet1 == '\n')
        {
            fgets(vet1,size_line+1,fita3);
        }
        fprintf(arq_saida, "%s\n",vet1);
        //printf("%s\n",vet1);

        while(strcmp(vet1, "\n") != 0)
        {
            fgets(vet1,size_line+1,fita3);
            if(*vet1 == '\n')
            {
                break;
            }
            fprintf(arq_saida, "%s\n", vet1);
            //printf("%s\n",vet1);
        }
        fclose(fita3);
        remove("fita3.txt");
    }

    fclose(arq_saida);
    fclose(arq_entrada);

    mathias_free(vet1);
    mathias_free(vet2);

}
