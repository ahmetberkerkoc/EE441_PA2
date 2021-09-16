//Ahmet Berker KOÇ 2232320
#include <iostream> //  Standard Input / Output Streams Library.
#include <fstream>
#include <string>
#include <cstdlib>
#include<time.h>
using namespace std;  // instead of using std::

//I use stcack for part d I implement it as before examples, I use push pop peek methods
 class Stack
{
	private:
		int stacklist[50];
		int top;
	public:
		Stack(void);
		void Push(const int& item);
		int Pop(void);
		void Clearstack(void);
		int Peek(void) const;
		int StackEmpty(void) const;
		int StackFull(void) const;
};


Stack::Stack(void):top(-1)
{}

int Stack::StackEmpty(void) const{
	return top==-1;
}

int Stack::StackFull(void) const{
	return top==50-1;
}

void Stack::Push(const int& item){
	int temp;
	if (StackFull()){
	cerr<<"Stack Full"<<endl;
	exit(1);
	}
	top++;
	stacklist[top]=item;
}

int Stack::Pop(void){
	int temp;
	if (StackEmpty()){
	cerr<<"Stack Empty"<<endl;
	exit(1);
	}
	temp=stacklist[top];
	top--;
	return temp;
}

int Stack::Peek(void) const{
if (StackEmpty()){
	cerr<<"Stack Empty"<<endl;
	exit(1);
	}
return stacklist[top];
}

//This is my Graph class. I used it as a map
class Graph{
    private:
    int      map[20][20];			//map 2D array. Its rows are cities which represents FROM CITIES and row are also cities which represent TO CITIES
    public:
        string cities[20];			//cities string array keeps the name of the cities
        Graph();					//constructor
        void AddGcity(string name);
        void RemoveGcity(string name);
        int SearchGcity(string name);
        void AddGroute(string fcity, string tcity,int fare);
        void RemoveGroute(string fcity, string tcity);
        int SearchGroutewithCoordinate(int i,int j);
        int SearchGroute(string fcity, string tcity);
        void ListGroute();
        void ListGroute2();
        void Listcity();

};
//in constructor it read the txt file and assign names of cities to string array cities also it initilaize the map elemans as 0
Graph::Graph(){
    string line;
    string city[20];
    ifstream myfile ("citylist.txt");
    if (myfile.is_open())
    {
        int i=0;
        while ( getline (myfile,line) )
        {
            city[i]=line;
            cities[i]=city[i];
            i++;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    int i,j;
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            map[i][j]=0;
        }
    }
}
    //This method searches the name on the cities array if find a city it returns the index
    int Graph::SearchGcity(string name){
        int i;
        for(i=0;i<20;i++){
            if (cities[i]==name)
                return i;
        }
        return -1;
    }
	//I dont use this method but if you remove a city and add a new city name this method enable that
	void Graph::AddGcity(string name){
		int i;
		for(i=0;i<20;i++){
			if(cities[i]==" "){
				cities[i]=name;
				break;
			}
		}
	}
	//I dont use this method but if you remove a city from the cities array and map rows and columns become 0
    void Graph::RemoveGcity(string name){
        int i;
        int j;
        i=SearchGcity(name);
        cities[i]=' ';
        for(j=0;j<20;j++){
            map[i][j]=0;
            map[j][i]=0;
        }
    }
    //This method add a fare value for a route. Route information is taken as input from city, to city, fare
    void Graph::AddGroute(string fcity, string tcity,int fare){
        int i,j;
		i=SearchGcity(fcity);
        j=SearchGcity(tcity);
        map[i][j]=fare;
    }
	//This method remove route from the map. Related location becomes 0
    void Graph::RemoveGroute(string fcity, string tcity){
        int i,j;
		i=SearchGcity(fcity);
        j=SearchGcity(tcity);
        map[i][j]=0;
    }
    //This method return fare value for related route according to cities name
    int Graph::SearchGroute(string fcity, string tcity){
        int i,j;
		i=SearchGcity(fcity);
        j=SearchGcity(tcity);
        if(map[i][j]!=0)
            return map[i][j];
        else
            return 0;
    }
    //This method return fare value for related route according to cities location values
     int Graph::SearchGroutewithCoordinate(int i,int j){
     	return map[i][j];
	 }
	//This method display the routes
    void Graph::ListGroute(){
        int i,j;
        for(i=0;i<20;i++){
            for(j=0;j<20;j++){
                if(map[i][j]!=0){
                    cout<<"("<<cities[i]<<" ---> " <<cities[j]<< ", " << map[i][j]<<")"<<"\n";
                }
    }
    }
    }

	//this method display the maps 2D array I use it for debugging
    void Graph::ListGroute2(){
        int i,j;
        for(i=0;i<20;i++){
            for(j=0;j<20;j++){

                cout<< map[i][j]<<" ";

    }
    cout <<"\n";
    }
    }
		//This method display the cities array content
	  void Graph::Listcity(){
        int j;
            for(j=0;j<20;j++){
                cout<< cities[j]<<"\n";
    }
	}

	//This function gives the initial values for map array with random fare
	void INITROUTEMAP(Graph& x){
		srand(time(0));					//srand for different random for every run if we dont use that all runs give same random value with values of first run
		x.AddGroute("Probia","Gulf of Archi",rand()%100+1);
		x.AddGroute("Probia","Las Datas",rand()%100+1);
		x.AddGroute("Probia","Logicheim",rand()%100+1);
		x.AddGroute("Logicheim","Probia",rand()%100+1);
		x.AddGroute("Signale","Probia",rand()%100+1);
		x.AddGroute("Gulf of Archi","Logicheim",rand()%100+1);

	}

	//Tree Node implementation
	class TreeNode{
		private:
			int occupancy_rate; //occcupancy rate
		public:
			int data;
			TreeNode *left; //left child
			TreeNode *right;	//right child
			TreeNode(const int &item,TreeNode *lptr=NULL, TreeNode *rptr=NULL);	 //constructor
			void SETOCCUPANCYRATE();
			int GETOCCUPANCYRATE()const;
	};

	TreeNode::TreeNode(const int &item, TreeNode *lptr, TreeNode *rptr):data(item),left(lptr),right(rptr){
	}
	void TreeNode::SETOCCUPANCYRATE(){

		occupancy_rate=rand() % 101; // random 0-100


	}

	int TreeNode::GETOCCUPANCYRATE() const{
		return occupancy_rate; //return occupany rate

	}
	//binary tree class for  creating a binary tree. Also,it enable us methods safety and more clear implementation
	class BinaryTree{
		private:
			TreeNode *root1;
		public:
			BinaryTree(); //constructor
			TreeNode* AddFlight(TreeNode* root ,int fnumber);
			TreeNode* RemoveFlight(TreeNode* root ,int fnumber);
			TreeNode* SearchFlight(TreeNode* root ,int fnumber);
			TreeNode* Min(TreeNode* root);
			void inorder(TreeNode *root);
			void length(TreeNode *root,int& count);
			void putoccupanciesfortree(TreeNode* root);
	};
	BinaryTree::BinaryTree(){

	}
	//add a flight to binary tree
	TreeNode* BinaryTree::AddFlight(TreeNode* root, int fnumber){
			if (root==NULL)   //if root null create a node
				return new TreeNode(fnumber,NULL,NULL);
			if(fnumber>root->data)  //add to right child
				root->right=AddFlight(root->right,fnumber);
			else//add to left child
				root->left=AddFlight(root->left,fnumber);
			return root;		//return the root it is very important when create a binary tree.
	}
	//search a key number which is flight number flight on binary tree
	TreeNode* BinaryTree::SearchFlight(TreeNode* root,int fnumber){
		if(root==NULL)
			return NULL;
		if(fnumber==root->data)
			return root;
		else if(fnumber>root->data)
			return SearchFlight(root->right,fnumber);
		else if(fnumber<root->data)
			return SearchFlight(root->left,fnumber);
	}
	//for finding min value of the binary tree
	TreeNode* BinaryTree::Min(TreeNode* root){
		TreeNode* current=root;
		while(current&&current->left!=NULL)
			current=current->left;
		return current;
	}
	//remove flight from  the binary tree
	TreeNode* BinaryTree::RemoveFlight(TreeNode* root, int fnumber){
			if(root==NULL)
				return NULL;
			if(fnumber<root->data)         //if it is less than root data go left
				root->left=RemoveFlight(root->left,fnumber);
			else if(fnumber>root->data)		//if it is more than root data go right
				root->right=RemoveFlight(root->right,fnumber);
			else{  //if same as the key value go to delate operation
				if(root->left==NULL){
				TreeNode* temp=root->right;  //if node has only one child
				delete root;
				return temp;
				}
				else if(root->right==NULL){
					TreeNode* temp=root->left;
				delete root;
				return temp;
				}
			//node with two child
			TreeNode* temp=Min(root->right);
			root->data=temp->data;// Copy the inorder successor's content to this node
			root->right=RemoveFlight(root->right,temp->data);//remove the inorder successor
		}
		return root;// return root it is very very important because our root can be changed
	}
	//for display with inorder traversal
	void BinaryTree::inorder(TreeNode* root)
{
    if (root != NULL) {
        inorder(root->left);
        if(root->data<1000)
        	cout <<"EE0"<< root->data<<endl;// to show with 4 digit EE0115
        else
        	cout <<"EE"<< root->data<<endl;
        inorder(root->right);
    }
}
	//I used this method while debugging but then I dont use it. It counts the eleman of the binary tree
	void BinaryTree::length(TreeNode* root,int& count)
{
    if (root != NULL) {
        length(root->left,count);
        count++;
        length(root->right,count);
    }

}
		//set the occupancies for binary search tree node
		void BinaryTree::putoccupanciesfortree(TreeNode* root)
{
    if (root != NULL) {
        putoccupanciesfortree(root->left);
        root->SETOCCUPANCYRATE();
       putoccupanciesfortree(root->right);
    }
}
		//initializing the binary tree with 6 node
	 TreeNode* INITFLIGHTPLAN(BinaryTree &object){
		TreeNode* tree=NULL;
		tree=object.AddFlight(tree,118);
		tree=object.AddFlight(tree,103);
		tree=object.AddFlight(tree,107);
		tree=object.AddFlight(tree,701);
		tree=object.AddFlight(tree,1501);
		tree=object.AddFlight(tree,1807);

		return tree;
	}
	//every mount new nodes are added number of nodes is an input N. I used N=5  in the main but it can be changed
	int* ADDMONTHLYNEWROUTES(Graph& map,int N){
		int a,b,t=1;
		int i;
		string from;
		string to;
		 int* array = new int[N];
		 for( i=0;i<N;i++){ // 0 all element in the array for safety
		 	array[i]=0;
		 }

		for( i=0;i<N;i++){

			a= rand() % 20;
			b= rand() %20;
			from=map.cities[a];
			to=map.cities[b];
			if (map.SearchGroute(from,to)==0 && a!=b){  //it should be 0 in the map and it should be differnt cities for from and to
				map.AddGroute(from, to, rand()%100+1);

				array[i]=100*(a+1)+b+1;//fligth number calculation and assign it to array

				cout<<"(" << from <<"---> " <<to <<", " <<map.SearchGroute(from,to)<<")"<< " Route Added"<<endl;
			}
			else
				i--;  //if condition is not sattisfy i-- to add N certainly
		}
		return array; //it return array and ADDMONTHLYNEWFLIGHTS use it for adding to tree
	}
	//This function it adds the new flight numbers to binary search tree
	TreeNode* ADDMONTHLYNEWFLIGHTS(BinaryTree &object,int *array,int N,TreeNode* tree){
			//arguments is binary search tree object, array wit flight numbers and root node

			for(int i=0;i<N;i++) {
				tree=object.AddFlight(tree,array[i]);
				if(array[i]<1000){
					cout<<"Flight "<<"EE0"<<array[i]<<" Added"<<endl;
				}
				else
					cout<<"Flight "<<"EE"<<array[i]<<" Added"<<endl;
		}
			return tree;//it is important for changing the root. It can be unnecessary in this question but it is very essential
	}

//This method is used for finding which route fare is changed, which route is deleted from both map and binary search tree.
//This method finds route, change fare and keep flight number in a stack. This stack enable us to remove related node from binary search tree
//for reaching all  flight numbers I use inorder traversal method. I choose them according to the instruction
void CANCELUNPOPULARFLIGHTS(BinaryTree &object, int OT,TreeNode* root,Graph &map,Stack &stack){
		int fnumber,fare;

		int oldoccupy;
		int i,j;
		int k=0;
		string from,to;
		if (root != NULL) {	//inorder traversal left root right
        CANCELUNPOPULARFLIGHTS(object,OT,root->left,map,stack); //go left
        oldoccupy=root->GETOCCUPANCYRATE(); //keep old occupany rate for compare flights for 2 months if it stay below the threshold two times node will be removed
        root->SETOCCUPANCYRATE();		//set new occupancy for all node i.e. go second month
        if(oldoccupy<OT){			//examination of first month

        	fnumber=root->data; //take data of node
        	i=fnumber/100; //parse them to find from city and to city
        	j=fnumber%100;//
        	i=i-1;//fit witharray index
        	j=j-1;//fit with array index
        	from=map.cities[i]; //take the name of "from city"
        	to=map.cities[j]; //take the name of "to city"
        	fare=map.SearchGroute(from,to); //take the fare of route

			map.AddGroute(from,to,fare/2);	//cut in half


        	 if(root->GETOCCUPANCYRATE()<OT){////examination of second month if occupancy below the treshold again node must be delated


        	 	map.RemoveGroute(from,to); //remove it from the map
        	 	cout<<"("<<from<<"---> "<<to<<")"<<"Route Discarded"<<endl;
        	 	stack.Push(fnumber);//push flight number in a stack to use it while remove flight number from bst
			 }
			 else{
			 	cout<<"("<<from<<"---> "<<to<< ","<<fare<<")"<<"is %50 Off"<<endl; //only discounted route not delated route
			 }

		}
        CANCELUNPOPULARFLIGHTS(object,OT,root->right,map,stack); //go to right node recursively

    }

	}
	//This method remove flight number from the bst according to the values in the stack comming from above formula
	TreeNode* removeunpopular(BinaryTree &object, TreeNode* root, Stack &stack){
		int value;
		while(!stack.StackEmpty()){ //pop the stack while it become empty
			value=stack.Pop();
			root=object.RemoveFlight(root,value); //remove it from the bst
			if(value<1000)
				cout<<"Flight EE0"<<value<<" Cancelled"<<endl;
			else
				cout<<"Flight EE"<<value<<" Cancelled"<<endl;
		}
		return root;//it is again very important because root of tree can be changed and we dont want to loss root of tree
	}
	//This method checl the routes and add the return route if it doesnot exist i.e. map array becoume symmetrical
	int* CHECKNADDRETURNROUTES(Graph& map){
		string i,j;
		int k,t,m=0;
		int *array=new int[400];
		for(k=0;k<20;k++){
			i=map.cities[k];
			for(t=0;t<20;t++){
				j=map.cities[t];
				if(map.SearchGroute(i,j)!=0 && map.SearchGroute(j,i)==0){ //check return is exist or not
					map.AddGroute(j,i,rand()%100+1);
					cout<<"( "<<j<<"--->" <<i<< ", " <<map.SearchGroute(j,i)<<") Return Route Added"<<endl;
					array[m]=100*(t+1)+k+1;//keep it an array for adding to bst
					m++;
				}



			}
		}
		return array; //for bst adding
	}
	//This method add the new return flights to bst according to information come from an array which returned from above function
	TreeNode* ADDRETURNFLIGHTS(BinaryTree &object,TreeNode* root,int *array){
		int i=0;
		while(array[i]!=0){
			root=object.AddFlight(root,array[i]);
			if(array[i]<1000)
				cout<<"Flight EE0"<<array[i]<<" Added"<<endl;
			else
				cout<<"Flight EE"<<array[i]<<" Added"<<endl;
			i++;
		}
		return root;
	}
	//This method display route option for direct,1 step ,2 step and no options
	void DISPLAYROUTEOPTIONS(Graph& map,string from,string to){
		int a;
		int b;
		int i,j;
		int flag=0;

		for(i=0;i<20;i++){
			if(from==map.cities[i])
				a=i;
			else if(to==map.cities[i])
				b=i;
		}//take the index values of cities
		if(map.SearchGroute(from,to)!=0){
			cout<<"Direct Trip:"<<endl;
			cout<<from<< " -> EE"<<(100*(a+1)+b+1) <<" -> " <<to <<"Fee: "<<map.SearchGroute(from,to)<<endl;
			flag=1;//for determination of no option
		}
		for(i=0;i<20;i++){
			if(map.SearchGroutewithCoordinate(a,i)!=0 && b!=i){ //scan the related row's  columns except destination
				if(map.SearchGroutewithCoordinate(i,b)!=0){ //check there is a route
				cout<<"1-stop Trips:"<<endl;
				cout<<from<< " -> EE"<<(100*(a+1)+i+1) <<" -> " <<map.cities[i]<<" -> EE"<<(100*(i+1)+b+1)<<" -> " <<to <<"Fee: "<<map.SearchGroute(from,map.cities[i])<<" + "<<map.SearchGroute(map.cities[i],to) <<endl;
				flag=1;//for determination of no option
				}
			}
		}

		for(i=0;i<20;i++){//find the routes from 1-2 then find the routes from 3-4 then check the there is a way 2-3
			for(j=0;j<20;j++){
				if(map.SearchGroutewithCoordinate(a,i)!=0 && b!=i){
					if(map.SearchGroutewithCoordinate(j,b)!=0 && a!=j){
						if(map.SearchGroutewithCoordinate(i,j)!=0){
							cout<<"2-stop Trips:"<<endl;
							cout<<from<< " -> EE"<<(100*(a+1)+i+1) <<" -> " <<map.cities[i]<<" -> EE"<<(100*(i+1)+j+1) <<" -> "<<map.cities[j]<<" -> EE"<<(100*(j+1)+b+1) <<" -> "<<to <<"Fee: "<<map.SearchGroute(from,map.cities[i])<<" + "<<map.SearchGroute(map.cities[i],map.cities[j])<<" + "<<map.SearchGroute(map.cities[j],to) <<endl;
						flag=1;//for determination of no option
						}

					}
				}
			}


		}
			if(flag==0)
				cout<<"NO OPTIONS"<<endl;
	}

    int main(){

    		Stack stack;
    	int i=0;
    	int j;
    	int *returnfligts=new int;
    	int *Mountlunewroutes=new int;
    	Graph berker;
        INITROUTEMAP(berker);
      	TreeNode* tree=NULL;
      	BinaryTree object;
		tree=INITFLIGHTPLAN(object);
		object.putoccupanciesfortree(tree);
		//object.inorder(tree);
		cout<<"----------------Month 1------------------:"<<endl;
		cout<<"Routes:"<<endl;
		berker.ListGroute();
		cout<<endl<<"Flights:"<<endl;
		object.inorder(tree);
		cout<<endl;
		cout<<"----------------Month 2------------------:"<<endl;
		cout<<endl<<"Monthly New Route Offers"<<endl;
		Mountlunewroutes=ADDMONTHLYNEWROUTES(berker,5); //new flights' numbers
		cout<<endl<<"Monthly New Flight Offers"<<endl;
		tree=ADDMONTHLYNEWFLIGHTS(object,Mountlunewroutes,5,tree);
		cout<<endl<<endl;
		cout<<"Routes:"<<endl;
		berker.ListGroute();
		cout<<endl<<"Flights:"<<endl;
		object.inorder(tree);
		cout<<"----------------Month 3------------------:"<<endl;
		cout<<endl<<"Monthly New Route Offers"<<endl;
		Mountlunewroutes=ADDMONTHLYNEWROUTES(berker,5); //new flights' numbers
		cout<<endl<<"Monthly New Flight Offers"<<endl;
		tree=ADDMONTHLYNEWFLIGHTS(object,Mountlunewroutes,5,tree); //5 new route is added
		cout<<endl<<endl;
		cout<<"Discarded Routes & Routes on Discount"<<endl;
		CANCELUNPOPULARFLIGHTS(object, 70,tree,berker,stack);
		cout<<endl<<"Cancelled Flights"<<endl;
		tree=removeunpopular(object,tree, stack);
		cout<<endl<<endl;
		cout<<"Routes:"<<endl;
		berker.ListGroute();
		cout<<endl<<"Flights:"<<endl;
		object.inorder(tree);
			cout<<"----------------Month 4------------------:"<<endl;
		cout<<endl<<"Monthly New Route Offers"<<endl;
		Mountlunewroutes=ADDMONTHLYNEWROUTES(berker,5); //new flights' numbers
		cout<<endl<<"Monthly New Flight Offers"<<endl;
		tree=ADDMONTHLYNEWFLIGHTS(object,Mountlunewroutes,5,tree);
		cout<<endl<<endl;
		cout<<"Discarded Routes & Routes on Discount"<<endl;
		CANCELUNPOPULARFLIGHTS(object, 70,tree,berker,stack);
		cout<<endl<<"Cancelled Flights"<<endl;
		tree=removeunpopular(object,tree, stack);
		cout<<endl<<endl;
		cout<<"Routes:"<<endl;
		berker.ListGroute();
		cout<<endl<<"Flights:"<<endl;
		object.inorder(tree);
			cout<<"----------------Month 5------------------:"<<endl;
		cout<<endl<<"Monthly New Route Offers"<<endl;
		Mountlunewroutes=ADDMONTHLYNEWROUTES(berker,5); //new flights' numbers
		cout<<endl<<"Monthly New Flight Offers"<<endl;
		tree=ADDMONTHLYNEWFLIGHTS(object,Mountlunewroutes,5,tree);
		cout<<endl<<endl;
		cout<<"Discarded Routes & Routes on Discount"<<endl;
		CANCELUNPOPULARFLIGHTS(object, 70,tree,berker,stack);
		cout<<endl<<"Cancelled Flights"<<endl;
		tree=removeunpopular(object,tree, stack);
		cout<<endl<<endl;
		cout<<"Routes:"<<endl;
		berker.ListGroute();
		cout<<endl<<"Flights:"<<endl;
		object.inorder(tree);
		cout<<"----------------Month 6------------------:"<<endl;
		cout<<endl<<"Monthly New Route Offers"<<endl;
		Mountlunewroutes=ADDMONTHLYNEWROUTES(berker,5); //new flights' numbers
		cout<<endl<<"Monthly New Flight Offers"<<endl;
		tree=ADDMONTHLYNEWFLIGHTS(object,Mountlunewroutes,5,tree);
		cout<<endl<<endl;
		cout<<"Discarded Routes & Routes on Discount"<<endl;
		CANCELUNPOPULARFLIGHTS(object, 70,tree,berker,stack);
		cout<<endl<<"Cancelled Flights"<<endl;
		tree=removeunpopular(object,tree, stack);
		cout<<"Missing Return Routes"<<endl;
		returnfligts=CHECKNADDRETURNROUTES(berker);
		cout<<"Missing Return Flights"<<endl;
		tree=ADDRETURNFLIGHTS(object,tree,returnfligts);
		cout<<endl<<endl;
		cout<<"Routes:"<<endl;
		berker.ListGroute();
		cout<<endl<<"Flights:"<<endl;
		object.inorder(tree);

		cout<<"-----------------------------------------------"<<endl; //I give a random routes it can be changed
		cout<<"One-way Trip Options for"<<berker.cities[0] <<"---> "<<berker.cities[6]<<":"<<endl;
		DISPLAYROUTEOPTIONS(berker,berker.cities[0],berker.cities[6]);
		cout<<"One-way Trip Options for"<<berker.cities[8] <<"---> "<<berker.cities[2]<<":"<<endl;
		DISPLAYROUTEOPTIONS(berker,berker.cities[8],berker.cities[2]);
		cout<<"One-way Trip Options for"<<berker.cities[10]<< "---> "<<berker.cities[15]<<":"<<endl;
		DISPLAYROUTEOPTIONS(berker,berker.cities[10],berker.cities[15]);
		cout<<"One-way Trip Options for"<<berker.cities[12]<< "---> "<<berker.cities[5]<<":"<<endl;
       	DISPLAYROUTEOPTIONS(berker,berker.cities[12],berker.cities[5]);
       	cout<<"One-way Trip Options for"<<berker.cities[7]<< "---> "<<berker.cities[16]<< ":"<<endl;
		DISPLAYROUTEOPTIONS(berker,berker.cities[7],berker.cities[16]);
        return 0;
    }
