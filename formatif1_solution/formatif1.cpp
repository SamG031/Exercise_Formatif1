#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "..\screen\screen.h"
using namespace std;

#include "activite.h" 
#include "eleve.h" 
#include "donnees.h"

Donnees lesDonneesDuProgramme;



int nombreActivitesReelles = 0;
int nombreElevesReels = 0;

char AfficherMenu();
//partie 1
void AjouterActivite();
void AfficherLesActivites();
void Afficher(Activite aActivite);

//partie 2
void AjouterLesEleves();
void AfficherLesEleves();
void Afficher(Eleve aLesEleve);
void InscrireUnEleve(string, string, string);

//partie 3
void InscrireEleveActivite();
int RechercherEleve(string eleveVoulu);
int RechercherActivite(string activiteVoulu);
void AfficherLesInscriptions();


int main()
{
	char choix = ' ';
	while (choix != '0')
	{
		choix = AfficherMenu();
		switch (choix)
		{
		case '1': AjouterActivite();
			break;
		case '2': AfficherLesActivites();
			break;
		case '3': AjouterLesEleves();
			break;
		case '4': AfficherLesEleves();
			break;
		case '5': InscrireEleveActivite();
			break;
		case '6': AfficherLesInscriptions();
			break;
		}
	}
}

//----------------------------------------------------------------------------------------
char AfficherMenu()
{
	char choix;
	ClrScr();
	Gotoxy(15, 4);
	cout << "1- Ajouter une activite";
	Gotoxy(15, 6);
	cout << "2- Afficher toutes les activites";
	Gotoxy(15, 8);
	cout << "3- Ajouter des eleves";
	Gotoxy(15, 10);
	cout << "4- Afficher les eleves";
	Gotoxy(15, 12);
	cout << "5- Inscrire un eleve a une activite";
	Gotoxy(15, 14);
	cout << "6- Afficher les inscriptions d'une activite";
	Gotoxy(15, 16);
	cout << "0- Arreter";
	Gotoxy(15, 18);
	cout << "Choix: ";
	cin >> choix;
	return choix;
}

//----------------------------------------------------------------------------------------
void AjouterActivite()
{
	string code;
	string titre;
	string responsable;
	ClrScr();
	cout << "Code activite: ";
	cin >> code;
	cout << "Titre: ";
	cin >> titre;
	cout << "Responsable: ";
	cin >> responsable;
	//ajoutez les instructions permettant d'inscrire la nouvelle activité dans le tableau des activités
	//utilisez nombreActivitesReelles comme indice pour le tableau
	//lesActivites[nombreActivitesReelles].setCode(code);
	lesDonneesDuProgramme.lesActivites[nombreActivitesReelles].InitialiserActivite(code, titre);
	lesDonneesDuProgramme.lesActivites[nombreActivitesReelles].AssignerResponsable(responsable);


	nombreActivitesReelles++;
}

//----------------------------------------------------------------------------------------
void AfficherLesActivites()
{
	ClrScr();
	int i;
	Activite aActivite;

	for (i = 0; i < nombreActivitesReelles; i++)
	{
		Afficher(lesDonneesDuProgramme.lesActivites[i]);
	}


	_getch();
}

void Afficher(Activite aActivite)
{
	string titre = aActivite.getTitre();
	string responsable = aActivite.getResponsable();

	cout << "Nom de l'activite: " + titre + ". Le Responsable: " + responsable + ".\n";
}
//----------------------------------------------------------------------------------------
void AjouterLesEleves()
{
	InscrireUnEleve("111", "Laroche", "Arthur");
	InscrireUnEleve("222", "Cailloux", "Fred");
	InscrireUnEleve("333", "Cailloux", "Delima");
	InscrireUnEleve("444", "Laroche", "Bertha");
	InscrireUnEleve("555", "Cailloux", "Agathe");
	InscrireUnEleve("666", "Laroche", "Boumboum");
	InscrireUnEleve("777", "Mirock", "Pierre");
	InscrireUnEleve("888", "Roche", "Onezime");
	InscrireUnEleve("999", "Roche", "Alfreda");
	InscrireUnEleve("112", "Cailloux", "Dino");
}

//----------------------------------------------------------------------------------------
void AfficherLesEleves()
{
	ClrScr();
	int i;
	//Activite aActivite;

	for (i = 0; i < nombreElevesReels; i++)
	{
		Afficher(lesDonneesDuProgramme.lesEleves[i]);

		
	}

	_getch();
}

void Afficher(Eleve aLesEleve)
{
	string codeE = aLesEleve.getCodeEleve();
	string nomE = aLesEleve.getNom();
	string prenomE = aLesEleve.getPrenom();

	cout << "Code de l'Eleve: " + codeE + "\n Nom de l'Eleve: " + nomE + ", " + prenomE + ".\n";
}

//----------------------------------------------------------------------------------------
void InscrireUnEleve(string inCode, string inNom, string inPrenom)
{
	string codeE = inCode;
	string nomE = inNom;
	string prenomE = inPrenom;

	lesDonneesDuProgramme.lesEleves[nombreElevesReels].inscrireEleve(codeE, nomE, prenomE);

	nombreElevesReels++;
}

//----------------------------------------------------------------------------------------
void InscrireEleveActivite()
{
	
	string eleve;
	string activite;
	int cptEleve;
	int cptActivite;
	ClrScr();
	cout << "Code de l'eleve a inscrire: ";
	cin >> eleve;
	cptEleve = RechercherEleve(eleve);
	Afficher(lesDonneesDuProgramme.lesEleves[cptEleve]);
	cout << "Activite desiree: ";
	cin >> activite;
	cptActivite = RechercherActivite(activite);
	Afficher(lesDonneesDuProgramme.lesActivites[cptActivite]);

	lesDonneesDuProgramme.lesEleves[cptEleve].InscrireAUneActivite(&lesDonneesDuProgramme.lesActivites[cptActivite]);
	
	cout << "L'inscription s'est effectue avec succes.";

	_getch();
}

//----------------------------------------------------------------------------------------
int RechercherEleve(string inCodeVoulu)
{
	int cptEleve = 0;
	bool trouve = false;
	while (trouve == false && cptEleve < maxEleves)
	{
		if (lesDonneesDuProgramme.lesEleves[cptEleve].getCodeEleve() == inCodeVoulu)
		{
			trouve = true;
		}
		cptEleve++;
	}
	return cptEleve-1;
}

//----------------------------------------------------------------------------------------
int RechercherActivite(string inCodeActiviteVoulue)
{
	bool trouve = false;
	int cptActivite = 0;
	while (trouve == false && cptActivite < maxActivites/*nombreActivites*/)
	{
		if (lesDonneesDuProgramme.lesActivites[cptActivite].getCode() == inCodeActiviteVoulue)
		{
			trouve = true;
		}
		
		cptActivite++;

	}

	if (trouve == false)
	{
		cptActivite = 0;
	}
	return cptActivite-1;
}
//----------------------------------------------------------------------------------------
void AfficherLesInscriptions()
{
	string activite;
	ClrScr();
	cout << "Code de l'activite: ";
	cin >> activite;

	if (RechercherActivite(activite) != -1)
	{



		for (int i = 0; i < nombreElevesReels; i++)
		{
			if (lesDonneesDuProgramme.lesEleves[i].getActivite() != NULL)
			{
				if (lesDonneesDuProgramme.lesEleves[i].getActivite()->getCode() == activite)
				{
					Afficher(lesDonneesDuProgramme.lesEleves[i]);
				}
			}
			
		}
	}

	_getch();
}







