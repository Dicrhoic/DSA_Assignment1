/*
 * main.cpp
 *
 *  Created on: 9 Apr 2020
 *      Author: Kevin Vo Le
 *
 *      I hereby certify that no other part of this submission has been copied from any
		other sources, including the Internet, books or other student’s work except the
		ones I have listed below. No part of the code has been written/produced for me
		by another person or copied from any other source.
		I hold a copy of this assignment that I can produce if the original is lost or
		damaged.
 */



#include <iostream>
#include <stack>
#include <ctime>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
#include <iterator>
#include <queue>

using namespace std;

const int BOARDSIZE = 3;
const int NUMBER_OF_BLOCKS = 6;
int BOARD_INDEX_MAX = 2;
int MAX_STATES = 100;
#include "State.h"
#include "Menu.h"
#include "Solver.h"
//#include "Credit.h"
#include "Goal.h"
#include "Action.h"

char option;

int main(){
	srand((int)time(0));
	Menu m;
	Solver sovl;
	m.menu();
	cin >> option;
//	if (option == 'a'){
//		//sovl.searchGoalPass();
//	}
//	if(option == 'b'){
//		//sovl.searchGoalCredit();
//	}
	if(option == 'c'){
		State s;
		s.getIntBoard();
		priority_queue<Goal> goals;
		m.askForGoal(goals);
		sovl.searchGoalD(s, goals);
	}
	if(option == 'q'){
		return 0;
	}
	return 0;
	//sovl.searchGoalPass();



}


