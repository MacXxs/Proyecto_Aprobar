#include"Cjt_cites.hh"

#include<iostream>
#include<sstream>
using namespace std;

int main(){
	string linia, m;
	Cjt_cites cites;
	Cjt_textos textos;
	bool sortir = false;
	while (getline(cin,linia) and not sortir){
		istringstream iss(linia);
		iss >> m;
		if (not linia.empty() and m != "sortir"){
			cout << linia << endl;
			if (m == "afegir"){
				iss >> m;
				if (m == "text"){
					iss >> m;
					linia.erase(0,13);
					linia.pop_back();
					string autor, text, contingut;
					text = "";
					getline(cin,autor);
					while(getline(cin,contingut) and contingut != "****") text += contingut;	
					autor.erase(0,7);
					autor.pop_back();
					textos.llegir_tot(linia,autor,text);
				}
				else {
					iss >> m;
					int x = atoi(m.c_str());
					iss >> m;
					int y = atoi(m.c_str());
					cites.afegir_cita(textos,x,y);
				}
			}
			else if (m == "triar"){
				linia.erase(0,12);
				linia.pop_back();
				textos.triar_text(linia);
			}
			else if (m == "eliminar"){
				iss >> m;
				if (m == "text") textos.eliminar_text();
				else {
					iss >> m;
					cites.eliminar_cita(m);
				}
			}
			else if (m == "substitueix"){
				string paraula1, paraula2;
				iss >> m;
				paraula1 = m;	
				iss >> m;
				iss >> m;
				paraula2 = m;
				textos.substituir(paraula1,paraula2);
			}
			else if (m == "textos"){
				linia.erase(0,14);
				linia.erase(linia.end()-3,linia.end());
				textos.textos_autor(linia);
			}
			else if (m == "tots"){
				iss >> m;
				if (m == "textos") {
					textos.tots_textos();
				}
				else {
					textos.tots_autors();
				}
			}
			else if (m == "info"){
				iss >> m;
				if (m == "?"){
					cites.info(textos);
				}
				else {
					iss >> m;
					cites.info_cita(m);
				}
			}
			else if (m == "autor"){
				cout << textos.consultar_autor() << endl;
			}
			else if (m == "contingut") {
				textos.consultar_contingut();
			}
			else if (m == "frases"){
				iss >> m;
				if (m[0] > '0' and m[0] < '9'){
					int x = atoi(m.c_str());
					iss >> m;
					int y = atoi(m.c_str());
					textos.consultar_frases(x,y);
				}
				else if (m[0] == '"'){
					linia.erase(0,8);
					linia.erase(linia.end()-3, linia.end());
					textos.consultar_frases(linia);
				}
				else{
					linia.erase(0,7);
					textos.frases(linia);
				}
			}
			else if (m == "nombre"){
				iss >> m;
				iss >> m;
				if (m == "frases") {
					textos.consultar_numf();
				}
				else{
					textos.consultar_nump();
				}
			}
			else if (m == "taula") {
				textos.consultar_taula_freq();
			}
			else if (m == "cites"){
				iss >> m;
				if (m == "autor"){
					iss >> m;
                    linia.erase(0, 13);
                    linia.erase(linia.end()-3,linia.end());
					cites.cites_autor(linia);
				}
                else {
					cites.fun_cites(textos);
				}
			}
			else if (m == "totes") {
				cites.totes_cites();	
			}
			cout << endl;
		}
		else if (m == "sortir"){
			sortir = true;
		}
	}
}
		
		
			
		
			
				