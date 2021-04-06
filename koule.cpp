#include "koule.h"
#include <cmath>
#include <iomanip>
//#define VYCHOZI 5 //vychozi konstanta polomeru v cm
const float vychoziPolomer = 5; //globalni konstantni (nemenna) float promenna s vychozim polomerem 5 cm

//Definice vychoziho konstruktoru bez parametru
Koule::Koule(){
	//Do objektu (this) nastavime vychozi meritko polomeru, tj. 5 cm
    this->polomer = vychoziPolomer;
}
//Definice konstruktoru s parametry
Koule::Koule(float r){
	//Na zaklade kontroly platnosti predaneho parametru v konstruktoru se nastavi na polomer z parametru
    if(kontrolaPlatnostiPolomeru(r)){
        this->polomer = r;
    }
    //V opacnem pripade bude nastavena vychozi hodnota
    else
        this->polomer = vychoziPolomer;
}
//Definice kopirovaciho kontruktoru
//&orig je reference na druhy objekt predany v parametru
Koule::Koule(const Koule &orig){
    this->polomer = orig.getPolomer();
}
//Destruktor! Musi vzdy byt!
//Pokud nepridelujeme pamet (pole, matice), je destruktor prazdny
Koule::~Koule(){}
//Getter cili metoda pro ziskani hodnoty polomeru objektu, ktery je ulozen v privatni clenske promenne (sekce private v class)
float Koule::getPolomer()const{
    return this->polomer;
}
//Setter cili metoda pro nastaveni hodnoty polomeru objektu
//Datovy typ bool, protoze muze nastat pripad, kdy neni neco v poradku
bool Koule::setPolomer(float r){
	//Nastavi hodnotu objektu na zaklade kontroly platnosti (je-li true)
    if(kontrolaPlatnostiPolomeru(r)){
        this->polomer = r;
        return true;
    }
    else{
        this->polomer = vychoziPolomer;
        return true;
    }
    return false;
}
//Metoda s navratovym typem float (desetinne cislo) pro vypocet povrchu koule
float Koule::povrch()const{
	//konstanta M_PI z knihovny cmath (ekv. <math.c>)
	//funkci pow z knihovny cmath predame v parametru nejprve mocnenec a nasledne mocnitel
    return 4*M_PI*std::pow(this->polomer,2);
}
//Metoda s navratovym typem float (desetinne cislo) pro vypocet objemu koule
float Koule::objem()const{
    return (4*M_PI*std::pow(this->polomer,3))/3;
}
//Metoda s navratovym typem bool (true, false) pro kontrolu platnosti polomeru
bool Koule::kontrolaPlatnostiPolomeru(float r)const{
	//Pokud je polomer (predany parametrem) mensi nebo rovno 0, tak nastane false
    if(r<=0){
        return false;
    }
    //V opacnem pripade true
    else
        return true;
}
//Metoda s navratovym typem float pro zaokrouhleni predaneho cisla na 2 desetinna mista 
float Koule::zaokrouhleni(float cislo)const{
	//Do promenne vysledek ulozime floatovou promennou cislo z parametru, kterou vynasobime 100 a pricteme 0.5
	//Nasledne operaci pretypujeme na int (cele cislo)
    float vysledek = (int)(cislo*100 + 0.5);
    //A z metody "vyhodime" vysledek pretypovany na float a vydeleny 100
    return (float)vysledek/100;
}
//Pretizeni operatoru <<, ktere nam slouzi ke zjednoduseni vypisu na obrazovku
//V main.cpp pote staci pouze napsat cout << k1 a vypise nam to tyto udaje o objektu:
std::ostream& operator<<(std::ostream &os, const Koule& koule){
 //os predstavuje vystup cili jakesi zapouzdreni toho, co chceme vypsat
 //&koule je reference na dany objekt vpravo od << (napr. cout << k1 (napr. tento objekt))
 os << "Polomer koule: " << koule.getPolomer() << " cm  "<< std::setw(8) << "Povrch: " << koule.zaokrouhleni(koule.povrch())
 << " cm ctverecnich " << std::setw(8) << "Objem: " << koule.zaokrouhleni(koule.objem()) << " cm krychlovych" << std::endl;
 //vracime vypis
 return os;
}
//Pretizeni operatoru ==, porovna, zdali jsou objekty totozne na zaklade polomeru jednotlivych objektu (objektVlevo==objektVpravo)
bool Koule::operator==(const Koule &koule)const{
    return this->polomer == koule.getPolomer();
}
//Pretizeni operatoru prirazeni (=). 
//Do soucasneho objektu predame hodnotu jineho objektu, ktery bude vpravo od =
Koule& Koule::operator=(const Koule &koule){
    this->polomer = koule.getPolomer();
    return *this; //vracime ukazatel na objekt (this)
}
