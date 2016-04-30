/** @file Cjt_textos.hh
	@brief Especificació de la classe Cjt_textos
*/

#ifndef CONJ_TEXTOS_HH
#define CONJ_TEXTOS_HH

#include "Texto.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <string>
#include <set>
#endif


/** @class Cjt_textos
	@brief Representa un conjunt de tots els textos


*/ 


class Cjt_textos {

public:

	//Constructores


	/** @brief Creadora per defecte
		S'executa automàticament al declarar un conjunt
		\pre <em>cert</em>
		\post El resultat es un conjunt de textos buit
	*/
	Cjt_textos();
	
	//Destructora
	
	~Cjt_textos();

	//Modificadores
	
	/** @brief Llegeix un titol, un autor i un text
		\pre <em>cert</em>
		\post es crida a la funcio llegir_titol, llegir_autor,
		 llegir_text de la classe Texto per afegir un titol al Text que s'esta tractant
	*/
	void llegir_tot(string &titol, string &autor, string &text);

	//Consultores
	
	/** @brief Proporciona la posicio del text que volem escollir
		\pre <em>cert</em>
		\post retorna un iterator apuntant al utlim text triat
	*/
	map<Autor,set<Texto> >::iterator text_actual();
	
	/** @brief Tria un text
		\pre <em>el paràmetre implícit conté els textos</em>
		\post retorna el text escollit
	*/
	void triar_text();

	/** @brief Mostra els textos d'un autor
		\pre <em>arriba un autor
		\post mostra tots els textos d'un determinat autor, 
			ordenats alfabeticament per títol
	*/
	void textos_autor(Autor a);

	/** @brief Mostra els textos del conjunt
		\pre <em>cert</em>
		\post mostra tots els textos del paràmetre implícit
			(només títol i autor de cada text), ordenats
			per autor i després per títol
	*/
	void tots_textos();
	
	/**@brief Mostra els autors del conjunt
		\pre <em>cert</em>
		\post mostra tots els autors (ordre alfabeticament) del paràmetre implícit
			indicant el nombre de textos que hi consten,
			el nombre total de frases i de paraules del 
			contingut dels seus textos
	*/
	void tots_autors();
	
private:
	map<Autor, set<Texto> > textos;
	map<Autor,set<Texto> >::iterator it;
	

};
#endif