#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h> // Biblioteca para _getch()
#include <windows.h> // Para Sleep() e SetConsoleTextAttribute()

//FAZENDO TEST GITHUB DESKTOP



#define TAMANHO 10




//----------------------------------------------------PEGA O NOME DO JOGADOR-----------------------------------------------------------------------

typedef struct {
    char nome[50];  // Nome do jogador
    int forca;      // Força do jogador
} Jogador;

Jogador jogador;  // Variável global do jogador





//-----------------------------------------------------VARIAVEIS GLOBAIS---------------------------------------------------------------------------

int matriz[TAMANHO][TAMANHO] = {0}; //cria uma matriz 10x10 (onde todos os valores são 0)
int i,j;


int poderes[4] = {5, 10, 15, 20};
int inimigos[4] = {-35, -40, -45, -50};

int poder_atual = 0;

int inimigo_proximo_forca = 0; 
int forca = 0;
int inimigo_proximo_antes = 0; // Armazena o estado do inimigo próximo anteriormente

int boneco_linha = 0;
int boneco_coluna = 0;




//--------------------------------------------------------------------------------------------------------------------------------------------------





//---------------------------------------IMPRIMINDO POSIÇÕES DO BONECO, INIMIGOS, PODERES E DO MAPA-------------------------------------------------
	
	void imprimirmapa(int matriz[TAMANHO][TAMANHO], int boneco_linha, int boneco_coluna){
		int i,j;

		for(i = 0; i < TAMANHO; i++){
			for(j = 0; j < TAMANHO; j++){
				if(i == boneco_linha && j == boneco_coluna){ // inicia o "Boneco (B), na primeira posição da matriz"
					printf("H  ");
				}
				else if (matriz[i][j] == 0){ // ja que na matriz eu fiz com que todos numeros sejam igual a 0, ela vai transformar todos os (0) em (.)
					printf(".  ");
				}else if (matriz[i][j] > 0){
					printf(".  ");					
				}else{
					printf(".  ");
				}		
			}
			printf("\n");
		}
		
	// Exibe a força do inimigo próximo ao lado da força do boneco, se houver um inimigo próximo
    if (inimigo_proximo_forca != 0) {
        printf("\n==========================================");
        printf("\n               BATALHA                 \n");
        printf("==========================================\n");
        printf("\nPODER DO INIMIGO: %d    VS   ", inimigo_proximo_forca);
    }else {
    	printf("\nRadar sem inimigos.\n\n");
	}

}

	
//--------------------------------------------------------------------------------------------------------------------------------------------------
	
	
	
	
		
//------------------------------------------------------- COR   INIMIGO PROXIMO (FUNÇÃO PRONTA VERMELHO)----------------------------------------------
		void inimigoproximo() {
	    // Muda a cor do texto para vermelho
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	    
	    // Limpa a tela
	    system("cls");
	    
	    // Exibe a mensagem
	    printf("\n\nO RADAR ENCONTROU UM INIMIGO PROXIMO!!!\n");
	    
	    // Restaura a cor do texto para o padrão
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	    
	    // Espera 3 segundos
	    Sleep(3000);
	    
	    // Limpa a tela novamente
	    system("cls");
	}
	
//--------------------------------------------------------------------------------------------------------------------------------------------------
	
	
	
	
		
//------------------------------------------------------- COR    PODER PROXIMO (FUNÇÃO PRONTA AZUL)--------------------------------------------------
	void poderproximo() {
    // Muda a cor do texto para vermelho
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    
    // Limpa a tela
    system("cls");
    
    // Exibe a mensagem
    printf("\n\nTEM UM PODER PROXIMO A VOCÊ!!!\n");
    
    // Restaura a cor do texto para o padrão
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    // Espera 3 segundos
    Sleep(2000);
    
    // Limpa a tela novamente
    system("cls");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------





//------------------------------------------------------- COR   RECEBEU PODER (FUNÇÃO PRONTA AZUL)--------------------------------------------------
	void recebeupoder(int poder_coletado) {
    // Muda a cor do texto para vermelho
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    
    // Limpa a tela
    system("cls");
    
    // Exibe a mensagem
    printf("\n\nVOCE RECEBEU   +%d   DE PODER!!!\n", poder_coletado);
    
    // Restaura a cor do texto para o padrão
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    // Espera 3 segundos
    Sleep(2000);
    
    // Limpa a tela novamente
    system("cls");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------





//-------------------------------------------------------COR  WIN (FUNÇÃO PRONTA VERDE)--------------------------------------------------
	void win() {
    // Muda a cor do texto para vermelho
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    // Limpa a tela
    system("cls");
    
    // Exibe a mensagem
    printf("\n\n          %s É O CAMPEÃO!!!\n  Parabéns, você se tornou o herói mais forte.\n\n  Se torne um professor e ensine aos mais novos.\n", jogador.nome);
    
    // Restaura a cor do texto para o padrão
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    // Espera 3 segundos
    Sleep(5000);
    
    // Limpa a tela novamente
    system("cls");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------





//-------------------------------------------------------COR  VENCEU INIMIGO (FUNÇÃO PRONTA VERDE)--------------------------------------------------
	void venceuinimigo() {
    // Muda a cor do texto para vermelho
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    // Limpa a tela
    system("cls");
    
    // Exibe a mensagem
    printf("\n\n%s VENCEU O INIMIGO!!!\n", jogador.nome);
    
    // Restaura a cor do texto para o padrão
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    
    // Espera 3 segundos
    Sleep(2000);
    
    // Limpa a tela novamente
    system("cls");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------





//------------------------------------------------------------PROCURA INIMIGOS PROXIMOS--------------------------------------------------------------


void verificarInimigosProximos(int matriz[TAMANHO][TAMANHO], int boneco_linha, int boneco_coluna) {
    int inimigo_proximo = 0; // Variável temporária para verificar se há inimigo próximo

    // Verifica as posições ao redor do boneco para encontrar inimigos
    if (boneco_linha > 0 && matriz[boneco_linha - 1][boneco_coluna] < 0) { // Acima
        inimigo_proximo = matriz[boneco_linha - 1][boneco_coluna];
        
    } else if (boneco_linha < TAMANHO - 1 && matriz[boneco_linha + 1][boneco_coluna] < 0) { // Abaixo
        inimigo_proximo = matriz[boneco_linha + 1][boneco_coluna];
        
    } else if (boneco_coluna > 0 && matriz[boneco_linha][boneco_coluna - 1] < 0) { // Esquerda
        inimigo_proximo = matriz[boneco_linha][boneco_coluna - 1];
        
    } else if (boneco_coluna < TAMANHO - 1 && matriz[boneco_linha][boneco_coluna + 1] < 0) { // Direita
        inimigo_proximo = matriz[boneco_linha][boneco_coluna + 1];
    }

    // Verifica se o inimigo é novo ou se você se afastou
    if (inimigo_proximo != 0) {
        inimigo_proximo_forca = inimigo_proximo;
        if (!inimigo_proximo_antes) { // Se o inimigo não estava próximo antes, mostra a mensagem
            inimigoproximo();
        }
        inimigo_proximo_antes = 1; // Atualiza o estado para indicar que um inimigo está próximo
    } else {
        inimigo_proximo_antes = 0; // Se não há inimigo próximo, limpa o estado
        inimigo_proximo_forca = 0; // Remove a força do inimigo exibida
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------





//------------------------------------------------------------PROCURA PODERES PROXIMOS---------------------------------------------------------------


void verificarpoderesproximos(int matriz[TAMANHO][TAMANHO], int boneco_linha, int boneco_coluna) {
    if (boneco_linha > 0 && matriz[boneco_linha - 1][boneco_coluna] > 0) { // Acima
        poderproximo();
    }
    else if (boneco_linha < TAMANHO - 1 && matriz[boneco_linha + 1][boneco_coluna] > 0) { // Abaixo
        poderproximo();
    }
    else if (boneco_coluna > 0 && matriz[boneco_linha][boneco_coluna - 1] > 0) { // Esquerda
        poderproximo();
    }
    else if (boneco_coluna < TAMANHO - 1 && matriz[boneco_linha][boneco_coluna + 1] > 0) { // Direita
        poderproximo();
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------





//-------------------------------------------------------------MENU INICIAL---------------------------------------------------------------------------
void menuInicial() {
    int opcao;
    
    while (1) {
        system("cls"); // Limpa a tela
        printf("=== MENU INICIAL ===\n\n");
        printf("1. Novo Jogo\n\n");
        printf("2. Mais Informacoes\n\n");
        printf("3. Sair\n\n");
        printf("Escolha uma opcao: ");
        
        opcao = _getch(); // Lê a opção do usuário
        
        switch (opcao) {
            case '1':
                // Inicia um novo jogo
                system("cls");
                printf("Nome do Herói: ");
                fgets(jogador.nome, sizeof(jogador.nome), stdin);  // Captura o nome do jogador
                jogador.nome[strcspn(jogador.nome, "\n")] = 0; // Remove o caractere '\n' do final
                system("cls");
                printf("Iniciando Novo Jogo...\n");
                Sleep(1000); // Espera 1 segundo
                return; // Sai do menu para iniciar o jogo
                
            case '2':
                // Exibe mais informações
                system("cls");
                printf("=== MAIS INFORMAÇÕES ===\n\n");
                printf("Movimentação do personagem\n\n");
                printf("[w] Para cima\n[s] Para baixo\n[a] Para a esquerda\n[d] Para a direita\n\n");
                printf("Este é um jogo rpg que consiste em voce buscar onde estão os poderes,\ne evitar os inimigos enquanto voce ainda esta fraco.\n\nApós coletar poderes e aumentar sua força vá atrás dos inimigos e roube a força deles.\n\nCaso você enfrente um inimigo com força superior a sua, você perde.\n\n\n");
                printf("Pressione qualquer tecla para voltar ao menu.\n");
                _getch(); // Espera uma tecla ser pressionada
                break;
                
            case '3':
                // Sai do programa
                printf("Saindo...\n");
                Sleep(1000); // Espera 1 segundo
                exit(0); // Encerra o programa
                
            default:
                printf("Opcao invalida! Pressione qualquer tecla para tentar novamente.\n");
                _getch(); // Espera uma tecla ser pressionada
                break;
        }
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------





//------------------------------------------------------- COR   GAME OVER (FUNÇÃO PRONTA VERMELHO)---------------------------------------------------
		void game_over() {
	    // Muda a cor do texto para vermelho
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	    
	    // Limpa a tela
	    system("cls");
	    
	    // Exibe a mensagem
	    printf("\n\n                 GAME OVER!!\n\n  Seu inimigo foi mais forte que voce,colete\n  mais poderes e volte para vencer. \n");
	    
	    // Restaura a cor do texto para o padrão
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	    
	    // Espera 3 segundos
	    Sleep(4000);
	    
	    // Limpa a tela novamente
	    system("cls");
	    
	    
	}
	
//----------------------------------------------------------------------------------------------------------------------------------------------




//-------------------------------------------------------VERIFICAR QUANTOS INIMIGOS TEM---------------------------------------------------------

int verificarInimigosRestantes(int matriz[TAMANHO][TAMANHO]) {
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            if (matriz[i][j] < 0) { // Se houver qualquer valor negativo, significa que ainda há inimigos
                return 1; // Retorna 1 se houver inimigos restantes
            }
        }
    }
    return 0; // Retorna 0 se não houver inimigos restantes
}

//----------------------------------------------------------------------------------------------------------------------------------------------





//--------------------------------------------------------------INICIO DO JOGO-------------------------------------------------------------------
void iniciarjogo(){
  while(1){	
	jogador.forca = 0;
	memset(matriz, 0, sizeof(matriz)); // Reseta a matriz

	
	srand(time(NULL)); // aqui faz com que os "poderes" e "inimigos" estejam em lugares diferentes a cada fez que execultar o programa
	
	




//----------------------------RESPONSAVEL POR POSICIONAR ALEATORIAMENTE OS PODERES NA MATRIZ------------------------------------------------------
	
	for (i = 0; i < 4; i++){
		int linhaaleatoria = rand() % 10; // faz com que escolha uma linha aleatoria entre 10(tamanho da matriz)
		int colunaaleatoria = rand() % 10; // faz com que escolha uma coluna aleatoria entre 10(tamanho da matriz)				
	
		
		do{
			linhaaleatoria = rand() % TAMANHO; // aqui eu repito linha e coluna aleatoria para que um poder nao fique sobre o outro -
			colunaaleatoria = rand() % TAMANHO; // se ele for diferente de 0 significa que essa posição ja é um poder, entao ele vai gerar outra posição
			
						   
		}while (linhaaleatoria == 0 && colunaaleatoria == 0 ||matriz[linhaaleatoria][colunaaleatoria] != 0);
		// esse while nao deixa que o inimigo venha na posição inicial do boneco, nem que um poder fique sobre o outro
		
			   
		matriz[linhaaleatoria][colunaaleatoria] = poderes[i];		
	}
	
//--------------------------------------------------------------------------------------------------------------------------------------------------
	
	
	
	
	
//----------------------------RESPONSAVEL POR POSICIONAR ALEATORIAMENTE OS INIMIGOS NA MATRIZ-------------------------------------------------------
	
	for (i = 0; i < 4; i++){
		int linhaaleatoria = rand() % TAMANHO; // faz com que escolha uma linha aleatoria entre 10(tamanho da matriz)
		int colunaaleatoria = rand() % TAMANHO; // faz com que escolha uma coluna aleatoria entre 10(tamanho da matriz)				
	
		
		do {
			linhaaleatoria = rand() % TAMANHO; // aqui eu repito linha e coluna aleatoria para que um poder nao fique sobre o outro -
			colunaaleatoria = rand() % TAMANHO; // se ele for diferente de 0 significa que essa posição ja é um poder, entao ele vai gerar outra posição	
			
					   
		}while(linhaaleatoria == 0 && colunaaleatoria == 0 || matriz[linhaaleatoria][colunaaleatoria] != 0);
		// esse while nao deixa que o inimigo venha na posição inicial do boneco, nem que um poder fique sobre o outro
		
			   
		matriz[linhaaleatoria][colunaaleatoria] = inimigos[i]; // somente atribui o valor do inimigo a matriz
	}
		
	
//--------------------------------------------------------------------------------------------------------------------------------------------------
	




//-----------------------------------------------CHAMAR O MAPA E ATUALIZA-LO A CADA NOVA POSIÇÃO DO BONECO-------------------------------------------
		
	while(1){ // o (1) significa TRUE, entao ele vai repetir enquanto for verdadeiro
	
	
		system("cls"); // Limpa a tela a cada nova atualização do boneco no vetor
        imprimirmapa(matriz, boneco_linha, boneco_coluna);
        printf("HERÓI %s: %d\n",jogador.nome, jogador.forca);  // Exibe o nome do jogador

        
        
        char movimento = _getch(); // Essa blibioteca aqui ela vai fazer com que vc não precise apertar o ENTER. Vai aperta a letra de movimento e ja vai se mover.
        

        
        switch(movimento){
        	case 'w': // o boneco vai para cima
			case 'W': // Maiúsculo
        		if(boneco_linha > 0) boneco_linha--; // se a linha que o boneco estar é maior que 0, (ele não esta na parte de cima). Ai ele vai poder ir pra cima
        		break; // caso contrario ele para
        		
        	case 's': // o boneco vai pra baixo
        	case 'S': // Maiúsculo
        		if(boneco_linha < TAMANHO - 1) boneco_linha++; // se essa condição é verdade o boneco n vai estar na ultima linha, então ele pode descer.
        		break;
        		
        	case 'a': // o boneco vai para a esquerda
        	case 'A': // Maiúsculo
        		if(boneco_coluna > 0 ) boneco_coluna--; // ele verifica se o boneco na esta na primeira coluna, se ele nao está, ai ele pode se mover para a esquerda
        		break;
        		
        	case 'd': // o boneco vai para a direita
        	case 'D': // Maiúsculo
        		if(boneco_coluna < TAMANHO - 1) boneco_coluna++; // se o boneco nao estiver na ultima coluna, ele vai poder ir para a direita
        		break;
        		
        	default:
        		printf("As teclas de Movimento são [w] para cima  [s] para baixo [a] para a esquerda  [d] para a direita:");
        		continue;
        }
        
        verificarInimigosProximos(matriz, boneco_linha, boneco_coluna);
        
        verificarpoderesproximos(matriz, boneco_linha, boneco_coluna);
//--------------------------------------------------------------------------------------------------------------------------------------------------
        
        
        
        
        				
//------------------------------ATUALIZA A FORÇA SE O BONECO ESTIVER NA MESMA LINHA E COLUNA DO PODER-----------------------------------------------
	
	
		if (matriz[boneco_linha][boneco_coluna] > 0) {  // Ganha a força se o boneco está na mesma posição que um poder
			int poder_coletado = matriz[boneco_linha][boneco_coluna];
			recebeupoder(poder_coletado); // Passa o valor do poder coletado
            jogador.forca += poder_coletado;
		    matriz[boneco_linha][boneco_coluna] = 0; // Remove o poder após coletado
	    
		} else if (matriz[boneco_linha][boneco_coluna] < 0) {   // Perde força se o boneco está na mesma posição que um inimigo
		    if (jogador.forca + matriz[boneco_linha][boneco_coluna] < 0) {
		        game_over();
		        boneco_linha = 0; // Reinicia a posição do boneco
				boneco_coluna = 0; // Reinicia a posição do boneco
		        menuInicial();
		        break;
	        
	        
		    } else {
		    	
		    	jogador.forca -= matriz[boneco_linha][boneco_coluna]; // Atualiza a força do boneco
		    	
		        if (forca > -matriz[boneco_linha][boneco_coluna]) {
		            poder_atual -= -matriz[boneco_linha][boneco_coluna]; // Converte o valor do inimigo para um poder
		        }
		        
		        matriz[boneco_linha][boneco_coluna] = 0; // Remove o inimigo após a interação
		        venceuinimigo();
		        
    		}
		}	
		
		if (verificarInimigosRestantes(matriz) == 0) {
            win(); // Chama a função de vitória
            boneco_linha = 0; // Reinicia a posição do boneco
			boneco_coluna = 0; // Reinicia a posição do boneco	
            menuInicial();
            break; // Termina o jogo após a vitória
        }
    }
}
    
menuInicial();
	
//--------------------------------------------------------------------------------------------------------------------------------------------------



	
}

int main() {
	setlocale(LC_ALL, "");
    menuInicial(); // Exibe o menu inicial e trata a escolha do usuário
    iniciarjogo(); // Inicia o jogo após a escolha do menu
    return 0;
}