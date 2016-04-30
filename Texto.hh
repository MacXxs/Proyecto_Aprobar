#ifndef TEXTO
#define TEXTO



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
	
	set<Paraula> parfreq; //conjunt de paraules del text ordenades decreixentment per frequencia, 
						  //i en cas d'empat creixentment, primer per llargada i despres afabeticament
	int numP;            //numero de paraules del contingut del text
	vector<Frase> Texto; //vector que conte totes las frases del text
	int numF;             //numero de frases del contingut del text
	int numcites;         //nombre de cites associades a aquest text
	vector<string> titol; 
	
	
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
};

#endif