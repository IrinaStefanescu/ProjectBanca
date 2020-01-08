#pragma once
#include <string>
#include <iostream>
#include "Tranzactie.h"
#include "ContEconomiiUtils.h"

class ContBancar{
public:
    double getSold();
    std::string getDetinator();
    std::string getData();

    void setSold(double);
    void setDetinator(std::string);
    void setData(std::string);

    ContBancar(double sold = -1, std::string detinator = "Nespecificat", std::string data = "Nespecificat") : sold(sold), detinator(detinator), data(data){};
    /*ContBancar(){
		this->sold = 0;
		this->detinator = "";
		this->data = "";
	};*/
    ~ContBancar(){};

    friend std::ostream& operator<<(std::ostream& out, ContBancar& cont);
    friend std::istream& operator>>(std::istream& in, ContBancar& cont);

    virtual Tranzactie* depunere(std::string dataDepunere, double suma){
        Tranzactie* tranzactie = new Tranzactie();
        tranzactie->setSoldInitial(this->sold);
        tranzactie->setCredit(suma);
        tranzactie->setDebit(0);
        tranzactie->setData(dataDepunere);
        return tranzactie;
    }

    virtual Tranzactie* retragere(std::string dataRetragere, double suma){
        Tranzactie* tranzactie = new Tranzactie();
        tranzactie->setSoldInitial(this->sold);
        tranzactie->setCredit(0);
        tranzactie->setDebit(suma);
        tranzactie->setData(dataRetragere);
        return tranzactie;
    }

    virtual void afisare() {
        std::cout << *this;
    }

    virtual float getProcentajDobanda() {
        return -1;
    }

    virtual tipRataDobanda getRataDobanda() {
        return tipRataDobanda::NESPECIFICAT;
    }

    virtual std::string typeutil(){
        return typeid(this).name();
    }

    virtual int getNrTranzactiiGratuite(){
		return 0;
	}

	virtual float getProcentajTranzactiiCuPlata(){
		return 0;
	}

	virtual void setNrTranzactiiGratuite(int nrTranzactiiGratuite){
		
	}

	virtual void setProcentajTranzactiiCuPlata(float procentajTranzactiiCuPlata){
		
	}

	ContBancar& operator=(const ContBancar& ob)
	{
		if (this != &ob)
		{
			this->detinator = ob.detinator;
			this->data = ob.data;
			this->sold = ob.sold;
		}
		return *this;
	}

private:
    double sold;
    std::string detinator;
    std::string data;
};

