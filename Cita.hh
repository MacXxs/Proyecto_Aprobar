/** @file Cita.hh
	@brief Especificació de la classe Cita
*/

#ifndef CITA_HH
#define CITA_HH

#include "Frase.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#endif


/** @class Cita
	@brief Representa una cita el text
*/

class Cita{
    
public:
	
	// Constructora
	
    Cita();
	
	//Destructora
    
    ~Cita();
    
	// Modificadora
	
    void crear_cita(string &referencia, char& x, char& y, vector<Frase>& frases, string& autor, vector<string>& Titol);
	
	
	//Consultores
	
	void consultar_autor() const;
	
	void consultar_referencia() const;
	
	void consultar_titol() const;
	
	void consultar_numini() const;
	
	void consultar_numfin() const;
	
	//Escrptura
	
	void escriure() const;
	
    
private:
    string autor;
    vector<string> Titol;
    int numini; //numero frase inicial
    int numfin; //numero frase final
    vector<Frase> vec_frase; //vector de Frases que formen la cita ordenat
    string referencia; //referencia de la cita
}
