#include "fileMethods.h"

vector <string> getRow(){
	vector <string> text;
	ifstream fin("text.txt");
	string row;
	while (!fin.eof()){
		getline(fin, row);
		text.push_back(row);
	}
	return text;
}

vector <string> getNumbers(vector <string> text){
	string num;
	vector <string> numbers;
	for (int i = 0; i < text.size(); i++){
		for (int j = 0; j < text[i].size(); j++){
			if (isdigit(text[i][j])){
				num += text[i][j];
			}
			if (!isdigit(text[i][j]) || j == text[i].size() - 1){
				numbers.push_back(num);
				num.clear();
			}
		}
	}
	return numbers;
}

vector<string> getData(vector <string> numbers){
	vector<string> numberData;
	string data, num, postfix, prefix, number, numberPrefix, numberPostfix;
	int des;
	for (int i = 0; i < numbers.size(); i++){
		num = numbers[i];
		des = num.size();
		while (true){
			if (!des){
				numberData.push_back(data);
				data.clear();
				break;
			}
			if (des == 3){
				postfix = "hundred";
				data += getNumPrefix(num[3]);
				data+= postfix;
				des--;
				continue;
			}
			if (des < 3){
				if (des == 2){
					string sum;
					sum = num[5] + num[4];
					if (stoi(sum) < 12 && stoi(sum) >= 10){
						switch (num[5] + num[4]){
						case '10':
							prefix = "ten";
							break;
						case '11':
							prefix = "eleven";
							break;
						case '12':
							prefix = "twelve";
							break;
						}
						data += prefix;
						des -= 2;
						continue;
					}
					if (stoi(sum) > 12 && stoi(sum) < 20){
						numberPostfix = "teen";
						switch (num[5] + num[4]){
						case '13':
							numberPrefix = "thirt";
							break;
						case '14':
							numberPrefix = "four";
							break;
						case '15':
							numberPrefix = "fif";
							break;
						case '16':
							numberPrefix = "six";
							break;
						case '17':
							numberPrefix = "seven";
							break;
						case '18':
							numberPrefix = "eight";
							break;
						case '19':
							numberPrefix = "nine";
							break;
						}
						data += numberPrefix;
						data +=numberPostfix;
						des -= 2;
						continue;
					}
					if (stoi(sum) >= 20){
						data += getNumPrefix(num[5]);
						data += getNumPostfix(num[4]);
						des -= 2;
						continue;
					}
				}
				if (des == 1){
					postfix = " thousand";
					data += getNumPostfix(num[4]);
					data +=postfix;
					des--;
					continue;
				}
			}
			if (des >  3){
				postfix = " thousand";
				if (des == 5){
					string sum;
					sum = num[5] + num[4];
					if (stoi(sum) < 12 && stoi(sum) >= 10){
						switch (num[5] + num[4]){
						case '10':
							prefix = "ten";
							break;
						case '11':
							prefix = "eleven";
							break;
						case '12':
							prefix = "twelve";
							break;
						}
						data += prefix;
						data +=postfix;
						des -= 2;
						continue;
					}
					if (stoi(sum) > 12 && stoi(sum) < 20){
						numberPostfix = "teen";
						switch (num[5] + num[4]){
						case '13':
							numberPrefix = "thirt";
							break;
						case '14':
							numberPrefix = "four";
							break;
						case '15':
							numberPrefix = "fif";
							break;
						case '16':
							numberPrefix = "six";
							break;
						case '17':
							numberPrefix = "seven";
							break;
						case '18':
							numberPrefix = "eight";
							break;
						case '19':
							numberPrefix = "nine";
							break;
						}
						data += numberPrefix;
						data += numberPostfix;
						data += postfix;
						des -= 2;
						continue;
					}
					if (stoi(sum) >= 20){
						data += getNumPrefix(num[5]);
						data += getNumPostfix(num[4]);
						data += postfix;
						des -= 2;
						continue;
					}
				}
				if (des == 4){
					postfix = " thousand";
					data += getNumPostfix(num[4]);
					data += postfix;
					des--;
					continue;
				}
			}
		}
	}
	return numberData;
}

void createFiles(vector <string> data, vector<string> numbers){
	string path;
	for (int i = 0; i < numbers.size(); i++){
		path = numbers[i] + ".txt";
		ofstream fout(path);
		fout << data[i];
		fout.close();
	}
}

string getNumPostfix(char N){
	string postfix;
	switch (N){
	case '0':
		postfix = "";
		break;
	case '1':
		postfix = "one";
		break;
	case '2':
		postfix = "two";
		break;
	case '3':
		postfix = "three";
		break;
	case '4':
		postfix = "four";
		break;
	case '5':
		postfix = "five";
		break;
	case '6':
		postfix = "six";
		break;
	case '7':
		postfix = "seven";
		break;
	case '8':
		postfix = "eight";
		break;
	case '9':
		postfix = "nine";
		break;
	}
	return postfix;
}

string getNumPrefix(char N){
	string prefix;
	switch (N){
	case '2':
		prefix = "twenty";
		break;
	case '3':
		prefix = "thirty";
		break;
	case '4':
		prefix = "forty";
		break;
	case '5':
		prefix = "fifty";
		break;
	case '6':
		prefix = "sixty";
		break;
	case '7':
		prefix = "seventy";
		break;
	case '8':
		prefix = "eighty";
		break;
	case '9':
		prefix = "ninety";
		break;
	}
	return prefix;
}

