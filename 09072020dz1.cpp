/*
Задание 1.
Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай».
Create a base class "Pet" and derived classes "Dog", "Cat", "Parrot".
С помощью конструктора установить имя каждого животного и его характеристики.
*/
#include <iostream>
using namespace std;

class Pet {//Домашнее животное
private:
	char* NAME; // имя 
	char* SEX; // пол
	char* COLOR; // цвет
	int AGE; // возраст
public:
	Pet() : NAME(nullptr), SEX(nullptr), COLOR(nullptr), AGE(0) { }
	Pet(const char* name, const char* sex, const char* color, int age) {
		NAME = _strdup(name);
		SEX = _strdup(sex);
		COLOR = _strdup(color);
		AGE = age;
	}
	virtual	~Pet() {
		delete[]NAME;
		delete[]SEX;
		delete[]COLOR;
	}
	virtual void Sound() = 0 {}
	virtual void Show() = 0 {
		cout << "NAME : " << NAME << endl;
		cout << "SEX : " << SEX << endl;
		cout << "COLOR : " << COLOR << endl;
		cout << "Age: " << AGE << endl;
	}
	virtual void Type() = 0 {}
	void SetNAME(const char* name) { delete[]NAME; NAME = _strdup(name); }
	void SetSEX(const char* sex) { delete[]SEX; SEX = _strdup(sex); }
	void SetCOLOR(const char* color) { delete[]COLOR; COLOR = _strdup(color); }
	void SetAGE(int age) { AGE = age; };
};

class Dog :public Pet {
private:
	char* DOG_SUBSPECIES; // название подвида
public:
	Dog() : DOG_SUBSPECIES(nullptr) { }
	Dog(const char* name, const char* sex, const char* color, int age, const char* dog_subspecies) :Pet(name, sex, color, age) {
		DOG_SUBSPECIES = _strdup(dog_subspecies);
	}
	~Dog() {
		delete[]DOG_SUBSPECIES;
	}
	void Sound() {
		cout << "woof - woof !" << endl;
	}
	void Show() {
		Pet::Show();
	}
	void Type() {
		cout << "Name of dog subspecies : " << DOG_SUBSPECIES << endl;
	}
	void SetDOG_SUBSPECIES(const char* dog_subspecies) { delete[]DOG_SUBSPECIES; DOG_SUBSPECIES = _strdup(dog_subspecies); }
};

class Cat :public Pet {
private:
	char* CAT_SUBSPECIES; // название подвида CATSUBSPECIES
public:
	Cat() : CAT_SUBSPECIES(nullptr) { }
	Cat(const char* name, const char* sex, const char* color, int age, const char* cat_subspecies) :Pet(name, sex, color, age) {
		CAT_SUBSPECIES = _strdup(cat_subspecies);
	}
	~Cat() {
		delete[]CAT_SUBSPECIES;
	}
	void Sound() {
		cout << "meow - meow !" << endl;
	}
	void Show() {
		Pet::Show();
	}
	void Type() {
		cout << "Name of cat subspecies : " << CAT_SUBSPECIES << endl;
	}
	void SetCAT_SUBSPECIES(const char* cat_subspecies) { delete[]CAT_SUBSPECIES; CAT_SUBSPECIES = _strdup(cat_subspecies); }
};

class Parrot :public Pet { // попугай
private:
	char* PARROT_SUBSPECIES; // название подвида
public:
	Parrot() : PARROT_SUBSPECIES(nullptr) { }
	Parrot(const char* name, const char* sex, const char* color, int age, const char* parrot_subspecies) :Pet(name, sex, color, age) {
		PARROT_SUBSPECIES = _strdup(parrot_subspecies);
	}
	~Parrot() {
		delete[]PARROT_SUBSPECIES;
	}
	void Sound() {
		cout << "Hннello ! Would you liiike some teeeea? !" << endl;
	}
	void Show() {
		Pet::Show();
	}
	void Type() {
		cout << "Name of parrot subspecies : " << PARROT_SUBSPECIES << endl;
	}
	void SetPARROT_SUBSPECIES(const char* parrot_subspecies) { delete[]PARROT_SUBSPECIES; PARROT_SUBSPECIES = _strdup(parrot_subspecies); }
};

int main() {
	Dog AA("Tuzik", "man", "gray", 3, "Dvorovoy");

	cout << "\tDog : " << endl;
	Dog A;
	A.SetNAME("Lord");
	A.SetSEX("M");
	A.SetCOLOR("Black");
	A.SetAGE(5);
	A.SetDOG_SUBSPECIES("Doberman");
	A.Type();
	A.Show();

	cout << "\n\tCat : " << endl;
	Cat B;
	B.SetNAME("Musja");
	B.SetSEX("W");
	B.SetCOLOR("White");
	B.SetAGE(9);
	B.SetCAT_SUBSPECIES("Vesloyhaja");
	B.Type();
	B.Show();

	cout << "\n\tParrot : " << endl;
	Parrot C;
	C.SetNAME("Zhylik");
	C.SetSEX("M");
	C.SetCOLOR("Gray");
	C.SetAGE(19);
	C.SetPARROT_SUBSPECIES("Ara");
	C.Type();
	C.Show();
}
