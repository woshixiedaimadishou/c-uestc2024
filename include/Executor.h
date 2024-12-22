#pragma once
#include<map>
#include<string>




class Point {
	friend bool operator==(const Point& p1, const Point& p2);

public:
	Point operator +(const Point& point) const;
	Point operator =(const Point& point);
	
	Point(int x, int y);
	Point();
	void Show();
private:
	int x;
	int y;
};

class Direction {
public:
	friend bool operator==(const Direction& d1, const Direction& d2);
	//bool operator==(const Direction direction);
	Direction(int Head, char heading) ;
	Direction();
	Direction(char heading);
	
	char direction[4] = {'N','E','S','W'};

	
	void TurnLeft();
	void TurnRight();

	int GetHead();
	char Getheading();

	void Show();
private:
	int Head;
	char heading;
};


class Pose{
	friend	bool operator==(const Pose& p1, const Pose& p2);
public:
	Pose(Point point, Direction direction);
	Pose();
	//bool operator==(Pose& pose);
	Point points[4] = { {0,1},{1,0},{0,-1},{-1,0} };

	void Move();
	void TurnLeft();
	void TurnRight();
	void Back();
	void Show();
	void ShowPoint();
	void ShowDirection();
	const Point GetPoint();
private:
	Point point;
	Direction direction;
};



class Executor {
public:
	Executor(Pose pose);
	Executor();
	void FastCommend();
	void BackCommend();
	void ShowPose();
	void Move();
	void TurnLeft();
	void TurnRight();
	void CommendCarry(std::string str);
	Pose GetPose();
private:
	void CmdGroupSet();
	void MoveCommend();
	void TurnLeftCommend();
	void TurnRightCommend();
	void TurnAroundCommend();
	std::map<std::string, void(Executor::*)()> CmdGroup;


	
protected:
	Pose pose;
	bool isFast;
	bool isBack;
};


class SportyCar :Executor {
public:
	SportyCar(Pose pose);
	SportyCar();
	void CommendCarry(std::string str);
	Pose GetPose();
private:
	void CmdGroupSet();
	void MoveCommend();
	void TurnLeftCommend();
	void TurnRightCommend();
	std::map<std::string, void(SportyCar::*)()> CmdGroup;
};

class Bus :Executor {
public:
	Bus(Pose pose);
	Bus();
	void CommendCarry(std::string str);
	void ShowPose();
	void GetBack();
	Pose GetPose();
private:
	void CmdGroupSet();
	void MoveCommend();
	void TurnLeftCommend();
	void TurnRightCommend();
	std::map<std::string, void(Bus::*)()> CmdGroup;
	Pose back;
};


