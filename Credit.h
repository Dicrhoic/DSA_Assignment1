/*
 * Credit.h
 *
 *  Created on: 17 Apr 2020
 *      Author: Kevin Vo Le 19396431
 *
 *      Header file used as proof that the works of Solver
 *      were not copied rather improvements of it's credit state.
 *
 */

#ifndef CREDIT_H_
#define CREDIT_H_
//class credit : public Solver {
//
//	void Solver::searchGoalPass(){
//		vector<State> states;
//		s.getIntBoard();
//		State copy(s);
//		states.push_back(copy);
//
//		vector<int> legalMovesList;
//		findLegalMoves(legalMovesList);
//		int i = legalMovesList.size();
//		s.moveBlock(legalMovesList[i-1], legalMovesList[i-2]);
//		legalMovesList.pop_back();
//		legalMovesList.pop_back();
//		cout << "Next State: " <<endl;
//		s.printBoard();
//
//	}
//
//	void Solver::findLegalMoves(vector<int>& legalMovesList){ //credit level
//		for (int src = 0; src < BOARDSIZE; src++){ //where s = source and d = dest
//	        for (int d = 0; d < BOARDSIZE; d++){
//	            if ( (src != d)  && (s.isEmpty(src)) && (s.isFull(d)) ){ //check if there is a value in source and if there isn't one at dest.
//						a.setAction(src, d);
//						legalMovesList.push_back(src);
//						legalMovesList.push_back(d);
//	                }
//	            }
//	        }
//	}
//
//	void Solver::legalMoves(priority_queue<Action>& actions){
//		Action act;
//		vector<Action> actions_vec;
//		vector<State> states;
//		int act_vect_d, act_vect_s;
//		int heu;
//		for (int src = 0; src < BOARDSIZE; src++){
//	        for (int d = 0; d < BOARDSIZE; d++){
//	            if ( (src != d)  && (s.isEmpty(d)) && (s.isFull(src)) ){
//					a.setAction(src, d);
//					//cout << "Action pushed!" << endl;
//					actions_vec.push_back(a);
//	                }
//	            }
//	        }
//	    for (int i = 0; i < actions_vec.size(); i++) {
//	    	actions.push(actions_vec[i]);
//	    	State copy(s);
//	    	act_vect_s = actions_vec[i].getDest();
//	    	act_vect_d = actions_vec[i].getDest();
//
//	    	copy.moveBlock(act_vect_s, act_vect_d);
//	    	states.push_back(copy);
//	    	//cout << "Value : "<< a.getValue() << endl;
//	    	if (copy.getValue(a.getDRow(), a.getDCol()) == a.getValue()){ //100%
//	    		heu = 100;
//	    	}
//	    	else if (copy.isEmpty(a.getDCol()) && copy.isOnTop(a.getValue()) ){ //the target block is on top and the DCol is empty
//	    		heu = 95;
//	    	}
//
//	    	else if(copy.isEmpty(a.getDCol())){
//	    		heu = 50;
//	    	}
//
//	    	else {
//	    		heu = 5;
//	    	}
//	    	actions_vec[i].setHeuristic(heu);
//	    	actions.push(actions_vec[i]);
//	    }
//	}
//
//
//	bool Solver::searchGoalCredit(){
//		vector<State> states;
//	    vector<State> usedStates;
//		s.getIntBoard();
//		a.setGoal();
//		printTarget();
//
//	    int generatedStates = 0;
//	    goalFound = false;
//
//	    int generateStates = 0;
//	    vector<int> legalMovesList;
//
//	    usedStates.push_back(s); //first state
//
//	    while(generatedStates < MAX_STATES){
//	    	if(s.getValue(a.getDRow(), a.getDCol()) == a.getValue()){
//	    	    cout << "Goal: ";
//	    	    printGoal();
//	    	    cout << " found in " << generatedStates << " steps!" << endl;
//	    	    goalFound = true;
//	    	    return true;
//	    	}
//	    	priority_queue<Action> actions;
//	    	legalMoves(actions);
//
//			if(actions.size() == 0){
//	    	    cout << "No actions available" << endl;
//	    	    return false;
//	    	}
//
//			Action action;
//
//			while(actions.size() > 0){
//			    State copy(s);
//
//			    action = actions.top();
//			    actions.pop();
//
//			    copy.moveBlock(a.getSrc(), a.getDest());
//			    bool repeated = false;
//			    for (int i = 0; i < usedStates.size(); i++){
//			        if(usedStates[i] == copy){
//			        repeated = true;
//			        //cout << "This state has already been generated" << endl;
//
//			        }
//			    }
//
//			    if( repeated == true) {
//			        continue;
//			    } else {
//			    	break;
//			    }
//			}
//
//			    printMovement(action, generatedStates);
//			    s.moveBlockAct(action);
//
//			    usedStates.push_back(s);
//			    s.printBoard();
//
//			    generatedStates++;
//		}
//		if(!goalFound){
//			cout << "Max steps of " << MAX_STATES << " was reached and the goal was not found." << endl;
//			return true;
//		}
//	}
//
//	void Solver::findFreeSpace(){
//		for(int r = 0; r < BOARDSIZE; r++){
//			for (int c = BOARDSIZE-1; c >= 0; c--){ //top down
//				if (s.grid[r][c] == 0){	//free space found
//					avaliableCs.push_back(c);
//				}
//			}
//		}
//	}
//
//
//};
//



#endif /* CREDIT_H_ */
