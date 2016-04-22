#ifndef CONJ_TEXTOS_HH
#define CONJ_TEXTOS_HH

#include<Texto.hh>

#include<map>

class Cjt_textos {
	//Tipus de modul: dades
	//Descripcio del tipus:


private:
	map<Autor, set<Texto> > textos;


public:

	//Creadora

	Cjt_textos();
	/*Pre: cert*/
	/*Post: el resultat es un conjunt de textos buit*/

	//Destructora
	
	~Cjt_textos();

	//Modificadores

	void afegir_text(const Texto& t);
	/*Pre: el paràmetre implícit pot ser buit*/
	/*Post: s'ha afegit el text al paràmetre implícit*/
	
	void eliminar_text(const Texto& t);
	/*Pre: el paràmetre implícit conté els textos de cada Autor*/
	/*Post: s'ha eliminat del paràmetre implícit l'últim text triat*/

	//Consultores

	Texto triar_text(const vector<string> &par);
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