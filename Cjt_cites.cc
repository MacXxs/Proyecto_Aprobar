#include "Cjt_cites.hh"


Cjt_cites::Cjt_cites() {
	//cites = map<string, Cita>;
	//map<string, int> referencies;
}

Cjt_cites::~Cjt_cites() {}

void Cjt_cites::afegir_cita(Cjt_textos& textos, int& x, int& y) {
	if (textos.hi_ha_text_triat()){
		int numf = textos.consultar_num_frases();
		if ((1 > x) or (x > y) or (y > numf)) cout << "error" << endl;
		else {
			map<string,Cita>::iterator it = cites.begin();
			string autor, titol, a, ref;
			autor = textos.consultar_autor();
			titol = textos.consultar_titol();
			istringstream iss(autor);
			while (iss>>a) ref.push_back(a[0]);
			int num_ref;
			bool valida = true;
			map<string,int>::iterator it2 = referencies.find(ref);
			if (it2 != referencies.end()) {
				num_ref = it2->second;
				while (it != cites.end() and valida){
					if (it->second.consultar_autor() == autor and it->second.consultar_titol() == titol){
						if (it->second.consultar_numini() == x){
							if (it->second.consultar_numfin() == y) valida = false;
						}
					}	
					++it;
				}
			}
			else {
				num_ref = 1;
				referencies[ref] = 1;
			}	
			if (valida){
				++referencies[ref];
				ref += to_string(num_ref); //afegeix a les inicials del autor el numero de la referencia passat a string
				Cita cita;
				map<int, Frase> frases;
				textos.consultar_cont_frases(frases, x, y);				
				cita.crear_cita(ref,x,y,autor,titol, frases);
				cites[ref] = cita;
			}
			else cout << "error" << endl;
		}
	}
	else cout << "error" << endl;
}

void Cjt_cites::eliminar_cita(string& referencia) {
    referencia.erase(referencia.begin());
    referencia.pop_back();
	map<string, Cita>::iterator it = cites.find(referencia);
	if (it != cites.end()) cites.erase(it);
	else cout << "error" << endl;
}

void Cjt_cites::info_cita(string& referencia) {
    referencia.erase(referencia.begin());
    referencia.pop_back();
	map<string, Cita>::iterator it = cites.find(referencia);
	if (it != cites.end()) {
		cout << it->second.consultar_autor() << ' ' << '"' << it->second.consultar_titol() << '"' << endl;
		cout << it->second.consultar_numini() << '-' << it->second.consultar_numfin() << endl;
		it->second.escriure_frases_cita();
	}
	else cout << "error" << endl;
}

void Cjt_cites::info(Cjt_textos& textos){
	if (textos.hi_ha_text_triat()){
		textos.info();
		cout << "Cites Associades:" << endl;
		string aut = textos.consultar_autor();
		istringstream iss(aut);
		string ref, m;
		while(iss>>m) ref.push_back(m[0]);
		int top = referencies[ref];
		map<string,Cita>::iterator it;
		bool sortir = false;
		for (int i = 0; i < top and not sortir; ++i){
			ref += to_string(i+1);
			it = cites.find(ref); 
			sortir = it != cites.end();
			while (ref[ref.size()-1] >= '0' and ref[ref.size()-1] <= '9') ref.pop_back();
		}
		for(int i = 0; i < top and it != cites.end(); ++i){
			if (it->second.consultar_autor() == aut){
				cout << it->first << endl;
				it->second.escriure_frases_cita();
			}
			++it;
		}
	}
	else cout << "error" << endl;
}

void Cjt_cites::totes_cites() {
	for (map<string, Cita>::iterator it = cites.begin(); it != cites.end(); ++it) {
		cout << it->first << endl;
		it->second.escriure_frases_cita();
		cout << it->second.consultar_autor() << ' ' << '"' << it->second.consultar_titol() << '"' << endl;
	}
}

void Cjt_cites::cites_autor(string& aut) {
    string m, ref, refe1;
	istringstream iss(aut);
	while (iss >> m) ref.push_back(m[0]); 
    refe1 = ref;
	ref.push_back('1');
	int top = referencies[refe1];
	map<string,Cita>::iterator it = cites.find(ref);
	for (int i = 0; i < top and it != cites.end(); ++i){
		if(it->second.consultar_autor() == aut){
			cout << it->first << endl; //escriu referencia
			it->second.escriure_frases_cita(); //escriu les frases de la cita
			cout << '"' << it->second.consultar_titol() << '"' << endl;
		}
		++it;
	}
}


void Cjt_cites::fun_cites(Cjt_textos& textos) {
	if (textos.hi_ha_text_triat()){
		string aut, tit;
		textos.info_text_triat(aut, tit);
        string m, ref, refe1;
        istringstream iss(aut);
        while (iss >> m) ref.push_back(m[0]);
        refe1 = ref;
        ref.push_back('1');
        int top = referencies[refe1];
        map<string, Cita>::iterator it = cites.find(ref);
		for (int i = 0; i < top and it != cites.end(); ++i) {
			if (it->second.consultar_autor() == aut) {
				cout << it->first << endl; //escriu referencia
				it->second.escriure_frases_cita(); //escriu les frases de la cita
				cout << aut << ' ' << '"' << tit << '"' << endl;
			}
			++it;
		}
	}
	else cout << "error" << endl;
}



