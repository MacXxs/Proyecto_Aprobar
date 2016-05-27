#include "Cjt_cites.hh"


Cjt_cites::Cjt_cites() {
	//cites = map<string, Cita>;
	//map<string, int> referencies;
}

Cjt_cites::~Cjt_cites() {}

void Cjt_cites::afegir_cita(Cjt_textos& textos, int& x, int& y) {
	map<string,Texto>::iterator it = textos.text_actual();
	string autor, titol, a, ref;
	autor = textos.consultar_autor();
	istringstream iss(autor);
	while (iss>>a) ref.push_back(a[0]);
	int num_ref;
	map<string,int>::iterator it2 = referencies.find(ref);
	if (it2 != referencies.end())	{
		++(*it2).second;
		num_ref = (*it2).second;
	}
	else {
		num_ref = 1;
		referencies[ref] = 1;
	}
	ref += to_string(num_ref); //afegeix a les inicials del autor el numero de la referencia passat a string
	Cita cita;
	
	map<int, Frase> frases;
	textos.consultar_cont_frases(frases, x, y);
	
	titol = textos.consultar_titol();
	cita.crear_cita(ref,x,y,autor,titol, frases);
	cites[ref] = cita;
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
    //hem eliminat les comilles
	map<string, Cita>::iterator it = cites.find(referencia);
	if (it != cites.end()) {
		cout << it->second.consultar_autor() << ' ' << '"' << it->second.consultar_titol() << '"' << endl;
		cout << it->second.consultar_numini() << '-' << it->second.consultar_numfin() << endl;
		it->second.escriure_frases_cita();
	}
}

void Cjt_cites::info(Cjt_textos& textos){
	textos.info();
	cout << "Cites associades:" << endl;
	string aut = textos.consultar_autor();
	istringstream iss(aut);
	string ref;
	while(iss>>aut) ref.push_back(aut[0]);
	int top = referencies[aut];
	ref.push_back('1');
	map<string,Cita>::iterator it = cites.find(ref); 
	for(int i = 0; i < top; ++i){
		if (it->second.consultar_autor() == aut){
			cout << ref << endl;
			//textos.consultar_frases(it->second.consultar_numfin(),it->second.consultar_numfin());
			it->second.escriure_frases_cita();
		}
	}
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
	for (int i = 1; i <= top; ++i){
		if(it->second.consultar_autor() == aut){
			cout << it->first << endl; //escriu referencia
			it->second.escriure_frases_cita(); //escriu les frases de la cita
			cout << '"' << it->second.consultar_titol() << '"' << endl;
		}
	}
}

