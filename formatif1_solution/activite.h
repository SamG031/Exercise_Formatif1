#ifndef ACTIVITE_H 
#define ACTIVITE_H

#include "..\screen\screen.h"
#include <string>
#include <iostream>
using namespace std;

class Activite
{
private:
	string codeActivite;
	string titre;
	string responsable;

public:
	Activite();
	Activite(string aCode, string aTitre, string aResponsable);
	string getCode() const;
	string getTitre() const;
	string getResponsable() const;
	//void setCode(string aCode);
	//void setTitre(string aTitre);
	//void setResponsable(string aResponsable);
	void InitialiserActivite(string, string);
	void AssignerResponsable(string);

};


#endif