/** @file Cita.hh
	@brief Especificació de la classe Cita
*/

#ifndef CITA_HH
#define CITA_HH

#include "Frase.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#include <map>
#endif


/** @class Cita
	@brief Representa una cita el text
*/

class Cita{
    
public:
	
	// Constructora
	
	/** @brief Creadora per defecte
		S'executa automàticament al declarar una cita
		\pre <em>cert</em>
		\post el resultat es una cita buida
	*/
    Cita();
	
	//Destructora
    
    ~Cita();
    
	// Modificadora
	
	/** @brief Dona uns valors a la cita creada
		\pre <em>tenim una cita</em>
		\post modifiquem els valors implicits de la cita
	*/
	void crear_cita(string &referencia, int& x, int& y, string& autor, string& Titol, map<int, Frase>& frases);
	
	
	//Consultores
	
	/** @brief Mostra l'autor de la cita
		\pre <em>cert</em>
		\post el resultat es el nom de l'autor de la cita
	*/
	string consultar_autor() const;
	
	/** @brief Mostra la referencia de la cita
		\pre <em>cert</em>
		\post el resultat es la referencia de la cita
	*/
	string consultar_referencia() const;
	
	/** @brief Mostra el titol de la cita
		\pre <em>cert</em>
		\post el resultat es el titol de la cita
	*/
	string consultar_titol() const;
	
	/** @brief Mostra el el nombre de linia on es troba la primera frase de la cita
		\pre <em>cert</em>
		\post el resultat es el nombre de linia on es troba la primera frase de la cita
	*/
	int consultar_numini() const;
	
	/** @brief Mostra el nombre de linia on es troba la ultima frase de la cita
		\pre <em>cert</em>
		\post el resultat es el nombre de linia on es troba la ultima frase de la cita
	*/
	int consultar_numfin() const;
	
	// /** @brief 
		//\pre <em>cert</em>
		//\post 
	//*/
	//void info() const;
	
	//Escrptura
	
	/** @brief Escriu la referencia de la cita
		\pre <em>tenim una cita amb referencia</em>
		\post escriu per pantalla la referencia de la cita
	*/
	void escriure();
	
    /** @brief Escriu la frase o frases que composen la cita
		\pre <em>tenim una cita</em>
		\post escriu per pantalla la referencia de la cita i el seu contingut
	*/
	void escriure_frases_cita();
    
private:
    string autor;
    string Titol; //string encapsulado con el titulo del texto al que corresponde la cita
    int numini; //numero frase inicial
    int numfin; //numero frase final
    string referencia; //referencia de la cita
    map<int,Frase> frases;
	
	//invariant: frases.size() = numfin - numini
};

#endif
