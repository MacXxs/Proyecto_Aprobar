#ifndef TEXTO
#define TEXTO



#include<set>

struct Autor{
		string nom;
		string cognom;
		bool operator<(const autor &a) const;
};

struct Paraula{
	string paraula;
	int freq;
	bool operator<(const Paraula &p) const;
};


class Texto {
	
private:
	vector<string> frase;
	set<Paraula> parfreq; //conjunt de paraules del text ordenades decreixentment per frequencia, 
						  //i en cas d'empat creixentment, primer per llargada i despres afabeticament
	//vector<Frase> Frases; //vector que conte totes las frases del text
	int numF;             //numero de frases que conte el text
	vector<string> titol; 
	
	
public:
	
	//Constructora

	Texto();
	/*Pre: cert*/
	/*Post: el resultat es un text buit*/
	
	//Destructora

	~Texto();
	
	//Consultores

	int paraules() const;
	/*Pre: cert*/
	/*Post: el resultat es el nombre de paraules d'una frase*/

	void consultar_autor();
	/*Pre: cert*/
	/*Post: mostra l'autor del text*/

	void info();
	/*Pre: cert*/
	/*Post: mostra l'autor, el titol, el nombre de frases, el nombre
			de paraules i les cites associades del text*/
	
	int consultar_numF();
	/*Pre: cert*/
	/*Post: retorna el numero de frases del text*/
	
	int consultar_numparaules();
	/*Pre: cert*/
	/*Post: retorna el nombre de paraules d'un text*/
	
	void frases_paraules();
	/*Pre: */
	/*Post: */
	
	void frases_expressio();
	/*Pre: */
	/*Post: */
	
	void taula_de_freq();
	/*Pre: cert*/
	/*Post: mostra totes les paraules del contingut del text ordenades decreixentment per frequencia;
			en cas d'empat, s'ordenen creixentment primer per llargada, despres alfabeticament*/
	
	bool operator<(const Texto &t) const; //ordena en funcio del titol del text.
};

#endif