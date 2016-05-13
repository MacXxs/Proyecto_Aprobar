#include"Texto.hh"

Texto::Texto(){
    //autor;
    //map<int,Cita> map_cites;
    //set<Paraula> parfreq;
    //vector<string> titol;
    numP = 0;
    numF = 0;
    numcites = 0;
    vector<Frase> vec_frases(maxfrases);
}

Texto::~Texto(){
}

void Texto::substituir(string &par1, string &par2){
    for(int i = 0; i < numF; ++i){
	vec_frases[i].substituir(par1,par2);
    }
}

void Texto::afegir_cita(string &referencia, char &x, char &y){
    vector<Frases> frases_cita = consultar_frases(x,y);
    Cita cita;
    cita.crear_cita(referencia,x,y,frases_cita);
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
    

    



    
    

    
    
    
    
    
    