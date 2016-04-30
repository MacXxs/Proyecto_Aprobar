#ifndef TEXTO
#define TEXTO

#include<Frase.hh>

#include<set>

struct Autor{
		string nom;
		string cognom;
		bool operator<(const Autor &a) const;
};

struct Paraula{
	string paraula;
	int freq;
	bool operator<(const Paraula &p) const;
};


class Texto {
	
private:
	
	struct Cita{
		Autor autor;
		vector<string> Titol;
		int numini; //numero frase inicial
		int numfin; //numero frase final
		vector<Frase> //vector de Frases que formen la cita ordenat
		string referencia //referencia de la cita
	};
	
	map<int,Cita>;     //mapa de cites del text on l'enter marca el numero de la referencia de la cita 
	
	set<Paraula> parfreq; //conjunt de paraules del text ordenades decreixentment per frequencia, 
						  //i en cas d'empat creixentment, primer per llargada i despres afabeticament
	int numP;            //numero de paraules del contingut del text
	vector<Frase> Texto; //vector que conte totes las frases del text
	int numF;             //numero de frases del contingut del text
	int numcites;         //nombre de cites associades a aquest text
	vector<string> titol; //titol del text 
	
	
public:
	
	//Constructora

	Texto();
	/*Pre: cert*/
	/*Post: el resultat es un text buit*/
	
	//Destructora

	~Texto();
	
	void llegir_titol(string &n);
	/*pre tenim un titol buit
	 \post anem construint el titol a mesura que arriben paraules (n) d'aquest
	 */
	
	void llegir_autor(string &nom, string &cognom);
	/*pre tenim un autor buit
	 \post assignem un nom i un cognom al autor buit
	 */
	
	void llegir_text(string &m);
	
	//Modificadores
	
	void substituir(string &par1, string &par2);
	/*pre cert
	 \post es crida a la funcio subsituir_paraula de la classe Frase per cada frase del contingut
	 */
	
	void afegir_cita(string &referencia, char &x, char &y);
	/*pre arriben dos caracters x i y, i hi ha un text triat
	 \post s'afegeix una cita basada en les frases que van de la x-esima a la y-esima del 
	 contingu del text amb la referencia passada pel primer parametre
	 */
	
	void eliminar_cita(string &referencia);
	/*pre existeix una cita amb una referencia igual a la que es passa pel parametre
	 \post s'elimina la cita amb referencia = referencia
	 */
	
	//Consultores

	int paraules() const;
	/*Pre: cert*/
	/*Post: el resultat es el nombre de paraules d'una frase*/

	void consultar_autor();
	/*Pre: cert*/
	/*Post: mostra l'autor del text*/
	
	void consultar_contingut();
	/*pre cert
	 \post mostra el contingut de l'ultim text triat amb les seves frases numerades a
	partir de l'1
	*/
	
	void incrementar_cites();
	/*pre cert
	 \post cada cop que s'afegeix una cita al text s'incrementa el nombre de cites d'aquest
	 */ 
	
	void info();
	/*Pre: cert*/
	/*Post: mostra l'autor, el titol, el nombre de frases, el nombre
			de paraules i les cites associades del text*/
	
	int consultar_numf();
	/*Pre: cert*/
	/*Post: retorna el nombre de frases del contingut del text*/
	
	int consultar_nump();
	/*Pre: cert*/
	/*Post: retorna el nombre de paraules del contingut del text*/
	
	void consultar_frases(char &x, char &y);
	/*pre cert
	 \post mostra les frases entre la x-esima i la y-esima del contingut del text
	 */
	
	void frases(string &expres);
	/*pre arriba una expressio
	 \post mostra les frases que compleixen la expressio
	 */
	
	void frases_paraules();
	/*Pre: */
	/*Post: */
	
	void frases_expressio();
	/*Pre: */
	/*Post: */
	
	void taula_freq();
	/*Pre: cert*/
	/*Post: mostra totes les paraules del contingut del text ordenades decreixentment per frequencia;
			en cas d'empat, s'ordenen creixentment primer per llargada, despres alfabeticament*/
	
	bool operator<(const Texto &t) const; //ordena en funcio del titol del text.
	
	void cites_autor(string &autor);
	/*pre el text conte cites
	 \post es mostren les cites del autor(referencia, contingut de les frases i titol del text)
	 */
	
	void cites();
	/*pre cert
	 \post es mostren totes les cites del text (referencia, contingut de les frases, autor i el 
	 titol  del text) 
	 */
};

#endif