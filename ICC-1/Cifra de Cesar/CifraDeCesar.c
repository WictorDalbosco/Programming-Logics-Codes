/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
    
    // Alfabetos auxiliares
    
    //Alocação do alfabeto minúsculo
    char *alfabeto = (char *) calloc(26, sizeof(char));

    for (int i = 0; i < 26; i++){
       //Setando as letras através do memset e tabela ascii
        memset(alfabeto + i, (char)(97 + i), sizeof(char));
    }
    
    //Alocação do alfabeto maiúsculo
    char *alfabetoA = (char *) calloc(26, sizeof(char));
    
    for (int i = 0; i < 26; i++){
        //Setando as letras através do memset e tabela ascii
        memset(alfabetoA + i, (char)(65 + i), sizeof(char));
    }
    
    
    // Alocação da mensagem digitada
	char *msg = (char *) calloc(100, sizeof(char));
	
	
	//Op --> 1: encripta, 2: desencripta
	//Chave --> chave de criptografia
	// j e i --> contadores
	int op, chave, tam, j, i;

	// leitura da opção
	scanf("%d", &op);
	
	// leitura da chave
	scanf("%d\n", &chave);
	
	//Leitura da msg com essa máscar para ler tambem os espaços
	scanf("%[^\n]",msg);
	
	//Calculando o tamnho da string incluindo espaços e caracteres especiais
	tam = strlen(msg);
	
	//printf("%d \n",tam);
	
	// Opçao para encriptar ou desencriptar
	switch(op){
	    //Encriptar
	    case 1:
	        
	        //Navegando pela palavra e pelo vetor auxiliar de letras
        	for(i = 0; i < tam ; i++){
                for(j = 0; j < 26; j++){
                    //Encontrou a letra no vetor auxiliar com as letras (Minúsculas)
                    if(msg[i] == alfabeto[j]){
                        // Caso ultrapasse 26 no alfabeto
                        if(j + chave >= 26){
                            msg[i] = alfabeto[(j + chave) - 26];
                            break;
                        // Caso esteja dentro do número do alfabeto
                        }else if(j + chave < 26){
                            msg[i] = alfabeto[j + chave];
                            break;
                        }
                    //Encontrou a letra no vetor auxiliar com as letras (Maiúsculas)
                    }else if(msg[i] == alfabetoA[j]){
                        // Caso ultrapasse 26 no alfabeto
                        if(j + chave >= 26){
                            msg[i] = alfabetoA[(j + chave) - 26];
                            break;
                        // Caso esteja dentro do número do alfabeto
                        }else if(j + chave < 26){
                            msg[i] = alfabetoA[j + chave];
                            break;
                        }
                    // Caso seja espaço
                    }else if(msg[i] == ' '){
                        msg[i] = ' ';
                    // Caso seja um caractere especial 
                    }else{
                        msg[i] = msg[i];
                    }
                }    
            }
        
	    break;
	    
	    //Desencriptar
	    case 2:
	    
	    //Navegando pela palavra e pelo vetor auxiliar de letras
	    for(i = 0; i < tam ; i++){
                for(j = 0; j < 26; j++){
                    //Encontrou a letra no vetor auxiliar com as letras (Minúsculas)
                    if(msg[i] == alfabeto[j]){
                        // Caso ultrapasse 0 no alfabeto, ou seja, o valor é menor que 0
                        if(j - chave < 0){
                            msg[i] = alfabeto[(j - chave) + 26];
                            break;
                        // Caso esteja dentro do número do alfabeto, ou seja o valor não fica abaixo 
                        }else if(j - chave >= 0){
                            msg[i] = alfabeto[j - chave];
                            break;
                        }
                    //Encontrou a letra no vetor auxiliar com as letras (Maiúsculas)
                    }else if(msg[i] == alfabetoA[j]){
                         // Caso ultrapasse 0 no alfabeto, ou seja, o valor é menor que 0
                        if(j - chave < 0){
                            msg[i] = alfabetoA[(j - chave) + 26];
                            break;
                        // Caso esteja dentro do número do alfabeto, ou seja o valor não fica abaixo 
                        }else if(j - chave >= 0){
                            msg[i] = alfabetoA[j - chave];
                            break;
                        }
                    // Caso seja espaço
                    }else if(msg[i] == ' '){
                        msg[i] = ' ';
                    // Caso seja um caractere especial 
                    }else{
                        msg[i] = msg[i];
                    }
                }    
            }
	    
	    break;
	}

    //Imprime a Mensagem desencriptada ou encriptada
    printf("%s \n",msg);
    
    free(alfabeto);
    free(alfabetoA);
    free(msg);
    
    return 0;
	
}