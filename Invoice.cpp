#include "Invoice.h"

Invoice::Invoice(unsigned long long int sellerNip, unsigned long long int buyerNip) : x_sellerNip(sellerNip), x_buyerNip(buyerNip)
{
    Invoice::x_totalAmountBeforeTax = 0;
    Invoice::x_totalAmountAfterTax = 0;
}

void Invoice::addItem(Item item)
{
    Invoice::x_boughtItems.emplace_back(item);

    Invoice::x_totalAmountBeforeTax += item.x_totalItemPriceBeforeTax;
    Invoice::x_totalAmountAfterTax += item.x_totalItemPriceAfterTax;
}

std::ostream &operator<<(std::ostream &str, Invoice &invoice)
{
    str <<  "------------------VAT invoice------------------\n"
            "===============================================\n"
            "Seller: " << invoice.x_sellerNip <<
            "            Buyer: 0" << invoice.x_buyerNip <<
            "\n\n                c.j.  VAT   il.    net    total\n";
    for (int i = 0; i < invoice.x_boughtItems.size(); i++)
    {
        str << i + 1 << ". " << invoice.x_boughtItems[i] << "\n";
    }
    str << "\n"
            "------------------------------------ TOTAL ----\n"
            "                                  "
            << invoice.x_totalAmountBeforeTax << " | " << invoice.x_totalAmountAfterTax << "\n";
    return str;
}
