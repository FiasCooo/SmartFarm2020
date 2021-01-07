#include<gtk/gtk.h>

typedef struct capteur
{
char nbre[50] ;
char nserie[50] ;
char marque[50] ;
char type[50] ;
char etat[50] ;
int bi  ;
int bs  ;
}capteur;


typedef struct 
{
char id [50] ;
int vall  ;
char date [50] ;
}histo ;




int verifier_num (char NUMERO[]);
void ajouter_capt ();
void affiche_capt (GtkWidget *liste);
void modifier_capt ();
void supp_capt (wbatreeviewcapteur);
void ajoutehisto (histo histo) ;
void afficherhisto (GtkWidget *liste) ;
void rech_capt() ;
void rech_histo();
void rech_ala();
void afficherrech(GtkWidget *liste);
void affiche_rech(GtkWidget *liste);
void afficherala(GtkWidget *liste);
