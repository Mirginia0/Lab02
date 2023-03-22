#include "Item.h"

Item::Item(std::string name, float unitNetPrice, char VAXtaxType, unsigned int theAmoundSold) : x_name(name), x_unitNetPrice(unitNetPrice), x_VAXtaxType(VAXtaxType), x_theAmoundSold(theAmoundSold)
{
    x_totalItemPriceBeforeTax = unitNetPrice * static_cast<float>(theAmoundSold);

    float vat;
    switch(VAXtaxType)
    {
        case 'A': vat = 0.23f; break;
        case 'B': vat = 0.08f; break;
        case 'C': vat = 0.f; break;
    }

    x_totalItemPriceAfterTax = x_totalItemPriceBeforeTax + (x_totalItemPriceBeforeTax * vat);
}

std::ostream &operator<<(std::ostream &str, Item &item)
{
    return str << std::fixed << std::showpoint << std::setprecision(2) <<
    item.x_name << " | "  <<
    item.x_unitNetPrice << "   " <<
    item.x_VAXtaxType << " | " <<
    item.x_theAmoundSold << "  | " <<
    item.x_totalItemPriceBeforeTax << " | " <<
    item.x_totalItemPriceAfterTax;
}
