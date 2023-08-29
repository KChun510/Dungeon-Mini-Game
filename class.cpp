#include <iostream>
#include <string>
#include <cstdlib>
#include "time.h"
using namespace std;

class player{
	private:
		string name = "Kyle Chun";
		int health = 100;
		int damage = 10;


	public:
		void heal(){
			cout << "\nYou use your spell and heal 10+ points";
			health += 10;
		}

		int attack(){
			srand(time(0));
			int rand_attack = rand() % damage + 1;
			cout << "Your damage is: " << rand_attack;
			cout << "\nYou attack the creature! ";
			return rand_attack;
		}

		string display_name(){
			return name;
		}
		int display_health(){
			return health;
		}
		void take_damage(int dam){
			cout << "The player took damage: " << dam;
			this->health = this->health - dam;
			cout << "\nYour health is:  " << this ->health << "\n";
		}

};


class enemy{
	private:
		string name = "doodoo head";
		int health = 50;
		int damage = 5;	
	public:
		string display_name(){
			return name;
		}	

		int display_health(){
			return health;
		}
		int display_damage(){
			return damage;
		}
		void take_damage(int dam){
			this->health = this->health - dam;
		}

		int attack(){
			srand(time(0));
			int rand_attack = rand() % damage + 1;
			cout << "Creature damage is: " << rand_attack;
			cout << "\nCreature attacks you! ";
			return rand_attack;
		}

		int chance_attack(){
			srand(time(0));
			int chance = rand() % 2 + 1; 
			if(chance == 2){ //1 out of 2 chance of attack back
				return this->attack();
			}
			else{
				return 0;
			}

		}

};






int main(){
	enemy ENa;
	player Playa;
	int option;
	int dam = 0;
	cout << "You enter the dungeon and you encounter an enemy. ";
	cout << "\n" << ENa.display_name() << " has " << ENa.display_health() << " health.";
	
	while (ENa.display_health() > 1){
		cout << "\n" << "1) Attack the enemy.\n2) Run Away.\n";
		cin >> option;
		switch(option){
			case 1:
				dam = Playa.attack();
				ENa.take_damage(dam);
				cout << "\nTotal damage: " << dam << " " << ENa.display_name() << "now has " << ENa.display_health() << "\n";
				Playa.take_damage(ENa.chance_attack());
				break;
			case 2:
				cout << "\nYou run away!!";
				break;
		}
	}

	cout << "\nYou defeat the enemy!!!";
	cout << "\nYou escape the dungeon!";
	return 0;





};
