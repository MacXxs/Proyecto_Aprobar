#include "Cjt_textos.hh"

Cjt_textos::Cjt_textos(){
	//map<string,map<string,Texto> > textos;
	//map<string,map<string,Texto> >::iterator it;
	//map<string,Texto>::iterator it2;
	text_triat = false;
}

Cjt_textos::~Cjt_textos(){}

void Cjt_textos::eliminar_text(){
	if (text_triat) {
		it->second.erase(it2);
		if (it->second.size() == 0) textos.erase(it);
		text_triat = false;
	}
	else cout << "error" << endl; 
}

void Cjt_textos::substituir(string &par1, string &par2){
	if (text_triat){
		par1.erase(0,1);
		par1.pop_back();
		par2.erase(0,1);
		par2.pop_back();
		it2->second.substituir(par1,par2);
	}
	else cout << "error" << endl;
}

void Cjt_textos::afegir_cita(int& x, int& y){
	it2->second.consultar_frases(x,y);
	it2->second.augmentar_numcites();
}
string Cjt_textos::consultar_autor(){
	return it->first;
}

string Cjt_textos::consultar_titol(){
	return it2->first;
}

void Cjt_textos::consultar_contingut(){
	if (text_triat) it2->second.consultar_contingut();
	else cout << "error" << endl;
}

void Cjt_textos::consultar_numf(){
	if (text_triat) cout << it2->second.consultar_numf() << endl;
	else cout << "error" << endl;
}

int Cjt_textos::consultar_num_frases() {
	return it2->second.consultar_numf();
}

void Cjt_textos::consultar_nump(){
	if (text_triat) cout << it2->second.consultar_nump() << endl;
	else cout << "error" << endl;
}

void Cjt_textos::consultar_frases(int& x, int& y){
	if (text_triat) it2->second.consultar_frases(x,y);
	else cout << "error" << endl;
}

void Cjt_textos::consultar_frases(string& paraules){
	if (text_triat) it2->second.consultar_frases(paraules);
	else cout << "error" << endl;
}

void Cjt_textos::consultar_cont_frases(map<int, Frase>& frases, int& x, int& y) {
	it2->second.consultar_cont_frases(frases, x, y);
}

void Cjt_textos::frases(string &expres){
	if (text_triat) it2->second.recur(expres);
	else cout << "error" << endl;
}

void Cjt_textos::taula_freq(){
	it2->second.taula_freq();
}

map<string,Texto>::iterator Cjt_textos::text_actual(){
	return it2;
}

void Cjt_textos::triar_text(string &paraules){
	istringstream iss(paraules);
	set<string> p;
	string paraula;
	while (iss >> paraula) p.insert(paraula);
	int trobats = 0, t;
	map<string,map<string,Texto> >::iterator it = textos.begin();
	map<string,Texto>::iterator it2;
	while (it != textos.end() and trobats < 2){
		it2 = it->second.begin();
		while (it2 != it->second.end() and trobats < 2){
			t = it2->second.triar_text(p);
			trobats += t;
			if (t == 1){
				this->it = it;
				this->it2 = it2;
			}
			t = 0;
			++it2;
		}
		++it;
	}
	if (trobats == 1) {
		text_triat = true;
		taula_freq();
	}
	else {
		text_triat = false;
		cout << "error" << endl;
	}
}

void Cjt_textos::textos_autor(string &autor){
	map<string,Texto>::iterator it = textos[autor].begin();
	while (it != textos[autor].end()){
		cout << '"' << it->first << '"' << endl;
		++it;
	}
}

void Cjt_textos::tots_textos(){
	map<string,map<string,Texto> >::const_iterator it = textos.begin();
	map<string,Texto>::const_iterator it2;
	while (it != textos.end()){
		it2 = it->second.begin();
		while (it2 != it->second.end()){
			cout << it->first << " " << '"' << it2->first << '"' << endl;
			++it2;
		}
		++it;
	}
}

void Cjt_textos::tots_autors(){
	map<string,map<string,Texto> >::iterator it = textos.begin();
	map<string,Texto>::iterator it2;
	int t, f, p;
	while (it != textos.end()){
		t = f = p = 0;
		it2 = it->second.begin();
		while (it2 != it->second.end()){
			++t;
			f += it2->second.consultar_numf();
			p += it2->second.consultar_nump();
			++it2;
		}
		cout << it->first << ' ' << t << ' ' << f << ' ' << p << endl;
		++it;
	}
}

void Cjt_textos::info(){
	cout << it->first << ' ' << '"' << it2->first << '"' << ' ' << it2->second.consultar_numf() << ' ' << it2->second.consultar_nump() << endl;
}

void Cjt_textos::consultar_taula_freq(){
	if (text_triat) it2->second.consultar_taula_freq();
	else cout << "error" << endl;
}

void Cjt_textos::info_text_triat(string& aut, string& tit) {
    aut = it->first;
    tit = it2->first;
}

bool Cjt_textos::hi_ha_text_triat(){
	return text_triat;
}

void Cjt_textos::llegir_tot(string &titol, string &autor, string &text){
	Texto Text;
	if (textos.find(autor) != textos.end()){
		if (textos[autor].find(titol) == textos[autor].end()){
			Text.llegir(titol,autor,text);
			textos[autor][titol] = Text;
		}
	}
	else {
		Text.llegir(titol,autor,text);
		textos[autor][titol] = Text;
	}
}

