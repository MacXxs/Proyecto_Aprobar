#include "Cita.hh"

Cita::Cita() {
	numini = numfin = 0;
}

Cita::~Cita() {}

Cita::crear_cita(string& referencia, char& x, char& y, string& autor, string& titol) {
	this->referencia = referencia;
	this->autor = autor;
	this->titol = titol;
	numini = x - '0';
	numfin = y - '0';
}

Cita::consultar_autor() const {
	return autor;
}

Cita::consultar_referencia() const {
	return referencia;
}

Cita::consultar_titol() const {
	return titol;
}

Cita::consultar_numini() const {
	return numini;
}

Cita::consultar_numfin() const {
	return numfin;
}

Cita::escriure() const {
	cout << referencia << endl;
}