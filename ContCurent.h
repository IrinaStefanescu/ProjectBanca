#pragma once
#include "ContBancar.h"

class ContCurent : public ContBancar{
public:

    friend std::istream& operator>>(std::istream& in, ContCurent& cont); 
	friend std::ostream& operator<<(std::ostream& out, ContCurent& cont);

	ContCurent(double sold = -1, std::string detinator = "Nespecificat", std::string data = "Nespecificat", int nrTranzactiiGratuite = 10, float procentajTranzactiiCuPlata = 1) :
					ContBancar(sold, detinator, data), nrTranzactiiGratuite(nrTranzactiiGratuite), procentajTranzactiiCuPlata(procentajTranzactiiCuPlata) {};
	~ContCurent(){}
	/*ContCurent(){
		this->nrTranzactiiGratuite = 10;
		this->procentajTranzactiiCuPlata = 1;
	}*/

	ContCurent& operator=(const ContCurent& ob)
	{
		if (this != &ob)
		{
			this->nrTranzactiiGratuite = ob.nrTranzactiiGratuite;
			this->procentajTranzactiiCuPlata = ob.procentajTranzactiiCuPlata;
		}
		return *this;
	}

	void afisare(){
		ContBancar::afisare();
		std::cout << std::endl;
		std::cout << *this;
	}

	std::string typeutil(){
        return typeid(this).name();
    }

	int getNrTranzactiiGratuite(){
		return this->nrTranzactiiGratuite;
	}

	float getProcentajTranzactiiCuPlata(){
		return this->procentajTranzactiiCuPlata;
	}

	void setNrTranzactiiGratuite(int nrTranzactiiGratuite){
		this->nrTranzactiiGratuite = nrTranzactiiGratuite;
	}

	void setProcentajTranzactiiCuPlata(float procentajTranzactiiCuPlata){
		this->nrTranzactiiGratuite = procentajTranzactiiCuPlata;
	}

private:
	int nrTranzactiiGratuite;
	float procentajTranzactiiCuPlata;
};