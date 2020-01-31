#ifndef EleveH 
#define EleveH
//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include "activite.h"
using namespace std;

class Eleve
{
private:
	string codeEleve;
	string nom;
	string prenom;
	Activite* activiteInscrit;

public:
	Eleve();
	Eleve(string aCodeEleve, string aNomEleve, string aPrenomEleve);
	string getCodeEleve();
	string getNom();
	string getPrenom();
	Activite *getActivite();
	void inscrireEleve(string, string, string);
	void InscrireAUneActivite(Activite*);

};

#endif

