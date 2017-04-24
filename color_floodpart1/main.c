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
 * \file main.c
 * \brief fichier de la fonction principale (boucle de jeu)
 * \author SVPlease
 * \date 24 avril 2017
 */
 
 

/*
@requires None
@assigns None
@return None
*/
/**
 * \brief fonction principale (boucle du jeu)
 */
int main(){
	colorgrill g;
	int i,n=0,s=0;
	printf("please input size:");
	scanf("%d",&n);
	printf("nombre de coups autorisé:");
	scanf("%d",&s);
	g=creat(n);
	init(&g);
	print_grill(&g);
	for(i=1;i<=s;i++){
		system("clear");
		printf("%d / %d\n",i,s);
		print_grill(&g);
		int x,y;
		printf("choisir la case de coordonnées (x,y)\n");
		printf("x=:");
		scanf("%d",&x);
		printf("y=:");
		scanf("%d",&y);
		char c= get_color(&g,x,y);
		printf("%c \n",c);
		change(&g,c,1,1);
		g.now_color=c;
	}
	print_grill(&g);
	status(&g);
	gfree(&g);
	
	char str[]="text.txt";
	printf("\n");
	input_fichier();
	n =get_line(str);
	change_size(n,&g);
	get_grill(str,&g);
	print_grill(&g);
}




