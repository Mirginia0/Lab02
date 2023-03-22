#include "Item.h"
#include "Invoice.h"

int main()
{
    Invoice inv(7770003699, 123456789);
    inv.addItem(Item("M3 screw  ", 0.37f, 'A', 100));
    inv.addItem(Item("2 mm drill", 2.54f, 'B', 2));

    std::cout << inv;

    std::cin.get();
    return 0;
}
