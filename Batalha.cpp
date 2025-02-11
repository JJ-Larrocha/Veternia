// Atacar
#include <stdio.h>
#include <stdlib.h>

enum atributo {queim = 1, queimGrv, afgmnt};

// Tipos e Estruturas
typedef struct{
    int dano;
    int porcentagemAcerto;
    int turnoEft;
    atributo atrbt;
} poder;

typedef struct{
    atributo atrbt;
	int porcentagemAcerto;
} item;

// Prototipos

int Ataque_do_Jogador(poder ataque, bool dmgBoool, atributo *atrbt);
bool Porcentagem_Acerto(int porcentagem);

// Main

int main(){
	int vida = 100;
	atributo efeitoNoInimigo;
	poder fogo, agua, golpe;

	fogo.atrbt = queim; fogo.dano = 13; fogo.porcentagemAcerto = 30;
	agua.atrbt = afgmnt; agua.dano = 7; agua.porcentagemAcerto = 5;
	golpe.dano = 23; golpe.porcentagemAcerto = 95;

	bool pass = true; char opc;
	while (pass == true && vida > 0){
		printf("[%3d]", vida);
		printf("------------------------------------\n");
		printf("[1]- Fogo\t[2]- Agua\n");
		printf("[3]- Itens\t[4]- Golpe\n");
		printf("[0]- Fugir\n");
		scanf("%c%*c", &opc);

		if (opc == '1'){
			vida -= Ataque_do_Jogador(fogo, true, &efeitoNoInimigo);
		}
		else if (opc == '2'){}
		else if (opc == '3'){}
		else if (opc == '4'){
			vida -= Ataque_do_Jogador(golpe, false, &efeitoNoInimigo);
		}
		else if (opc == '0')
			pass = false;
		else 
			printf("Opcao Inexistente!\n");
	}

return 0;
}

// Funcoes

int Ataque_do_Jogador(poder ataque, bool dmgBoool, atributo *atrbt){

    int golpe = 0; // Dano total

	/*Verificar a precedencia dos ifs*/
	
	if(dmgBoool && Porcentagem_Acerto(ataque.porcentagemAcerto)) // Se ataque tem % de acertar
		golpe = ataque.dano;
	/* Esse if nao deixa o golpe receber valor */
	// else if(Porcentagem_Acerto(ataque.porcentagemAcerto)) // Atribuicao de efeitos
	// 	*atrbt = ataque.atrbt;
	
	else
		golpe = ataque.dano;	

return golpe;
}

bool Porcentagem_Acerto(int porcentagem){
    if ((rand()%100)+1 <= porcentagem)
        return true;
    else
        return false;
}
