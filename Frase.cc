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

void Frase::triar_text(set<string>& paraules){
	set<string>::iterator it;
	string par;
	for (int i = 0; i < n_paraules and not paraules.empty(); ++i){
		par = frase[i];
		if (par[par.size()-1] < 'A' or par[par.size()-1] > 'z') par.pop_back();
		it = paraules.find(par);
		if (it != paraules.end()) paraules.erase(it);
	}
}
		

void Frase::substituir_paraula(string& a, string& b, int& par_subs) {
	for (int i = 0; i < n_paraules; ++i) {
		string aux;
		char last;
		if (frase[i][frase[i].size()-1] >= 'a' and frase[i][frase[i].size()-1] <= 'z') { //l'ultim char esta entre la a i la z 
			if (a == frase[i]){
				frase[i] = b;
				++par_subs;
			}
		}
		else { //vol dir que l'ultim char de la paraula es o be ':', ',', ';', '.', '?', '!'
			aux = frase[i];
			aux.pop_back();
			if (a == aux) {
				last = frase[i][frase[i].size() - 1];
				b.push_back(last);
				frase[i] = b;
				++par_subs;
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

void Frase::llegir(string& frase, int& nump) {
	istringstream iss(frase);
	string paraula;
	while(iss >> paraula){
		this->frase.push_back(paraula);
		++nump;
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