
typedef struct
{

    	char code_precipitation[20];
    	char quantite[20];
	char mois[20] ;
	char annee[20];

}precipitation;

void ajouter_precipitation(precipitation PT);
int supprimer_precipitation(char code_sup[]);
int modif_precipitation(char code_modif[],int element,char val[] ); 
int afficher_precipitation(GtkWidget* list);
void resultat(int choix[],char text[]);
int P1_trouve(char code[]);
int int_ch(char ch[]);
int P1_trouve_mois_annee(char mois[],char annee[] );
int calcul_quantite(char annee[]);
