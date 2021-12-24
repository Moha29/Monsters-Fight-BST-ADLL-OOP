#include "header.h"

//The purpose of this program is to create a game where the user will be able to create monsters of 4 different kinds. This program supports 4 breeds vampires, zombies, werewolfs, and witches. Each breed has their own original status, the user will be able to apply power ups for each breed. Victory can be achived when the attack and defense of a monster are hight than the other one.

//Constructor
BST::BST(){
	root = NULL;
}

//Adding new monster
int BST::add_monster(monster * source){

	return add(source,root);
}

//Adding
int BST::add(monster * source, m_node *& root){
	if(!root){ //Base case
		root = new m_node(source);
		root -> set_left(NULL);
		root -> set_right(NULL);
		return 1;
	}
  //If passed name value is less than the node
	if(strcmp(root->return_name(),source->return_data())>0){
		add(source,root->get_left());
	}
	else
		add(source,root->get_right());
	return 1;
}

//Display monsters
int BST::display_monster(){
	if(!root)
		return 0;
	return display(root);
}

int BST::display(m_node * root){
	int counter;
	if(!root) //Base case
		return 0;
	counter = display(root->get_left());
	++counter;
	root->display_m_node();
	counter += display(root->get_right());
	return counter;
}

//GEtting the monster type
char * BST::get_monster(char * name1){
  if(!root)
    return NULL;
  char * type1; //To catch the type
  get(type1,name1, root);
  return type1;
}

void BST::get(char *& type1,char * name1,m_node * root){
  if(!root) //Base case
    return;
  get(type1,name1,root->get_left());
	if(strcmp(name1,root->return_name()) ==0){ //If match has been found
    type1 = new char [strlen(root->return_type())+1];
    strcpy(type1,root->return_type()); //Giving the passed array the value
    return;
  }
	return get(type1,name1,root->get_right());

}

//Destructor
BST::~BST(){
  if(root){
    delete root;
    root = NULL; 
  }
}

//Deleting all the data in a tree
int BST::remove_wrapper(){
  if(!root)
    return 0;
  return remove_all(root);
}
int BST::remove_all(m_node *& root){
  if(!root){
    return 1;
  }
  remove_all(root -> get_left());
  remove_all(root -> get_right());
  delete root;
  root = NULL; 
  return 1;
}

