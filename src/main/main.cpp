#include<iostream>
#include"Executor.h"
#include<string>


 int main() {
	Executor* ptr = new Executor();
	std::string cmd;
	ptr->CommendCarry("S");
	while (1) {
		std::cin >> cmd;
		ptr->CommendCarry(cmd);
		
		ptr->CommendCarry("S");
		std::cout << std::endl;
	}
	/*
	SportyCar* ptr = new SportyCar();
	std::string cmd;
	ptr->CommendCarry("S");
	while (1) {
		std::cin >> cmd;
		ptr->CommendCarry(cmd);

		ptr->CommendCarry("S");
		std::cout << std::endl;
	}

	Bus* ptr = new Bus();
	std::string cmd;
	ptr->CommendCarry("S");
	while (1) {
		std::cin >> cmd;
		ptr->CommendCarry(cmd);

		ptr->CommendCarry("S");
		std::cout << std::endl;
	}


	*/

}
