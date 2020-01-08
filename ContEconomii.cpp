#include "ContEconomii.h"

tipRataDobanda ContEconomii::getRataDobanda(){
    return this->rataDobanda;
}
int ContEconomii::getTipRata() {
	return this->tip_rata;
}
float ContEconomii::getProcentajDobanda(){
    return this->procentajDobanda;
}
std::string ContEconomii::getDataScadenta(){
    return this->dataScadenta;
}

void ContEconomii::setRataDobanda(tipRataDobanda rataDobanda){
    this->rataDobanda = rataDobanda;
}
void ContEconomii::setTipRata(int tip_rata) {
	this->tip_rata = tip_rata;
}
void ContEconomii::setProcentajDobanda(float procentajDobanda){
    this->procentajDobanda = procentajDobanda;
}
void ContEconomii::setDataScadenta(std::string dataScadenta){
    this->dataScadenta = dataScadenta;
}

std::ostream& operator<<(std::ostream& out, ContEconomii& cont){
	out << "rata dobanda : "; int tip;
    switch(static_cast<std::underlying_type<tipRataDobanda>::type>(cont.rataDobanda)){
        case 0:{
            out << "PE 3 LUNI\n";
			cont.setTipRata(0);
            break;
        }
        case 1:{
            out << "PE 6 LUNI\n";
			cont.setTipRata(1);
            break;
        }
        case 2:{
            out << "PE 1 AN\n";
			cont.setTipRata(2);
            break;
        }
        case 3:{
            out << "Nespecificat\n";
            break;
        }
        default:{
            out << "Eroare tip rata dobanda\n";
        }
    }
    out << "procentaj dobanda : " << cont.procentajDobanda << "\ndata scadenta : " << cont.dataScadenta << std::endl;
        return out;
}

std::istream& operator>>(std::istream& in, ContEconomii& cont)
{
	std::cout << "Procentaj Dobanda : "; in >> cont.procentajDobanda;
	std::cout << std::endl;
	std::cout << "Data Scadenta : "; in >> cont.dataScadenta;

	return in;
}