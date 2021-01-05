/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char *mazeFileName;
    FILE *pMazeFile;
    char **mazeGrid;
    int rows, col;
    int iniPosX, iniPosY;
    int annoyingPeople,validPaths,visitedPaths;
    float totalExploration;
}MAZE;

char *readLine(FILE *stream) {
    scanf(" ");

	char *string = NULL;
	int pos = 0;
	
    do{
        string = (char *) realloc(string, pos+1);
		string[pos] = (char) fgetc(stream);
		pos++;

	} while (string[pos-1] != '\n' && !feof(stream) );

	if(pos >= 2 && string[pos - 2] == '\r'){
		string[pos - 2] = '\0';
	}

	string[pos-1] = '\0';
	string = (char *) realloc(string, pos);
	
	return string;

}

void allocMaze(MAZE *maze){
   
    maze->mazeGrid = (char **) calloc (maze->rows,sizeof(char *));

    // Em seguida alocamos as colunas como sendo vários vetores associados as linhas
    for(int i = 0; i < maze->rows; i++){
        maze->mazeGrid[i]  = (char *) calloc (maze->col,sizeof(char));
    } 
    
    if (maze->mazeGrid == NULL){
        abort();
    }
}

void deallocMaze(MAZE *maze){
    int i;

    for(i=0; i < maze->rows; i++){
        free(maze->mazeGrid[i]); 
    }

    free(maze->mazeGrid);
}

void readMazeGrid(MAZE *maze){
    for (int i = 0; i < maze->rows; i++){
        for (int j = 0; j < maze->col; j++){
            
            char auxChar = fgetc(maze->pMazeFile);
            if(auxChar == '\n'){ //Para não termos '\n' incluidos
                j = j-1;
                continue;
            }else{
                maze->mazeGrid[i][j] = auxChar; //Armazenou na matriz
                if(auxChar == '#'){
                    maze->annoyingPeople++; //Contamos o números de 'barreiras'
                }
                if(auxChar == '.'){
                    maze->validPaths++; // Contamos o número de caminhos disponíveis
                }
            }       
        }    
    }    
}

void printMazeState(MAZE *maze){
    for (int i = 0; i < maze->rows; i++){
        for (int j = 0; j < maze->col; j++){
            printf("%c",maze->mazeGrid[i][j]);           
        }
        printf("\n");   
    }
}

void readMazeInfo(MAZE *maze){
    
    maze->pMazeFile = fopen(maze->mazeFileName, "r");
    
    if(maze->pMazeFile == NULL){
        printf("Arquivo não foi encontrado\n");
        free(maze->pMazeFile);
        exit(1);
    }

    fscanf(maze->pMazeFile,"%d %d",&maze->rows,&maze->col);
    fscanf(maze->pMazeFile,"%d %d\n",&maze->iniPosX,&maze->iniPosY);
    allocMaze(maze);

    readMazeGrid(maze);

    fclose(maze->pMazeFile);
}

int escapeMaze(MAZE *maze,int curPosX,int curPosY){

    //Bateu na parede ou voltou para um lugar ja visitado
    if(maze->mazeGrid[curPosX][curPosY] == '#' || maze->mazeGrid[curPosX][curPosY] == '*'){
        return 0;
    }
    
    //Visitamos um novo caminho válido
    maze->visitedPaths++;
    maze->mazeGrid[curPosX][curPosY] = '*';

    //Caso base: chegar em qualquer uma das 4 bordas
    if (curPosX == 0 || curPosX == maze->rows-1 || curPosY == 0 || curPosY == maze->col-1){
        //maze->mazeGrid[curPosX][curPosY] = '*';
        return 1;
    }

    //Vamos testar as 4 direçoes
    if(escapeMaze(maze,curPosX-1,curPosY)) return 1; // Cima

    if(escapeMaze(maze,curPosX,curPosY+1)) return 1; // Direita       
    
    if(escapeMaze(maze,curPosX+1,curPosY)) return 1; // Baixo    
    
    if(escapeMaze(maze,curPosX,curPosY-1)) return 1; // Esquerda    

    return 0;
}

void printMazeFinalStats(MAZE *maze){
    
    maze->totalExploration = floor(((float)maze->visitedPaths/(float)maze->validPaths)*100);

    printMazeState(maze);
    printf("\nVoce escapou de todos! Ninguem conseguiu te segurar!\n");
    printf("Veja abaixo os detalhes da sua fuga:\n");
    printf("----Pessoas te procurando: %d\n",maze->annoyingPeople);
    printf("----Numero total de caminhos validos:   %d\n",maze->validPaths);
    printf("----Numero total de caminhos visitados: %d\n",maze->visitedPaths);
    printf("----Exploracao total do labirinto: %.1lf%%\n",maze->totalExploration);

}

int main(int argc, char *argv[]){

    MAZE *maze = (MAZE *)calloc(1,sizeof(MAZE));
    
    maze->mazeFileName = readLine(stdin);

    readMazeInfo(maze);

    escapeMaze(maze,maze->iniPosX,maze->iniPosY);
    
    printMazeFinalStats(maze);

    deallocMaze(maze);
    free(maze->mazeFileName);
    free(maze);

    return 0;
}