#include "ContBancar.h"

double ContBancar::getSold(){
    return this->sold;
}

std::string ContBancar::getDetinator(){
    return this->detinator;
}

std::string ContBancar::getData(){
    return this->data;
}

void ContBancar::setSold(double sold){
    this->sold = sold;
}

void ContBancar::setDetinator(std::string detinator){
    this->detinator = detinator;
}

void ContBancar::setData(std::string data){
    this->data = data;
}


std::ostream& operator<<(std::ostream& out, ContBancar& cont){
            out << "detinator : " << cont.getDetinator() << "\nsold : " << cont.getSold() << "\ndata deschidere : " << cont.getData();
            return out;
}

std::istream& operator>>(std::istream& in, ContBancar& cont){
    std::cout << "Detinator : "; in >> cont.detinator;
    std::cout << std::endl;
    std::cout << "Sold : "; in >> cont.sold;
    std::cout << std::endl;
    std::cout << "Data : "; in >> cont.data;
    std::cout << std::endl;
    return in;
}