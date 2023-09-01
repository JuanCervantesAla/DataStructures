#include "../include/collection.hpp"
#include "../include/product.hpp"
#include <iostream>
#include <iterator>
#include <ostream>


int Collection::getActualProduct() const
{
    return actualProduct;
}

void Collection::setActualProduct(const int& newActualProduct)
{
    actualProduct=newActualProduct;
}

void Collection::setnewProduct(const int& productNumber, Product newProduct)
{

    product[productNumber].setStock(newProduct.getStock());
    product[productNumber].setBarCode(newProduct.getBarCode());
    product[productNumber].setName(newProduct.getName());
    product[productNumber].setPrice(newProduct.getPrice());
    product[productNumber].setWholesale(newProduct.getWholesale());
    product[productNumber].setRetail(newProduct.getRetail());
    product[productNumber].setDate(newProduct.getDate());


}

void Collection::searchInExistenceProduct(const std::string& toCheckBarcode, const int& flag)
{

    int counter=0;
    int addStock;

    while (counter<=500)
    {

        if(toCheckBarcode.compare(product[counter].getBarCode())==0)
        {

            if(flag == -2)
            {

                std::cout<<"********Product found-------"<<std::endl;

                addStock=product[counter].getStock();
                product[counter].setStock(addStock+1);

                std::cout<<"Now product "<<product[counter].getName()<<" has "<<product[counter].getStock()<<" in existence"<<std::endl;

                return;
            }

            if (flag== -3)
            {

                if(product[counter].getStock()>=0)
                {

                    std::cout<<"******Product found+++++++"<<std::endl;

                    addStock=product[counter].getStock();
                    product[counter].setStock(addStock-1);

                    std::cout<<"Now product "<<product[counter].getName()<<" has "<<product[counter].getStock()<<" in existence"<<std::endl;
                    return;

                }

                else
                {

                    std::cout<<"Not susbtracting from product, 0 in existence";
                    std::string hola="ola";

                }


            }

            if(flag==-4)
            {

                std::cout<<"----------------------------------------------------------------------------------------------------------"<<std::endl;
                std::cout<<"|   Barcode   |     Name      |    Price    |     Wholesale    |    Retail    |    Date    |    Stock    |"<<std::endl;
                std::cout<<"|"<<product[counter].getBarCode();
                std::cout<<"|"<<product[counter].getName();
                std::cout<<"          |     "<<product[counter].getPrice();
                std::cout<<"     |"<<product[counter].getWholesale();
                std::cout<<"               |    "<<product[counter].getRetail();
                std::cout<<"    |    "<<product[counter].getDate().getDay()<<"-";
                std::cout<<product[counter].getDate().getMonth()<<"-";
                std::cout<<product[counter].getDate().getDay()<<"|";
                std::cout<<product[counter].getStock()<<"         |"<<std::endl;
                std::cout<<"----------------------------------------------------------------------------------------------------------"<<std::endl;




            }

        }
        counter++;
    }

}

