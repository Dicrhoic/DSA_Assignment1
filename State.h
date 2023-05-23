/*
 * Board.h
 *
 *  Created on: 9 Apr 2020
 *      Author: Kevin Vo Le
 */

#ifndef STATE_H
#define STATE_H
#include "Action.h"

class State {
private:
    vector<int> blocks;
public:
	int grid[BOARDSIZE][BOARDSIZE];

    State() {
        for(int r = 0; r < BOARDSIZE; r++){
            for(int c = 0; c < BOARDSIZE; c++){
                grid[r][c] = 0;
            }
        }
    }

    State(const State& s) {
           for(int r = 0; r < BOARDSIZE; r++){
               for(int c = 0; c < BOARDSIZE; c++){
                   grid[r][c] = s.grid[r][c];
               }
           }
       }

    bool operator==(State s) {
        for(int r = 0; r < BOARDSIZE; r++){
            for(int c = 0; c < BOARDSIZE; c++){
                if(grid[r][c] == s.getValue(r,c)){
                    return true;
                }
            }
        }
        return false;
    } 
	void printBoard();
    void generateBlocks();
    void generateIntState();
    void getIntBoard();
    void pushDown();

	void setValue(int row, int column, int value);

	int getTopValue(int column);
	int removeBlockFrom(int column);
	int getValue(int row, int column) const;
	int getRowValue(int column);
	int getColValue(int row);
	int searchValue(int input);
	void findFreeSpaces();
	void getPosition(int value, int& row, int& column);
	int freeSpace(int row);
	int getValue(int row, int column);

	int findBlock(int value);
	int findBlockR(int value);
	int findBlockC(int value);

	bool isUnderneath(int col);
	bool isOnTop(int target);
	bool moveBlock(int source, int destination);
    bool insertBlockTo(int c, int value);
    bool moveBlockAct(Action action);
    bool isColFull(int col);


	bool isEmpty(int column);
	bool isFull(int column);
};

void State::generateBlocks(){
	int zeroCount = 1;
    for (int i = 1; i <= 9; i++) {
        blocks.push_back(i);

		if (zeroCount <= 3) {
            blocks.push_back(0);
        }
        zeroCount++;
    }

    for (int i = 8; i > 0; i--) {
        int num = rand() % i;
        int temp = blocks[i];

        blocks[i] = blocks[num];
        blocks[num] = temp;
    }
}



void State::generateIntState(){
    int bIndex = 0;
    generateBlocks();

    for(int r = 0; r < BOARDSIZE; r++){
        for(int c = 0; c < BOARDSIZE; c++){
            setValue(r, c, blocks[bIndex]);
            bIndex++;
        }
    }
}

void State::getIntBoard(){
    generateIntState();
    cout << "Initial State:" << endl;
    pushDown();
    printBoard();
}

void State::pushDown(){
	stack<int> list;
	for (int i = 0; i < BOARDSIZE; i++){
		for (int j = BOARDSIZE-1; j >= 0; j--){
			if (grid[j][i] != 0){
				int a = grid[j][i];
				list.push(a);
			}
		}
	for (int j = 0; j < BOARDSIZE; j++){
		if(list.empty()){
			grid[j][i] = 0;
		}
		else {
			grid[j][i] = list.top();
			list.pop();
			}
		}
	}
}

void State::printBoard() {

	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			cout << " | " << grid[BOARDSIZE - i - 1][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "  ---  ---  --- " << endl;
}

int State::getValue(int row, int column) const{
	return grid[row][column];
}

void State::setValue(int row, int column, int value){
	grid[row][column] = value;
}

int State::getTopValue(int column){
	for (int r = BOARD_INDEX_MAX; r >=0; r--){
		if(grid[r][column] != 0){
			return grid[r][column];
		}
	}
	return -1;
}

int State::getRowValue(int column){
	for (int r = BOARDSIZE-1; r >= 0; r--){
			if (grid[r][column] != 0){
					return r;
			}
	}
	return -1;
}
int State::getColValue(int row){
	for (int c = BOARDSIZE-1; c >= 0; c--){
		if (grid[row][c] != 0){
			return c;
		}
	}
	return -1;
}
int State::freeSpace(int row){
	for (int c = 0; c < BOARD_INDEX_MAX; c++){
		cout << "value: " << grid[row][c] << endl;
		if(grid[row][c] == 0){
			return c;
		}
	}
	return -1;
}
bool State::moveBlock(int source, int destination){
	int row = getRowValue(source);
	int col = source; //source is column
	int sourceBlock = getValue( getRowValue(source), source);
	
	if (isEmpty(destination)){
		if (insertBlockTo(destination, removeBlockFrom(source)) ){
//			cout << "Value: " << sourceBlock << " was moved from column: " << source
//			<< " to " << destination << endl;
            return true;
        }
	}
	return false;

}

bool State::insertBlockTo(int c, int value){
        for (int r = 0; r <= BOARD_INDEX_MAX; r++) {
            if (getValue(r, c) == 0){
                setValue(r, c, value);

                return true;
            }
        }
        return false;
    }

int State::searchValue(int input){
	for (int r = BOARDSIZE-1; r >= 0; r--){
			if (grid[r][input] != 0){
					return r;
			}
	}
	return -1;
}

int State::removeBlockFrom(int column){
	int value, sV;
	sV = searchValue(column);
	if (sV != -1){
		value = grid[sV][column];
		grid[sV][column] = 0;
		return value;
	}
	return -1;
}


bool State::isEmpty(int column){
	for (int r = BOARDSIZE; r >= 0; r--){
		if(getValue(r, column) == 0){
			//cout <<"Input column for isEmpty: " << column << endl;
			return true;
		}
	}
	return false;
}

bool State::isFull(int column){
	for (int r = 0; r < BOARDSIZE; r++){
		if(getValue(r, column) != 0){
			return true;
		}
	}
	return false;
}

int State::getValue(int row, int column) {
	return grid[row][column];
}

bool State::isOnTop(int target){
	int location;
	for (int  r = BOARD_INDEX_MAX; r >= 0; r--){
		for (int c = 0; c <= BOARD_INDEX_MAX; c++){
			if(getValue(r,c) == target){
				if ( r < 2 && getValue(r+1, c) != 0){
					return false;
				}
				else {
					return true;
				}
			}
		}
	}
	return false;
}

bool State::moveBlockAct(Action action){
    if( isFull(action.getSrc()) && isEmpty(action.getDest()) ){
            if (insertBlockTo(action.getDest(), removeBlockFrom(action.getSrc())) ){
                return true;
            }
        }
        return false;
}

bool State::isUnderneath(int col){
	for (int r = BOARD_INDEX_MAX; r >= 0; r--){
		if (grid[r][col] != 0){
			if(r < 2 && getValue(r+1,col) != 0){
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

int State::findBlock(int value){
	for (int r = BOARD_INDEX_MAX; r >= 0; r--){
		for (int c = 0; c <= BOARD_INDEX_MAX; c++){
			if(grid[r][c] == value){
				return r,c;
			}
		}
	}
	return -1;
}

bool State::isColFull(int col){
	if (getValue(BOARD_INDEX_MAX, col) != 0){
		return true;
	}
	return false;
}

int State::findBlockR(int value){
	for (int r = BOARD_INDEX_MAX; r >= 0; r--){
		for (int c = 0; c <= BOARD_INDEX_MAX; c++){
			if(grid[r][c] == value){
				return r;
			}
		}
	}
	return -1;
}

int State::findBlockC(int value){
	for (int r = BOARD_INDEX_MAX; r >= 0; r--){
		for (int c = 0; c <= BOARD_INDEX_MAX; c++){
			if(grid[r][c] == value){
				return c;
			}
		}
	}
	return -1;
}


#endif /* BOARD_H_ */
