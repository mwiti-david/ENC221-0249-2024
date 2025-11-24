#include <iostream>
#include <string>
using namespace std;
class myneighbour {
  public:
      string name;
      string height;
      string complexion;
      string mood;
      int age;
};
int main( ) {

    myneighbour neighbour;
    neighbour.name=" davis";
    neighbour.height=" 5 foot";
    neighbour.complexion=" dark ";
    neighbour.mood=" jovial";
    neighbour.age= 20;
    cout <<"my neighbour is"<<neighbour.name<<endl;
    cout <<"my neighbour is"<<neighbour.height<<" tall"<<endl;
    cout <<"my neighbour is"<<neighbour.complexion<<endl;
    cout <<"my neighbour is"<<neighbour.mood<<endl;
    cout <<"my neighbour is"<<neighbour.age<< " years old"<< endl;

    return 0;

};
