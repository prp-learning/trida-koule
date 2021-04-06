#include <iostream>
#include <cstdio>
#include "koule.cpp" //zahrnuti souboru koule.cpp
//Pouziti objektu ze jmenne oblasti std
using std::cout;
using std::cin;
using std::endl;

int chcesOpakovatCyklus(int hodnota){
	int pocetZnaku=0;
	//Vyprazdneni bufferu
	while(getchar()!='\n')
		pocetZnaku++;
    /*Pokud je vstupem znak, vytiskne se demonstrativne na obrazovku tato hlaska:*/
	if(pocetZnaku>0)
		cout << "Nezadal/a jste cislo, a uz vubec ne pozadovane" << endl;
    /*Pokud je hodnota zadana uzivatelem rovna 1, vse je v poradku.*/
	else if(hodnota==1)
		return 1;
	return 0;
}
int main()
{
	//Vytvoreni objektu pomoci konstruktoru bez parametru, tj. vychozi hodnota 5 cm
    Koule k1;
    //Vytvoreni objektu pomoci konstruktoru s parametry
    //Hodnota bude 20 cm
    Koule k2(20);
    //Vytvoreni kopirovaciho objektu k3, kteremu bude predan objekt k2. 
    //Cili z objekt k3 se prevlece do objektu k2 - bude mit hodnotu 20 cm
    Koule k3(k2);
    //Pomocna promenna
    int odpoved;
    //floatova promenna pro polomer, ktery pote ziskame od uzivatele v cin
    float polomer;
    cout << "Objekt k1 vytvoreny vychozim konstruktorem" << endl;
    cout << "---------------------------------------" << endl;
    //Zde uz vyuzivame pretizeni operatoru <<
    //Za << predavame objekt, ktery se vypise, resp. vypise se to, co jsme predepsali v koule.cpp
    cout << k1;
    cout << endl;

    cout << "Objekt k2 vytvoreny konstruktorem s parametry" << endl;
    cout << "------------------------------------------" << endl;
    //Znovu vyuzivame pretizeni operatoru <<, zde vypiseme objekt k2 a jeho veci
    cout << k2;
    cout << endl;

    cout << "Objekt k3 vytvoreny kopirovacim konstruktorem" << endl;
    cout << "------------------------------------------" << endl;
    //Znovu vyuzivame pretizeni operatoru <<, zde vypiseme objekt k3 a jeho veci
    cout << k3;
    cout << endl;
    cout << endl;
    do{
        cout << "Zadej polomer v cm: ";
        //Uzivatelsky vstup
        cin >> polomer; 
        //Zavolani setteru pro nastaveni polomeru objektu k1 (k objektu se dostaneme prostednictvim pristupoveho operatoru .)
        k1.setPolomer(polomer);
        cout << endl;
        cout << endl;
        cout << "Objekt k1 po zmene" << endl;
        cout << "------------------" << endl;
        //Pretizeni operatoru <<
        cout << k1;
        cout << endl;
        cout << endl;

        cout << "Porovnani objektu k1 a k2: ";
        //Pokud jsou objekty shodne (na zaklade pretizeni operatoru ==), tedy true)
        if(k1==k2)
			//Tak vypise hlasku
            cout << "objekty jsou shodne" << endl;
        else
            cout << "objekty nejsou shodne" << endl;
        cout << endl;
        cout << endl;

        cout << "Objekt k3 po prirazeni hodnoty z objektu k2" << endl;
        cout << "-------------------------------------------" << endl;
        //Pretizeni operatoru prirazeni =
        k3=k2;
        cout << k3;
        cout << endl;
        cout << endl;
        cout << "Chcete-li pokracovat, stisknete 1: ";
        //Uzivatelsky vstup
        cin >> odpoved;
    }while(chcesOpakovatCyklus(odpoved));
    return 0;
}
