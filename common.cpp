#include <iostream>

using namespace std;

void info(int f){

	switch(f){
		case 1: cout << "Enter number of vertexes and edges: "; break;
		case 2: cout << "Error! Try again: "; break;
		case 3: cout << "Choose:\n1) Keyboard.\n2>) Random.\nYour choise: "; break;
		case 4: cout << "Enter vertex 1, vertex 2 and weight: "; break;
		case 5: cout << "Enter number of first vertex: "; 
	}
}

int get_data(){
	int temp;
	while (1){
		std::cin >> temp;
		if (std::cin.fail()) info(2);
		else return temp;
	}
	return temp;
}

