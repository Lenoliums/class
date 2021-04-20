#include <iostream>

class Triangle {
private:
	double x_A, x_B, x_C, y_A, y_B, y_C, square, perimetr, lenAB, lenBC, lenAC, lenAB_squared, lenBC_squared, lenAC_squared;
	void count_P_S() {
		double p;
		perimetr = lenAB + lenAC + lenBC;
		p = perimetr / 2;
		square = sqrt(p*(p - lenAB)*(p - lenAC)*(p - lenBC));
	}
	void count_lens_squared() {
		lenAB_squared = (x_A - x_B)*(x_A - x_B) + (y_A - y_B)*(y_A - y_B);
		lenBC_squared = (x_C - x_B)*(x_C - x_B) + (y_C - y_B)*(y_C - y_B);
		lenAC_squared = (x_A - x_C)*(x_A - x_C) + (y_A - y_C)*(y_A - y_C);
	}
	void count_lens() {
		count_lens_squared();
		lenAB = sqrt(lenAB_squared);
		lenBC = sqrt(lenBC_squared);
		lenAC = sqrt(lenAC_squared);
	}
public:
	Triangle() {
		x_A = 0;
		y_A = 1;
		x_B = sqrt(3) / 2;
		y_B = -0.5;
		x_C = -sqrt(3) / 2;
		y_C = -0.5;
		count_P_S();
		count_lens();
	}
	Triangle(double xA, double yA, double xB, double yB, double xC,   double yC) {
		x_A = xA;
		x_B = xB;
		x_C = xC;
		y_A = yA;
		y_B = yB;
		y_C = yC;
		count_lens();
		count_P_S();
	}
	double get_x_A() const {return(x_A);}
	double get_x_B() const {return(x_B);}
	double get_x_C() const {return(x_C);}
	double get_y_C() const  {return(y_C);}
	double get_y_A() const  {return(y_A);}
	double get_y_B() const {return(y_B);}
	double get_lenAB() const {return(lenAB);}
	double get_lenBC() const {return(lenBC);}
	double get_lenAC() const {return(lenAC);}
	double get_Perimetr() const  {return(perimetr);}
	double get_Square() const {return(square);}

	void set_x_A(double new_x) {
		x_A = new_x;
		count_lens();
		count_P_S();
	}
	void set_x_B(double new_x) {
		x_B = new_x;
		count_lens();
		count_P_S();
	}
	void set_x_C(double new_x) {
		x_C = new_x;
		count_lens();
		count_P_S();
	}
	void set_y_A(double new_y) {
		y_A = new_y;
		count_lens();
		count_P_S();
	}
	void set_y_B(double new_y) {
		y_B = new_y;
		count_lens();
		count_P_S();
		
	}
	void set_y_C(double new_y) {
		y_C = new_y;
		count_lens();
		count_P_S();
	}
	void set_A(double new_x, double new_y) {
		x_A = new_x;
		y_A = new_y;
		count_lens();
		count_P_S();
	}
	void set_B(double new_x, double new_y) {
		x_B = new_x;
		y_B = new_y;
		count_lens();
		count_P_S();
	}
	void set_C(double new_x, double new_y) {
		x_C = new_x;
		y_C = new_y;
		count_lens();
		count_P_S();
	}


	double  inscribed_circle_radius(){return(2*square /perimetr);}
	double  circumscribed_circle_radius() { return((lenAB*lenAC*lenBC) / (4 * square)); }
	bool equilateral_triangle() {return(lenAB == lenAC && lenAB == lenBC);}
	bool isosceles_triangle() {return(lenAB == lenAC || lenAB == lenBC|| lenAC== lenBC);}
	bool rectangular_triangle() {return(lenAB_squared == lenAC_squared + lenBC_squared || lenAB_squared + lenAC_squared == lenBC_squared || lenAC_squared == lenAB_squared + lenBC_squared);}
	bool obtuse_triangle() {return(lenAB_squared > lenAC_squared + lenBC_squared || lenAB_squared + lenAC_squared < lenBC_squared || lenAC_squared > lenAB_squared + lenBC_squared);}

	~Triangle() {
		std::cout << "That is all" << std::endl;
	}
};

int main() {
	Triangle ABC(1,1,1,2,2,1);

	std::cout << "A(" << ABC.get_x_A() << " ;" << ABC.get_y_A() << ")" <<std::endl;
	std::cout << "B(" << ABC.get_x_B() << " ;" << ABC.get_y_B() << ")" << std::endl;
	std::cout << "C(" << ABC.get_x_C() << " ;" << ABC.get_y_C() << ")" << std::endl;
	std::cout << "AB length:" << ABC.get_lenAB() << std::endl;
	std::cout << "BC length:" << ABC.get_lenBC() << std::endl;
	std::cout << "AC length:" << ABC.get_lenAC() << std::endl;
	std::cout << "Perimetr: " << ABC.get_Perimetr() << " Square: "<< ABC.get_Square() <<std::endl;
	std::cout << "r: "<<ABC.inscribed_circle_radius() << std::endl;
	std::cout << "R: "<<ABC.circumscribed_circle_radius() << std::endl;
	if (ABC.equilateral_triangle()) {
		std::cout << "ABC - equilateral triangle" << std::endl;
	}
	if (ABC.isosceles_triangle()) {
		std::cout << "ABC - isosceles triangle" << std::endl;
	}
	if (ABC.rectangular_triangle()) {
		std::cout << "ABC - rectangular triangle" << std::endl;
	}
	if (ABC.obtuse_triangle()) {
		std::cout << "ABC - obtuse triangle" << std::endl;
	}

	ABC.set_A(0, 0);
	std::cout << "New Perimetr: " << ABC.get_Perimetr() << " New Square: " << ABC.get_Square() << std::endl;

	return 0;
}