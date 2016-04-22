#ifndef CJT_CITES_HH
#define CJT_CITES_HH

#include"Cjt_textos.hh"


class Cjt_cites{
  
private:
	
	struct Cita{
		Autor autor;
		vector<string> Titol;
		int numini; //numero frase inicial
		int numfin; //numero frase final
	};
	string ref; //referencia;
	map<ref,Cita> cites; //conjunt de totes les cites;
	
public:
	void afegir_cita(const Texto& t, int x, int y); //guardar en alguna estructura
	
	void eliminar_cita(string refer); //eliminar cita de la estructura
	
	void info_cita(string refer); //mostra tota la informacio d'una cita
	
	void cites_autor(Autor aut); //mostra les cites d'un autor
	
	void cites(); //mostra totes les cites de l'ultim text triat
	
	void totes_cites(); //mostra totes les cites de tot el Cjt_cites
};

#endif
  