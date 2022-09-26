#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// nao levo em consideracoes as pontuacoes alem de . e ,
// UTF-8 BOM tem um espaco branco no comeco


bool buscaPalavra (char *nome, char *palavra){

    char c; int qntde = 0;

    FILE *fp = fopen(nome, "rb");
    if ( fp == NULL ) return false;

    while ( !feof(fp) ){

        c = tolower(getc(fp));

        if (c != palavra[0]){
            while (c != EOF && c != ' ') c = getc(fp);
        }

        else {
            int i = 1;
            while (palavra[i] != '\0'){
                if (getc(fp) != palavra[i]) break;
                i += 1;
            }
            if (palavra[i] == '\0'){
                c = getc(fp);
                if ( c == ' ' || c == ',' || c == '.' ) {
                    qntde += 1;
                }
            }
        }
    }

    fclose(fp);
    return (qntde > 0) ? true : false;
}




int main(){

    char nome[20]; char palavra[20];

    printf("Nome do arquivo : "); gets(nome); printf("\n");
    printf("Palavra a ser buscada : "); gets(palavra); printf("\n");
    for (int i = 0; palavra[i] != '\0'; i++) palavra[i] = tolower(palavra[i]);
    
    if (buscaPalavra(nome, palavra) == true) printf("true");
    else printf("false");

    return 0;
}
