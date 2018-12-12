/*
 * Compte.cpp
 *
 *  Created on: 10 oct. 2018
 *      Author: 3202883
 */

#include <atomic>

using namespace std;
namespace cmpt {

class Compte{

	// atomic car commutations possibles lors de la modification du solde
	atomic<int> solde;




public:
	//unsigned -> on ne credite pas de valeur negative

	Compte(int sol): solde(sol) {}
	void crediter(unsigned int val){
		solde+=val;
	}

	int getSolde() const{
		return solde;
	}



};


}

