#include"Cjt_cites.hh"

#include<iostream>
#include<sstream>
using namespace std;

int main(){
	string linia, m;
	getline(cin,linia);
	istringstream iss(linia);
	Cjt_cites cites;
	Cjt_textos textos;
	while (iss >> m and m != "sortir"){
		if (m == "afegir"){
			iss >> m;
			if (m == "text"){
				iss >> m;
				linia.erase(linia.begin(), linia.begin() + 12);
				string autor, text;
				getline(cin,autor);
				getline(cin,text,'*');
				autor.erase(autor.begin(), autor.begin() + 6);
				textos.llegir_tot(linia,autor,text);
			}
			else {
				iss >> m;
				char x = m[0];
				iss >> m;
				char y = m[0];
				cites.afegir_cita(x,y);
			}
		}
		else if (m == "triar"){
			iss >> m;
			iss.str(linia);
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
			iss.str(linia);
			textos.textos_autor(linia);
		}
		else if (m == "tots"){
			iss >> m;
			if (m == "textos") textos.tots_textos();
			else textos.tots_textos();
		}
		else if (m == "info"){
			iss >> m;
			if (m == "?"){
			    textos.info();
			    cites.info();
			else {
				iss >> m;
				cites.info_cita(m);
			}
		}
		else if (m == "autor") textos.consultar_autor();
		else if (m == "coningut") textos.consultar_contingut();
		else if (m == "frases"){
			iss >> m;
			if (m[0] > '0' and m[0] < '9'){
				char x = m[0];
				iss >> m;
				char y = m[0];
				textos.consultar_frases(x,y);
			}
			else textos.frases(m);
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
				textos.cites_autor(m);
			}
			else textos.cites();
		}
		else if (m == "totes") cites.totes_cites();				
	}
}
		
		
			
		
			
				