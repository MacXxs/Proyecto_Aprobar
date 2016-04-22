#ifndef FRASE_HH
#define FRASE_HH

#include<vector>
#include<string>

class Frase {
	//Tipus de modul: dades
	//Descripcio del tipus: 


private:
	vector<string> frase;
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

	//Lectura i escriptura

	void llegir();
	/*Pre: al canal d'entrada estan esperant els strings que llegirem,
			acabat en punt, interrogant o exclamacio*/
	/*Post: al parametre implicit tenim el conjunt de strings que hem llegit*/

	void escriure() const;
	/*Pre: cert*/
	/*Post: s'han escrit pel canal estandard de sortida els strings del parametre implicit*/

};
#endif