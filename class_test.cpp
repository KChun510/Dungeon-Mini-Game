#include <iostream>
#include <cstdlib>
#include <string>
#include "time.h"
using namespace std;


class base_player{
public:
	int health = 100;
	int atk = 15;
	
	int attack(){
		srand(time(0));
		int hit_points = rand() % atk + 1; //random attack number from atk to 1.
		return hit_points;		
	}

	void heal(){
		this -> health += 10;

	}
};



class base_enemy{
	public:
		int health = 50;
		int atk = 10;

		void heal(){
			health += 10;
			
		}
		int attack(){
			srand(time(0));
			int hit_points = rand() % atk + 1; //random attack number from atk to 1.
			return hit_points;		
		}


};



class special_enemy : public base_enemy{
	public:
		int get_health(){
			return health;
		}
		int set_health(int numb){
			health = numb;
			return health;
		}
};


class attack_ecounter{
public: 
	int option;
	int damage;
	void intiate(base_player& p1, special_enemy& e1){
		cout << "\nAn enemy pop's out from the shadows. \n";
		while(p1.health > 0 && e1.health > 0 && option != 3 ){
			cout << "Checking the health of e1 on outer loop: " << e1.health;
			cout << "\n1)Attack \n2)Heal \n3)Run\n";
			cout << "Enter your option:  "; cin >> option;
			switch(option){
				case 1:
					damage = p1.attack();
					e1.health -= damage;
					cout << "\nYou attack the creature\n";
					cout << "\nYou do: " << damage << " points of damage.\n";
					cout << "\nThe creature has: " << e1.health << " health points.\n";
					break;
				case 2:
					p1.heal();
					cout << "\nYou healed 10+ HP. You now have: " << p1.health << " HP. \n";
					break;
				case 3:
					option = 3;
					break;
			}
			
		}
	}
};











int main(){
	attack_ecounter ecounter;
	special_enemy e1;
	base_player p1;
	int option;

	while(p1.health > 0){
		cout << "\nYou have: " << p1.health << " health and decide to crawl the dungeon.";
		cout << "\n1) Explore the Cavern \n2) Leave\n";
		cout << "Enter your option: "; cin >> option;
		switch(option){
			case 1:
				cout << "\nYou decide to explore. ";
				srand(time(0));
				if ((rand() % 2 + 1) == 2){ // 1/2 chance of encountering a enemy
					ecounter.intiate(p1, e1);
				}
				else{
					cout << "\nYou walk around the cave and don't find anything.";
				}
		
				break;
			case 2:
				cout << "\nYou decide to leave the cave";
				p1.health = -1;
				break;
		}		
	}
	

}