#include "gtest/gtest.h"
#include "checkout.h"

TEST(checkout, shouldCalculateTotal)
{
    Checkout checkout;

    checkout.addItemPrice("a", 1);
    checkout.addItem("a");
    int total = checkout.getTotal();
    ASSERT_EQ(total, 1);
}

TEST(checkout, shouldCalculateTotalForMultipleItems)
{
    Checkout checkout;

    checkout.addItemPrice("a", 1);
    checkout.addItemPrice("b", 2);
    checkout.addItem("a");
    checkout.addItem("b");
    int total = checkout.getTotal();
    ASSERT_EQ(total, 3);
}

TEST(checkout, shouldCalculateTotalWithDiscount)
{
    Checkout checkout;

    checkout.addItemPrice("a", 1);
    checkout.addDiscount("a", 3, 2);
    checkout.addItem("a");
    checkout.addItem("a");
    checkout.addItem("a");
    int total = checkout.getTotal();
    ASSERT_EQ(total, 2);
}

TEST(checkout, shouldThrowExceptionForItemWithoutPrice)
{
    Checkout checkout;

    ASSERT_THROW(checkout.addItem("a"), std::invalid_argument);
}