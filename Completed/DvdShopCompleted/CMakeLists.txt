cmake_minimum_required(VERSION 3.12)
project(DvdShopCompleted)

set(DVD_SHOP_SOURCES Movie.cpp Movie.h Rental.cpp Rental.h
        ChildrensMovie.cpp ChildrensMovie.h RentalStatement.cpp RentalStatement.h
        NewReleaseMovie.cpp NewReleaseMovie.h RegularMovie.cpp RegularMovie.h)
set(TEST_SOURCES DvdShopTest.cpp MovieTest.cpp RentalTest.cpp)

add_executable(DvdShopCompleted main.cpp ${DVD_SHOP_SOURCES})
add_executable(DvdShopCompletedTest ${DVD_SHOP_SOURCES} ${TEST_SOURCES})
target_link_libraries(DvdShopCompletedTest "Catch2WithMain")