#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nomeJogador[11];
    int chkpnt;
} dados;

int main(){
	dados pedro;
	FILE *fp;
	fp = fopen("Salvos.dat", "wb");

	if (fp == NULL){
        printf("Erro ao carregar!\n");
        return 0;
    }

    printf("Nome: "); scanf("%s", pedro.nomeJogador);
	pedro.chkpnt = 10;
    
	fwrite(&pedro, sizeof(dados), 1, fp);
    
    // fseek(fp, sizeof(int), SEEK_END);
    // fwrite(*p, sizeof(int), 1, fp);

	fclose(fp);
return 0;
}