#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
//#include "reclamationagent.h"
#include "reclamation_nour.h"
//#include "recherche.h"


void on_buttonajouter_clicked (GtkButton *button,gpointer  user_data)
{

GtkWidget *output;
GtkWidget *comboboxrec 	     =	lookup_widget(button,"comboboxrec");
GtkWidget *input_rec	     =	lookup_widget(button,"entryreclclient");
GtkWidget *input_res	     =	lookup_widget(button,"entry_numres_client");
GtkWidget *input_date        =  lookup_widget(button,"entry_daterec");

//type t;
char res[100],rec[100],CMB[100],daterec[100];
strcpy(res,gtk_entry_get_text(GTK_ENTRY(input_res)));
strcpy(rec,gtk_entry_get_text(GTK_ENTRY(input_rec)));
strcpy(CMB,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxrec)));
strcpy(daterec,gtk_entry_get_text(GTK_ENTRY(input_date)));
output=lookup_widget(button,"label15");
gtk_label_set_text(GTK_LABEL(output),"Reclamation est envoyée");
int i,n;
n=strlen(rec);
for(i=0;i<n;i++)
if(rec[i]==' ')
rec[i]='_';

//if(strcmp("problemes de vol",CMB)==0)
{FILE *f;
f=fopen("reclamation.txt","a+");
fprintf(f,"%s %s %s %s \n",res,rec,CMB,daterec);
fclose(f);
}

/*if(strcmp("problemes de guide touristique",CMB)==0)
{FILE* f;
f=fopen("reclamation.txt","a+");
fprintf(f,"%s %s %s\n",res,rec,CMB);
fclose(f);
}
if(strcmp("problemes des services hoteliers",CMB)==0)
{FILE* f;
f=fopen("reclamation.txt","a+");
fprintf(f,"%s %s %s\n",res,rec,CMB);
fclose(f);
}

if(strcmp("problemes de location des voitures",CMB)==0)
{FILE* f;
f=fopen("reclamation.txt","a+");
fprintf(f,"%s %s %s\n",res,rec,CMB);
fclose(f);
}*/

GtkWidget  *validation_ajout_rec;

validation_ajout_rec=lookup_widget(button,"validation_ajout_rec");
validation_ajout_rec= create_validation_ajout_rec();
gtk_widget_show (validation_ajout_rec);



}


void
on_new1_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_open1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_save1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_save_as1_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_quit1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_cut1_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_copy1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_paste1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_delete1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_about1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_new2_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_open2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_save2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_save_as2_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_quit2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_cut2_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_copy2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_paste2_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_delete2_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_about2_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}




void on_button_afficher_tabrec_clicked      (GtkButton       *button2,
                                        gpointer         user_data)
{
GtkWidget *fenetre_reclamation_client;
GtkWidget *treeview_gestion_rec;
GtkWidget *gestion_reclamation_agent1;

gestion_reclamation_agent1=lookup_widget(button2,"gestion_reclamation_agent1");
gtk_widget_destroy(gestion_reclamation_agent1);

gestion_reclamation_agent1=lookup_widget(button2,"gestion_reclamation_agent1");
gestion_reclamation_agent1= create_gestion_reclamation_agent1();
gtk_widget_show (gestion_reclamation_agent1);

treeview_gestion_rec=lookup_widget(gestion_reclamation_agent1,"treeview_gestion_rec");

afficher_recl_client(treeview_gestion_rec);


}





void
on_buttonquitter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_reclamation_client;
fenetre_reclamation_client=lookup_widget(button,"fenetre_reclamation_client");
gtk_widget_destroy(fenetre_reclamation_client);
}


void
on_buttonhistorique_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_reclamation_client;
GtkWidget *historiq_reclamations;
GtkWidget *treeview_historiq_reclamations;

fenetre_reclamation_client=lookup_widget(button,"fenetre_reclamation_client");

gtk_widget_destroy(fenetre_reclamation_client);
historiq_reclamations=lookup_widget(button,"historiq_reclamations");
historiq_reclamations=create_historiq_reclamations();

gtk_widget_show(historiq_reclamations);

treeview_historiq_reclamations=lookup_widget(historiq_reclamations,"treeview_historiq_reclamations");
historique_recl_client(treeview_historiq_reclamations);

}




void
on_button_quitter_rec_agent_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestion_reclamation_agent1;
gestion_reclamation_agent1=lookup_widget(button,"gestion_reclamation_agent1");
gtk_widget_destroy(gestion_reclamation_agent1);

}


void
on_button_retour_fenajout_recl_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_reclamation_client, *historiq_reclamations;


historiq_reclamations=lookup_widget(button,"historiq_reclamations");
gtk_widget_destroy(historiq_reclamations);
fenetre_reclamation_client=create_fenetre_reclamation_client();
gtk_widget_show(fenetre_reclamation_client);
}


void
on_buttonchercher1_client_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *recherche_rec_nour;
recherche_rec_nour=create_recherche_rec_nour();
gtk_widget_show(recherche_rec_nour);
}


void
on_buttonchercher2_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
//strcpy(p.Nom,gtk_entry_get_text(GTK_ENTRY (input5)));
char numres[50];
char reclamation[50];
char type_probk[50];
char date_reclamation[50];
char cherchertreeview[50];


GtkWidget *input  =  lookup_widget(button,"entryrecherche");
GtkWidget *input5 =  lookup_widget(button,"entryreclamation_agent");
strcpy(cherchertreeview,gtk_entry_get_text(GTK_ENTRY(input)));
int a=0;
a=recherche(cherchertreeview);
modif(a,numres,reclamation,type_probk,date_reclamation);
gtk_entry_set_text(GTK_ENTRY(input5),reclamation);
}


void
on_buttonsupprimer_rec_client_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
char cherchertreeview[50];
GtkWidget *input;
input = lookup_widget(button,"entryrecherche");
if(gtk_entry_get_text(GTK_ENTRY (input))!= NULL)
{
strcpy(cherchertreeview,gtk_entry_get_text(GTK_ENTRY (input)));
int x=0;
//x=recherche(cherchertreeview);
supprimerm(cherchertreeview);
}

GtkWidget  *validation_supp_rec;

validation_supp_rec=lookup_widget(button,"validation_supp_rec");
validation_supp_rec= create_validation_supp_rec();
gtk_widget_show (validation_supp_rec);


}

void
on_buttonmodif_rec_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modif_recl;
modif_recl=create_modif_recl();
gtk_widget_show(modif_recl);
}


void
on_buttonvaliser_modif_recl_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{


char cherchrec[50];
char numres[50];
char reclamation[50];
char type_probk[50];
char date_reclamation[50];
int a=0;

GtkWidget *input  =	lookup_widget(button,"entrynumres1");
GtkWidget *input5 =  lookup_widget(button,"entrynumres2");
GtkWidget *input4 =  lookup_widget(button,"entry_recente_rec");
GtkWidget *input3 =  lookup_widget(button,"entrytype_prob");
GtkWidget *input2 =  lookup_widget(button,"entrydate_rec_client");

strcpy(cherchrec,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(numres,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(reclamation,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(type_probk,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(date_reclamation,gtk_entry_get_text(GTK_ENTRY(input2)));
a=recherche(cherchrec);
supprimerm(cherchrec);

int i,n;
n=strlen(reclamation);
for(i=0;i<n;i++)
if(reclamation[i]==' ')
reclamation[i]='_';

//if(strcmp("problemes de vol",CMB)==0)
{FILE *f;
f=fopen("reclamation.txt","a+");
fprintf(f,"%s %s %s %s\n",numres,reclamation,type_probk,date_reclamation);
fclose(f);
}

GtkWidget  *validation_modif_rec;

validation_modif_rec=lookup_widget(button,"validation_modif_rec");
validation_modif_rec= create_validation_modif_rec();
gtk_widget_show (validation_modif_rec);




}


void
on_button_retour_fenrecl_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *historiq_reclamations, *modif_recl;


historiq_reclamations=lookup_widget(button,"modif_recl");
gtk_widget_destroy(modif_recl);
historiq_reclamations=create_historiq_reclamations();
gtk_widget_show(historiq_reclamations);
}


void
on_button_cherchetmodif_rec_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
char numres[50];
char reclamation[50];
char type_probk[50];
char date_reclamation[50];
char chercherrec_client_nour[50];


GtkWidget *input  =  lookup_widget(button,"entrynumres1");
GtkWidget *input5 =  lookup_widget(button,"entrynumres2");
GtkWidget *input4 =  lookup_widget(button,"entry_recente_rec");
GtkWidget *input3 =  lookup_widget(button,"entrytype_prob");
GtkWidget *input2 =  lookup_widget(button,"entrydate_rec_client");
strcpy(chercherrec_client_nour,gtk_entry_get_text(GTK_ENTRY(input)));
int a=0;
a=recherche(chercherrec_client_nour);
modif(a,numres,reclamation,type_probk,date_reclamation);
gtk_entry_set_text(GTK_ENTRY(input5),numres);
gtk_entry_set_text(GTK_ENTRY(input4),reclamation);
gtk_entry_set_text(GTK_ENTRY(input3),type_probk);
gtk_entry_set_text(GTK_ENTRY(input2),date_reclamation);

}


void
on_buttonretour_gestrec_agent_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *recherche_rec_nour, *gestion_reclamation_agent1;


recherche_rec_nour=lookup_widget(button,"recherche_rec_nour");
gtk_widget_destroy(recherche_rec_nour);
/*gestion_reclamation_agent1=create_gestion_reclamation_agent1();
gtk_widget_show(gestion_reclamation_agent1);*/



}


void
on_buttonvalid_ajoutrec_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *fenetre_reclamation_client, *validation_ajout_rec;

validation_ajout_rec=lookup_widget(button,"validation_ajout_rec");
gtk_widget_destroy(validation_ajout_rec);
fenetre_reclamation_client=create_fenetre_reclamation_client();
gtk_widget_show(fenetre_reclamation_client);
}


void
on_buttonvalid_modifrec_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modif_recl, *validation_modif_rec;

validation_modif_rec=lookup_widget(button,"validation_modif_rec");
gtk_widget_destroy(validation_modif_rec);
modif_recl=create_modif_recl();
gtk_widget_show(modif_recl);
}


void
on_buttonvalid_supprec_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *recherche_rec_nour, *validation_supp_rec;

validation_supp_rec=lookup_widget(button,"validation_supp_rec");
gtk_widget_destroy(validation_supp_rec);
recherche_rec_nour=create_recherche_rec_nour();
gtk_widget_show(recherche_rec_nour);
}

