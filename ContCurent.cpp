#include "ContCurent.h"

std::ostream& operator<<(std::ostream& out, ContCurent& cont){
    out << "Nr. tranzactii gratuite : " << cont.nrTranzactiiGratuite << "\n";
    out << "Procentaj tranzactii cu plata : " << cont.procentajTranzactiiCuPlata << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, ContCurent& cont) {
	std::cout << "Nr tranzactii gratuite : " << "\n";
	in >> cont.nrTranzactiiGratuite;
	std::cout << "\n";
	std::cout << "Procentaj tranzactii cu plata : " << "\n";
	in >> cont.procentajTranzactiiCuPlata;

	return in;
}