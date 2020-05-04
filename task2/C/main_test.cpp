#include "main_test.h"

TEST(CHECK, FUNCTION_A)
{
    ASSERT_TRUE(A_checker());
}

TEST(CHECK, FUNCTION_B)
{
    ASSERT_TRUE(B_checker());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
