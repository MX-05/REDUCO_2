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

char title[] = 
"\t                                        _..._       .-'''-.                   \n"
"\t            _______                  .-'_..._''.   '   _    \\      .-''-.     \n"
"\t        .--.\\  ___ `'.             .' .'      '.\\/   /` '.   \\   .' .-.  )    \n"
"\t        |__| ' |--.\\  \\           / .'          .   |     \\  '  / .'  / /     \n"
"\t.-,.--. .--. | |    \\  '         . '            |   '      |  '(_/   / /      \n"
"\t|  .-. ||  | | |     |  '        | |            \\    \\     / /      / /       \n"
"\t| |  | ||  | | |     |  | _    _ | |             `.   ` ..' /      / /        \n"
"\t| |  | ||  | | |     ' .'| '  / |. '                '-...-'`      . '         \n"
"\t| |  '- |  | | |___.' /'.' | .' | \\ '.          .                / /    _.-') \n"
"\t| |     |__|/_______.'/ /  | /  |  '. `._____.-'/              .' '  _.'.-''  \n"
"\t| |         \\_______|/ |   `'.  |    `-.______ /              /  /.-'_.'      \n"
"\t|_|                    '   .'|  '/            `              /    _.'         \n"
"\t                         `-'  `--'                           ( _.-'            \n\n"; // 121


// determina la lunghezza delle righe del file
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

// FIXME: run and fix the bug
void new_visua_tab(kitchen tab[], int n){
    
    int n_max =0;

    // scrivo tutte le categorie
    for (int i=0; i<n; i++){
        cout<<" | "<<tab[i].tag;

        if (n_max <tab[i].n)
            n_max = tab[i].n;

    }cout<<" | \n";

    // scrivo i cibi
    for (int j=0; j<n_max; j++){
        for (int i=0; i<n; i++){

            if (j<tab[i].n){
                cout<<" | "<<tab[i].food[j];

                // se il nome del cibo è più piccolo del nome della categoria, allora aggiunge degli spazi per la formattazione
                if (tab[i].food[j].length() < tab[i].tag.length())
                    cout<<string(tab[i].tag.length() -tab[i].food[j].length(), ' ');
            }
            else
                cout<<" | "<<string(tab[i].tag.length(), ' ');

        }cout<<" | \n";
    }
    
    return;
}

void visua_tags(kitchen v[], int n){
    cout<<"CATEGORIE: \n"<<string(40, '-')<<endl;

    for (int i=0; i<n; i++){
        cout<<' '<<i+1<<") "<<v[i].tag<<endl;
    }
    cout<<' '<<n+1<<") All\n"<<endl;

    return;
}

void visua_foods(string v[], int n){
    // TODO: inserire la visualizzazione verticale se < 10
    for (int i=0; i<n; i++){
        cout<<' '<<i+1<<". "<<v[i]<<";\n";
    }cout<<endl;

    return;
}

int chiedi(string msg, int n, string error){
    int index = -1;

    do{
        cout<<msg; cin>>index;
        index--;

        if (index>=n or index <0)
            cout<<error<<endl;
    }while (index >=n or index <0);    

    return index;
}

int main(){
    kitchen food_storage[max];
    init(food_storage, max);

    cout<<title;

    int N = get_data(food_storage);
    visua_tags(food_storage, N);

    int choice = -1;
    choice = chiedi("inserire la categoria: ", N+1, "Per favore inserire un numero degli elementi sopra elencati");

    if (choice == N)
        visua_tab(food_storage, N);
    else{
        visua_foods(food_storage[choice].food, food_storage[choice].n);
    }

    system("pause");
    return 0;
}