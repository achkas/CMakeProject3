#include <iostream>
#include <windows.h>
#include "CMakeProject3.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

TEST_CASE("List", "[List]") {
    List body1;

    SECTION("PushBack - добавление элемента в список с конца") {
        INFO("элемент не добавлен");
        body1.PushBack(101);
        REQUIRE(body1.Size() == 1);        
    }

    SECTION("PopFront - добавление элемента в список сначала") {
        INFO("элемент не добавлен");
        body1.PushFront(404);
        REQUIRE(body1.Size() == 1);
    }

    SECTION("PushFront - удаление элемента пустого списока сначала") {
        INFO("Вызвано исключение");
        REQUIRE(body1.PopFront());
    }

    SECTION("PopBack - удаление элемента пустого списока с конца") {
        INFO("Вызвано исключение");
        REQUIRE(body1.PopBack());
    }

    SECTION("Комплексная проверка: добавление 2 элементов сначала списка, 2 элементов с конца списка, удаление 1 элемента сначала списка, удаление 1 элемента с конца списка, очистка списка,удаление элемента пустого списока сначала,удаление элемента пустого списока с конца")
    {

        REQUIRE(body1.Empty() == 1);

        body1.PushFront(404);
        body1.PushFront(444);
        CHECK(body1.Size() == 2);
        REQUIRE(body1.Size() <= 2);

        body1.PushBack(101);
        body1.PushBack(111);
        CHECK(body1.Size() == 4);
        REQUIRE(body1.Size() <= 4);

        CHECK(body1.PopFront());
        CHECK(body1.Size() == 3);
        REQUIRE(body1.Size() >= 3);

        CHECK(body1.PopBack());
        CHECK(body1.Size() == 2);
        REQUIRE(body1.Size() >= 2);

        //CHECK(body1.Size() == 2);




        SECTION("Очистка списка") {
            INFO("список не пустой");
            body1.Clear();
            REQUIRE(body1.Empty() == 1);
            REQUIRE(body1.Size() == 0);
        }

        REQUIRE(body1.Size() == 0);
        CHECK(body1.PopFront());
        
        REQUIRE(body1.Size() == 0);
        CHECK(body1.PopBack());

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


