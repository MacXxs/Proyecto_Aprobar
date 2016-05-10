#include "Frase.hh"
#include <string>
#include <sstream>
#include <vector>


Frase::Frase() {
	n_paraules = 0;
}

Frase::paraules() const {
	return n_paraules;
}

Frase::substituir_paraula(string& a, string& b) {
	a = b;
}

Frase::llegir(string& paraula) {
	istringstream iss(paraula);
	iss >> paraula;
	while (paraula != "." or paraula != "?" or paraula != "!") {
		frase.push_back(paraula);
		iss >> paraula;
	}
}