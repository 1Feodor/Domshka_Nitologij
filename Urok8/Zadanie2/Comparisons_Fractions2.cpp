#include <iostream>
#include <Windows.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;
	void Sokraschenie(int* num, int* denom)
	{
		int size{ 0 };
		if (*num < *denom) size = *num;
		else size = *denom;
		for (int i = size; i >= 2; i--)
		{
			if (*num % i == 0 && *denom % i == 0)
			{
				*num /= i;
				*denom /= i;
				break;
			}
		}
	}
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	int Get_numerator_() const
	{
		return this->numerator_;
	}
	int Get_denominator_() const
	{
		return this->denominator_;
	}
	bool operator==(const Fraction& fract)
	{
		return this->numerator_ / this->denominator_ == fract.numerator_ / fract.denominator_;
	}
	bool operator!=(const Fraction& fract)
	{
		return this->numerator_ / this->denominator_ != fract.numerator_ / fract.denominator_;
	}
	bool operator<(const Fraction& fract)
	{
		return this->numerator_ / this->denominator_ < fract.numerator_ / fract.denominator_;
	}
	bool operator>(const Fraction& fract)
	{
		return this->numerator_ / this->denominator_ > fract.numerator_ / fract.denominator_;
	}
	bool operator<=(const Fraction& fract)
	{
		return this->numerator_ / this->denominator_ <= fract.numerator_ / fract.denominator_;
	}
	bool operator>=(const Fraction& fract)
	{
		return this->numerator_ / this->denominator_ >= fract.numerator_ / fract.denominator_;
	}
	Fraction operator+(const Fraction& fract)
	{
		int numerator = this->numerator_ * fract.denominator_ + this->denominator_ * fract.numerator_;
		int denominator = this->denominator_ * fract.denominator_;
		Sokraschenie(&numerator, &denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator-(const Fraction& fract)
	{
		int numerator = this->numerator_ * fract.denominator_ - this->denominator_ * fract.numerator_;
		int denominator = this->denominator_ * fract.denominator_;
		Sokraschenie(&numerator, &denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator*(const Fraction& fract)
	{
		int numerator = this->numerator_ * fract.numerator_;
		int denominator = this->denominator_ * fract.denominator_;
		Sokraschenie(&numerator, &denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator/(const Fraction& fract)
	{
		int numerator = this->numerator_ * fract.denominator_;
		int denominator = this->denominator_ * fract.numerator_;
		Sokraschenie(&numerator, &denominator);
		return Fraction(numerator, denominator);
	}
	Fraction operator+()
	{
		int numerator = this->numerator_;
		int denominator = this->denominator_;
		return Fraction(numerator, denominator);
	}
	Fraction operator-()
	{
		int numerator = this->numerator_;
		int denominator = -this->denominator_;
		return Fraction(numerator, denominator);
	}
	Fraction& operator++()
	{
		this->numerator_ = this->numerator_ + this->denominator_;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction temp = *this;
		this->numerator_ = this->numerator_ + this->denominator_;
		return temp;
	}
	Fraction& operator--()
	{
		this->numerator_ = this->numerator_ - this->denominator_;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction temp = *this;
		this->numerator_ = this->numerator_ - this->denominator_;
		return temp;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num{}, denom{};

	std::cout << "¬ведите числитель дроби 1: ";
	std::cin >> num;
	std::cout << "¬ведите знаменатель дроби 1: ";
	std::cin >> denom;
	Fraction f1{ num, denom };

	std::cout << "¬ведите числитель дроби 2: ";
	std::cin >> num;
	std::cout << "¬ведите знаменатель дроби 2: ";
	std::cin >> denom;
	Fraction f2{ num, denom };
	
	Fraction f3{ f1 + f2 };
	std::cout << f1.Get_numerator_() << "/" << f1.Get_denominator_() << " + ";
	std::cout << f2.Get_numerator_() << "/" << f2.Get_denominator_() << " = ";
	std::cout << f3.Get_numerator_() << "/" << f3.Get_denominator_() << std::endl;
	
	f3 = f1 - f2;
	std::cout << f1.Get_numerator_() << "/" << f1.Get_denominator_() << " - ";
	std::cout << f2.Get_numerator_() << "/" << f2.Get_denominator_() << " = ";
	std::cout << f3.Get_numerator_() << "/" << f3.Get_denominator_() << std::endl;

	f3 = f1 * f2;
	std::cout << f1.Get_numerator_() << "/" << f1.Get_denominator_() << " * ";
	std::cout << f2.Get_numerator_() << "/" << f2.Get_denominator_() << " = ";
	std::cout << f3.Get_numerator_() << "/" << f3.Get_denominator_() << std::endl;

	f3 = f1 / f2;
	std::cout << f1.Get_numerator_() << "/" << f1.Get_denominator_() << " / ";
	std::cout << f2.Get_numerator_() << "/" << f2.Get_denominator_() << " = ";
	std::cout << f3.Get_numerator_() << "/" << f3.Get_denominator_() << std::endl;

	f3 = -f1;
	std::cout << "-(" << f1.Get_numerator_() << "/" << f1.Get_denominator_();
	std::cout << ") = " << f3.Get_numerator_() << "/" << f3.Get_denominator_() << std::endl;

	std::cout << "++" << f1.Get_numerator_() << "/" << f1.Get_denominator_() << " * ";
	f3 = ++f1 * f2;
	std::cout << f2.Get_numerator_() << "/" << f2.Get_denominator_() << " = ";
	std::cout << f3.Get_numerator_() << "/" << f3.Get_denominator_() << std::endl;
	std::cout << "«начение дроби 1 = " << f1.Get_numerator_() << "/" << f1.Get_denominator_() << std::endl;

	std::cout << f1.Get_numerator_() << "/" << f1.Get_denominator_() << "-- * ";
	f3 = f1-- * f2;
	std::cout << f2.Get_numerator_() << "/" << f2.Get_denominator_() << " = ";
	std::cout << f3.Get_numerator_() << "/" << f3.Get_denominator_() << std::endl;
	std::cout << "«начение дроби 1 = " << f1.Get_numerator_() << "/" << f1.Get_denominator_() << std::endl;

	/*std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';*/

	return 0;
}