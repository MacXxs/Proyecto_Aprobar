#include "Cjt_cites.hh"


Cjt_cites::Cjt_cites() {
	//cites = map<string, Cita>;
}

Cjt_cites::~Cjt_cites() {}

void Cjt_cites::afegir_cita(Cjt_textos& textos, char& x, char& y) {
	map<string,Texto>::iterator it = textos.text_actual();
	string autor, titol, a, ref;
	autor = textos.consultar_autor();
	istringstream iss(autor);
	while (iss>>a){
		if (a[0] >= 'a' and a[0] <= 'z') ref.push_back(a[0] - 32);
		else ref.push_back(a[0]);
	}	
	map<string,int>::iterator it = referencies.find(ref);
	if (it != referencies.end(){
		++(*it).second;
		num_ref = (*it).second;
	}
	else {
		num_ref = 1;
		referencies[ref] = 1;
	}
	ref += to_string(num_ref); //afegeix a les inicials del autor el numero de la referencia passat a string
	Cita cita;
	titol = textos.consultar_titol();
	cita.crear_cita(ref,x,y,autor,titol);
	cites[ref] = cita;
}

void Cjt_cites::eliminar_cita(string& referencia) {
	map<string, Cita>::const_iterator it = cites.find(referencia);
	if (it != cites.end()) cites.erase(it);
	else cout << "error" << endl;
}

Cjt_cites::info_cita(string& referencia) {
	map<string, Cita>::const_iterator it = cites.find(referencia);
	if (it != cites.end()) {
		cout << it->second.autor << ' ' << it->second.titol << endl;
		cout << it->second.numini << '-' << it->second.numfin << endl;

		//escribir las frases
	}
}

/*void Cjt_cites::info() {

}*/

void Cjt_cites::totes_cites() {
	for (map<string, Cita>::const_iterator it = cites.begin(); it != cites.end(); ++it) {
		cout << it->first << endl;
		//escribir linea de la frase y el contenido de la cita
		cout << it->second.autor << ' ' << it->second.titiol << endl;
	}
}

void Cjt_cites::cites_autor(string& aut) {
	string m, referencia_aux, refer_aux_2;
	istringstream iss(aut);
	while (iss >> m) {
		//ho mirem per si hi ha casos com Alissa von Bismark
		if (m[0] >= 'a' and m[0] <= 'a') referencia_aux.push_back(m[0] - 32)
		else referencia_aux.push_back(m[0]); 
		//tenemos guardada la referencia con las iniciales del autor
	}

	map<string, int>::const_iterator it1 = referencies.find(referencia_aux);
	if (it1 != referencies.end()) {
		string aux;
		ostringstream convert;
		convert << it1->second;
		aux = convert.str(); //tenim el numero de la referencia en un string
		referencia_aux = it1->first;
		refer_aux_2 = it1->first;
		refer_aux_2.insert(refer_aux_2.end(), 1);
		referencia_aux.insert(referencia_aux.end(), aux); //tenim la referencia completa
	}

	map<string, Cita>::const_iterator it2 = cites.find(refer_aux_2);
	map<string, Cita>::const_iterator it3 = cites.find(referencia_aux);
	while (it2 <= it3) {
		if (it2->second.autor == aut) {
			cout << it2->second.referencia << endl;
			//escribir frases
			cout << it2->second.autor << ' ' << it2->second.titol << endl;
		}
		++it2;
	}
}