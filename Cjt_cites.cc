#include "Cjt_cites.hh"


Cjt_cites::Cjt_cites() {
	cites = map<string, Cita>();
}

Cjt_cites::~Cjt_cites() {}

Cjt_cites::afegir_cita(char& x, char& y) {
	Texto text_frases;
	string autor, titol;
	guarda_frases_cita(text_frases, x, y);
	titol_autor_cita(autor, titol);


}

Cjt_cites::eliminar_cita(string& referencia) {
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

Cjt_cites::info() {

}

Cjt_cites::totes_cites() {
	for (map<string, Cita>::const_iterator it = cites.begin(); it != cites.end(); ++it) {
		cout << it->first << endl;
		//escribir linea de la frase y el contenido de la cita
		cout << it->second.autor << ' ' << it->second.titiol << endl;
	}
}

Cjt_cites::cites_autor(string& aut) {
	string m, referencia_aux, refer_aux_2;
	istringstream iss(aut);
	while (iss >> m) {
		//ho mirem per si hi ha casos com Alissa von Bismark
		if (m[0] >= 'a' and m[0] <= 'a') referencia_aux.push_back(m[0] - ('a' - 'A'))
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