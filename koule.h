#ifndef KOULE_H_INCLUDED
#define KOULE_H_INCLUDED
#include <iostream>

//Deklarace tridy Koule
class Koule{
//Verejna cast tridy
public:
	//Konstruktor bez parametru, vychozi
    Koule(); 
    //Konsturktor s parametrem polomeru
    Koule(float);
    //Kopirovaci konstruktor
    Koule(const Koule&);
    //Destruktor
    virtual ~Koule();
    //Getter
    float getPolomer()const;
    //Setter
    bool setPolomer(float);
    //Metody pro vypocty
    float povrch()const;
    float objem()const;
    //Sekce pretezovani operatoru <<, ==, =
    friend std::ostream& operator<<(std::ostream&, const Koule&);
    bool operator==(const Koule&)const;
    Koule&operator=(const Koule&);
    //Koule operator+(const Koule &)const;
    //Koule operator-(const Koule &)const;
    
//Soukroma cast tridy
private:
	//Privatni promenna polomer
    float polomer;
    //Privatni metoda pro zaokrouhleni
    float zaokrouhleni(float)const;
    //Metoda pro kontrolu platnosti
    bool kontrolaPlatnostiPolomeru(float)const;
};

#endif // KOULE_H_INCLUDED
