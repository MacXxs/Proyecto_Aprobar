#include "Cita.hh"
#include <iostream>

Cita::Cita() {
	numini = numfin = 0;
}

Cita::~Cita() {}

void Cita::crear_cita(string& referencia, char& x, char& y, string& autor, string& Titol) {
	this->referencia = referencia;
	this->autor = autor;
	this->Titol = Titol;
	numini = x - '0';
	numfin = y - '0';
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