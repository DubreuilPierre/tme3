/*
 * main.cpp
 *
 *  Created on: 10 oct. 2018
 *      Author: 3202883
 */

#include <iostream>
#include <thread>
#include <vector>
#include "Compte.cpp"
#include "Comptelock.cpp"
#include "Banque.cpp"

using namespace std;
using namespace cmpt;
namespace q1q2 {

void work(int id) {
	cout << id << endl;
	this_thread::sleep_for(chrono::milliseconds(::rand() % 1000));
	cout << "finished" << id << endl;
}

void createAndWait(int N) {
	vector<thread> threads;
	threads.reserve(N);
	Banque banque(20, 100)
	for (int i = 0; i < N - 2; i++) {
		threads.emplace_back(thread(transfertJob, std::ref(banque)));

	}

	for(int i = 0; i < 2, i++){
		threads.emplace_back(thread(comptableJob, std::cref(banque), 5))
	}
	for (int i = 0; i < N; ++i) {
		threads[i].join();
	}
}

void comptableJob(const Banque & banque, int nb){
	for(int i = 0; i < nb; i++){
		if( ! banque.comptabiliser()){
			std::cout << "Probleme de compte" << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
}

void transferJob(Banque & banque){
	for( int i = 0 ; i < 10000; i++){
		int debite = rand()%banque.size();
		int credite = rand()%banque.size();
		int val = rand() % 50 + 30;
		banque.transfert(debite, credite, val);
	}
}
void jackpot(Compte &c) {
	for (int i = 0; i < 10000; ++i) {
		c.crediter(1);
	}
}

void losepot(Comptelock &c){
	int debit = 0;
	while( debit * 10 < 1000){
		c.debiter(10);
		++debit;
	}
}
}
int main() {
	::srand(time(nullptr));

	createAndWait(10);
	return 0;
}


