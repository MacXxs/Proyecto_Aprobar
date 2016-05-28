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
	
    /** @brief Mira si hi ha tot el conjunt de paraules al text
		\pre <em>arriba un conjunt de paraules</em>
		\post mira si hi ha totes les paraules del conjunt al text, en cas
                  afirmatiu, les elimina del set
	*/
	void triar_text(set<string>& paraules); 
	
    /** @brief Mira si les paraules estan a la frase
		\pre <em>arriben unes paraules i un bool b</em>
		\post b es true si totes les paraules estan a la frase
	*/
	void buscar_par(string& p, bool& b);
	
    /** @brief Indica si la frase conte les paraules
		\pre <em>arriben unes paraules</em>
		\post retorna true si la frase conte les paraules passades per parametre
	*/
	bool consultar_frases(string& paraules); //mostra la frase, si aquesta conte les paraules que es passen per parametre
	
	//Modificadora

	/** @brief S'intercanvien dues paraules
		\pre <em>arriben dos paraules a = A, b = B</em>
		\post es canvien totes les aparicions de la paraula a per la b
	*/
	void substituir_paraula(string& a, string& b, int& par_subs);
	
    /** @brief Afegeix les paraules de la frase a la taula de frequencies
		\pre <em>arriba un map de strings i enters</em>
		\post afegeix les paraules de la frase a la taula de freq, al map de string i int
	*/
	void taula_freq(map<string,int>& parfreq) const; //afegeix les paraules de la frase a la taula de frequencies
	
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