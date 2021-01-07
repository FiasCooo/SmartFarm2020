#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "plantation.h"
#include "precipitation.h"


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* code_plante;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* etat;
gchar* stock;
gchar* type;
plantation p;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter,path))
{
//obtenir les valeurs de la ligne selectionnée

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&code_plante,2,&jour,3,&mois,4,&annee,5,&etat,6,&stock,7,&type,-1);

//copie dans e
    strcpy(p.nom,nom);
    strcpy(p.code_plante,code_plante);
    strcpy(p.code_plante,code_plante);
    strcpy(p.d.jour,jour);
    strcpy(p.d.mois,mois);
    strcpy(p.d.annee,annee);
    strcpy(p.etat,etat);
    strcpy(p.stock,stock);
    strcpy(p.type,type);




//*appel de la fct de suppression
//*supprimer_plant(code_plant);//
//màj du treeview
afficher_plantation(treeview);



}
}


void
on_button1_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
ajouter = create_ajouter (); 
gtk_widget_show (ajouter);
}


void
on_button2_modifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menuprincipale;
 GtkWidget *modifier1;
menuprincipale=lookup_widget(objet,"menuprincipale");

gtk_widget_destroy(menuprincipale);
modifier1=lookup_widget(objet,"modifier1");
modifier1=create_modifier1();
gtk_widget_show(modifier1);

}


void
on_button3_ajouter_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3;
 GtkWidget *T, *E;
 GtkWidget *JOUR;
 GtkWidget *MOIS;
 GtkWidget *ANNEE;
 plantation p;
 GtkWidget *ajouter;
 FILE *f=NULL;
 
ajouter=lookup_widget(objet_graphique,"ajouter");
input1=lookup_widget(objet_graphique,"entry_nom");
input2=lookup_widget(objet_graphique,"entry_code");
JOUR=lookup_widget(objet_graphique,"jour");
MOIS=lookup_widget(objet_graphique,"mois");
ANNEE=lookup_widget(objet_graphique,"annee");
E=lookup_widget(objet_graphique,"combobox_etat");
input3=lookup_widget(objet_graphique,"entry_stock");
T=lookup_widget(objet_graphique,"combobox_type");
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.code_plante,gtk_entry_get_text(GTK_ENTRY(input2)));
p.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JOUR));
p.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MOIS));
p.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ANNEE));
strcpy(p.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(E)));
strcpy(p.stock,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(T)));

ajouter_plantation(p);
}


void
on_button4_afficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
GtkWidget *modifier;
GtkWidget *modifier1;
GtkWidget *menuprincipale;
GtkWidget *treeview;

ajouter=lookup_widget(objet,"ajouter");
gtk_widget_destroy(ajouter);
modifier=lookup_widget(objet,"modifier");
gtk_widget_destroy(modifier);
modifier1=lookup_widget(objet,"modifier1");
gtk_widget_destroy(modifier1);
menuprincipale=lookup_widget(objet,"menuprincipale");
menuprincipale=create_menuprincipale();
gtk_widget_show (menuprincipale);
treeview=lookup_widget(menuprincipale,"treeview");
afficher_plantation(treeview);
}


void
on_button5_modifier_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
char CODE_PLANTE[20];
int test;
plantation p;
plantation m;
GtkWidget *input1,*input2,*input3,*entry22_code;
GtkWidget *S;
GtkWidget *T1, *E1;
GtkWidget *JOUR;
GtkWidget *MOIS;
GtkWidget *ANNEE;
GtkWidget *modifier1,*modifier;
GtkWidget *output;
char fichier[]={"plantation.txt"};
modifier=lookup_widget(objet_graphique,"modifier");
input1=lookup_widget(objet_graphique,"entry1_nom");
input2=lookup_widget(objet_graphique,"entry1_code");
JOUR=lookup_widget(objet_graphique,"jour1");
MOIS=lookup_widget(objet_graphique,"mois1");
ANNEE=lookup_widget(objet_graphique,"annee1");
E1=lookup_widget(objet_graphique,"combobox1_etat");
input3=lookup_widget(objet_graphique,"entry1_stock");
T1=lookup_widget(objet_graphique,"combobox1_type");
/*if (verifier_cin(CODE_PLANTE)!=0)
gtk_label_set_text(GTK_LABEL(output),"agent n'existe pas");*/
/*else
{*/ 
		// gtk_widget_show(window6);


strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.code_plante,gtk_entry_get_text(GTK_ENTRY(input2)));
p.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JOUR));
p.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MOIS));
p.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ANNEE));
strcpy(p.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(E1)));
strcpy(p.stock,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(T1)));
modifier_plantation(p);

}



void
on_button6_afficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
GtkWidget *modifier;
GtkWidget *modifier1;
GtkWidget *menuprincipale;
GtkWidget *treeview;

ajouter=lookup_widget(objet,"ajouter");
gtk_widget_destroy(ajouter);
modifier=lookup_widget(objet,"modifier");
gtk_widget_destroy(modifier);
modifier1=lookup_widget(objet,"modifier1");
gtk_widget_destroy(modifier1);
menuprincipale=lookup_widget(objet,"menuprincipale");
menuprincipale=create_menuprincipale();
gtk_widget_show (menuprincipale);
treeview=lookup_widget(menuprincipale,"treeview");
afficher_plantation(treeview);
}


void
on_button500_modifier_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input2;
 plantation p;
 GtkWidget *modifier1;
 GtkWidget *modifier;
input2=lookup_widget(objet_graphique,"entry22_code");
strcpy(p.code_plante,gtk_entry_get_text(GTK_ENTRY(input2)));
modifier1=lookup_widget(objet_graphique,"modifier1");
gtk_widget_destroy(modifier1);
modifier=lookup_widget(objet_graphique,"modifier");
modifier=create_modifier();
gtk_widget_show(modifier);

}

	
/*GtkWidget *windowb3;
		GtkWidget *windowb6;
		windowb3=lookup_widget(objet_graphique,"windowb3");	
		windowb6 = create_windowb6();
		gtk_widget_destroy(windowb3);
		gtk_widget_show(windowb6);*/


/*GtkWidget *input;
GtkWidget *output;
GtkWidget *windowb2, *windowb4;
agent g;
char refer[20];
input=lookup_widget(objet_graphique,"entryb9");
output=lookup_widget(objet_graphique,"label1");
strcpy(refer,gtk_entry_get_text(GTK_ENTRY(input)));
if(strcmp(refer,g.cin)==0)
gtk_label_set_text(GTK_LABEL(output),"client n'existe pas");
else
{
modifier_agent(refer);
gtk_label_set_text(GTK_LABEL(output),"suppression avec succée");
windowb4=lookup_widget(objet_graphique,"windowb6");

windowb2=lookup_widget(objet_graphique,"windowb3");
gtk_widget_hide(windowb2);
windowb4 = create_windowb4();
gtk_widget_show (windowb4);
}*/


/////////////






void
on_button1_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
supprimer = create_supprimer (); 
gtk_widget_show (supprimer);
}


void
on_button_supprimer_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
plantation p;
GtkWidget  *input2;



input2=lookup_widget(objet_graphique,"entry22_code");

strcpy(p.code_plante,gtk_entry_get_text(GTK_ENTRY(input2)));

supprimer_plantation(p);
}


void
on_button333_afficher_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
GtkWidget *modifier;
GtkWidget *modifier1;
GtkWidget *supprimer;
GtkWidget *menuprincipale;
GtkWidget *treeview;

ajouter=lookup_widget(objet,"ajouter");
gtk_widget_destroy(ajouter);
modifier=lookup_widget(objet,"modifier");
gtk_widget_destroy(modifier);
modifier1=lookup_widget(objet,"modifier1");
gtk_widget_destroy(modifier1);
supprimer=lookup_widget(objet,"supprimer");
gtk_widget_destroy(supprimer);
menuprincipale=lookup_widget(objet,"menuprincipale");
menuprincipale=create_menuprincipale();
gtk_widget_show (menuprincipale);
treeview=lookup_widget(menuprincipale,"treeview");
afficher_plantation(treeview);
}


void
on_button_chercher_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
plantation p ;
GtkWidget *menuprincipale , *treeview ,*input1 ;
menuprincipale=lookup_widget(objet_graphique,"menupricipale");

char fichier[]={"recherche.txt"};
char fichier1[]={"plantation.txt"};





menuprincipale=lookup_widget(objet_graphique,"menuprincipale");
input1=lookup_widget(objet_graphique,"entry1_rech");
strcpy(p.type,gtk_entry_get_text(GTK_ENTRY(input1)));

rech_p(p) ;
gtk_widget_destroy(menuprincipale) ;
menuprincipale=lookup_widget(objet_graphique,"menuprincipale");
menuprincipale=create_menuprincipale();
gtk_widget_show(menuprincipale);
treeview=lookup_widget(menuprincipale,"treeview");
afficher_rech(treeview);
}



void
on_button1_retour_clicked              (GtkWidget       *objet,

                                        gpointer         user_data)
{
GtkWidget *menuprincipal ;
menuprincipal=create_menuprincipale();
gtk_widget_show (menuprincipal);

}


void
on_button2_retour_clicked              (GtkWidget       *objet,

                                        gpointer         user_data)
{
GtkWidget *modifier1 ;
modifier1=create_modifier1();
gtk_widget_show (modifier1);

}


void
on_button3_retour_clicked              (GtkWidget       *objet,

                                        gpointer         user_data)
{
GtkWidget *ajouter ;
ajouter=create_ajouter();
gtk_widget_show (ajouter);

}


void
on_button4_retour_clicked              (GtkWidget       *objet,

                                        gpointer         user_data)
{
GtkWidget *modifier ;
modifier=create_modifier();
gtk_widget_show (modifier);
}


void
on_button_refresh_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menuprincipale ;
GtkWidget *treeview ;
menuprincipale=lookup_widget(objet_graphique,"menuprincipale");
gtk_widget_destroy(menuprincipale) ;
menuprincipale=lookup_widget(objet_graphique,"menuprincipale");
menuprincipale=create_menuprincipale();
gtk_widget_show (menuprincipale);
treeview=lookup_widget(menuprincipale,"treeview");
afficher_plantation(treeview);


}


void
on_afficher_precipitation_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowaffich ;
GtkWidget *fenetre_ajout;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet,"ajout_precipitation");
gtk_widget_destroy(fenetre_ajout);
windowaffich=lookup_widget(objet,"affichage_precipitation");

GtkWidget *windowpr1,* windowpr2,* windowpr3,* windowpr4;
windowpr1=lookup_widget(objet,"ajout_precipitation");
gtk_widget_destroy(windowpr1);
windowpr2=lookup_widget(objet,"modif_precipitation");
gtk_widget_destroy(windowpr2);
windowpr3=lookup_widget(objet,"supprimer_precipitatio");
gtk_widget_destroy(windowpr3);
windowpr4=lookup_widget(objet,"acceuil_precipitation");
gtk_widget_destroy(windowpr4);

windowaffich=create_affichage_precipitation();
gtk_widget_show (windowaffich);

treeview1=lookup_widget(windowaffich,"treeview1");
afficher_precipitation(treeview1);
}


void
on_supprimer_precipitation_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprim_precipitation ;

GtkWidget *windowpr1,* windowpr2,* windowpr3,* windowpr4;
windowpr1=lookup_widget(objet,"acceuil_precipitation");
gtk_widget_destroy(windowpr1);
windowpr2=lookup_widget(objet,"ajout_precipitation");
gtk_widget_destroy(windowpr2);
windowpr3=lookup_widget(objet,"modif_precipitation");
gtk_widget_destroy(windowpr3);
windowpr4=lookup_widget(objet,"affichage_precipitation");
gtk_widget_destroy(windowpr4);


supprim_precipitation=create_supprimer_precipitatio();
gtk_widget_show (supprim_precipitation);
}


void
on_modifier_precipitation_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modif_prcipitation ;

GtkWidget *windowpr1,* windowpr2,* windowpr3,* windowpr4;
windowpr1=lookup_widget(objet,"acceuil_precipitation");
gtk_widget_destroy(windowpr1);
windowpr2=lookup_widget(objet,"ajout_precipitation");
gtk_widget_destroy(windowpr2);
windowpr3=lookup_widget(objet,"supprimer_precipitatio");
gtk_widget_destroy(windowpr3);
windowpr4=lookup_widget(objet,"affichage_precipitation");
gtk_widget_destroy(windowpr4);

modif_prcipitation=create_modif_precipitation();
gtk_widget_show (modif_prcipitation);
}


void
on_ajouter_precipitation_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout_precipitation ;

GtkWidget *windowpr1,* windowpr2,* windowpr3,* windowpr4;
windowpr1=lookup_widget(objet,"acceuil_precipitation");
gtk_widget_destroy(windowpr1);
windowpr2=lookup_widget(objet,"modif_precipitation");
gtk_widget_destroy(windowpr2);
windowpr3=lookup_widget(objet,"supprimer_precipitatio");
gtk_widget_destroy(windowpr3);
windowpr4=lookup_widget(objet,"affichage_precipitation");
gtk_widget_destroy(windowpr4);

ajout_precipitation=create_ajout_precipitation();
gtk_widget_show (ajout_precipitation);
}


void
on_valider_precipitation_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
FILE* f;precipitation PT; char ch[50];
int j,m,a,mon; char chj[20],chm[20],cha[20],chs[20],text[20];
int test1 , test2;
   
    GtkWidget *C,*QA,*M,*A,*pt;
    GtkWidget *ajouter_precipitation1;
    ajouter_precipitation1=lookup_widget(objet,"ajout_precipitation");
    C=lookup_widget(objet,"entry_code_precipitation");
    M=lookup_widget(objet,"spinbutton_mois");
    A=lookup_widget(objet,"spinbutton_annee");
    QA=lookup_widget(objet,"spinbutton_quantite");
   

    pt=lookup_widget (objet ,"sortie_validation");
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(M)); sprintf(chm,"%d",m);
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(A)); sprintf(cha,"%d",a);
mon=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(QA)); sprintf(chs,"%d",mon);
strcpy(PT.code_precipitation,gtk_entry_get_text(GTK_ENTRY(C)));

strcpy(PT.mois,chm);
strcpy(PT.annee,cha);
strcpy(PT.quantite,chs);
test1=P_trouve(PT.code_precipitation);
test2=P_trouve_mois_annee(PT.mois,PT.annee);

		

    
	    if (test1!=1&&test2!=1)
		{ 
		    ajouter_precipitation (PT);
		    sprintf(ch,"Ajout reussi");
		    gtk_label_set_text(GTK_LABEL(pt),ch);
		}
	    else
		{
		    sprintf(ch,"ERREUR: precipitation deja existant");
		    gtk_label_set_text(GTK_LABEL(pt),ch);

		}
}


void
on_chercher_modif_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget* identif,*pt; char id [25],ch[40]; int test;
char ch1[20],ch2[20],ch3[20],ch4[20];
GtkWidget *qa, *mm, *aa;
FILE* f;
f=fopen("precipitation.txt","r");
identif=lookup_widget(objet,"entry2");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(identif)));   
qa=lookup_widget(objet,"sortie_quantite");
mm=lookup_widget(objet,"sortie_mois_precipitation");
aa=lookup_widget(objet,"sortie_annee_precipitation");
pt=lookup_widget(objet,"sortie_recherche_precipitation");

	if (f!=NULL)
{

         while (fscanf (f, "%s %s %s %s\n",ch1,ch2,ch3,ch4)!=EOF)
            {
	if (strcmp(id,ch1)==0)

		{

		   	 sprintf(ch,"Identifiant existant!");
		   	 gtk_label_set_text(GTK_LABEL(pt),ch);

			gtk_label_set_text(GTK_LABEL(qa),ch2);
			gtk_label_set_text(GTK_LABEL(mm),ch3);
			gtk_label_set_text(GTK_LABEL(aa),ch4);


		}}
	fclose(f);
		}
	    else
		{
		    sprintf(ch,"ERREUR: identifiant non existant.");
		    gtk_label_set_text(GTK_LABEL(pt),ch);

		} 

}


void
on_valider_modif_precipitation_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
char ch_element[20],ch_value[20],id[20],ch[50]; int e,test;

	GtkWidget *element,*val,*identif,*pt;

pt=lookup_widget(objet,"sortie_resultat_precipitation");
identif=lookup_widget(objet,"entry2");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(identif)));   
element=lookup_widget(objet,"combobox_modif");
val=lookup_widget(objet,"entry_val");

strcpy(ch_element,gtk_combo_box_get_active_text(GTK_COMBO_BOX(element)));

e=int_ch(ch_element); 

strcpy(ch_value,gtk_entry_get_text(GTK_ENTRY(val)));

test=modif_precipitation(id,e,ch_value);

sprintf(ch,"%d",test);//gtk_label_set_text(GTK_LABEL(pt),ch);

    
	    if (strcmp(ch,"1")==0)
		{ 
		 
		    sprintf(ch,"Modification reussie!");
		    gtk_label_set_text(GTK_LABEL(pt),ch);
		}
	    else
		{
			
		    sprintf(ch,"ERREUR: identifiant inexistant");
		    gtk_label_set_text(GTK_LABEL(pt),ch);

		} 


}


void
on_retour2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *retour_acceuil ;

GtkWidget *windowpr1,* windowpr2,* windowpr3,* windowpr4;
windowpr1=lookup_widget(objet,"ajout_precipitation");
gtk_widget_destroy(windowpr1);
windowpr2=lookup_widget(objet,"modif_precipitation");
gtk_widget_destroy(windowpr2);
windowpr3=lookup_widget(objet,"supprimer_precipitatio");
gtk_widget_destroy(windowpr3);
windowpr4=lookup_widget(objet,"affichage_precipitation");
gtk_widget_destroy(windowpr4);

retour_acceuil=create_acceuil_precipitation();
gtk_widget_show (retour_acceuil);
}


void
on_retour3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *retour_acceuil ;
GtkWidget *windowpr1,* windowpr2,* windowpr3,* windowpr4;
windowpr1=lookup_widget(objet,"ajout_precipitation");
gtk_widget_destroy(windowpr1);
windowpr2=lookup_widget(objet,"modif_precipitation");
gtk_widget_destroy(windowpr2);
windowpr3=lookup_widget(objet,"supprimer_precipitatio");
gtk_widget_destroy(windowpr3);
windowpr4=lookup_widget(objet,"affichage_precipitation");
gtk_widget_destroy(windowpr4);
retour_acceuil=create_acceuil_precipitation();
gtk_widget_show (retour_acceuil);
}


void
on_valider_suppression_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget* code_precipitation,*window_supp;
GtkWidget* pt;
 char id[20], ch[50]; int test;
window_supp=lookup_widget(objet,"supprimer_precipitatio");
code_precipitation=lookup_widget(objet,"entry_code_supp");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(code_precipitation)));
pt=lookup_widget (objet ,"sortie_code_supprimer");
test=supprimer_precipitation(id);
sprintf(ch,"%d",test);

    
	    if (strcmp(ch,"1")==0)
		{ 
		    
		    sprintf(ch,"Supression reussie");
		    gtk_label_set_text(GTK_LABEL(pt),ch);
		}
	    else
		{
		    sprintf(ch,"ERREUR: ID inexistant");
		    gtk_label_set_text(GTK_LABEL(pt),ch);

		} 

}


void
on_retour4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *retour_acceuil ;
GtkWidget *windowpr1,* windowpr2,* windowpr3,* windowpr4;
windowpr1=lookup_widget(objet,"ajout_precipitation");
gtk_widget_destroy(windowpr1);
windowpr2=lookup_widget(objet,"modif_precipitation");
gtk_widget_destroy(windowpr2);
windowpr3=lookup_widget(objet,"supprimer_precipitatio");
gtk_widget_destroy(windowpr3);
windowpr4=lookup_widget(objet,"affichage_precipitation");
gtk_widget_destroy(windowpr4);
retour_acceuil=create_acceuil_precipitation();
gtk_widget_show (retour_acceuil);
}


void
on_retour1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *retour_acceuil ;
GtkWidget *windowpr1,* windowpr2,* windowpr3,* windowpr4;
windowpr1=lookup_widget(objet,"ajout_precipitation");
gtk_widget_destroy(windowpr1);
windowpr2=lookup_widget(objet,"modif_precipitation");
gtk_widget_destroy(windowpr2);
windowpr3=lookup_widget(objet,"supprimer_precipitatio");
gtk_widget_destroy(windowpr3);
windowpr4=lookup_widget(objet,"affichage_precipitation");
gtk_widget_destroy(windowpr4);
retour_acceuil=create_acceuil_precipitation();
gtk_widget_show (retour_acceuil);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* code_precipitation;
gchar* mm;
gchar* aa;
gchar* qq;
precipitation PT;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter,path))
{
//obtenir les valeurs de la ligne selectionnée

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,1,&code_precipitation,2,&qq,3,&mm,4,&aa,-1);

}
}


void
on_chercher_annee_seche_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{

FILE* f; char ch[50],chq[20];
char ch1[20],ch2[20],ch3[20],ch4[20],as[20];
int q,qt;
    	GtkWidget *pt;
	GtkWidget *affichage;
	affichage=lookup_widget(objet,"affichage_precipitation");
   	pt=lookup_widget (objet ,"sortie_annee_seche");
	q=0;
f=fopen("precipitation.txt","r");
if (f!=NULL)
{
         while (fscanf (f, "%s %s %s %s \n",ch1,ch2,ch3,ch4)!=EOF)
           		 {
				
				qt=calcul_quantite(ch4);
				if (qt<=q) 
				{
				q=qt;
				strcpy(as,ch4);}
				else q=qt;
			 }
}
fclose(f);
strcpy(chq,as);

gtk_label_set_text(GTK_LABEL(pt),chq);

}



void
on_button_anneeseche_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *acceuil_precipitation;
GtkWidget *menuprincipale;
menuprincipale= create_menuprincipale (); 
gtk_widget_destroy(menuprincipale);
acceuil_precipitation = create_acceuil_precipitation(); 
gtk_widget_show (acceuil_precipitation);
}






