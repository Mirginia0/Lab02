#pragma once

#include <vector>
#include "Item.h"

class Invoice
{
    unsigned long long int x_sellerNip, x_buyerNip;
    std::vector<Item> x_boughtItems;
    float x_totalAmountBeforeTax, x_totalAmountAfterTax;

public:
    Invoice(unsigned long long int sellerNip, unsigned long long int buyerNip);
    void addItem(Item item);
    friend std::ostream &operator<<(std::ostream &str, Invoice &invoice);
};
