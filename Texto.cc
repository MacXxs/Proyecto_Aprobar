#include"Texto.hh"

bool comp(const pair<string,int>& a, const pair<string,int>& b){
	if (a.second != b.second) return a.second > b.second;
	else if (a.first.length() != b.first.length()) return a.first.length() < b.first.length();
	else return a.first < b.first;
}

Texto::Texto(string& titol){
	this->titol = titol;
	//vector<pair<string,int> > parfreq;
	//autor;
	nump = 0;
    numcites = 0;
    map<int,Frase> map_frases;
}

Texto::Texto(){
    //autor;
	//titol;
    //vector<pair<string,int> > parfreq;
	nump = 0;
    numcites = 0;
    map<int,Frase> map_frases;
    
}

Texto::~Texto(){
}

void Texto::substituir(string &par1, string &par2){
	int par_subs = 0;
    for(int i = 1; i <= map_frases.size(); ++i)
		map_frases[i].substituir_paraula(par1,par2,par_subs);
	int pos_par1 = -1;
	bool par2_trobada = false;
	for(int i = 0;  i < parfreq.size() and (pos_par1 == -1 or not par2_trobada); ++i){
		if (parfreq[i].first == par1) pos_par1 = i;
		else if (parfreq[i].first == par2){
			parfreq[i].second += par_subs;
			par2_trobada = true;
		}
    }
    if (pos_par1 != -1){
		parfreq.erase(parfreq.begin() + pos_par1);
		if (not par2_trobada){
			parfreq.insert(parfreq.begin(),make_pair(par2,par_subs));
		}
		sort(parfreq.begin(),parfreq.end(),comp);
	}
}

int Texto::paraules() const{
    return parfreq.size();
}

string Texto::consultar_titol() const{
	return titol;
}

void Texto::consultar_autor() const{
    cout << autor << endl;
}

void Texto::consultar_contingut(){
    for(int i = 1; i <= map_frases.size(); ++i){
	cout << i << ' ';
	map_frases[i].escriure();
	cout << endl;
    }
}

int Texto::consultar_numf() const{
	return map_frases.size();
}

int Texto::consultar_nump() const{
	return nump;
}

void Texto::consultar_frases(int &x, int &y){
	for(int i = 0; i <= y - x; ++i){
		cout << x + i << ' ';
		map_frases[x+i].escriure();
		cout << endl;
	}
}

void Texto::consultar_frases(string& p){
	for (int i = 1; i <= map_frases.size(); ++i){
		if (map_frases[i].consultar_frases(p)){
			cout << i << ' ';
			map_frases[i].escriure();
			cout << endl;
		}
	}
}

void Texto::consultar_cont_frases(map<int, Frase>& frases, int& x, int& y){
	for (int i = 0; i <= y - x; ++i) {
		frases.insert(make_pair(x + i, map_frases[x+i]));
	}
}

void Texto::recur(string& expres){
	bool b; 
	int pos;
	for (int i = 0; i < map_frases.size(); ++i){
		b = false;
		pos = 0;
		recur_im(expres,pos,b,map_frases[1+i]);
		if (b){
			int x = i+1;
			consultar_frases(x,x);
		}
	}
}

void Texto::recur_im(string& exp, int& pos, bool& b, Frase& f){
	if (pos < exp.size()){
		//invariant: 0 <= pos < exp.size()
		if (exp[pos] == '{'){
			//cas base: es tracta la expressio entre clau d'ators
			string aux = "";
			++pos;
			while(exp[pos] != '}'){
				aux += exp[pos];
				++pos;
				//les paraules entre claus d'ators es posen en un string
			}
			istringstream iss(aux);
			string m;
			bool b1,b2;
			b1 = true;
			while (iss >> m){
				f.buscar_par(m,b2);
				b1 = b1 and b2;
				/*es mira si les paraules acumulades a aux compleixen que totes estiguin a la frase f
				i si totes ho complexen es posa b1 a true */
			}
			b = b1;
			//s'iguala b a b1
		}
		else {
			//cas recursiu
			if (exp[pos] == '('){
			recur_im(exp,++pos,b,f);
			//es torna a cridar a la recursiva amb ++pos per avançar en cas de que s'apunti a un parentesis
			recur_im(exp,++pos,b,f);
			//es torna a cridar a la recursiva amb ++pos perque avanci i acabi d'evaluar tota la expresio
			}
			else if (exp[pos] == '&'){
				bool b1;
				recur_im(exp,++pos,b1,f);
				b = b and b1;
				/*en cas de que pos apunti a & es torna a cridar a la recursiva amb un nou bolea per despres
				mirar si les expresions d'avanç i les de despres del & es compleixen*/
			}
			else if (exp[pos] == '|'){
				bool b1;
				recur_im(exp,++pos,b1,f);
				b = b or b1;
				/*en cas de que pos apunti a | es torna a cridar a la recursiva amb un nou bolea per despres
				mirar si les expresions d'avanç o les de despres de | es compleixen*/
			}
			else recur_im(exp,++pos,b,f);
			//es torna a cridar a la recursiva en el cas de que pos apunti a un espai
		}
	}
}

void Texto::taula_freq(){
	parfreq.clear();
	map<string,int> a;
	for(int i = 1; i <= map_frases.size(); ++i){
		map_frases[i].taula_freq(a);
	}
	map<string,int>::iterator it = a.begin();
	for(int i = 0; i < a.size(); ++i){
		parfreq.push_back(make_pair(it->first,it->second));
		++it;
	}
	sort(parfreq.begin(),parfreq.end(),comp);
}

void Texto::consultar_taula_freq(){
	for (int i = 0; i < parfreq.size(); ++i){
		cout << parfreq[i].first << ' ' << parfreq[i].second << endl;
	}
}

void Texto::augmentar_numcites(){
	++numcites;
}

void Texto::llegir(string& titol, string& autor, string& contingut){
	this->titol = titol;
	this->autor = autor;
	bool buscar = true;
	size_t pos, posp, pose, posi;
	int count = 1, nump = 0;
	while (buscar){ 
		posp = contingut.find('.');
		pose = contingut.find('!');
		posi = contingut.find('?');
		if (posp < pose){
			if (posp > posi) pos = posi;
			else pos = posp;
		}
		else if (pose < posp){
			if (pose < posi) pos = pose;
			else pos = posi;
		}
		else {
			if (pose == posi) buscar = false;
			else pos = posi;
		}
		if (buscar){
			string frase = contingut.substr(0,pos+1);
			contingut.erase(0,pos+1);
			map_frases[count].llegir(frase,nump);
			++count;
		}
		this->nump = nump;
	}
}

int Texto::triar_text(set<string> paraules){
	istringstream a(autor);
	istringstream t(titol);
	string p, aux;
	set<string>::iterator it;
	while (a>>p){
		if (p[p.size()-1] == '.' or p[p.size()-1] == ',' or p[p.size()-1] == '!' or p[p.size()-1] == '?' or p[p.size()-1] == ':' or p[p.size()-1] == ';'){
			p.pop_back();
			it = paraules.find(p);
		}
		else it = paraules.find(p);
		if (it != paraules.end()) paraules.erase(it);
	}
	while (t>>p){
		if (p[p.size()-1] == '.' or p[p.size()-1] == ',' or p[p.size()-1] == '!' or p[p.size()-1] == '?' or p[p.size()-1] == ':' or p[p.size()-1] == ';'){
			p.pop_back();
			it = paraules.find(p);
		}
		else it = paraules.find(p);
		if (it != paraules.end()) paraules.erase(it);
	}
	for (int i = 1; i <= map_frases.size() and not paraules.empty(); ++i)
		map_frases[i].triar_text(paraules);
	if (paraules.empty()) return 1;
	else return 0;
}

    
    
    
    
    
    