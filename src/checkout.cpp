#include "checkout.h"

Checkout::Checkout() { }

void Checkout::addItemPrice(std::string item, int price)
{
    prices[item] = price;
}

void Checkout::addItem(std::string item)
{
    int * price = getFromMap(&prices, item);

    if (price == NULL)
        throw std::invalid_argument("There's no price for this item.");

    items[item]++;
}

void Checkout::addDiscount(std::string item, int num_items, int discount)
{
    Discount d;
    d.num_items = num_items;
    d.price = discount;

    discounts[item] = d;
}

int Checkout::getTotal()
{
    int total {0};

    for (auto iter = items.begin(); iter != items.end(); iter++)
    {
        std::string item = iter->first;
        int count = iter->second;
        int price = prices[item];

        Discount * discount = getFromMap(&discounts, item);

        if (discount != NULL && count >= discount->num_items)
        {
            int discount_items = count / discount->num_items;
            total += discount_items * discount->price;
            int additional_items = count % discount->num_items;
            total += additional_items * price;
        }
        else
        {
            total += count * price;
        }
    }

    return total;
}

template<typename T>
T * getFromMap(std::map<std::string, T> * map, std::string item)
{
    auto iter = map->find(item);

    if (iter != map->end())
    {
        return &iter->second;
    }
    else
    {
        return NULL;
    }
}