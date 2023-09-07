#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

class Fraction {
	private: 
		int64_t numerator;
		int64_t denominator;
	public: 
		Fraction() {
			numerator = 0;
			denominator = 1;
		}

		Fraction(int64_t n) {
			numerator = n;
			denominator = 1;
		}

		Fraction(int64_t n, int64_t d) {
			numerator = n;
			denominator = d;
			simplify();
		}

		string getFraction() {
			simplify();
			return to_string(numerator) + " / " + to_string(denominator);
		}

		const int64_t getNum() {
			return numerator;
		}

		const int64_t getDen() {
			return denominator;
		}

		int64_t gcd(int64_t a, int64_t b) {
			int64_t tmp;

			while (b != 0) {
				tmp = b;
				b = a % b;
				a = tmp;

				gcd(a, b);
			}

			return a;
		}

		void simplify() {
			int64_t divisor;

			if ((gcd(numerator, denominator)) != 1) {
				divisor = gcd(numerator, denominator);

				numerator   /= divisor;
				denominator /= divisor;
			}

			if (denominator < 0) {
				numerator *= -1;
				denominator *= -1;
			}

		}

		void simplify(Fraction& a) {
			int64_t divisor;

			if ((gcd(a.numerator, a.denominator)) != 1) {
				divisor = gcd(a.numerator, a.denominator);

				a.numerator   /= divisor;
				a.denominator /= divisor;
			}

			if (a.denominator < 0) {
				a.numerator *= -1;
				a.denominator *= -1;
			}
		}

		// Arithmetic Operators 
		Fraction operator+(const Fraction& f) {
			Fraction result, tmpN, tmpD;

			result.numerator = (numerator * f.denominator) 
							 + (f.numerator * denominator);
			result.denominator = denominator * f.denominator;
		
			simplify(result);
			return result;
		}

		Fraction operator-(const Fraction& f) {
			Fraction result;

			result.numerator = (numerator * f.denominator)
							 - (f.numerator * denominator);
			result.denominator = denominator * f.denominator;

			simplify(result);
			return result;
		}
		
		Fraction operator*(const Fraction& f) {
			Fraction result;

			result.numerator = numerator * f.numerator;
			result.denominator = denominator * f.denominator;

			simplify(result);
			return result;
		}
		
		Fraction operator/(const Fraction& f) {
			Fraction result, d;
			int64_t tmp;

			d.numerator = f.numerator;
			d.denominator = f.denominator;

			tmp = d.numerator;
			d.numerator = d.denominator;
			d.denominator = tmp;

			result.numerator = numerator * d.numerator;
			result.denominator = denominator * d.denominator;

			simplify(result);
			return result;
		}

		// Boolean Operators 
		bool operator==(const Fraction& f) {
			if ((static_cast<float>(numerator) / denominator)
			== (static_cast<float>(f.numerator) / f.denominator)) {
				return true;
			}

			return false;
		}

		bool operator!=(const Fraction& f) {
			if ((static_cast<float>(numerator) / denominator)
			!= (static_cast<float>(f.numerator) / f.denominator)) {
				return true;
			}

			return false;
		}

		bool operator>(const Fraction& f) {
			if ((static_cast<float>(numerator) / denominator)
			 > (static_cast<float>(f.numerator) / f.denominator)) {
				return true;
			}

			return false;
		}

		bool operator>=(const Fraction& f) {
			if ((static_cast<float>(numerator) / denominator)
			>= (static_cast<float>(f.numerator) / f.denominator)) {
				return true;
			}

			return false;
		}

		bool operator<(const Fraction& f) {
			if ((static_cast<float>(numerator) / denominator)
			 < (static_cast<float>(f.numerator) / f.denominator)) {
				return true;
			}
			return false;
		}

		bool operator<=(const Fraction& f) {
			if ((static_cast<float>(numerator) / denominator)
			<= (static_cast<float>(f.numerator) / f.denominator)) {
				return true;
			}

			return false;
		}

		// EXTRAS FOR NON-FRACTIONS
		bool operator==(const float& flo) {
			if ((static_cast<float>(numerator) / denominator) == flo) {
				return true;
			}

			return false;
		}

		bool operator!=(const float& flo) {
			if ((static_cast<float>(numerator) / denominator) != flo) {
				return true;
			}

			return false;
		}

		// Stream operators
		friend ostream& operator<<(ostream& os, const Fraction& f) {
			os << f.numerator << " / " << f.denominator;
			return os;
		}

		friend istream& operator>>(istream& is, Fraction& f) {
			char skip;

			is >> f.numerator;
			is >> skip;
			is >> f.denominator;
			f.simplify();
			return is;
		}

};