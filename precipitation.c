#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "precipitation.h"

enum{
ECODE_PRECIPITATION,
EMOIS_DE_PRECIPITATION,
EANNEE_DE_PRECIPITATION,
EQUANTITE,
COLUMNS
};


void ajouter_precipitation(precipitation PT)
{
    FILE *f ;
  f=fopen("precipitation.txt","a+");
    if (f!=NULL)
	{
	fprintf(f,"%s %s %s %s\n",PT.code_precipitation,PT.quantite,PT.mois,PT.annee);

    	}
    fclose(f);

}
///////////////////////////////////////////////////////////////////
int P_trouve(char code[])
{
	FILE* f; int test=0; char ch[20];
	f=fopen("precipitation.txt","r");
if (f!=NULL)
{
	while(fscanf(f,"%s %*s %*s %*s \n",ch)!=EOF)
		{	
			if (strcmp(code,ch)==0)
				test=1;
		}
}
fclose(f);
return test;
}
///////////////////////////////////////////////////////////////////
int supprimer_precipitation(char code_sup[])
{
   FILE* fw;
    FILE* f; int test=0;
    char ch1[20],ch2[20],ch3[20],ch4[20];
    f=fopen("precipitation.txt","r"); fw=fopen("precipitation_aux.txt","a+");
    if (fw!=NULL && f!=NULL)
    {
         while (fscanf (f, "%s %s %s %s \n",ch1,ch2,ch3,ch4)!=EOF)
            {
                if (strcmp (ch1, code_sup) != 0)
                fprintf (fw,"%s %s %s %s \n",ch1,ch2,ch3,ch4);
                else
                    test=1; //supression etablie.
            }

    }
    else
        return(0) ;

    fclose(fw);
    fclose(f);
   remove("precipitation.txt");
   rename("precipitation_aux.txt","precipitation.txt");
return test;}
///////////////////////////////////////////////////////////////////
int modif_precipitation(char code_modif[],int element,char val[] )
{
FILE* fw;
    FILE* f; int test=0;

    char ch1[20],ch2[20],ch3[20],ch4[20];
    f=fopen("precipitation.txt","r"); fw=fopen("precipitation_aux.txt","a");
    if (fw!=NULL && f!=NULL)
     {
         while (fscanf (f, "%s %s %s %s \n",ch1,ch2,ch3,ch4)!=EOF)
            {
                if (strcmp (ch1, code_modif) == 0)
                {
                    test=1;
                    switch (element)
                    {

                        case 0:
                            fprintf (fw, "%s %s %s %s \n",val,ch2,ch3,ch4);
                            break;
                        case 1:
                            fprintf (fw, "%s %s %s %s \n",ch1,ch2,val,ch4);
                            break;
                        case 2:
                            fprintf (fw, "%s %s %s %s \n",ch1,ch2,ch3,val);
                            break;
                        case 3:
                            fprintf (fw, "%s %s %s %s \n",ch1,val,ch3,ch4);
                            break;
                        

                    }
                }
                    else
                     fprintf (fw, "%s %s %s %s \n",ch1,ch2,ch3,ch4);

            }

}
fclose(f); fclose(fw);
 remove("precipitation.txt");
 rename("precipitation_aux.txt","precipitation.txt");

return test;
}
///////////////////////////////////////////////////////////////////
int int_ch(char ch[])
{

if (ch[0]=='1')
	return 1;
else if (ch[0]=='2')
	return 2;
else if (ch[0]=='3')
	return 3;
else if (ch[0]=='4')
	return 4;
else if (ch[0]=='5')
	return 5;
else if (ch[0]=='6')
	return 6;
else if (ch[0]=='7')
	return 7;

else return (-1);

}
//////////////////////////////////////////////////////////////
int afficher_precipitation(GtkWidget* list)
{

GtkCellRenderer *renderer;  //envoyer la saisir de l'utilisateur de 		chaque champ 
	GtkTreeViewColumn *column;//correspendre le contenue du champ a son 		attribue de la liste
	GtkTreeIter   iter;    //itterateur sur l'ensemble des elements de 		treeview
	GtkListStore  *store;    //l'enregistrement de treeview
	FILE *f ;
	char aa [25],mm[20],qq[20],code_precipitation[20];

	store=NULL ;

	store=gtk_tree_view_get_model(list);
	if (store==NULL)
	{
	
	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Code_precipitation",renderer,"text",ECODE_PRECIPITATION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);



	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Mois ",renderer,"text",EMOIS_DE_PRECIPITATION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Annee ",renderer,"text",EANNEE_DE_PRECIPITATION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);

	renderer = gtk_cell_renderer_text_new () ;
	column = gtk_tree_view_column_new_with_attributes("Quantite",renderer,"text",EQUANTITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (list), column);


	}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("precipitation.txt","r");
if(f==NULL)
{
return;
}
else
{

f=fopen("precipitation.txt","a+");
while (fscanf(f,"%s %s %s %s \n",code_precipitation,qq,mm,aa)!=EOF)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,ECODE_PRECIPITATION,code_precipitation,EQUANTITE,qq,EMOIS_DE_PRECIPITATION,mm,EANNEE_DE_PRECIPITATION,aa,-1);

}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
g_object_unref(store);

}

}
////////////////////////////////////////////////////////////////////////////////
int P_trouve_mois_annee(char mois[],char annee[] )
{
	FILE* f; int test=0; char ch1[20],ch2[20];
	f=fopen("precipitation.txt","r");
if (f!=NULL)
{
	while(fscanf(f,"%*s %*s %s %s \n",ch1,ch2)!=EOF)
		{	
			if ((strcmp(annee,ch2)==0)&&(strcmp(mois,ch1)==0))

				test=1;
		}
}
fclose(f);
return test;
}
////////////////////////////////////////////////////////////////////////////////

int calcul_quantite(char annee[])
{
FILE* f;
int qtt=0;
int qt;
char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[20],ch7[20],ch8[20];
f=fopen("precipitation.txt","r");
if (f!=NULL)
{
         while (fscanf (f, "%s %s %s %s \n",ch1,ch2,ch3,ch4)!=EOF)
           		 {
				if (strcmp(ch4,annee)==0) 
				{qt=atoi(ch2);
				 qtt=qtt+qt;

				}

		
			 }
}
    fclose(f);

return qtt;
}
////////////////////////////////////////////////////////////////////////////////





