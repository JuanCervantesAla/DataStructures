#include "../include/menu.hpp"
#include "../include/collection.hpp"
#include <iostream>

using namespace std;

int stockNumber=0;
int productNumber;
Collection collection;

int Menu::getSelectedOption() const
{

    switch (selectedOption)
    {
    case 1:
        collection.setActualProduct(stockNumber);
        productNumber=collection.getActualProduct();
        stockNumber++;
        return productNumber;
        break;

    case 2:
        return -2;
        break;

    case 3:
        return -3;
        break;
    case 4:
        return -4;
        break;
    case 5:
        return -4;
        break;

    default:
        std::cout<<"Ingreso incorrecto"<<endl;
        return -1;
    }
}


void Menu::setSelectedOption(const int& newSelectedOption)
{
    selectedOption=newSelectedOption;
}


void Menu::showMenu()
{

    std::cout<<"Grocery store-'Mexicans'"<<std::endl;
    std::cout<<"Pick an option\n"<<"1.Add a new product\n2.Add +1 on stock product\n3.Remove -1 on stock product\n4.Show products\n5.Exit\n";

}

