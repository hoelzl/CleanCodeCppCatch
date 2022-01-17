cmake_minimum_required(VERSION 3.16)
project(DvdShop)

set(DVD_SHOP_SOURCES Movie.cpp Movie.h Customer.cpp Customer.h Rental.cpp Rental.h)
set(TEST_SOURCES DvdShopTest.cpp CustomerTest.cpp MovieTest.cpp RentalTest.cpp)

add_executable(DvdShop main.cpp ${DVD_SHOP_SOURCES})

add_executable(DvdShopTest ${DVD_SHOP_SOURCES} ${TEST_SOURCES})
target_link_libraries(DvdShopTest "Catch2WithMain")
