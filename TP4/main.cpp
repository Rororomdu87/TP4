#include <iostream>
#include <stdio.h>
#include "Header.h"

using namespace std;

int main() {

	int choix;
	char* x="";
	fileAttente f = filenouv();

	do
	{
		menu();
		cin >> choix;

		switch (choix)
		{
		case 1:
			cout << "Entrer un nom a mettre dans la file : ";
			scanf_s("%s", x);
			ajouter(f, x);
			break;
		case 2:
			retirer(f);
			break;
		case 3:
			consult(f);
			break;
		case 4:
			cout << "La longueur de la file est de : " << longueur(f) << endl;
			break;
		case 5:
			//undo
			break;
		default:
			cout << "Au revoir" << endl;
			break;
		}

	} while (choix != 6);
}