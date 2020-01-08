#include <string>
#pragma once

class Tranzactie{
public:
    Tranzactie(){
		this->data = " ";
		this->soldInitial = 0;
		this->soldFinal = 0;
		this->credit = 0;
		this->debit = 0;
		this->taxa = 0;
	};
    ~Tranzactie(){};

    std::string getData();
    double getSoldInitial();
    double getSoldFinal();
    double getDebit();
    double getCredit();
    double getTaxa();

    void setData(std::string);
    void setSoldInitial(double);
    void setSoldFinal(double);
    void setDebit(double);
    void setCredit(double);
    void setTaxa(double);

private:
    std::string data;
    double soldInitial;
    double soldFinal;
    double debit;
    double credit;
    double taxa;
};