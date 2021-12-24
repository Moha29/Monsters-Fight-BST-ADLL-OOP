#include "header.h"

//The purpose of this program is to create a game where the user will be able to create monsters of 4 different kinds. This program supports 4 breeds vampires, zombies, werewolfs, and witches. Each breed has their own original status, the user will be able to apply power ups for each breed. Victory can be achived when the attack and defense of a monster are hight than the other one.

//Constructor
ADLL::ADLL(){
  head = new p_node * [SIZE];
  head [0] = NULL;
  head [1] = NULL;
  head [2] = NULL;
  head [3] = NULL;
  head [4] = NULL;
}

//ADD Wrapper
int ADLL::add_power(power & source, int index){
  if(!head[index]){ //If list is empty
    head[index] = new p_node(source);
    head[index] -> set_next(NULL);
    head[index] -> set_prev(NULL);
    return 1;
  }
  //To connect nodes with a previous pointer
  p_node * temp = head[index];
  return add(source,head[index],temp);
}

//ADD recursive function
int ADLL::add(power & source,p_node *& head,p_node *& temp){

//Base case
  if(!head){
    head = new p_node(source);
    head -> set_next(NULL);
    head -> set_prev(temp);
    return 1;
  }
  //Setting temp the previous node
  temp = head;
  return add(source,head->get_next(),temp);
}

//Display all the power-ups
int ADLL::display_power(int index){
  if(!head) //If empty
    return 0;
  return display_DLL(head[index]);
}

int ADLL::display_DLL(p_node * head){
  if(!head){ //Base case
    return 1;
  }
  //Display node
  head -> display_p_node();
  //Get next node
  return display_DLL(head -> get_next());
}

//Getting the total of atk and def
int ADLL::getting_total(int index){
  if(!head)
    return 0;
  return total(head[index]);
}

int ADLL::total(p_node * head){
  if(!head)
    return 0;
  int a = total(head -> get_next()) + head -> return_total();
  return a;
}

//Destructor
ADLL::~ADLL(){
  if(head){
    delete head;
    head =NULL;
  }
}

//Removal functions
int ADLL::remove_wrapper(){
  if(!head)
    return 0;
  int i = 0;
  int a = remove_array(i); 
  delete head;
  head = NULL;
  return 1;
}
//Traversing through the array
int ADLL::remove_array(int i){
  if(!head[i])
    return 0;
  remove_DLL(head[i]); //Traversing through the list

  return remove_array(i+1);
}

void ADLL::remove_DLL(p_node *& head ){
  if(!head)
    return;
  remove_DLL(head->get_next()); //Delete from last to first
  delete head;
  head = NULL;
  return;
}
