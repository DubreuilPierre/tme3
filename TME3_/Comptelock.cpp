/*
 * Comptelock.cpp
 *
 *  Created on: 10 oct. 2018
 *      Author: 3202883
 */
#include <mutex>
using namespace std;
namespace cmpt {
class Comptelock {
	//Q16
	mutable recursive_mutex m;
	int solde;

public:
	//unsigned -> on ne credite pas de valeur negative

	Comptelock(int sol) :
			solde(sol) {
	}

	Comptelock(const Comptelock & other){
		other.m.lock();
		solde = other.solde;
		other.m.unlock();
	}

	Comptelock(const Comptelock & other){
		other.lock();
		solde = other.solde;
		other.unlock();
	}
	void crediter(unsigned int val) {
		 lock_guard<recursive_mutex> lg(m);
		solde += val;
		m.unlock();
	}

	int getSolde() const {
		 lock_guard<recursive_mutex> lg(m);
		int res = solde;
		return res;
	}

	bool debiter(unsigned int val) {
		 lock_guard<recursive_mutex> lg(m);

		//posssible car pas de valeur négative pour solde
		bool go = ((unsigned int)solde >= val);
		if (go) {
			solde -= val;
		}
		return go;
	}

	void lock(){
		m.lock();
	}

	void unlock(){
		m.unlock();
	}



	bool try_lock(){

		return m.try_lock();
	}

};

} /* namespace cmpt_unlock */
