#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <memory>
#include <vector>

using namespace std;
//menu
void menu() {

    cout << "--------------------------------" << endl;
    cout << "--------------------------------" << endl;
    cout << "-----------KSIEGARNIA-----------" << endl;
    cout << "--------------------------------" << endl;
    cout << "--------------------------------" << endl;
    cout << "--------------------------------" << endl;
    cout << "Witamy w Ksiegarni!" << endl;
    cout << "Wybierz opcje:" << endl;
    cout << "1 -> Wyswietl wszystkich klientow" << endl;
    cout << "2 -> Wyswietl wszystkie ksiazki" << endl;
    cout << "3 -> Usun klienta" << endl;
    cout << "4 -> Wypozycz ksiazke" << endl;
    cout << "5 -> Znajdz klienta" << endl;
    cout << "6 -> Znajdz ksiazke" << endl;
    cout << "7 -> Posortuj klientow wzgledem numeru pesel rosnaco" << endl;
    cout << "8 -> Posortuj klientow wzgledem numeru pesel malejaco" << endl;
    cout << "9 -> Posortuj ksiazki wzgledem liczby stron rosnaco" << endl;
    cout << "10 -> Posortuj ksiazki wzgledem liczby stron malejaco" << endl;
    cout << "11 -> Dodaj klienta" << endl;
    cout << "12 -> Dodaj ksiazke" << endl;
    cout << "13 -> Zamknij program" << endl;
    cout << "" << endl;
}
//klasa osoby zawierajaca informacje o kliencie
class Osoby {
public:
    int pesel;
    string imie;
    string nazwisko;
    string data_urodzenia;
    string adres;

    Osoby() { pesel = 0; imie = ""; nazwisko = ""; data_urodzenia = ""; adres = ""; }

    Osoby(int _pesel, string _imie, string _nazwisko, string _data_urodzenia, string _adres) {
        pesel = _pesel;
        imie = _imie;
        nazwisko = _nazwisko;
        data_urodzenia = _data_urodzenia;
        adres = _adres;
    }
    friend ostream& operator<<(ostream& os, const Osoby& obj);
};


//klasa zawierajaca informacje o ksiazkach
class Ksiazka {
public:
    int id;
    string tytul;
    string autor;
    string data_wydania;
    int liczba_stron;

    Ksiazka() { id = 0; tytul = ""; autor = ""; data_wydania = ""; liczba_stron = 0; }

    Ksiazka(int _id, string _tytul, string _autor, string _data_wydania, int _listastron) {
        id = _id;
        tytul = _tytul;
        autor = _autor;
        liczba_stron = _listastron;
    }
    friend ostream& operator<<(ostream& os, const Ksiazka& obj);
};
ostream& operator<<(std::ostream& os, const Osoby& obj)
{
    os << obj.pesel << '\t' << obj.imie << '\t' << obj.nazwisko << '\t' << obj.data_urodzenia << '\t' << obj.adres;
    return os;
}
ostream& operator<<(std::ostream& os, const Ksiazka& obj)
{
    os << obj.id << '\t' << obj.tytul << '\t' << obj.autor << '\t' << obj.data_wydania << '\t' << obj.liczba_stron;
    return os;
}
//szablon listy oraz elemntow listy 
template <typename T>
class Element
{
public:
    Element(const T& d) : d(d) {}
    T d;
    shared_ptr<Element<T>> nastepny;
    weak_ptr<Element<T>> poprzedni;
};

template <typename T>
class Lista {
public:
    shared_ptr<Element<T>> glowa;
    shared_ptr<Element<T>> ogon;
    int dlugosc;
    Lista() : glowa(nullptr), ogon(nullptr) {}
    ~Lista() {}


    //funckja ktora dodaje elementy na koniec listy
    void dodajNaKoncu(const T& d)
    {
        shared_ptr<Element<T>> nowy = make_shared<Element<T>>(d);
        if (dlugosc == 0)
        {
            glowa = make_shared<Element<T>>(d);
            ogon = glowa;
        }
        else
        {
            shared_ptr<Element<T>> nowy = make_shared<Element<T>>(d);
            ogon->nastepny = nowy;
            nowy->poprzedni = ogon;
            ogon = ogon->nastepny;
        }
        dlugosc++;
    }

    void dodajWSrodku(int index, const T& d)
    {
        if (!(index >= 0 && index <= dlugosc))
        {
            throw invalid_argument("Niewlasciwy index");
        }

        shared_ptr<Element<T>> tymczasowy = glowa;
        for (int i = 0; i < index - 1; i++)
        {
            tymczasowy = tymczasowy->nastepny;
        }
        shared_ptr<Element<T>> nowy = make_shared<Element<T>>(d);
        shared_ptr<Element<T>> tymczasowy2 = tymczasowy->nastepny;
        tymczasowy->nastepny = nowy;
        nowy->poprzedni = tymczasowy;
        tymczasowy2->poprzedni = nowy;
        nowy->nastepny = tymczasowy2;
    }

    //funkcja odpowiedzialna za usuwanie elementow z listy
    void usunElement(int pesel1, auto(*lambda)(T&, int&)->bool) {
        shared_ptr<Element<T>> tymczasowy = glowa;
        while (tymczasowy != nullptr) {
            if (lambda(tymczasowy->d, pesel1)) {
                if (tymczasowy == glowa) {
                    glowa = tymczasowy->nastepny;
                }
                else {
                    tymczasowy->poprzedni.lock()->nastepny = tymczasowy->nastepny;
                }
                if (tymczasowy == ogon) {
                    ogon = tymczasowy->poprzedni.lock();
                }
                else {
                    tymczasowy->nastepny->poprzedni = tymczasowy->poprzedni;
                }
                break;
            }
            tymczasowy = tymczasowy->nastepny;
        }
    }

   /* T znajdz(int pesel, auto(*lambda)(T&, int&)->bool) {
        shared_ptr<Element<T>> tymczasowy = glowa;
        while (tymczasowy != nullptr) {
            if (lambda(tymczasowy->d, pesel))
                return tymczasowy.get()->d;
            tymczasowy = tymczasowy->nastepny;
        }
        T osoba;
        osoba.pesel = 0;
        return osoba;
    }*/
    //funckje odpowiedzialna za znajdywanie elementu w liscie
    T znajdz(int pesel, auto(*lambda)(T&, int&)->bool) {
        shared_ptr<Element<T>> current = glowa;
        while (current != nullptr) {
            if (lambda(current->d, pesel))
                return current.get()->d;
            current = current->nastepny;
        }
        T osoba;
        osoba.pesel = 0;
        return osoba;
    }
  
    T znajdz1(int id, auto(*lambda)(T&, int&)->bool) {
        shared_ptr<Element<T>> tymczasowy = glowa;
        while (tymczasowy != nullptr) {
            if (lambda(tymczasowy->d, id))
                return tymczasowy.get()->d;
            tymczasowy = tymczasowy->nastepny;
        }
        T ksiazka;
        ksiazka.id = 0;
        return ksiazka;
    }
    //wyswietlanie elementu lub calej listy
    void wyswietl()
    {
        shared_ptr<Element<T>> tymczasowy = glowa;
        while (tymczasowy)
        {
            cout << tymczasowy->d << endl;
            tymczasowy = tymczasowy->nastepny;
        }
    }

    void wyswietlOdKonca()
    {
        shared_ptr<Element<T>> tymczasowy = ogon;
        while (tymczasowy)
        {
            cout << tymczasowy->d << endl;
            tymczasowy = tymczasowy->poprzedni.lock();
        }
    }
    //sortowanie elementow w liscie 
    void sortujRosnaco(auto(*lambda)(T&, T&)->bool) {
        for (shared_ptr<Element<T>> i = glowa; i != ogon; i = i->nastepny) {
            shared_ptr<Element<T>> min = i;
            for (shared_ptr<Element<T>> j = i->nastepny; j != nullptr; j = j->nastepny) {
                if (lambda(j->d, min->d))
                    min = j;
            }
            swap(i->d, min->d);
        }
    }
    void sortujMalejaco(auto(*lambda)(T&, T&)->bool) {
        for (shared_ptr<Element<T>> i = glowa; i != ogon; i = i->nastepny) {
            shared_ptr<Element<T>> max = i;
            for (shared_ptr<Element<T>> j = i->nastepny; j != nullptr; j = j->nastepny) {
                if (lambda(j->d, max->d))
                    max = j;
            }
            swap(i->d, max->d);
        }
    }
    //zapis do pliku
    void zapis(string nazwa) {
        ofstream plik(nazwa);
        if (plik) {
            shared_ptr<Element<T>> curr = glowa;
            while (curr != nullptr) {
                plik << curr->d << endl;
                curr = curr->nastepny;
            }
        }
    }
    


    };


int main()
{



    system("CLS");
    menu();
    auto lambda1 = [](Osoby& value1, Osoby& value2)->bool { return value1.pesel <= value2.pesel; };
    auto lambda2 = [](Osoby& value1, Osoby& value2)->bool { return value1.pesel >= value2.pesel; };
    auto lambda3 = [](Ksiazka& value1, Ksiazka& value2)->bool { return value1.liczba_stron <= value2.liczba_stron; };
    auto lambda4 = [](Ksiazka& value1, Ksiazka& value2)->bool { return value1.liczba_stron >= value2.liczba_stron; };
    auto lambda5 = [](Osoby& value1, int& value2)->bool { return value1.pesel == value2; };
    auto lambda6 = [](Ksiazka& value1, int& value2)->bool { return value1.id == value2; };
    Osoby found;
    Ksiazka found1;

    Lista<Osoby> lista;
    Osoby osoba;
    ifstream inFile("Osoby.txt");
    int pesel;
    string imie;
    string nazwisko;
    string data_urodzenia;
    string adres;

    while (inFile >> pesel >> imie >> nazwisko >> data_urodzenia >> adres)
    {
        osoba.pesel = pesel;
        osoba.imie = imie;
        osoba.nazwisko = nazwisko;
        osoba.data_urodzenia = data_urodzenia;
        osoba.adres = adres;
        lista.dodajNaKoncu(osoba);
    }

    Lista<Ksiazka> lista1;
    Ksiazka ksiazka;
    ifstream inFile1("Ksiazki.txt");
    int id;
    string tytul;
    string autor;
    string data_wydania;
    int liczba_stron;
    while (inFile1 >> id >> tytul >> autor >> data_wydania>> liczba_stron)
    {
        ksiazka.id = id;
        ksiazka.tytul = tytul;
        ksiazka.autor = autor;
        ksiazka.data_wydania = data_wydania;
        ksiazka.liczba_stron = liczba_stron;
        lista1.dodajNaKoncu(ksiazka);

    }


    //int peseldod;
    //string imiedod;
    //string nazwiskodod;
    //string data_urodzeniadod;
    //string adresdod;

    //cout << "\tWprowadz pesel: ";
    //cin >> peseldod;
    //if (peseldod < 1000000 || peseldod > 9999999) {
    //    cout << "Nieprawidlowe dane" << endl;
    //}
    //else {
    //    cout << "\tWprowadz imie: ";
    //    getline(cin, imiedod);
    //    cout << "\tWprowadz nazwisko: ";
    //    getline(cin, nazwiskodod);
    //    cout << "\tWprowadz date urodzenia: ";
    //    getline(cin, data_urodzeniadod);
    //    cout << "\tWprowadz adres: ";
    //    getline(cin, adresdod);
    //    Osoby klient(peseldod, imiedod, nazwiskodod, data_urodzeniadod, adresdod);
    //    lista.dodajNaKoncu(klient);
    //}


        /*   lista.dodajNaKoncu(osoba);

      lista.sortujRosnaco(lambda1);
      lista.wyswietl();
      lista.sortujMalejaco(lambda2);

      lista.wyswietl();

      lista.usunElement(434242422, lambda5);
      lista.wyswietl();
      lista.wyswietl();
      Osoby found = lista.znajdz(903231313, lambda5);
      if (found.pesel != 0) {
          std::cout << "Znaleziono element o wartosci " << found << std::endl;
      }
      else {
          std::cout << "Nie znaleziono elementu o podanej wartosci" << std::endl;
      }*/


        int wybor;
        cin >> wybor;
        while (cin.fail())
        {
            cout << "Wprowadziles bledne dane" << endl;

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Wprowadz dane ponownie:";
            cin >> wybor;
        }

        while (wybor != 13)
        {

            switch (wybor)
            {
            case 1:
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                lista.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                menu();
                break;

            case 2:
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                lista1.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                menu();
                break;
            case 3:
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                lista.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Usuwanie klienta po peselu" << std::endl;
                cout << "Prosze podac pesel osoby, ktora chcesz usunac" << std::endl;
                int p;
                cin >> p;
                lista.usunElement(p, lambda5);
                cout << "Pozostali klienci" << std::endl;
                lista.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                menu();
                break;
            case 4:
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                lista1.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Wypozyczanie ksiazki" << std::endl;
                cout << "Prosze podac id ksiazki, ktora chcesz wypozyczyc" << std::endl;
                int o;
                cin >> o;
                found = lista.znajdz(o, lambda5);
                if (found.pesel != 0) {
                    cout << "Podana ksiazka jest juz wypozyczona "  << found << std::endl;
                }
                else {
                    cout << "Ksiazka zostala wypozyczona, oto lista dostepnych ksiazek:" << std::endl;
                    lista1.usunElement(o, lambda6);
                    lista1.wyswietl();
                    cout << "-----------------------------------------------------" << endl;
                }
                menu();
                break;

            case 5:
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                cout << "Znajdz osobe po peselu" << std::endl;
                cout << "Prosze podac pesel osoby, ktora chcesz znalezc" << std::endl;
                cout << "-----------------------------------------------------" << endl;
                lista.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                int l;
                cin >> l;
                found = lista.znajdz(l, lambda5);
                if (found.pesel != 0) {
                    cout << "Znaleziono osobe o podanym peselu " << found << std::endl;
                }
                else {
                    cout << "Nie znaleziono podanej osoby" << std::endl;
                    cout << "-----------------------------------------------------" << endl;
                }
                menu();
                break;
            case 6:
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                cout << "Znajdz ksiazke po id" << std::endl;
                cout << "Prosze podac id ksiazki, ktora chcesz znalezc" << std::endl;
                cout << "-----------------------------------------------------" << endl;
                lista1.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                int up;
                cin >> up;
                found1 = lista1.znajdz1(up, lambda6);
                if (found1.id != 0) {
                    cout << "Znaleziono ksiazke o zadanym id " << found << std::endl;
                }
                else {
                    cout << "Nie znaleziono podanej ksiazki" << std::endl;
                    cout << "-----------------------------------------------------" << endl;
                }
                menu();
                break;
            case 7:
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Lista klientow posortowanych wzgledem peselu" << std::endl;
                lista.sortujRosnaco(lambda1);
                lista.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                menu();
                break;
            case 8:
                system("CLS");
                menu();
                cout << "-----------------------------------------------------" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Lista klientow posortowanych malejaco wzgledem peselu" << std::endl;
                lista.sortujMalejaco(lambda2);
                lista.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                menu();
                break;
            case 9:
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Lista ksiazek posortowanych rosnaco wzgledem liczby stron" << std::endl;
                lista1.sortujRosnaco(lambda3);
                lista1.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                menu();
                break;
            case 10:
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Lista ksiazek posortowanych malejaco liczby stron" << std::endl;
                lista1.sortujRosnaco(lambda4);
                lista1.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                menu();
                break;
            case 11: {
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Dodaj nowego klienta" << std::endl;
                int peseldod;
                string imiedod;
                string nazwiskodod;
                string data_urodzeniadod;
                string adresdod;
                cout << "\tWprowadz pesel: ";
                cin >> peseldod;
                if (peseldod < 1000000 || peseldod > 9999999) {
                    cout << "Nieprawidlowe dane" << endl;
                }
                else {
                    cout << "\tWprowadz imie: ";
                    cin >> imiedod;
                    cout << "\tWprowadz nazwisko: ";
                    cin >> nazwiskodod;
                    cout << "\tWprowadz date urodzenia: ";
                    cin >> data_urodzeniadod;
                    cout << "\tWprowadz adres: ";
                    cin >> adresdod;
                    Osoby klient(peseldod, imiedod, nazwiskodod, data_urodzeniadod, adresdod);
                    lista.dodajNaKoncu(klient);
                }
                lista.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                menu();
                break;
            }
            case 12: {
                system("CLS");
                cout << "-----------------------------------------------------" << endl;
                cout << "Dodaj nowa ksiazke" << std::endl;
                int id_;
                string tytul_;
                string autor_;
                string data_wydania_;
                int liczba_stron_;
                cout << "\tWprowadz id: ";
                cin >> id_;
                if (id_ < 1000000 || id_ > 9999999) {
                    cout << "Nieprawidlowe dane" << endl;
                }
                else {
                    cout << "\tWprowadz tytul: ";
                    getline(cin, tytul_);
                    cout << "\tWprowadz autora: ";
                    getline(cin, autor_);
                    cout << "\tWprowadz date wydania: ";
                    getline(cin, data_wydania_);
                    cout << "\tWprowadz liczbe_stron: ";
                    cin >> liczba_stron_;
                    Ksiazka nowaksiazka(id_, tytul_, autor_, data_wydania_, liczba_stron_);
                    lista1.dodajNaKoncu(nowaksiazka);
                }
                lista1.wyswietl();
                cout << "-----------------------------------------------------" << endl;
                menu();
                break;
            }
            case 13:
                system("CLS");
                menu();
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
        lista.zapis("Osoby.txt");
        lista1.zapis("Ksiazki.txt");
        return 0;


        



    }
