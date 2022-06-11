#pragma once
#include <string>

struct Order {
	std::string PLAT;		//розрахунковий рахунок платника
	std::string POL;			//розрахунковий рахунок одержувача
	long double SUMMA;	//сума, що перераховується в грн.

	std::string data;		//точний час на момент проведення платежу
};
