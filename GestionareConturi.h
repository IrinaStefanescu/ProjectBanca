#pragma once
#include <string>
#include <vector>
#include <typeinfo>
#include <map>
#include "ContBancar.h"
#include "ContEconomii.h"
#include "ContCurent.h"

class GestionareConturi{
public:
    GestionareConturi(std::vector<ContBancar*> conturi){
        int index = 1;
        for(auto& cont : conturi){
            this->conturiBancare.insert(std::pair<ContBancar*, int>(cont, index));
            index += 1;
        }
        this->index = index - 1;
    }
    GestionareConturi(){
        this->index = 0;
    }
    ~GestionareConturi(){}

    void addCont(ContBancar* cont){
        this->index += 1;
		std::cin >> *cont;
        this->conturiBancare.insert(std::pair<ContBancar*, int>(cont, index));      
    }


    void printDetaliiConturi(){
        for(std::map<ContBancar*, int>::iterator it = conturiBancare.begin(); it != conturiBancare.end(); it++){
			std::cout << it->second << ". ";
			std::string str = it->first->typeutil();
			if (str.find("ContBancar") != std::string::npos)
				std::cout << "Cont Bancar\n";

			else
				if (str.find("ContEconomii") != std::string::npos)
					std::cout << "Cont Economii\n";
				else
					std::cout << "Cont Curent\n";
			it->first->afisare();
			std::cout << "\n\n";
        }
    }

	ContBancar* find_cont(string nume)
	{
		for (std::map<ContBancar*, int>::iterator it = conturiBancare.begin(); it != conturiBancare.end(); it++) {
			if (it->first->getDetinator().compare(nume) == 0)
				return it->first;
		}
		return nullptr;
	}

    void calculSold(Tranzactie* tranzactie){
        for(std::map<ContBancar*, int>::iterator it = conturiBancare.begin(); it != conturiBancare.end(); it++){
            std::string str = it->first->typeutil();
            if(str.find("ContEconomii") != std::string::npos){
                std::string tr = typeid(tranzactie).name();
                if(tranzactie->getDebit() > 0){
                    //std::cout << "\n\nNu se pot efectua retrageri din contul de economii.\n\n";
                }
                else
                {
                    int rataDobanda = 1;
                    switch(static_cast<std::underlying_type<tipRataDobanda>::type>(it->first->getRataDobanda())){
                        case 0:{
                            //PE 3 LUNI
                            rataDobanda = 3;
                            break;
                        }
                        case 1:{
                            //PE 6 LUNI
                            rataDobanda = 6;
                            break;
                        }
                        case 2:{
                            //PE 1 AN
                            rataDobanda = 12;
                            break;
                        }
                        case 3:{
                            //Nespecificat
                            rataDobanda = 1;
                            break;
                        }
                        default:{
                            std::cout << "Eroare tip rata dobanda\n";
                        }
                    }
                    //Formula : !!!
                    /*std::cout << "\nDETALII TRANZACTIE : sold initial = " << tranzactie->getSoldInitial() << " credit = " << tranzactie->getCredit() << 
                            " procentaj dobanda = " << it->first->getProcentajDobanda() << " rata dobanda = " << rataDobanda << "\n\n"; */
                    tranzactie->setSoldFinal(tranzactie->getSoldInitial() + tranzactie->getCredit() + 
                                                (tranzactie->getCredit() * it->first->getProcentajDobanda() * rataDobanda / 12.0) );
                    it->first->setSold(tranzactie->getSoldFinal());
                }
            }
            else
                if(str.find("ContCurent") != std::string::npos){
                    std::string tr = typeid(tranzactie).name();
                     if(tranzactie->getDebit() > 0){
                        tranzactie->setTaxa(0);
                        tranzactie->setSoldFinal(tranzactie->getSoldInitial() - tranzactie->getDebit());
                        it->first->setNrTranzactiiGratuite(it->first->getNrTranzactiiGratuite() - 1);
                        if(it->first->getNrTranzactiiGratuite() <= 0){
                            tranzactie->setTaxa(it->first->getProcentajTranzactiiCuPlata() * tranzactie->getDebit());
                            tranzactie->setSoldFinal(tranzactie->getSoldFinal() - tranzactie->getTaxa());
                        }
                        it->first->setSold(tranzactie->getSoldFinal());
                     }
                     else{
                        tranzactie->setTaxa(0);
                        tranzactie->setSoldFinal(tranzactie->getSoldInitial() + tranzactie->getCredit());
                        it->first->setSold(tranzactie->getSoldFinal());
                     }
                }
                     
        }
    }

    void readConturi(int n){
        for(int i = 0; i < n; i++)
            {
                double sold; std::string detinator, data;
                std::cout << "Detinator : "; std::cin >> detinator;
                std::cout << std::endl;
                std::cout << "Sold : "; std::cin >> sold;
                std::cout << std::endl;
                std::cout << "Data : "; std::cin >> data;
                std::cout << std::endl;
                ContBancar* cont = new ContBancar(sold, detinator, data);
                addCont(cont);
            }
    }

	GestionareConturi& operator+=(const GestionareConturi& op)
	{
		this->index = this->index + op.index;

		return *this;
	}

private:
    int index;
    std::map <ContBancar*, int> conturiBancare;
};
