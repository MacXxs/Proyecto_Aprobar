#include"Cjt_cites"

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
				iss.str(linia);
				string autor, text
				getline(cin,autor);
				getline(cin,text);
				istringstream iss(autor), issi(text);
				iss >> m;
				iss.str(autor);
				issi.str(text);
				textos.llegir_tot(linia,autor,text);
			}
			else {
				iss >> m;
				iss >> m;
				cites.afegir_cita(char(iss>>m),char(is>>m));
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
		else if (m == "substitueix"){
			string paraula1, paraula2;
			iss >> m;
			paraula1 = m;
			iss >> m;
			paraula2 = m;
			textos.subsituir(paraula1,paraula2);
		}
		else if (m == "textos"){
			iss >> m;
			iss.str(linia);
			textos.consultar_autor(linia);
		}
		else if (m == "tots"){
			iss >> m;
			if (m == "textos") textos.tots_textos();
			else textos.tots_textos():
		}
		else if (m == "info"){
			iss >> m;
			if (m == "?") textos.info();
			else {
				iss >> m;
				cites.info_cita(m);
			}
		}
		else if (m == "autor") textos.consultar_autor();
		else if (m == "coningut") textos.consultar_contingut();
		else if (m == "frases"){
			iss >> m;
			if (m > '0' and m < '9'){
				char x = char(m);
				iss >> m;
				char y = char(m);
				textos.consult_frases(x,y);
			}
			else textos.frases();
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
				cites.cites_autor(m);
			}
			else textos.cites()
		}
		else if (m == "totes") cites.totes_cites();				
	}
}
		
		
			
		
			
				