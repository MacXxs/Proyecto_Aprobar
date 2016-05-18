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
#include <sstream>
#endif


/** @class Cjt_textos
	@brief Representa un conjunt de tots els textos
*/

class Cjt_textos {

public:

	//Constructora

	
	/** @brief Creadora per defecte
		S'executa automàticament al declarar un conjunt
		\pre <em>cert</em>
		\post El resultat es un conjunt de textos buit
	*/
	Cjt_textos();

	//Destructora
	
	~Cjt_textos();

	//Modificadores
	
	/** @brief Elimina l'ultim text triat
		\pre <em>tenim un text triat</em>
		\post el text triat s'elimina i no hi ha un altre text triat 
			  fins que no es torni a cridar a la funcio triar text
	*/
	void eliminar_text();
	
	/** @brief Canvia dues paraules
		\pre <em>tenim un text triat</em>
		\post es crida a la funcio substitur de la classe Texto per canviar totes les aparicions de la paraula
	 par1 per par2
	*/
	void substituir(string &par1, string &par2);
    
    /** @brief Afegeix una cita
		\pre <em>arriben dos caracters x i y i una referencia</em>
		\post es crida a la funcio afegir_cita de la classe Texto
	*/
    void afegir_cita(char& x, char& y);
	
	//Consultores
	
	/** @brief Consulta l'autor de l'ultim text triat
		\pre <em>tenim un text triat</em>
		\post es crida la funcio consultar_autor de la classe Texto de l'ultim text triat
	*/
	string consultar_autor();
	
	string consultar_titol(); 
	
	/** @brief Consulta el contingut de l'ultim text triat
		\pre <em>tenim un text triat</em>
		\post es crida a la funcio conultar_contingut de la classe Texto de l'ultim text triat
	*/
	void consultar_contingut();
	
	/** @brief Consulta el nombre de frases de l'ultim text triat
		\pre <em>tenim un text triat</em>
		\post es crida a la funcio conultar_numf de la classe Texto de l'ultim text triat
	*/
	void consultar_numf();
	
	/** @brief Consulta el nombre de paraules de l'ultim text triat
		\pre <em>tenim un text triat</em>
		\post es crida a la funcio conultar_nump de la classe Texto de l'ultim text triat
	*/
	void consultar_nump();
	
	/** @brief Consulta les frases entre x i y de l'ultim text triat
		\pre <em>tenim un text triat i es passen uns valors x i y</em>
		\post es crida a la funcio consultar_frases de la classe Texto de l'ultim text triat
	*/
	void consultar_frases(char &x, char &y);
	
	/** @brief Mostra les frases del contingut de l'ultim text triat que compleixin l'expressio
		\pre <em>tenim un text triat i es passa una expressio</em>
		\post es crida a la funcio frases de la classe Texto
	*/
	void frases(string &expres);
	
	/** @brief 
		\pre <em>tenim un text triat</em>
		\post es crida a la funcio taula_freq de la classe Texto de l'ultim text triat
	*/
	void taula_freq();
	
	/** @brief Proporciona la posicio del text que volem escollir
		\pre <em>cert</em>
		\post retorna un iterator apuntant al utlim text triat
	*/
	map<string,Texto>::iterator text_actual();

	/** @brief Tria un text
		\pre <em>el paràmetre implícit conté els textos</em>
		\post retorna el text escollit
	*/
	void triar_text(string &paraules);
	
	/** @brief Mostra els textos d'un autor
		\pre <em>arriba un autor
		\post mostra tots els textos d'un determinat autor, 
			ordenats alfabeticament per títol
	*/
	void textos_autor(string &autor);
	
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
	
	/**@brief Mostra la informacio de l'ultim text triat
		\pre <em>tenim un text triat</em>
		\post crida a la funcio info de la classe Texto de l'ultim text triat
	*/
	void info();

    //Lectura
    
    /** @brief Llegeix un titol, un autor i un text
		\pre <em>cert</em>
		\post es crida a la funcio llegir de la classe Texto per afegir un Text al sistema.
	*/
	void llegir_tot(string &titol, string &autor, string &text);
	
    
private:
	map<string,map<string,Texto> > textos; //mapa de set de textos ordenat per autor i set ordenat per titol del text
	map<string,map<string,Texto> >::iterator it; // iterador que apunta al conjunt de textos d'un autor
	map<string,Texto>::iterator it2; //iterador que apunta al ultim text triat del conjunt de textos d'un autor
	bool text_triat; 				

};

#endif