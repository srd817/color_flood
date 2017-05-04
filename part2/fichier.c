#include<stdio.h>
#include<termios.h>
#include<sys/types.h>
#include<sys/time.h>
#include<stdlib.h>
#include<unistd.h> 
#include<time.h>
#include<string.h>

#include "grill.h"
#include "fichier.h"

/**
 * \file fichier.c
 * \brief gestion des fichiers contenant des grilles
 * \author SVPlease
 * \version 0.1
 * \date 24 avril 2017
 */

/*
@requires 0
@assigns un nouveau fichier à un pointeur
@ensures creation /lecture du fichier text.txt
*/
/**
 * \brief creation et/ou lecture d'un fichier
 */
void creer_fichier(){
	FILE *p=fopen("text.txt","w+t");
	fclose(p);
}



/*
@requires 0
@assigns un nouveau fichier à un pointeur
@ensures creation/lecture et remplissage avec une grille entrée au clavier du fichier text.txt
*/
/**
 * \brief remplissage du fichier text.txt avec une grille entrée au clavier
 */
void input_fichier(){
    char color[]={'B','V','R','Y','M','G'};
	srand((unsigned)time(NULL));
	FILE *p=fopen("text.txt","w+t");
	int i,j,n;
	printf("choisir ligne:");
	scanf("%d",&n);
	char **str;
	str=(char **)calloc(n,sizeof(char*));
	for(i=0;i<n;i++){
		str[i]=(char *)calloc(n,sizeof(char));
		for(j=0;j<=n;j++){
			str[i][j]=color[(rand()%6)];
			if(j==n)
			str[i][j]='\n';
		}
	}
	for(i=0;i<n;i++)
		fputs(str[i],p);
	free(str);
	fclose(p);
}



/*
@requires un nom de fichier s
@assigns 0
@ensures le nombre de lignes de s
*/
/**
 * \brief décompte du nombre de lignes d'un fichier
 * \param s un pointeur vers une chaîne de caractères (nom du fichier)
 * \return n entier égal au nombre de lignes du fichier
 */
int get_line(char *s){
	FILE *p=fopen(s,"r");
	int n=0;
	int ch;  
	while((ch = fgetc(p)) != EOF) {  
        	if(ch == '\n') 
                 n++; 
        }  
        fclose(p); 
	return n;
}

/*
@requires un nom de fichier s, une grille g
@assigns réaffecte les couleurs de g
@ensures une grille dans la quelle celle du fichier s a étéé chargée
*/
/**
 * \brief extrait une grille contenue dans un fichier .txt
 * \param s un pointeur vers le nom du fichier
 * \param g un pointeur vers une grille
 * \return g la grille remplie avec les valeurs du fichier
 */
void get_grill(char* s, colorgrill *g){
	int n= g->size;
	int i;
	FILE *p=fopen(s,"r+");
	g->grill=(char **)calloc(n,sizeof(char*));
	for(i=0;i<n;i++){
		g->grill[i]=(char *)calloc(n,sizeof(char));
	}
	for(i=0;i<n;i++){
		fgets(g->grill[i],n+2,p);
	}
	g->now_color= g->grill[0][0];
	fclose(p);
}



