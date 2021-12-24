#include "header.h"

//The purpose of this program is to create a game where the user will be able to create monsters of 4 different kinds. This program supports 4 breeds vampires, zombies, werewolfs, and witches. Each breed has their own original status, the user will be able to apply power ups for each breed. Victory can be achived when the attack and defense of a monster are hight than the other one.


//Output Overloading for class power
ostream& operator << (ostream & cout, const power & source){
  cout<<"\nItem: "<<source.item<<"\nATK: "<<source.atk<<"\nDEF: "<<source.def<<"\n\n";
  return cout;
}

//Assaignment operator
power& power::operator = (const power & source){
  if(this == &source)
    return *this;
  if(item)
    delete [] item;
  item = new char[strlen(source.item)+ 1];
  strcpy(item,source.item);
  atk = source.atk;
  def = source.def;
  return *this;
} 

//ABC
monster::monster(){

}

monster::~monster(){

}

//Constructor
vampire::vampire(){
  type = NULL;
  ability = NULL;
  name = NULL;
}

zombie::zombie(){
  type = NULL;
  ability = NULL;
  name = NULL;
}

werewolf::werewolf(){
  type = NULL;
  ability = NULL;
  name = NULL;
}

witch::witch(){
  type = NULL;
  ability = NULL;
  name = NULL;
}



//Copy constructors
vampire::vampire(const vampire &source){
  if(source.type){
    type = new char[strlen(source.type)+1];
    strcpy(type,source.type);
  }
  if(source.name){
    type = new char[strlen(source.name)+1];
    strcpy(type,source.name);
  }
  if(source.ability){
    type = new char[strlen(source.ability)+1];
    strcpy(type,source.ability);
  }
}

zombie::zombie(const zombie &source){
  if(source.type){
    type = new char[strlen(source.type)+1];
    strcpy(type,source.type);
  }
  if(source.name){
    type = new char[strlen(source.name)+1];
    strcpy(type,source.name);
  }
  if(source.ability){
    type = new char[strlen(source.ability)+1];
    strcpy(type,source.ability);
  }
}

werewolf::werewolf(const werewolf &source){
  if(source.type){
    type = new char[strlen(source.type)+1];
    strcpy(type,source.type);
  }
  if(source.name){
    type = new char[strlen(source.name)+1];
    strcpy(type,source.name);
  }
  if(source.ability){
    type = new char[strlen(source.ability)+1];
    strcpy(type,source.ability);
  }
}

witch::witch(const witch &source){
  if(source.type){
    type = new char[strlen(source.type)+1];
    strcpy(type,source.type);
  }
  if(source.name){
    type = new char[strlen(source.name)+1];
    strcpy(type,source.name);
  }
  if(source.ability){
    type = new char[strlen(source.ability)+1];
    strcpy(type,source.ability);
  }
}


//Setting data passed to the object
vampire::vampire(char * name1){
  type = new char [strlen("Vampire")+1];
  strcpy(type,"Vampire");
  ability = new char [strlen("Speed, flight, and mind control.")+1];
  strcpy(ability,"Speed, flight, and mind control.");
  if(name1){
    name = new char[strlen(name1)+1];
    strcpy(name,name1);
  }
}

zombie::zombie( char * name1){
  type = new char[strlen("Zombie")+1];
  strcpy(type,"Zombie");
  ability = new char[strlen("Enhanced Senses, and Invulnerability.")+ 1];
  strcpy(ability,"Enhanced Senses, and Invulnerability.");
  if(name1){
    name = new char[strlen(name1)+1];
    strcpy(name,name1);
  }
}

werewolf::werewolf(char * name1){
  type = new char[strlen("Werewolf")+1];
  strcpy(type,"Werewolf");
  ability = new char[strlen("Healing, Night Vision, and Speed.")+1];
  strcpy(ability,"Healing, Night Vision, and Speed.");
  if(name1){
    name = new char[strlen(name1)+1];
    strcpy(name,name1);
  }
}

witch::witch(char * name1){
  type = new char[strlen("Witch")+1];
  strcpy(type,"Witch");
  ability = new char[strlen("Magic, and Elemental Control .")+1];
  strcpy(ability,"Magic, and Elemental Control .");
  if(name1){
    name = new char[strlen(name1)+1];
    strcpy(name,name1);
  }
} 


//Destructors
vampire::~vampire(){
  if(type){
    delete [] type;
    type = NULL;
  }
  if(name){
    delete [] name;
    name = NULL;
  }
  if(ability){
    delete [] ability;
    ability = NULL;
  }
}

zombie::~zombie(){
  if(type){
    delete [] type;
    type = NULL;
  }
  if(name){
    delete [] name;
    name = NULL;
  }
  if(ability){
    delete [] ability;
    ability = NULL;
  }
}

werewolf::~werewolf(){
  if(type){
    delete [] type;
    type = NULL;
  }
  if(name){
    delete [] name;
    name = NULL;
  }
  if(ability){
    delete [] ability;
    ability = NULL;
  }
}

witch::~witch(){
  if(type){
    delete [] type;
    type = NULL;
  }
  if(name){
    delete [] name;
    name = NULL;
  }
  if(ability){
    delete [] ability;
    ability = NULL;
  }
}


//Getting name
char * vampire::return_data(){
  return name;
}

char * zombie::return_data(){
  return name;
}

char * werewolf::return_data(){
  return name;
}

char * witch::return_data(){
  return name;
}

//Getting the breed type
char * vampire::return_type(){
  return type;
}

char * zombie::return_type(){
  return type;
}

char * werewolf::return_type(){
  return type;
}

char * witch::return_type(){
  return type;
}

//Display functions
int monster::display(){
  return 1;
}

int vampire::display(){
  cout<<"\nType: "<<type<<"\nName: "<<name<<"\nability: "<<ability<<"\n\n";
  return 1;
}

int zombie::display(){
  cout<<"\nType: "<<type<<"\nName: "<<name<<"\nability: "<<ability<<"\n\n";
  return 1;
}

int werewolf::display(){
  cout<<"\nType: "<<type<<"\nName: "<<name<<"\nability: "<<ability<<"\n\n";
  return 1;
}

int witch::display(){
  cout<<"\nType: "<<type<<"\nName: "<<name<<"\nability: "<<ability<<"\n\n";
  return 1;
}




//Power functions

//Constructor
power::power():def(0),atk(0),item(NULL){
}

//Copy constructor
power::power(const power &source){
  def = source.def;
  atk = source.atk;
  if(source.item){
    item = new char[strlen(source.item)+1];
    strcpy(item,source.item);
  }
}

//Setting data to the class object
power::power(int def1,int atk1,char * item1){
  atk = atk1;
  def = def1;
  if(item1){
    item = new char [strlen(item1)+1];
    strcpy(item,item1);
  }
}

//Returning total of atk and def
int power::calc(){
  int a = atk+def;
  return a;
}

//Returning item
char * power::return_item(){
  return item;
}

//Displaying items
int power::display_items(){
  int num;
  cout<<"\n         ITEMS\n"<<"(1) Stormbringer. \n(2) Hylian Shield. \n(3) Proton Packs. \n";
  cout<<"What items do you want to equip: ";
  cin>>num;
  cin.ignore(100,'\n');
  return num;
}

//Destructor
power::~power(){
  if(item){
    delete [] item;
    item = NULL;
  }
}
