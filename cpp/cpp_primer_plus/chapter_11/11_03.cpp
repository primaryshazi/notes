
//vector.h
//*******************************************************************************************

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode; 
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; }
		double yval() const { return y; }
		double magval();
		double angval();
		void polar_mode();
		void rect_mode();
	
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
} 

#endif

//*******************************************************************************************

//vecror.cpp
//*******************************************************************************************

#include <cmath>
#include "vector.h"  
#include <iostream>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
using std::endl;

namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);

	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}

	void Vector::set_x()
	{
		x = mag * cos(ang);
	}

	void Vector::set_y()
	{
		y = mag * sin(ang);
	}
 
	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "Vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "Vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{
	}

	double Vector::magval()
	{
		return sqrt(x * x + y * y);
	}

	double Vector::angval()
	{
		return atan2(y, x);
	}

	void Vector::polar_mode()
	{
		mode = POL;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}

	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{  
		if (v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
			os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
		else
			os << "Vector object mode is invalid";

		return os;
	}
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"
#include <vector>

int main()
{
	using namespace std;

	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	int n;
	unsigned long stepmax;
	unsigned long stepmin;
	unsigned long total = 0;
	double average;

	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length : ";
		if (!(cin >> dstep))
			break;
		cout << "Input time of repetion : ";
		if (!(cin >> n))
			break;
		vector<unsigned long>st(n);
		for (int i = 0; i < n; i++)
		{
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}
			total += steps;
			st[i] = steps;
			steps = 0;
			result.reset(0.0, 0.0);
		}
		stepmax = stepmin = st[0];
		for (int i = 0; i < n; i++)
		{
			if (st[i] > stepmax)
				stepmax = st[i];
			if (st[i] < stepmin)
				stepmin = st[i];
		}
		average = double(total / n);

		cout << "The max steps is " << stepmax << endl;
		cout << "The min steps is " << stepmin << endl;
		cout << "The averge steps is " << average << endl;

		total = 0;
		average = 0;
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!" << endl;
	
	cin.clear();
	while (cin.get() != '\n');
	
	system("pause");
	return 0;
}

//*******************************************************************************************