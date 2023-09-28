#include <iostream>
#include <windows.h>
#include "CMakeProject3.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

TEST_CASE("List", "[List]") {
    List body1;
    CHECK(body1.Empty() == 1);
    body1.PushBack(101);
    body1.PushBack(202);
    body1.PushBack(303);
    //REQUIRE(body1.Size() == 555);
    CHECK(body1.Size() == 3);
    SECTION("after cleaning") {
        body1.Clear();
        CHECK(body1.Empty() == 1);
        CHECK(body1.Size() == 0);
    }

}


int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    return Catch::Session().run();  

    return 0;

}


