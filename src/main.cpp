#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<cstdlib>

using namespace std;
class Pojazd
{
public:
	virtual string nazwa() = 0;
	virtual float cena_za_dzien() = 0;
	virtual int rok() = 0;
	virtual int liczba_miejsc() = 0;
	virtual float wypozyczenie() = 0;
};
class Samochod_osobowy : public Pojazd
{
public:
	Samochod_osobowy(string nazwa, float cena, int rok, int liczba_miejsc, int ile_dni)
	{
		n = nazwa;
		c = cena;
		r = rok;
		l = liczba_miejsc;
		ile = ile_dni;
		cout << "Wprowadz nazwe,cene za dzien,rok,liczbe mijesc,ilosc dni wypozyczenia, np. volvo 200 1999 5 20" << endl;
		cin >> n >> c >> r >> l >> ile;

	}
	virtual string nazwa()
	{
		return n;
	}
	virtual float cena_za_dzien()
	{
		return c;
	}
	virtual int rok()
	{
		return r;
	}
	virtual int liczba_miejsc()
	{
		return l;
	}
	virtual float wypozyczenie()
	{
		if (ile == 1)
		{
			return c;
		}
		else if (ile == 2)
		{
			return c * ile;
		}
		else if (ile >= 3 && ile <= 6)
		{
			return c * ile - c / 2;
		}
		else if (ile >= 7 && ile <= 14)
		{
			return c * ile - c;
		}
		else if (ile >= 15 && ile <= 30)
		{
			return c * ile - 2 * c;
		}
		else
		{
			return c * ile - 4 * c;
		}

	}

private:
	string n;
	float c;
	int r, l, ile;
};

class Samochod_ciezarowy : Pojazd
{
public:
	Samochod_ciezarowy(string nazwa, float cena, int rok, int ladownosc, int ile_dni)
	{
		n = nazwa;
		c = cena;
		r = rok;
		l = ladownosc;
		ile = ile_dni;
		cout << "Wprowadz nazwe,cene za dzien,rok,ladownosc w kg,ilosc dni wypozyczenia, np. volvo 200 1999 5 20" << endl;
		cin >> n >> c >> r >> l >> ile;
	}
	virtual string nazwa()
	{
		return n;
	}
	virtual float cena_za_dzien()
	{
		return c;
	}
	virtual int rok()
	{
		return r;
	}
	virtual int liczba_miejsc()
	{
		return l;
	}
	virtual float wypozyczenie()
	{
		if (ile == 1)
		{
			return c;
		}
		else if (ile == 2)
		{
			return c * ile;
		}
		else if (ile >= 3 && ile <= 6)
		{
			return c * ile - c / 2;
		}
		else if (ile >= 7 && ile <= 14)
		{
			return c * ile - c;
		}
		else if (ile >= 15 && ile <= 30)
		{
			return c * ile - 4 * c;
		}
		else
		{
			return c * ile - 6 * c;
		}
	}
private:
	string n;
	float c;
	int r, l, ile;
};
class Autokar : Pojazd
{
public:
	Autokar(string nazwa, float cena, int rok, int liczba_miejsc, int ile_dni)
	{
		n = nazwa;
		c = cena;
		r = rok;
		l = liczba_miejsc;
		ile = ile_dni;
		cout << "Wprowadz nazwe,cene za dzien,rok,liczbe mijesc,ilosc dni wypozyczenia, np. volvo 200 1999 5 20" << endl;
		cin >> n >> c >> r >> l >> ile;
	}
	virtual string nazwa()
	{
		return n;
	}
	virtual float cena_za_dzien()
	{
		return c;
	}
	virtual int rok()
	{
		return r;
	}
	virtual int liczba_miejsc()
	{
		return l;
	}
	virtual float wypozyczenie()
	{
		if (ile == 1)
		{
			return c;
		}
		else if (ile == 2)
		{
			return c * ile;
		}
		else if (ile >= 3 && ile <= 6)
		{
			return c * ile - c / 2;
		}
		else if (ile >= 7 && ile <= 14)
		{
			return c * ile - c;
		}
		else if (ile >= 15 && ile <= 30)
		{
			return c * ile - 3 * c;
		}
		else
		{
			return c * ile - 5 * c;
		}
	}
private:
	string n;
	float c;
	int r, l, ile;
};
/*
class Bazowadozapisu
{
public:
	Bazowadozapisu() {}
	virtual ~Bazowadozapisu() {}
	virtual void zapis(string spis) = 0;

};
class SpisKlientow : public Bazowadozapisu
{
public:
	SpisKlientow() {}
	virtual void zapis(string spis)
	{
		cout << spis << endl;
	}
};
class ZapisKlientow : public Bazowadozapisu
{
public:
	ZapisKlientow(string nazwapliku)
	{
		plik.open(nazwapliku, ofstream::out | ofstream::app);
	}
	virtual ~ZapisKlientow()
	{
		plik.close();
	}
	virtual void zapis(string spis)
	{
		plik << spis << endl;
	}

private:
	ofstream plik;
};
*/
class Placa
{
public:
	virtual float pensja() = 0;
};
class Pensja_mechanika : public Placa
{
public:
	Pensja_mechanika(float ilosc_godzin, float godzinowka_mechanika)
	{
		ilosc = ilosc_godzin;
		gm = godzinowka_mechanika;
		cout << "Wpisz ilosc godzin w miesiacu, stawke godzinowa" << endl;
		cin >> ilosc;
		cin >> gm;
	}
	virtual float pensja()
	{
		if (ilosc >= 0 && ilosc <= 100)
		{
			return gm * ilosc;
		}
		else if (ilosc >= 101 && ilosc <= 200)
		{
			return gm * ilosc + 150;
		}
		else if (ilosc >= 201 && ilosc <= 300)
		{
			return gm * ilosc + 300;
		}
		else
		{
			return gm * ilosc + 400;
		}
	}
private:
	float ilosc, gm;

};
class Pensja_sekretarki : public Placa
{
public:
	Pensja_sekretarki(float ilosc_godzin, float godzinowka_sekretarki)
	{
		ilosc = ilosc_godzin;
		gm = godzinowka_sekretarki;
		cout << "Wpisz ilosc godzin w miesiacu, stawke godzinowa" << endl;
		cin >> ilosc;
		cin >> gm;
	}
	virtual float pensja()
	{
		if (ilosc >= 0 && ilosc <= 100)
		{
			return gm * ilosc;
		}
		else if (ilosc >= 101 && ilosc <= 200)
		{
			return gm * ilosc + 100;
		}
		else if (ilosc >= 201 && ilosc <= 300)
		{
			return gm * ilosc + 200;
		}
		else
		{
			return gm * ilosc + 300;
		}
	}
private:
	float ilosc, gm;

};
class Pensja_ochroniarza : public Placa
{
public:
	Pensja_ochroniarza(float ilosc_godzin, float godzinowka_ochroniarza)
	{
		ilosc = ilosc_godzin;
		gm = godzinowka_ochroniarza;
		cout << "Wpisz ilosc godzin w miesiacu, stawke godzinowa" << endl;
		cin >> ilosc;
		cin >> gm;
	}
	virtual float pensja()
	{
		if (ilosc >= 0 && ilosc <= 100)
		{
			return gm * ilosc;
		}
		else if (ilosc >= 101 && ilosc <= 200)
		{
			return gm * ilosc + 50;
		}
		else if (ilosc >= 201 && ilosc <= 300)
		{
			return gm * ilosc + 100;
		}
		else
		{
			return gm * ilosc + 150;
		}
	}
private:
	float ilosc, gm;

};

class Danefirmy
{
public:
	void danefirmy()
	{
		plikdanych.open("danefirmy.txt", ios::in);
		if (plikdanych.good() == false)
		{
			cout << "nie mozna znalez pliku" << endl;
			exit(0);
			
		}
		while (getline(plikdanych, linia))
		{
			switch (nr_lini)
			{
			case 1: nazwafirmy = linia; break;
			case 2: ulica = linia; break;
			case 3: email = linia; break;
			case 4: telefon = atoi(linia.c_str()); break;
			}
			nr_lini++;
		}
		cout << "Nazwa firmy: " << nazwafirmy << endl;
		cout << "Ulica: " << ulica << endl;
		cout << "Dane kontaktowe: " << endl;
		cout << "Email: " << email << endl;
		cout << "Telefon: " << telefon << endl;


	}
private:
	fstream plikdanych;
	string linia;
	int nr_lini = 1;
	string nazwafirmy, email, ulica;
	int telefon;
};

class Osoba
{
public:
	virtual string imie() = 0;
};




int main()
{

	//wypisywanie danych firmy z pliku
	Danefirmy d1;
	d1.danefirmy();
	cout << endl;
	//zmienne
	string osoba;
	vector<Pojazd*> pojazdy = {};
	vector<Placa*> placa = {};
	string dodawanie, dodawanieplac;
	int wybor = 0;
	cout << "Wbierz czy chcesz dzialac jako szef czy klient, wpisz klient lub szef" << endl;
	cin >> osoba;

	while (true)
	{
		if (osoba == "szef")
		{

			// wpisywanie wypozyczonych pojazdow i obliczanie zaleznosci 1.nazwa 2.cena_zadzien 3. rok 4 . ilosc miejsa 5. ilosc dni wypozyczenia
			cout << "Jesli chcesz dodac samochod osobowy to wpisz samochod_o ,jesli chcesz dodac samochod ciezarowy to wpisz samochod_c,jesli chcesz dodac autokar to wpisz autokar" << endl;
			cin >> dodawanie;
			while (true)
			{
				if (dodawanie == "samochod_o")
				{
					pojazdy.push_back((Pojazd*)new Samochod_osobowy("wewe", 123, 123, 123, 123));

				}
				else if (dodawanie == "samochod_c")
				{
					pojazdy.push_back((Pojazd*)new Samochod_ciezarowy("wewe", 123, 123, 123, 123));

				}
				else if (dodawanie == "autokar")
				{
					pojazdy.push_back((Pojazd*)new Autokar("wewe", 123, 123, 123, 123));

				}
				else if (dodawanie != "autokar" || "samochod_c" || "samochod_o") break;

				cout << "Dodaj kolejny pojazd lub zakonczy wpisujac end" << endl;
				cin >> dodawanie;
			}

			// wypisywanie danych wypozyczenia i kosztow 
			for (Pojazd* f : pojazdy) {
				cout << " " << f->nazwa() << ",cena za dzien= " << f->cena_za_dzien() << ",rok = " <<
					f->rok() << ",liczba_miejsc= " << f->liczba_miejsc() << ",koszt wypozyczenia= " << f->wypozyczenie() << endl;
			}


			cout << endl;
			/*
			// dodawanie plikow do zapisu klientow
			vector<Bazowadozapisu*> zapisy = {
				new SpisKlientow(),
				new ZapisKlientow("spisklientow.txt")
			};
			cout << "Klienci: " << endl;
			// dodawanie danych klientow
			for (auto* z : zapisy)
			{
				z->zapis("1. Stanislaw Kowalski wiek 27");
				z->zapis("2. Wojciech Nowak wiek 30");
			};
			for (auto* z : zapisy) delete z;
			zapisy.clear();
			*/
			cout << endl;

			// dodawanie pracownikow 1.ilosc_godzin w miesiac 2.godzinowka
			cout << "Jesli chcesz obliczyc pensje mechanika wpisz mechanik,jesli sekretarki wpisz sekretarka,jesli ochroniarza wpisz ochroniasz,jesli nie chcesz to wpisz cokoliwek" << endl;
			cin >> dodawanieplac;
			while (true)
			{
				if (dodawanieplac == "sekretarka")
				{
					placa.push_back((Placa*)new Pensja_mechanika(111, 11));

				}
				else if (dodawanieplac == "ochroniarz")
				{
					placa.push_back((Placa*)new Pensja_ochroniarza(111, 11));

				}
				else if (dodawanieplac == "mechanik")
				{
					placa.push_back((Placa*)new Pensja_sekretarki(111, 11));

				}
				else if (dodawanieplac != "sekretarka" || "ochroniarz" || "mechanik") break;

				cout << "Oblicz kolejna pensje lub zakoncz" << endl;
				cin >> dodawanieplac;
			}
			cout << "Pensje pracownikow: " << endl;
			// wypisywanie penji miesiecznej pracownikow
			for (Placa* p : placa)
			{
				cout << "placa pracownika wynosi = " << p->pensja() << endl;
			}
			cout << "Wbierz czy chcesz pracowac jako szef czy klient, wpisz klient lub szef,jesli chcesz zakonczyc wpisz cokoliwek" << endl;
			cin >> osoba;
		}

		else if (osoba == "klient")
		{
			cout << "Aktualnie dostepne samochody" << endl;
			for (Pojazd* f : pojazdy) {
				cout << f->nazwa() << ",cena za dzien= " << f->cena_za_dzien() << ",rok = " <<
					f->rok() << ",liczba_miejsc= " << f->liczba_miejsc() << ",koszt wypozyczenia= " << f->wypozyczenie() << endl;
			}
			cout << "Wybierz samochod ktory chcesz wypozyczyc, wpisz jego numer na liscie" << endl;
			cin >> wybor;
			pojazdy.erase(pojazdy.begin() + wybor - 1);

			cout << "Wbierz czy chcesz pracowac jako szef czy klient, wpisz klient lub szef,jesli chcesz zakonczyc wpisz cokoliwek" << endl;
			cin >> osoba;
		}
		else break;
	}

	return 0;
}


