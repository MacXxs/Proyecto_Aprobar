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
		if (par[par.size()-1] == '.' or par[par.size()-1] == ',' or par[par.size()-1] == '!' or par[par.size()-1] == '?' or par[par.size()-1] == ':' or par[par.size()-1] == ';') par.pop_back();
		it = paraules.find(par);
		if (it != paraules.end()) paraules.erase(it);
	}
}

void Frase::buscar_par(string& p, bool& b) {
	b = false;
	for (int i = 0; i < frase.size() and not b; ++i){
		string aux = frase[i];
		if (aux[aux.size()-1] == '.' or aux[aux.size()-1] == ',' or aux[aux.size()-1] == '!' or aux[aux.size()-1] == '?' or aux[aux.size()-1] == ':' or aux[aux.size()-1] == ';') aux.pop_back();
		b = aux == p;
	}
}

bool Frase::consultar_frases(string& p){
	istringstream iss(p);
	string m, aux;
	vector<string> pars;
	while (iss >> m){
		pars.push_back(m);
	}
	int count = 0;
	bool trobada = false;
	for (int i = 0; i < frase.size() and not trobada; ++i){
		aux = frase[i];
		if (aux[aux.size()-1] == '.' or aux[aux.size()-1] == ',' or aux[aux.size()-1] == '?' or aux[aux.size()-1] == '!' or aux[aux.size()-1] == ':' or aux[aux.size()-1] == ';'){
			aux.pop_back();
			if (aux == pars[count])	++count;
			else count = 0;
		}
		else {
			if (aux == pars[count]) ++count;
			else count = 0;
		}
		trobada = count == pars.size();
	}
	return trobada;
}

void Frase::substituir_paraula(string& a, string& b, int& par_subs) {
	for (int i = 0; i < n_paraules; ++i) {
		string aux = frase[i];
		char last;
		if (aux[aux.size()-1] != '.' and aux[aux.size()-1] != ',' and aux[aux.size()-1] != '?' and aux[aux.size()-1] != '!' and aux[aux.size()-1] != ':' and aux[aux.size()-1] != ';') {//l'ultim char es o una vocal o una consonant
			if (a == aux){
				frase[i] = b;
				++par_subs;
			}
		}
		else { //vol dir que l'ultim char de la paraula es o be ':', ',', ';', '.', '?', '!'
			last = aux[aux.size()-1];
			aux.pop_back();
			if (a == aux) {
				frase[i] = b;
				frase[i].push_back(last);
				++par_subs;
			}
		}
	}
}

void Frase::taula_freq(map<string,int>& a) const{
	map<string,int>::iterator it;
	string aux;
	for(int i = 0; i < n_paraules; ++i){
		aux = frase[i];
		if (aux[aux.size()-1] == '.' or aux[aux.size()-1] == ',' or aux[aux.size()-1] == '?' or aux[aux.size()-1] == '!' or aux[aux.size()-1] == ':' or aux[aux.size()-1] == ';') aux.pop_back();
		if (not aux.empty()){
			it = a.find(aux);
			if (it != a.end()) ++it->second;
			else a[aux] = 1;
		}
	}
}

void Frase::llegir(string& frase, int& nump) {
	istringstream iss(frase);
	string paraula;
	while(iss >> paraula){
		this->frase.push_back(paraula);
		++nump;
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