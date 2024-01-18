#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#define COUNT 5

using namespace std;

class tNode{
    public:
    int data;
    tNode* left;
    tNode* right;

    tNode() : data(0){ left=right=NULL; }

    tNode(int data){
        this->data=data;
        left=right=NULL;
    }
};

class BST{
    public:
    tNode* root;
    static int flag;
    BST(){ root=NULL;	}

    void insertNode(int d){
        tNode* NN=new tNode(d);

        if(root == NULL){   root=NN;  }
        else{
            tNode* temp=root;

            while(temp != NULL){
                if(temp->data == d){
                    cout<<"tNode with the same value exists! "<<endl;
                    break;
                }
                else if(d < temp->data && temp->left == NULL){
                    temp->left=NN;
                    break;
                }
                else if(d < temp->data){
                    temp=temp->left;
                }
                else if(d >temp->data && temp->right == NULL){
                    temp->right=NN;
                    break;
                }
                else if(d > temp->data){
                    temp=temp->right;
                }
            }
        }
    }

    void genRandTree(){
        for(int i=0; i<7; i++){
            int d=1+(rand()%100);
            insertNode(d);
        }
    }

	void print2D(tNode* root, int space){
    
		if (root == NULL)	return;
		space += COUNT;	
		print2D(root->right, space);
	
		cout << endl;
		for (int i = COUNT; i < space; i++)			cout << " ";
		cout << root->data << "\n";
	
		print2D(root->left, space);
	}

    int height(tNode * r) {
		if (r == NULL)	return -1;
		else {
			int lheight = height(r -> left);
			int rheight = height(r -> right);

		if (lheight > rheight)	return (lheight + 1);
		return (rheight + 1);
		}
  	}

  	int getBalanceFactor(tNode * n) {
		if (n == NULL)	return -1;
		return height(n -> left) - height(n -> right);
  	}

  	bool isBalanced(tNode* root){
		int lh;	int rh;

		if (root == NULL)		return 1;

		lh = height(root->left);
		rh = height(root->right);
	
		if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))	return 1;	
		return 0;
	}

   void BSTGame(){
        char choice;
        cout<<"\nBalanced BST: Height of left subtree - height of right subtree is 0 or 1"<<endl;
        cout<<"\nA SIDEWAYS binary search tree will be shown on your screen for 5 seconds"<<endl;
        system("pause");
        BST tree;
        tree.genRandTree();
        tNode* temp = tree.root;
        tree.print2D(temp,0);
        sleep(5);
        system("CLS");
        cout<<"\nWas the given Binary Search tree Balanced? Enter Y || y (for Yes) OR N || n (for No) "<<endl;
        cin>>choice;
        
            if(choice == 'Y' || choice == 'y'){
                if(isBalanced(temp)){
                    cout<<"Correct answer"<<endl<<endl;
                    flag=0;
                }
                else{
                cout<<"Wrong answer!! play again"<<endl<<endl;
                flag=1;
                }
            }
            else if(choice == 'N' || choice == 'n'){
                if(isBalanced(temp)){
                    cout<<"Wrong answer!! play again"<<endl<<endl;
                    flag=1;
                }
                else{
                cout<<"Correct answer"<<endl<<endl;
                flag=0;
                }
            }
    }
	friend class game;

};	int BST::flag=0;

template <class NTem> 
class Node {
public:
    NTem data;
    Node* link;  
    Node(NTem n){ this->data = n; this->link = NULL; }
};

template <class STem>
class Stack {
    Node<STem>* top;
 
public:
    Stack() { top = NULL; }
    
    void view() {
			Node<STem> *temp = top;
			while (temp!=NULL)	{
				cout << temp->data;
		 		temp = temp->link;
			}
	}
 
    void push(STem data) {
        Node<STem>* temp = new Node<STem>(data);
 
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }
        
        if (top==NULL)	top=temp;
        else
        {
        	temp->link = top;
        	top = temp;
		} 
    }
 
    bool isEmpty() {    return top == NULL; }
    
    int topsize(){	return top->data.size();	}
 
    STem pop()  {
    	STem x;
    	
        Node<STem>* temp;
 
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
 
            temp = top;
            top = top->link;
            x = temp->data;
            free(temp);
            return x;
        }
    }
  
    void display()   {
        Node<STem>* temp;
 
        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        }
        else {
            temp = top;
            while (temp != NULL) {
 
                cout << temp->data;
 				sleep(1);
		 		system ("CLS");
                temp = temp->link;
            }
        }
    }
    void stackdisplay()
    {
        Node<STem>* temp;
 
        if (top == NULL) {     cout << " ";     }
        else {
            temp = top;
            while (temp != NULL) {
                cout << temp->data << "\n";
                temp = temp->link;
            }
        }
    }
};

bool numberordergame(){
	Stack<int> s;
	int x;
	int y;
	
	for (int i=0; i<5; i++)	{
		x = rand();
		if (x>0 && x<10)	{			s.push(x);		}
		else		{			i--;		}
	}
	
 	cout<<"\nNumbers will be shown on your screen, focus!"<<endl;
    system("pause");
	system ("CLS");
	
	s.display();
	
	cout << "Enter the numbers one by one in the order in which they appeared : ";
	
	for (int i=0; i<5; i++)	{
		 cin >> y;
		 x=s.pop();
		 if(y!=x)	 {
		 	cout << "Failed game" << endl;
		 	return 0;
		 }
	}
	cout << "Passed game" << endl;
	return 1;
}

bool ringgame(){
	int f,t,r=0,moves=0;
	string temp;
	cout << "The given string of 1s represent rings, the more 1s in a string, the bigger the ring is. \nYour goal is to sort the rings on any one of the three poles in ascending order (smallest on top and biggest at the bottom ). \nRemember that only a shorter ring can be stacked on top of another, and only the top ring can be moved per turn. You only get 20 Moves, use them wisely!" << endl;
	
	cout << "\nEnter -1 to quit the game at any time\n";
	Stack<string> s1;
	Stack<string> s2;
	Stack<string> s3;
	
	while (r<1 || r>5){		r=rand() % 6;	}
	
	switch (r){
		case 1:
			s1.push("1 1 1 1 1");
			s1.push("1 1 1");
			
			s2.push("1 1 1 1");
			s2.push("1");
			
			s3.push("1 1");
			break;
			
		case 2:
			s1.push("1 1 1 1");
			s1.push("1 1 1");
			
			s2.push("1 1 1 1 1");
			s2.push("1");
			
			s3.push("1 1");
			break;	
	
		case 3:
			s1.push("1 1");
			s1.push("1");
			
			s2.push("1 1 1 1");
			s2.push("1 1 1");
			
			s3.push("1 1 1 1 1");
			break;
			
		case 4:
			s1.push("1 1 1 1 1");
			s1.push("1 1 1 1");
			
			s2.push("1 1 1");
			s2.push("1");
			
			s3.push("1 1");
			break;
			
		case 5:
			s1.push("1 1 1 1 1");
			s1.push("1 1");
			
			s2.push("1 1 1 1");
			s2.push("1 1 1");
			
			s3.push("1 ");
			break;
	
		default:
			break;
	}
	
	while(f!= -1 && t!= -1)
	{
		if(moves>20)	{
			cout << "No Moves Left :(" << endl;
			return 0;
		}
		
		cout << "Moves Left : " << 20-moves << endl;
		
		cout << "\n1st Pole : \n";
		s1.stackdisplay();
		cout << "\n2nd Pole : \n";
		s2.stackdisplay();
		cout << "\n3nd Pole : \n";
		s3.stackdisplay();
		
		cout << "Move from :\n1) 1st Pole\n2) 2nd Pole\n3) 3rd Pole" << endl;
		cin >> f; 
		if (f==-1) break;
		cout << "Move to :\n1) 1st Pole\n2) 2nd Pole\n3) 3rd Pole\n" << endl;
		cin >> t;
		if (t==-1) break;
		if (f!=t && f>0 && f<4 && t>0 && t<4)
		{
			switch (f)
			{
				case 1:
					switch (t)
					{
						case 2:
							if ((s2.isEmpty() || s2.topsize()>s1.topsize()) && !s1.isEmpty())	{
								temp=s1.pop();
								s2.push(temp);
								moves++;
							}
							else{	cout << "Illegal Move, hehe" << endl;	}
							break;
						case 3:
							if ((s3.isEmpty() || s3.topsize()>s1.topsize()) && !s1.isEmpty()){
								temp=s1.pop();
								s3.push(temp);
								moves++;
							}
							else{		cout << "Illegal Move, hehe" << endl;	}
							break;
						default:
							cout << "Invalid Input!" << endl;
							break;
					}
					break;
					
				case 2:
					switch (t)
					{
						case 1:
							if ((s1.isEmpty() || s1.topsize()>s2.topsize()) && !s2.isEmpty()){
								temp=s2.pop();
								s1.push(temp);
								moves++;
							}
							else	{		cout << "Illegal Move, hehe" << endl;	}
							break;
						case 3:
							if ((s3.isEmpty() || s3.topsize()>s2.topsize()) && !s2.isEmpty())	{
								temp=s2.pop();
								s3.push(temp);
								moves++;
							}
							else	{
								cout << "Illegal Move, hehe" << endl;	}
							break;
						default:
							cout << "Invalid Input!" << endl;
							break;
					}
					break;
					
				case 3:
					switch (t)
					{
						case 1:
							if ((s1.isEmpty() || s1.topsize()>s3.topsize()) && !s3.isEmpty())	{
								temp=s3.pop();
								s1.push(temp);
								moves++;
							}
							else	{cout << "Illegal Move, hehe" << endl;	}
							break;
						case 2:
							if ((s2.isEmpty() || s2.topsize()>s3.topsize()) && !s3.isEmpty())	{			
								temp=s3.pop();
								s2.push(temp);
								moves++;
							}
							else	{	cout << "Illegal Move, hehe" << endl;	}
							break;
						default:
							cout << "Invalid Input!" << endl;
							break;
					}
					break;
					
				default:
					cout << "Invalid Input!" << endl;
					break;
			}
		}
		else		{			cout << "Invalid Input!" << endl; return 0;		}
		if ((s1.isEmpty() && s2.isEmpty()) || (s2.isEmpty() && s3.isEmpty()) || (s1.isEmpty() && s3.isEmpty()))	{
			cout << "PASSED THE GAME LESSGOOOOO!" << endl;
			return 1;
		}
	}
}

bool minigame(){
		//Binary Search Tree Mini Game
		BST tree1;
		for(int i=0; i<2; i++){
			tree1.BSTGame();
			if(tree1.flag == 0){
				cout<<"Task finished successfulLy"<<endl;
				return 1;
				break;
			}
		}
		if(tree1.flag == 1)
			cout<<"Task failed"<<endl;
		return 0;
	}

class player{
	public:
		string ID;
		bool killer;
		player * next;
		player * blames;
		player(string i):ID(i){ next = NULL;	killer = false;}
};

class list{
	public:
		player * head;
		int total;
		list() : total(0){	head=NULL;	}
		
		bool addplayer(string i){
			if (head ==  NULL) 	head = new player(i);
			else{
				player * temp = head;
				while (temp->next != NULL){
					temp = temp->next;
					if (temp->ID == i) return false;
				} 
				temp->next = new player(i);
			}
			total++;
			return true;
		}
		
		bool findplayer(string i){
			player * temp = head;
			while(temp->ID != i){
				if (temp->next == NULL) return false;	
				temp = temp->next;
			}
			return temp;
		}
		
		bool killplayer(string i){
			player * temp = head;
			if (head->ID == i){
				 head = head->next; 	return true;
			}
			while(temp->next->ID != i){
				temp = temp->next;
				if (temp->next == NULL) return false;	
			}
			temp->next = temp->next->next;
			total--;
			return true;
		}
		
		void showplayers(){
			player * temp = head;
			cout << endl;
			while (temp!= NULL){
				cout << "\t" << temp->ID  ;
				temp = temp->next;
			} cout << endl;
		}
		
		void showplayers(string i){
			player * temp = head;
			cout << endl;
			while (temp!= NULL){
				if (temp->ID != i) cout << temp->ID << "\t" ;
				temp = temp->next;
			} cout << endl;
			
		}
		
		player * assignkiller(){
			int r=1;
			player * temp = head;
			while( r != 0){
				if (rand() % 10 == 0){
					temp->killer = true;
					return temp;
				}
				temp = temp->next;
				if (temp==NULL) temp=head;
			}
			return temp;
		}
		
		void revealkiller(){
			player * temp = head;
			while(!temp->killer && temp != NULL) temp = temp->next;
			cout << "The killer is: " << temp->ID;
		}
		
};

bool minigamemanager(){
	int r;
	while (r<1 || r>3){	r=rand() % 4;	}
	
	switch (r){
		case 1:
			return minigame();
			break;
		case 2:
			return ringgame();
			break;
		case 3:
			return numberordergame();
			break;
		default:
			break;
	}
}

class game{
	public:
	player * killer;
	player * winner;
	int totalplayers;
	list playerlist;
	string victim;
	
	game() : totalplayers(0){			}
	
	void play(){
		
		while (totalplayers < 4){
			cout << "\nEnter number of players: ";
			cin >> totalplayers;
			if (totalplayers < 4) cout << "\nYou need atleast 4 players to play! ";
		}
		
		string id;
		for (int i=0 ; i<totalplayers ; i++){
			cout << "\nEnter ID for player " << i+1 << ": ";
			cin >> id;
			playerlist.addplayer(id)	;
		}
		
		killer = playerlist.assignkiller();
		
		while (playerlist.total > 2){
			int w=round();
			system ("CLS");
			if (w == 0) {
				cout << "\nThe Killer has been defeated!";
				system("pause");
				 return;
			}
			else if (w == 1){
				cout << "\n\n\tThe Killer has won!\n";
				system("pause");
				 return;
			}
			else {
				cout << " . . . " << victim << " was killed in the previous round :( \n";
				cout << "\nProceeding to the next round!";
				system("pause");
			}
		}
		
		//playerlist.revealkiller();
	}
	
	int round(){
		
		int correctguesses;
		bool choice;
		
		player * temp = playerlist.head;	
		
		while(temp != NULL){
			
			system ("CLS");
			
			playerlist.killplayer(victim);
			cout << "Remaining players: "; playerlist.showplayers();
			
			if (totalplayers == 2){
					winner = killer;
					return 1;
			}
			
			cout << "\nSwitch seats!\n";
			cout << "\nNext turn: Player " << temp->ID << endl;
			
			system("pause");
			system("cls");
			cout << "\nWelcome " << temp->ID << "!\n";
			if (temp->killer){
				
				cout << "\n\n\tYou are the killer! \n";
				if (minigamemanager())
				{
					cout << "Do you want to kill someone?\n0.No\n1.Yes" << endl;
					cin >> choice;
					if (choice==1)
					{
						cout << "Who's dying tonight? \n";
						playerlist.showplayers(temp->ID);
						cin >> victim;
						
						while (victim == killer->ID || !playerlist.findplayer(victim) ){
							
							if (victim == killer->ID) cout << "\nYou cannot kill yourself - strike again: ";
							else cout << "\nPlayer not found - strike again: ";
							cin >> victim;
						}
						
						cout << "\nSuccessful kill! Remaining players: \n"; totalplayers-- ;
					//	cout << "......total : " << totalplayers << " " << playerlist.total << endl;
						playerlist.showplayers(victim);
					}
					else victim = "no one";
				}
				else victim = "no one";
				
				if (playerlist.total == 1){
					winner = killer;
					return 1;
				}
			}
			
			else{
				if (minigamemanager())
				{
					cout << "Do you want to blame someone?\n0.No\n1.Yes" << endl;
					cin >> choice;
					if(choice == 1)
					{
						string blamed;
					
						while (!playerlist.findplayer(blamed)){
							cout << "who do you blame? ";
							playerlist.showplayers(temp->ID);
							cin >> blamed;
							if (!playerlist.findplayer(blamed)) cout << "\nPlayer not found - try again!\n";
						}
						
						
						if (blamed == killer->ID) correctguesses++;
					}
				}
				
			}
			
			char c;
			cout << "\nEnter any key to exit your turn (no peeking!) : ";
			system("pause");
			
			temp = temp->next;
			
		}
		if (correctguesses >= totalplayers/2){			return 0;			}
		playerlist.killplayer(victim);
		return -1;
	}
};

void arrow(int realPos, int arrowPos){
	if(realPos == arrowPos)
		cout<<"-> ";
	else cout<<"   ";
}

int menu(){
	int pos=1;
	int keyPressed=0;
	
	while(keyPressed != 13){
		
		system("CLS");
		
		arrow(1,pos); cout<<" 1. Start Game"<<endl;
		arrow(2,pos); cout<<" 2. Instructions"<<endl;
		arrow(3,pos); cout<<" 3. Settings"<<endl;
		arrow(4,pos); cout<<" 4. Quit Game"<<endl;
	
		keyPressed=getch();
	
		if(keyPressed == 80 && pos != 4){
			pos++;
		}
		else if(keyPressed == 72 && pos !=1){
			pos--;
		}
		else pos=pos;
		}
		
		return pos;
}

int theme(){
	int pos=1;	int keyPressed=0;
	
	const char* colors[12] = { "Color 0F", "Color F0", "Color 4F", 
								"Color 0A", "Color 3F", "Color 5D", 
								"Color 2E","Color 8B", "Color 9F", 
								"Color 6E", "Color 8F", "Color CE"};
								
	string colornames[12] = {  "Default (Black/White)","Notepad","Red Velvet", 
										"Matrix", "i am under the water pls help me",  "Princess", 
										"Springtime", "Futuristic", "System Crash",
										"Gold", "Silver", "McDonalds"}; 
	
	while(keyPressed != 13){
		system("CLS");
		
		cout << "\n\tSelect your theme: \n\n";
		
		for (int i=1 ; i<=12 ; i++){		arrow(i,pos); cout << i << ": " << colornames[i-1] << endl;	}
		
		keyPressed=getch();
		
		if(keyPressed == 80 && pos != 12)
		{	pos++;	system(colors[pos-1]); }
		
		else if(keyPressed == 72 && pos != 1)
		{	pos--;	system(colors[pos-1]);	}
		
	}
	return pos;
}

void welcomescreen(){
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl; 
	cout<<"\t\t.-----..-----..-----.  .-----..-----..-----..-----..-----.  .-----..-----..-----..-----.\n";
	cout<<"\t\t| --- || --- || --- |  | --- || --- || --- || --- || --- |  | --- || --- || --- || --- |\n";
	cout<<"\t\t|     ||     ||     |  |     ||     ||     ||     ||     |  |     ||     ||     ||     |\n";
	cout<<"\t\t|  T  ||  H  ||  E  |  |  B  ||  L  ||  A  ||  M  ||  E  |  |  G  ||  A  ||  M  ||  E  |\n";
	cout<<"\t\t|     ||     ||     |  |     ||     ||     ||     ||     |  |     ||     ||     ||     |\n";
	cout<<"\t\t| --- || --- || --- |  | --- || --- || --- || --- || --- |  | --- || --- || --- || --- |\n";
	cout<<"\t\t'-----''-----''-----'  '-----''-----''-----''-----''-----'  '-----''-----''-----''-----'\n";
	cout<<endl;
	cout<<"                     _ "<<endl;
	cout<<"                    / | "<<endl;
	cout<<"                   /  /  "<<endl;
	cout<<"      ____________/  /   "<<endl;
	cout<<"     /           ___/____________  "<<endl;
	cout<<"                   ______________)  "<<endl;
	cout<<"                   \\                     "<<endl;
	cout<<"    \\           ,-'                     "<<endl;
	cout<<"     \\           \\                        "<<endl;
	cout<<"      ------------'                        "<<"\n\n\n";
	
	cout<<"\t\t----------------------------------------------------------------------------------------\n";  
	cout<<endl<<endl<<endl<<endl<<endl;  
   system("pause");
	system("cls");
	
	
}

void exitscreen(){
system("cls");
	cout<<endl<<endl<<endl<<endl<<endl; 
	cout<<"\t\t.-----..-----..-----..-----..-----.  .-----..-----..-----.\n";
	cout<<"\t\t| --- || --- || --- || --- || --- |  | --- || --- || --- | \n";
	cout<<"\t\t|     ||     ||     ||     ||     |  |     ||     ||     | \n";
	cout<<"\t\t|  T  ||  H  ||  A  ||  N  ||  K  |  |  Y  ||  O  ||  U  | \n";
	cout<<"\t\t|     ||     ||     ||     ||     |  |     ||     ||     | \n";
	cout<<"\t\t| --- || --- || --- || --- || --- |  | --- || --- || --- | \n";
	cout<<"\t\t'-----''-----''-----''-----''-----'  '-----''-----''-----' \n";
	cout<<endl;
	cout<<"                     _ "<<endl;
	cout<<"                    / | "<<endl;
	cout<<"                   /  /  "<<endl;
	cout<<"      ____________/  /   "<<endl;
	cout<<"     /           ___/____________  "<<endl;
	cout<<"                   ______________)  "<<endl;
	cout<<"                   \\                     "<<endl;
	cout<<"    \\           ,-'                     "<<endl;
	cout<<"     \\           \\                        "<<endl;
	cout<<"      ------------'                        "<<"\n\n\n";
	
	cout<<"\t\t----------------------------------------------------------------------------------------\n";  
	cout<<endl<<endl<<endl<<endl<<endl;  
   system("pause");
	system("cls");


}

void settings(){
	theme();
}

void instructions(){
	system("cls");
	cout << "\n \t \t INSTRUCTIONS \n\n";
	cout << "\n \t 1. You need a minimum of four players for this game \n";
	cout << "\n \t 2. Enter the number of players and their usernames  \n";
	cout << "\n \t 3. A killer is randomly selected for the game \n";
	cout << "\n \t 4. Players take their turn at the computer one by one \n";
	cout << "\n \t 5. Other players MUST look away while a player is taking his/her turn  \n";
	cout << "\n \t 6. The killer can eliminate any other player during his/her turn if he/she passes the minigame  \n";	
	cout << "\n \t 7. Other players will play mini-games during their turn   \n";
	cout << "\n \t 8. Each player other than the killer can 'blame' one other player who they suspect is the killer \nif he/she passes the minigame  \n";
	cout << "\n \t 9. If more than half the players blame the right killer, the killer loses \n";
	cout << "\n \t 10. If the killer manages to kill all but two players, the killer wins \n\n\n";
	system("pause");
}

int main(){

	srand(time(0));
	game round1;
	
	welcomescreen();
	int choice;
	
	while(choice != 4){
		choice = menu();
		switch(choice){
			case 1:
				round1.play();
				break;
			
			case 2:
				instructions();
				break;
			
			case 3:
				settings();
				break;
				
			case 4:
				exitscreen();
				break;
		}
	}
}
