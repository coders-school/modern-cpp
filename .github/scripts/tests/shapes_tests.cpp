#include <gtest/gtest.h>

#include <memory>
#include <vector>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "addShape.hpp"
#include "fibonacci.hpp"

struct FibonacciTestFixture : ::testing::TestWithParam<std::pair<unsigned, long>> {};

TEST_P(FibonacciTestFixture, shouldCalculateFibonacciSeries) {
    auto [element, result] = GetParam();
    ASSERT_EQ(fibonacci(element), result);
}

INSTANTIATE_TEST_CASE_P(FibonacciTest,
                        FibonacciTestFixture,
                        ::testing::Values(
                            std::pair{1, 1},
                            std::pair{2, 1},
                            std::pair{3, 2},
                            std::pair{4, 3},
                            std::pair{5, 5},
                            std::pair{6, 8},
                            std::pair{15, 610},
                            std::pair{23, 28657}));

template <typename T>
struct SfinaeTestFixture : testing::Test {
    constexpr static auto shapeColor = static_cast<Color>(0);
    std::vector<std::shared_ptr<Shape>> collection;
};

TYPED_TEST_SUITE_P(SfinaeTestFixture);

TYPED_TEST_P(SfinaeTestFixture, shouldAddShapeIfDerivedFromShapeClass) {
    TypeParam shape{this->shapeColor};

    addShape(shape, this->collection);

    ASSERT_EQ(this->collection.size(), 1);
}

REGISTER_TYPED_TEST_SUITE_P(SfinaeTestFixture, shouldAddShapeIfDerivedFromShapeClass);

using ShapesTypes = ::testing::Types<Circle, Square, Rectangle>;
INSTANTIATE_TYPED_TEST_SUITE_P(SfinaeTest, SfinaeTestFixture, ShapesTypes);
