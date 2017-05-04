#include<stdio.h>
#include<string.h>
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
#include "boucle.h"

/**
 * \file boucle.c
 * \brief La boucle principale du jeu et les fonctions necessaires a son fonctionnement.
 * \author SVPlease
 * \date 02 mai 2017
 */

/**  
* \brief fait la lecture clavier de la taille de la grille
* \return n l'entier entré par l'utilisateur  
*/
int size(){
	int n;
	printf("taille de la grille ? ");
	scanf("%d",&n);	
	return n;
}

/**
 * \brief  fait la lecture clavier du nombre de coups autorisés entré par l'utilisateur
 * \return s l'entier entré par l'utilisateur
 */
int coups(){
	int s;
	printf("nombre de coups autorisé ? ");
	scanf("%d",&s);
	return s;
}

/**
 * \brief fait la lecture clavier du choix entré par l'utilisateur pour une nouvelle partie
 * \return c le caractère entré par l'utilisateur
 */
char statut(){
	char c;
	printf("rejouer ? (y/n):\n");
	scanf(" %c",&c);
	printf("%c\n",c);
	system("clear");
	return c;
}

/**
 * \brief boucle principale du jeu
 */
void boucle()
{
	colorgrill g;
	int i,n=0,s=0;
	int sta;
	char c=' ';
	n= size();
	s= coups();
	g=creat(n);
	init(&g);
	system("clear");
	for(i=1;i<=s;i++){
		printf("%d / %d\n",i,s);
		printf("la couleur choisie est %c \n",c);
		print_grill(&g);
		int x,y;
		while(1){
			printf("choisir la case de coordonnées (x,y)\n");
			printf("ligne:(<=%d)\n",n);
			scanf("%d",&x);
			printf("colonne:(<=%d)\n",n);
			scanf("%d",&y);			
			if( x>n ||y>n )
			    printf("size error,encore une foi!\n");
			else 
			    break;
		}
		c= get_color(&g,x,y);
		printf("%c\n",c);
		change(&g,c,1,1);
		g.now_color=c;
		sta=status(&g);
		if(sta>0)
		break;
		system("clear");
	}
	print_grill(&g);
	if(sta!=0)
		printf("victoire\n");
	else
		printf("défaite\n");
	printf("fin.\n");
	gfree(&g);
}

