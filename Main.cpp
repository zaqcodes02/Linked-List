#include "List.h"
using namespace std;

int main()
{

    List<float> l;
    int a;
    float data;
    cout << "Linked List Implementation" << endl;

    cout << "List Empty?" << l.isEmpty() << endl;
    cout << "Entering Elements!" << endl;
    l.add(1.5);
    l.add(2.1);
    l.add(3.5);
    l.add(4.6);
    l.add(5.8);
    l.add(6.9);
    l.add(7.1);

    cout << "The elements in list are: ";
    l.printList();
    cout << "Deleting by position: ";
    cin >> a;
    l.removeByPosition(a);
    l.printList();
    cout << "Deleting by data: ";
    cin >> data;
    l.removeByData(data);
    cout << "Deleting all Elements!" << endl;
    l.clear();

    cout << "List Empty?" << l.isEmpty() << endl;

    return 0;
}