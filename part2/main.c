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
	char sta='y';
	while(sta=='y')
	{
		boucle();
		sta=statut();
	}
	return 0;
		
}
	





