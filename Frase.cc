#include "Frase.hh"
#include <string>
#include <sstream>
#include <vector>


Frase::Frase() {
	n_paraules = 0;
}

Frase::~Frase() {}

Frase::paraules() const {
	return n_paraules;
}

Frase::substituir_paraula(string& a, string& b) {
	for (int i = 0; i < n_paraules; ++i) {
		string aux;
		char last;
		if (frase[i][frase[i].size()] >= 'a' and frase[i][frase[i].size()] <= 'z') { //no es ni ':', ni ',', ni ';' 
			if (a == frase[i]) frase[i] = b;
		}
		else { //vol dir que l'ultim char de la paraula es o be ':', ',', ';', '.', '?', '!'
			aux = frase[i];
			aux.pop_back();
			if (a == aux) {
				last = frase[i][frase[i].size() - 1];
				b.push_back(last);
				frase[i] = b;
			}
		}
	}
}


Frase::llegir(string& paraula) {
	istringstream iss(paraula);
	while (iss >> paraula) {
		frase.push_back(paraula);
		++n_paraules;
	}
}