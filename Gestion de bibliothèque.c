#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* 
#########################################################################################################################
#												LES STRUCTURES 															#
#########################################################################################################################
*/

typedef struct{
	int j,m,a;
}date;

typedef struct{
	int number;
	char titre[30],auteur[30];
}livre;


typedef struct {
		int num;
		char prenom[100];
		char nom[100];
		char adresse[100];
}adherent;

typedef struct{
	int num_Empr;
	adherent num_adherent;
	livre num_livre;
	date date_Empr,Date_Ret;
}emprunt;




/* 
#########################################################################################################################
#											DECLARATION DES VARIABLES / STRUCTURES / FONCTIONS							#
#########################################################################################################################
*/

void menuG();
void livres();
void adherents();
void systemlogin();
void emprunts();

int find_variable;
int x=2,xl=2,xa = 2;

livre L[100];
emprunt E[100];
adherent A[200];


/* 
#########################################################################################################################
#											UN SYSTEM DE LOGIN		PAS ENCORE TERMINE									#
#########################################################################################################################
*/
void systemlogin()
{
	
	char user[50],pass[50];
	strcpy(user,"admin"); strcpy(pass,"admin");
	
	printf("##### Bienvenue dans le laboratoire ! #### \n \n \n \n");
	printf("-----------------------------------------------------------------------------\n");
	printf("- 				Espace Client 		            	    -\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("				| Username : ");
	scanf("%s",&user);
	printf("				| Mot de passe : ");
	scanf("%s",&pass);
	
	if((strcmp (user,"admin") == 0) && strcmp(pass,"admin") == 0)
	{
		printf("\n \nBIENVENUE DANS VOTRE ESPACE ADMINISTRATEUR \n");
		printf("Redirection vers le menu .. \n");
		sleep(2);
		system("CLS");
		menuG();
	}
	else
	{
		printf("Username/password incorrect ou le compte n'existe pas \n ");
	
	}
}
void inscription()
{
	char nomcompte[10],motdepasse[30];
	printf("---------------------------------------------------------------------\n");
	printf("- 				Inscription		      -\n");
	printf("---------------------------------------------------------------------\n");
	printf("- Veuillez inserer le nom du compte souhaite : ");
	scanf("%d",&nomcompte);
	printf("\n- Veuillez inserer le mot de passe souhaite : ");
	scanf("%d",&motdepasse);
	
}


/* 
#########################################################################################################################
#											MAIN CODE 															#
#########################################################################################################################
*/


int main()
{	
	// DECLARATION DES LIVRES
	L[0].number = 1;
	strcpy(L[0].auteur,"Robert KIYOSAKI");
	strcpy(L[0].titre,"Pere riche, pere pauvre");
	
	L[1].number = 2;
	strcpy(L[1].auteur,"Robert AXELROD");
	strcpy(L[1].titre,"Donnant Donnant");
	
	
	
	// DECLARATION DES ADHERENTS
	A[0].num = 1;
	strcpy(A[0].nom,"BOUBN");
	strcpy(A[0].prenom,"Hamza");
	strcpy(A[0].adresse,"48 avenue la resistance, Hassan, Rabat");
	
	A[1].num = 2;
	strcpy(A[1].nom,"AZIKI");
	strcpy(A[1].prenom,"Tarik");
	strcpy(A[1].adresse,"34 rue misr, Mimosas, Kenitra");
	
	

	// DECLARATION DES EMPRUNTS
	E[0].num_Empr = 1;
	E[0].date_Empr.j = 07; E[0].date_Empr.m = 8; E[0].date_Empr.a = 2020,E[0].Date_Ret.j = 07,E[0].Date_Ret.m = 9,E[0].Date_Ret.a = 2020;
	
	E[1].num_Empr = 2;
	E[1].date_Empr.j = 9; E[1].date_Empr.m = 9; E[1].date_Empr.a = 2020,E[1].Date_Ret.j = 07,E[1].Date_Ret.m = 9,E[1].Date_Ret.a = 2020;



	menuG(); // APPEL AU MENU GENERAL
		
		
	}
/* 
#########################################################################################################################
#											MENU PRINCIPAL																#
#########################################################################################################################
*/
void menuG()
{
		int choice;
		
		do{
			printf("\t\t				----------------------------\n");
			printf("\t\t				| - [1]  - Les livres     -| \n");
			printf("\t\t				| - [2]  - Les adherents  -|\n");
			printf("\t\t				| - [3]  - Les emprunts   -|\n");
			printf("\t\t				----------------------------\n");
			printf("\t\t				| - [4]  - Se deconnecter -|\n");
			printf("\t\t				----------------------------\n");

	printf("\t\t\t\t\t\t 	 	");
			scanf("%d",&choice);
			if(choice < 1 || choice > 4)
				printf("				\n !! Choix invalide !!"); sleep(2); system("CLS");
		}while(choice < 1 || choice > 4);
		
		
		switch(choice)
		{
			case 1 : system("CLS"); livres(); break; // APPEL A LA FONCTION LIVRE
			case 2 : system("CLS"); adherents(); break; // APPEL A LA FONCTION DADHERENTS
			case 3 : system("CLS"); emprunts(); break; // APPEL A LA FONCTION EMPRUNTS
			case 4 : system("CLS"); menuG(); break; // APPEL A LA FONCTION MENU PRINCIPAL (SE DECONNECTER PAS ENCORE TERMINE)
		}
	}
	
/* 
#########################################################################################################################
#											FONCTION DE LIVRE														#
#########################################################################################################################
*/	
void livres()
{

	
	int n,i,j;
	int found,choice;
	char choixlivre[10];
		

do {
	printf("\t\t			--------------------------------------\n");
	printf("\t\t			| - [1]  - Affichage des livres     -| \n");
	printf("\t\t			| - [2]  - Ajout des livres	    -|\n");
	printf("\t\t			| - [3]  - Suppression des livres   -|\n");
	printf("\t\t			| - [4]  - Modification des livres  -|\n");
	printf("\t\t			| -----------------------------------|\n");
	printf("\t\t			| - [5]  - Retour au menu principal -|\n");
	printf("\t\t			--------------------------------------\n");

	printf("\t\t\t\t\t\t\t  ");
	scanf("%d",&choice);
	
	
	
	
	switch(choice)
	{
	case 1 : 
		// AFFICHAGE DES LIVRES EXISTANTS
		
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 					AFFICHAGE DES LIVRES		            	  			 	-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");
		printf("			[NUM]\t\t\t[AUTEUR]\t\t\t[TITRE]\n\n");
		for(i=0;i<xl;i++)
		{
			printf("			[%d]			[%s]				[%s]\n",L[i].number,L[i].auteur,L[i].titre);
			
		}
		printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n");
		printf("\n \n \n \n"); system("pause"); system("cls"); break;
	
	case 2 : 
	
		// AJOUT DES LIVRES AU STRUCTURES DE LIVRES
		do{
		system("CLS");
		printf("Combien de livre vous voulez ajouter ?\n");
		scanf("%d",&n);
		}while(n < 1 || n > 3);
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 						AJOUT DES LIVRES		            	  			 	-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");

		for(i=0;i<n;i++)
		{
			do{
				printf("\n => ID du livre : ");
				scanf("%d", &L[xl].number );
					for ( j = 0 , found = 0 ; j<xl ; j++ )
					{
						if (L[xl].number == L[j].number )
 	   					found = 1;
					}
				
					if ( found == 1 )
						printf("ERREUR ! L'ID existe deja. \n");
			}while( found == 1 );
		
			printf("  - L'auteur du livre : ");
			scanf("%s",&L[xl].auteur);
			printf("  - Titre du livre :  ");
			scanf("%s",&L[xl].titre);
			printf("\n \t \t \t		-------------------------------------");
			printf("\n \t \t \t		- Ajout du livre [%d] avec success ! -\n",L[xl].number);
			printf("\t \t \t		-------------------------------------\n\n");
			sleep(2);
			xl++;
		}
			system("CLS"); break;
	
	case 3 :
		
		// SUPPRESSION DES LIVRES EXISTANTS AVEC L'ID
		
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 					SUPPRESSION DES LIVRES		            	  			 	-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");

		do
		{
			printf("\n- Entrer l\'ID du livre a supprimer: ");
			scanf("%d", &find_variable );
			for ( i = 0 , found = 0 ; i<xl && found == 0 ; i++ )
			{
    			if ( find_variable == L[i].number )
				{    found = 1 ;
					for ( j = i ; j < xl ; j++ )
					{
						L[j] = L[j+1];
					}
						printf("\n \t \t \t		-------------------------------------------");
						printf("\n \t \t \t		- SUPPRESION du livre [%d] avec success ! -\n",find_variable);
						printf("\t \t \t		-------------------------------------------\n\n");
         			x--;
				}
			}
			if (found == 0)
			{
				printf("	- ERREUR ! l'ID que vous avez entre n'existe pas ! \n");
			}
				
		}while ( found == 0);
		
		printf("\n \n \n \n"); system("pause"); system("cls"); break;
		
	case 4 :
		// MODIFICATION DES LIVRES EXISTANTS AVEC LID
		
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 					MODIFICATION DES LIVRES		            	  			 	-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");
	
		
		printf("=> L'ID du livre a modifier : ");
		scanf("%d",&find_variable);
		for(i=0;i<xl;i++)
		{
			if(find_variable == L[i].number)
			{
				printf("\n - LE LIVRE A ETE RETROUVE AVEC SUCCESS  \n\n ");
				
				printf("\n \n ---------------------------------------------------------------------------------------------------------------------- \n \n");
				
				printf("		[NUM]\t\t\t[AUTEUR]\t\t\t[TITRE]\n\n");

				printf("		[%d]			[%s]				[%s]\n",L[i].number,L[i].auteur,L[i].titre);
			
				printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n");

						printf("\n => Reinserer l'auteur du livre : ");
						fflush(stdin);
						gets(L[i].auteur);	
						printf("\n => Reinserer le Titre du livre : ");
						gets(L[i].titre);
					
				printf("\n \t \t \t		---------------------------------------------");
				printf("\n \t \t \t		- Modification du livre [%d] avec success ! -\n",find_variable);
				printf("\t \t \t		---------------------------------------------\n\n");
			}
		}
		
		
		printf("\n \n \n \n"); system("pause"); system("cls"); break;
		case 5 : system("CLS"); menuG(); break;

	}
}while(choice != 6);
}
/* 
#########################################################################################################################
#											FONCTION DES ADHERENTS														#
#########################################################################################################################
*/	

void adherents()
{

	int n,i,j;
	int found,choice;
	int find_variable;
	char choixlivre[10];
		


do {
	printf("\t\t			----------------------------------------\n");
	printf("\t\t			| - [1]  - Affichage des adherents    -| \n");
	printf("\t\t			| - [2]  - Ajout des adherents	      -|\n");
	printf("\t\t			| - [3]  - Suppression des adherents  -|\n");
	printf("\t\t			| - [4]  - Modification des adherents -|\n");
	printf("\t\t			| -------------------------------------|\n");
	printf("\t\t			| - [5]  - Retour au menu principal   -|\n");
	printf("\t\t			----------------------------------------\n");
	printf("\t\t\t\t\t\t	   ");
	scanf("%d",&choice);
	
	
	
	
	switch(choice)
	{
	case 1 :
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 					AFFICHAGE DES ADHERENTS		            	  			 	-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");
		printf("	[NUM]		[NOM]		[PRENOM]		[ADRESSE]\n\n");
		for(i=0;i<xa;i++)
		{
			printf("	[%d]		[%s]		[%s]   		[%s]\n",A[i].num,A[i].nom,A[i].prenom,A[i].adresse);
			
		}
		printf("\n \n \n \n"); system("pause"); system("cls"); break;
	
	case 2 :
		do{
			system("CLS");
			printf("Combien d'adherent vous voulez ajouter ?\n");
			scanf("%d",&n);
		}while(n < 1 || n > 3);
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 						AJOUT DES ADHERENTS		            	  			 	-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");
		for(i=0;i<n;i++)
		{
			do{
				printf("\n => NUM d'adherent : ");
				scanf("%d", &A[xa].num );
					for ( j = 0 , found = 0 ; j<xa ; j++ )
					{
						if (A[xa].num == A[j].num )
 	   					found = 1;
					}
				
					if ( found == 1 )
						printf("ERREUR ! L'ID existe deja. \n");
			}while( found == 1 );
		
			printf("  - Le nom d'adherent : ");
			scanf("%s",&A[x].nom);
			printf("  - Le prenom d'adherent:  ");
			scanf("%s",&A[x].prenom);
			printf("  - L'adresse d'adherent:  ");
			fflush(stdin);
			scanf("%s",&A[x].adresse);
			printf("\n \t \t \t		--------------------------------------");
			printf("\n \t \t \t		- Ajout d'adherent [%d] avec success !-\n",A[xa].num);
			printf("\t \t \t		--------------------------------------\n\n");
			sleep(2);
			xa++;
		}
			system("CLS"); break;
	
	case 3 :
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 					SUPPRESION DES ADHERENTS		            	  			-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");
		do
		{
			printf("\n - Entrer le NUM d'adherent a supprimer: ");
			scanf("%d", &find_variable );
			for ( i = 0 , found = 0 ; i<xa && found == 0 ; i++ )
			{
    			if ( find_variable == A[i].num )
				{    found = 1 ;
					for ( j = i ; j < xa ; j++ )
					{
						A[j] = A[j+1];
					}
						printf("\n \t \t \t		-------------------------------------------");
						printf("\n \t \t \t		- SUPPRESION d'adherent [%d] avec success !-\n",find_variable);
						printf("\t \t \t		-------------------------------------------\n\n");
						x--;
				}
			}
			if (found == 0)
			{
				printf("	- ERREUR ! l'ID que vous avez entre n'existe pas ! \n");
			}
				
		}while ( found == 0);
		
		printf("\n \n \n \n"); system("pause"); system("cls"); break;
		
	case 4 :
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 					MODIFICATION DES ADHERENTS		            	  			-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");	
		
		printf("=> L'ID d'adherent a modifier : ");
		scanf("%d",&find_variable);
		for(i=0, found = 0;i<xa;i++)
		{
			if(find_variable == A[i].num)
			{
				printf("\n LE LIVRE A ETE RETROUVE AVEC SUCCESS  \n\n ");
				
				printf("\n \n ---------------------------------------------------------------------------------------------------------\n \n");
				
				printf("		[NUM]\t[NOM]\t\t[PRENOM]\t\t[ADRESSE]\n\n");
				printf("		[%d]\t[%s]\t\t[%s]   \t\t[%s]\n",A[i].num,A[i].nom,A[i].prenom,A[i].adresse);
				
				printf("\n \n ---------------------------------------------------------------------------------------------------------- \n \n");

						printf("\n => Reinserer le nom d'adherent : ");
						fflush(stdin);
						gets(A[i].nom);	
						printf("\n => Reinserer le prenom d'adherent : ");
						gets(A[i].prenom);
						printf("\n => Reinserer l'adresse d'adherent : ");
						gets(A[i].adresse);
						found = 1;
					
			}
		}
		if(found == 0)
		{
			printf("- ID introuvable");
		}
		
		printf("\n \n \n \n"); system("pause"); system("cls"); break;
		
		
		case 5 : system("CLS"); menuG(); break;

	}
}while(choice != 6);
}


/* 
#########################################################################################################################
#											FONCTION DES EMPRUNTS														#
#########################################################################################################################
*/	

void emprunts()
{


	
	
	int n,i,j;
	int found,choice;
	int find_variable;
	char choixlivre[10];
	
	for(i=0;i<xl;i++)
	{
		E[i].num_livre.number = L[i].number;
		E[i].num_adherent.num = A[i].num;
	
	}	
	
do {
	printf("\t\t			--------------------------------------\n");
	printf("\t\t			| - [1]  - Affichage des emprunts   -| \n");
	printf("\t\t			| - [2]  - Ajout des emprunts	    -|\n");
	printf("\t\t			| - [3]  - Suppression des emprunts -|\n");
	printf("\t\t			| - [4]  - Modification des emprunts-|\n");
	printf("\t\t			| -----------------------------------|\n");
	printf("\t\t			| - [5]  - Retour au menu principal -|\n");
	printf("\t\t			--------------------------------------\n");

	printf("\t\t\t\t\t\t 	   ");
	scanf("%d",&choice);
	
	
	switch(choice)
	{
		
	case 1 :
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 					AFFICHAGE DES EMPRUNTS		            	  			 	-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");
		printf("	[NUM EMPRUNT]\t[NUM LIVRE]\t\t[NUM ADHERENT]\t\t[DATE_EMPRUNT]\t\t[DATE_RETOUR]\n\n");
		for(i=0;i<x;i++)
		{
			printf("	[%d]\t\t[%d]\t\t\t[%d]\t\t\t[%d/%d/%d]\t\t[%d/%d/%d]\n",E[i].num_Empr,E[i].num_livre.number,E[i].num_adherent.num,E[i].date_Empr.j,E[i].date_Empr.m,E[i].date_Empr.a,E[i].Date_Ret.j,E[i].Date_Ret.m,E[i].Date_Ret.a);
		
		}
		printf("\n \n \n \n"); system("pause"); system("cls"); break;
	
	case 2 :
		do{
			system("CLS");
			printf("- Combien d'adherent vous voulez ajouter ?\n");
			scanf("%d",&n);
		}while(n < 1 || n > 3);
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 						AJOUT DES EMPRUNTS		            	  			 	-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");
		for(i=0;i<n;i++)
		{
			do{
				printf("\n => NUM d'emprunt : ");
				scanf("%d", &E[x].num_Empr );
					for ( j = 0 , found = 0 ; j<x ; j++ )
					{
						if (E[x].num_Empr == E[j].num_Empr )
 	   					found = 1;
					}
				
					if ( found == 1 )
						printf("ERREUR ! L'ID existe deja. \n");
			}while( found == 1 );
		
			printf("\n - La liste des livres existants : \n");
			printf("\n \n ---------------------------------------------------------------------------------------------------------------------- \n \n");
			printf("		[NUM]-\t\t\t[AUTEUR]-\t\t\t[TITRE]\n\n");
			for(i=0;i<xl;i++)
			{
			printf("		[%d]			[%s]				[%s]\n",L[i].number,L[i].auteur,L[i].titre);
			
			}
			printf("\n \n ---------------------------------------------------------------------------------------------------------------------- \n \n");
			
			printf("\nChoisisez un livre a lier : ");
			scanf("%d",&E[i].num_livre); 	
			system("CLS");
		
			printf("\n- La liste des adherents existants :");	
			printf("\n \n ---------------------------------------------------------------------------------------------------------------------- \n \n");
			printf("[NUM]\t[NOM]\t\t[PRENOM]\t\t	[ADRESSE]\n\n");
			
			for(i=0;i<xa;i++)
			{
				printf("[%d]\t[%s]\t\t[%s]   	\t\t[%s]\n",A[i].num,A[i].nom,A[i].prenom,A[i].adresse);			
			}
			printf("\n \n ----------------------------------------------------------------------------------------- \n \n");
			printf("\nChoisisez un adherent a lier : ");
			scanf("%d",&E[x].num_adherent); 
			do{
				printf("\n Entrer la date d'emprunt (JOUR/MOIS/ANNEE):");
				scanf("%d/%d/%d",&E[x].date_Empr.j,&E[x].date_Empr.m,&E[x].date_Empr.a);
			}while((E[x].date_Empr.j < 1 || E[x].date_Empr.j > 31) || (E[x].date_Empr.m < 1 || E[x].date_Empr.m > 12) || (E[x].date_Empr.a < 2020  || E[x].date_Empr.j > 2030));		
			
			printf("\n \t \t \t	--------------------------------------");
			printf("\n \t \t \t	- Ajout d'emprunt [%d] avec success !-\n",E[x].num_Empr);
			printf("\t \t \t	--------------------------------------\n\n");
			sleep(1);
			x++;
		}
			system("CLS"); break;
	
	case 3 :
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 						SUPPRESSION DES EMPRUNTS		            	  			-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");
		do
		{
			printf("\n => Entrer le NUM d'emprunt a supprimer: ");
			scanf("%d", &find_variable);
			for ( i = 0 , found = 0 ; i<x && found == 0 ; i++ )
			{
    			if ( find_variable == E[i].num_Empr )
				{    found = 1 ;
					for ( j = i ; j < x ; j++ )
					{
						E[j] = E[j+1];
					}
				printf("\n \t \t \t	------------------------------------------");
				printf("\n \t \t \t	- Suppresion l'emprunt [%d] avec success !-\n",find_variable);
				printf("\t \t \t	------------------------------------------\n\n");
         			x--;
				}
			}
			if (found == 0)
			{
				printf("	- ERREUR ! l'ID que vous avez entre n'existe pas ! \n");
			}
				
		}while ( found == 0);
		
		printf("\n \n \n \n"); system("pause"); system("cls"); break;
		
	case 4 :
		system("CLS");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("- 						MODIFICATION DES EMPRUNTS		            	  			-\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n\n");		
		
		printf("=> L'ID d'emprunt a modifier : ");
		scanf("%d",&find_variable);
		for(i=0;i<x;i++)
		{
			if(find_variable == E[i].num_Empr)
			{
				printf("\n L'EMPRUNT A ETE TROUVE AVEC SUCCESS  \n\n ");
				
				printf("\n \n ------------------------------------------------------------------------------------------------------------ \n \n");
				
				printf("	[NUM EMPRUNT]\t[NUM LIVRE]\t\t[NUM ADHERENT]\t\t[DATE_EMPRUNT]\t\t[DATE_RETOUR]\n\n");
				printf("	[%d]\t\t[%d]\t\t\t[%d]\t\t\t[%d/%d/%d]\t\t[%d/%d/%d]\n",E[i].num_Empr,E[i].num_livre.number,E[i].num_adherent.num,E[i].date_Empr.j,E[i].date_Empr.m,E[i].date_Empr.a,E[i].Date_Ret.j,E[i].Date_Ret.m,E[i].Date_Ret.a);
				
				printf("\n \n ------------------------------------------------------------------------------------------------------------ \n \n");

				printf("				| - Modification (Date Du retour) - |\n\n ");
				do{
					printf("=> Inserer la date (JOUR/MOIS/ANNEE) : ");
					scanf("%d/%d/%d",&E[i].Date_Ret.j,&E[i].Date_Ret.m,&E[i].Date_Ret.a);
				}while((E[i].Date_Ret.j < 1 || E[i].Date_Ret.j > 31) || (E[i].Date_Ret.m < 1 || E[i].Date_Ret.m > 12) || (E[i].Date_Ret.a < 2020  || E[i].Date_Ret.a > 2030));
				printf("\n \t \t \t	-------------------------------------------------");
				printf("\n \t \t \t	- Modification de la date du retour avec success !-\n");
				printf("\t \t \t	------------------------------------------------\n\n");
							
			}
		}
		
		printf("\n \n \n \n"); system("pause"); system("cls"); break;
		

	case 5 : system("CLS"); menuG();
	}
}while(choice != 6);


	
	
}



