#ifndef FRASE_HH
#define FRASE_HH

#include <vector>
#include <string>

class Frase {
	//Tipus de modul: dades
	//Descripcio del tipus: 


private:
	vector<string> fra;
	int n_paraules;


public:
	//Constructora

	Frase();
	/*Pre: cert*/
	/*Post: el resultat es una frase buida*/

	//Destructora

	~Frase();

	//Consultoras

	int paraules() const;
	/*Pre: cert*/
	/*Post: el resultat es el nombre de paraules d'una frase*/

	


}