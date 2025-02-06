#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function declarations
bool Not(bool a);
bool And(bool a, bool b);
bool Or(bool a, bool b);
bool Imp(bool a, bool b);
bool PirsiSlaq(bool a, bool b);
bool XOR(bool x, bool y);
bool GumarumTRA(bool a, bool b);
bool Gic(bool a, bool b);
bool Hamarjeck(bool a, bool b);
void Truth_table_vector();
void Zhegalkin_polynomial(bool w1[], bool x1[], bool y1[]);
string simplifyPolynomial(const vector<string>& terms);
void pahanj();
void menu();

void Truth_table_vector() {
    int OctalValues[8][3] = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 1}
    };

    bool x, y, z, a, b, c, d, e, f, g, k, h, w;
    bool x1[8], y1[8], z1[8], w1[8];

    string CNF = ""; //kkndz
    string DNF = ""; //kdndz

    cout << "Truth table:" << endl << "\n";
    cout << "x  y  z    a  b  c  d  e  f  h  k  w\n\n";

    for (int i = 0; i < 8; ++i) {
        x = OctalValues[i][0];
        y = OctalValues[i][1];
        z = OctalValues[i][2]; //and-y bazmapatkumna 

        a = And(x, y);                     
        b = Not(a);              
        c = And(a,z);     //1)
        d = Imp(x,y);     //x -> y
        e = Hamarjeck(b,d);        //2)
        f = GumarumTRA(c,e);       //3)
        h = Gic(f,z);              //4)
        k = Or(h,x);               //5)
        w = GumarumTRA(k, b);      //6)        

        x1[i] = x;
        y1[i] = y;
        z1[i] = z;
        w1[i] = w;

        cout << x << "  " << y << "  " << z << "    ";
        cout << a << "  " << b << "  " << c << "  ";
        cout << d << "  " << e << "  ";
        cout << f << "  " << h << "  " << k << "  " << w << "\n";
    }
    cout << "\nFiltered table (z = 0):\n";
    cout << "x  y  w\n";
    for (int i = 0; i < 8; ++i) {
        if (z1[i] == 0) {
            cout << x1[i] << "  " << y1[i] << "  " << w1[i] << "\n";
            if (w1[i] == 0) {
                CNF += "(";
                CNF += (x1[i] == 0) ? "!x" : "x";
                CNF += " || ";
                CNF += (y1[i] == 0) ? "!y" : "y";
                CNF += ") AND ";
            } else {
                DNF += "(";
                DNF += (x1[i] == 1) ? "x" : "!x";
                DNF += " && ";
                DNF += (y1[i] == 1) ? "y" : "!y";
                DNF += ") OR ";
            }
        }
    }
    if (!CNF.empty()) CNF = CNF.substr(0, CNF.size() - 5);
    if (!DNF.empty()) DNF = DNF.substr(0, DNF.size() - 4);
    cout << "\nKonyuktiv: " << CNF << "\n";
    cout << "Dizunktiv: " << DNF << "\n\n";
    Zhegalkin_polynomial(w1, x1, y1);
}

void Zhegalkin_polynomial(bool w1[], bool x1[], bool y1[]) {
    vector<string> terms; 
    string polynomial = "P(x,y) = ";

    for (int i = 0; i < 8; ++i) {
        if (w1[i]) { 
            string term = "(" + string((x1[i] == 1) ? "x" : "!x") + " * " + string((y1[i] == 1) ? "y" : "!y") + ")";
            terms.push_back(term);
        }
    }
    string simplified = simplifyPolynomial(terms);
    cout << "Zhegalkin Polynomial: " << simplified << "\n";
}

string simplifyPolynomial(const vector<string>& terms) {
    if (terms.empty()) return "0";

    string result = "";
    for (size_t i = 0; i < terms.size(); ++i) {
        bool isDuplicate = false;
        for (size_t j = 0; j < i; ++j) {
            if (terms[i] == terms[j]) {
                isDuplicate = true;
                break;
            }
        }
        string term = terms[i];
        if (term.find("!y") != string::npos) {
            term = term.replace(term.find("!y"), 2, "(y GumarumTRA 1)");
        }
        if (!isDuplicate) {
            if (!result.empty()) {
                result += " OR ";
            }
            result += term;
        }
    }
    
    return result.empty() ? "0" : result;
}

bool Not(bool a) {
    return !a;
}

bool And(bool a, bool b) { //and
    return a && b;
}

bool Or(bool a, bool b) { //or
    return (a || b);
}

bool Imp(bool a, bool b) { //depi ag slaq
    return !a || b;
}

bool PirsiSlaq(bool a, bool b) { //nerqevslaq
    return !(a || b);  
}

bool XOR(bool x, bool y) { //depi nerqev slaq
    return (x ^ y);
}

bool GumarumTRA(bool a, bool b) {    //gumarum
    return a != b; 
}

bool Gic(bool a, bool b) { //sheferi shtrix
    return (!(a && b));                       
}

bool Hamarjeck(bool a, bool b) { //Hamarjeck
    return (a == b) ? 1 : 0; 
}

void pahanj() {
    cout << "Bulyan funksiyayi hamar stanal." << endl;
    cout << "1. Funkciayi skutyan axyusaky ev skutyan vektory," << endl; 
    cout << "2. Heracnel funkcayi fctv popoxakannery," << endl;
    cout << "3. Stanal bulyan funksayi KDNC ev KKNC," << endl;
    cout << "4. Stanal bulyan funksayi Jegalkin bazmandamy," << endl;
    cout << "5. Karucel bulyan funksayi funkcional tarrer sxema, vor bardutyuny ch gerazancum 6-y." << endl << endl;
}

void menu() {
    cout << '\n';
    cout << "1. Task" << endl;
    cout << "2. Truth table, truth vector" << endl; 
    cout << "3. Fictiv" << endl;
    cout << "4. Normal forma" << endl;
    cout << "5. Zhegalkin" << endl; 
    cout << "6. Exit" << endl;
    cout << '\n';
    cout << "Number = ";
}

int main() {
    int value;
    menu();
    do {
        cin >> value; 
        cout << '\n';
        
        switch (value) {
            case 1:
                pahanj();
                menu(); 
                break;
            case 2:
                Truth_table_vector(); 
                menu();
                break; 
            case 3:
                menu(); 
                break;
            case 4:
                menu();
                break;
            case 5:
                menu();
                break;
            case 6:
                break; 
            default:
                cout << "Error" << endl; 
                menu();
                break;
        }
    } while (value != 6); 
    return 0; 
}