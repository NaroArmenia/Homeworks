#include <iostream>
#include <limits.h>
using namespace std;

struct Oxak {
    int tvyal;
    Oxak *next;
};

class C_List {
    private:
        Oxak *head;

    public:
        C_List() {
            head = NULL;
        }

        ~C_List() {
            Oxak *temp;
            while (head != NULL) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        int displayMenu() {
            int choice;
            cout << "Մենյու\n";
            cout << "1. Տպել ցուցակը\n";
            cout << "2. Ցուցակի սկզբում ցուցակի միավոր ավելացնել\n";
            cout << "3. Ցուցակի տրված տեղում ցուցակի միավոր ավելացնել\n";
            cout << "4. Ցուցակի սկզբից ցուցակի միավոր հեռացնել\n";
            cout << "5. Ցուցակի վերջից ցուցակի միավոր հեռացնել\n";
            cout << "6. Փնտրվող միավորի մասին ինֆորմացիա\n";
            cout << "7. Ամենամեծ բացասական տարրը\n";
            cout << "8. Ելք\n";
            cout << "Ընտրեք գործողությունը: ";
            cin >> choice;

            return choice;
        }

        void Add_At_Position(int a, int position) {
            Oxak *nor = new Oxak;
            nor->tvyal = a;
            nor->next = NULL;

            if (position == 1) {
                nor->next = head;
                head = nor;
                return;
            }

            Oxak *t = head;
            int i = 1;

            while (t != NULL && i < position - 1) {
                t = t->next;
                i++;
            }

            if (t == NULL) {
                cout << "Տրված դիրքը սխալ է: Ցուցակի երկարությունը չի բավարարում։" << endl;
                delete nor;
                return;
            }

            nor->next = t->next;
            t->next = nor;
        }


        void Add_Start(int a) {
            Oxak *nor = new Oxak;
            nor->tvyal = a;
            nor->next = head;
            head = nor;
        }

        void Print() {
            Oxak *t = head;
            if(t == NULL) {
                cout << "Ցուցակ գոյություն չունի:" << endl;
            }
            while (t != NULL) {
                cout << t->tvyal << endl;
                t = t->next;
            }
        }

        void Del_Start() {
            if (head != NULL) {
                Oxak *temp = head;
                head = head->next;
                delete temp;
            }
        }

        void Del_End() {
            if (head == NULL) {
                return;
            }

            if (head->next == NULL) {
                delete head;
                head = NULL;
                return;
            }

            Oxak *t = head;
            while (t->next->next != NULL) {
                t = t->next;
            }

            delete t->next;
            t->next = NULL;
        }

        bool Search_List(int a) {
            Oxak *t = head;
            while (t != NULL) {
                if (t->tvyal == a) {
                    return true;  
                }
                t = t->next;
            }
            return false;
        }
        void Max_Negative() {
            Oxak *t = head;
            int maxNegative = INT_MIN;
            bool found = false;

            while (t != NULL) {
                if (t->tvyal < 0 && t->tvyal > maxNegative) {
                    maxNegative = t->tvyal;
                    found = true;
                }
                t = t->next;
            }

            if (found) {
                cout << "Ամենամեծ բացասական թիվը՝ " << maxNegative << endl;
            } else {
                cout << "Ցուցակում բացասական թվեր չկան։" << endl;
            }
        }
};

int main() {
    C_List ob;
    int choice;

    do {
        choice = ob.displayMenu();
        switch (choice) {
            case 1: {
                cout << "Ընթացիկ ցուցակն է:\n";
                ob.Print();
                break;
            }
            case 2: {
                int a;
                cout << "Մուտքագրել թիվը ցուցակի սկզբում ավելացնելու համար:\n";
                cin >> a;
                ob.Add_Start(a);
                break;
            }
            case 3: {
                int a, position;
                cout << "Մուտքագրեք թիվը և տեղը, որտեղ պետք է այն ավելացվի (օր.` 42 3):\n";
                cin >> a >> position;
                ob.Add_At_Position(a, position);
                break;
            }
            case 4: {
                cout << "Ցուցակի սկիզբը հեռացվում է\n";
                ob.Del_Start();
                break;
            }
            case 5: {
                cout << "Ցուցակի վերջը հեռացվում է\n";
                ob.Del_End();
                break;
            }
            case 6: {
                int a;
                cout << "Մուտքագրել թիվը փնտրելու համար:\n";
                cin >> a;
                if (ob.Search_List(a)) {
                    cout << a << "-ն ցուցակի տարր է\n";
                } else {
                    cout << a << "-ն ցուցակի տարր չէ\n";
                }
                break;
            }
            case 7: {
                cout << "Ամենամեծ բացասական թիվը գտնել\n";
                ob.Max_Negative();
                break;
            }
            case 8: {
                cout << "Ելք\n";
                break;
            }
            default: {
                cout << "Սխալ!!! Կրկին փորձեք:)\n";
                break;
            }
        }
    } while (choice != 8);

    return 0;
}