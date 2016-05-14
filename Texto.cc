#include"Texto.hh"

bool comp(const pair<string,int>& a, const pair<string,int>& b){
	if (a.second != b.second) return a.second > b.second;
	else if (a.first.lenght() != b.second.lenght()) return a.first.lenght > a.second.lenght;
	else return a.first < b.first;
}

Texto::Texto(){
    //autor;
    //vector<pair<string,int> > parfreq;
    //vector<string> titol;
    numP = 0;
    numF = 0;
    numcites = 0;
    map<int,Frase> map_frases;
    
}

Texto::~Texto(){
}

void Texto::substituir(string &par1, string &par2){
    for(int i = 0; i < numF; ++i){
	map_frases[i].substituir(par1,par2);
    }
}

void Texto::afegir_cita(string &referencia, char &x, char &y){
    consultar_frases(x,y);
    Cita cita;
    cita.crear_cita(referencia,x,y,frases_cita,autor,titol);
    map_cites.insert(make_pair(referencia[2] - '0',cita);
    ++numcites;
}

void Texto::eliminar_cita(string &referencia){
    map_cites.erase(referencia[2] - '0');
    --numcites;
}

int Texto::paraules(){
    return numP;
}

void Texto::consultar_autor(){
    string m;
    iss >> m; 
    cout << m;
    while (iss >> m) cout << ' ' << m;
}

void Texto::consultar_contingut(){
    string m;
    for(int i = 0; i < numF; ++i){
	cout << i + 1 << ' ';
	for(int j = 0; j < vec_frases[j].paraules(); ++j) vec_frases[j].escriure;
    }
}

int Texto::consultar_numf(){
	return numF;
}

int Texto::consultar_nump(){
	return numP;
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

void Texto::frases(string& expres){
}
		
void Texto::taula_freq(){
	map<sting,int> a;
	for(int i = 0; i < numF; ++i){
		map_frases[i].taula_freq(a);
	}
	map<sting,int>::iterator it = a.begin();
	for(int i = 0; i < a.size(); ++i){
		parfreq.first = it->first;
		parfreq.second = it->second;
		++it;
	}
	sort(parfreq.begin(),parfreq.end(),comp);
}

bool Texto::operator<(const Texto &t){
	if (titol < t.titol) return true;
	else return false;
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
			map_frases[count].llegir(frase);
			++count;
		}
	}
}

		
 

    
    
    
    
    
    