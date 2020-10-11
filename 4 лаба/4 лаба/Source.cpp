//figure
#include <iostream>
#include <cmath>
using namespace std;
class cfigure {
protected:
	int angle1;
	int angle2;
	int angle3;
	int angle4;
public:
	cfigure() : angle1(0), angle2(0), angle3(0), angle4 (0) {}
	cfigure(int angle11, int angle22, int angle33, int angle44) :
		angle1 (angle11),
		angle2 (angle22),
		angle3 (angle33),
		angle4 (angle44)	{}
	~cfigure() {}
	void output_cfigure() {
		cout << "angles:   " << endl;
		cout << angle1 <<endl;
		cout << angle2 <<endl;
		cout << angle3 <<endl;
		cout << angle4 << endl;
	}
};
class cparalellogram :virtual public cfigure {
protected:
	int radius;
public:
	cparalellogram(int angle11, int angle22, int angle33, int angle44, int radius1) :	
		cfigure(angle11, angle22, angle33, angle44),radius(radius1){  }
	~cparalellogram() {}
	void output_cparalellogram() {
		cout << "angles:   " << angle1 << " " << angle2 << " " << angle3 << " " << angle4 << endl;
		cout << "radius:  " << radius << endl;
	}
};
class cquadrangle : virtual public cfigure {
protected:
	int perimeter;
public:
	cquadrangle(int angle11, int angle22, int angle33, int angle44,int perimeter1) :cfigure(angle11, angle22, angle33, angle44), perimeter(perimeter1){}
	void output_cquadrangle() {
		cout << "angles:   " << angle1 << " " << angle2 << " " << angle3 << " " << angle4 << endl;
		cout << "perimeter:  " << perimeter << endl;
	}
	~cquadrangle(){}

};
class crhombus :public  cquadrangle {
protected:
	int size;
public:
	crhombus(int angle11, int angle22, int angle33, int angle44, int perimeter1,int size1) :
		cfigure(angle11, angle22, angle33, angle44),
		cquadrangle(angle11, angle22, angle33, angle44, perimeter1),
		size (size1){}
	~crhombus() {}
	void output_crhombus() {
		cout << "angles:   " << angle1 << " " << angle2 << " " << angle3 << " " << angle4 << endl;
		cout << "perimeter:  " << perimeter << endl;
		cout << "size:  " << size << endl;
	}
};
class crectangle : public cparalellogram {
protected:
	float coordinate_center_x;
	float coordinate_center_y;
public:
	crectangle(int angle11, int angle22, int angle33, int angle44, int radius,float coordinate_center_x1, float coordinate_center_y1) :
		cfigure(angle11, angle22, angle33, angle44),
		cparalellogram(angle11, angle22, angle33, angle44,radius),
		coordinate_center_x(coordinate_center_x1),
		coordinate_center_y(coordinate_center_y1){}
	void output_crectangle() {
		cout << "angles:   " << angle1 << " " << angle2 << " " << angle3 << " " << angle4 << endl;
		cout << "radius:  " << radius<< endl;
		cout << "coordinates:  " << coordinate_center_x<<" "<<coordinate_center_y<<endl;
	}
	~crectangle(){}
};
class csquare : public crectangle, public crhombus {
private:
	int square;
public:
	csquare(int angle11, int angle22, int angle33, int angle44,int radius1, float coordinate_center_x1, float coordinate_center_y1,
		int square1, int perimeter, int size) :
	cfigure(angle11, angle22, angle33, angle44), 
	crectangle(angle11, angle22, angle33, angle44,radius1, coordinate_center_x1, coordinate_center_y1),
	crhombus(angle11,angle22,angle33,angle44,perimeter,size),
	square (square1)	{}
	void output_csquare() {
		cout << "angles:   " << angle1 << " " << angle2 << " " << angle3 << " " << angle4 << endl;
		cout << "radius:  " << radius << endl;
		cout << "coordinates:  " << coordinate_center_x << " " << coordinate_center_y << endl;
		cout << "perimeter:  " << perimeter << endl;
		cout << "size:  " << size << endl;
		cout << "square:  " << square << endl;
	}
	~csquare(){}
};

int main() {
	int angle11, angle22, angle33, angle44;
	int radius, radius1;
	float coordinate_center_x, coordinate_center_y;
	int size,fl=0;
	int perimeter,perimeter1;;
	int square,square1;
	int a = 360;
	bool fail=true;
	do {
		cout << "input angles: ";
		cin >> angle11 >> angle22 >> angle33 >> angle44;
		if (cin.fail() || cin.rdbuf()->in_avail() > 1) 	cout << "error" << endl;
		else fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (angle11 != 90 || angle22 != 90 || angle33 != 90 || angle44 != 90|| fail);
	fail = true;
	do {
		
		cout << "input size: " << endl;
		cin >> size;
		if (cin.fail() || cin.rdbuf()->in_avail() > 1) 	cout << "error" << endl;
		else fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (size<=0 ||fail);
	fail = true;
	do {
		radius1 = size / 2;
		if (fl > 0) {
			cout <<endl<< "radius in square is " << radius1<<endl;
		}
		cout << "input radius" << endl;
		cin >> radius;
		if (cin.fail() || cin.rdbuf()->in_avail() > 1) 	cout << "error" << endl;
		else fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		fl++;
	} while ( radius<=0 || radius!=radius1|| fail);
	fail = true;
	fl = 0;
	do {
		cout << "input coordinats: " << endl;
		cin >> coordinate_center_x >> coordinate_center_y;
		if (cin.fail() || cin.rdbuf()->in_avail() > 1) 	cout << "error" << endl;
		else fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fail);
	fail = true;
	do {
		if (fl > 0) {
			cout << endl << "square perimeter is " << perimeter1 << endl;
		}
		perimeter1= size * 4;
		cout << "input perimeter: " << endl;
		cin >> perimeter;
		if (cin.fail() || cin.rdbuf()->in_avail() > 1) 	cout << "error" << endl;
		else fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		fl++;
	} while (perimeter<=0 || perimeter!=perimeter1|| fail);
	fail=true;
	fl = 0;
	do {
		square1 = size * size;
		if (fl > 0) {
			cout << endl << "square area is " << square1 << endl;
		}
		cout << "input square: " << endl;
		cin >> square;
		fl++;
		if (cin.fail() || cin.rdbuf()->in_avail() > 1) 	cout << "error" << endl;
		else fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (square<=0 || square!=square1|| fail);
	csquare* c = new csquare(angle11,angle22,angle33,angle44,radius, coordinate_center_x, coordinate_center_y, square, perimeter, size);
	c->output_csquare();
	return 0;
}
