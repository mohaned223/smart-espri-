#include<stdio.h>
#include"fonction.h"
#include<string.h>
#include<gtk/gtk.h>

enum{
ID,
NOM,
PRENOM,
CIN,
DATE,
NUM,
EMAIL,
POSTE,
GENRE,
COLUMNS
};
int verif(char log[], char pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if (f!=NULL){
while (fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{if( (strcmp(ch1,log)==0) && (strcmp(ch2,pw)==0)){
trouve=1;}
}
fclose(f);
}
return trouve;
}



/* Fonction Ajouter */
void ajouter_util(user p)

{

FILE *f;
f=fopen("util.txt","a+");
if (f!=NULL)
{
fprintf(f, "%d %s %s %s %s %s %s %s %s \n",p.id,p.nom,p.prenom,p.CIN,p.sexe,p.date_naissance,p.poste,p.num,p.email);

fclose(f);
}}


/*fonction_aff*/

void afficher_util(GtkWidget *liste )

{

user p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("NOM",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("PRÉNOM",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("SEXE",renderer,"text",GENRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("DNS",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("POSTE",renderer,"text",POSTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("NUMÉRO",renderer,"text",NUM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("E-MAIL",renderer,"text",EMAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("util.txt","r");

char id1[30];
char nom1[30];
char prenom1[30];
char CIN1[30];
char sexe1[30];
char date_naissance1[30];
char poste1[30];
char num1[30];
char email1[40];


{
f=fopen("util.txt","a+");
	while(fscanf(f, "%s %s %s %s %s %s %s %s %s \n",id1,nom1,prenom1,CIN1,sexe1,date_naissance1,poste1,num1,email1)!=EOF)
	{
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ID,id1,NOM,nom1,PRENOM,prenom1,CIN,CIN1,GENRE,sexe1,DATE,date_naissance1,POSTE,poste1,NUM,num1,EMAIL,email1,-1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

/*fonction_rechercher*/
void rechercher_util(GtkWidget *liste,char ch[30] )

{

user p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",GENRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("dns",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("poste",renderer,"text",POSTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("numero",renderer,"text",NUM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("email",renderer,"text",EMAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("util.txt","r");

char id1[30];
char nom1[30];
char prenom1[30];
char CIN1[30];
char sexe1[30];
char date_naissance1[30];
char poste1[30];
char num1[30];
char email1[40];


{
f=fopen("util.txt","a+");
	while(fscanf(f, "%s %s %s %s %s %s %s %s %s \n",id1,nom1,prenom1,CIN1,sexe1,date_naissance1,poste1,num1,email1)!=EOF)
	{if (strcmp(nom1,ch)==0){
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ID,id1,NOM,nom1,PRENOM,prenom1,CIN,CIN1,GENRE,sexe1,DATE,date_naissance1,POSTE,poste1,NUM,num1,EMAIL,email1,-1);
	}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

/*fonction_supprimer*/

void supprimer_util (char id[]){

char id1[30];
char nom1[30];
char prenom1[30];
char CIN1[30];
char sexe1[30];
char date_naissance1[30];
char poste1[30];
char num1[30];
char email1[40];
FILE*f=NULL;
FILE*f1=NULL;
user p ;
f=fopen("util.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f, "%s %s %s %s %s %s %s %s %s \n",id1,nom1,prenom1,CIN1,sexe1,date_naissance1,poste1,num1,email1)!=EOF){
if(strcmp(id,id1)!=0){
    fprintf(f1,"%s %s %s %s %s %s %s %s %s \n",id1,nom1,prenom1,CIN1,sexe1,date_naissance1,poste1,num1,email1);
}}
fclose(f);
fclose(f1);
remove("util.txt");
rename("ancien.txt","util.txt");
printf("supprimer avec succes\n");
}


void modifier_userr(char id[],user r){
char id1[30];
char nom1[30];
char prenom1[30];
char CIN1[30];
char sexe1[30];
char date_naissance1[30];
char poste1[30];
char num1[30];
char email1[40];
FILE*f=NULL;
FILE*f1=NULL;
user p ;
f=fopen("util.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f, "%s %s %s %s %s %s %s %s %s \n",id1,nom1,prenom1,CIN1,sexe1,date_naissance1,poste1,num1,email1)!=EOF){
if(strcmp(id,id1)==0){
fprintf(f1, "%d %s %s %s %s %s %s %s %s \n",r.id,r.nom,r.prenom,r.CIN,r.sexe,r.date_naissance,r.poste,r.num,r.email);
}
else
{
fprintf(f1,"%s %s %s %s %s %s %s %s %s \n",id1,nom1,prenom1,CIN1,sexe1,date_naissance1,poste1,num1,email1);
}

}
fclose(f);
fclose(f1);
remove("util.txt");
rename("ancien.txt","util.txt");
printf("modifié avec succes \n");
}


/*fonctions de controle de saisie*/

int verifier_cin (char ch[20])
{int i;int x = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' &&ch[i] != '4' &&ch[i] != '5' &&ch[i] != '6' &&ch[i] != '7' &&ch[i] != '8' &&ch[i] != '9'  || strlen(ch)!=8 )
    x = 1 ;}
   if ( x == 0 ) return 1;
    else return 0;
}

int verifier_email (char ch[20])
{int i;int x = 0;int y = 0; int z = 0; int b = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] == '@' )
    x =x+ 1 ;
    if (ch[i] == '.' )
    b =b+ 1 ;
    if (ch[i] == ' ' )
    y = 1 ;}
    if (ch [0]=='@' || ch[strlen(ch)-1]=='@' || ch[strlen(ch)-1]=='.' )
        z =1;
   if ( x == 1 && y == 0 && z == 0 && b >0) return 1;
    else return 0;
}
int verifier_lettre (char ch[20])
{int i;int x = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] != 'a' && ch[i] != 'b' && ch[i] != 'c' && ch[i] != 'd' &&ch[i] != 'e' &&ch[i] != 'f' &&ch[i] != 'g' &&ch[i] != 'h' &&ch[i] != 'i' &&ch[i] != 'j' &&ch[i] != 'k'&&ch[i] != 'l'&&ch[i] != 'm'&&ch[i] != 'n'&&ch[i] != 'o'&&ch[i] != 'p'&&ch[i] != 'z'&&ch[i] != 'q'&&ch[i] != 'r'&&ch[i] != 's'&&ch[i] != 't'&&ch[i] != 'u'&&ch[i] != 'v'&&ch[i] != 'w'&&ch[i] != 'x'&&ch[i] != 'z'&&ch[i] != 'y'&& ch[i] != ' '  )
    x = 1 ;}
   if ( x == 0 ) return 1;
    else return 0;
}



 /*fonctions partie2*/

dechet plat1 (int z){
FILE *f;
dechet x;
dechet y;
int s1,s2;
if (z==1){s1=1; s2=7;}
if (z==2){s1=8; s2=14;}
if (z==3){s1=15; s2=21;}
if (z==4){s1=22; s2=29;}

float ddd=100.000000;
f=fopen("dechets.txt","r");


while(fscanf(f,"%d %d %f \n",&x.x1,&x.x2,&x.x3)!=-1){
if(x.x2==1 && x.x1>=s1 && x.x1<=s2){
	if (x.x3<ddd){

ddd=x.x3;

y.x1=x.x1;
y.x2=x.x2;
y.x3=x.x3;

}
}
    

}  return y;}


dechet plat2 (int z){
FILE *f;
dechet x;
dechet y;
float ddd=100.00;
int s1,s2;
if (z==1){s1=1; s2=7;}
if (z==2){s1=8; s2=14;}
if (z==3){s1=15; s2=21;}
if (z==4){s1=22; s2=29;}
f=fopen("dechets.txt","r");


while(fscanf(f, "%d %d %f \n",&x.x1,&x.x2,&x.x3)!=EOF){
if(x.x2==2  && x.x1>=s1 && x.x1<=s2){
	if (x.x3<ddd){
ddd=x.x3;
y.x1=x.x1;
y.x2=x.x2;
y.x3=x.x3;
}

    
}
}

return y;}



dechet plat3 (int z){
FILE *f;
dechet x;
dechet y;
float ddd=100.0;
int s1,s2;
if (z==1){s1=1; s2=7;}
if (z==2){s1=8; s2=14;}
if (z==3){s1=15; s2=21;}
if (z==4){s1=22; s2=29;}
f=fopen("dechets.txt","r");


while(fscanf(f, "%d %d %f \n",&x.x1,&x.x2,&x.x3)!=EOF){
if(x.x2==3  && x.x1>=s1 && x.x1<=s2){
	if (x.x3<ddd){
ddd=x.x3;
y.x1=x.x1;
y.x2=x.x2;
y.x3=x.x3;
}

    
}
} return y;}


/*fonction_verif mot de passe*/
int verif_pass(char log[], char pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if (f!=NULL){
while (fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{if( (strcmp(ch1,log)==0) && (strcmp(ch2,pw)==0)){
trouve=1;}
}
fclose(f);
}
return trouve;
}


