/*
 * Goal.h
 *
 *  Created on: 14 Apr 2020
 *      Author: Home
 */

#ifndef GOAL_H_
#define GOAL_H_

class Goal {
public:
	int block;
	int row;
	int col;

	bool operator<(const Goal g) const {
	        if(row > g.row || (row == g.row && col > g.col) ||
	        (row == g.row && col == g.col && block > g.block)){
	            return true;
	        }
	        else{
	            return false;
	        }
	    }

	void setGoal(int b, int r, int c);
	void printGoal();


	int getBlock();
	int getRow();
	int getCol();

};




void Goal::setGoal(int b, int r, int c){
	block = b;
	row = r;
	col = c;
}

void Goal::printGoal(){
	 cout << "(" << block <<", " << row << ", " << col << ")" << endl;
}

int Goal::getBlock(){
	return block;
}

int Goal::getRow(){
	return row;
}

int Goal::getCol(){
	return col;
}

#endif /* GOAL_H_ */
