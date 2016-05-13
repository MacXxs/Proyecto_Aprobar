#ifndef CITA_HH
#define CITA_HH

#include"Frase.hh"

#ifndef NO_DIAGRAM
#include<string>
#endif


class Cita{
    
private:
    istringstream autor;
    vector<string> Titol;
    int numini; //numero frase inicial
    int numfin; //numero frase final
    vector<Frase> vec_frase; //vector de Frases que formen la cita ordenat
    string referencia; //referencia de la cita
	
public:
    Cita();
    
    ~Cita();
    
    void crear_cita(string &referencia, char& x, char& y, vector<Frase>& frases);
    
    
    
    
	
