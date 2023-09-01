#include <iostream>
#include <ostream>
#include <stdlib.h>
#include "product.cpp"
#include "date.cpp"
#include "menu.cpp"
#include "collection.cpp"

using namespace std;

/*
Author: Cervantes Alatorre Juan José Emiliano
Date: 28/01/2023
Assigment:
*/

int main()
{

    Menu menu;
    Collection collection;
    Product product,tempProduct;

    int selectedOption, productNumber;
    std::string barCode;
    std::string name;
    float wholesale, retail, price;
    int stock;
    int year;
    int month;
    int day;
    Date entryDate;

    do
    {
        menu.showMenu();
        cin>>selectedOption;

        menu.setSelectedOption(selectedOption);
        productNumber=menu.getSelectedOption();

        if(productNumber>=0)
        {

            do
            {

                cout<<"*Entry product barcode"<<endl;
                cin>>barCode;

            }
            while(barCode.lenght()<13);

            tempProduct.setBarCode(barCode);

            cout<<"*Next product's name"<<endl;
            cin>>name;
            tempProduct.setName(name);

            cout<<"*Then product's price"<<endl;
            cin>>price;
            tempProduct.setPrice(price);

            cout<<"*Entry the wholesale"<<endl;
            cin>>wholesale;
            tempProduct.setWholesale(wholesale);

            cout<<"*And retail"<<endl;
            cin>>retail;
            tempProduct.setRetail(retail);

            cout<<"*Type product's year entry:"<<endl;
            cin>>year;
            entryDate.setYear(year);

            cout<<"*Type product's month entry:"<<endl;
            cin>>month;
            entryDate.setMonth(month);

            cout<<"*Type product's day entry:"<<endl;
            cin>>day;
            entryDate.setDay(day);

            tempProduct.setDate(entryDate);

            tempProduct.setStock(1);

            collection.setnewProduct(productNumber, tempProduct);
            cout<<"Product added succesfully"<<endl;
            system("PAUSE");

        }

        if(productNumber==(-2)||productNumber ==(-3) ||productNumber==(-4))
        {

            cout<<"Entry the product's barcode"<<endl;
            cin>>barCode;
            collection.searchInExistenceProduct(barCode,productNumber);
            system("PAUSE");
        }

        system("cls");

    }
    while(productNumber!=-5);

    system("Exit");

}
