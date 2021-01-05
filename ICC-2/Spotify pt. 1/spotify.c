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
    double popularity;
    TRACK **trackList;
}ARTIST;

typedef struct{
    TRACK **musics;
    int nMusics;
    ARTIST **artists;
    int nArtists;
}LIBRARY;

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

void calculaPopularidade(LIBRARY *musicLibrary){
    for (int i = 0; i < musicLibrary->nArtists; i++){ //Passamos por cada artista
        musicLibrary->artists[i]->popularity = 0;
        for (int j = 0; j < musicLibrary->artists[i]->nTracks; j++){ //E agora calcularemos em todas as musicas
            musicLibrary->artists[i]->popularity += musicLibrary->artists[i]->trackList[j]->popularity;
        }
        musicLibrary->artists[i]->popularity /= musicLibrary->artists[i]->nTracks;
    }
}

void mergeSort(ARTIST **artistList,int inicio,int fim){

    if(fim <= inicio) return; //Caso base

    int meio = (inicio+fim)/2;

    //Fazemos o "merge" nas duas partes do vetor
    mergeSort(artistList,inicio,meio);
    mergeSort(artistList,meio+1,fim);

    ARTIST **aux = malloc((fim-inicio+1) * sizeof(ARTIST*));

    int i = inicio, j = meio+1, k = 0;

    while(j <= fim && i <= meio){
        //printf("A popularidade comparada em questão é:%f e %f\n",artistList[i]->popularity,artistList[j]->popularity);
        if(artistList[i]->popularity > artistList[j]->popularity){
            aux[k] = artistList[i];
            i++;
        }else{
            aux[k] = artistList[j];
            j++;
        } 
        k++;
    }

    while(i <= meio){
        aux[k] = artistList[i];
        i++;
        k++;
    }

    while(j <= fim){
        aux[k] = artistList[j];
        j++;
        k++;
    }

    for (int i = inicio, k = 0; i <= fim; i++, k++){
        artistList[i] = aux[k];
    }

    free(aux);
}

void freeLibrary(LIBRARY *musicLibrary){ //Função para liberar toda a memória
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

int main(int argc, char *argv[]){

    char *dataSetName = readLine(stdin);
    LIBRARY *musicLibrary = malloc (sizeof(LIBRARY));
    musicLibrary->nMusics = countTracks(dataSetName); //Contando inicialmente quantas músicas temos no csv

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

    calculaPopularidade(musicLibrary);
    mergeSort(musicLibrary->artists,0,musicLibrary->nArtists-1); //Ordenar com base na popularidade

    printf("O Dataset contem %d Artistas e %d Musicas\n", musicLibrary->nArtists, musicLibrary->nMusics);
    printf("Os artistas mais populares sao:\n");
    for(int i=0; i<musicLibrary->nArtists; i++){
        printf("(%d) Artista: %s, Musicas: %d musicas, Popularidade: %.2lf, Link: https://open.spotify.com/artist/%s\n", i+1,musicLibrary->artists[i]->artistName,musicLibrary->artists[i]->nTracks,musicLibrary->artists[i]->popularity,musicLibrary->artists[i]->artistId);
    }

    free(dataSetName);
    free(auxLine);
    freeLibrary(musicLibrary);

    return 0;
}