#include <iostream>
#include <string> 
#include <vector>
#include <map>
#include <tuple>
using namespace std;

int main() {
string name = "Mira";
vector<int> scores = {85, 90, 95};
map < string, int >  ageMap; 
ageMap ["Alice"] = 30;
ageMap["Bob" ] = 25;

// std:: string
// std:: vector
// std:: map
tuple<string, int, bool> person = {"John", 40, true}; // std: : tuple

cout << "Name: "<< name << endl;
cout << "First score: " << scores [0] << endl;
cout << "Bob's age: " << ageMap["Bob"] << endl;
cout << "Tuple name: " << get<0>(person) << endl;
return 0; 

}