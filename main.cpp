#include <iostream>
#include "GestionareConturi.h"
#include <iostream>
#include <string>
//#include <utils/stringutils.h>
//#include <ctime>

using namespace std;

int main(){

	GestionareConturi Manager;
	int contor;
	while (true)
	{
		std::cout << endl << "Introduceti una din optiunile de mai jos sau 0 pentru a parasi programul: \n";
		std::cout << "1 - adaugare cont Economii" << endl;
		std::cout << "2 - adaugare cont Curent" << endl;
		std::cout << "3 - citire conturi Bancare" << endl;
		std::cout << "4 - depunere suma si calcul sold" << endl;
		std::cout << "5 - retragere suma si calcul sold" << endl;
		std::cout << "6 - afisare detalii conturi" << endl;
		std::cout << "0 - iesire program" << endl;

		try {
			cin >> contor;
			if (cin.fail()) {
				throw - 1;
			}
			else
				throw 0;
		}
		catch (int exception) {
			if (exception != 0) {
				cout << "\nRASPUNS INVALID\n";
			}
		}
		
		switch (contor)
		{
		case 1:
		{
			ContBancar* cont = new ContEconomii();
			Manager.addCont(cont);
			break;
		}
		case 2:
		{
			ContBancar* cont = new ContCurent();
			Manager.addCont(cont);
			break;
		}
		case 3:
		{
			std::cout << "Introduceti numarul de conturi pe care doriti sa le cititi: \n";
			int n; cin >> n;
			Manager.readConturi(n);
			break;
		}
		case 4:
		{
			ContBancar* cont;
			std::cout << "Numele utilizatorului : " << endl; 
			string nume; cin >> nume;
			std::cout << "Suma depusa: " << endl;
			float suma; cin >> suma;
			std::cout << "La data de: " << endl;
			string data; cin >> data;
			cont = Manager.find_cont(nume);
			
			Tranzactie* tranzactie = cont->depunere(data, suma);
			std::cout << "Soldul actualizat dupa depunerea unei sume: " << endl;
			Manager.calculSold(tranzactie);
		}
		case 5:
		{
			ContBancar* cont;
			std::cout << "Numele utilizatorului: " << endl;
			string nume; cin >> nume;
			std::cout << "Suma retrasa: " << endl;
			float suma; cin >> suma;
			std::cout << "La data de: " << endl;
			string data; cin >> data;
			cont = Manager.find_cont(nume);

			Tranzactie* tranzactie = cont->retragere(data, suma);
			std::cout << "Soldul actualizat dupa retragerea unei sume: " << endl;
			Manager.calculSold(tranzactie);
		}
		case 6:
		{
			Manager.printDetaliiConturi();
		}
		default:
			break;
		}

		std::cout << "\nDoriti sa mai efectuati vreo modificare?" << endl;
		int raspuns;
		cin >> raspuns;
		if (raspuns == 0)
			break;
		else
		{
			system("cls");
			continue;
		}
			
	}
   
   /* ContBancar* cont2 = new ContEconomii(100, "detinator", "data", 2, "data scadenta", tipRataDobanda::PE3LUNI);
    ContBancar* cont3 = new ContCurent(100, "detinator", "data", 10, 1);
   // Manager.addCont(cont1);
    Manager.addCont(cont2);
    Manager.addCont(cont3);
    Manager.printDetaliiConturi();
    Tranzactie* tranzactie = cont3->retragere("data", 50);
    Manager.calculSold(tranzactie);
    Manager.printDetaliiConturi();*/

    return 0;
}
