#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

class Item
{
    std::string x_name;
    float x_unitNetPrice;
    char x_VAXtaxType;
    unsigned int x_theAmoundSold;

    float x_totalItemPriceBeforeTax;
    float x_totalItemPriceAfterTax;

public:
    friend class Invoice;

    Item(std::string name, float unitNetPrice, char VAXtaxType, unsigned int theAmoundSold);

    friend std::ostream &operator<<(std::ostream &str, Item &item);
};
