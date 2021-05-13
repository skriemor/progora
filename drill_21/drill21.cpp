#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <fstream>
#include <map>
#include <numeric>
using namespace std;

struct item {
	string name;
	int iid;
	double value;
public:
	item(string n = "", int i = 0, double d = 0.0) : name(n), iid(i), value(d) {};
};
template<class A>ostream& operator<<(ostream& k, vector<A> iv) {
	for (auto g : iv) {
		k <<g << endl;
	}
	return k;
}
ostream& operator<<(ostream& k, vector<item> iv) {
	for (auto g : iv) {
		k << g.name << "\t|" << g.iid << "\t|" << g.value << endl;
	}
	return k;
}

ostream& operator<<(ostream& k, list<item> iv) {
	for (auto g : iv) {
		k << g.name << "\t|" << g.iid << "\t|" << g.value << endl;
	}
	return k;
}

template<class A, class B>ostream& operator<<(ostream& k, map<A,B> iv) {
	for (auto g : iv) {
		k << g.first << "\t|" << g.second << endl;
	}
	return k;
}
template<class A>void read_value_File(string filename, vector<A>& h) {
	A n;
	ifstream enn{ filename };
	while (enn >> n ) {
		h.push_back(n);
	}
}
void read_item_File(string filename, vector<item>& h) {
	string n;
	int i;
	double d;
	ifstream enn{ filename };
	while (enn >> n >> i >> d) {
		h.push_back(item(n,i,d));
	}
}
struct match_name {
	string h;
public:
	match_name(string f) :h(f) {};
	bool operator()(item g) {
		return g.name == h;
	}
};
struct match_iid {
	int h;
public:
	match_iid(int f) :h(f) {};
	bool operator()(item g) {
		return g.iid == h;
	}
};
struct comp_name {
	bool operator()(const item& a, const item& b) const {
		return a.name < b.name;
	}
};
struct comp_iid {
	bool operator()(const item& a, const item& b) const {
		return a.iid < b.iid;
	}
};
struct comp_value {
	bool operator()(const item& a, const item& b) const {
		return a.value > b.value;
	}
};
void read_into_map(map<string,int>& map1) {
	string first; int second;
	while (cin >> first >> second) {
		map1.insert(pair<string, int>(first, second));
	}
}
int sum_that(map<string, int>& g) {
	int sum=0;
	for (auto h : g) sum += h.second;
	return sum;
}
int main(){
	vector<item> vi;
	read_item_File("inputfile.txt", vi);
	//----------------------------
	list<item> vl;
	copy(vi.begin(), vi.end(), back_inserter(vl));
	//----------------------------
	cout <<"Before sort\n"<< vi << endl;
	sort(vi.begin(), vi.end(), [](item a, item b)->bool{return a.name < b.name; });
	cout <<"After sort by name\n"<< vi << endl;
	sort(vi.begin(), vi.end(), [](item a, item b)->bool {return a.iid < b.iid; });
	cout << "After sort by iid\n" << vi << endl;
	sort(vi.begin(), vi.end(), [](item a, item b)->bool {return a.value > b.value; });
	cout << "After sort by value in descending order\n" << vi << endl;
	vi.insert(vi.begin(), item("horse shoe", 99, 12.34));
	vi.insert(vi.begin(), item("Canon S400", 9988, 499.95));

	//erase lambdaval
	vi.erase(find_if(vi.begin(), vi.end(), [](item a)->bool {return a.name == "egy"; }));
	vi.erase(find_if(vi.begin(), vi.end(), [](item a)->bool {return a.iid == 3; }));
	//erase function class-sel
	vi.erase(find_if(vi.begin(), vi.end(), match_name("ketto") ));
	vi.erase(find_if(vi.begin(), vi.end(), match_iid(4)));
	cout << "After adding 2, then erasing 4 values \n" << vi;

	
	vl.sort(comp_name());
	vl.sort(comp_iid());
	vl.sort(comp_value());
	cout << "After sorting list:\n"<< vl;
	vl.erase(find_if(vl.begin(), vl.end(), match_name("ketto")));
	vl.erase(find_if(vl.begin(), vl.end(), match_name("egy")));
	vl.erase(find_if(vl.begin(), vl.end(), [](item a)->bool {return a.iid == 3; }));
	vl.erase(find_if(vl.begin(), vl.end(), [](item a)->bool {return a.iid == 4; }));
	cout << "After erasing from list:\n" << vl;
	vl.insert(vl.begin(), item("horse shoe", 99, 12.34));
	vl.insert(vl.begin(), item("Canon S400", 9988, 499.95));
	cout << "After inserting 2 values to list:\n" << vl;

	//map resze a drillnek
	map<string, int> msi;
	msi.insert(pair<string, int>("lecture",21));
	msi.insert(pair<string, int>("ketto", 2));
	msi.insert(pair<string, int>("harom", 3));
	msi.insert(pair<string, int>("negy", 4));
	msi.insert(pair<string, int>("ot", 5));
	msi.insert(pair<string, int>("hat", 6));
	msi.insert(pair<string, int>("het", 7));
	msi.insert(pair<string, int>("nyolc", 8));
	msi.insert(pair<string, int>("kilenc", 9));
	msi.insert(pair<string, int>("tiz", 10));

	cout <<"\nA map coutolva:\n"<< msi;

	msi.erase(find_if(msi.begin(), msi.end(), [](pair<string, int> g)->bool {return g.first == "lecture"; }));
	cout << "A map coutolva miutan eraseltem \"lecturet\":\n" << msi;

	cout << "\nIrjon be egy string es egy integer part,\na beolvasasnak akkor van vege,\nha int erteknek nem numerikus erteket ad(pl. \"f f\")\n";
	read_into_map(msi);
	cout << "A map coutolva beolvasas utan:\n" << msi;
	int e;
	
	cout << sum_that(msi) <<" az elemek ertekeinek osszege.\n";

	map<int, string> mis;
	for (auto a : msi) {
		mis.insert(pair<int, string>(a.second, a.first));
	}
	
	cout <<"\nA \"mis map coutolva:\"\n"<<mis;


	
	//vektoros feladatok

	vector<double> vd;
	read_value_File("inputfile2.txt", vd);
	cout << "Vd vektor beolvasva:\n" << vd;

	vector<int>vii(vd.size());
	transform(vd.begin(), vd.end(), vii.begin(), [](double x) {return (int)x; });
	cout << "Vi vektor copy utan:\n" << vii;

	cout << "\nA vektorok parban\n";
	for (int i = 0; i < vd.size(); i++) {
		cout << vd[i] << " " << vii[i] << endl;
	}

	cout <<"\nVd sum-ja:\n"<< accumulate(vd.begin(),vd.end(), 0.0);


	cout << "\nVd es vi kulonbsege:\n" << accumulate(vd.begin(), vd.end(), 0.0) - accumulate(vii.begin(),vii.end(),0) << endl;

	reverse(vd.begin(), vd.end());

	double mean = accumulate(vd.begin(), vd.end(), 0.0) / vd.size();
	cout << "\nAz atlaga vd vektor elemeinek:\n" <<mean << endl;

	vector<double> vd2(vd.size());
	copy_if(vd.begin(), vd.end(), vd2.begin(), [mean](int x)->bool {return x < mean; });
	cout << "\nVd2 vektor elemei copy_if utan:\n" << vd2 <<endl;

	sort(vd.begin(), vd.end());
	cout << "\nVd vektor elemei sort utan:\n" << vd << endl;

	do {
		cout << "\n Irjon be egy betut a kilepeshez\n";
	} while (cin >> e);

}