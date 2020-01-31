#include "eleve.h"
#include <conio.h>

Eleve::Eleve()
{
	codeEleve = "";
	nom = "";
	prenom = "";
	activiteInscrit = NULL;
}

Eleve::Eleve(string aCodeEleve, string aNom, string aPrenom)
{
	codeEleve = aCodeEleve;
	nom = aNom;
	prenom = aPrenom;
	activiteInscrit = NULL;
}

string Eleve::getCodeEleve()
{
	return codeEleve;
}

string Eleve::getNom()
{
	return nom;
}

string Eleve::getPrenom()
{
	return prenom;
}

Activite *Eleve::getActivite()
{
	return activiteInscrit;
}

void Eleve::inscrireEleve(string aCode, string aNom, string aPrenom)
{
	codeEleve = aCode;
	nom = aNom;
	prenom = aPrenom;
}

void Eleve::InscrireAUneActivite(Activite* pointeurActivite)
{
	activiteInscrit = pointeurActivite;
}