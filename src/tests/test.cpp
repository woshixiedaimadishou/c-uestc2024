#include "../gtest/gtest.h"
#include "Executor.h"
#include "Executor.cpp"

bool operator==(const Direction &d1, const Direction &d2)
{
	return d1.Head == d2.Head;
}

bool operator==(const Point &p1, const Point &p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

bool operator==(const Pose &p1, const Pose &p2)
{
	return (p1.point == p2.point && p1.direction == p2.direction);
}

TEST(ExecutorTest, MOVECOMMEND)
{
	Executor Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("M");
	Pose pose{{1, 2}, {'N'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(ExecutorTest, TURNLEFTCOMMEND)
{
	Executor Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("L");
	Pose pose{{1, 1}, {'W'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(ExecutorTest, TURNRIGHTCOMMEND)
{
	Executor Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("R");
	Pose pose{{1, 1}, {'E'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(ExecutorTest, FASTCOMMEND)
{
	Executor Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("F");
	Executor.CommendCarry("M");
	Pose pose{{1, 3}, {'N'}};
	EXPECT_EQ(pose, Executor.GetPose());
	Executor.CommendCarry("F");
	Executor.CommendCarry("M");
	Pose pose2{{1, 4}, {'N'}};
	EXPECT_EQ(pose2, Executor.GetPose());
}

TEST(ExecutorTest, BACKCOMMEND)
{
	Executor Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("B");
	Executor.CommendCarry("M");
	Pose pose{{1, 0}, {'N'}};
	EXPECT_EQ(pose, Executor.GetPose());
	Executor.CommendCarry("B");
	Executor.CommendCarry("M");
	Pose pose2{{1, 1}, {'N'}};
	EXPECT_EQ(pose2, Executor.GetPose());
}

TEST(ExecutorTest, TURNARROUNDCOMMEND)
{
	Executor Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("TR");
	Pose pose{{0, 1}, {'S'}};
	EXPECT_EQ(pose, Executor.GetPose());
	Executor.CommendCarry("F");
	Executor.CommendCarry("TR");
	Pose pose2{{1, 0}, {'N'}};
	EXPECT_EQ(pose2, Executor.GetPose());
}

TEST(SportyCarTest, MOVECOMMEND)
{
	SportyCar Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("M");
	Pose pose{{1, 3}, {'N'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(SportyCarTest, TURNLEFTCOMMEND)
{
	SportyCar Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("L");
	Pose pose{{0, 1}, {'W'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(SportyCarTest, TURNRIGHTCOMMEND)
{
	SportyCar Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("R");
	Pose pose{{2, 1}, {'E'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(SportyCarTest, FASTCOMMEND)
{
	SportyCar Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("F");
	Executor.CommendCarry("M");
	Pose pose{{1, 5}, {'N'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(SportyCarTest, BACKCOMMEND)
{
	SportyCar Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("B");
	Executor.CommendCarry("M");
	Pose pose{{1, -1}, {'N'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(BusTest, MOVECOMMEND)
{
	Bus Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("M");
	Pose pose{{1, 2}, {'N'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(BusTest, TURNLEFTCOMMEND)
{
	Bus Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("L");
	Pose pose{{1, 2}, {'W'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(BusTest, TURNRIGHTCOMMEND)
{
	Bus Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("R");
	Pose pose{{1, 2}, {'E'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(BusTest, FASTCOMMEND)
{
	Bus Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("F");
	Executor.CommendCarry("M");
	Pose pose{{1, 3}, {'N'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

TEST(BusTest, BACKCOMMEND)
{
	Bus Executor{{{1, 1}, {'N'}}};
	Executor.CommendCarry("B");
	Executor.CommendCarry("M");
	Pose pose{{1, 0}, {'N'}};
	EXPECT_EQ(pose, Executor.GetPose());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();
}