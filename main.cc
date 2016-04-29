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
				cites.afegir_cita(iss>>m,is>>m);
			}
		}
		else if (m == "triar"){
			iss >> m;
			getline.str(linia);
		}
		else if (m == "textos"){
			
				