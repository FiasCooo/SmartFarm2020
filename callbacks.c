#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "equipement.h"
#include <string.h>
#include "rec.h"
#include "stat.h"
void
on_buttonb3_clicked   (GtkWidget  *objet_graphique, 
			gpointer    user_data)
{
GtkWidget *window2 ;
 GtkWidget *window3;

window2=lookup_widget(objet_graphique,"windowb2");
gtk_widget_hide(window2);
window3 = create_windowb3();
gtk_widget_show (window3);
}







//void
//on_buttonb6_clicked      (GtkWidget  *button, gpointer user_data)
//{
//GtkWidget *windowb1, *windowb2;

//windowb2=lookup_widget(button,"windowb2");
//gtk_widget_hide(windowb2);
//windowb1 = create_windowb1();
//gtk_widget_show (windowb1);
//}


void
on_buttonb8_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}

void
on_button1_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttonb7_clicked                   (GtkWidget     *objet_graphique, gpointer      user_data)
{
equipement e;
GtkWidget *output;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6;


input1=lookup_widget(objet_graphique,"entryb3");
input2=lookup_widget(objet_graphique,"entryb4");
input3=lookup_widget(objet_graphique,"entryb5");
input4=lookup_widget(objet_graphique,"entryb6");
input5=lookup_widget(objet_graphique,"entry7");
input6=lookup_widget(objet_graphique,"entryb8");




output= lookup_widget(objet_graphique,"label100");
strcpy(e.type,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.marque,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.matricule,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.num_id,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(e.puissance,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(e.annee,gtk_entry_get_text(GTK_ENTRY(input6)));
gtk_label_set_text(GTK_LABEL(output),"ajouté avec succés");



       
ajouter_equipement(e);

}



void
on_buttonb13_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)



{GtkWidget *windowb3;
equipement e;
GtkWidget *treeview1;
windowb3=lookup_widget(objet_graphique,"windowb3");
treeview1=lookup_widget(windowb3,"treeviewb1");
afficher_equipement(treeview1);
}


//{
//GtkWidget *windowb3;
//GtkWidget *treeview1;
//windowb3=lookup_widget(objet,"windowb3");
//gtk_widget_destroy(windowb3);


//gtk_widget_show(windowb3);

//treeview1=lookup_widget(windowb3,"treeview1");
//afficher_agent(treeview1);

//}




void
on_buttonb9_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
char MATRICULE[20];
int test;
equipement e;
GtkWidget *entryb9, *entryb11,*entryb12,*entryb13,*entryb14,*entryb15,*entryb16,*entry10,*entry11;
GtkWidget *windowb3,*windowb6;
GtkWidget *output;
windowb6=create_windowb6();
entryb9=lookup_widget(objet_graphique,"entryb9");
entryb11=lookup_widget(windowb6,"entryb11");
entryb12=lookup_widget(windowb6,"entryb12");
entryb13=lookup_widget(windowb6,"entryb13");
entryb14=lookup_widget(windowb6,"entryb14");
entryb15=lookup_widget(windowb6,"entryb15");
entryb16=lookup_widget(windowb6,"entryb16");
entry11=lookup_widget(windowb6,"entry10");
entry10=lookup_widget(windowb6,"entry11");

output= lookup_widget(objet_graphique,"label1");
strcpy(MATRICULE,gtk_entry_get_text(GTK_ENTRY(entryb9)));
if (verifier_matricule(MATRICULE)==0)
gtk_label_set_text(GTK_LABEL(output),"equipement n'existe pas");
else
{
FILE *f2;
f2=fopen("equipement.txt","r"); 
if (f2!=NULL)
{while (fscanf(f2,"%s %s %s %s %s %s\n",e.type,e.marque,e.matricule,e.num_id,e.puissance,e.annee)!=EOF)
{if (strcmp(e.matricule,MATRICULE)==0) 
{ gtk_widget_show(windowb6);
gtk_entry_set_text(GTK_ENTRY(entryb11),e.type) ;
gtk_entry_set_text(GTK_ENTRY(entryb12),e.marque) ;
gtk_entry_set_text(GTK_ENTRY(entryb13),e.matricule) ;
gtk_entry_set_text(GTK_ENTRY(entryb14),e.num_id) ;
gtk_entry_set_text(GTK_ENTRY(entryb15),e.puissance) ;
gtk_entry_set_text(GTK_ENTRY(entryb16),e.annee) ;


break ;}}
}
fclose(f2);
}		// gtk_widget_show(window6);
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







void
on_buttonb14_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
equipement e;
GtkWidget *entryb9,*entryb12,*entryb13,*entryb14,*entryb15,*entryb16,*entry10,*entry11;
GtkWidget *output;
entryb9=lookup_widget(objet_graphique,"entryb11");
entryb12=lookup_widget(objet_graphique,"entryb12");
entryb13=lookup_widget(objet_graphique,"entryb13");
entryb14=lookup_widget(objet_graphique,"entryb14");
entryb15=lookup_widget(objet_graphique,"entryb15");
entryb16=lookup_widget(objet_graphique,"entryb16");

output=lookup_widget(objet_graphique,"label2");
strcpy(e.type,gtk_entry_get_text(GTK_ENTRY(entryb9)));
strcpy(e.marque,gtk_entry_get_text(GTK_ENTRY(entryb12)));
strcpy(e.matricule,gtk_entry_get_text(GTK_ENTRY(entryb13)));
strcpy(e.num_id,gtk_entry_get_text(GTK_ENTRY(entryb14)));
strcpy(e.puissance,gtk_entry_get_text(GTK_ENTRY(entryb15)));
strcpy(e.annee,gtk_entry_get_text(GTK_ENTRY(entryb16)));


modifier_equipement(e);
gtk_label_set_text(GTK_LABEL(output),"modifié avec succés") ;
}





void
on_buttonb10_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *output;
equipement e;
char ref[20];
input=lookup_widget(objet_graphique,"entryb10");
output=lookup_widget(objet_graphique,"labelb29");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));
if(strcmp(ref,e.matricule)==0)
gtk_label_set_text(GTK_LABEL(output),"client n'existe pas");
else
{
supprimer_equipement(ref);
gtk_label_set_text(GTK_LABEL(output),"suppression avec succée");
}
}
/*GtkWidget *windowb3;
	GtkWidget *window4;
windowb3 = 
	windowb3=lookup_widget(objet_graphique,"windowb3");	
	

}
*/





void
on_buttonb5_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowb2, *windowb5;
windowb2=lookup_widget(objet_graphique,"windowb2");
gtk_widget_hide(windowb2);
windowb5 = create_windowb6();
gtk_widget_show (windowb5);
}
void
on_buttonbackb2_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowb3, *windowb2;
windowb3=lookup_widget(objet_graphique,"windowb3");
gtk_widget_hide(windowb3);
windowb2 = create_windowb2();
gtk_widget_show (windowb2);
}
void
on_buttonbackb3_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowb3, *windowb2;
windowb3=lookup_widget(objet_graphique,"windowb3");
gtk_widget_hide(windowb3);
windowb2 = create_windowb2();
gtk_widget_show (windowb2);
}
void
on_buttonback5_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowb5, *windowb2;
windowb5=lookup_widget(objet_graphique,"windowb5");
gtk_widget_hide(windowb5);
windowb2 = create_windowb2();
gtk_widget_show (windowb2);
}


void
on_buttonb555_clicked              (GtkWidget      *objet_graphique,
                                        gpointer         user_data)



{GtkWidget *windowb5;

GtkWidget *treeview;
windowb5=lookup_widget(objet_graphique,"windowb5");
treeview=lookup_widget(windowb5,"treeviewb3");
afficher_stat(treeview);
}

void
on_buttonback4_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowb2, *windowb5;
windowb5=lookup_widget(objet_graphique,"windowb5");
gtk_widget_hide(windowb5);
windowb2 = create_windowb2();
gtk_widget_show (windowb2);
}

void
on_buttonb11_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)

{GtkWidget *windowb4;

GtkWidget *treeviewb;
windowb4=lookup_widget(objet_graphique,"windowb4");
treeviewb=lookup_widget(windowb4,"treeviewb2");
afficher_commentaire(treeviewb);
}


void
on_buttonb963_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
{
GtkWidget *windowb3, *windowb6;
windowb6=lookup_widget(button,"windowb6");
gtk_widget_hide(windowb6);
windowb3 = create_windowb3();
gtk_widget_show (windowb3);
}
}


void
on_recherche_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview_rechercher_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

