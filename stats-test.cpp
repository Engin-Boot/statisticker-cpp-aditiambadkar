#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include<math.h>

#include <cmath>

TEST_CASE("reports average, minimum and maximum of array with all non-NAN elements") {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average, maximum and minimum is NaN for empty array") {
    auto computedStats = Statistics::ComputeStatistics({});
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    //Design the REQUIRE statement here.
    //Use http://www.cplusplus.com/reference/cmath/isnan/
    REQUIRE(isnan(computedStats.average) == true);
    REQUIRE(isnan(computedStats.max) == true);
    REQUIRE(isnan(computedStats.min) == true);
}

TEST_CASE("reports average, minimum and maximum of array with atleast one NAN element but not all NAN elements") {
    //auto computedStats = Statistics::ComputeStatistics({1.5, 2.5, NAN, 3.6, 2.4, NAN});
    auto computedStats = Statistics::ComputeStatistics({NAN, NAN, NAN, 1.6, NAN});
    //Returns average, max and min of non-NAN elements
    float epsilon = 0.001;
    /*REQUIRE(std::abs(computedStats.average - 2.5) < epsilon);
    REQUIRE(std::abs(computedStats.max - 3.6) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);*/
    REQUIRE(std::abs(computedStats.average - 1.6) < epsilon);
    REQUIRE(std::abs(computedStats.max - 1.6) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.6) < epsilon);
}

TEST_CASE("average, maximum and minimum is NAN for array with all NAN elements") {
    auto computedStats = Statistics::ComputeStatistics({NAN, NAN, NAN, NAN});
    REQUIRE(isnan(computedStats.average) == true);
    REQUIRE(isnan(computedStats.max) == true);
    REQUIRE(isnan(computedStats.min) == true);
}
