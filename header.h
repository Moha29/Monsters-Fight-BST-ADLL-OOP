#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 5; //Constant size for the array of DLL

//The purpose of this program is to create a game where the user will be able to create monsters of 4 different kinds. This program supports 4 breeds vampires, zombies, werewolfs, and witches. Each breed has their own original status, the user will be able to apply power ups for each breed. Victory can be achived when the attack and defense of a monster are hight than the other one.



//an ABC for the breeds
//*I didn't use operator overloading in this heriarchy because I used pointers when upcasting. It was already too late to change it up. I only used it for the array of DLL 
class monster{
	public:
		monster();
		virtual char * return_data() = 0;
    virtual char * return_type() = 0;
		virtual int display() = 0;
		virtual ~monster();

	private:

};


//Type of breeds. Derived from monster

class vampire: public monster{
	public:
		vampire();  //Constructor
		vampire(const vampire &); //CC
		vampire(char *); //Setting data
		char * return_data(); //getters
    char * return_type();
		int display(); //display function
		~vampire();//Destructor
	private:
		char * name;
		char * type;
		char * ability;
};

//Type of breeds. Derived from monster
class zombie : public monster{
	public:
		zombie();
		zombie(const zombie &);
		zombie(char *);
		char * return_data();
    char * return_type();
		int display();
		~zombie();
	private:
		char * name;
		char * type;
		char * ability;
};

//Type of breeds. Derived from monster
class werewolf : public monster{
	public: 
		werewolf();
		werewolf(const werewolf &);
		werewolf(char *);
		char * return_data();
    char * return_type();
		int display();
		~werewolf();
	private:
		char * name;
		char * type;
		char * ability;
};

//Type of breeds. Derived from monster
class witch : public monster{
	public:
		witch();
		witch(const witch &);
		witch(char *);
		char * return_data();
    char * return_type();
		int display();
		~witch();
	private:
		char * name;
		char * type;
		char * ability;
};

//A node class that holds the breeds data
class m_node{
	public:
		m_node(); //Constructor
		m_node(monster *); //setting the node data
		m_node *& get_left(); //Setters and getters
		void set_left(m_node *);
		m_node *& get_right();
		void set_right(m_node *);
		void display_m_node(); //display
		char * return_name(); //geting the breeds data
    char * return_type();
		~m_node();
	private:
		monster * data; //ABC pointer
		m_node * right; //node pointers
		m_node * left;
};

//Class that manages the BST data structure
class BST{
	public:
		BST(); //Constructor
		int add_monster(monster *); //Adding wrapper
		int add(monster *, m_node *&); //Adding recursive
    char * get_monster(char *); //getting the type of monsters
    void  get(char *&, char *, m_node *);
		int display_monster(); //Display
		int display(m_node *);
    int remove_wrapper(); //Remove all 
    int remove_all(m_node *& );
		~BST();
	private:
		m_node * root;
};


//Class that holds the power-ups data
class power{
  public:
    //Output overloaded function
    friend ostream& operator << (ostream & cout, const power & source);
    //Assignment operator
    power& operator = (const power &);
    power(); //Consrtuctor
    power(const power &); //CC
    power(int,int,char *); //Setting data
    int calc(); //Getting total of atk and def
    int display_items();//Display available items
    char * return_item(); //Returning the item equiped
    ~power();
  private:
    int def;
    int atk;
    char * item;
};


//A node that holds the power-ups data
class p_node{
  public:
    p_node(); //Constructor
		p_node(power &); //CC
		p_node *& get_next(); //getters and setters
		void set_next(p_node *);
		p_node * get_prev();
		void set_prev(p_node *);
		void display_p_node(); //Ourputting data
    char * return_item(); 
		int return_total();// returning the total of Atk and Def
		~p_node();
  private:
    power data; //A class object
    p_node * next; //node pointers
    p_node * prev;
};

//Class the manages the Array of DLL 
class ADLL{
  public:
    ADLL(); //C
		int add_power(power &,int ); //adding
		int add(power &, p_node *&, p_node *&); 
    int getting_total(int); //Getting the total pf Atk and Def
    int total(p_node *);
		int display_power(int ); //Display power-ups for a breed
		int display_DLL(p_node *);
    int remove_wrapper(); //Delete all
    int remove_array(int);
    void remove_DLL(p_node *& );
		~ADLL();
  private:
    p_node ** head; //Pointer to a pointer
};
