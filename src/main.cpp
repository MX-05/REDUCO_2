#include <typeinfo>

#include "const.h"
#include "files.cpp"


// FIXME: se scrivo una lettera/parola il programma entra in un loop
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
    init_kitchen(food_storage, max);

    cout<<title;

    int N = get_data(food_storage, "../data.csv");
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