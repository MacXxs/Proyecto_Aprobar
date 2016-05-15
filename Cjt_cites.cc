#include "Cjt_cites.hh"


Cjt_cites::Cjt_cites() {
	cites = map<string, Cita>();
}

Cjt_cites::~Cjt_cites() {}

Cjt_cites::afegir_cita(char& x, char& y) {
	
}

Cjt_cites::eliminar_cita(string& referencia) {

}

Cjt_cites::info_cita(string& referencia) {
	map<string, Cita>::const_iterator it = cites.find(referencia);
	if (it != cites.end()) {
		cout << cites[it].autor << ' ' << cites[it].titol << endl;
		cout << cites[it].numini << '-' << cites[it].numfin << endl;

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
	string m, referencia_aux;
	istringstream iss(aut);
	while (iss >> m) {
		//ho mirem per si hi ha casos com Alissa von Bismark
		if (m[0] >= 'A' and m[0] <= 'Z') referencia_aux.push_back(m[0]);
		//tenemos guardada la referencia con las iniciales del autor
	}

	//hay que contemplar que un autor tenga mas de una cita

	map<string, Cita>::const_iterator it = cites.find(referencia_aux);
	if (cites[it].autor == aut) {
		cout << cites[it].referencia << endl;
		//escribir frases de la cita
		cout << cites[it].autor << ' ' << cites[it].titol << endl;
	}
}