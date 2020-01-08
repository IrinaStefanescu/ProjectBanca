#pragma once
#include "ContBancar.h"
#include "ContEconomiiUtils.h"
#include <iostream>

class ContEconomii : public ContBancar{
public:
	ContEconomii(double sold = -1, std::string detinator = "Nespecificat", std::string data = "Nespecificat", float procentajDobanda = -1, std::string dataScadenta = "Nespecificat", tipRataDobanda rataDobanda = tipRataDobanda::NESPECIFICAT) : 
			ContBancar(sold,detinator,data), procentajDobanda(procentajDobanda), dataScadenta(dataScadenta) , rataDobanda(rataDobanda){};
    /*ContEconomii(){
		this->procentajDobanda = 0;
		this->dataScadenta = " ";
	};*/
    ~ContEconomii(){};

    tipRataDobanda getRataDobanda();
	int getTipRata();
    float getProcentajDobanda();
    std::string getDataScadenta();

    void setRataDobanda(tipRataDobanda);
    void setProcentajDobanda(float);
    void setDataScadenta(std::string);
	void setTipRata(int);

    friend std::istream& operator>>(std::istream& in, ContEconomii& cont);
    friend std::ostream& operator<<(std::ostream& out, ContEconomii& cont);

	ContEconomii& operator=(const ContEconomii& ob)
	{
		if (this != &ob)
		{
			this->rataDobanda= ob.rataDobanda;
			this->procentajDobanda = ob.procentajDobanda;
			this->dataScadenta = ob.dataScadenta;
		}
		return *this;
	}

	std::string typeutil(){
        return typeid(this).name();
    }

	void afisare(){
		ContBancar::afisare();
		std::cout << "\n" << *this;
	}
private:
    tipRataDobanda rataDobanda;
	int tip_rata;
    float procentajDobanda;
    std::string dataScadenta;
};

/*template<class T>
void afisare_conturi_dobanda()
{
	for (std::map<ContBancar*, int>::iterator it = conturiBancare.begin(); it != conturiBancare.end(); it++) {
		std::cout << it->second << ". ";
		std::string str = it->first->typeutil();
		if (str.find("ContEconomii") != std::string::npos)
		{
			int tip_rata; std::cout << "Introduceti tipul de rata dorit: " << endl; cin >> tip_rata;
			if (it->first->setTipRata(2) == tip_rata)
		}
	}
}*/