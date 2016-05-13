/** @file Frase.hh
	@brief Especificació de la classe Frase
*/

#ifndef FRASE_HH
#define FRASE_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
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
	
	//Modificadora

	/** @brief S'intercanvien dues paraules
		\pre <em>arriben dos paraules a = A, b = B</em>
		\post es canvien totes les aparicions de la paraula a per la b
	*/
	void substituir_paraula(string& a, string& b);
	
	//Lectura

	/** @brief Llegeix una frase
		\pre <em>cert</em>
		\post es va formant una frase a partir de les paraules que arriben
	*/
	void llegir(istringstream paraula);

private:
	vector<string> frase;
	int n_paraules;

};
#endif