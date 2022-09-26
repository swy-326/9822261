#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// nao levo em consideracoes as pontuacoes
// UTF=8 BOM tem um espaco branco no comeco


int main(){

    char c;
    char nome[20];
    char palavra[10];
    int qntde = 0;

    printf("Nome do arquivo : "); gets(nome); printf("\n");
    printf("Palavra a ser buscada : "); gets(palavra); printf("\n");
    for (int i = 0; palavra[i] != '\0'; i++) palavra[i] = tolower(palavra[i]);


    FILE *fp = fopen(nome, "rb");
    if ( fp == NULL ) return 0;

    while ( !feof(fp) ){

        c = tolower(getc(fp));
        putchar(c);

        if (c != palavra[0]){
            while (c != EOF && c != ' ' ) c = getc(fp);
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
                    printf("*****");
                    qntde += 1;
                }
            }
        }
        
    }

    fclose(fp);
    printf("\nQntde : %d", qntde);
    

    return 0;
}
