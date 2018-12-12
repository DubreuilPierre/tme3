/*
 * Banque.cpp
 *
 *  Created on: 10 oct. 2018
 *      Author: 3202883
 */



#include "Comptelock.cpp"
#include <vector>

using namespace std;
namespace cmpt {

class Banque {
	int initial;
	vector<Comptelock> comptes;

public:

	Banque(int nbcomptes, int si){
		initial = si;
		for(int i = 0; i < nbcomptes; i++){
			comptes.emplace_back(si);
		}
	}

	size_t size() const{
		return comptes.size();
	}

	bool transfert(int idD, int idC, int val){
		bool b = false;
		Comptelock & deb = comptes[idD];
		Comptelock & cred = comptes[idC];
		lock(deb,cred);
		if(deb.debiter(val)){
			cred.crediter(val);
			b = true;
		}
		return b;
	}

	bool comptabiliser() const{
		lock_guard<mutex> l(m);
		int total = initial * comptes.size();
		int somme = 0;
		for(const auto & compte : comptes){
			somme += compte.getSolde();
		}

		if(somme != total){
			cout << "Le compte est faux" << endl;
		}

		return total == somme;
	}

};
} /* namespace cmpt_unlock */
