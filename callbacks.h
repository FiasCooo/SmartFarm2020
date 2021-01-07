#include <gtk/gtk.h>




void
on_buttonajout_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_wbatreeviewcapteur_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttoncomfirmer_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);





void
on_buttonactua_clicked                 (GtkWidget      *objet	,
                                        gpointer         user_data);

void
on_gestion_capteur_show                (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_buttonannuler_clicked               (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonajouhisto_clicked             (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonaffhisto_clicked              (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttoncomfirmerhisto_clicked        (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonannuler2_clicked              (GtkButton       *objet,
                                        gpointer         user_data);

void
on_treeviewhisto_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonannulerhist_clicked           (GtkButton       *objet,
                                        gpointer         user_data);


void
on_buttonmodif_clicked                 (GtkButton       *objet,
                                        gpointer         user_data);




void
on_buttonannuler1_clicked              (GtkButton       *objet,
                                        gpointer         user_data);



void
on_affiche_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonsupp_clicked                  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonaffmodif_clicked              (GtkButton       *objet,
                                        gpointer         user_data);



void
on_buttoncomfsupp_clicked              (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonretour_clicked                (GtkButton       *objet,
                                        gpointer         user_data);

void
on_refresh_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_OK_clicked                          (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttoncomfirmer1_clicked            (GtkButton       *objet,
                                        gpointer         user_data);


                                    

void
on_Aff_clicked                         (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonchercher_clicked              (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttoncherchisto_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonala_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_ref_clicked                         (GtkButton       *button,
                                        gpointer         user_data);
