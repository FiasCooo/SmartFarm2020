enum{
NOM,
CODE_PLANTE,
JOUR_DE_PLANTATION,
MOIS_DE_PLANTATION,
ANNEE_DE_PLANTATION,
ETAT,
STOCK,
TYPE,
COLUMNS,
};





#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plantation.h"
#include <gtk/gtk.h>





void ajouter_plantation(plantation p)
{FILE *f ;
f=fopen("plantation.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %d %d %d %s %s %s \n ",p.nom,p.code_plante,p.d.jour,p.d.mois,p.d.annee,p.etat,p.stock,p.type);
fclose(f);
}
}


void afficher_plantation (GtkWidget* list)
{
GtkCellRenderer *renderer;  //envoyer la saisir de l'utilisateur de 		chaque champ 
	GtkTreeViewColumn *column;//correspendre le contenue du champ a son 		attribue de la liste
	GtkTreeIter   iter;    //itterateur sur l'ensemble des elements de 		treeview
	GtkListStore  *store;    //l'enregistrement de treeview
	FILE *f ;
        char nom[20];
  	char code_plante[20];
        char jour[20];
	char mois[20];
	char annee[20];
        char etat[20];
        char stock[20];
	char type[20];
	
	
	
	
	store=NULL ;

	store=gtk_tree_view_get_model(list);
	if (store==NULL)
	{
	


        renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Code_Plante",renderer,"text",CODE_PLANTE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);


        renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR_DE_PLANTATION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",MOIS_DE_PLANTATION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",ANNEE_DE_PLANTATION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

       
        renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

       
        renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Stock",renderer,"text",STOCK,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);



	
	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

	
	
	

	}
store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("plantation.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("plantation.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s \n" ,nom,code_plante,jour,mois,annee,etat,stock,type)!=EOF)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,NOM,nom,CODE_PLANTE,code_plante,JOUR_DE_PLANTATION, jour,MOIS_DE_PLANTATION,mois,ANNEE_DE_PLANTATION,annee,ETAT,etat,STOCK,stock,TYPE,type,-1);

}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
g_object_unref(store);

}
}


void modifier_plantation(plantation p)
{

char nom[30];
char cp[30];
int jour , mois , annee ;
char type[30];
char etat[30];
char stock[30];


FILE *f ;
FILE *fi ;


f=fopen("plantation.txt","r");
fi=fopen("plantation2.txt","w+");



if(f != NULL)
{
if (fi != NULL )
{
while(fscanf(f,"%s %s %d %d %d %s %s %s\n",nom,cp,&jour,&mois,&annee,etat,stock,type)!=EOF)

{
if (strcmp(p.code_plante,cp)!=0)
{
fprintf(fi,"%s %s %d %d %d %s %s %s\n",nom,cp,jour,mois,annee,etat,stock,type);
}
else
 
{
fprintf(fi,"%s %s %d %d %d %s %s %s\n",p.nom,p.code_plante,p.d.jour,p.d.mois,p.d.annee,p.etat,p.stock,p.type);

}
}}


fclose(f);
fclose(fi);

remove("plantation.txt");
rename("plantation2.txt","plantation.txt");
}
} 




int verifier_cin(char CIN[])
{plantation p;
FILE *f;
int test = 0 ; 
f=fopen("plantation.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%s %s %s %s %s %s\n",p.nom,p.code_plante,p.d.jour,p.d.mois,p.d.annee,p.etat,p.stock,p.type)!=EOF) 
{ 
if((strcmp(p.code_plante,CODE_PLANTE)==0))
test=1 ;
 } }
fclose(f);
 
return test;
}


void supprimer_plantation(plantation p)
{
char ch1[20];
char ch2[20];
int a;
int b;
int c;
char ch3[20];
char ch4[20];
char ch5[20];
FILE *f;
FILE *f1;
 
f=fopen("plantation.txt","r");

f1=fopen("plantation_1.txt","w");
while(fscanf(f,"%s %s %d %d %d %s %s %s \n ",ch1,ch2,&a,&b,&c,ch3,ch4,ch5)!=EOF)
{
if(strcmp(ch2,p.code_plante)!=0)

fprintf(f1,"%s %s %d %d %d %s %s %s \n",ch1,ch2,a,b,c,ch3,ch4,ch5);
}
fclose(f);
fclose(f1);
remove("plantation.txt");
rename("plantation_1.txt","plantation.txt");

}

/*int P_trouve(char code_plante[])
{
	FILE* f; int test=0; char ch[20];
	f=fopen("plantation.txt","r");
if (f!=NULL)
{
	while(fscanf(f,"%*s %s %*d %*d %*d %*s %*s %*s\n",ch)!=EOF)
		{	
			if (strcmp(code_plante,ch)==0)
				test=1;
		}
}
fclose(f);
return test;
}*/


void afficher_rech (GtkWidget* list)
{
GtkCellRenderer *renderer;  //envoyer la saisir de l'utilisateur de 		chaque champ 
	GtkTreeViewColumn *column;//correspendre le contenue du champ a son 		attribue de la liste
	GtkTreeIter   iter;    //itterateur sur l'ensemble des elements de 		treeview
	GtkListStore  *store;    //l'enregistrement de treeview
	FILE *f ;
        char nom[20];
  	char code_plante[20];
        char jour[20];
	char mois[20];
	char annee[20];
        char etat[20];
        char stock[20];
	char type[20];
	
	
	
	
	store=NULL ;

	store=gtk_tree_view_get_model(list);
	if (store==NULL)
	{
	


        renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Code_Plante",renderer,"text",CODE_PLANTE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);


        renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR_DE_PLANTATION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",MOIS_DE_PLANTATION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",ANNEE_DE_PLANTATION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

       
        renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

       
        renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Stock",renderer,"text",STOCK,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);



	
	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

	
	
	

	}
store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("recherche.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("recherche.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s \n" ,nom,code_plante,jour,mois,annee,etat,stock,type)!=EOF)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,NOM,nom,CODE_PLANTE,code_plante,JOUR_DE_PLANTATION, jour,MOIS_DE_PLANTATION,mois,ANNEE_DE_PLANTATION,annee,ETAT,etat,STOCK,stock,TYPE,type,-1);

}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
g_object_unref(store);

}
}

void rech_p(plantation p)
{


FILE *f;
FILE *fi ;

char Nom[50] ;
char code_plante[50] ;
int  jour,mois,annee;
char etat[50] ;
char stock[50]  ;
char type[50] ;

f=fopen("plantation.txt","r");
fi=fopen("recherche.txt","w+");

if (f != NULL)
{
if (fi != NULL)
{
while(fscanf(f,"%s %s %d %d %d %s %s %s\n",Nom,code_plante,&jour,&mois,&annee,etat,stock,type)!=EOF)
{
if(strcmp(type,p.type)==0)
{
fprintf(fi,"%s %s %d %d %d %s %s %s \n ",Nom,code_plante,jour,mois,annee,etat,stock,type);
}

}}
fclose(f);
fclose(fi);
}}













