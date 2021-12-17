class Laptop;
/////////базовый класс//////////
class Computer 
{
protected:
    string Name;  //фирма компьютера
    int Cost;  //стоимость компьютера
public:
    string Inf; 
    Computer(string Inf1) {Inf = Inf1;} //конструктор с параметрами
    Computer(): Name("None"), Cost(0) {} //конструктор, для инициалиации объектов
    void get_Name_Cost() {cout << "Фирма: "; cin >> Name; cout << "Стоимость (руб.): "; cin >> Cost;} //ввод данных
    void show_Name_Cost() {cout << "Фирма: " << Name << "\nСтоимость (руб.): " << Cost << endl;} //вывод данных
    virtual void show_Inf() {cout << "ГРУППА: " << Inf << endl;} //виртуальная функция, выводящая на экран значения класса
};
/////////1 проиводный класс//////////
class Desktop : public Computer   
{
public:
    Desktop() {}; //конструктор без параметров
    Desktop(string Inf1): Computer(Inf1) {} //конструктор с параметрами
    void get_Inf() {cin >> Inf;} //функция, для ввода дополнительной информации
    void show_Inf() {cout << Inf << endl;} //виртуальная функция
    friend int Min(Desktop *x, Laptop *y, int a, int b); //объявление дружественной функции
    bool operator<(Desktop *p1) {return p1[1].Cost<p1[0].Cost;} //оператор-функция, для работы с объектами класса Desktop
};
/////////2 проиводный класс//////////
class Laptop : public Computer   
{
public:
    Laptop() {}; //конструктор без параметров
    Laptop(string Inf1): Computer(Inf1) {} //конструктор с параметрами
    void get_Inf() {cin >> Inf;} //функция, для ввода дополнительной информации
    void show_Inf() {cout << Inf << endl;} //виртуальная функция
    friend int Min(Desktop *x, Laptop *y, int a, int b); //объявление дружественной функции
    bool operator<(Laptop *p2) {return p2[1].Cost<p2[0].Cost;} //оператор-функция, для работы с объектами класса Laptop
};

int Min(Desktop *x, Laptop *y, int a, int b) //дружественная функция, вычис-ляющая наименьшую стоимость
{
    bool m, n;
    int k=x[0].Cost, h=y[0].Cost;
    for (int i=0; i<a-1; i++)
    {
        m = x[i].Cost < x[i+1].Cost;
        if (m==true) k=x[i].Cost;
        else k=x[i+1].Cost;}
    for (int j=0; j<b-1; j++)
    {   n = y[j].Cost < y[j+1].Cost;
        if (n==true) h=y[j].Cost;
        else h=y[j+1].Cost;}
    cout << "\nСтоимость самого дешевого компьютера: ";
    if (k<h) cout << k << endl;
    else cout << h << endl;
};
