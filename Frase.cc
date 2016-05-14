#include "Frase.hh"
#include <string>
#include <sstream>
#include <vector>


Frase::Frase() {
	//vector<string> frase;
	n_paraules = 0;
}

Frase::~Frase() {}

int Frase::paraules() const {
	return n_paraules;
}

void Frase::substituir_paraula(string& a, string& b) {
	for (int i = 0; i < n_paraules; ++i) {
		string aux;
		char last;
		if (frase[i][size()-1] >= 'a' and frase[i][size()-1] <= 'z') { //no es ni ':', ni ',', ni ';' 
			if (a == frase[i]) frase[i] = b;
		}
		else { //vol dir que l'ultim char de la paraula es o be ':', ',', ';', '.', '?', '!'
			aux = frase[i];
			aux.pop_back();
			if (a == aux) {
				last = frase[i][size() - 1];
				b.push_back(last);
				frase[i] = b;
			}
		}
	}
}

void Frase::taula_freq(map<string,int>& a){
	map<string,int>::iterator it;
	for(int i = 0; i < n_paraules; ++i){
		it = a.find(frase[i]);
		if (it != a.end()) it->second;
		else a[frase[i]] = 1;
	}
}
	
	


void Frase::llegir(string& paraula) {
	istringstream iss(paraula);
	while (iss >> paraula) {
		frase.push_back(paraula);
		++n_paraules;
	}
}

void Frase::escriure() const {
	bool primer = true;
	for (int i = 0; i < frase.size(); ++i) {
		if (primer) {
			cout << frase[i];
			primer = false;
		}
		else cout << ' ' << frase[i];
	}
}