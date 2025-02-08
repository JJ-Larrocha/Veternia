#include <stdio.h> 
#include <stdlib.h>

// Estruturas

typedef struct{
    char nome[11];
    int chkpnt;
} dados;

// Prototipos

int Carregar_Jogo(const char arquivo[], dados &jogador);

int main(){
    dados jogo;

    jogo.chkpnt = -1;
    bool pass = true;
    char opc;
// Menu Inicial
    while (pass == true and jogo.chkpnt < 0){
        printf("=======================================\n");
        printf("|1|- Carregar Jogo\t|2|- Novo Jogo |\n");
        printf("|3|- Opções\t        |4|- Créditos  |\n");
        printf("|0|- sair\t                       |\n");
        scanf("%c%*c", &opc);
        printf("========================================\n");

    // Carregar Jogo
        if (opc == '1'){
            if(Carregar_Jogo("Salvos.dat", jogo) == 0)
                printf("Erro ao caregar!\n");
        }

    // Novo Jogo
        else if (opc == '2'){
            char opc1;
            printf("\n----------------------------------------------------\n");
            printf("Ao carregar um novo jogo seus dados serão perdidos\nDesseja continuar?\n");
            printf("[S]- [Sim]\t[N]- [Não]\n");
            scanf("%c%*c", &opc1);
            printf("-----------------------------------------------------\n");
            if (opc1 == 's' || 'S')
                jogo.chkpnt = 0;
        }

        else if (opc == '3'){}
        else if (opc == '4'){
            printf("PedrinPvP\n");
        }
        else if (opc == '0')
            pass = false;
        else 
            printf("Opção Inexistente!\n");
    }

// Comeco do Jogo
    if (jogo.chkpnt == 0){
        printf("Aqui vai ter uma introducao;\n");

        printf("Qual o seu nome? (Até 10 digitos se espaco)\n");
        scanf("%s", jogo.nome);
        printf("%s", jogo.nome);
    }




return 0;
}

int Carregar_Jogo(const char arquivo[], dados &jogador){
    FILE *fp;
    fp = fopen(arquivo, "rb");

    if (fp == NULL)
        return 0;
    
    fread(&jogador, sizeof(dados), 1,fp);
    fclose(fp);
return 1;
}