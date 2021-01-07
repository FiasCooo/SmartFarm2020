#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
#include <string.h>


//-----------------------------------------------------------------------------------

void
on_buttonajout_clicked                 (GtkWidget       *objet_graphique,
                                       gpointer         user_data)
{
capteur capteur ;
GtkWidget *Ajouter  ;
GtkWidget *gestion_capteur ;

gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
gtk_widget_destroy(gestion_capteur) ;
Ajouter=lookup_widget(objet_graphique,"Ajouter");
Ajouter=create_Ajouter();

gtk_widget_show(Ajouter);
}
//-----------------------------------------------------------------------


void
on_buttoncomfirmer_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
capteur capteur ;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7;
GtkWidget *Ajouter ,*e ,*e1 ;
GtkWidget *gestion_capteur ;
GtkWidget *wbatreeviewcapteur , *output ;
Ajouter=lookup_widget(objet_graphique,"Ajouter");

input1=lookup_widget(objet_graphique,"entrynum");
input2=lookup_widget(objet_graphique,"entrynserie");
input3=lookup_widget(objet_graphique,"entrymarque");
e=lookup_widget(objet_graphique,"comboboxtype");
input5=lookup_widget(objet_graphique,"spinbuttonbi");
input6=lookup_widget(objet_graphique,"spinbuttonbs");
e1=lookup_widget(objet_graphique,"comboboxetat");


strcpy(capteur.nbre,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(capteur.nserie,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(capteur.marque,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(capteur.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(e)));
capteur.bi=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
capteur.bs=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
strcpy(capteur.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(e1)));

ajouter_capt(capteur);
/*gtk_widget_destroy(Ajouter) ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);
wbatreeviewcapteur=lookup_widget(gestion_capteur,"wbatreeviewcapteur");
affiche_capt(wbatreeviewcapteur);*/
output=lookup_widget(objet_graphique,"label102");
gtk_label_set_text(GTK_LABEL(output),"ajouté avec succés");
}


//-----------------------------------------------------------

void
on_wbatreeviewcapteur_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	  
GtkWidget *gestion_capteur, *supprimer , *wbatreeviewcapteur ;
GtkTreeIter iter ;
gchar* entrynum ;
gchar* entrynserie ;
gchar* entrymarque ;
gchar* entrytype ;
gchar* entrybi ;
gchar* entrybs ;
gchar* entryetat ;
capteur capteur ;
char fichier[]={"capteur.txt"};


GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path))
{
	gtk_tree_model_get (GTK_LIST_STORE (model), &iter , 0 , &entrynum ,  1 ,&entrynserie, 2 , &entrymarque , 3 , &entrytype ,4 ,&entryetat, 5 , &entrybi, 6 , &entrybs,   -1);
	strcpy(capteur.nbre,entrynum);
	strcpy(capteur.nserie,entrynserie);
	strcpy(capteur.marque,entrymarque);
	strcpy(capteur.type,entrytype);
	strcpy(capteur.etat,entryetat);
	strcpy(capteur.bi,entrybi);
	strcpy(capteur.bs,entrybs);
	
	wbatreeviewcapteur=lookup_widget(gestion_capteur,"wbatreeviewcapteur");
	affiche_capt(wbatreeviewcapteur);
}

}




//---------------------------------------------------------







//-----------------------------------------------------------------------




void
on_gestion_capteur_show                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajouter ;
GtkWidget *gestion_capteur ;




}

//--------------------------------------------------

void
on_buttonannuler_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajouter , *wbatreeviewcapteur ;
GtkWidget *gestion_capteur ;
Ajouter=lookup_widget(objet_graphique,"Ajouter");

gtk_widget_destroy(Ajouter) ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);
wbatreeviewcapteur=lookup_widget(gestion_capteur,"wbatreeviewcapteur");
affiche_capt(wbatreeviewcapteur);
}
//--------------------------------------------------------------------

void
on_buttonajouhisto_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouthisto ;
GtkWidget *gestion_capteur ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");

gtk_widget_destroy(gestion_capteur) ;
ajouthisto=lookup_widget(objet_graphique,"ajouthisto");
ajouthisto=create_ajouthisto();

gtk_widget_show(ajouthisto);
}
//---------------------------------------------------------------------------

void
on_buttonaffhisto_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affichehisto ;
GtkWidget *gestion_capteur ;
GtkWidget *treeviewhisto ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");

gtk_widget_destroy(gestion_capteur) ;
affichehisto=lookup_widget(objet_graphique,"affichehisto");
affichehisto=create_affichehisto();
gtk_widget_show(affichehisto);
treeviewhisto=lookup_widget(affichehisto,"treeviewhisto");
afficherhisto(treeviewhisto);


}
//---------------------------------------------------------------------------

void
on_buttoncomfirmerhisto_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
histo histo ;
GtkWidget *input1,*input2,*input3 ;
GtkWidget *ajouthisto , *output ;
ajouthisto=lookup_widget(objet_graphique,"ajouthisto");

input1=lookup_widget(objet_graphique,"entryhistonum");
input2=lookup_widget(objet_graphique,"entryhistodate");
input3=lookup_widget(objet_graphique,"spinbuttonval");



strcpy(histo.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(histo.date,gtk_entry_get_text(GTK_ENTRY(input2)));
histo.vall=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));

ajoutehisto(histo);
output=lookup_widget(objet_graphique,"label106");
gtk_label_set_text(GTK_LABEL(output),"ajouté avec succés");
}

//---------------------------------------------------------------------
void
on_buttonannuler2_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouthisto , *wbatreeviewcapteur ;
GtkWidget *gestion_capteur ;
ajouthisto=lookup_widget(objet_graphique,"ajouthisto");

gtk_widget_destroy(ajouthisto) ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);
wbatreeviewcapteur=lookup_widget(gestion_capteur,"wbatreeviewcapteur");
affiche_capt(wbatreeviewcapteur);
}

//------------------------------------------------------------------------------
void
on_treeviewhisto_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter ;
gchar* entryhistonum ;
gchar* entryhistodate ;
gchar* entryhistoval;

histo histo ;
char fichier[]={"histo.txt"};


GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter, path))
{
	gtk_tree_model_get (GTK_LIST_STORE (model), &iter , 0 , &entryhistonum ,  1 ,&entryhistodate, 2 , &entryhistoval, -1);
	strcpy(histo.id,entryhistonum);
	strcpy(histo.date,entryhistodate);
	strcpy(histo.vall,entryhistoval);
	
	afficherhisto(treeview);
}
}


//------------------------------------------------------------------

void
on_buttonannulerhist_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affichehisto ,*wbatreeviewcapteur ;
GtkWidget *gestion_capteur ;
affichehisto=lookup_widget(objet_graphique,"affichehisto");

gtk_widget_destroy(affichehisto) ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);
wbatreeviewcapteur=lookup_widget(gestion_capteur,"wbatreeviewcapteur");
affiche_capt(wbatreeviewcapteur);
}
//------------------------------------------------------------------------------
void
on_buttonmodif_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *numodif ; 
GtkWidget *gestion_capteur , *modifier ;


gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");

gtk_widget_destroy(gestion_capteur) ;
modifier=lookup_widget(objet_graphique,"modifier");
modifier=create_modifier();

gtk_widget_show(modifier);

}



//--------------------------------------------------------------------------------



void
on_buttonannuler1_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifier, *wbatreeviewcapteur ;
GtkWidget *gestion_capteur ;
modifier=lookup_widget(objet_graphique,"modifier");

gtk_widget_destroy(modifier) ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
gestion_capteur=create_gestion_capteur();
gtk_widget_show(gestion_capteur);
wbatreeviewcapteur=lookup_widget(gestion_capteur,"wbatreeviewcapteur");
affiche_capt(wbatreeviewcapteur);
}

//--------------------------------------------------------------------------


void
on_affiche_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouthisto ;
GtkWidget *affichehisto ;
GtkWidget *treeviewhisto ;
ajouthisto=lookup_widget(objet,"ajouthisto");

gtk_widget_destroy(ajouthisto) ;
affichehisto=lookup_widget(objet,"affichehisto");
affichehisto=create_affichehisto();

gtk_widget_show(affichehisto);
treeviewhisto=lookup_widget(affichehisto,"treeviewhisto");
afficherhisto(treeviewhisto);
}
//-----------------------------------------------------------------------------------

void
on_buttonsupp_clicked                  (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_capteur ;
GtkWidget *supprimer ;

gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
gtk_widget_destroy(gestion_capteur) ;
supprimer=lookup_widget(objet_graphique,"supprimer");
supprimer=create_supprimer();

gtk_widget_show(supprimer);
}
//------------------------------------------------------------------------




void
on_buttoncomfsupp_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
capteur capteur ; 
char Numero[50];

GtkWidget *gestion_capteur , *supprimer ,*input1 ;
GtkWidget *wbatreeviewcapteur ,*output ;

input1=lookup_widget(objet,"numsupp");
strcpy(capteur.nbre,gtk_entry_get_text(GTK_ENTRY(input1)));


supp_capt(capteur);
//gtk_widget_destroy(supprimer) ;
/*gestion_capteur=lookup_widget(objet,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);

wbatreeviewcapteur=lookup_widget(gestion_capteur,"wbatreeviewcapteur");
affiche_capt(wbatreeviewcapteur);*/
output=lookup_widget(objet,"label101");
gtk_label_set_text(GTK_LABEL(output),"supprimé avec succés");

}


void
on_buttonretour_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_capteur ;
GtkWidget *supprimer ;
GtkWidget *wbatreeviewcapteur ;
supprimer=lookup_widget(objet_graphique,"supprimer");
gtk_widget_destroy(supprimer) ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);
wbatreeviewcapteur=lookup_widget(gestion_capteur,"wbatreeviewcapteur");
affiche_capt(wbatreeviewcapteur);
}


void
on_refresh_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_capteur ;
GtkWidget *wbatreeviewcapteur ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
gtk_widget_destroy(gestion_capteur) ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);
wbatreeviewcapteur=lookup_widget(gestion_capteur,"wbatreeviewcapteur");
affiche_capt(wbatreeviewcapteur);
}


/*void
on_OK_clicked                          (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1 ;
GtkWidget *numodif ;
GtkWidget *modifier ;
capteur capteur ;



input1=lookup_widget(objet,"entrynumodif");
strcpy(capteur.nbre,gtk_entry_get_text(GTK_ENTRY(input1)));

gtk_widget_destroy(numodif) ;
modifier=lookup_widget(objet,"modifier");
modifier=create_modifier();

gtk_widget_show(modifier);



}*/

void
on_buttoncomfirmer1_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
capteur capteur ;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7;
GtkWidget *modifier ,*c ,*c1;
GtkWidget *gestion_capteur, *numodif ;
GtkWidget  *wbatreeviewcapteur , *output ;	
char fichier[]={"capteur.txt"};




modifier=lookup_widget(objet_graphique,"modifier");

input1=lookup_widget(objet_graphique,"entrynum1");
input2=lookup_widget(objet_graphique,"entrynserie1");
input3=lookup_widget(objet_graphique,"entrymarque1");
c=lookup_widget(objet_graphique,"comboboxtype1");
input5=lookup_widget(objet_graphique,"spinbuttonbi1");
input6=lookup_widget(objet_graphique,"spinbuttonbs1");
c1=lookup_widget(objet_graphique,"comboboxetat1");



strcpy(capteur.nbre,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(capteur.nserie,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(capteur.marque,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(capteur.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(c)));
capteur.bi=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
capteur.bs=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
strcpy(capteur.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(c1)));



modifier_capt(capteur);

/*gtk_widget_destroy(modifier) ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
gestion_capteur=create_gestion_capteur();

gtk_widget_show(gestion_capteur);

wbatreeviewcapteur=lookup_widget(gestion_capteur,"wbatreeviewcapteur");
affiche_capt(wbatreeviewcapteur);*/
output=lookup_widget(objet_graphique,"label103");
gtk_label_set_text(GTK_LABEL(output),"modifié avec succés");

}












void
on_Aff_clicked                         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

char NUMERO[20];
int test;
char f[]={"capteur.txt"};
capteur capteur ;
GtkWidget *entrymarque1, *entrynserie1 , *entrynum1 ,*c ,*c1 ,*input1 ,*input2 ,*input3  ;
GtkWidget *modifier;
GtkWidget *output;
modifier=lookup_widget(objet_graphique,"modifier");
input1=lookup_widget(objet_graphique,"entrynum1");
input2=lookup_widget(objet_graphique,"entrynserie1");
input3=lookup_widget(objet_graphique,"entrymarque1");
//lookup_widget(objet_graphique,"comboboxtype1")=c;
//input5=lookup_widget(objet_graphique,"spinbuttonbi1");
//input6=lookup_widget(objet_graphique,"spinbuttonbs1");
//lookup_widget(objet_graphique,"comboboxetat1")=c1;
//output= lookup_widget(objet_graphique,"label1");
strcpy(NUMERO,gtk_entry_get_text(GTK_ENTRY(entrynum1)));
if (verifier_num(NUMERO)==0)
//gtk_label_set_text(GTK_LABEL(output),"equipement n'existe pas");
//else
//{

{
if (f!=NULL)
{while (fscanf(f,"%s %s %s %s %s %d %d\n",capteur.nbre,capteur.nserie,capteur.marque,capteur.type,capteur.etat,capteur.bi,capteur.bs)!=EOF)
{if (strcmp(capteur.nbre,NUMERO)==0) 
{/* gtk_widget_show(modifier);
gtk_entry_set_text(GTK_ENTRY(entrynserie1),capteur.nserie) ;
	gtk_entry_set_text(GTK_ENTRY(entrymarque1),capteur.marque) ;
	//gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxtype1),capteur.type) ;
  // gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxetat1),capteur.etat) ;
//gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonbi1),capteur.bi) ;
  //   gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonbs1),capteur.bs) ;
*/
}}
//}
fclose(f);
}}	
gtk_widget_destroy(modifier) ;
	modifier=lookup_widget(objet_graphique,"modifier");
	modifier=create_modifier();
	gtk_widget_show(modifier);

}	// gtk_widget_show(window6);




void
on_buttonchercher_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
capteur capteur ;
GtkWidget *gestion_capteur , *wbatreeviewcapteur ,*input1 ;
gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");

char fichier[]={"rechcapteur.txt"};
char fichier1[]={"capteur.txt"};





	gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
	input1=lookup_widget(objet_graphique,"entryrech");
	strcpy(capteur.type,gtk_entry_get_text(GTK_ENTRY(input1)));

	rech_capt(capteur) ;
	gtk_widget_destroy(gestion_capteur) ;
	gestion_capteur=lookup_widget(objet_graphique,"gestion_capteur");
	gestion_capteur=create_gestion_capteur();
	gtk_widget_show(gestion_capteur);
	wbatreeviewcapteur=lookup_widget(gestion_capteur,"wbatreeviewcapteur");
	affiche_rech(wbatreeviewcapteur);
}







void
on_buttoncherchisto_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

histo histo ;
GtkWidget *ajouthisto ;
GtkWidget *affichehisto ;
GtkWidget *treeviewhisto , *input1 ;
affichehisto=lookup_widget(objet_graphique,"affichehisto");

char fichier[]={"rechhisto.txt"};
char fichier1[]={"histo.txt"};





	affichehisto=lookup_widget(objet_graphique,"affichehisto");
	input1=lookup_widget(objet_graphique,"entryrech1");
	strcpy(histo.id,gtk_entry_get_text(GTK_ENTRY(input1)));

	rech_histo(histo) ;
	gtk_widget_destroy(affichehisto) ;
	affichehisto=lookup_widget(objet_graphique,"affichehisto");
	affichehisto=create_affichehisto();
	gtk_widget_show(affichehisto);
	treeviewhisto=lookup_widget(affichehisto,"treeviewhisto");
	afficherrech(treeviewhisto);
}


void
on_buttonala_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

histo histo ;
GtkWidget *ajouthisto ;
GtkWidget *affichehisto ;
GtkWidget *treeviewhisto , *input1 ;
affichehisto=lookup_widget(objet_graphique,"affichehisto");

char fichier[]={"ala.txt"};
char fichier1[]={"histo.txt"};





	affichehisto=lookup_widget(objet_graphique,"affichehisto");
	rech_ala(histo) ;
	gtk_widget_destroy(affichehisto) ;
	affichehisto=lookup_widget(objet_graphique,"affichehisto");
	affichehisto=create_affichehisto();
	gtk_widget_show(affichehisto);
	treeviewhisto=lookup_widget(affichehisto,"treeviewhisto");
	afficherala(treeviewhisto);

}


void
on_ref_clicked                         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affichehisto ;
GtkWidget *treeviewhisto ;
affichehisto=lookup_widget(objet_graphique,"affichehisto");
gtk_widget_destroy(affichehisto) ;
affichehisto=lookup_widget(objet_graphique,"affichehisto");
affichehisto=create_affichehisto();

gtk_widget_show(affichehisto);
treeviewhisto=lookup_widget(affichehisto,"treeviewhisto");
afficherhisto(treeviewhisto);
}

