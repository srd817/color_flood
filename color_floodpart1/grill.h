#ifndef _GRILL_H
#define _GRILL_H



/**
 * \struct colorgrill
 * \brief structure d'une grille de couleurs
 */
struct colorgrill {
	int size;				/*!< taille de la grille */
	char now_color;			/*!< couleur en haut à gauche de la grille */
	char **grill;			/*!< tableau de char de taille size*size */
};
typedef struct colorgrill colorgrill;

colorgrill creat(int n);
void gfree(colorgrill *g);
void init(colorgrill *g);
void print_grill(colorgrill *g);
char get_color(colorgrill *g,int x,int y);
void change_color(colorgrill *g,char color,int x,int y);
void change(colorgrill *g, char color,int x, int y);
void status(colorgrill *g);

#endif