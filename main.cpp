#include "fileMethods.h"

void main(){
	vector <string> row = getText();
	vector<string> numbers = getNumbers(row);
	vector<string> data = getData(numbers);
	createFiles(data, numbers);
	system("pause");
}