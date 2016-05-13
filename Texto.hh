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

struct Paraula{
	string paraula;
	int freq;
	bool operator<(const Paraula &p) const;
};

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
		\pre <em>cer</em>
		\post es crida a la funcio subsituir_paraula de la classe Frase per cada frase del contingut
	*/
	void substituir(string &par1, string &par2);
	
	/** @brief Afegeix una cita
		\pre <em>arriben dos caracters x i y, i hi ha un text triat</em>
		\post s'afegeix una cita basada en les frases que van de la x-esima a la y-esima del 
	 	contingut del text amb la referencia passada pel primer parametre (es crida a la funcio
	 	crear_cita de la classe Cita.hh
	*/	
	//Consultores

	/** @brief Indica el nombre de paraules d'una frase
		\pre <em>cert</em>
		\post el resultat es el nombre de paraules d'una frase
	*/
	int paraules();
	
	/** @brief Mostra l'autor del text
		\pre <em>cert</em>
		\post mostra l'autor del text
	*/
	void consultar_autor();
	
	/** @brief Mostra el contingu d'unt text
		\pre <em>cert</em>
		\post mostra el contingut de l'ultim text triat amb les seves frases numerades a
			  partir de l'1
	*/
	void consultar_contingut();
	
	/** @brief Mostra tota la informacio d'un text
		\pre <em>cert</em>
		\post mostra l'autor, el titol, el nombre de frases i el nombre de paraules.
	*/
	void info();
	
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
		\pre <em>cert</em>
		\post mostra les frases entre la x-essima i la y-essima del contingut del text
	*/
	void consultar_frases(char &x, char &y);
	
	/** @brief Mostra les frases que compleixen l'expressio
		\pre <em>arriba una expressio</em>
		\post mostra les frases que compleixen l'expressio
	*/
	void frases(string &expres);
	
	
	void frases_paraules();
	/*Pre: */
	/*Post: */
	
	void frases_expressio();
	/*Pre: */
	/*Post: */
	
	/** @brief Mostra totes les paraules del contingut del text
		\pre <em>cert</em>
		\post mostra totes les paraules del contingut del text ordenades decreixentment per frequencia;
			en cas d'empat, s'ordenen creixentment primer per llargada, despres alfabeticament
	*/
	void taula_freq();
	
	
	bool operator<(const Texto &t) const; //ordena en funcio del titol del text.
	
	/** @brief Mostra les cites d'un autor
		\pre <em>el text conte cites</em>
		\post es mostren les cites del autor(referencia, contingut de les frases i titol del text)
	*/
	void cites_autor(istringstream &aut);
	
	/** @brief Mostra totes les cites del text
		\pre <em>cert</em>
		\post es mostren totes les cites del text (referencia, contingut de les frases, autor i el 
			  titol  del text) 
	*/
	void cites();
	

	//Lectura

	/** @brief Llegeix el titol
		\pre <em>tenim un titol buit</em>
		\post anem construint el titol a mesura que arriben paraules (n) d'aquest
	*/	
	void llegir_titol(string &n);
	
	/** @brief Llegeix l'autor
		\pre <em>tenim un autor buit</em>
		\post assignem un nom i un cognom al autor buit
	*/
	void llegir_autor(string &autor);
	
	/** @brief Llegeix el text
		\pre <em>tenim un text buit</em>
		\post assignem el contingut del text al text buit
	*/
	void llegir_text(string &m);
	
private:
	string autor;
	map<int,Cita> map_cites;  //mapa de cites del text on l'enter marca el numero de la referencia de la cita 
	
	set<Paraula> parfreq; //conjunt de paraules del text ordenades decreixentment per frequencia, 
						  //i en cas d'empat creixentment, primer per llargada i despres afabeticament
	int numP;            //numero de paraules del contingut del text
	map<int,Frase> vec_frases; //vector que conte totes las frases del text
	int numF;             //numero de frases del contingut del text
	int numcites;         //nombre de cites associades a aquest text
	string titol; //titol del text 
	static const int maxfrases = 50;


};

#endif
