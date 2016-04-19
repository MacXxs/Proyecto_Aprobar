#ifndef "TEXTO"
#define "TEXTO"

#include "Frase.hh"

class Texto {
	
private:
	struct autor{
		string nom;
		string cognom;
		bool operator<(const autor &a) const;
	};
	
	struct Paraula{
		string paraula;
		int freq;
		bool operator<(const Paraula &p) const;
	};
	
	set<Paraula> parfreq; //conjunt de paraules del text ordenades decreixentment per frequencia, 
						  //i en cas d'empat creixentment, primer per llargada i despres afabeticament
	vector<Frase> Frases; //vector que conte totes las frases del text
	int numF;             //numero de frases que conte el text
	Frase titul; 
	
public:
	
	Text();
	
	~Text();
	
	//Construcotores
	Frase consultar_autor();

	Frase consultar_titul();
	
	int consultar_numF();
	
	//Constructores
	void llegir_text();
	
	void llegir_autor();
	
	void llegir_titul();
	
	
	
	
	
	
	
	
	
	

	
	
	