#include "Executor.h"
#include <map>
#include <iostream>

Direction::Direction(int Head, char heading)
{
	this->Head = Head;
	this->heading = heading;
}

Direction::Direction()
{
	this->Head = 0;
	this->heading = 'N';
}

Direction::Direction(char heading)
{
	this->heading = heading;
	for (int i = 0; i < 4; i++)
	{
		if (direction[i] == heading)
		{
			this->Head = i;
			break;
		}
	}
}

void Direction::TurnLeft()
{
	Head = (Head + 3) % 4;
	heading = direction[Head];
}

void Direction::TurnRight()
{
	Head = (Head + 1) % 4;
	heading = direction[Head];
}

int Direction::GetHead()
{
	return Head;
}

char Direction::Getheading()
{
	return heading;
}

void Direction::Show()
{
	std::cout << heading;
}

Point Point::operator+(const Point &point) const
{
	return Point(x + point.x, y + point.y);
}

Point Point::operator=(const Point &point)
{
	this->x = point.x;
	this->y = point.y;
	return *this;
}

/*bool Point::operator==(Point& point)
{
	if (x == point.x && y == point.y)
		return true;
	else
		return false;
}*/

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

void Point::Show()
{
	std::cout << x << " " << y << " ";
}

Pose::Pose(Point point, Direction direction)
{
	this->point = point;
	this->direction = direction;
}

Pose::Pose()
{
}

/*bool Pose::operator==(Pose& pose)
{
	if (point == pose.point && direction == pose.direction)
		return true;
	else
		return false;
}*/

void Pose::Move()
{
	this->point = this->point + points[direction.GetHead()];
}

void Pose::TurnLeft()
{
	direction.TurnLeft();
}

void Pose::TurnRight()
{
	direction.TurnRight();
}

void Pose::Back()
{
	this->point = this->point + points[(direction.GetHead() + 2) % 4];
}

void Pose::Show()
{
	point.Show();
	std::cout << " ";
	direction.Show();
}

void Pose::ShowPoint()
{
	point.Show();
}

void Pose::ShowDirection()
{
	direction.Show();
}

const Point Pose::GetPoint()
{
	return point;
}

Executor::Executor(Pose pose)
{
	this->pose = pose;
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

Executor::Executor()
{
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

void Executor::FastCommend()
{
	if (isFast == 0)
		isFast = 1;
	else
		isFast = 0;
}

void Executor::BackCommend()
{
	if (isBack == 0)
		isBack = 1;
	else
		isBack = 0;
}

void Executor::ShowPose()
{
	pose.Show();
}

void Executor::Move()
{
	if (isBack == 0)
		pose.Move();
	else
		pose.Back();
}

void Executor::TurnLeft()
{
	if (isBack == 0)
		pose.TurnLeft();
	else
		pose.TurnRight();
}

void Executor::TurnRight()
{
	if (isBack == 0)
		pose.TurnRight();
	else
		pose.TurnLeft();
}

void Executor::CommendCarry(std::string str)
{
	if (CmdGroup.count(str) == 1)
		(this->*CmdGroup[str])();
}

Pose Executor::GetPose()
{
	return pose;
}

void Executor::CmdGroupSet()
{

	CmdGroup.insert(std::pair<std::string, void (Executor::*)()>("M", &Executor::MoveCommend));
	CmdGroup.insert(std::pair<std::string, void (Executor::*)()>("L", &Executor::TurnLeftCommend));
	CmdGroup.insert(std::pair<std::string, void (Executor::*)()>("R", &Executor::TurnRightCommend));
	CmdGroup.insert(std::pair<std::string, void (Executor::*)()>("TR", &Executor::TurnAroundCommend));
	CmdGroup.insert(std::pair<std::string, void (Executor::*)()>("F", &Executor::FastCommend));
	CmdGroup.insert(std::pair<std::string, void (Executor::*)()>("B", &Executor::BackCommend));
	CmdGroup.insert(std::pair<std::string, void (Executor::*)()>("S", &Executor::ShowPose));
}

void Executor::MoveCommend()
{
	Move();
	if (isFast == 1)
		Move();
}

void Executor::TurnLeftCommend()
{
	if (isFast == 1)
		Move();
	TurnLeft();
}

void Executor::TurnRightCommend()
{
	if (isFast == 1)
		Move();
	TurnRight();
}

void Executor::TurnAroundCommend()
{
	if (isFast == 1)
		Move();
	TurnLeft();
	Move();
	TurnLeft();
}

SportyCar::SportyCar(Pose pose)
{
	this->pose = pose;
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

SportyCar::SportyCar()
{
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

void SportyCar::CommendCarry(std::string str)
{
	if (CmdGroup.count(str) == 1)
		(this->*CmdGroup[str])();
}

Pose SportyCar::GetPose()
{
	return pose;
}

void SportyCar::CmdGroupSet()
{
	CmdGroup.insert(std::pair<std::string, void (SportyCar::*)()>("M", &SportyCar::MoveCommend));
	CmdGroup.insert(std::pair<std::string, void (SportyCar::*)()>("L", &SportyCar::TurnLeftCommend));
	CmdGroup.insert(std::pair<std::string, void (SportyCar::*)()>("R", &SportyCar::TurnRightCommend));
	CmdGroup.insert(std::pair<std::string, void (SportyCar::*)()>("F", &SportyCar::FastCommend));
	CmdGroup.insert(std::pair<std::string, void (SportyCar::*)()>("B", &SportyCar::BackCommend));
	CmdGroup.insert(std::pair<std::string, void (SportyCar::*)()>("S", &SportyCar::ShowPose));
}

void SportyCar::MoveCommend()
{
	Move();
	Move();
	if (isFast == 1)
	{
		Move();
		Move();
	}
}

void SportyCar::TurnLeftCommend()
{
	if (isFast == 1)
		Move();
	TurnLeft();
	Move();
}

void SportyCar::TurnRightCommend()
{
	if (isFast == 1)
		Move();
	TurnRight();
	Move();
}

Bus::Bus(Pose pose)
{
	this->pose = pose;
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

Bus::Bus()
{
	isFast = 0;
	isBack = 0;
	CmdGroupSet();
}

void Bus::CommendCarry(std::string str)
{
	if (CmdGroup.count(str) == 1)
		(this->*CmdGroup[str])();
}

void Bus::ShowPose()
{
	GetBack();
	std::cout << "front:";
	pose.ShowPoint();
	std::cout << " back:";
	back.ShowPoint();
	std::cout << " ";
	pose.ShowDirection();
}

void Bus::GetBack()
{
	Pose temp = pose;
	temp.Back();
	back = temp;
}

Pose Bus::GetPose()
{
	return pose;
}

void Bus::CmdGroupSet()
{
	CmdGroup.insert(std::pair<std::string, void (Bus::*)()>("M", &Bus::MoveCommend));
	CmdGroup.insert(std::pair<std::string, void (Bus::*)()>("L", &Bus::TurnLeftCommend));
	CmdGroup.insert(std::pair<std::string, void (Bus::*)()>("R", &Bus::TurnRightCommend));
	CmdGroup.insert(std::pair<std::string, void (Bus::*)()>("F", &Bus::FastCommend));
	CmdGroup.insert(std::pair<std::string, void (Bus::*)()>("B", &Bus::BackCommend));
	CmdGroup.insert(std::pair<std::string, void (Bus::*)()>("S", &Bus::ShowPose));
}

void Bus::MoveCommend()
{
	if (isFast == 1)
		Move();
	Move();
}

void Bus::TurnLeftCommend()
{
	if (isFast == 1)
		Move();
	Move();
	TurnLeft();
}

void Bus::TurnRightCommend()
{
	if (isFast == 1)
		Move();
	Move();
	TurnRight();
}
