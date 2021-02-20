#include <iostream>
#include <cstdlib>
class Date {
private:
	int day, month, year;
public:
	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	Date(const char dat[11]) {
		day = atoi(dat);
		char dat_1[] = { dat[3], dat[4], dat[5], dat[6], dat[7], dat[8], dat[9], dat[10] };
		month = atoi(dat_1);
		char dat_2[] = { dat[6], dat[7], dat[8], dat[9], dat[10] };
		year = atoi(dat_2);
	}
	
	void print_date() {
		std::cout << day << "." << month << "." << year << std::endl;
	}

};

int main() {
	Date ABC("12.10.2002");
	ABC.print_date();
}