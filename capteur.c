#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>
#include"capteur.h"
enum 
{
	ENBRE,
	ENSERIE,
	EMARQUE,
	ETYPE,
	EETAT,
	EBI,
	EBS,
	COLUMNS,
};
enum 
{
	EID,
	EVALL,
	EDATE,
	COLUMNS1,
};




void ajouter_capt (capteur capteur)
{
FILE *f ;

f=fopen("capteur.txt","a+");

if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %d %d\n",capteur.nbre,capteur.nserie,capteur.marque,capteur.type,capteur.etat,capteur.bi,capteur.bs);

fclose(f);
}
}





//---------------------------------------------------------------------
void affiche_capt (GtkWidget *liste)
{

	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column ;
	GtkTreeIter iter ;
	GtkListStore *store ;


	char Numero[50] ;
	char N_serie[50] ;
	char Marque[50] ;
	char Type[50] ;
	char Etat[50] ;
	char Borne_inf [50]  ;
	char Borne_sup [50] ;
	//store=NULL ;

 	FILE *f ;
	capteur capteur ;
	store = gtk_tree_view_get_model ( liste );
	
	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Numero",renderer, "text", ENBRE ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("N_serie",renderer, "text", ENSERIE ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Marque",renderer, "text", EMARQUE ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type",renderer,  "text", ETYPE ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Etat",renderer,  "text", EETAT ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Borne_inf",renderer,  "text", EBI ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Borne_sup",renderer, "text", EBS ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste ),column);
	
	
	
	store = gtk_list_store_new (COLUMNS , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("capteur.txt","r");
	if(f==NULL)
	{
		return ;
	}
	else
	{
		f = fopen("capteur.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s\n",Numero,N_serie,Marque,Type,Etat,Borne_inf,Borne_sup)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter , ENBRE , Numero , ENSERIE , N_serie , EMARQUE , Marque , ETYPE , Type , EETAT , Etat ,EBI, Borne_inf ,EBS, Borne_sup,-1 );		
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW ( liste ), GTK_TREE_MODEL (store));
		g_object_unref (store);


}
}
}

//-----------------------------------------------------------------------
void modifier_capt (capteur capteur)
{

char Numero[30];
char Nserie[30];
char Marque[30];
char Type[30];
char Etat[30];
int Borne_inf;
int Borne_sup;

FILE *f ;
FILE *fi ;


f=fopen("capteur.txt","r");
fi=fopen("tempcapt.txt","w+");



if(f != NULL)
{
	if (fi != NULL )
	{
	while(fscanf(f,"%s %s %s %s %s %d 			%d\n",Numero,Nserie,Marque,Type,Etat,&Borne_inf,&Borne_sup)!=EOF)
		
	{
		if (strcmp(capteur.nbre,Numero)!=0)
			{
			fprintf(fi,"%s %s %s %s %s %d %d\n",Numero,Nserie,Marque,Type,Etat,Borne_inf,Borne_sup);
		        }
		else
 			
		{
		fprintf(fi,"%s %s %s %s %s %d %d\n",capteur.nbre,capteur.nserie,capteur.marque,capteur.type,capteur.etat,capteur.bi,capteur.bs);
	
		}
}}


	fclose(f);
	fclose(fi);	
	
		remove("capteur.txt");
		rename("tempcapt.txt","capteur.txt");
		}
	}	

//--------------------------------------------------------------------
void supp_capt(capteur capteur )
{
	char Numero[50] ;
	char N_serie[50] ;
	char Marque[50] ;
	char Type[50] ;
	char Etat[50] ;
	int Borne_inf   ;
	int Borne_sup  ;
	
	
FILE *f,*g  ;

	
	f=fopen("capteur.txt","r");
	g=fopen("tempcapt.txt","w+");
	if(g!= NULL )
		{
	if(f!= NULL )
		{
		while (fscanf(f,"%s %s %s %s %s %d %d\n",Numero,N_serie,Marque,Type,Etat,&Borne_inf,&Borne_sup)!=EOF ) 
		{
		if(strcmp(capteur.nbre,Numero)!=0)
		
			fprintf(g,"%s %s %s %s %s %d %d\n",Numero,N_serie,Marque,Type,Etat,Borne_inf,Borne_sup); 
			

		}}
		fclose(f);
		fclose(g);
		
	
		remove("capteur.txt");
		rename("tempcapt.txt","capteur.txt");
	
}}

//---------------------------------------------------------------------------


//---------------------------------------------------------------------
void ajoutehisto (histo histo)
{
FILE *fi ;

fi=fopen("histo.txt","a+");

if(fi!=NULL)
{
fprintf(fi,"%s %d %s \n",histo.id,histo.vall,histo.date);
fclose(fi);
}
}




//----------------------------------------------------------------------------

void afficherhisto (GtkWidget *liste)
{

	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column ;
	GtkTreeIter iter ;
	GtkListStore *store ;


	char Numero [50] ;
	char Valeur[50] ;
	char Date[50] ;
	
	

 	FILE *fi ;
	histo histo ;
	store = gtk_tree_view_get_model ( liste );
	
	if(store==NULL)
	{
	

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("\tNumero",renderer,"text", EID ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("\tValeur",renderer,  "text", EVALL ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("\tDate",renderer, "text", EDATE ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste ),column);
	
	
	
	store = gtk_list_store_new (COLUMNS1 , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	fi=fopen("histo.txt","r");
	if(fi==NULL)
	{
		return ;
	}
	else
	{
		fi = fopen("histo.txt","a+");
		while(fscanf(fi,"%s %s %s\n",Numero,Valeur,Date)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter , EID , Numero , EVALL , Valeur , EDATE , Date  ,-1 );		
		}
		fclose(fi);
		gtk_tree_view_set_model (GTK_TREE_VIEW ( liste ), GTK_TREE_MODEL (store));
		g_object_unref (store);


}
}
}

//-------------------------------------------------------------------
void rech_capt(capteur capteur)
{


FILE *f;
FILE *fi ;

	char Numero[50] ;
	char N_serie[50] ;
	char Marque[50] ;
	char Type[50] ;
	char Etat[50] ;
	int Borne_inf   ;
	int Borne_sup  ;

f=fopen("capteur.txt","r");
fi=fopen("rechcapteur.txt","w+");

if (f != NULL)
{
	if (fi != NULL)
	{
		 while(fscanf(f,"%s %s %s %s %s %d %d\n",Numero,N_serie,Marque,Type,Etat,&Borne_inf,&Borne_sup)!=EOF)
		{
		if(strcmp(Type,capteur.type)==0)
			{
			fprintf(fi,"%s %s %s %s %s %d %d\n ",Numero,N_serie,Marque,Type,Etat,Borne_inf,Borne_sup);
			}

}}
fclose(f);
fclose(fi);
}}
//-----------------------------------------------------------
void affiche_rech (GtkWidget *liste)
{

	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column ;
	GtkTreeIter iter ;
	GtkListStore *store ;


	char Numero[50] ;
	char N_serie[50] ;
	char Marque[50] ;
	char Type[50] ;
	char Etat[50] ;
	char Borne_inf [50]  ;
	char Borne_sup [50] ;
	//store=NULL ;

 	FILE *fi ;
	capteur capteur ;
	store = gtk_tree_view_get_model ( liste );
	
	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Numero",renderer, "text", ENBRE ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("N_serie",renderer, "text", ENSERIE ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Marque",renderer, "text", EMARQUE ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type",renderer,  "text", ETYPE ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Etat",renderer,  "text", EETAT ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Borne_inf",renderer,  "text", EBI ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Borne_sup",renderer, "text", EBS ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste ),column);
	
	
	
	store = gtk_list_store_new (COLUMNS , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	fi=fopen("rechcapteur.txt","r");
	if(fi==NULL)
	{
		return ;
	}
	else
	{
		fi = fopen("rechcapteur.txt","a+");
		while(fscanf(fi,"%s %s %s %s %s %s %s\n",Numero,N_serie,Marque,Type,Etat,Borne_inf,Borne_sup)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter , ENBRE , Numero , ENSERIE , N_serie , EMARQUE , Marque , ETYPE , Type , EETAT , Etat ,EBI, Borne_inf ,EBS, Borne_sup,-1 );		
		}
		fclose(fi);
		gtk_tree_view_set_model (GTK_TREE_VIEW ( liste ), GTK_TREE_MODEL (store));
		g_object_unref (store);


}
}
}


//-------------------------------------------------------------------------
void rech_histo(histo histo)
{


FILE *f;
FILE *g ;

	char Numero[50] ;
	int vall ;
	char date[50] ;

f=fopen("histo.txt","r");
g=fopen("rechhisto.txt","w+");

if (f != NULL)
{
	if (g != NULL)
	{
		 while(fscanf(f,"%s %d %s \n",Numero,&vall,date)!=EOF)
		{
		if(strcmp(Numero,histo.id)==0)
			{
			fprintf(g,"%s %d %s \n ",Numero,vall,date);
			}

}}
fclose(f);
fclose(g);
}}
//------------------------------------------------------------



void afficherrech (GtkWidget *liste)
{

	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column ;
	GtkTreeIter iter ;
	GtkListStore *store ;


	char Numero [50] ;
	char Valeur[50] ;
	char Date[50] ;
	
	

 	FILE *g ;
	histo histo ;
	store = gtk_tree_view_get_model ( liste );
	
	if(store==NULL)
	{
	

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("\tNumero",renderer,"text", EID ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("\tValeur",renderer,  "text", EVALL ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("\tDate",renderer, "text", EDATE ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste ),column);
	
	
	
	store = gtk_list_store_new (COLUMNS1 , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	g=fopen("rechhisto.txt","r");
	if(g==NULL)
	{
		return ;
	}
	else
	{
		g = fopen("rechhisto.txt","a+");
		while(fscanf(g,"%s %s %s\n",Numero,Valeur,Date)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter , EID , Numero , EVALL , Valeur , EDATE , Date  ,-1 );		
		}
		fclose(g);
		gtk_tree_view_set_model (GTK_TREE_VIEW ( liste ), GTK_TREE_MODEL (store));
		g_object_unref (store);


}
}
}
//--------------------------------------------------------------------------

void rech_ala(histo histo)
{


FILE *f;
FILE *g ;

	char Numero[50] ;
	int vall ;
	char date[50] ;

f=fopen("histo.txt","r");
g=fopen("ala.txt","w+");

if (f != NULL)
{
	if (g != NULL)
	{
		 while(fscanf(f,"%s %d %s \n",Numero,&vall,date)!=EOF)
		{
		if((vall>40)||(vall<10))
			{
			fprintf(g,"%s %d %s \n ",Numero,vall,date);
			}

}}
fclose(f);
fclose(g);
}}

//-----------------------------------------------------------------------------------

void afficherala (GtkWidget *liste)
{

	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column ;
	GtkTreeIter iter ;
	GtkListStore *store ;


	char Numero [50] ;
	char Valeur[50] ;
	char Date[50] ;
	
	

 	FILE *g ;
	histo histo ;
	store = gtk_tree_view_get_model ( liste );
	
	if(store==NULL)
	{
	

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("\tNumero",renderer,"text", EID ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("\tValeur",renderer,  "text", EVALL ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("\tDate",renderer, "text", EDATE ,NULL);
	gtk_tree_view_append_column ( GTK_TREE_VIEW ( liste ),column);
	
	
	
	store = gtk_list_store_new (COLUMNS1 , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	g=fopen("ala.txt","r");
	if(g==NULL)
	{
		return ;
	}
	else
	{
		g = fopen("ala.txt","a+");
		while(fscanf(g,"%s %s %s\n",Numero,Valeur,Date)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter , EID , Numero , EVALL , Valeur , EDATE , Date  ,-1 );		
		}
		fclose(g);
		gtk_tree_view_set_model (GTK_TREE_VIEW ( liste ), GTK_TREE_MODEL (store));
		g_object_unref (store);


}
}
}
int verifier_num (char NUMERO[50])

{
capteur capteur ;

	char N_serie[50] ;
	char Marque[50] ;
	char Type[50] ;
	char Etat[50] ;
	int Borne_inf   ;
	int Borne_sup  ;

FILE *f;
int test = 0 ;
f=fopen("capteur.txt","r");
if(f!=NULL) {
while(fscanf(f,"%s %s %s %s %s %d %d\n",NUMERO,N_serie,Marque,Type,Etat,&Borne_inf,&Borne_sup)!=EOF)
{
if((strcmp(capteur.nbre,NUMERO)==0))
test=1 ;
 } }
fclose(f);

return test;
}



