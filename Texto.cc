#include"Texto.hh"

bool comp(const pair<string,int>& a, const pair<string,int>& b){
	if (a.second != b.second) return a.second > b.second;
	else if (a.first.length() != b.first.length()) return a.first.length() > a.first.length();
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
    for(int i = 0; i < map_frases.size(); ++i)
		map_frases[i].substituir_paraula(par1,par2,par_subs);
	int pos_par1;
	bool par2_trobada = false;
	for(int i = 0;  i < parfreq.size(); ++i){
		if (parfreq[i].first == par1){
			parfreq[i].second -= par_subs;
			pos_par1 = i;
		}
		else if (parfreq[i].first == par2){
			parfreq[i].second += par_subs;
			par2_trobada = true;
		}
    }
    if (pos_par1 != -1){
		if (parfreq[pos_par1].second < 1) parfreq.erase(parfreq.begin() + pos_par1);
	}
	else if (not par2_trobada){
		parfreq.insert(parfreq.begin(),make_pair(par2,par_subs));
		sort(parfreq.begin(),parfreq.end(),comp);
	}
}

int Texto::paraules(){
    return parfreq.size();
}

string Texto::consultar_titol(){
	return titol;
}

void Texto::consultar_autor(){
    cout << autor << endl;
}

void Texto::consultar_contingut(){
    for(int i = 1; i <= map_frases.size(); ++i){
	cout << i << ' ';
	map_frases[i].escriure();
	cout << endl;
    }
}

int Texto::consultar_numf(){
	return map_frases.size();
}

int Texto::consultar_nump(){
	return parfreq.size();
}

void Texto::consultar_frases(char &x, char &y){
	int aux = x-'0';
	int auy = y-'0';
	for(int i = 0; i < auy - aux; ++i){
		cout << aux + i << ' ';
		for(int j = aux - 1; j < auy; ++j){
			map_frases[j].escriure();
		}
	}
}

//void Texto::frases(string& expres);
		
void Texto::taula_freq(){
	map<string,int> a;
	for(int i = 0; i < map_frases.size(); ++i){
		map_frases[i].taula_freq(a);
	}
	map<string,int>::iterator it = a.begin();
	for(int i = 0; i < a.size(); ++i){
		parfreq.push_back(make_pair(it->first,it->second));
		++it;
	}
	sort(parfreq.begin(),parfreq.end(),comp);
}

bool Texto::operator<(const Texto &t) const{
	if (titol < t.titol) return true;
	else return false;
}

void Texto::augmentar_numcites(){
	++numcites;
}

void Texto::llegir(string& titol, string& autor, string& contingut){
	this->titol = titol;
	this->autor = autor;
	bool buscar = true;
	size_t pos, posp, pose, posi;
	int count = 1;
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
	}
}

int Texto::triar_text(set<string> paraules){
	istringstream a(autor);
	istringstream t(titol);
	string p;
	set<string>::iterator it;
	while (a>>p){
		it = paraules.find(p);
		if (it != paraules.end()) paraules.erase(it);
	}
	while (t>>p){
		it = paraules.find(p);
		if (it != paraules.end()) paraules.erase(it);
	}
	for (int i = 1; i < map_frases.size() and paraules.size() != 0; ++i)
		map_frases[i].triar_text(paraules);
	if (paraules.size() == 0) return 1;
	else return 0;
}

		
 

    
    
    
    
    
    