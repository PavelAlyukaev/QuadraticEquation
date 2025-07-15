#include "gtest/gtest.h"
#include "Solver.h"
#include <algorithm>
#include <stdexcept>

TEST(lib, NoSolution) {
    auto r = Solve(1, 0, 1);
    ASSERT_TRUE(r.empty());
}

TEST(lib, TwoRoots) {
    auto r = Solve(1, 0, -1);
    ASSERT_TRUE(r.size() == 2);
    ASSERT_TRUE(r[0] == 1 || r[1] == 1);
    ASSERT_TRUE(r[1] == -1 || r[0] == -1);
}

TEST(lib, OneRoot) {
    auto r = Solve(1, 2, 1);
    ASSERT_TRUE(r.size() == 1);
    ASSERT_TRUE(r[0] == -1);
}

TEST(lib, ZeroCoefficient) {
    ASSERT_THROW(Solve(0, 2, 1), std::invalid_argument);
}


TEST(lib, InvalidInput) {
    const double nan = std::numeric_limits<double>::quiet_NaN();
    const double inf = std::numeric_limits<double>::infinity();

    EXPECT_THROW(Solve(nan, 1.0, 1.0), std::invalid_argument);
    EXPECT_THROW(Solve(1.0, nan, 1.0), std::invalid_argument);
    EXPECT_THROW(Solve(1.0, 1.0, nan), std::invalid_argument);

    EXPECT_THROW(Solve(inf, 1.0, 1.0), std::invalid_argument);
    EXPECT_THROW(Solve(-inf, 1.0, 1.0), std::invalid_argument);
    EXPECT_THROW(Solve(1.0, inf, 1.0), std::invalid_argument);
    EXPECT_THROW(Solve(1.0, -inf, 1.0), std::invalid_argument);
    EXPECT_THROW(Solve(1.0, 1.0, inf), std::invalid_argument);
    EXPECT_THROW(Solve(1.0, 1.0, -inf), std::invalid_argument);

    EXPECT_THROW(Solve(inf, nan, 1.0), std::invalid_argument);

}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}