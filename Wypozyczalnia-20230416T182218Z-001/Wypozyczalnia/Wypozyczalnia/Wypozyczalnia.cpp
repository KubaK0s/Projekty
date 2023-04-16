/* @file */
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <Windows.h>;



using namespace std;

/** Funkcja wyswietlajaca interfejs, w ktorym uzytkownik decyduje co chce zrobic w programie.

*/
void menu() {

cout << "--------------------------------" << endl;
cout << "--------------------------------" << endl;
cout << "----------WYPOZYCZALNIA---------" << endl;
cout << "-------SPRZETU-SPORTOWEGO-------" << endl;
cout << "--------------------------------" << endl;
cout << "--------------------------------" << endl;
cout << "Witamy w wypozyczalni!" << endl;
cout << "Wybierz opcje:" << endl;
cout << "1 -> Wyswietl wszystkie sprzety" << endl;
cout << "2 -> Wyswietl wszystkich klientow" << endl;
cout << "3 -> Wyswietl wszystkich wypozyczajacych" << endl;
cout << "4 -> Sprawdz dostepne sprzety" << endl;
cout << "5 -> Dodaj sprzet" << endl;
cout << "6 -> Dodaj klienta" << endl;
cout << "7 -> Aktualnie wypozyczony sprzet" << endl;
cout << "8 -> Zamknij system" << endl;
cout << "" << endl;

}

/** Funkcja void wczytaj() wczytuje parametr.
@param int wybor
*/
void wczytaj() {
	int wybor;
	cin >> wybor;
}



/** Klasa Sprzet
@param  string id
@param  string nazwa
@param  string sport
@param  string cena
@param bool dostepnosc
*/
class Sprzet {
public:
	string id;
	string nazwa;
	string sport;
	string cena;
	bool dostepnosc;

	/** Konstruktor
@param   id = ""
@param   nazwa = ""
@param	 sport = ""
@param   cena = ""
@param   dostepnosc = false
*/
	Sprzet() {
		id = "";
		nazwa = "";
		sport = "";
		cena = "";
		dostepnosc = false;
	};

	/** Konstruktor przeciążony
@param   id = _id
@param   nazwa = _nazwa
@param	 sport = _sport
@param   cena = _cena
@param   dostepnosc = _dostepnosc
*/
	Sprzet(string _id, string _nazwa, string _sport, string _cena, bool _dostepnosc) {
		id = _id;
		nazwa = _nazwa;
		sport = _sport;
		cena = _cena;
		dostepnosc = _dostepnosc;
	}
	/** Metoda void pokazDane() sluzy do wyswietlania atrybutow klasy Sprzet

	*/
	void pokazDane() {
		cout <<"" << id << "\t " << nazwa << " " << sport << "\t " << cena << " \t";
	}
	/** Metoda string getId() zwraca id

	*/
	string getId() { return id; }
	/** Metoda bool aktualnieDostepne() zwraca dostepnosc

	*/
	bool aktualnieDostepne() { return dostepnosc;}
};




/**Klasa Klient
@param  string pesel
@param  string imie
@param  string nazwisko
@param  string miasto
@param  string wiek 
*/
class Klient {
public:
	string pesel;
	string imie;
	string nazwisko;
	string miasto;
	string wiek;

	/** Konstruktor
@param   imie = ""
@param   nazwisko = ""
@param	 pesel = ""
@param   miasto = ""
@param   wiek = ""
*/
		Klient() {
		imie = "";
		nazwisko = "";
		pesel = "";
		miasto = "";
		wiek = "";

		}

/** Konstruktor przeciążony
	@param		pesel = _pesel;
	@param		imie = _imie;
	@param		nazwisko = _nazwisko;
	@param		miasto = _miasto;
	@param		wiek = _wiek;
		*/
	Klient(string  _pesel, string _imie, string _nazwisko, string _miasto, string _wiek)
	{
		pesel = _pesel;
		imie = _imie;
		nazwisko = _nazwisko;
		miasto = _miasto;
		wiek = _wiek;
		
	}

	/** Metoda void pokazDane() sluzy do wyswietlania atrybutow klasy Klient

	*/
	void pokazDane() {
		cout << pesel << " " << imie << " " << nazwisko << "\t" << miasto << "\t" << wiek << "\t";
	}

};

/** Klasa WypozyczonySprzet bedaca pochodna klasy Sprzet
@param  string id
@param  string nazwa
@param  string sport
@param  string cena
@param bool dostepnosc
@param  dataWypozyczenia
@param  pesel
*/
class WypozyczonySprzet : public Sprzet {
public:
	string dataWypozyczenia;
	string pesel;


	/** Konstruktor przeciążony
@param   id = _id
@param   nazwa = _nazwa
@param	 sport = _sport
@param   cena = _cena
@param   dostepnosc = _dostepnosc
*/
	WypozyczonySprzet(string _id, string _sport, string _nazwa,  string _cena, string _dostepnosc, string _dataWypozyczenia, string _pesel)
		: Sprzet(_id, _sport, _nazwa, _cena, dostepnosc) {
		dostepnosc = false;
		dataWypozyczenia = _dataWypozyczenia;
		pesel = _pesel;
	}

};
/** Wektor sprzetow
*/
vector<Sprzet> sprzety;
/** Wektor klientow
*/
vector<Klient> klienci;
/** Wektor wypozyczonych sprzetow
*/
vector<WypozyczonySprzet> wypozyczonysprzet;



/** Metoda void wczytajSprzet() sluzy do wczytywania danych na temat sprzetu z pliku i wpisuje je do vectora klas

*/
void wczytajSprzet() {
		fstream daneSprzet("Sprzety.txt");
		string id, nazwa, sport, cena, _dostepnosc;
		bool dostepnosc;
		sprzety.clear();
		if (daneSprzet) {
			while (!daneSprzet.eof()) {
				getline(daneSprzet, id, '\t');
				if (id != "") {
					getline(daneSprzet, nazwa, '\t');
					getline(daneSprzet, sport, '\t');
					getline(daneSprzet, cena, '\t');
					getline(daneSprzet, _dostepnosc, '\t');
					if (_dostepnosc == "true") {
						dostepnosc = true;
					}
					else {
						dostepnosc = false;
					}
					Sprzet sprzet(id, nazwa, sport, cena, dostepnosc);
					sprzety.push_back(sprzet);
				}
			}
		}
		daneSprzet.close();
	}
/** Metoda void wczytajKlientow() sluzy do wczytywania danych na temat klientow z pliku i wpisuje je do vectora klas

*/
void wczytajKlientow() {
	fstream daneKlienci("Klienci.txt");
	string _pesel, imie, nazwisko, miasto, _wiek;
	klienci.clear();
	if (daneKlienci) {
		while (!daneKlienci.eof()) {
			getline(daneKlienci, _pesel, '\t');
			if (_pesel != "") {
				getline(daneKlienci, imie, '\t');
				getline(daneKlienci, nazwisko, '\t');
				getline(daneKlienci, miasto, '\t');
				getline(daneKlienci, _wiek, '\t');
				Klient klient(_pesel, imie, nazwisko, miasto, _wiek);
				klienci.push_back(klient);
			}
		}
	}
	daneKlienci.close();
}
/** Metoda void wczytajWypozyczoneSprzet() sluzy do wczytywania danych na temat wypozyczonych sprzetow z pliku i wpisuje je do vectora klas

*/
void wczytajWypozyczoneSprzet() {
	fstream daneWypozyczonySprzet("WypozyczoneSprzety.txt");
	string id, nazwa, sport, cena, dostepnosc, dataWypozyczenia, pesel;
	daneWypozyczonySprzet.clear();
	if (daneWypozyczonySprzet) {
		while (!daneWypozyczonySprzet.eof()) {
			getline(daneWypozyczonySprzet, id, '\t');
			if (id != "") {
				getline(daneWypozyczonySprzet, nazwa, '\t');
				getline(daneWypozyczonySprzet, sport, '\t');
				getline(daneWypozyczonySprzet, cena, '\t');
				getline(daneWypozyczonySprzet, dostepnosc, '\t');
				getline(daneWypozyczonySprzet, dataWypozyczenia, '\t');
				getline(daneWypozyczonySprzet, pesel, '\n');
				WypozyczonySprzet wypozyczonySprzet(id, nazwa, sport, cena, dostepnosc, dataWypozyczenia, pesel);
				wypozyczonysprzet.push_back(wypozyczonySprzet);
			}
		}
	}
	daneWypozyczonySprzet.close();
}
/** Metoda void wyswietlKlientow() sluzy do wyswietlania listy klientow wypozyczalni

*/
void wyswietlKlientow() {
	cout << "Wszyscy Klienci" << endl;

	for (int i = 0; i < klienci.size(); i++) {
		klienci[i].pokazDane();
		cout << endl;
	}
}
/** Metoda void wyswietlSprzety() sluzy do wyswietlania sprzetow mozliwych do wypozyczenia

*/
void wyswietlSprzety() {
	cout << "Wszystkie sprzety" << std::endl;

	for (int i = 0; i < sprzety.size(); i++) {
		sprzety[i].pokazDane();
		cout << endl;
	}
}
/** Metoda void wyswietlWypozyczajacych() sluzy do wyswietlania osob aktualnie wypozyczajacych jakis sprzet
*/
void wyswietlWypozyczajacych() {
	cout << "Klienci aktualnie wypozyczajacy sprzet sportowy" << endl;
	for (int i = 0; i < klienci.size(); i++) {
		klienci[i].pokazDane();
		cout << endl;
	}
}

/** Metoda void wyswietlWypozyczoneSprzety() sluzy do wyswietlania wypozyczonego sprzetu
*/
void wyswietlWypozyczoneSprzety() {
	cout << "Aktualnie wypozyczone sprzety" << endl;
	for (int i = 0; i < wypozyczonysprzet.size(); i++) {
		wypozyczonysprzet[i].pokazDane();
		cout << endl;
	}
}

/** Metoda void dostepneSprzety() sluzy do wyswietlania nie wypozyczonego sprzetu
*/
void dostepneSprzety() {
	cout << "Dostepne sprzety" << std::endl;
	for (int i = 0; i  < sprzety.size(); i++) {
		sprzety[i].pokazDane();
		cout << endl;
	
	}
}

/** Metoda void dodajSprzet() sluzy do dodawania nowego sprzetu do magazynu
*/
void dodajSprzet() {
	string id, nazwa, sport, cena;
	bool dostepnosc = true;

	cout << "\tWprowadz numer sprzetu: ";
	getline(cin, id);
	getline(cin, id);
	if (nazwa == "5") {
		cout << "Nieprawidlowe dane" << endl;
	}
	else {
		cout << "\tWprowadz nazwe sprzetu: ";
		getline(cin, nazwa);
		cout << "\tWprowadz dyscypline sportu: ";
		getline(cin, sport);
		cout << "\tWprowadz cene: ";
		getline(cin, cena);
		Sprzet sprzet(id, nazwa, sport, cena, true);
					sprzety.push_back(sprzet);
					
	}
}

/** Metoda void dodajKlienta() sluzy do dodawania nowych klientow
*/
void dodajKlienta() {
	string pesel, imie, nazwisko, miasto, wiek;
	
	cout << "\tWprowadz numer pesel: ";
	getline(cin, pesel);
	getline(cin, pesel);
	if (pesel == "8") {
		cout << "Nieprawidlowe dane" << endl;
	}
	else {
		cout << "\tWprowadz imie klienta: ";
		getline(cin, imie);
		cout << "\tWprowadz nazwisko klienta: ";
		getline(cin, nazwisko);
		cout << "\tWprowadz miejsce zamieszkania klienta: ";
		getline(cin, miasto);
		cout << "\tWprowadz wiek klienta: ";
		getline(cin, wiek);
		Klient klient(pesel, imie, nazwisko, miasto, wiek);
		klienci.push_back(klient);

	}
}

/** Metoda void drukKlient() sluzy do drukowania ilosci klientow
*/
void drukKlient() {

	ofstream zapisKlientow("KlienciWydruk.txt");
	zapisKlientow << "--------------------------------" << endl;
	zapisKlientow << "--------------------------------" << endl;
	zapisKlientow << "----------WYPOZYCZALNIA---------" << endl;
	zapisKlientow << "-------SPRZETU-SPORTOWEGO-------" << endl;
	zapisKlientow << "--------------------------------" << endl;
	zapisKlientow << "--------------------------------" << endl;
	zapisKlientow << "------------Klienci-------------" << endl;
	zapisKlientow << "Ilosc klientow:" << 6 << endl;
}

/** Metoda void drukSprzet() sluzy do drukowania ilosci sprzetu
*/
void drukSprzet() {

	ofstream zapisSprzetu("Sprzetwydruk.txt");
	zapisSprzetu << "--------------------------------" << endl;
	zapisSprzetu << "--------------------------------" << endl;
	zapisSprzetu << "----------WYPOZYCZALNIA---------" << endl;
	zapisSprzetu << "-------SPRZETU-SPORTOWEGO-------" << endl;
	zapisSprzetu << "--------------------------------" << endl;
	zapisSprzetu << "--------------------------------" << endl;
	zapisSprzetu << "------------Sprzet-------------" << endl;
	zapisSprzetu << "Ilosc sprzetu:" << 11 << endl;
	zapisSprzetu.close();
}

	

int main(int argc, const char* argv[])
{  
	system("CLS");
	menu();
	wczytajSprzet();
	wczytajKlientow();
	wczytajWypozyczoneSprzet();
	drukKlient();
	drukSprzet();
	
	int wybor;
	cin >> wybor;
	while (cin.fail()) {
		cout << "Wprowadziles bledne dane" << endl;

		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Wprowadz dane ponownie:";
		cin >> wybor;
	}
	while (wybor != 8) {

		switch (wybor) {
		case 1:
			system("CLS");
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "----------WYPOZYCZALNIA---------" << endl;
			cout << "-------SPRZETU-SPORTOWEGO-------" << endl;
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "-----------------------------------------------------" << endl;
			wyswietlSprzety();
			cout << "-----------------------------------------------------" << endl;
			break;

		case 2:
			system("CLS");
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "----------WYPOZYCZALNIA---------" << endl;
			cout << "-------SPRZETU-SPORTOWEGO-------" << endl;
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "-----------------------------------------------------" << endl;
			wyswietlKlientow();
			cout << "-----------------------------------------------------" << endl;
			
			break;
		case 3:
			system("CLS");
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "----------WYPOZYCZALNIA---------" << endl;
			cout << "-------SPRZETU-SPORTOWEGO-------" << endl;
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "-----------------------------------------------------" << endl;
			wyswietlWypozyczajacych();
			cout << "-----------------------------------------------------" << endl;

			break;
		case 4:
			system("CLS");
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "----------WYPOZYCZALNIA---------" << endl;
			cout << "-------SPRZETU-SPORTOWEGO-------" << endl;
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "-----------------------------------------------------" << endl;
			dostepneSprzety();
			cout << "-----------------------------------------------------" << endl;
			break;
		case 5:
			system("CLS");
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "----------WYPOZYCZALNIA---------" << endl;
			cout << "-------SPRZETU-SPORTOWEGO-------" << endl;
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "-----------------------------------------------------" << endl;
			dodajSprzet();
			cout << "-----------------------------------------------------" << endl;
			break;
		case 6:
			system("CLS");
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "----------WYPOZYCZALNIA---------" << endl;
			cout << "-------SPRZETU-SPORTOWEGO-------" << endl;
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "-----------------------------------------------------" << endl;
			dodajSprzet();
			cout << "-----------------------------------------------------" << endl;
			break;
		case 7:
			system("CLS");
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "----------WYPOZYCZALNIA---------" << endl;
			cout << "-------SPRZETU-SPORTOWEGO-------" << endl;
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "-----------------------------------------------------" << endl;
			wyswietlWypozyczoneSprzety();
			cout << "-----------------------------------------------------" << endl;
			
			break;
		case 8:
			system("CLS");
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "----------WYPOZYCZALNIA---------" << endl;
			cout << "-------SPRZETU-SPORTOWEGO-------" << endl;
			cout << "--------------------------------" << endl;
			cout << "--------------------------------" << endl;
			cout << "Zamknij system" << endl;
			break;
		default:

			system("cls");
			menu();
			cout << "Zostala wprowadzona zla wartosc" << endl;

			break;
		}
		cin >> wybor;
	}

	return 0;
}