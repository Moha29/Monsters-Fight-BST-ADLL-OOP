#include "header.h"

//The purpose of this program is to create a game where the user will be able to create monsters of 4 different kinds. This program supports 4 breeds vampires, zombies, werewolfs, and witches. Each breed has their own original status, the user will be able to apply power ups for each breed. Victory can be achived when the attack and defense of a monster are hight than the other one.

//Constructor
m_node::m_node(): data(NULL),right(NULL),left(NULL){

}

//Setting data pointer
m_node::m_node(monster * source){
	data = source;
}

//Getters and setters
m_node *& m_node::get_left(){
	return left;
}

void m_node::set_left(m_node * root){
	left = root;
}

m_node *& m_node::get_right(){
	return right;
}

void m_node::set_right(m_node * root){
	right = root;
}

//Display monster info
void m_node::display_m_node(){
	int a = data -> display();
	return;
}

//Returning the monster name
char * m_node::return_name(){
	return data -> return_data();
}

//Returning the monster type
char * m_node::return_type(){
  return data -> return_type();
}

//Destructor
m_node::~m_node(){
  if(left){
    delete left;
    left = NULL;
  }
  if(right){
    delete right;
    right = NULL;
  }
  if(data){
    delete data;
    data = NULL;
  }
}


//Power node

//Constructor 
p_node::p_node(): next(NULL),prev(NULL){

}

//Copying from class object to data
p_node::p_node(power & source){
	data = source;
}

//Setters and getters
p_node *& p_node::get_next(){
	return next;
}

void p_node::set_next(p_node * head){
	next = head;
}

p_node * p_node::get_prev(){
	return prev;
}

void p_node::set_prev(p_node * head){
	prev = head;
}

//Displaying node
void p_node::display_p_node(){
	cout<<data;

}

//Returing item 
char * p_node::return_item(){
	return data.return_item();
}

//REturing total
int p_node::return_total(){
  int a = data.calc();
  return a;
}

//Destructor
p_node::~p_node(){
  
  
  if(next){
    //delete next;
    next = NULL;
  }
  if(prev){
    //delete prev;
    prev = NULL;
  }
  
}
