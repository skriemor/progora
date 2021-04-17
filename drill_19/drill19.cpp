#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <exception>
//forward dec-ek
template <class T> class S;
template<class T> std::ostream& operator<<(std::ostream& out, S<T> varo);
template<class T> std::istream& operator>>(std::istream& in, S<T>& vari);

//template struct
template <class T> struct S {

private:
	T val;
public:
	S(T i = { }) : val(i) {};

	T& get();

	void set(T inputvalue);

	T operator[](T i) const {
		return i;
	}
	

	T& operator[](T i) {
		return i;
	}

	template<class T> friend std::istream& operator>>(std::istream& in, S<T>&);
	template<class T> friend std::ostream& operator<<(std::ostream& out, S<T>);



	template<class T> friend void read_val(T& v);
};


template<class T> T& S<T>::get() {
	return val;
}

template<class T> void S<T>::set(T inputvalue) {
	val = inputvalue;
}

template<class T> std::istream& operator>>(std::istream& in, S<T>& vari) {
	in >> vari.val;
	return in;
}
template<class T> std::ostream&  operator<<(std::ostream& out,  S<T> varo) {
	out << varo.val;
return out;
}




template<class T> void read_val(T& v) {
	std::cin >> v;
}

int main(){
	S<int> a = 1;
	S<int> h = 1;
	S<double> b = 2.2;
	S<char> c ('c');
	S<std::string> d = std::string("egy");
	S<std::vector<int>> e;
	e.set({ 1,2,3 });

	//std::cout << a.val << std::endl;  //val privatta valt; ilyen modon mar nem olvashato

	//std::cout << a.get() << std::endl; //get fuggvenyek
	//std::cout << b.get() << endl;
	//std::cout << c.get() << endl;
	d.set(std::string("fmumblerap"));
	//std::cout << d.get() << endl;
	
	for (auto s : e.get()) {
		std::cout << s << " ";
	}std::cout << std::endl;

	std::cout << "integer:a  felveve a 12 erteket: \n";
	std::cout << a[12] << std::endl;
	std::cout << "integer:a  erteke amugy: \n";
	std::cout << a << std::endl;
	
	//cin >> a;
	//cout << a<<endl;
	
	//read_val tesztelese
	std::cout << "Kerem irjon be 1 integert: \n";
	read_val(a);
	std::cout << "Kerem irjon be 1 double erteket (#.##...): \n";
	read_val(b);
	std::cout << "Kerem irjon be 1 char erteket (egyetlen karakter): \n";
	read_val(c); 

	//std::cout << e;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}