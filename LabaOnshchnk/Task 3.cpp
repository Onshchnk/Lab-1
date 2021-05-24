#include <iostream>

class Adam {

	std::uint16_t indict, sun, moon;

public:
    Adam() {
        indict = 0;
        sun = 0;
        moon = 0;
    }

    Adam(const Adam& adam) :indict(adam.indict), sun(adam.sun), moon(adam.moon) {}

    ~Adam() {
        std::cout << "Destruct here!" << std::endl;
    }
    
    Adam(std::uint64_t year) {
		std::uint16_t tmp1 = (year + 5508) % 15;
		if (tmp1 == 0) {
			indict = 15;
		}
		else {
			indict = tmp1;
		}
		std::uint16_t  tmp2 = (year + 5508) % 28;
		if (tmp2 == 0) {
			sun = 28;
		}
		else {
			sun = tmp2;
		}
		std::uint16_t tmp3 = (year + 5508) % 19;
		if (tmp3 == 0) {
			moon = 19;
		}
		else {
			moon = tmp3;
		}
	}
	
	Adam(std::uint16_t aIndict, std::uint16_t aSun, std::uint16_t aMoon) {
		std::uint16_t tmp1 = aIndict % 15;
		if (tmp1 == 0) {
			indict = 15;
		}
		else {
			indict = tmp1;
		}
		std::uint16_t tmp2 = aSun % 28;
		if (tmp2 == 0) {
			sun = 28;
		}
		else {
			sun = tmp2;
		}
		std::uint16_t tmp3 = aMoon % 19;
		if (tmp3 == 0) {
			moon = 19;
		}
		else {
			moon = tmp3;
		}
	}
	
	void OutAdam(int indict,int sun, int moon) {
        int year = 1;
        while (year % 15 != indict || year % 28 != sun || year % 19 != moon) {
            year++;
        }
        std::cout << year << std::endl;
    }

    std::uint16_t GetIndict() {
        return indict;
    }

    std::uint16_t GetSun() {
        return sun;
    }
    
    std::uint16_t GetMoon() {
        return moon;
    }
    
    void SetIndict(std::uint16_t x) {
		std::uint16_t tmp = x % 15;
		if (tmp == 0) {
			indict = 15;
		}
		indict = tmp;
	}
	
	void SetSun(std::uint16_t x) {
		std::uint16_t tmp = x % 28;
		if (tmp == 0) {
			sun = 28;
		}
		sun = tmp;
	}
	
	void SetMoon(std::uint16_t x) {
		std::uint16_t tmp = x % 19;
		if (tmp == 0) {
			moon = 19;
		}
		moon = tmp;
	}
	
	std::uint16_t TotalValue() {
		std::uint16_t totalValue = indict * moon * sun;
		std::cout << totalValue << std::endl;
		return totalValue;
	}
	
	friend Adam operator+ (const Adam& left, const Adam& right); 
	friend Adam operator- (const Adam& left, const Adam& right); 
	friend Adam operator* (const Adam& left, const Adam& right);
	friend Adam operator/ (const Adam& left, const Adam& right);

	Adam operator= (const Adam& right) {
		if (this != &right) {
			indict = right.indict;
			moon = right.moon;
			sun = right.sun;
		}
		return *this;
	}
	
    friend std::ostream& operator<< (std::ostream& out, const Adam& x);
    friend std::istream& operator>> (std::istream& in, Adam& x);
};

Adam operator+ (const Adam& left, const Adam& right) {
	std::uint16_t indict1 = x.indict + x1.indict;
	std::uint16_t  sun1 = x.sun + x1.sun;
	std::uint16_t moon1 = x.moon + x1.moon;
	return Adam(indict1, sun1, moon1);
}

Adam operator- (const Adam& left, const Adam& right) {
	std::uint16_t indict1 = 0;
	std::uint16_t  sun1 = 0;
	std::uint16_t moon1 = 0;
	if (x.indict >= x1.indict) {
		indict1 = x.indict - x1.indict;
	}
	else {
		indict1 = (x.indict + 15) - x1.indict;
	}
	if (x.sun >= x1.sun) {
		sun1 = x.sun - x1.sun;
	}
	else {
		sun1 = (x.sun + 28) - x1.sun;
	}
	if (x.moon >= x1.moon) {
		moon1 = x.moon - x1.moon;
	}
	else {
		moon1 = (x.moon + 19) - x1.moon;
	}
	return Adam(indict1, sun1, moon1);
}

Adam operator* (const Adam& left, const Adam& right) {
    std::uint16_t indict1 = x.indict * x1.indict;
    std::uint16_t  sun1 = x.sun * x1.sun;
    std::uint16_t moon1 = x.moon * x1.moon;
    return Adam(indict1, sun1, moon1);
}

Adam operator/ (const Adam& left, const Adam& right) {
	std::uint16_t indict1 = 0;
	std::uint16_t  sun1 = 0;
	std::uint16_t moon1 = 0;
	if (x.indict >= x1.indict) {
		indict1 = x.indict / x1.indict;
	}
	else {
		indict1 = x1.indict / x.indict;
	}
	if (x.sun >= x1.sun) {
		sun1 = x.sun / x1.sun;
	}
	else {
		sun1 = x1.sun / x.sun;
	}
	if (x.moon >= x1.moon) {
		moon1 = x.moon / x1.moon;
	}
	else {
		moon1 = x1.moon / x.moon;
	}
	return Adam(indict1, sun1, moon1);
}

std::ostream& operator<< (std::ostream& out, const Adam& x) {
	bool tmp = 0;
    std::cin >> tmp; // 1 - Адам, 0 - Как обычно
	if (tmp) {
        std::cout << "Indict: " << x.indict << "\nSun: " << x.sun << "\nMoon : " << x.moon  << std::endl;
	}
	else {
        std::cout << OutAdam(x.indict, x.sun, x.moon);
	}
	return std::cout;
}

std::istream& operator>> (std::istream& in, Adam& x) {
	bool tmp = 0;
	std::cin >> tmp; // 1 - Адам, 0 - Как обычно
	if (tmp) {
        std::uint16_t i, s, m;
		std::cout << "Enter indict, sun and moon: " << std::endl;
		std::cin >> i >> s >> m;
		std::uint16_t tmp1 = i % 15;
		if (tmp1 == 0) {
			x.indict = 15;
		}
		else {
			x.indict = tmp1;
		}
		std::uint16_t tmp2 = s % 28;
		if (tmp2 == 0) {
			x.sun = 28;
		}
		else {
			x.sun = tmp2;
		}
		std::uint16_t tmp3 = m % 19;
		if (tmp3 == 0) {
			x.moon = 19;
		}
		else {
			x.moon = tmp3;
		}
	}
	
	else {
        std::uint64_t y, tmp1, tmp2, tmp3;
		std::cout<< "Enter year :" << std::endl;
		std::cin >> y;
		tmp1 = y % 15;
		if (tmp1 == 0) {
			x.indict = 15;
		}
		else {
			x.indict = d;
		}
		tmp2 = y % 28;
		if (tmp2 == 0) {
			x.sun = 28;
		}
		else {
			x.sun = tmp2;
		}
		tmp3 = y % 19;
		if (tmp3 == 0) {
			x.moon = 19;
		}
		else {
			x.moon = tmp3;
		}
	}
	return std::cin;
}

int main() {

	Adam a(1652);
	a.OutAdam(a.Get_indict(),a.Get_sun(),a.Get_moon());

}