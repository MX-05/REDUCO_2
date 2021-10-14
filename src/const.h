# pragma once

#include <iostream>

using namespace std;
# define max 100

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


// inizializza il vettore mettendo tutti i tag vuoti
void init_kitchen(kitchen Fstorage[], int n){
    for (int i=0; i<n; i++){
        Fstorage[i].tag = "";
    }
    return;
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

void visua_tags(kitchen v[], int n, bool all){
    cout<<string(46, '-')<<"\nCATEGORIE: \n"<<string(46, '-')<<endl;

    for (int i=0; i<n; i++){
        cout<<' '<<i+1<<") "<<v[i].tag<<endl;
    }
    if (all)
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
