#ifndef CONJ_TEXTOS_HH
#define CONJ_TEXTOS_HH


class Cjt_textos {
	//Tipus de modul: dades
	//Descripcio del tipus:


private:
	map<Autor, Texto> textos;


public:

	//Creadora
	Cjt_textos();
	/*Pre: cert*/
	/*Post: el resultat es un conjunt de textos buit*/

	//Destructora
	
	~Cjt_textos();

	//Modificadores

	void afegir_cita(const Texto& t, int x, int y); //guardar en alguna estructura

	void eliminar_cita(); //eliminar cita de la estructura

	//Consultores

	void info_cita();

	void cites_autor();

	void cites();

	void totes_cites();


};
#endif