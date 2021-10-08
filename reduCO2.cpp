#include <iostream> // command line interface
#include <fstream>  // input and output from file

#include <string>   // to manage the strings
#include <typeinfo>

using namespace std;
#define max 100

// le categorie sono 11
struct kitchen
{
    string tag;
    string food[max];
    float co_2[max];
    int n;
};
char alphabet[] = {
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r', 's', 't', 
    'u', 'v', 'w', 'x', 'y', 
    'x'
};

// determina la lunghezza del file
int len_file(string path){
    ifstream file(path);
    int len=0;

    if (file){
        string line;

        while (getline(file, line)){
            len++;
        }

        file.close(); file.clear();
    }else{
        cout<<"couldn't read the file :-(\n";
    }

    return len;
}

// inizializza il vettore mettendo tutti i tag vuoti
void init(kitchen Fstorage[], int n){
    for (int i=0; i<n; i++){
        Fstorage[i].tag = "";
    }
    return;
}

// carica i dati del file excel nella tabella
int get_data(kitchen Fstorage[]){
    
    int n=0; // inizializzo la lunghezza del vettore
    ifstream data("data.csv"); // apro il file contenente i dati per il calcolo
    
    // verifico che si legga il file
    if (!data){
        cout<<"!! ERRORE NELLA LETTURA DEL FILE DATA\n";
    }else{

        // se si legge inizializzo le variabili
        string tag = "";
        string food = "";
        string co2 = "";
        int i=0, j=0; // inizializzo gli indici
        
        //finché riesce a leggere una riga
        while (getline(data, food, ';')){ //legge la colonna del cibo
            getline(data, tag, ';');      //legge la colonna dei tag
            getline(data, co2);           //legge il consumo di co2
            
            // se il tag è diverso lo cambio
            if (Fstorage[i].tag != tag){

                // se non è il primo elemento
                if (Fstorage[i].tag != ""){ 

                    // salvo la lunghezza del vettore
                    Fstorage[i].n = j;
                    j = 0;
                     
                    i++;
                    Fstorage[i].tag = tag; // cambio il tag

                }else{ // se è il primo elemento inserisco il nome della categoria
                    Fstorage[i].tag = tag;
                }
            }

            Fstorage[i].food[j] = food; // inserisco il cibo

            // inserisco la co_2 prodotta
            try{
                // converto la stringa in float
                Fstorage[i].co_2[j] = stof(co2);
            }
            // stampo l'errore nel caso non riesca a convertire
            catch(invalid_argument ecc_co2){
                cout<<"ERRORE: non è stato possibile convertire la co2 del cibo, "<<Fstorage[i].food[j]<<", in float"<<endl;
            }
            j++;
        }
        // salvo la lunghezza dell'ultima lista e quella della tabella
        Fstorage[i].n = j;
        n = i+1;

        data.close(); data.clear(); // chiudo tutto 
    }

    return n;
}

//visualizza la tabella
void visua_tab(kitchen table[], int n){
    int len=0;

    for (int i=0; i<n; i++){
        len = table[i].tag.length();

        cout<<' '<<alphabet[i]<<") "<<table[i].tag<<endl;
        /* |_______*/cout<<string(len/2, ' ')<<"|"<<string(len/2, '_')<<"cibo: \n";
        
        for (int j=0; j<table[i].n; j++){
            cout<<string(len, ' ')<<j+1<<". "<<table[i].food[j]<<";\n";
        }
        cout<<endl<<string(41, '-')<<endl<<endl;
    }

    return;
}

int main(){
    kitchen food_storage[max];
    init(food_storage, max);

    int N = get_data(food_storage);

    visua_tab(food_storage, N);

    system("pause");
    return 0;
}