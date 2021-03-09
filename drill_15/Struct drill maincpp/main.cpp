#include "std_lib_facilities.h"



std::locale loc;
bool badchar;

bool nemcsakalfa(std::string g){
	badchar = false;
	for (std::string::iterator i = g.begin(); i != g.end(); ++i) {
		if (!std::isalpha(*i, loc)) {
			badchar = true;
			break;
		}
	}
	return badchar;
}




struct Person {
	
		Person(std::string inname,std::string secondname, int innage)  {

			if (innage < 150 && innage>0)age = innage;
			else error("Nem jo kor");

			if (!nemcsakalfa(inname)) name = inname;
			else error("Nem jo nev"); 
			
			if (!nemcsakalfa(secondname)) second_name = secondname;
			else error("Nem jo nev");
			
		}
	
	
private:
	string name, 
		second_name;
	int age;
	
public:
	
	const void set_name(string inname) {
		name = inname;
	}
	const void set_age(int inage) {
		age = inage;
	}
	const void set_second_name(int iname) {
		second_name = iname;
	}
	string get_name() {
		return name;
	}
	string get_second_name() {
		return second_name;
	}
	int get_age() {
		return age;
	}
};
int main() {
	try {
		Person person1("Goofy","Goofer", 63);

		std::cout << person1.get_name() << " " <<person1.get_second_name() <<" "<< person1.get_age() << endl;

		
		std::cout << "input the first name" << endl;
		String inputname;
		std::cin >> inputname;

		std::cout << "input the second name" << endl;
		String inputsname;
		std::cin >> inputsname;

		std::cout << "input the age" << endl;
		int inputage;
		std::cin >> inputage;
		Person inputperson(inputname,inputsname,inputage);
		std::cout << endl << inputperson.get_name() <<" " << inputperson.get_second_name()<< " " << inputperson.get_age() <<"\n"<< endl;

		
		//Person vektor
		std::cout <<endl<< "A filebol olvasott nevek (namesAges.txt): " << endl;
		vector<Person> emberek;
		string nevin,snevin, sor; int korin;
		string deli = "\t";
		string deli2 = " ";
		vector<string> adatok;
		istringstream sorstream;
		ifstream brr("namesAges.txt");
		if (brr.is_open()) {
			while (getline(brr, sor)) {
				sorstream.clear();
				sorstream.str(sor);
				copy(istream_iterator<string>(sorstream), istream_iterator<string>(), back_inserter(adatok));
				nevin = adatok[0];
				snevin = adatok[1];
				korin = stoi(adatok[2]);
				emberek.push_back(Person(nevin,snevin,korin) );
				adatok.clear();
			}
			brr.close();
		}
		for (Person p : emberek) std::cout << p.get_name()<<" "+p.get_second_name()<<" aki "<<p.get_age()<<" eves"<<endl;









	}
	
	catch (runtime_error& e) {
		cerr << "runtime error: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
}