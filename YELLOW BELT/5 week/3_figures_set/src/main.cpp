#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Figure {
public:
	Figure(const string& name): name_(name){}
	virtual string Name() = 0;
	virtual float Perimeter() = 0;
	virtual float Area() = 0;
protected:
	const string name_;
};

class Rect: public Figure {
public:
	Rect(const float& height,
		 const float& width):
			 Figure("RECT"),
			 height_(height),
			 width_(width) {}
	virtual string Name() override {
		return name_;
	}
	virtual float Perimeter() override {
		return 2*(height_+width_);
	}
	virtual float Area() override {
		return height_*width_;
	}
private:
	const float height_;
	const float width_;
};

class Triangle: public Figure {
public:
	Triangle(const float& a,
		 const float& b,
		 const float& c):
			 Figure("TRIANGLE"),
			 a_(a),
			 b_(b),
			 c_(c){}
	virtual string Name() override {
		return name_;
	}
	virtual float Perimeter() override {
		return a_+b_+c_;
	}
	virtual float Area() override {
		float p = Perimeter() / 2;
		return sqrt(p*(p-a_)*(p-b_)*(p-c_));
	}
private:
	const float a_;
	const float b_;
	const float c_;
};

class Circle: public Figure {
public:
	Circle(const float& r):
			 Figure("CIRCLE"),
			 r_(r) {}
	virtual string Name() override {
		return name_;
	}
	virtual float Perimeter() override {
		return 2*3.14*r_;
	}
	virtual float Area() override {
		return 3.14*r_*r_;
	}
private:
	const float r_;
};

shared_ptr<Figure> CreateFigure(istringstream& ss) {
	string figure;
	ss >> figure;
	if (figure == "RECT") {
		int h,w;
		ss >> h >> w;
		return make_shared<Rect>(h,w);
	} else if (figure == "CIRCLE") {
		int r;
		ss >> r;
		return make_shared<Circle>(r);
	}
	else {
		int a,b,c;
		ss >> a >> b >> c;
		return make_shared<Triangle>(a,b,c);
	}
}


int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
