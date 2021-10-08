#include <iostream>
#include <fstream>

using namespace std;
#define max 100

// le categorie sono 11
struct kitchen
{
    string tag;
    string food[max];
    float co_2;
};

int get_data(kitchen Fstorage[]){
    // TODO: inizizalizzare la tabella con tutti i dati forniti dal file excel
    int n=0;
    ifstream data("data.csv");

    if (!data){
        cout<<"!! ERRORE NELLA LETTURA DEL FILE DATA\n";
    }else{

        string tag = "";
        string food = "";
        string co2 = "";

        while (getline(data, food, '|')){
            
            getline(data, tag, '|');
            getline(data, co2);

            cout<<tag<<" | "<<food<<" | "<<co2<<endl;
        }

        data.close(); data.clear();
    }

    return n;
}

int main(){
    kitchen food_storage[max];
    int N = get_data(food_storage);

    system("pause");
    return 0;
}