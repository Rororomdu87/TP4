#include <iostream>
#include "Header.h"
using namespace std;

void menu()
{
	cout << "************* Menu *************" << endl;
	cout << "1. Ajouter une personne en queue" << endl;
	cout << "2. Retirer la personne en tete" << endl;
	cout << "3. Consulter la personne en tete de file" << endl;
	cout << "4. Calculer la longueur de la file d'attente" << endl;
	cout << "5. Undo" << endl;
	cout << "6. Quitter" << endl << endl;
}

void init(fileAttente f) {
	f.tete = NULL;
	f.queue = NULL;
}

fileAttente filenouv() {
	fileAttente f;
	f.tete = NULL;
	f.queue = NULL;
	return f;
}

void ajouter(fileAttente f, elt x) {
	maillon *nm;
	nm = new maillon;

	if (f.queue == NULL)
	{
		(*nm).numero = x;
		(*nm).suivant = NULL;
		f.queue = nm;
		f.tete = nm;
	}
	else
	{
		nm = f.queue;
		(*nm).suivant = new maillon;
		f.queue = (*nm).suivant;
		(*(f.queue)).numero = x;
		(*(f.queue)).suivant = NULL;
	}
}

void retirer(fileAttente f) {
	maillon *sp;

	if (f.tete == NULL)
	{
		cout << "La file etait deja vide. Aucun element n'a ete supprime" << endl;
	}
	else
	{
		if (f.tete == f.queue)
		{
			init(f);
		}
		else
		{
			sp = f.tete;
			f.tete = (*(f.tete)).suivant;
			(*sp).suivant = NULL;
			delete sp;
		}
	}
}

void consult(fileAttente f) {
	if (f.tete != NULL)
	{
		cout << "La numero en tete est : ";
		cout << (*(f.tete)).numero << endl;
	}
	else
	{
		cout << "Pas d element dans la file." << endl;
	}
}

int longueur(fileAttente f) {
	int l;
	maillon *sp;
	l = 0;

	sp = f.tete;

	if (f.tete == NULL)
	{
		return 0;
	}
	else if (f.tete == f.queue)
	{
		return 1;
	}
	else
	{
		do
		{
			sp = (*sp).suivant;
			l++;
		} while (sp != f.queue);
	}
	return l + 1;
}