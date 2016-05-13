#include"Texto.hh"

Texto::Texto(){
    //autor;
    //map<int,Cita> map_cites;
    //set<Paraula> parfreq;
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
    cita.crear_cita(referencia,x,y,frases_cita,consultar_autor,autor,titol);
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

void Texto::info(){
    string aux = autor;
    aux.erase(0,1);
    aux.pop_back();
    cout << aux << ' ' << titol << ' ' << numP << endl;
}
	
	
	

    

    



    
    

    
    
    
    
    
    