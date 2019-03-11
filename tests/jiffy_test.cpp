#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <nitro/jiffy/jiffy.hpp>

#include <chrono>

extern "C"
{
#include <stdlib.h>
}

TEST_CASE("Print 100 jiffies in iso format", "[jiffy]")
{
    for (int i = 0; i < 100; i++)
    {
        nitro::jiffy::Jiffy j;

        std::cout << j << std::endl;
    }
}

TEST_CASE("Jiffy can be taken", "[jiffy]")
{
    SECTION("Default constructed")
    {
        nitro::jiffy::Jiffy now;
    }

    SECTION("Chrono constructed")
    {
        nitro::jiffy::Jiffy now(std::chrono::system_clock::now());
    }
}

TEST_CASE("Jiffy can handle fractions", "[jiffy]")
{
    std::chrono::system_clock::time_point ctp(std::chrono::microseconds(1542297437305463));

    SECTION("can print fractions")
    {
        nitro::jiffy::Jiffy tp(ctp);

        REQUIRE(tp.format("%f") == "305463");
    }

    SECTION("can print iso format with fractions")
    {
        nitro::jiffy::Jiffy tp(ctp);

        REQUIRE(tp.isoformat().substr(20, 6) == "305463");
    }

    // TODO Implement parsing %f
    // SECTION("can parse fractions")
    // {
    //     nitro::jiffy::Jiffy tp;
    //
    //     REQUIRE_NOTHROW(tp = nitro::jiffy::Jiffy("2018-11-15T16:57:17.305463+0100"));
    //
    //     REQUIRE(nitro::jiffy::Jiffy(ctp) == tp);
    // }
}

TEST_CASE("Jiffy are comparable", "[jiffy]")
{
    nitro::jiffy::Jiffy now;

    REQUIRE(now == now);
}

// TEST_CASE("Jiffy time_point is in UTC")
// {
//     REQUIRE(
//         nitro::jiffy::Jiffy("1970-01-01T00:00:00+0000").time_point().time_since_epoch().count()
//         == 0);
// }
//
// TEST_CASE("Jiffy can be parsed without a fraction", "[jiffy]")
// {
//     std::chrono::system_clock::time_point ctp(std::chrono::microseconds(1542297437000000));
//
//     nitro::jiffy::Jiffy tp(ctp);
//
//     REQUIRE(nitro::jiffy::Jiffy("2018-11-15T15:57:17+0000") == tp);
//     REQUIRE(nitro::jiffy::Jiffy("2018-11-15T19:27:17+0330") == tp);
//
//     // force UTC as timezone
//     // This must be the last test!
//     setenv("TZ", "", true);
//     REQUIRE(tp.isoformat() == "2018-11-15T15:57:17.000000+0000");
// }
