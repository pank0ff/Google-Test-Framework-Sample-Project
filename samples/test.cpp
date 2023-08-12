#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "sample.h"

using namespace testing;

//! -------------------------------------
//!             UNIT TESTS
//! -------------------------------------

TEST( sampleTest, GetSumUnitTest_Basic )
{
    uint8_t result = getSum( 1, 2 );
    EXPECT_EQ( result, 3 );
}

TEST( sampleTest, GetSumUnitTest_Overflow )
{
    uint8_t result = getSum( UINT8_MAX, 1 );
    EXPECT_EQ( result, UINT8_MAX) ;
}

TEST( sampleTest, GetSumUnitTest_Underflow )
{
    uint8_t result = getSum( 0, -1 );
    EXPECT_EQ( result, 0xFF );
}

TEST( sampleTest, GetSumUnitTest_ZeroInput )
{
    uint8_t result = getSum( 0, 0 );
    EXPECT_EQ(result, 0);
}

TEST( sampleTest, GetSumUnitTest_MaxInput )
{
    uint8_t result = getSum( UINT8_MAX, UINT8_MAX );
    EXPECT_EQ( result, UINT8_MAX );
}
