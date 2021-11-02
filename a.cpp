// TODO: dont use auto always use iterator
#include <iostream>
#include <set>
#include <iterator>
#include <list>

using namespace std;

list<int>l;

struct box{
	list<int>::iterator it;
	bool operator<(const box &other)const{
		return this->it < other.it;
	}
};

set<box> st;


int main(){
	for(int i=0;i<10;++i){
		list<int>::iterator it = l.insert( l.begin(), i );
		st.insert( it );
	}
}
	
