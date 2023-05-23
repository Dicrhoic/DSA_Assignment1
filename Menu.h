/*
 * Board.h
 *
 *  Created on: 10 Apr 2020
 *      Author: Home
 */

#ifndef MENU_H_
#define MENU_H_
#include "Goal.h"

class Menu {
public:


    void menu();
    void askForGoal(priority_queue<Goal>& goals);


};
void Menu::menu(){
	cout << "Data Structure and Algorithms Assignment 1" << endl;
	//cout << "(a) Pass Level " << endl;
	//cout << "(b) Credit Level " << endl;
	cout << "(c) Distinction Level Conjunctive" <<endl;
	cout << "(q) Quit" << endl;
	cout << "Enter which level to run the program...." << endl;
}

void Menu::askForGoal(priority_queue<Goal>& goals){
	int v, r ,c;
	bool done = false;
	char option = ' ';
	do {
		cout << "Input a goal in this format (block, row, column): " << endl;
		do{
			cout << "Block (1-6): ";
			cin >> v;
		} while ( v < 1 || v > 6);

		 do{
			 cout << "Row (0-2)[Bottom-Up]: ";
			 cin >> r;
		} while (r < 0 || r > 2);

		do{
			cout << "Column (0-2)[Left-Right]: ";
			cin >> c;

		 } while (c < 0 || c > 2);
		Goal g;
		g.setGoal(v,r,c);
		cout << "\nGoal (" << v << ", " << r << ", " << c << ") added" << endl;
		goals.push(g);
		cout << "Press g to input more goals; Press s to start search." << endl;
		cin >> option;
		if (option != 's'){
			done = false;
		}
		else {
			done = true;
		}
	}

	while (!done);

}









#endif /* MENU_H_ */
