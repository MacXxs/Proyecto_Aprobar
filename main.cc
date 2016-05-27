#include"Cjt_cites.hh"

#include<iostream>
#include<sstream>
using namespace std;

int main(){
	string linia, m;
	Cjt_cites cites;
	Cjt_textos textos;
	while (getline(cin,linia)){
		if (linia.size() > 0){
			istringstream iss(linia);
			iss >> m;
			if (m == "afegir"){
				iss >> m;
				if (m == "text"){
					iss >> m;
					linia.erase(0,13);
					linia.pop_back();
					string autor, text;
					getline(cin,autor);
					getline(cin,text,'*');
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
				paraula2 = m;
				textos.substituir(paraula1,paraula2);
			}
			else if (m == "textos"){
				iss >> m;
				m.erase(0,1);
				m.pop_back();
				textos.textos_autor(m);
			}
			else if (m == "tots"){
				iss >> m;
				if (m == "textos") textos.tots_textos();
				else textos.tots_autors();
			}
			else if (m == "info"){
				iss >> m;
				if (m == "?"){
					textos.info();
					cites.info(textos);
				}
				else {
					iss >> m;
					cites.info_cita(m);
				}
			}
			else if (m == "autor") textos.consultar_autor();
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
				else{
					linia.erase(0,7);
					linia.pop_back();
					textos.frases(linia);
				}
			}
			else if (m == "nombre"){
				iss >> m;
				iss >> m;
				if (m == "frases") textos.consultar_numf();
				else textos.consultar_nump();
			}
			else if (m == "taula") textos.taula_freq();
			else if (m == "cites"){
				iss >> m;
				if (m == "autor"){
					iss >> m;
                    linia.erase(0, 13);
                    linia.pop_back();
                    linia.pop_back();
                    linia.pop_back();
					cites.cites_autor(linia);
				}
                else cites.fun_cites(textos);
			}
			
			else if (m == "totes") cites.totes_cites();	
		}
	}
}
		
		
			
		
			
				
