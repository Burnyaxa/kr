#include "fileMethods.h"

void main(){
	vector <string> row = getRow();
	vector<string> numbers = getNumbers(row);
	vector<string> data = getData(numbers);
	createFiles(data, numbers);
	system("pause");
}