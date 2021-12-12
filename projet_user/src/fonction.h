#include<gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int verif(char log[], char verif[]);

typedef struct 
{
int id;
char date_naissance[30];
char nom[30];
char prenom[30];
char CIN[30];
char poste[30];
char num[30];
char email[30];
char sexe[30];
}user;
typedef struct 
{
int x1;
int x2;
float x3;

}dechet;
