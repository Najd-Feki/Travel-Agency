#include <gtk/gtk.h>
//#include "choixprob.h"

/*typedef struct
{
char vol[200];
char guide[200];
char voiture[200];
char hotel[200];
}type;*/

//void choixprob (type_prob t,char rec[50],char tel[50]);


/*typedef struct
{ 
char numres[100];
char date_reclamation[20];
char trait[10];
char reclamation[200];
type tp;
}recl;*/

void afficher_recl_client (GtkWidget *liste);
void historique_recl_client(GtkWidget *liste1);
//void supprimer_recl_client (recl r);


int recherche(char nom_cin[]);
void sup_reclamation(int lno);
void modif(int a,char numres[],char reclamation[],char type_probk[],char date_reclamation[]);
void supprimerm(char cin[]);




