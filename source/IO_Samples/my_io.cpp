#include <iostream>
#include <fstream>

using namespace std;


int main () {

string filename = "mytxt.txt";

ofstream txtcreator(filename);

txtcreator << "Put this line in.\n";
txtcreator << "Dis too ;-; \n";


txtcreator.close();



return 0;
}
