/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Todas as structs utilizadas no trabalho
typedef struct{
    char *trackName;
    char *trackId;
    char *albumName;
    char *albumId;
    char *artistName;
    char *artistId;
    char *realeaseDate;
    int lenght;
    int popularity;
    double acousticness;
    double danceability;
    double energy;
    double instrumentalness;
    double liveness;
    double loudness;
    double speechiness; 
    double tempo; 
    int time_signature;
}TRACK;

typedef struct{
    char *artistName;
    char *artistId;
    int nTracks;
    //double popularity;
    TRACK **trackList;
}ARTIST;

typedef struct{
    TRACK **musics;
    int nMusics;
    ARTIST **artists;
    int nArtists;
}LIBRARY;

typedef struct{
    double distance;
    TRACK *music1;
    TRACK *music2;
}DISTANCIA;

//Readline normal por linha
char *readLine(FILE *stream) {
    scanf(" ");

	char *string = NULL;
	int pos = 0;
	
    do{
        string = (char *) realloc(string, pos+1);
		string[pos] = (char) fgetc(stream);
		pos++;

	} while (string[pos-1] != '\n' && !feof(stream));

	if(pos >= 2 && string[pos - 2] == '\r'){
		string[pos - 2] = '\0';
	}

	string[pos-1] = '\0';
	string = (char *) realloc(string, pos);
	
	return string;

}

char *getField(FILE *stream){ //Função readline modificada para pegar a cada ";" e cortar o \n
    scanf(" ");

    char *string = NULL;
	int pos = 0;
	
    do{
        string = (char *) realloc(string, pos+1);
		string[pos] = (char) fgetc(stream);
		pos++;

	} while (string[pos-1] != ';' && !feof(stream));
    fgetc(stream);

	if(pos >= 2 && string[pos - 2] == '\r'){
		string[pos - 2] = '\0';
	}

	string[pos-1] = '\0';
	string = (char *) realloc(string, pos);
	
	return string;
}

TRACK *getMusic(FILE *stream){ //Para pegar todos os parâmetros da música utilizamos esta função

    TRACK *music = malloc(sizeof(TRACK));

    //Todos os *char podem ser atribuidos diretamente
    music->trackName = getField(stream);
    music->trackId = getField(stream);
    music->albumName = getField(stream);
    music->albumId = getField(stream);
    music->artistName = getField(stream);
    music->artistId = getField(stream);
    music->realeaseDate = getField(stream);

    //Agora o resto deve ser feito o parseamento correto para o tipo indicado na struct
    char *aux = getField(stream);
    music->lenght = atoi(aux);
    free(aux);
    aux = getField(stream);
    music->popularity = atoi(aux);
    free(aux);
    aux = getField(stream);
    music->acousticness = atof(aux);
    free(aux);
    aux = getField(stream);
    music->danceability = atof(aux);
    free(aux);
    aux = getField(stream);
    music->energy = atof(aux);
    free(aux);
    aux = getField(stream);
    music->instrumentalness = atof(aux);
    free(aux);
    aux = getField(stream);
    music->liveness = atof(aux);
    free(aux);
    aux = getField(stream);
    music->loudness = atof(aux);
    free(aux);
    aux = getField(stream);
    music->speechiness = atof(aux);
    free(aux);
    aux = getField(stream);
    music->tempo = atof(aux);
    free(aux);
    aux = getField(stream);
    music->time_signature = atoi(aux);
    free(aux);
    fgetc(stream); // pega o \n 

    return music;
}

void insertMusic(LIBRARY *musicLibrary,int currentSong){ //Função para inserir a música em seu devido artista

    for (int i = 0; i < musicLibrary->nArtists; i++){ 
        if(strcmp(musicLibrary->musics[currentSong]->artistId,musicLibrary->artists[i]->artistId) == 0){ //Procurando se já tem musicas do artista da musica na base
            
            musicLibrary->artists[i]->nTracks++; //Aumentou o número de músicas do artista
            int aux = musicLibrary->artists[i]->nTracks;
            musicLibrary->artists[i]->trackList = realloc(musicLibrary->artists[i]->trackList,aux * sizeof(TRACK**));
            musicLibrary->artists[i]->trackList[aux-1] = musicLibrary->musics[currentSong];
            
            return;
        }
    }

    //Caso o artista ainda não esteja na base, criamos um
    musicLibrary->nArtists++;
    musicLibrary->artists = realloc(musicLibrary->artists,musicLibrary->nArtists * sizeof(ARTIST*));
    musicLibrary->artists[musicLibrary->nArtists-1] = malloc(sizeof(ARTIST));
    musicLibrary->artists[musicLibrary->nArtists-1]->nTracks = 1; //First song eeeh :)
    //Copiamos então as informações para o artista
    musicLibrary->artists[musicLibrary->nArtists-1]->artistId = musicLibrary->musics[currentSong]->artistId;
    musicLibrary->artists[musicLibrary->nArtists-1]->artistName = musicLibrary->musics[currentSong]->artistName;
    //Atribuindo a primeira música
    musicLibrary->artists[musicLibrary->nArtists-1]->trackList = malloc(sizeof(TRACK*));
    musicLibrary->artists[musicLibrary->nArtists-1]->trackList[0] = musicLibrary->musics[currentSong];
}

int countTracks(char *csvName){ //Função para somente contar o numero de faixas no csv
    FILE *pCSV_File = fopen(csvName,"r");
    int nTracks = 0;

    //Consumir a primeira linha
    char *linhaInicial = readLine(pCSV_File);
    free(linhaInicial);

    while(!feof(pCSV_File)){ //Navegar pelo csv

        char *line = readLine(pCSV_File);

        if(line[0] == 0){free(line);break;} //Caso a linha não contenha nada saimos

        free(line);
          
        nTracks++;//Aumentou uma música da biblioteca 
       
    }

    fclose(pCSV_File);

    return nTracks;

}

//Mergesort por trackId
void mergeSort(TRACK **tracks,int inicio,int fim){

    if(fim <= inicio) return; //Caso base

    int meio = (inicio+fim)/2;

    //Fazemos o "merge" nas duas partes do vetor
    mergeSort(tracks,inicio,meio);
    mergeSort(tracks,meio+1,fim);

    TRACK **aux = malloc((fim-inicio+1) * sizeof(TRACK*));

    int i = inicio, j = meio+1, k = 0;

    while(j <= fim && i <= meio){
        //printf("A id comparada em questão é:%s e %s\n",tracks[i]->trackId,tracks[j]->trackId);
        if(strcmp(tracks[i]->trackId,tracks[j]->trackId)<0){
            aux[k] = tracks[i];
            i++;
        }else{
            aux[k] = tracks[j];
            j++;
        } 
        k++;
    }

    while(i <= meio){
        aux[k] = tracks[i];
        i++;
        k++;
    }

    while(j <= fim){
        aux[k] = tracks[j];
        j++;
        k++;
    }

    for (int i = inicio, k = 0; i <= fim; i++, k++){
        tracks[i] = aux[k];
    }

    free(aux);
}

void freeLibrary(LIBRARY *musicLibrary){ //Função para liberar toda a memória da biblioteca
    for (int i = 0; i < musicLibrary->nMusics; i++){
        free(musicLibrary->musics[i]->trackName);
        free(musicLibrary->musics[i]->trackId);
        free(musicLibrary->musics[i]->albumName);
        free(musicLibrary->musics[i]->albumId);
        free(musicLibrary->musics[i]->artistName);
        free(musicLibrary->musics[i]->artistId);
        free(musicLibrary->musics[i]->realeaseDate);
        free(musicLibrary->musics[i]);
    }
    for (int i = 0; i < musicLibrary->nArtists; i++){
        free(musicLibrary->artists[i]->trackList);
        free(musicLibrary->artists[i]);
    }
    free(musicLibrary->musics);
    free(musicLibrary->artists);
    free(musicLibrary);   
}


double calculaDistancia(TRACK *s1, TRACK *s2){ //Calcula distancia euclidiana entre atributos de song1 e song2
    double d = sqrt(pow(s1->acousticness-s2->acousticness,2)+pow(s1->danceability-s2->danceability,2)+
                    pow(s1->energy-s2->energy,2)+pow(s1->instrumentalness-s2->instrumentalness,2)+
                    pow(s1->liveness-s2->liveness,2)+pow(s1->loudness-s2->loudness,2)+pow(s1->speechiness-s2->speechiness,2)+
                    pow(s1->tempo-s2->tempo,2)+pow(s1->time_signature-s2->time_signature,2));
    return d;
}

DISTANCIA **alocaMatriz(int dimensao){
    DISTANCIA **matriz = (DISTANCIA **)calloc(dimensao,sizeof(DISTANCIA*));

    for (int i = 0; i < dimensao; i++){
        matriz[i] = (DISTANCIA *)calloc(dimensao,sizeof(DISTANCIA));
    }
    
    return matriz;  
}

void desalocaMatriz(DISTANCIA **matriz,int dimensao){
    for (int i = 0; i < dimensao; i++){ 
        free(matriz[i]);
    }
    free(matriz);  
}

DISTANCIA **montarMatrizDissimilaridade(TRACK **tracks,int nTracks){

    DISTANCIA **matriz = alocaMatriz(nTracks);

    for (int i = 0; i < nTracks; i++){
        for (int j = 0; j < (i+1); j++){
            matriz[i][j].distance = calculaDistancia(tracks[i],tracks[j]);
            matriz[i][j].music1 = tracks[i];
            matriz[i][j].music2 = tracks[j];
                
            matriz[j][i].distance = matriz[i][j].distance;
            matriz[j][i].music1 = tracks[j];
            matriz[j][i].music2 = tracks[i];
            
        }
    }

    return matriz;
}

int buscaBinariaRecursiva(DISTANCIA **matriz,int inicio, int fim, char *idChave){
	if (fim >= inicio){
		int meio = inicio + (fim - inicio)/2;
        
		if (strcmp(matriz[meio]->music1->trackId,idChave) == 0) return meio;
			
		if (strcmp(matriz[meio]->music1->trackId,idChave) > 0){
			return buscaBinariaRecursiva(matriz,inicio,meio-1,idChave);
		}
		return buscaBinariaRecursiva(matriz,meio+1,fim,idChave);
	}
	return -1;
}

void radixSort_256(DISTANCIA *vetor, int N){
    //Utilizaremos a base 256
    int C[256] = {0};
    int pos[256];
    DISTANCIA *vetorCopia = (DISTANCIA*) malloc(sizeof(DISTANCIA)*N);

    for(int shift = 0; shift <= 24; shift+=8){
        //contagem + cópia
        for(int j = 0; j < N; j++){
            int P = 1000000;
            short k = ((int)round(vetor[j].distance * P) >> shift) & 255;
            C[k]++;
            vetorCopia[j] = vetor[j];
        }
        //contagem acumulada
        pos[0] = 0;
        for(int i = 1; i < 256; i++){
            pos[i] = pos[i-1] + C[i-1];
            C[i-1] = 0;
        }
        //copio os elementos na posição correta
        for(int j = 0; j < N; j++){
            int P = 1000000;
            short k = ( (int)round(vetorCopia[j].distance * P) >> shift ) & 255;
            vetor[pos[k]] = vetorCopia[j];
            pos[k]++;
        }
    }

    free(vetorCopia);
}

void printMostSimilarTracks(TRACK **tracks,DISTANCIA **M, int index, int K){
    printf("----As %d musicas mais parecidas com %s sao:\n", K, tracks[index]->trackName);
    for (int i = 0; i < K; i++){
        printf("\t(%d)Artista: %s\n", i,M[index][i].music2->artistName);
        printf("\t\tMusica: %s\n", M[index][i].music2->trackName);
        printf("\t\tDissimilaridade: %lf\n", M[index][i].distance);
        printf("\t\tLink: https://open.spotify.com/track/%s\n", M[index][i].music2->trackId);
    }
    printf("\n");
}

int main(int argc, char *argv[]){

    char *dataSetName = readLine(stdin);
    LIBRARY *musicLibrary = malloc (sizeof(LIBRARY));
    musicLibrary->nMusics = countTracks(dataSetName); //Contando inicialmente quantas músicas temos no csv
    int musicasBuscadas = 0,musicasSimilares = 0; 

    //Inicializando o acervo musical
    musicLibrary->nArtists = 0;
    musicLibrary->artists = NULL;
    musicLibrary->musics = malloc(musicLibrary->nMusics * sizeof(TRACK*));

    FILE *pCSV_File = fopen(dataSetName,"r");
    char *auxLine = readLine(pCSV_File); // consumir primeira linha
    for (int i = 0; i < musicLibrary->nMusics; i++){
        musicLibrary->musics[i] = getMusic(pCSV_File); //Pegar uma música
        insertMusic(musicLibrary,i); //Adicionar ela ao artista 
    }
    fclose(pCSV_File);

    mergeSort(musicLibrary->musics,0,musicLibrary->nMusics-1); //Ordenar TODAS as tracks com base no trackId


    DISTANCIA **matrizDissimilaridade = montarMatrizDissimilaridade(musicLibrary->musics,musicLibrary->nMusics);
         
    scanf("%d %d",&musicasBuscadas,&musicasSimilares);

    //Vamos fazer as recomendacoes
    for (int i = 0; i < musicasBuscadas; i++){
        char *idMusicaBuscada = readLine(stdin);
        int pos = buscaBinariaRecursiva(matrizDissimilaridade,0,musicLibrary->nMusics-1,idMusicaBuscada);

        if(pos != -1){
            radixSort_256(matrizDissimilaridade[pos],musicLibrary->nMusics);
            printMostSimilarTracks(musicLibrary->musics,matrizDissimilaridade,pos,musicasSimilares);
        }
        free(idMusicaBuscada);
    }

    //Area de desalocação de memoria heap
    desalocaMatriz(matrizDissimilaridade,musicLibrary->nMusics);
    free(dataSetName);
    free(auxLine);
    freeLibrary(musicLibrary);

    return 0;
}