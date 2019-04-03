#include "fileMethods.h"

vector <string> getText(){
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
	string data, num, temp, postfix, prefix, number, numberPrefix, numberPostfix;
	int des;
	for (int i = 0; i < numbers.size(); i++){
		temp = numbers[i];
		num = reverseString(temp);
		des = num.size();
		while (true){
			if (!des){
				numberData.push_back(data);
				data.clear();
				break;
			}
			if (des == 3){
				if (num[2] == '0'){
					des--;
					continue;
				}
				postfix = " hundred ";
				data += getNumPostfix(num[2]);
				data += postfix;
				des--;
				continue;
			}
			if (des < 3){
				if (des == 2){
					if (num[1] == '0'){
						des --;
						continue;
					}
					char sum[2] = { num[1], num[0] };
					if (stoi(sum) <= 12 && stoi(sum) >= 10){
						switch (stoi(sum)){
						case 10:
							prefix = " ten ";
							break;
						case 11:
							prefix = " eleven ";
							break;
						case 12:
							prefix = " twelve ";
							break;
						}
						data += prefix;
						des -= 2;
						continue;
					}
					if (stoi(sum) > 12 && stoi(sum) < 20){
						numberPostfix = "teen";
						switch (num[1] + num[0]){
						case '13':
							numberPrefix = " thirt ";
							break;
						case '14':
							numberPrefix = " four ";
							break;
						case '15':
							numberPrefix = " fif ";
							break;
						case '16':
							numberPrefix = " six ";
							break;
						case '17':
							numberPrefix = " seven ";
							break;
						case '18':
							numberPrefix = " eight ";
							break;
						case '19':
							numberPrefix = " nine ";
							break;
						}
						data += numberPrefix;
						data +=numberPostfix;
						des -= 2;
						continue;
					}
					if (stoi(sum) >= 20){
						data += getNumPrefix(num[1]);
						data += getNumPostfix(num[0]);
						des -= 2;
						continue;
					}
				}
				if (des == 1){
					data += getNumPostfix(num[0]);
					des--;
					continue;
				}
			}
			if (des >  3){
				if (des == 6){
					if (num[5] == '0'){
						des--;
						continue;
					}
					postfix = " hundred ";
					data += getNumPostfix(num[5]);
					data += postfix;
					des--;
					continue;
				}
				postfix = " thousand ";
				if (des == 5){
					char sum[2] = { num[4], num[3] };
					if (stoi(sum) <= 12 && stoi(sum) >= 10){
						switch (stoi(sum)){
						case 10:
							prefix = "ten ";
							break;
						case 11:
							prefix = "eleven ";
							break;
						case 12:
							prefix = "twelve ";
							break;
						}
						data += prefix;
						data +=postfix;
						des -= 2;
						continue;
					}
					if (stoi(sum) > 12 && stoi(sum) < 20){
						numberPostfix = "teen ";
						switch (stoi(sum)){
						case 13:
							numberPrefix = "thirt";
							break;
						case 14:
							numberPrefix = "four";
							break;
						case 15:
							numberPrefix = "fif";
							break;
						case 16:
							numberPrefix = "six";
							break;
						case 17:
							numberPrefix = "seven";
							break;
						case 18:
							numberPrefix = "eight";
							break;
						case 19:
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
						data += getNumPrefix(num[4]);
						data += getNumPostfix(num[3]);
						data += postfix;
						des -= 2;
						continue;
					}
					data += postfix;
					des -= 2;
					continue;
				}
				if (des == 4){
					postfix = " thousand ";
					data += getNumPostfix(num[3]);
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
	string numPostfix;
	switch (N){
	case '0':
		numPostfix = "";
		break;
	case '1':
		numPostfix = "one ";
		break;
	case '2':
		numPostfix = "two ";
		break;
	case '3':
		numPostfix = "three ";
		break;
	case '4':
		numPostfix = "four ";
		break;
	case '5':
		numPostfix = "five ";
		break;
	case '6':
		numPostfix = "six ";
		break;
	case '7':
		numPostfix = "seven ";
		break;
	case '8':
		numPostfix = "eight ";
		break;
	case '9':
		numPostfix = "nine ";
		break;
	}
	return numPostfix;
}

string getNumPrefix(char N){
	string prefix;
	switch (N){

	case '2':
		prefix = "twenty ";
		break;
	case '3':
		prefix = "thirty ";
		break;
	case '4':
		prefix = "forty ";
		break;
	case '5':
		prefix = "fifty ";
		break;
	case '6':
		prefix = "sixty ";
		break;
	case '7':
		prefix = "seventy ";
		break;
	case '8':
		prefix = "eighty ";
		break;
	case '9':
		prefix = "ninety ";
		break;
	}
	return prefix;
}

string reverseString(string num){
	string temp;
	for (int i = 0; i < num.size(); i++){
		temp += num[num.size() - i - 1];
	}
	return temp;
}

