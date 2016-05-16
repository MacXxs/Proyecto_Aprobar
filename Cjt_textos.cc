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
		text_triat = false;
	}
	else cout << "Error al elimnar text (no hi ha text triat)" << endl; 
}

void Cjt_textos::llegir_tot(string &titol, string &autor, string &text){
	Texto Text;
	Text.llegir(titol,autor,text);
	textos[autor][titol] = Text;
}


void Cjt_textos::substituir(string &par1, string &par2){
	it2->second.substituir(par1,par2);
}

void Cjt_textos::afegir_cita(char& x, char& y){
	it2->second.consultar_frases(x,y);
	it2->second.augmentar_numcites();
}
void Cjt_textos::consultar_autor(){
	cout << it->first << endl;
}

void Cjt_textos::consultar_contingut(){
	it2->second.consultar_contingut();
}

void Cjt_textos::consultar_numf(){
	cout << it2->second.consultar_numf() << endl;
}

void Cjt_textos::consultar_nump(){
	cout << it2->second.consultar_nump() << endl;
}

void Cjt_textos::consultar_frases(char& x, char& y){
	it2->second.consultar_frases(x,y);
}

//void Cjt_textos::frases(string &expres); 

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
	int trobats = 0;
	map<string,map<string,Texto> >::iterator it = textos.begin();
	map<string,Texto>::iterator it2;
	for(int i = 0; i < textos.size(); ++i){
		it2 = it->second.begin();
		for (int j = 0; j < it->second.size() and trobats < 2; ++j){
			trobats += it2->second.triar_text(p);
			if (trobats == 1){
				it = this->it;
				it2 = this->it2;
			}
		}
		++it;
	}
	if (trobats > 1 or trobats < 1) text_triat = true;
	else text_triat = false;
}

void Cjt_textos::textos_autor(string &autor){
	map<string,Texto>::iterator it = textos[autor].begin();
	while (it != textos[autor].end()){
		cout << it->first << endl;
		++it;
	}
}

void Cjt_textos::tots_textos(){
	map<string,map<string,Texto> >::const_iterator it = textos.begin();
	map<string,Texto>::const_iterator it2;
	while (it != textos.end()){
		it2 = it->second.begin();
		while (it2 != it->second.end()){
			cout << it->first << ' ' << it2->first << endl;
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
		}
		cout << it->first << ' ' << t << ' ' << f << ' ' << p << endl;
	}
}
			

	
	