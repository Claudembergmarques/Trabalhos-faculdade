#include <iostream>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char reserva[10][6] = {
	{' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' '}
};

	int fileira = -1, acento = -1, tipopassagem, confirmacaocompra;
	char poltrona = ' ';
	char fazeroutrareserva;
	char resposta = ' ';
	
	
	while (true) {
	printf("\nDigite a fileira (1-10): ");
	scanf("%d", &fileira);
	
	if (fileira < 1 or fileira > 10) { //Verifica se a fileira está entre 1 e 10
            printf("\nFileira invalida! Por digite uma fileira de 1 a 10");
            continue;
        }
	
	printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
	scanf(" %c", &poltrona);
	
	poltrona = tolower(poltrona); // Função Tolower serve para tratar tanto letras maíusculas como minúsculas; Verifica se a fileira está entre A e F
		
		switch(poltrona) {
		case 'a': acento = 0; break;
		case 'b': acento = 1; break;
		case 'c': acento = 2; break;
		case 'd': acento = 3; break;
		case 'e': acento = 4; break;
		case 'f': acento = 5; break;
		default: printf("\nPoltrona invalida");		
	}
	if (reserva[fileira-1][acento] == 'x') {//Verifica se a poltrona ja está ocupada
	printf("\n\n[ATENCAO] Poltrona selecionada está ocupada, por favor selecione uma fileira e poltrona descoupada. \n\n");
	continue;
	}
	
	printf("\nTipo de Passagem (1-Executivo, 2-Economico): "); //Função para selecionar o tipo de passagem (EXECUTIVO OU ECONOMICO)
    scanf(" %d", &tipopassagem);
    
    if (tipopassagem == 2) { // Verificando quando a passagem for econômica
            if (poltrona == 'a' or poltrona == 'f') {  // As poltronas de A e F são somente para o tipo de passagem Executivo
                printf("\nAs poltronas A e F sao exclusivas para passagem da classe Executiva! Escolha outra poltrona entre B e E.\n");
                continue; 
            }
            reserva[fileira - 1][acento] = 'x'; // Marca o assento como reservado
            printf("\nReserva concluída!\n");
            } 
		else if (tipopassagem == 1) { // Verificando quando a passagem for executiva
    		if (poltrona != 'a' and poltrona != 'f') { // As poltronas de A e F são somente para o tipo de passagem Executivo
        		while (true) {
            	printf("Deseja confirmar a compra desta reserva? (1 - SIM e 2 - NAO) \nInformamos que as poltronas A OU F sao priotitarias e ficam ao lado da janela: ");
            	scanf(" %d", &confirmacaocompra);
            		if (confirmacaocompra == 2) {
                		break; // Quebra o loop do segundo while
            		} 
					else if (confirmacaocompra == 1) {
                		reserva[fileira - 1][acento] = 'x'; // Confirmar a poltrona como reservada
                		printf("\nReserva realizada com sucesso!\n");
                		break; // Quebra o loop do segundo while
            		} 
					else {
                		printf("Por favor digite uma resposta valida (Digite 1 para SIM e 2 para NAO)\n"); // Pede ao passageiro para digitar uma resposta válida
            		}
        		}
    		} 
		else { // Para quando a poltrona ja é A ou F (janela)
	        reserva[fileira - 1][acento] = 'x'; // Confirma a reserva
	        printf("\nReserva realizada com sucesso!\n");
   		}
	}

	printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
	for (int x=0; x<10; x++) {
		if(x!=9) printf("\n\t0%d\t", x+1);
		else printf("\n\t%d\t", x+1);
		
		for(int y=0; y<6; y++) {
			printf("[%c] ", reserva[x][y]);
			if(y==2) {
				printf("\t");
			}
		}
	}
	while (true) {
            printf("\nDeseja realizar mais alguma reserva? (S- SIM e N - NAO): "); //Após validada a reserva este comando verifica se o cliente deseja fazer mais uma reserva
            scanf(" %c", &fazeroutrareserva);
            if (fazeroutrareserva == 'n' or fazeroutrareserva == 'N') {
                printf("\nSua reserva foi concluida. Tenha uma boa viagem!!!\n");
                return 0;  // Esse return encerra o terceiro while
            } else if (fazeroutrareserva == 's' or fazeroutrareserva == 'S') {
                break; // Retorna ao loop do primeiro while
            } else {
                printf("OPCAO INVALIDA! Digite S para SIM e N para NAO");
            }
        }
	}
	return 0; 
}


