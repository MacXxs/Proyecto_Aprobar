#include "Cita.hh"
#include <iostream>

Cita::Cita() {
	numini = numfin = 0;
}

Cita::~Cita() {}

void Cita::crear_cita(string& referencia, char& x, char& y, string& autor, string& Titol, map<int, Frase>& frases) {
	this->referencia = referencia;
	this->autor = autor;
	this->Titol = Titol;
	numini = x - '0';
	numfin = y - '0';
	this->frases = frases;
}

string Cita::consultar_autor() const {
	return autor;
}

string Cita::consultar_referencia() const {
	return referencia;
}

string Cita::consultar_titol() const {
	return Titol;
}

int Cita::consultar_numini() const {
	return numini;
}

int Cita::consultar_numfin() const {
	return numfin;
}

void Cita::escriure() {
	cout << referencia << endl;
}

void escriure_frases_cita() {
	for (map<int, Frase>::iterator it = frases.begin(); it != frases.end(); ++it) {
		cout << it->first << ' ' << it->second.escriure() << endl;
	}
}