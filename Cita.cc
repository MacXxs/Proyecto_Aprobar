#include "Cita.hh"

Cita::Cita() {
	numini = numfin = 0;
}

Cita::~Cita() {}

void Cita::crear_cita(string& referencia, char& x, char& y, string& autor, string& titol) {
	this->referencia = referencia;
	this->autor = autor;
	this->titol = titol;
	numini = x - '0';
	numfin = y - '0';
}

void Cita::consultar_autor() const {
	return autor;
}

void Cita::consultar_referencia() const {
	return referencia;
}

void Cita::consultar_titol() const {
	return titol;
}

void Cita::consultar_numini() const {
	return numini;
}

void Cita::consultar_numfin() const {
	return numfin;
}

void Cita::escriure() {
	cout << referencia << endl;
}