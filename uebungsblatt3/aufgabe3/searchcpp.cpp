#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char * argv[]){
	
	if(argc < 2){
		cout << "Kein Suchbegriff eingegeben!\n" << endl;
		return EXIT_FAILURE;
	}
	
	string needle = argv[1];
	
   ifstream infile("/home/SWT-LABOR/2060696/nethome/SeCo/20seco04/uebungsblatt3/aufgabe3/allkeys.txt");
   
   string line;
   size_t found;
   string::size_type pos;
   string current_number_as_hex;
   unsigned int current_number_as_dez;
   
   string max_number_as_hex;
   unsigned int max_number_as_dez = 0;
   
   unsigned int counter = 0;
   
   while(getline(infile, line)){
	
		if(line.front() == '#'){
			continue;
		}
		if(line.front() == '\n'){
			continue;
		}
		if(line.front() == '@'){
			continue;
		}
		
		found = line.find(needle);
		
		if (found!=string::npos){
			counter++;
			//cout << "first 'needle' found at: " << found << '\n';
			pos = line.find(' ');
			
			if (pos != string::npos){
				current_number_as_hex = line.substr(0, pos);
				current_number_as_dez = stoul(current_number_as_hex, nullptr, 16);
				
				if(current_number_as_dez > max_number_as_dez){
					max_number_as_dez = current_number_as_dez;
					max_number_as_hex = current_number_as_hex;
				}
			}
			
		}
			
		
		
		
	}
	if(counter > 0){
		cout << counter << " - " <<  max_number_as_hex << " - " << max_number_as_dez << endl;
	}else{
		cout << "Nix" << endl;
	}

}
