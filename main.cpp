#include "header.h"

//The purpose of this program is to create a game where the user will be able to create monsters of 4 different kinds. This program supports 4 breeds vampires, zombies, werewolfs, and witches. Each breed has their own original status, the user will be able to apply power ups for each breed. Victory can be achived when the attack and defense of a monster are hight than the other one.

int main() { 
	BST my_bst;// BST class object
  int index; //Index of a breed
  int item_c; //choice of items 
  char item1[20] = ("Stormbringer"); //Set of items for the user to choose from
  char item2[20] = ("Hylian Shield");
  char item3[20] = ("Proton Packs");
  char defult[20] = ("Original"); //Each breed will get one at the beggining
  int atk1; //Attack 
  int def1; //Defense
  ADLL my_ADLL; //ADLL class object
  power my_power; //Power class object
	char type1[50]; //type of breef
	char name1[50]; //Monster name
  char name2[50];
  int monster1; //Total atk and def
  int monster2;
	char ability1[50]; //Abilities of a breed
	int choice = 0; //choice of menu
	int mons; //Choice of breed


  //Setting the breeds intial status
  //Vampire
  my_power = power(100,200,defult);
  my_ADLL.add_power(my_power,0);
  //Zombie
  my_power = power(50,100,defult);
  my_ADLL.add_power(my_power,1);
  //Werewolf
  my_power = power(120,150,defult);
  my_ADLL.add_power(my_power,2);
  //Witch
  my_power = power(50,350,defult);
  my_ADLL.add_power(my_power,3);


	cout<<"\nWelcome! This program will have you enter different types of monsters and add some power-ups for them. You will be able to create three different types of monster Vampires, Zombies, Werewolfs, and witches. Then you can have the monsters fight against each other.\n";
	while(choice != 6){ //MENU
		cout<<"What do you want to do:"<<'\n'<<"(1) Enter a new monster."<<'\n'<<"(2) Add a power-up to a monster type. "<<'\n'<<"(3) Display items equiped for a breed."<<'\n'<<"(4) Start a fight."<<'\n'<<"(5) Display all monsters."<<'\n'<<"(6) Quit and delete all data."<<'\n'<<"Enter a number: ";
		cin>>choice;
		cin.ignore(100,'\n');
		if(choice == 1){
			//Add a new monster to the BST
			cout<<"\n(1)Vampire.\n(2)Zombie.\n(3)Werewolf.\n(4)Witch\nWhat type of monsters to you want to deploy: ";
			cin>>mons;
			cin.ignore(100,'\n');
      //Vampire
			if(mons == 1){
				cout<<"\nEnter the name: ";
				cin.get(name1,50,'\n');
				cin.ignore(100,'\n');
				vampire * my_vampire;
        //Creating a pointer and setting it to the desired object
				my_vampire = new vampire(name1);
				monster * my_monster = my_vampire; //Upcasting
				my_bst.add_monster(my_monster);

			}
      //Zombie
			if(mons == 2){ 
				cout<<"\nEnter the name: "; 
				cin.get(name1,50,'\n'); 
				cin.ignore(100,'\n'); 
				zombie * my_zombie;
				my_zombie = new zombie(name1);
				monster * my_monster = my_zombie;
				my_bst.add_monster(my_monster);
			}
      //Werewolf
			if(mons == 3){
				cout<<"\nEnter the name: ";
				cin.get(name1,50,'\n');
				cin.ignore(100,'\n');
				werewolf * my_werewolf;
				my_werewolf = new werewolf(name1);
				monster * my_monster = my_werewolf;
				my_bst.add_monster(my_monster);
			}
      //Witch
			if(mons == 4){
				cout<<"\nEnter the name: ";
				cin.get(name1,50,'\n');
				cin.ignore(100,'\n');
				witch * my_witch;
				my_witch = new witch(name1);
				monster * my_monster = my_witch;
				my_bst.add_monster(my_monster);
			}
		}
		if(choice == 2){
			//Add new power-ups to the array of doubly linked list
      item_c = my_power.display_items();
    
      //Choice #1 of items
      if(item_c == 1){
        atk1 = 200;
        def1 = 50;
        my_power = power(def1,atk1,item1);
      }
      //Choice #2 of items
      if(item_c == 1){
        atk1 = 30;
        def1 = 150;
        my_power = power(def1,atk1,item2);
      }
      //Choice #3 of items
      if(item_c == 3){
        atk1 = 100;
        def1 = 20;
        my_power = power(def1,atk1,item3);
        }
    
      cout<<"\nWhat breed to want to equip the item for:"<<"\n(1) Vampire.\n(2) Zombie.\n(3) Werewolf.\n(4) Witch.\n"<<"Enter the number: ";
      cin>>index;
      cin.ignore(100,'\n');
      if(index > 0 && index < 5){ //To not access unexisting memory
        my_ADLL.add_power(my_power,index-1);
      }
		}
    //If the user wants to display power-ups for a certain breed
    if(choice == 3){
      cout<<"\nWhat Breed's items do you want displayed: "<<"\n(1) Vampire.\n(2) Zombie.\n(3) Werewolf.\n(4) Witch.\n"<<"Enter the number: ";
      cin>>index;
      cin.ignore(100,'\n');
      if(index > 0 && index < 5){
        my_ADLL.display_power(index-1);
      }
    }
		if(choice == 4){
			//Start a fight between to monsters by name
      //Display all monsters
      if(my_bst.display_monster()){
        cout<<"\nEnter the name of the monster #1: ";
        cin.get(name1,50,'\n');
        cin.ignore(100,'\n');
        char * type2 = new char [20];
        //Getting the monster breed
        strcpy(type2,my_bst.get_monster(name1));
        //Getting the second monster
        cout<<"\nEnter the name of the monster #2: ";
        cin.get(name2,50,'\n');
        cin.ignore(100,'\n');
        char * type3 = new char [20];
        //Getting the second monster breed 
        strcpy(type3,my_bst.get_monster(name2));
        //if same breed
        if(strcmp(type2,type3) == 0){
          cout<<"\nThere are from the same breed. They can't fight each other!\n";
        }

        //get their status
        else{
          //First monster status
          if(strcmp(type2,"Vampire") == 0){
            //Call the ADLL function with index 
            index = 0;
            monster1 = my_ADLL.getting_total(index);
          }
          if(strcmp(type2,"Zombie") == 0){
            index = 1;
            monster1 = my_ADLL.getting_total(index);
          }
          if(strcmp(type2,"Werewolf") == 0){
            index = 2;
            monster1 = my_ADLL.getting_total(index);
          }
          if(strcmp(type2,"Witch") == 0){
            index = 3;
            monster1 = my_ADLL.getting_total(index);
          }

          //Second monster status
          if(strcmp(type3,"Vampire") == 0){
            //Call the ADLL function with index 
            index = 0;
            monster2 = my_ADLL.getting_total(index);
          }
          if(strcmp(type3,"Zombie") == 0){
            index = 1;
            monster2 = my_ADLL.getting_total(index);
          }
          if(strcmp(type3,"Werewolf") == 0){
            index = 2;
            monster2 = my_ADLL.getting_total(index);
          }
          if(strcmp(type3,"Witch") == 0){
            index = 3;
            monster2 = my_ADLL.getting_total(index);
          }
          //If monster1 status is higher than monster2
          if(monster1 > monster2){
            cout<<'\n'<<'{'<<name1<<"} Won the battle!!\n\n";
          }
          if(monster1 < monster2){
            cout<<'\n'<<'{'<<name2<<"} Won the battle!!\n\n";
          }
        }
        
      }
		}
		if(choice == 5){
			//Display BST
			if(!my_bst.display_monster())
				cout<<"\nThere is no data! \n\n";
      my_bst.remove_wrapper();

		}

	}
  //Destroying all data
  my_bst.remove_wrapper();
  my_ADLL.remove_wrapper();
  cout<<"\n\nAll data has been deleted!\n\n";

	return 0;
}
