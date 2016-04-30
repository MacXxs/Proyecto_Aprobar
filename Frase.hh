#ifndef FRASE_HH
#define FRASE_HH

#include<vector>
#include<string>

class Frase {
	//Tipus de modul: dades
	//Descripcio del tipus: 


private:
	vector<string> frase;
	int n_paraules;


public:
	//Constructora

	Frase();
	/*Pre: cert*/
	/*Post: el resultat es una frase buida*/

	//Destructora

	~Frase();

	//Consultoras
	
	void llegir(string paraula);
	/*pre cert
	 \post es va formant una frase a partir de les paraules que arriben
	 */
	
	int paraules() const;
	/*Pre: cert*/
	/*Post: el resultat es el nombre de paraules d'una frase*/

	//Modificadora

	void substituir_paraula(string& a, string& b);
	/*Pre: arriben dos paraules a = A, b = B*/
	/*Post: es canvien totes les aparicions de la paraula a per la b
	*/
};
#endif