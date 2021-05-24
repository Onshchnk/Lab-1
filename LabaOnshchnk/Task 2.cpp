#include <iostream>
#include <string>
using namespace std;

class LongNumber {

    string num;

public:
    LongNumber() {
    }

    LongNumber(string num):num(num) {}

    LongNumber(const LongNumber& longNumber) :num(longNumber.num) {}

    ~LongNumber() {
        std::cout << "Destructor here." << std::endl;
    }

    string GetNum() {
        return num;
    }

    void SetNum(string x) {
        num = x;
    }
    
    friend LongNumber operator+ (const LongNumber& left, const LongNumber& right);
    friend LongNumber operator- (const LongNumber& left, const LongNumber& right);
    //friend LongNumber operator* (const LongNumber& left, const LongNumber& right);
    //friend LongNumber operator/ (const LongNumber& left, const LongNumber& right);

   /* LongNumber operator= (const LongNumber& right) {
        if (this != &right) {
            num = right.num;
        }
        return *this;
    }
    */
    friend std::ostream& operator<< (std::ostream& out, const LongNumber& x);
    friend std::istream& operator>> (std::istream& in, LongNumber& x);
};

LongNumber operator+ (const LongNumber& left, const LongNumber& right) {
    int len;
    int nex = 0;
    string c;
    string a = left.num;
    string b = right.num;
    if (a.length() > b.length()) {
        len = a.length() - 1;
        c = string(a.length() - b.length(), '0');
        b = c + b;
    }
    else {
        len = b.length() - 1;
        c = string(b.length() - a.length(), '0');
        a = c + a;
    }
    //int nex = 0;
    c = "";
    for (int i = len; i >= 0; ix--)
    {
        int res;
        res = (int)(a[i] - '0') + (int)(b[i] - '0') + nex;
        nex = res / 10; // если есть разряд для переноса, переносим его в следующий разряд
        res %= 10; // если есть разряд для переноса он отсекается
        c += to_string(res);
    }
    reverse(c.begin(), c.end());
    return LongNumber(c);
}

LongNumber operator- (const LongNumber& left, const LongNumber& right) {
    int len;
    bool flag = 0;
    int nex = 0;
    string c;
    string a = left.num;
    string b = right.num;
    if (a.length() > b.length()) {
        len = a.length() - 1;
        c = string(a.length() - b.length(), '0');
        b = c + b;
    }
    else if ( a.length() == b.length() ) {
        bool big = 0;
        len = a.length() - 1;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] < b[i]) {
                big = 1;
                break;
            }
        }
        if (big) {
            flag = 1;
            string tmp = a;
            a = b;
            b = tmp;
        }
    }
    else {
        len = b.length() - 1;
        c = string(b.length() - a.length(), '0');
        a = c + a;
        //flag = 0;
        string tmp = a;
        a = b;
        b = tmp;
        flag = 1;
    }
    c = "";
    for (int i = len; i >= 0; i--) {
        int res;
        if (((int)(a[i] - '0')) < ((int)(b[i] - '0'))) {
            
            res = ((int)(a[i] - '0') + 10) - ((int)(b[i] - '0')) + nex;
            nex = -1;
        }
        else {
            res = (((int)(a[i] - '0')) - ((int)(b[i] - '0')))+nex;
            nex = 0;
        }
        c += to_string(res);
    }
    reverse(c.begin(), c.end());
    len = 0;
    for (int i = 0; i < c.length(); i++) {
        if (c[i] != '0')
            break;
        else
            len++;
    }
    if(len==c.length())
        return LongNumber("0");
    c.erase(0, len);
    if (flag)
        c = "-" + c;
    return LongNumber(c);
}
/*
LongNumber operator* (const LongNumber& left, const LongNumber& right) {
    if (left.length() < right.length()) {
        int tmp;
        tmp = left;
        left = right;
        right = tmp;
    }
    int nex = 0;
    for (i = left.length(), i > 0, i--) {
        for (j = right.length(), j > 0, j--) {
            int res;
            res = (int)(left[i] - '0') * (int)(right[j] - '0') + nex;
            nex = res / 10;
            res %= 10;
            c += to_string(res); // надо как-то добавлять в разные  строки с, если разные i (чем больше i, тем больше сдвиг влево, а справа нули)
        }
    }
    //вызвать оператор+ для разных строк с и вернуть их сумму 
} */

LongNumber operator* (const LongNumber& left, const LongNumber& right) {
    int tmp;
    for (int i = 0; i < right.length(); i++){
        tmp = 0;
        fot (int j = 0; j < left.length(); i++){

        }
    }
}

/*
LongNumber operator/ (const LongNumber& left, const LongNumber& right) {
    if (left.length() < right.length()) {
        res = 0;
        return res;
    }
    if (left.length() = right.length()) {
        if (left = right) {
            res = 1;
            return res;
        }
        else if (left < right) {
            res = 0
                return res;
        }
    }
    if (left.length() >= right.length()) {
        string subString;

    }
}
*/
std::ostream& operator<< (std::ostream& out, const LongNumber& x) {
    out << "Num: " << x.num << std::endl;
    return out;
}

std::istream& operator>> (std::istream& in, LongNumber& x) {
    in >> x.num;
    return in;
}

int main() {
    LongNumber a;
    LongNumber b;
    std::cin >> a;
    std::cin >> b;
    std::cout << (a - b).GetNum();
}


