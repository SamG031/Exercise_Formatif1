#include "activite.h"

Activite::Activite()
{
	codeActivite = "";
	titre = "";
	responsable = "";
}

Activite::Activite(string aCode, string aTitre, string aResponsable)
{
	codeActivite = aCode;
	titre = aTitre;
	responsable = aResponsable;
}

string Activite::getCode() const
{
	return codeActivite;
}

string Activite::getTitre() const
{
	return titre;
}

string Activite::getResponsable() const
{
	return responsable;
}

void Activite::InitialiserActivite(string acode, string aTitre)
{
	codeActivite = acode;
	titre = aTitre;

}

void Activite::AssignerResponsable(string aResponsable)
{
	responsable = aResponsable;
}

//void Activite::setCode(string aCode)
//{
//	codeActivite = aCode;
//}
//
//void Activite::setTitre(string aTitre)
//{
//	titre = aTitre;
//}
//
//void Activite::setResponsable(string aResponsable)
//{
//	responsable = aResponsable;
//}
