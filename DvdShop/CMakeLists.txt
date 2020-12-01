cmake_minimum_required(VERSION 3.16)
project(DvdShop)

set(CMAKE_CXX_STANDARD 11)

set(DVD_SHOP_SOURCES Movie.cpp Movie.h Customer.cpp Customer.h Rental.cpp Rental.h)
set(TEST_SOURCES catch.hpp DvdShopTest.cpp CustomerTest.cpp MovieTest.cpp RentalTest.cpp)

add_executable(DvdShop main.cpp ${DVD_SHOP_SOURCES})
add_executable(DvdShopTest ${DVD_SHOP_SOURCES} ${TEST_SOURCES})
