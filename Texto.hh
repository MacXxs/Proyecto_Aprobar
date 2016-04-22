#ifndef TEXTO
#define TEXTO

#include "Frase.hh"

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
	vector<Frase> Frases; //vector que conte totes las frases del text
	int numF;             //numero de frases que conte el text
	vector<string> titol; 
	
	
public:
	
	Text();
	
	~Text();
	
	//Construcotores
	void consultar_autor();

	void info();
	
	int consultar_numF();
	
	int consultar_numparaules();
	
	void frases_paraules() 
	
	void frases_expressio();
	
	void taula_de_freq();
	
	//Constructores
	void llegir_text();
	
	void llegir_autor();
	
	void llegir_titol();
	
	bool operator<(const Texto &t) const; //ordena en funcio del titol del text.
};

#endif