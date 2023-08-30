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

//Main idea of classes. Set up a class that has the base functions. Then Use inheritance so spawn another object with the same fucntions and then you can add more/differnace witht the inheritied object.
//Idea: We have a enemy with base moves. Then we have specific enemys, that we can add more to but with the base inherited
//Also we can put classes into their own seperate file, ie: an .h File.
class enemy{ 
	public:
		void set_health(int numb){
			health = numb;
		}

		void set_name(string input){
			name = input;
		}

		void set_damage(int numb){
			damage = numb;
		}

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
	protected:
		string name = "Basic Type";
		int health = 50;
		int damage = 5;

};



class test_enemy{
	protected:
		int private_health = 100;
		string test = "private string";
};


class special_en : protected test_enemy{

};




//Our  "special" class, inherited the fucntions in the public scope of "enemy".
class special : public enemy{
};


int main(){
	special_en testingA1;

	cout << "\n" << testingA1.test << "\n";

	enemy ENa;

	special ENb;
	ENb.set_name("Mike Wazowski");
	ENb.set_damage(10);
	ENb.set_health(50);



	cout << "\n" << ENb.display_name() << "\n";





	player Playa;
	int option;
	int dam = 0;
	cout << "You enter the dungeon and you encounter an enemy. ";
	cout << "\n" << ENb.display_name() << " has " << ENb.display_health() << " health.";
	
	while (ENa.display_health() > 1){
		cout << "\n" << "1) Attack the enemy.\n2) Run Away.\n";
		cin >> option;
		switch(option){
			case 1:
				dam = Playa.attack();
				ENb.take_damage(dam);
				cout << "\nTotal damage: " << dam << " " << ENb.display_name() << "now has " << ENb.display_health() << "\n";
				Playa.take_damage(ENb.chance_attack());
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