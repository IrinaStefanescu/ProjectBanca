#include "Tranzactie.h"

std::string Tranzactie::getData(){
    return data;
}
double Tranzactie::getSoldInitial(){
    return soldInitial;
}
double Tranzactie::getSoldFinal(){
    return soldFinal;
}
double Tranzactie::getDebit(){
    return debit;
}
double Tranzactie::getCredit(){
    return credit;
}
double Tranzactie::getTaxa(){
    return taxa;
}

void Tranzactie::setData(std::string data){
    this->data = data;
}
void Tranzactie::setSoldInitial(double soldInitial){
    this->soldInitial = soldInitial;
}
void Tranzactie::setSoldFinal(double soldFinal){
    this->soldFinal = soldFinal;
}
void Tranzactie::setDebit(double debit){
    this->debit = debit;
}
void Tranzactie::setCredit(double credit){
    this->credit = credit;
}
void Tranzactie::setTaxa(double taxa){
    this->taxa = taxa;
}