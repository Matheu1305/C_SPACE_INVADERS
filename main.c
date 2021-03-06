#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> 
#include <stdbool.h>

// Esta era para o caso de termos grÃ¡ficos no jogo.
//#include <graphics.h>

int WIDTH = 20;
int LENGTH = 100;

// FunÃ§Ã£o que encontrei para mudar o tamanho da consola.
// Para mudar o tamanho mexam nas variÃ¡veis em cima, podem ignorar o cÃ³digo dentro desta funÃ§Ã£o.
void setConsoleSize(){
	HANDLE wHnd;    // Handle to write to the console.
	
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle("Space Invaders!");
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, LENGTH, WIDTH};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
}

// Esta funÃ§Ã£o vai ser a mais importante para o jogo.
void showMap(){
	int i, j;
	// Desenhar o mapa
	for(i = 0; i < WIDTH; i++){
		for(j = 0; j < LENGTH; j++){
			
			// Desenhar a parte de cima
			if(i == 0 || i == WIDTH - 1){
				printf("#");
				continue;
			}
			
			// Desenhar a parte de baixo
			if(j == 0 || j == LENGTH - 1){
				printf("#");
				continue;
			}
			
			//############ RESERVADO PARA AS NAVES/BOSS ############
			if (j == 5 && i == 5){
				printf("T");
			}
			
			
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
}

// SÃ³ para ser mais rÃ¡pido arranjar um nÃºmero aleatÃ³rio.
int getRandomNumber(int min, int max){
	
	// um nÃºmero aleatÃ³rio entre 0 e a
	int r = (rand() % (max + 1 - min)) + min;

	return r;
}

int main() {
	
	int x;
	int y;
	
	setConsoleSize();
	
	while (true){
		showMap();
		Beep(4000, 300); // Para fazer sons!
		sleep(10000); // Para para o programa
	}
	return 0;
}
