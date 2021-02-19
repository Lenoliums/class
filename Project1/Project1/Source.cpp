#include <iostream>
class Triangle {
private:
	double x_A, x_B, x_C, y_A, y_B, y_C, square, perimetr, lenAB, lenBC, lenAC;
	void count_P_and_S() {
		double p;
		perimetr = lenAB + lenAC + lenBC;
		p = perimetr / 2;
		square = sqrt(p*(p - lenAB)*(p - lenAC)*(p - lenBC));
	}
public:
	Triangle() {
		x_A = 0;
		y_A = 1;
		x_B = sqrt(3) / 2;
		y_B = -0.5;
		x_C = -sqrt(3) / 2;
		y_C = -0.5;
		lenAB = sqrt((x_A - x_B)*(x_A - x_B) + (y_A - y_B)*(y_A - y_B));
		lenBC = sqrt((x_C - x_B)*(x_C - x_B) + (y_C - y_B)*(y_C - y_B));
		lenAC = sqrt((x_A - x_C)*(x_A - x_C) + (y_A - y_C)*(y_A - y_C));
		count_P_and_S();
	}
	Triangle(double xA, double xB, double xC, double yA, double yB, double yC) {
		x_A = xA;
		x_B = xB;
		x_C = xC;
		y_A = yA;
		y_B = yB;
		y_C = yC;
		lenAB = sqrt((x_A - x_B)*(x_A - x_B) + (y_A - y_B)*(y_A - y_B));
		lenBC = sqrt((x_C - x_B)*(x_C - x_B) + (y_C - y_B)*(y_C - y_B));
		lenAC = sqrt((x_A - x_C)*(x_A - x_C) + (y_A - y_C)*(y_A - y_C));
		count_P_and_S();
	}
	bool equilateral_T() {
		return(lenAB == lenAC & lenAB == lenBC);
	}
	void print_coor() {
		std::cout << "A {" << x_A << ", " << y_A << '}' << std::endl;
		std::cout << "B {" << x_B << ", " << y_B << '}' << std::endl;
		std::cout << "C {" << x_C << ", " << y_C << '}' << std::endl;
	}
	void print_S_P() {
		std::cout << "Square: " << square << std::endl;
		std::cout << "Perimetr: " << perimetr << std::endl;
	}

};

int main() {
	Triangle ABC(1, 1, 0, 1, 2, 1);
	ABC.print_coor();
	ABC.print_S_P();
	std::cout << ABC.equilateral_T() << std::endl;


}
//