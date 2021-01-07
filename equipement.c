



#include<stdio.h>
#include<string.h>
#include "equipement.h"
#include <gtk/gtk.h>


enum
{

     TYPE,
     MARQUE,
     MATRICULE,
     NUM_ID,
     PUISSANCE,
     ANNEE,
     ID,
     MP,
     COLUMNS
};


void ajouter_equipement(equipement e)
{

FILE *f,*f1;
f=fopen("equipement.txt","a+");
f1=fopen("users.txt","a+");
if((f!=NULL)&&(f1!=NULL))
{
fprintf(f,"%s %s %s %s %s %s %s %s \n",e.type,e.marque,e.matricule,e.num_id,e.puissance,e.annee,e.identifiant,e.mot_pass);
fprintf(f1,"%s %s 1\n",e.identifiant,e.mot_pass);
}
fclose(f1);
fclose(f);
}



void afficher_equipement(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;

char type[25];
char marque[35];
char matricule[20];
char num_id[20];
char puissance[35];
char annee[60];

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Type",renderer, "text",TYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Marque",renderer, "text",MARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Matricule",renderer, "text",MATRICULE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" numero d'identifiant",renderer, "text",NUM_ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Puissance",renderer,"text",PUISSANCE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Année",renderer, "text",ANNEE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


}
	store=gtk_list_store_new(6,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("equipement.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("equipement.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s\n",type,marque,matricule,num_id,puissance,annee)!=EOF)
	{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,TYPE,type,MARQUE,marque,MATRICULE,matricule,NUM_ID,num_id,PUISSANCE,puissance,ANNEE,annee-1);
	}
	fclose(f);}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);


}



int supprimer_equipement(char refer[])
{
FILE *f,*f1;
equipement e;

f=fopen("equipement.txt","r");
f1=fopen("agent_tmp.txt","w");
 if ((f!=NULL) && (f1!=NULL))
{
while(fscanf(f,"%s %s %s %s %s %s\n",e.type,e.marque,e.matricule,e.num_id,e.puissance,e.annee)!=EOF)
{
if(strcmp(refer,e.matricule)!=0)
{
fprintf(f1,"%s %s %s %s %s %s\n",e.type,e.marque,e.matricule,e.num_id,e.puissance,e.annee);
}}
fclose(f) ;
fclose(f1);
}

f=fopen("equipement.txt","w");
f1=fopen("agent_tmp.txt","r");
if ((f!=NULL) && (f1!=NULL))
{
while(fscanf(f1,"%s %s %s %s %s %s\n",e.type,e.marque,e.matricule,e.num_id,e.puissance,e.annee)!=EOF)
{
if(strcmp(refer,e.matricule)!=0)
{
fprintf(f,"%s %s %s %s %s %s %s %s\n",e.type,e.marque,e.matricule,e.num_id,e.puissance,e.annee,e.identifiant,e.mot_pass);
}}
fclose(f) ;
fclose(f1);
}}

int modifier_equipement(equipement e)
{

equipement m;

FILE *f;
FILE *f2;
f=fopen("equipement.txt","r");
f2=fopen("agent_tmp.txt","a+");
if (f!=NULL)
{
if (f2!=NULL)

{
     while (fscanf(f,"%s %s %s %s %s %s\n",m.type,m.marque,m.matricule,m.num_id,m.puissance,m.annee)!=EOF)
    {
	if (strcmp(e.matricule,m.matricule)==0){
   fprintf(f2,"%s %s %s %s %s %s\n",e.type,e.marque,e.matricule,e.num_id,e.puissance,e.annee);
}
	else
{	    fprintf(f2,"%s %s %s %s %s %s\n",m.type,m.marque,m.matricule,m.num_id,m.puissance,m.annee);
     }

}}
fclose(f2);
fclose(f);
remove("equipement.txt");
rename("agent_tmp.txt","equipement.txt");

}


}


int verifier_matricule(char MATRICULE[])
{equipement e;
FILE *f;
int test = 0 ;
f=fopen("equipement.txt","r");
if(f!=NULL) {
while(fscanf(f,"%s %s %s %s %s %s\n",e.type,e.marque,e.matricule,e.num_id,e.puissance,e.annee)!=EOF)
{
if((strcmp(e.matricule,MATRICULE)==0))
test=1 ;
 } }
fclose(f);

return test;
}
