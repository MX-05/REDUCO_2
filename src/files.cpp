#include "const.h" 
#include <fstream>
#include <string> 



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

// carica i dati del file excel nella tabella
int get_data(kitchen Fstorage[], string path){
    
    int n=0; // inizializzo la lunghezza del vettore
    ifstream data(path); // apro il file contenente i dati per il calcolo
    
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
