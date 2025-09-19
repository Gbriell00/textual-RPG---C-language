#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>


//variáveis globais do player
char name_player [20];
int exp_gain = 0;
int exp_actual = 0;
int exp_max = 10;
double life [2] = {[1]=10}; //[0] = current life, [1] = max life
double attributes[] ={1, 1, 2} ; // level, força, defesa;
int size_attributes =  sizeof(attributes)/sizeof(attributes[0]);


int itens [3][1]=  {0}; 
int size_itens = sizeof(itens)/sizeof(itens[0]);


int actual_location = 0; //0 = cela, 01 = porta, 1 = fora da cela


//listagem das funções por ordem em que apareecem:

void get_name_player();
void level_up();
int menu (int mi);
void view_attributes();
void view_itens();


// falar o loot recebido
void loot_analyser(int a[][1], int t);

//telas:
void screen0();
void screen1();



//obter o nome do jogador
void get_name_player(){
	printf("Antes de iniciarmos, me diga o seu nome:\n");
	
	fgets(name_player, sizeof(name_player), stdin);
	name_player[strcspn(name_player, "\r\n")] = '\0';

	
	printf("Seja bem-vindo,");
	for (int i = 0; name_player[i]!= '\0'; i++){
			printf("%c", name_player[i]);
	}
	printf("\n");
}

//localizar em qual cena o jogo tá

//upar de nível
void level_up(){
printf("Você subiu de nível\n");
for (int i=0; i<size_attributes; i++){
	if(i==0){
		attributes[i]++;
	}
	else{
	attributes[i]*=1.3;
	life[i] *= 1.3;
	}
	switch (i){
		case 0: printf("HP: %.0lf/%.0lf\nlvl: %.0lf\n", life[i], life[i+1], attributes[i]); break;
		case 1: printf("str: %.2lf\n", attributes[i]); break;
		case 2: printf("def: %.2lf\n", attributes[i]); break;
	}
}
exp_max *= attributes[2]*1.5; //lvl do player

}

//menu: look around, bag, view attributes, go to, interact

int menu (int mi){
int selector;
int t_f = 1;
int action_code;


printf ("Selecione o sua ação\n");

switch (mi){
	case 0:
		do{
		printf("1. Olhar ao redor\n2. mochila\n3. Status do jogador\n4. Ir para\n");
		scanf(" %d", &selector);
		

		//o menu chama funções que vão executar os comandos
		if(selector>0 && selector<=5){
		switch (selector){
			
			case 1: //t_f = 0; action_code= 1; break;
			printf("nada foi programado aqui ainda\n");
			break;


			case 2:  view_itens();break;

			case 3: view_attributes(); t_f = 0;  break;

			case 4:
			printf("nada foi programado aqui ainda\n");
			break;

		}
		}
		else{
			printf("Opção não encontrada, selecione novamente\n");
		}
		}while(t_f); break;
	
	/*case 1: 
		do{
		printf("Interagir?\n1. Sim\n2. Não");
		scanf(" %d", &selector);
		if(selector>0 && selector<=2){
			switch (selector){
				case 1: 
				t_f = 0; 
					switch (actual_location ){
						case 0: action_code = 11; break;
						case 1: action_code = 12; break;
					}

				break;
				
				case 2: printf("nada foi programado aqui ainda\n");
				break;
			}

		}	
		else{
			printf("Opção não encontrada, selecione novamente\n");
		}

	}while (t_f); break*/

return action_code;

}

}


void view_attributes(){

for (int i=0; i<size_attributes; i++){

switch (i){
		case 0: printf("\nHP: %.0lf/%.0lf\nlvl: %.0lf\n", life[i], life[i+1], attributes[i]); break;
		case 1: printf("str: %.2lf\n", attributes[i]); break;
		case 2: printf("def: %.2lf\n", attributes[i]); break;
	}

}
	
printf("\nFaltam %d pontos de experiência para o level %.0lf\n", exp_max - exp_actual, attributes[0]+1);
printf("\n");
}


void view_itens(){
int j = 0;

	for (int i=0; i<size_itens; i++){
		switch (i){
		case 0: printf("\nCura: %d\n", itens[i][j]); break;
		case 1: 
			if (itens[i][j]== 0){
				printf("Você não possui nenhuma arma\n");
			}
			else{
				switch(itens[i][j]){
					case 1: printf("Graveto\n"); break;
					case 2: printf("Espada de ferro\n"); break;
				}
			} break;
		case 2: printf("Chaves: %d\n", itens[i][j]); break;
	
}
printf("\n");
}
}



void loot_analyser(int a [][1], int t){

printf("Você achou:");

int j = 0;

	for (int i=0; i< t ; i++){
		switch (i){
		case 0: printf("Cura: %d\n", a[i][j]); break;
		case 1: 
			if (a[i][j]== 0){
				printf("Você não possui nenhuma arma\n");
			}
			else{
				switch(a[i][j]){
					case 1: printf("Graveto\n"); break;
					case 2: printf("Espada de ferro\n"); break;
				}
			} break;
		case 2: printf("Chaves: %d\n", a[i][j]); break;
	
}

	for (int i = 0; i < t; i++) {
    itens[i][0] += a[i][0];
}
}




}


void screen0(){
	int code_localizer = 0;
	actual_location = code_localizer;
	int action_localizer;
	int menu_initiator = 0;
	int loot_skeleton [3][1] = {{3} , {2}, {1}};
	int size_loot_sk = sizeof(loot_skeleton)/sizeof(loot_skeleton[0]);
	int selector;


	menu (menu_initiator);
	action_localizer = menu (menu_initiator);

	switch (action_localizer){
		case 0: menu(menu_initiator); break;
		case 1: 
			printf("Tem algo emitindo um leve brilho perto de onde você tá.\n");
			printf("Ao se aproximar, nota que é um esqueleto trajado com o resto do que já foi uma armadura.\n");
			printf("Além disso, você também percebe que está num tipo de cela. Você pode:\n");
			printf("1. Ohar Esqueleto\n2. Olhar porta da cela\n");

			/*scanf("%d", &selector);
				switch (selector){
					case 1: menu_initiator = 1; menu(menu_initiator); break;

					case 2: code_localizer = 01; actual_location = code_localizer;
					menu_initiator = 1; menu(menu_initiator); 
					break;
		
					case 11: loot_analyser(loot_skeleton, size_loot_sk); break;
					case 12: printf("acho que precisa de uma chave para abrir\n"); break;*/
	}
	
}



void screen1(){
//int code_localizer = 1;



}



int main() {
	
	get_name_player();

	//Início, jogo
	printf("Alguma coisa pingou no seu rosto e te fez despertar em meio a escuridão.\n");
	printf("Você não faz ideia aonde está, muito menos como chegou aqui\n");

	screen0();
		

	




	return 0;
}