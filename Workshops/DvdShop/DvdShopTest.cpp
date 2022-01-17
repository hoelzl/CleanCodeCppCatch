#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "Customer.h"

TEST_CASE("video store")
{
    Customer customer{"Fred"};

    SECTION("test single new release statement")
    {
        customer.add_rental({Movie{"The Cell", Movie::new_release}, 3});
        CHECK(
            customer.statement()
            == "Rental Record for Fred\n\tThe Cell\t9.00\nYou owed 9.00\nYou "
               "earned 2 frequent renter points\n");
    }

    SECTION("test dual new release statement")
    {
        customer.add_rental({Movie{"The Cell", Movie::new_release}, 3});
        customer.add_rental({Movie{"The Tiger Movie", Movie::new_release}, 3});
        CHECK(
            customer.statement()
            == "Rental Record for Fred\n\tThe Cell\t9.00\n\tThe Tiger "
               "Movie\t9.00\nYou owed "
               "18.00\nYou earned 4 frequent renter points\n");
    }

    SECTION("test single children's statement")
    {
        customer.add_rental({Movie{"The Tiger Movie", Movie::childrens}, 3});
        CHECK(
            customer.statement()
            == "Rental Record for Fred\n\tThe Tiger Movie\t1.50\nYou owed "
               "1.50\nYou earned 1 frequent renter points\n");
    }

    SECTION("test multiple regular release statement")
    {
        customer.add_rental({Movie{"Plan 9 from Outer Space", Movie::regular}, 1});
        customer.add_rental({Movie{"8 1/2", Movie::regular}, 2});
        customer.add_rental({Movie{"Eraserhead", Movie::regular}, 3});
        CHECK(
            customer.statement()
            == "Rental Record for Fred\n\tPlan 9 from Outer Space\t2.00\n\t8 "
               "1/2\t2.00\n\tEraserhead\t3.50\nYou owed "
               "7.50\nYou earned 3 frequent renter points\n");
    }
}
