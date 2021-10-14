#include <typeinfo>
#include <cctype>

#include "const.h"
#include "files.cpp"

struct carrello
{
    float co2;
    int punt;
};


// FIXME: se scrivo una lettera/parola il programma entra in un loop
int ask(string msg, int n, string error);

int ask_char(string msg, int n, string error);

void insert(/*carrello list[], int n,*/ kitchen foodStorage[]);

int main(){
    kitchen food_storage[max];

    cout<<title;

    char help[] = " Seleziona una delle seguenti modalità: \n"
    "\t- scrivi I per inserire il consumo della CO2 di oggi\n"
    "\t- scrivi Q per uscire dal programma\n"
    "\t- Scrivi H per ricevere aiuto \n\n";
    cout<<help;

    string A; 

    do{
        cout<<" $ "; cin>>A;

        if (A.length() ==1)
            A = tolower(A[0]);
        else   
            A = "x";
            
        switch (A[0])
        {
        case 'i':
            insert(food_storage);

            break;

        case 'q':

            system("pause");
            return 0;
        
        /************/
        
        default:
            cout<<" \t BIP! BUP! Non ho capito [:'-(]\n \t scrivi 'h' per aiuto [:-)]\n";
            break;
        }
    
    }  while (true);


    /*
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

int ask(string msg, int n, string error){
    int index = -1;

    do{
        cout<<msg; cin>>index;
        index--;

        if (index>=n or index <0)
            cout<<error<<endl;
    }while (index >=n or index <0);    

    return index;
}

int ask_char(string msg, int n, string error){
    int index = -1;
    char A;

    do{
        cout<<msg; cin>>A;

        for (int i=0; i<n; i++){
            if (alphabet[i] == A)
                index = i;
        }

        if (index>=n or index <0)
            cout<<error<<endl;
    }while (index >=n or index <0);    

    return index;
}

void insert(/*carrello list[], int n,*/ kitchen foodStorage[]){

    /******* GET DATA FROM CSV FILE ********/
    init_kitchen(foodStorage, max);
    int N = get_data(foodStorage, "../data.csv");

    /*********** GET THE CATEGORY **********/
    visua_tags(foodStorage, N, true);
    int choice =  ask(
        "inserire la categoria: ", 
        N+1, 
        " ! Per favore inserire un numero degli elementi sopra elencati"
    );

    if (choice == N){
        visua_tab(foodStorage, N);

        choice =  ask_char(
            "inserire la categoria: ", 
            N, 
            " ! Per favore inserire la lettera che indica la categoria da inserire"
        );
    }
    else
        visua_foods(foodStorage[choice].food, foodStorage[choice].n);
    
    /*********** GET THE FOOD **********/
    int food_choice = ask(
        "inserire il cibo: ", 
        foodStorage[choice].n, 
        " ! Per favore inserire un nomero di un cibo della categoria richiesta"
    );

    return;
}