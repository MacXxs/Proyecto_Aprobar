/** @file Frase.hh
	@brief Especificació de la classe Frase
*/

#ifndef FRASE_HH
#define FRASE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#endif

using namespace std;


/** @class Frase
	@brief Representa un conjunt de strings
*/

class Frase {

public:

	//Constructora

	/** @brief Creadora per defecte
		S'executa automàticament al declarar una frase
		\pre <em>cert</em>
		\post el resultat es una frase buida
	*/
	Frase();

	//Destructora

	~Frase();

	//Consultoras
	
	/** @brief Indica el nombre de paraules d'una frase
		\pre <em>cert</em>
		\post el resultat es el nombre de paraules d'una frase
	*/	
	int paraules() const;
	
	void triar_text(set<string>& paraules); //consulta si a la frase hi ha alguna o totes les paraules del text, en cas afirmatiu la/les elimina del set
	
	//Modificadora

	/** @brief S'intercanvien dues paraules
		\pre <em>arriben dos paraules a = A, b = B</em>
		\post es canvien totes les aparicions de la paraula a per la b
	*/
	void substituir_paraula(string& a, string& b, int& par_subs);
	
	void taula_freq(map<string,int>& parfreq); //afegeix les paraules de la frase a la taula de frequencies
	
	//Lectura

	/** @brief Llegeix una frase
		\pre <em>cert</em>
		\post genera una frase a partir d'una frase encapsulada en un string
	*/
	void llegir(string& frase, int& nump);

	//Escriptura
	
	/** @brief Escriu una frase
		\pre <em>tenim una frase</em>
		\post escriu per pantalla la frase
	*/
	void escriure() const;

private:
	vector<string> frase;
	int n_paraules;

};
#endif