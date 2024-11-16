#include <gtest/gtest.h>
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"
#include <sstream>

TEST(PentagonTest, CenterCalculation) {
    Pentagon pentagon;
    std::stringstream ss("0 0 2 0 3 2 1.5 4 0 2");
    ss >> pentagon;
    
    auto center = pentagon.getCenter();
    EXPECT_NEAR(center.x, 1.3, 0.0001);
    EXPECT_NEAR(center.y, 1.6, 0.0001);
}

TEST(PentagonTest, AreaCalculation) {
    Pentagon pentagon;
    std::stringstream ss("0 0 2 0 3 2 1.5 4 0 2");
    ss >> pentagon;
    
    double area = static_cast<double>(pentagon);
    EXPECT_NEAR(area, 8.0, 0.0001);
}

TEST(PentagonTest, Equality) {
    Pentagon p1, p2;
    std::stringstream ss1("0 0 2 0 3 2 1.5 4 0 2");
    std::stringstream ss2("0 0 2 0 3 2 1.5 4 0 2");
    ss1 >> p1;
    ss2 >> p2;
    
    EXPECT_TRUE(p1 == p2);
}

TEST(HexagonTest, CenterCalculation) {
    Hexagon hexagon;
    std::stringstream ss("0 0 2 0 3 2 2 4 0 4 -1 2");
    ss >> hexagon;
    
    auto center = hexagon.getCenter();
    EXPECT_NEAR(center.x, 1.0, 0.0001);
    EXPECT_NEAR(center.y, 2.0, 0.0001);
}

TEST(HexagonTest, AreaCalculation) {
    Hexagon hexagon;
    std::stringstream ss("0 0 2 0 3 2 2 4 0 4 -1 2");
    ss >> hexagon;
    
    double area = static_cast<double>(hexagon);
    EXPECT_NEAR(area, 12.0, 0.0001);
}

TEST(HexagonTest, Equality) {
    Hexagon h1, h2;
    std::stringstream ss1("0 0 2 0 3 2 2 4 0 4 -1 2");
    std::stringstream ss2("0 0 2 0 3 2 2 4 0 4 -1 2");
    ss1 >> h1;
    ss2 >> h2;
    
    EXPECT_TRUE(h1 == h2);
}

TEST(OctagonTest, CenterCalculation) {
    Octagon octagon;
    std::stringstream ss("0 0 2 0 3 2 3 4 2 6 0 6 -1 4 -1 2");
    ss >> octagon;
    
    auto center = octagon.getCenter();
    EXPECT_NEAR(center.x, 1.0, 0.0001);
    EXPECT_NEAR(center.y, 3.0, 0.0001);
}

TEST(OctagonTest, AreaCalculation) {
    Octagon octagon;
    std::stringstream ss("0 0 2 0 3 2 3 4 2 6 0 6 -1 4 -1 2");
    ss >> octagon;
    
    double area = static_cast<double>(octagon);
    EXPECT_NEAR(area, 20.0, 0.0001);
}

TEST(OctagonTest, Equality) {
    Octagon o1, o2;
    std::stringstream ss1("0 0 2 0 3 2 3 4 2 6 0 6 -1 4 -1 2");
    std::stringstream ss2("0 0 2 0 3 2 3 4 2 6 0 6 -1 4 -1 2");
    ss1 >> o1;
    ss2 >> o2;
    
    EXPECT_TRUE(o1 == o2);
}

TEST(OperationsTest, PentagonCopyAssignment) {
    Pentagon p1;
    std::stringstream ss("0 0 2 0 3 2 1.5 4 0 2");
    ss >> p1;
    
    Pentagon p2;
    p2 = p1;
    EXPECT_TRUE(p1 == p2);
}

TEST(OperationsTest, HexagonMoveAssignment) {
    Hexagon h1;
    std::stringstream ss("0 0 2 0 3 2 2 4 0 4 -1 2");
    ss >> h1;
    
    Hexagon h2;
    h2 = std::move(h1);
    
    Hexagon expected;
    std::stringstream ss2("0 0 2 0 3 2 2 4 0 4 -1 2");
    ss2 >> expected;
    EXPECT_TRUE(h2 == expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}