#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.c"
user o;
char id111[4];
char sexe1[10]="Homme";
int cnf1=0;
char sexe2[10]="Homme";
int cnf2=0;
void
on_button102_hsm_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *label55_hsm;

label55_hsm = lookup_widget(button,"label6_sexe");
//sexe (s,msg);

gtk_label_set_text(GTK_LABEL(label55_hsm),sexe1);
}


void
on_retour_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_user;
ajouter_user=lookup_widget(button,"ajouter_user");
gtk_widget_destroy(ajouter_user);
GtkWidget *afficher_user;
afficher_user = create_afficher_user ();
  gtk_widget_show (afficher_user);
}


void
on_ajouter_user_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";

user p;

GtkWidget *nom_user,*prenom_user,*cin_user,*tel_user,*email_user,*comboboxentry1_user,*calendar1_user;
GtkWidget *spinbutton1_user;

nom_user=lookup_widget(button,"nom_user");
prenom_user=lookup_widget(button,"prenom_user");
cin_user=lookup_widget(button,"cin_user");
tel_user=lookup_widget(button,"tel_user");
email_user=lookup_widget(button,"email_user");
comboboxentry1_user=lookup_widget(button,"comboboxentry1_user");
calendar1_user=lookup_widget(button,"calendar1_user");
spinbutton1_user=lookup_widget(button,"spinbutton1_user");

GtkWidget *ecin_us;
ecin_us = lookup_widget (button ,"ecin_us");
GtkWidget *etel_us;
etel_us = lookup_widget (button ,"etel_us");
GtkWidget *eemail_us;
eemail_us = lookup_widget (button ,"eemail_us");
GtkWidget *enom_us;
enom_us = lookup_widget (button ,"enom_us");
GtkWidget *eprenom_us;
eprenom_us = lookup_widget (button ,"eprenom_us");
GtkWidget *eposte_us;
eposte_us = lookup_widget (button ,"eposte_us");
GtkWidget *econf_us;
econf_us = lookup_widget (button ,"econf_us");


int bbb=0;
gtk_calendar_get_date (GTK_CALENDAR(calendar1_user),
                       &aa,
                       &mm,
                       &jj);

mm=mm+1;
sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,a);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,c);

p.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1_user));
strcpy(p.date_naissance,y);
strcpy(p.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1_user)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom_user)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_user)));
strcpy(p.CIN,gtk_entry_get_text(GTK_ENTRY(cin_user)));
strcpy(p.sexe,sexe1);
strcpy(p.num,gtk_entry_get_text(GTK_ENTRY(tel_user)));
strcpy(p.email,gtk_entry_get_text(GTK_ENTRY(email_user)));



if (verifier_cin (p.CIN)==0 || (strcmp(p.CIN,"")==0)){bbb=1;
	          gtk_widget_show (ecin_us);
}
else {
		  gtk_widget_hide(ecin_us);
}
if (verifier_cin (p.num)==0 || (strcmp(p.num,"")==0)){bbb=1;
	          gtk_widget_show (etel_us);

}
else {
		  gtk_widget_hide(etel_us);
}	

if (verifier_email (p.email)==0 || (strcmp(p.email,"")==0) ){bbb=1;
	gtk_widget_show (eemail_us);

}
else {
		  gtk_widget_hide(eemail_us);
}
if (verifier_lettre (p.nom)==0 || (strcmp(p.nom,"")==0) ){bbb=1;
	gtk_widget_show (enom_us);

}
else {
		  gtk_widget_hide(enom_us);
}
if (verifier_lettre (p.prenom)==0 || (strcmp(p.prenom,"")==0) ){bbb=1;
	gtk_widget_show (eprenom_us);

}
else {
		  gtk_widget_hide(eprenom_us);
}
if ( (strcmp(p.poste,"")==0) ){bbb=1;
	gtk_widget_show (eposte_us);

}
else {
		  gtk_widget_hide(eposte_us);
}

if ( cnf1==0) {bbb=1;
	gtk_widget_show (econf_us);

}
else {
		  gtk_widget_hide(econf_us);
}

if (bbb == 0){

ajouter_util(p);

GtkWidget *ajouter_user;
ajouter_user=lookup_widget(button,"ajouter_user");
gtk_widget_destroy(ajouter_user);
GtkWidget *afficher_user;
afficher_user = create_afficher_user ();
  gtk_widget_show (afficher_user);
}
}

void
on_radiobutton1_hsm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Homme");
}


void
on_radiobutton2_user_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Femme");
}


void
on_actualiser_user_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_user;
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");
treeview1_user=lookup_widget(afficher_user,"treeview1_user");


afficher_util(treeview1_user);
}


void
on_go_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");
gtk_widget_destroy(afficher_user);
user p;
char id1[30];
char nom1[30];
char prenom1[30];
char CIN1[30];
char sexe1[30];
char date_naissance1[30];
char poste1[30];
char num1[30];
char email1[40];
FILE *f;

f=fopen("util.txt","r");
GtkWidget *modifier1_user;
  modifier1_user = create_modifier1_user ();
  gtk_widget_show (modifier1_user);
GtkWidget *nom_user1;
nom_user1 = lookup_widget (modifier1_user ,"nom_user1");
GtkWidget *prenom_user1;
prenom_user1 = lookup_widget (modifier1_user ,"prenom_user1");
GtkWidget *cin_user1;
cin_user1 = lookup_widget (modifier1_user ,"cin_user1");
GtkWidget *tel_user1;
tel_user1 = lookup_widget (modifier1_user ,"tel_user1");
GtkWidget *email_user1;
email_user1 = lookup_widget (modifier1_user ,"email_user1");
GtkWidget *comboboxentry11_user;
comboboxentry11_user = lookup_widget (modifier1_user ,"comboboxentry11_user");

while(fscanf(f, "%s %s %s %s %s %s %s %s %s \n",id1,nom1,prenom1,CIN1,sexe1,date_naissance1,poste1,num1,email1)!=EOF){
 if (strcmp(id111,id1)==0){
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"nom_user1")),nom1);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"prenom_user1")),prenom1);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"cin_user1")),CIN1);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"tel_user1")),num1);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"email_user1")),email1);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier1_user,"comboboxentry11_user")),poste1);

}}
}


void
on_go_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");

GtkWidget *supprimer1_user;
supprimer1_user = create_supprimer1_user ();
  gtk_widget_show (supprimer1_user);
}


void
on_go_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");
gtk_widget_destroy(afficher_user);
GtkWidget *ajouter_user;
ajouter_user = create_ajouter_user ();
  gtk_widget_show (ajouter_user);
}


void
on_rechercher_user_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview1_user;
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");

treeview1_user=lookup_widget(afficher_user,"treeview1_user");
cherch = lookup_widget (button ,"entre_rechercher_user");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 rechercher_util(treeview1_user,ch);
}


void
on_conf_aj_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
cnf1=1;
}


void
on_treeview1_user_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* genre;
	gchar* dns;
	gchar* poste;
	gchar* num;
	gchar* email;
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &id, 1, &nom,2,&prenom,3,&cin,4,&genre,5,&dns,6,&poste,7,&num,8,&email,-1);
	strcpy(id111,id);
	
	}
}


void
on_conf_supp_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
supprimer_util(id111);
GtkWidget *supprimer1_user;
supprimer1_user=lookup_widget(button,"supprimer1_user");
gtk_widget_destroy(supprimer1_user);
GtkWidget *afficher_user;

  gtk_widget_show (afficher_user);
}


void
on_annuler_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer1_user;
supprimer1_user=lookup_widget(button,"supprimer1_user");
gtk_widget_destroy(supprimer1_user);
GtkWidget *afficher_user;

  gtk_widget_show (afficher_user);
}


void
on_modifier_us_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ecin_us;
ecin_us = lookup_widget (button ,"ecin_us1");
GtkWidget *etel_us;
etel_us = lookup_widget (button ,"etel_us1");
GtkWidget *eemail_us;
eemail_us = lookup_widget (button ,"eemail_us1");
GtkWidget *enom_us;
enom_us = lookup_widget (button ,"enom_us1");
GtkWidget *eprenom_us;
eprenom_us = lookup_widget (button ,"eprenom_us1");
GtkWidget *eposte_us;
eposte_us = lookup_widget (button ,"eposte_us1");
GtkWidget *econf_us;
econf_us = lookup_widget (button ,"econf_us1");


int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";
int bbb=0;
user p;

GtkWidget *nom_user,*prenom_user,*cin_user,*tel_user,*email_user,*comboboxentry1_user,*calendar1_user;
GtkWidget *spinbutton1_user;

nom_user=lookup_widget(button,"nom_user1");
prenom_user=lookup_widget(button,"prenom_user1");
cin_user=lookup_widget(button,"cin_user1");
tel_user=lookup_widget(button,"tel_user1");
email_user=lookup_widget(button,"email_user1");
comboboxentry1_user=lookup_widget(button,"comboboxentry11_user");
calendar1_user=lookup_widget(button,"calendar11_user");
spinbutton1_user=lookup_widget(button,"spinbutton11_user");



gtk_calendar_get_date (GTK_CALENDAR(calendar1_user),
                       &aa,
                       &mm,
                       &jj);

mm=mm+1;
sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,a);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,c);

p.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1_user));
strcpy(p.date_naissance,y);
strcpy(p.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1_user)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom_user)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_user)));
strcpy(p.CIN,gtk_entry_get_text(GTK_ENTRY(cin_user)));
strcpy(p.sexe,sexe2);
strcpy(p.num,gtk_entry_get_text(GTK_ENTRY(tel_user)));
strcpy(p.email,gtk_entry_get_text(GTK_ENTRY(email_user)));


if (verifier_cin (p.CIN)==0 || (strcmp(p.CIN,"")==0)){bbb=1;
	          gtk_widget_show (ecin_us);
}
else {
		  gtk_widget_hide(ecin_us);
}
if (verifier_cin (p.num)==0 || (strcmp(p.num,"")==0)){bbb=1;
	          gtk_widget_show (etel_us);

}
else {
		  gtk_widget_hide(etel_us);
}	

if (verifier_email (p.email)==0 || (strcmp(p.email,"")==0) ){bbb=1;
	gtk_widget_show (eemail_us);

}
else {
		  gtk_widget_hide(eemail_us);
}
if (verifier_lettre (p.nom)==0 || (strcmp(p.nom,"")==0) ){bbb=1;
	gtk_widget_show (enom_us);

}
else {
		  gtk_widget_hide(enom_us);
}
if (verifier_lettre (p.prenom)==0 || (strcmp(p.prenom,"")==0) ){bbb=1;
	gtk_widget_show (eprenom_us);

}
else {
		  gtk_widget_hide(eprenom_us);
}
if ( (strcmp(p.poste,"")==0) ){bbb=1;
	gtk_widget_show (eposte_us);

}
else {
		  gtk_widget_hide(eposte_us);
}
if ( cnf2==0) {bbb=1;
	gtk_widget_show (econf_us);

}
else {
		  gtk_widget_hide(econf_us);
}

if (bbb == 0){
modifier_userr(id111,p);

GtkWidget *modifier1_user;
modifier1_user=lookup_widget(button,"modifier1_user");
gtk_widget_destroy(modifier1_user);
GtkWidget *afficher_user;
afficher_user = create_afficher_user ();
  gtk_widget_show (afficher_user);
}
}

void
on_anuuler_md_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier1_user;
modifier1_user=lookup_widget(button,"modifier1_user");
gtk_widget_destroy(modifier1_user);
GtkWidget *afficher_user;
afficher_user = create_afficher_user ();
  gtk_widget_show (afficher_user);
}


void
on_button4_md_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *label33_sexe;

label33_sexe = lookup_widget(button,"label33_user");
//sexe (s,msg);

gtk_label_set_text(GTK_LABEL(label33_sexe),sexe2);
}


void
on_radiobutton11_user_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe2,"Homme");
}


void
on_radiobutton22_user_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe2,"Femme");
}


void
on_checkbutton11_user_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
cnf2=1;
}


void
on_statique_plat_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
char a3[10];
char b3[10];
char c3[10];
char y3[40]="le jour : ";


char a1[10];
char b1[10];
char c1[10];
char y1[40]="le jour : ";

char a2[10];
char b2[10];
char c2[10];
char y2[40]="le jour : ";

char num[3];

GtkWidget *spinbutton1_semaine;

spinbutton1_semaine = lookup_widget(button,"spinbutton1_semaine");

int z=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1_semaine));

sprintf(num,"%d",z);

GtkWidget *num_semaine;
num_semaine = lookup_widget(button,"num_semaine");
gtk_label_set_text(GTK_LABEL(num_semaine),num);

dechet pl1 = plat1(z);
dechet pl2 = plat2(z);
dechet pl3 = plat3(z);

sprintf(a1,"%d",pl1.x1);sprintf(b1,"%d",pl1.x2);sprintf(c1,"%f",pl1.x3);
strcat(y1,a1);strcat(y1," qui contient ");strcat(y1,c1);(y1," de dechets");strcat(y1," %");

sprintf(a2,"%d",pl2.x1);sprintf(b2,"%d",pl2.x2);sprintf(c2,"%f",pl2.x3);
strcat(y2,a2);strcat(y2," qui contient ");strcat(y2,c2);(y2," de dechets");strcat(y2," %");

sprintf(a3,"%d",pl3.x1);sprintf(b3,"%d",pl3.x2);sprintf(c3,"%f",pl3.x3);
strcat(y3,a3);strcat(y3," qui contient ");strcat(y3,c3);(y3," de dechets");strcat(y3," %");


GtkWidget *plat1;
plat1 = lookup_widget(button,"plat1");
gtk_label_set_text(GTK_LABEL(plat1),y1);
GtkWidget *plat2;
plat2 = lookup_widget(button,"plat2");
gtk_label_set_text(GTK_LABEL(plat2),y2);
GtkWidget *plat3;
plat3 = lookup_widget(button,"plat3");
gtk_label_set_text(GTK_LABEL(plat3),y3);
}


void
on_login_user_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *erreur_pass;

erreur_pass = lookup_widget(button,"erreur_pass");

GtkWidget *username, *password, *windowAcceuil_hsm;
char user[20];
char passw[20];
int trouve;
username = lookup_widget (button, "entry1_user");
password = lookup_widget (button, "entry2_pass");
strcpy(user ,gtk_entry_get_text ( GTK_ENTRY(username)));
strcpy(passw ,gtk_entry_get_text ( GTK_ENTRY(password)));
trouve=verif_pass(user,passw);
if (trouve==1)
{

GtkWidget *auth_user;
auth_user=lookup_widget(button,"auth_user");
gtk_widget_destroy(auth_user);
GtkWidget *afficher_user;
afficher_user = create_afficher_user ();
  gtk_widget_show (afficher_user);
}
else if (trouve==-1){gtk_widget_show (erreur_pass);}
}


void
on_inscri_user_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *auth_user;
auth_user=lookup_widget(button,"auth_user");
gtk_widget_destroy(auth_user);
GtkWidget *inscri_user;
inscri_user = create_inscri_user ();
  gtk_widget_show (inscri_user);
}



void
on_inscri_us_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *login, *pw;
char login1[40];
char passw[40];
login = lookup_widget(button,"entre_username");
pw = lookup_widget(button,"entre_password");
strcpy(login1,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
f=fopen("utilisateur.txt","a+");
if (f != NULL)
{
fprintf(f,"%s %s \n",login1,passw);

}
fclose(f);
GtkWidget *inscri_user;
inscri_user=lookup_widget(button,"inscri_user");
gtk_widget_destroy(inscri_user);
GtkWidget *auth_user;
auth_user = create_auth_user ();
  gtk_widget_show (auth_user);


}
void
on_annuler_ins_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inscri_user;
inscri_user=lookup_widget(button,"inscri_user");
gtk_widget_destroy(inscri_user);
GtkWidget *auth_user;
auth_user = create_auth_user ();
  gtk_widget_show (auth_user);
}


void
on_deconn_user_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_user;
afficher_user=lookup_widget(button,"afficher_user");
gtk_widget_destroy(afficher_user);
GtkWidget *auth_user;
auth_user = create_auth_user ();
  gtk_widget_show (auth_user);
}

