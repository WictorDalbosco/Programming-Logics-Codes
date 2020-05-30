/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Definindo um enum para tipo booleano
enum bool{
    false,
    true
};

typedef enum bool BOOL;

//Definindo um struct do tipo Livro
struct Book {
    char *name;
    int daysLeft;
    BOOL isBorrowed;
}; //12 bytes

typedef struct Book BOOK;

//Função readLine
char *readLine(FILE *stream) {
    scanf(" ");

	char *string = NULL;

    //Posição do ponteiro do stream
	int pos = 0;
	
    do {
		//Alocamos um byte
        string = (char *) realloc(string, pos+1);

        //Lemos um caractere do stream e colocamos na string em sua respectiva 
        //posição
		string[pos] = (char) fgetc(stream);

        //Próximo caractere
		pos++;

	} while (string[pos-1] != '\n' && !feof(stream));


	//Checar se não há nenhuma quebra de linha 
	if(pos >= 2 && string[pos - 2] == '\r'){
		string[pos - 2] = '\0';
	}

    //Limpamos o \n que vier incluido no stream
	string[pos-1] = '\0';

    //Realocamos para o novo tamanho da string
	string = (char *) realloc(string, pos);
	
	return string;
    free(string);

}

//Funcao para ordenar os livros conforme solicitada a exclusao
void ordenarLivros(BOOK **alugados,int *posicao, int indiceExclusao){
    int i = 0;
    //A partir do indice de exclusao iremos mover todos para um indice atrás
    for( i = indiceExclusao; i < *posicao; ++i){
        //Ja esta na última posição
        if(i + 1 == *posicao){
            break;
        }
        alugados[i]=alugados[i + 1];
    }
    //Agora os livros alugados nao tem mais o mesmo de número de antes
    *posicao = *posicao - 1;
}

//Função para alugar livros
void alugarLivro(FILE *stream, BOOK **book, int qtdLivros, BOOK **alugados,int *posicao){
   
   //Recebemos a pesquisa e lemos com a readline
   char *nome1 = readLine(stream);
    
   //Indice --> achou o livro nesse indice
   //Count --> contamos pelos livros da biblioteca, se = 0, não achou o livro 
   // buscado pelo usuário
   int indice = 0, count = 0;

    //For para navegar pelos livros
    for(int j = 0; j < qtdLivros; j++){

        //Checando se é o mesmo livro
        if((strcmp(nome1,book[j]->name) == 0)){
            count++;
            //Achou nesse indice
            indice = j;
        }
               
    }

    //Não não é o mesmo Livro
    if(count == 0){
        printf("Livro nao encontrado na biblioteca\n");
        free(nome1);
        return;
    }else if(*posicao >= 10){
        printf("Voce ja tem 10 livros alugados\n");
        free(nome1);
        return;
    }else if(book[indice]->isBorrowed == 1){
        printf("Livro ja alugado\n");
        free(nome1);
        return;
    }else{
        printf("%s alugado com sucesso\n",book[indice]->name);
        book[indice]->isBorrowed = 1;

        //Copiamos para o nosso acervo 
        alugados[*posicao] = book[indice];

        //Aumento a quantidade de livros alugados
        *posicao = *posicao + 1;

        free(nome1);
        return;
    } 

}    

//Mostra livros alugados
void mostrarAlugados(BOOK **alugados, int *posicao){

    if(*posicao == 0){
        printf("Voce nao tem livros alugados\n");
        return;
    }else {
        printf("Voce tem %d livro(s) alugado(s)\n",*posicao);
        for(int i = 0; i < *posicao; i++){
            if(alugados[i]->isBorrowed == 1){
                printf("Livro nome: %s\n",alugados[i]->name);
                printf("Devolve-lo daqui %d dias\n",alugados[i]->daysLeft);
            }
        } 
        return;
    }

}

//Devolve um livro
void devolverLivro(FILE *stream, BOOK **book, int qtdLivros, BOOK **alugados, int *posicao){
    char *nome1 = readLine(stream);
    int i = 0;
    
    //For para navegar pelos nossos livros
    for(int j = 0; j < *posicao; j++){
       i = 0;
       //Comparando strings dos livros enquanto forem as mesmas
        while(nome1[i] == alugados[j]->name[i]){
            //Se elas tiverem os terminadores na mesma posição, são a mesma string
            if(nome1[i] == '\0' || alugados[j]->name[i] == '\0'){
                break;
            }
            i++;
        }
        if(nome1[i] == '\0' && alugados[j]->name[i] == '\0'){
            if(alugados[j]->isBorrowed == 1){
                printf("Livro %s foi devolvido com sucesso\n",alugados[j]->name);
                alugados[j]->isBorrowed = 0;
                ordenarLivros(alugados,posicao,j);
                
                free(nome1);
                return;

            }else{
                printf("Voce nao possui esse livro\n");

                free(nome1);
                return;
            }
        } 
    }  
    printf("Voce nao possui esse livro\n");
    free(nome1);
    return;
}

int main(int argc, char *argv[]){
    //Quantidade de livros da biblioteca
    //Op -> operação a ser realizada
    int qtdLivros, op = 0;
    //Aux para para pegar o int como char com a readLine
    char *aux;
    //**book -> acervo de livros
    //**alugados -> meus livros alugados
    BOOK **book, **alugados;
    //Ponteiro para mostrar qual posicao deve-se alocar o próximo livro
    int posicao = 0;
    
    //Lendo a quantidade de livros coma readLine
    aux = readLine(stdin);
    qtdLivros = atoi(aux);
    //printf("qtdLivro: %d\n",qtdLivros);   
    
    //Alocando o acervo na memória heap
    book = (BOOK **)malloc(sizeof(BOOK *) * qtdLivros);
    if(book == NULL){
        printf("Não foi alocado o array\n");
    }
    
    //Alocando os livros no acervo
    for(int i = 0; i < qtdLivros; i++){
        book[i]= (BOOK *)calloc(1,sizeof(BOOK));
        if(book[i] == NULL){
            printf("Não alocou o livro\n");
        }
    }

    //Fazendo uma lista de livros para o cliente com 10 espaços
    alugados = (BOOK **)malloc(sizeof(BOOK *) * 10);
    if(alugados == NULL){
        printf("Não foi alocado o array\n");
    }
 
    //Alocando esses livros que serão depois alugados
    for(int i = 0; i < 10; i++){
        alugados[i] = NULL;

    } 

    //Pegando os atributos do livros
    for(int i = 0; i< qtdLivros; i++){
        book[i]->name = readLine(stdin);
        scanf("%d",&book[i]->daysLeft);
        getchar();
    }

    while (op != 4){
        scanf("%d",&op);
        //Limpar buffer
        getchar();

        switch (op){
        //Buscar livro
        case 1:
            printf("Digite o livro que voce procura:\n");
            alugarLivro(stdin,book,qtdLivros,alugados, &posicao); 
            break;
        
        //Mostrar alugados
        case 2:
            mostrarAlugados(alugados, &posicao);
        break;

        //Devolver livro
        case 3:
            printf("Digite o livro que deseja devolver:\n");
            devolverLivro(stdin,book,qtdLivros,alugados, &posicao);
        break;
        
        default:
            break;
        }
    }

    printf("Programa finalizado\n");

    //Desalocando os livros
    for(int i = 0; i < qtdLivros; i++){
        free(book[i]->name);
        free(book[i]);
    }
    
    free(book);
    free(alugados);
    free(aux);

    return 0;
}