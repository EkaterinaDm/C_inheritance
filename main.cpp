#include <iostream>
#include <cstring>
using namespace std;
#include "classes.h"
int main()
{
    Computer *p;
    Computer obj("КОМПЬЮТЕРЫ");
    p=&obj; p->show_Inf(); //вызов виртуальной функции для базового класса
    int size1, size2, variant=0, data;
    cout << "Введите количество настольных компьютеров: ";
    cin >> size1;
    Desktop *p1; 
    Desktop obj1("настольный компьютер");
    p1 = new Desktop[size1]; // размещение массива объектов Desktop
    if (!p1) {cout << "Ошибка выделения памяти \n"; return 1;}
    for (int i=0; i<size1; i++)
    {
        cout << "Введите информацию о " << i+1 << " компьютере:\n"; 
        p1[i].get_Name_Cost();
        cout << "Введите ЦВЕТ корпуса " << i+1 << " компьютера:\n"; 
        p1[i].get_Inf();
    }
    
    cout << "\nВведите количество ноутбуков: ";
    cin >> size2;
    Laptop *p2;
    Laptop obj2("ноутбук");
    p2 = new Laptop[size2]; // размещение массива объектов Laptop
    if (!p2) {cout << "Ошибка выделения памяти \n"; return 1;}
    for (int j=0; j<size2; j++)
    {
        cout << "Введите информацию о " << j+1 << " ноутбуке:\n";
        p2[j].get_Name_Cost();
        cout << "Введите ЦВЕТ корпуса " << j+1 << " ноутбука:\n"; 
        p2[j].get_Inf();
    }
    
    while (variant != 6)
    {
        cout << "\nВведите: \n1 - если хотите изменить информацию о на-столь-ном компьютере \n2 - если хотите изменить информацию о ноут-буке \n3 - если хотите вывести информацию о настольном компьютере \n4 - если хотите вывести информацию о ноутбуке \n5 - если хотите вы-вести информацию о самом дешевом компьютере \n6 - если хотите выйти\n";
        cout << ">>> ";
        cin >> variant;
        switch (variant)
        {
            case 1: cout << "\nВведите номер настольного компьютера: ";
                    cin >> data;
                    cout << "Введите информацию о " << data << " компьюте-ре:\n"; p1[data-1].get_Name_Cost();
                    cout << "Введите ЦВЕТ корпуса " << data << " компьютера:\n"; p1[data-1].get_Inf();break;
                
            case 2: cout << "\nВведите номер ноутбука: ";
                    cin >> data;
                    cout << "Введите информацию о " << data << " ноутбуке:\n"; p2[data-1].get_Name_Cost(); 
                    cout << "Введите ЦВЕТ корпуса " << data << " ноутбука:\n"; p2[data-1].get_Inf(); break;
            
            case 3: cout << "\nВведите номер настольного компьютера: ";
                    cin >> data;
                    cout << "Информация о " << data << " компьютере:\n"; p1[data-1].show_Name_Cost(); 
                    cout << "Тип: "; p=&obj1; p->show_Inf(); //вызов виртуальной функции для 1 производного класса
                    cout << "Цвет корпуса: "; p1[data-1].show_Inf(); break;
                    
            case 4: cout << "\nВведите номер ноутбука: ";
                    cin >> data;
                    cout << "Информация о " << data << " ноутбуке:\n"; p2[data-1].show_Name_Cost(); 
                    cout << "Тип: "; p=&obj2; p->show_Inf(); //вызов виртуальной функции для 2 производного класса
                    cout << "Цвет корпуса: "; p2[data-1].show_Inf(); break;
                    
            case 5: Min(p1, p2, size1, size2); break;
            case 6: break;       
        }
    }
    delete [] p1;
    delete [] p2;
return 0;
}
