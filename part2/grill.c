#include<stdio.h>
#include<termios.h>
#include<sys/types.h>
#include<sys/time.h>
#include<stdlib.h>
#include<unistd.h> 
#include<time.h>
#include<string.h>

#include "grill.h"

/**
 * \file grill.c
 * \brief contient les fonctions qui créent, remplissent et gèrent une grille de couleurs
 * \author SVPlease
 * \date 24 avril 2017
 */



/*
@requires: un entier n, taille de la grille 
@assigns: 0
@ensures: créé la grille de jeu à la bonne taille
*/
/**
 * \brief crée une grille vide de taille n
 * \param n un entier taille de la grille
 * \return g la grille initialisée
*/
colorgrill creat(int n){
	colorgrill g;
	g.size=n;
	g.now_color=' ';
	return g;
}



/*
@requires une grille
@assigns vide la place mémoire de la grille
@ensures: free la mémoire prise par la grille
*/
/**
 * \brief vide la place mémoire allouée à une grille
 * \param g un pointeur vers une grille
*/
void gfree(colorgrill *g){
	free(g->grill);
}


/*
@requires une grille de jeu
@assigns assigne les couleurs dans la grille dans la mémoire
@ensures initialise la grille avec des couleurs aléatoires
*/
/**
 * \brief remplit une grille donnée avec des coulaurs choisies aléatoirement
 * \param g un pointeur vers une grille
*/
void init(colorgrill *g){
	char color[]={'B','V','R','Y','M','G'};
	srand((unsigned)time(NULL));
	int i,j;
	int n=g->size;
	g->grill=(char **)calloc(n,sizeof(char *));
	for(i=0;i<n;i++){
		g->grill[i]=(char *)calloc(n,sizeof(char));
		for(j=0;j<n;j++)
			g->grill[i][j]=color[(rand()%6)];
	}
	g->now_color=g->grill[0][0];
}



/*
@requires: un entier pour changer la taille de la grille, une grille
@assigns: 0
@ensures: change la taille de la grille à la taille n
*/
/**
 * \brief change la taille d'une grille de couleurs
 * \param n un entier nouvelle taille de la grille
 * \param g un pointeur vers la grille à modifier
*/
void change_size(int n, colorgrill *g){
	g->size=n;
}



/*
@requires une grille de jeu
@assigns 0
@ensures affichage de la grille
*/
/**
 * \brief affichage en terminal d'une grille
 * \param g un pointeur vers une grille
*/
void print_grill(colorgrill *g){
	int i,j;
	int n=g->size;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf(" %c ",g->grill[i][j]);
		printf("\n");
	}
}


/*
@requires une grille de jeu, x le numéro d'une ligne et y le numéro d'une colonne
@assigns 0
@ensures retourne la couleur de la case de la grille aux coordonnées x et y
*/
/**
 * \brief donne la valeur de la case dans g de coordonnées x et y
 * \param g un pointeur vers une grille
 * \param x un entier
 * \param y un entier
 * \return char la valeur de la case de coordonnees x et y
*/
char get_color(colorgrill *g,int x,int y) {
	return g->grill[x-1][y-1];
}



/*
@requires une grille g, une couleur, les coordonnées x et y
@assigns réassigne la case mémoire d'une couleur
@ensures la case de coordonnées x et y dans g prend la couleur passée en argument
*/
/**
 * \brief la case de coordonnées x et y dans g prend la valeur passée en argument
 * \param g un pointeur vers une grille
 * \param x un entier
 * \param y un entier
 * \param color un caratère
*/
void change_color(colorgrill *g,char color,int x,int y) {
	g->grill[x-1][y-1]=color;
}


/*
@requires une grille, une couleur, deux entiers x et y
@assigns réassigne les cases mémoire de la grille pour leur donner une nouvelle couleur
@ensures une nouvelle grille dont le groupe 4-connexe en haut à gauche a pris la couleur des coordonnées x et y
*/
/**
 * \brief effectue le changement de couleur de la tâche 4-connexe située en haut à gauche de la grille ers la couleur de la grille se trouvant aux coordonnées x et y
 * \param g un pointeur vers une grille
 * \param x un entier
 * \param y un entier
*/
void change(colorgrill *g, char color,int x, int y){
	int n=g->size;
	char c=g->now_color;
	if(g->grill[x-1][y-1]==c && c!=color){
		g->grill[x-1][y-1]=color;
		if(x!=1)
			change(g,color,x-1,y);
		if(x!=n)
			change(g,color,x+1,y);
		if(y!=1)
			change(g,color,x,y-1);
		if(y!=n)
			change(g,color,x,y+1);
	}
}



/*
@requires une grille
@assigns 0
@ensures vérifie les conditions de victoire pour la grille
*/
/**
 * \brief vérifie si la victoire est acquise
 * \param g un pointeur vers une grille
*/
int status(colorgrill *g){
	int n=g->size;	
	int sta=1;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(g->grill[i][j]!=g->now_color)
				sta=0;
	return sta;
}


