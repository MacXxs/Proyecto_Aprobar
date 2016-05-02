#ifndef CJT_CITES_HH
#define CJT_CITES_HH

#include"Cjt_textos.hh"


class Cjt_cites{
  
private:
	
	map<string,Cita> cites; //conjunt de totes les cites;
	
public:
	
	//Constructora
	
	Cjt_cites();
	
	//Destructora
	
	~Cjt_cites();
	
	//Modificadora
	
	void afegir_cita(char &x, char &y);
	/*pre arriben dos caracters x i y, i hi ha un text triat
	 \post es crida a la funcio afegir_cita de la classe Cjt_textos i s'afegeix una cita 
	 al sistema basada en les frases que van de la x-esima a la y-esima del contingut de 
	 l'ultim text triat
	 */
	
	void eliminar_cita(string &refer);
	/*pre hi ha una referencia amb referencia = refer
	 \post s'ha eliminat la cita amb referencia = refer i es crida a la funcio eliminar_cita
	 de la classe Cjt_textos
	 */
	
	void info_cita(string &refer);
	/*pre es passa una referencia d'una cita
	 \post es mostra informacio de la cita referenciada (autor, titol. numero de la frase 
	 inicial i numero de la frase final. contingut de la frase o frases que la componen).
	 */
	
	void totes_cites();
	/*pre cert
	 \post mostra totes les cites emmagatzemades en el sistema (referencia, contingut de les frases.
	 autor i titol del text)
	 */
};

#endif
  