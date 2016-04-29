#ifndef CONJ_TEXTOS_HH
#define CONJ_TEXTOS_HH

#include<Texto.hh>

#include<map>

class Cjt_textos {
	//Tipus de modul: dades
	//Descripcio del tipus:


private:
	map<Autor, set<Texto> > textos;
	map<Autor,set<Texto> >::iterator it;
	

public:

	//Creadora

	Cjt_textos();
	/*Pre: cert*/
	/*Post: el resultat es un conjunt de textos buit*/

	//Destructora
	
	~Cjt_textos();

	//Modificadores
	
	void llegir_tot(string &titol, string &autor, string &text);
	/*pre cert
	 \post es crida a la funcio llegir_titol, llegir_autor, llegir_text de la classe Texto per afegir un titol al Text que s'esta tractant
	*/

	//Consultores
	
	map<Autor,set<Texto> >::iterator text_actual();
	/*pre cert
	 \post retorna un iterator apuntant al utlim text triat
	*/

	void triar_text();
	/*Pre: el paràmetre implícit conté els textos*/
	/*Post: retorna el texto escogido*/

	void textos_autor(Autor a);
	/*Pre: */
	/*Post: mostra tots els textos d'un determinat autor, 
			ordenats alfabeticament per títol*/

	void tots_textos();
	/*Pre: cert*/
	/*Post: mostra tots els textos del paràmetre implícit
			(només títol i autor de cada text), ordenats
			per autor i després per títol*/
	void tots_autors();
	/*Pre: cert*/
	/*Post: mostra tots els autors (ordre alfabeticament) del paràmetre implícit
			indicant el nombre de textos que hi consten,
			el nombre total de frases i de paraules del 
			contingut dels seus textos*/


};
#endif