#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	Person(const string& name, const string& occupation): Name(name),Occupation(occupation) {}
	virtual void Walk(const string& destination) const {
		cout << Occupation <<": " << Name << " walks to: " << destination << endl;
	};
public:
	const string Name;
	const string Occupation;
};

class Student: public Person {
public:
	Student(const string& name, const string& favouriteSong): Person(name,"Student"), FavouriteSong(favouriteSong){}

    void Learn() const {
        cout << Occupation <<": " << Name << " learns" << endl;
    }

    void SingSong() const {
		cout << Occupation << ": " << Name << " sings a song: " << FavouriteSong << endl;
	}

    void Walk(const string& destination) const override {
    	Person::Walk(destination);
    	SingSong();
    }



public:
    const string FavouriteSong;
};


class Teacher: public Person {
public:

	Teacher(const string& name, const string& subject): Person(name,"Teacher"), Subject(subject){};

    void Teach() {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

public:
    const string Subject;
};


class Policeman : public Person {
public:
	Policeman(const string& name): Person(name,"Policeman"){};

    void Check(const Person& t) {
        cout << Occupation <<": " << Name << " checks "<< t.Occupation
        		<< ". " << t.Occupation << "'s name is: " << t.Name << endl;
    }
};


void VisitPlaces(const Person& person,const vector<string>& places) {
	for (const auto& p : places) {
		person.Walk(p);
	}
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}

