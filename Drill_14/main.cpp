#include "std_lib_facilities.h"

class B1 {
	
public:
	string name;
	B1(string n){
		name = n;
	}
	B1() {
		name = "";
	}
	virtual void vf() {
		std::cout << name << endl;
	}
	void f() {
		std::cout << name << endl;
	}
	virtual void pvf() = 0;
	
};
class D1 : public B1 {
public:
	D1(string m) {
		name = m;
	}
	D1() {

	}
	void vf() override{

	}
	// 4) 
	void f() {

	}
};
class D2 : public D1 {
public:
	D2(string h){
		name = h;
	}
	void pvf() override {

	}
	
};

class B2 : public B1 {
private:
	int g;
public:
	B2() {
	
	}
	B2(int gg) {
		g = gg;
	}
	virtual void pvf() = 0;
};
class D21: public B2 {
private:
	string damem;
public:
	D21(string h) {
		damem = h;
	}
	void pvf() override {
		std::cout << damem << endl;
	}
};
class D22 :public B2 {
private:
	int damo;
public:
	D22(int j) {
		damo = j;
	}
	void pvf() override {
		std::cout << damo << endl;
	}
	
};




void f(B2& mek) {
	mek.pvf();
}

int main() {
	/*
	// 1) B1 objektum es funkciok 1)
	B1 ok("Kokk");
	ok.f();
	ok.vf();
	// 2) D1 objektum es funk  

	D1 nonn("Dangu");
	nonn.f();
	nonn.vf();

	// 3) B1 referencia "monka" es arra meghivni a funcokat 
	B1& monka= nonn;
	monka.f();
	monka.vf();
	*/

	D2 macska("ver");
	macska.f();
	macska.vf();
	macska.pvf();
	
	
	D21 elso("fooker");
	D22 masodik(5);

	f(elso);
	f(masodik);
}
