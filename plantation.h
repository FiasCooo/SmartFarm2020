#include<gtk/gtk.h>

typedef struct date 
{int jour;
 int mois;
 int annee;
}DATE; 
typedef struct plantation
{  char nom [50];
   char code_plante[50];
   char etat[50];
   char stock[50];
   char type[50];
   DATE d;
   
}plantation;
 
 void ajouter_plantation(plantation p);
 void afficher_plantation (GtkWidget* list);
void modifier_plantation(plantation p);
void supprimer_plantation(plantation p);
void rech_p(plantation p);
void afficher_rech(GtkWidget* list);
int verifier_cin(char CODE_PLANTE[]);

