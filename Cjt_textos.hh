#ifndef CONJ_TEXTOS_HH
#define CONJ_TEXTOS_HH

#include<Texto.hh>

#include<map>

class Cjt_textos {
	//Tipus de modul: dades
	//Descripcio del tipus:


private:
	map<Autor,set<Texto> > textos;       //mapa de textos ordenats per autor
	map<Autor,set<Texto> >::iterator it; //iterator que apunta al ultim text triat
	

public:

	//Creadora

	Cjt_textos();
	/*Pre: cert*/
	/*Post: el resultat es un conjunt de textos buit*/

	//Destructora
	
	~Cjt_textos();

	//Modificadores
	
	void llegir_tot(string &titol, string &autor, string &text);
	/*pre cert
	 \post es crida a la funcio llegir_titol, llegir_autor, llegir_text de la classe Texto per afegir un titol al Text que s'esta tractant
	*/
	
	void eliminar_text();
	/*pre hi ha un text triat
	 \post el text triat s'elimina i no hi ha un altre text triat fins que no es torni a cridar a la funcio triar text
	 */
	
	void eliminar_cita(string &referencia, Autor &autor);
	/*pre hi ha un autor igual que el que es passa com a parametre
	 \post es crida a la funcio eliminar cita de la classe Texto
	 */
	
	void substituir(string &par1, string &par2);
	/*pre hi ha un text triat
	 \post es crida a la funcio substitur de la classe Texto per canviar totes les aparicions de la paraula
	 par1 per par2
	 */
	
	void afegir_cita(string &referencia, char &x, char &y);
	/*pre arriben dos caracters x i y i una referencia
	 \post es crida a la funcio afegir_cita de la classe Texto
	 */
	
	//Consultores
	
	void consultar_autor();
	/*pre tenim un text triat
	 \post es crida la funcio consultar_autor de la classe Texto de l'ultim text triat
	 */
	
	void consultar_contingut();
	/*pre tenim un text triat
	 \post es crida a la funcio conultar_contingut de la classe Texto de l'ultim text triat
	 */
	
	void consultar_numf();
	/*pre tenim un text triat
	 \post es crida a la funcio consultar_numf de la classe Texto de l'ultim text triat
	 */
	
	void consultar_nump();
	/*pre tenim un text triat
	 \post es crida a la funcio consultar_nump de la classe Texto de l'ultim text triat
	 */	
	
	void consultar_frases(char &x, char &y);
	/*pre hi ha un text triat i es passen uns valors x i y
	 \post es crida a la funcio consultar_frases de la classe Texto de l'ultim text triat
	 */
	
	void cites_autor(string &autor); //mostra les cites d'un autor
	/*pre rep el nom d'un autor
	 \post es crida a la funcio cites_autor de la classe Texto
	 */
	
	void cites();
	/*pre hi ha un text triat
	 \post crida a la funcio cites de cla classe Texto de lultim text triat
	 */
	
	void frases(string &expres);
	/*pre hi ha un text triat i es passa una expressio
	 \post es crida a la funcio frases de la classe Texto de l'ultim text triat
	 */
	
	void taula_freq();
	/*pre hi ha un text triat
	 /post es crida a la funcio taula_freq de la classe Texto de l'ultim text triat
	 */
	
	map<Autor,set<Texto> >::iterator text_actual();
	/*pre cert
	 \post retorna un iterator apuntant al utlim text triat
	*/

	void triar_text(string &paraules);
	/*Pre: el paràmetre implícit conté els textos*/
	/*Post: retorna el texto escogido*/

	void textos_autor(string &autor);
	/*Pre: */
	/*Post: mostra tots els textos d'un determinat autor, 
			ordenats alfabeticament per títol*/

	void tots_textos();
	/*Pre: cert*/
	/*Post: mostra tots els textos del paràmetre implícit
			(només títol i autor de cada text), ordenats
			per autor i després per títol*/
	
	void tots_autors();
	/*Pre: cert*/
	/*Post: mostra tots els autors (ordre alfabeticament) amb textos
			del paràmetre implícit indicant el nombre de textos que hi consten,
			el nombre total de frases i de paraules del 
			contingut dels seus textos*/
	
	void info();
	/*pre hi ha un text triat
	 \post crida a la funcio info de la classe Texto de l'ultim text triat
	 */


};
#endif