#include <string>
#include <map>

class Checkout
{
public:
    Checkout();
    void addItemPrice(std::string, int);
    void addItem(std::string);
    void addDiscount(std::string, int, int);
    int getTotal();

protected:
    struct Discount
    {
        int num_items;
        int price;
    };

    std::map<std::string, int> prices;
    std::map<std::string, Discount> discounts;
    std::map<std::string, int> items;
};

template<typename T>
T * getFromMap(std::map<std::string, T> * map, std::string item);
