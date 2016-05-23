/** @file Texto.hh
	@brief Especificació de la classe Texto
*/

#ifndef TEXTO_HH
#define TEXTO_HH

#include "Frase.hh"

#ifndef NO_DIAGRAM
#include <set>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#endif

/** @class Texto
	@brief Representa un conjunt de frases
*/

class Texto {	
	
public:
	
	//Constructora

    /** @brief Creadora amb un titol
        \pre <em>cert</em>
        \post el resultat es un text amb titol
    */
	Texto(string& titol);
	
	/** @brief Creadora per defecte
		\pre <em>cert</em>
		\post el resultat es un text buit
	*/
	Texto();
	
	//Destructora

	~Texto();
		
	//Modificadores

	/** @brief Intercanvia dues paraules
		\pre <em>cert</em>
		\post es crida a la funcio subsituir_paraula de la classe Frase per cada frase del contingut
	*/
	void substituir(string &par1, string &par2);
	
	/** @brief Contador del nombre de cites
		\pre <em>cert</em>
		\post augmentem en un el nombre de cites
	*/
	void augmentar_numcites();
	
	//Consultores

	/** @brief Indica el nombre de paraules d'una frase
		\pre <em>cert</em>
		\post el resultat es el nombre de paraules d'una frase
	*/
	int paraules();
	
	/** @brief Indica el titol del text
		\pre <em>cert</em>
		\post retorna el titol del text
	*/
	string consultar_titol();
	
	/** @brief Mostra l'autor del text
		\pre <em>cert</em>
		\post mostra per pantalla l'autor del text
	*/
	void consultar_autor();
	
	/** @brief Mostra el contingu d'unt text
		\pre <em>cert</em>
		\post mostra per pantalla el contingut de l'ultim text triat amb les seves frases numerades a
			  partir de l'1
	*/
	void consultar_contingut();
	
	/** @brief Indica el nombre de frases del text
		\pre <em>cert</em>
		\post retorna el nombre de frases del contingut del text
	*/
	int consultar_numf();
	
	/** @brief Indica el nombre de paraules del text
		\pre <em>cert</em>
		\post retorna el nombre de paraules del contingut del text
	*/
	int consultar_nump();
	
	/** @brief Mostra les frases entre x i y
		\pre <em>arriben dos caracters x i y</em>
		\post mostra per pantalla les frases entre la x-essima i la y-essima del contingut del text
	*/
	void consultar_frases(char &x, char &y);
	
	void consultar_cont_frases(map<int, Frase>& frases, char&x, char& y);
	
	/** @brief Mostra les frases que compleixen l'expressio
		\pre <em>arriba una expressio</em>
		\post mostra per pantalla les frases que compleixen l'expressio
	*/
	void frases(string &expres);
	
	/** @brief Mostra totes les paraules del contingut del text
		\pre <em>cert</em>
		\post mostra per pantalla totes les paraules del contingut del text ordenades decreixentment per frequencia;
			en cas d'empat, s'ordenen creixentment primer per llargada, despres alfabeticament
	*/
	void taula_freq();
	
     /** @brief Indica si les paraules estan al text, titol o autor del text
		\pre <em>arriba una sequencia de paraules</em>
		\post retorna 1 si totes les paraules del set de paraules
                  es troben al text, autor o al titol
	*/
	int triar_text(set<string> paraules);
	
    /** @brief Ordena en funcio del titol
        \pre <em>arriba un text</em>
        \post ordena el conjunt en funcio del titol del text
    */
	bool operator<(const Texto &t) const; //ordena en funcio del titol del text.

	//Lectura

	/** @brief Llegeix el titol
		\pre <em>arriben el titol, l'autor i el contingut del text</em>
		\post afegim un Text al sistema amb Titol = titol, autor = autor i contingut = contingut
	*/	
	void llegir(string& titol, string& autor, string& contingut);
	
private:
	string titol; 
	string autor; 
	vector<pair<string,int> > parfreq; //conjunt de paraules del text ordenades decreixentment per frequencia, 
						//i en cas d'empat creixentment, primer per llargada i despres afabeticament
	map<int,Frase> map_frases; //vector que conte totes las frases del text
	int numcites;         //nombre de cites associades a aquest text
	int nump;             //nombtr de paraules del text
};

#endif
