#include <iostream>
#include <windows.h>
#include "CMakeProject3.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include <catch2/matchers/catch_matchers.hpp>

TEST_CASE("List", "[List]") {
    List body1;

    //REQUIRE_FALSE(body1.Empty()!=1);

    SECTION("PushBack - ���������� �������� � ������ � �����") {
        INFO("������� �� ��������");
        body1.PushBack(101);
        REQUIRE(body1.Size() == 1);        
    }

    SECTION("PopFront - ���������� �������� � ������ �������") {
        INFO("������� �� ��������");
        body1.PushFront(404);
        REQUIRE(body1.Size() == 1);
    }

    SECTION("PushFront - �������� �������� ������� ������� �������") {
        INFO("���������� �� �������!");
       // body1.PushBack(101);
        CHECK_THROWS_AS(body1.PopFront(), std::runtime_error);
        
    }

    SECTION("PopBack - �������� �������� ������� ������� � �����") {
        INFO("���������� �� �������!");
        //body1.PushBack(101);
        CHECK_THROWS_AS(body1.PopBack(), std::runtime_error);       
    }

    SECTION("����������� ��������: ���������� 2 ��������� ������� ������, 2 ��������� � ����� ������, �������� 1 �������� ������� ������, �������� 1 �������� � ����� ������, ������� ������,�������� �������� ������� ������� �������,�������� �������� ������� ������� � �����")
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

        SECTION("������� ������") {
            INFO("������ �� ������");
            body1.Clear();
            REQUIRE(body1.Empty() == 1);
            REQUIRE(body1.Size() == 0);
        }
        
       // body1.PushBack(111);       
        CHECK_THROWS_WITH(body1.PopFront(), "list is empty");
        
       // body1.PushBack(111);
       // CHECK_NOTHROW(body1.PopBack());       
        CHECK_THROWS(body1.PopBack());
        
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


