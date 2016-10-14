#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Header.h"

using namespace std;

int main() {

	int choix = 3;
	elt x;
	fileAttente f = filenouv();

	do
	{
		menu();
		cin >> choix;

		switch (choix)
		{
		case 1:
			cout << "Entrer un entier a mettre dans la file :";
			cin >> x;
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
		default:
			cout << "Au revoir !" << endl;
			break;
		}

	} while (choix != 5);
}