#define _USE_MATH_DEFINES //dodaje możliwość używania M_PI z cmath
#include <iostream>
#include <cmath>

using namespace std;

class MyData //definicja klasy
{
public:
	int promienKuli;//trzy zmienne
	int wysokoscWalca;
	int wysokoscStozka;
	MyData();//konstruktor bezparametrowy
	MyData(int r, int h1, int h2);//konstruktor parametrowy
	int oblicz_powierchnie();//dwie funkcje w klasie czyli METODY
	int oblicz_objetosc();
};

MyData::MyData()//W przypadku bezparametrowego ustawiamy konkretne wartości
{
	promienKuli = 15;
	wysokoscWalca = 25;
	wysokoscStozka = 4;
}

MyData::MyData(int r, int h1, int h2)//W przypadku parametrowego ustaiamy warości które otzymujemy jako parametr jako właściwe dane
{
	promienKuli = r;
	wysokoscWalca = h1;
	wysokoscStozka = h2;
}

int MyData::oblicz_powierchnie()//obliczanie powierzni i pola z rozpisaniem na poszczególne wzory aby zminimalizować opcje pomylenia się w zapisie wielkiego wzoru naraz
{
	int l = abs((promienKuli ^ 2)+(wysokoscStozka));//L potrzebne do obliczenia powierzchni stożka obliczamy sobie wcześniej
	int powierzchniaBocznaWalca = 2 * M_PI * promienKuli * wysokoscWalca;
	int powierzchniaBocznaStozka = M_PI * promienKuli * l;
	int powierzchniaPolowyKuli = 2 * M_PI * (promienKuli^2);
	return (powierzchniaBocznaStozka + powierzchniaBocznaWalca + powierzchniaPolowyKuli);
}

int MyData::oblicz_objetosc()
{
	int objetoscWalca = M_PI * (promienKuli ^ 2) * wysokoscWalca;
	int objetoscStozka = M_PI * (promienKuli ^ 2) * wysokoscStozka;
	int objetoscPolowyKuli = (2 * M_PI * (promienKuli ^ 3))/3;
	return (objetoscStozka + objetoscWalca + objetoscPolowyKuli);
}

int main()
{
	// powołujemy do życia trzy obiekty (FirstObj,.. to nazwy a w ewentualnym nawiasie przekazujemy parametry)
	MyData FirstObj;
	MyData SecondObj(15,25,4);
	MyData ThirdObj(10,11,12);
	MyData FourthObj(21, 19, 17);

	//Wywołujemy metody dla każdego obiektu
	
	int objetosc1 = FirstObj.oblicz_objetosc();
	int powierzchnia1 = FirstObj.oblicz_powierchnie();
	int objetosc2 = SecondObj.oblicz_objetosc();
	int powierzchnia2 = SecondObj.oblicz_powierchnie();
	int objetosc3 = ThirdObj.oblicz_objetosc();
	int powierzchnia3 = ThirdObj.oblicz_powierchnie();

	cout << "Obietosc obiektu nr 1: " << objetosc1 << "		Powierzchnia obiektu nr 1: " << powierzchnia1 << endl;
	cout << "Obietosc obiektu nr 2: " << objetosc2 << "		Powierzchnia obiektu nr 2: " << powierzchnia2 << endl;
	cout << "Obietosc obiektu nr 3: " << objetosc3 << "		Powierzchnia obiektu nr 3: " << powierzchnia3 << endl;

	int objetosc4 = FourthObj.oblicz_objetosc();
	int powierzchnia4 = FourthObj.oblicz_powierchnie();

	cout << "Obietosc obiektu nr 3: " << objetosc3 << "		Powierzchnia obiektu nr 3: " << powierzchnia3 << endl << endl;

}

