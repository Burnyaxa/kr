#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector <string> getRow();
vector <string> getNumbers(vector <string> text);
vector<string> getData(vector <string> numbers);
void createFiles(vector <string> data, vector<string> numbers);
string getNumPostfix(char N);
string getNumPrefix(char N);

