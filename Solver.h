/*
 * Solver.h
 *
 *  Created on: 9 Apr 2020
 *      Author: Home
 */

#ifndef SOLVER_H_
#define SOLVER_H_
#include "State.h"
#include "Goal.h"


class Solver {
private:
	bool goalFound;
	int val, source, destination;


public:
	//pass -> credit found in Credit.h
//	void searchGoalPass();
//	bool searchGoalCredit();
//	void findFreeSpace();
//	void filterFreeSpaces();
//	void findLegalMoves(vector<int>& legalMovesList);
//	void legalMoves(priority_queue<Action>& actions);

	//distinction
	void legalMovesD(priority_queue<Action>& actions, Goal g,  State state);
	void printTarget();
	void printMovement(Action a, int count, State state);
	void printGoal();
	bool searchGoalD(State state, priority_queue<Goal>& goals);

	Action a;
	vector<int> avaliableCs;



};


void Solver::legalMovesD(priority_queue<Action>& actions, Goal g, State state){
	Action act;
	vector<Action> actions_vec;
	vector<State> states;
	int act_vect_d, act_vect_s;
	int heu;
	for (int s = 0; s < BOARDSIZE; s++){
        for (int d = 0; d < BOARDSIZE; d++){
        	//cout << "First loop working Ignore" << endl;
            if ( (s != d)  && (state.isEmpty(d)) && (state.isFull(s)) ){
				a.setAction(s, d);
				//cout << "Action pushed!" << endl;
				actions_vec.push_back(a);
                }
            }
        }
    for (int i = 0; i < actions_vec.size(); i++) {
    	actions.push(actions_vec[i]);
    	State copy(state);
    	act_vect_s = actions_vec[i].getDest();
    	act_vect_d = actions_vec[i].getDest();

    	copy.moveBlock(act_vect_s, act_vect_d);
    	states.push_back(copy);
    	int col = g.getCol();
    	//cout << "Value : "<< a.getValue() << endl;
    	//cout << "Target column: "<< g.getCol() << endl;
    	if (copy.getValue(g.getRow(), g.getCol()) == g.getBlock()){ //100%
    		heu = 100;
    	}
    	else if (copy.isEmpty(col) && copy.isOnTop(g.getBlock()) ){
    		heu = 99;
    	}
    	else if (copy.isOnTop(g.getCol()) && copy.isOnTop(g.getBlock()) ){ //the target block is on top and the DCol is empty
    		heu = 85;
    	}
    	else if(copy.isOnTop(g.getBlock()) && copy.isUnderneath(g.getCol())){
    		heu = 55;
    	}
    	else if (copy.isOnTop(g.getBlock()) && copy.isColFull(g.getCol())){
    		heu = 45;
    	}
    	else if (copy.isColFull(g.getCol()) && copy.isUnderneath(g.getBlock())){
    		heu = 30;
    	}
    	else if (copy.isColFull(g.getCol()) && copy.isColFull(copy.findBlockC(g.getBlock())) &&
    			copy.isUnderneath(g.getBlock())){
    		heu = 10;
    	}
    	else {
    		heu = 15;
    	}
    	actions_vec[i].setHeuristic(heu);
    	actions.push(actions_vec[i]);
    }
}


void Solver::printMovement(Action a, int count, State state){
	cout << "Step " << count+1 << ": Move block ";
	cout << state.getValue(state.getRowValue(a.getSrc()), a.getSrc() ) << ", from column ";
	cout << a.getSrc() << " to column " << a.getDest();
	cout << " with heuristic value " << a.getHeuristic();
	cout << ". \n";
}

void Solver::printTarget(){
	cout << "We want to move " << a.getValue() << " to row ";
	cout << a.getDRow() << " and column " << a.getDCol() << endl;
}

void Solver::printGoal(){
	cout << "(" << a.getValue() << ", " << a.getDRow() << ", "  << a.getDCol() << ")" << endl;
}

bool Solver::searchGoalD(State state,priority_queue<Goal>& goals){
	vector<State> states;
    vector<State> usedStates;

	//printTarget();

    int generatedStates = 0;
    goalFound = false;

    int generateStates = 0;
    vector<int> legalMovesList;

    usedStates.push_back(state); //first state

    while(generatedStates < MAX_STATES){
    	//cout << goals.size() << endl;
    	if (goals.size() == 0){
    		cout << "All goals have been achieved!" << endl;
    	}
    	while (goals.size() > 0){
    		Goal g = goals.top();
    		if(generatedStates == MAX_STATES){
    			if(!goalFound){
    				cout << "Max steps of " << MAX_STATES << " was reached and the goal";
    				g.printGoal();
    				cout << " was not found." << endl;
    				return true;
    			}
    		}
    		if(generatedStates == 100 && goals.size() > 1){
    			cout << "Goal";
    			g.printGoal();
    			cout << " could not be found, moving to next goal" << endl;
    			goals.pop();
    			generatedStates = 0;
    			continue;
    		}

    		if(state.getValue(g.getRow(), g.getCol()) == g.getBlock()){
    		    cout << "Goal: ";
    		    g.printGoal();
    		    cout << " found in " << generatedStates << " steps!" << endl;
    		    goalFound = true;
    		    return true;
    		}
    		priority_queue<Action> actions;
    		legalMovesD(actions, g, state);

    		if(actions.size() == 0){
    		    cout << "No actions available" << endl;
    		    return false;
    		}

    		Action action;

    		while(actions.size() > 0){
    			State copy(state);

    			action = actions.top();
    			actions.pop();

    		copy.moveBlock(a.getSrc(), a.getDest());
    		bool repeated = false;
    			for (int i = 0; i < usedStates.size(); i++){
    				if(usedStates[i] == copy){
    					repeated = true;
    					//cout << "This state has already been generated" << endl;
    				}
    			}

    			if( repeated == true) {
    	        	continue;
				} else {
    				break;
    	    	}
    		}
    		printMovement(action, generatedStates, state);
    		state.moveBlockAct(action);

    		usedStates.push_back(state);
    		state.printBoard();

    		generatedStates++;
    	}
	}
    return true;
}







#endif /* SOLVER_H_ */
