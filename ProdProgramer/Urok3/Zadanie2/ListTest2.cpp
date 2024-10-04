//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>

#include <cstdint>
#include "List_class.h"



//юнит-тест
TEST_CASE("List are computed", "[List]") {
    List testy;
    CHECK_THROWS(testy.PopBack());
    REQUIRE_THROWS_AS(testy.PopFront(),std::runtime_error);

    SECTION("checking the function PushFront") {
        testy.PushFront(1);
        testy.PushFront(2);
        testy.PushFront(3);
        CHECK(testy.PopFront() == 3);
    }

    SECTION("checking the function PushBack") {
        testy.PushBack(4);
        CHECK(testy.PopBack() == 4);
    }
}