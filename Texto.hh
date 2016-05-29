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
	
	//Consultores

	/** @brief Indica el nombre de paraules d'una frase
		\pre <em>cert</em>
		\post el resultat es el nombre de paraules d'una frase
	*/
	int paraules() const;
	
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
	int consultar_numf() const;
	
	/** @brief Indica el nombre de paraules del text
		\pre <em>cert</em>
		\post retorna el nombre de paraules del contingut del text
	*/
	int consultar_nump() const;
	
	/** @brief Mostra les frases entre x i y
		\pre <em>arriben dos enters x i y</em>
		\post mostra per pantalla les frases entre la x-essima i la y-essima del contingut del text
	*/
	void consultar_frases(int &x, int &y);
	
    /** @brief Mostra les frases on les paraules tinguin el mateix ordre
		\pre <em>arriben un conjunt de paraules</em>
		\post mostra per pantalla les frases que contenen totes les paraules en el mateix ordre
	*/
	void consultar_frases(string& paraules);
	
    /** @brief Guarda el contingut de la frase
		\pre <em>arriben dos enters x i y i un conjunt de enters i Frase</em>
		\post guardem al conjunt el contingut de la frase x-essima fins la y-essima
	*/
	void consultar_cont_frases(map<int, Frase>& frases, int& x, int& y);
	
	
	/** @brief Mostra totes les paraules del contingut del text
		\pre <em>cert</em>
		\post mostra per pantalla totes les paraules del contingut del text ordenades decreixentment per frequencia;
			en cas d'empat, s'ordenen creixentment primer per llargada, despres alfabeticament
	*/
	void taula_freq();
	
    /** @brief Mostra la taula de frequencies
		\pre <em>cert</em>
		\post mostra per pantalla la taula de frequencies de l'ultim text triat
	*/
	void consultar_taula_freq(); //Es mostra la taula de frequencies
	
     /** @brief Indica si les paraules estan al text, titol o autor del text
		\pre <em>arriba una sequencia de paraules</em>
		\post retorna 1 si totes les paraules del set de paraules
                  es troben al text, autor o al titol
	*/
	int triar_text(string& autor, string& titol, set<string> paraules);
	
    /** @brief Mostra les frases que compleixin l'expressio
        \pre <em>arriba una expressio</em>
        \post es crida a la funcio recur_im per cada frase del text
                  amb l'expressio expres, i si la compleix es mostra per pantalla la frase
    */	
	void recur(string& expres); 

	//Lectura

	/** @brief Llegeix el titol
		\pre <em>arriben el titol, l'autor i el contingut del text</em>
		\post afegim un Text al sistema amb Titol = titol, autor = autor i contingut = contingut
	*/	
	void llegir(string& contingut);
	
private:
	vector<pair<string,int> > parfreq; //conjunt de paraules del text ordenades decreixentment per frequencia, 
						//i en cas d'empat creixentment, primer per llargada i despres afabeticament
	map<int,Frase> map_frases; //vector que conte totes las frases del text
	int nump;             //nombtr de paraules del text
	
	/** @brief Funcio recursiva que mira si la expresisio expres es compleix per la frase f
		\pre <em>expres es la expressio que nosaltres introduim, pos = 0, b = false i f es una de les frases del ultim text triat</em>
		\post per a la frase f es mira que tota la expressio f es compleixi, en cas afirmatiu es retorna b = true i f es mostra per pantalla. Al
			  finalitzar la recursiva pos = expres.size();
	*/
	void recur_im(string& expres, int& pos, bool& b, Frase& f); 
	
	/*invariant: 0 <= parfreq.size() <= nump
				 si (parfreq.size() == nump i parfreq.size() != 0) -> totes les paraules de parfreq tenen frequencia de 1*/
};

#endif
