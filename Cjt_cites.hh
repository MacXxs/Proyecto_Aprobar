/** @file Cjt_cites.hh
	@brief Especificació de la classe Cjt_cites
*/

#ifndef CJT_CITES_HH
#define CJT_CITES_HH

#include "Cjt_textos.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <string>
#endif

class Cjt_cites{
  
public:
	
	//Constructora
	
	/** @brief Creadora per defecte
		S'executa automàticament al declarar una frase
		\pre <em>cert</em>
		\post el resultat es un conjunt de cites buit
	*/
	Cjt_cites();
	

	//Destructora
	
	~Cjt_cites();
	
	//Modificadora
	
	/** @brief Afegeix una cita
		\pre <em>arriben dos caracters x i y, i hi ha un text triat</em>
		\post es crida a la funcio afegir_cita de la classe Cjt_textos i s'afegeix una cita 
	 		  al sistema basada en les frases que van de la x-esima a la y-esima del contingut de 
			  l'ultim text triat
	*/
	void afegir_cita(char &x, char &y);
	
	/** @brief Elimina una cita
		\pre <em>hi ha una referencia amb referencia = refer</em>
		\post s'ha eliminat la cita amb referencia = refer i es crida a la funcio eliminar_cita
			  de la classe Cjt_textos
	*/
	void eliminar_cita(string &refer);
	
	/** @brief Mostra informacio sobre una cita
		\pre <em>es passa una referencia d'una cita</em>
		\post es mostra informacio de la cita referenciada (autor, titol. numero de la frase 
			  inicial i numero de la frase final. contingut de la frase o frases que la componen).
	*/
	void info_cita(string &refer);
	
	/** @brief Mostra totes les cites emmagatzemades
		\pre <em>cert</em>
		\post mostra totes les cites emmagatzemades en el sistema (referencia, contingut de les frases.
			  autor i titol del text)
	*/
	void totes_cites();

private:
	
	map<string,Cita> cites; //conjunt de totes les cites;
	
};

#endif
  