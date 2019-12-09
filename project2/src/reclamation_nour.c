#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "choixprob.h"
//#include "reclamationagent.h"
#include <gtk/gtk.h>
//#include "recherche.h"

/*void choixprob (type_prob t,char rec[200],char tel[12])
{
type_prob tp;


FILE *f1;
FILE* f2;
FILE* f3;
FILE* f4;
if(strcmp(tp.vol,"problemes de vol")==0)
{ 

f1=fopen("recl_vol.txt","a+");
}
if (f1!= NULL)
{
fprintf(f1,"%s %s \n",tel,rec);
fclose(f1);
}
if(strcmp(tp.guide,"problemes de guide touristique")==0)
{
f2=fopen("recl_guide.txt","a+");
}
if (f2!= NULL)
{
fprintf(f2,"%s \n",tel,rec);
fclose(f2);
}
if(strcmp(tp.hotel,"problemes des services hoteliers")==0)
{ 
f3=fopen("recl_hotel.txt","a+");
}
if (f3!= NULL)
{
fprintf(f3,"%s \n",tel,rec);
fclose(f3);
}
if(strcmp(tp.voiture,"problemes de location des voitures")==0)
{ 
f4=fopen("recl_voiture.txt","a+");
}
if (f4!= NULL)
{
fprintf(f4,"%s \n",tel,rec);
fclose(f4);
}
}*/





enum
{
NUMRES,
RECLAMATION,
TYPE_PROBK,
DATE,
COLUMNS};
enum
{UN,DEUX,TROIS,QUATRE,COLUMNSX};

void afficher_recl_client(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

GtkListStore *store;

char numres[50];
char reclamation[50];
char type_probk[50];
char date_reclamation[50];


store=NULL;

FILE *f;


store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" numres", renderer, "text",NUMRES, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" reclamation", renderer, "text",RECLAMATION, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" type_probk", renderer, "text",TYPE_PROBK, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" date_reclamation", renderer, "text",DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("reclamation.txt","r");
if(f==NULL)
{
	return;
}
else
{ f= fopen("reclamation.txt","a+");
	while(fscanf(f,"%s %s %s %s \n",numres,reclamation,type_probk,date_reclamation)!=EOF)
	{
gtk_list_store_append (store,&iter);

gtk_list_store_set (store, &iter, NUMRES, numres, RECLAMATION, reclamation, TYPE_PROBK, type_probk, DATE, date_reclamation, -1);
	}
	fclose(f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}}
void historique_recl_client(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

GtkListStore *store;



char numres[50];
char reclamation[50];
char type_probl[50];
char date_reclamation[50];
store=NULL;
FILE *f;


store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" numres",renderer,"text",UN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" reclamation", renderer, "text",DEUX, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" type_probl", renderer, "text",TROIS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" date_reclamation", renderer, "text",QUATRE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNSX, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("reclamation.txt","r");

if(f==NULL)
{
	return;
}
else
{ f= fopen("reclamation.txt","a+");
	while(fscanf(f,"%s %s %s %s \n",numres,reclamation,type_probl,date_reclamation)!=EOF)
	{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set (store, &iter, UN, numres, DEUX, reclamation, TROIS, type_probl, QUATRE, date_reclamation, -1);
	}
	fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}}}



void modif(int a,char numres[],char reclamation[],char type_probk[],char date_reclamation[])
{


    FILE *f;
    f=fopen("reclamation.txt", "r");
    int line=0;
    while(fscanf(f,"%s %s %s %s \n",numres,reclamation,type_probk,date_reclamation)!= EOF) {
        line++;
        if(line == a) break;
}
fclose(f);
}


int recherche(char nom_cin[])
{
char numres[50];
char reclamation[50];
char type_probk[50];
char date_reclamation[50];

int ligne=0;
FILE*f;
f=fopen("reclamation.txt","r"); 
if(f!=NULL) 
	{
		while(fscanf(f,"%s %s %s %s \n",numres,reclamation,type_probk,date_reclamation)!=EOF)
		{ligne++;
			if(strcmp(nom_cin,numres)==0)
			{fclose(f);
			return(ligne);}
		}
		fclose(f);
		return(-1);
	}
	return(-1);
}
void supprimerm(char cin[])
{
        char  NOM[50] ;
        char  PRENOM[50] ;
        char  IDENTIFIANT[50] ;
        char  TEXTE[50] ;
       

FILE *l=fopen("reclamation.txt","r");
FILE *t=fopen("tamp2.txt","a+");
if (l!=NULL)
	{
	while(fscanf(l,"%s %s %s %s\n",NOM,PRENOM,IDENTIFIANT,TEXTE)!=EOF)
		{
		if (strcmp(NOM,cin)!=0)
			{
			fprintf(t,"%s %s %s %s\n",NOM,PRENOM,IDENTIFIANT,TEXTE);
			}
		}
	}
fclose(l);
fclose(t);
remove("reclamation.txt");
rename("tamp2.txt","reclamation.txt");
}

