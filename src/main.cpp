#include <typeinfo>
#include <cctype>

#include "const.h"
#include "files.cpp"


// FIXME: se scrivo una lettera/parola il programma entra in un loop
int ask_int(string msg, int n, string error);

int main(){
//     kitchen food_storage[max];    init_kitchen(food_storage, max);
//     int N = get_data(food_storage, "../data.csv");

    cout<<title;

    char help[] = " Seleziona una delle seguenti modalità: \n"
    "\t- scrivi I per inserire il consumo della CO2 di oggi\n"
    "\t- scrivi Q per uscire dal programma\n"
    "\t- Scrivi H per ricevere aiuto \n\n";
    cout<<help;

    char A; 

    do{
        cout<<" $ "; cin>>A;
        A = tolower(A);

        switch (A)
        {
        case 'i':

            cout<<" codice per l'inserimento\n";
            break;

        case 'q':

            system("pause");
            return 0;
        
        default:
            cout<<" \t BIP! BUP! Non ho capito [:'-(]\n \t scrivi 'h' per aiuto [:-)]\n";
            break;
        }
    
    }  while (true);


    /*
    visua_tags(food_storage, N);

    int choice = -1;
    choice = ask("inserire la categoria: ", N+1, "Per favore inserire un numero degli elementi sopra elencati");

    if (choice == N)
        visua_tab(food_storage, N);
    else{
        visua_foods(food_storage[choice].food, food_storage[choice].n);
    }
    */
}

/*
string add_vector_elements(string msg, char vector[], int n){
    
    msg += " {";
    for (int i=0; i<n; i++){
        if (i != n-1)
            msg = msg + vector[i] + ", ";
        else   
            msg = msg +vector[i] + "}\n\n";
    }

    return msg;
}
*/

/*
char ask(string msg, char answers[], int n, string error){
    char a;
    bool running = true; 

    do{
        cout<<msg; cin>>a;

        for (int i=0; i<n; i++)
            if (answers[i] == a)
                running = false;

        if (running == true)
            cout<<error;

    }while (running);
    

    return a;
}
*/

int ask_int(string msg, int n, string error){
    int index = -1;

    do{
        cout<<msg; cin>>index;
        index--;

        if (index>=n or index <0)
            cout<<error<<endl;
    }while (index >=n or index <0);    

    return index;
}