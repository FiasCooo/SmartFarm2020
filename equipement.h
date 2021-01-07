#include <gtk/gtk.h>
typedef struct
{
char type[25];
char marque[35];
char matricule[20];
char num_id[20];
char puissance[35];
char annee[60];
char identifiant[60];
char mot_pass[60];
}equipement;
void ajouter_equipement(equipement e);
void afficher_equipement(GtkWidget *liste);
int supprimer_equipement(char refer[]);
int modifier_equipement(equipement e);
int verifier_matricule(char MATRICULE[]);

