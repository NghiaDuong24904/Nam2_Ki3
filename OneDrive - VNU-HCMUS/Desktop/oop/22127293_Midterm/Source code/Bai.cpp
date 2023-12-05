#include "Bai.h"
account::account()
{
    this->id = "";
    this->name = "";
    this->money = 0.0;
}
account::account(string id, string name, double money)
{
    this->id = id;
    this->name = name;
    this->money = money;
}
double account::get_money()
{
    return this->money;
}
string account::get_id()
{
    return this->id;
}
void account::set_money(double money)
{
    this->money = money;
}
void account::nap(double so_tien)
{
    this->money += so_tien;
}
void account::rut(double so_tien)
{
    double tmp = this->money;
    this->money -= so_tien;
    if (this->money < 0)
    {
        cout << "So du tai khoan khong du.\n";
        this->money = tmp;
    }
}
void account::view_money()
{
    cout << "So du tai khoan la: " << this->money << "\n";
}
bool account::operator>(const account &other)
{
    return money > other.money;
}
bool account::operator<(const account &other)
{
    return money < other.money;
}
bool account::operator==(const account &other)
{
    return money == other.money;
}
bool account::operator<=(const account &other)
{
    return operator<(other) || operator==(other);
}
bool account::operator>=(const account &other)
{
    return operator>(other) || operator==(other);
}
void account::view_info()
{
    cout << "CMND/CCCD: " << this->id << "\n";
    cout << "Ho va ten: " << this->name << "\n";
    cout << "So du: " << this->money << "\n";
}
bank::bank()
{
    this->name = "";
    this->addr = "";
    this->list = {};
}
bank::~bank()
{
    this->list.clear();
}
bank::bank(string name, string addr)
{
    this->name = name;
    this->addr = addr;
    this->list = {};
}
void bank::print_dec()
{
    sort(list.begin(), list.end(), dec_money);

    for (auto &acc : list)
    {
        acc.view_info();
    }
}
void bank::update(account &a)
{
    for (auto it = list.begin(); it < list.end(); it++)
    {
        if (it->get_id() == a.get_id())
        {
            it->set_money(a.get_money());
        }
    }
}
bool dec_money(account a, account b)
{
    return a.get_money() > b.get_money();
}
void bank::add(const account &a)
{
    list.push_back(a);
}

double bank::sum_money()
{
    double sum = 0.0;
    for (auto &acc : list)
    {
        sum += acc.get_money();
    }
    return sum;
}
void bank::find_max()
{
    sort(list.begin(), list.end(), dec_money);

    list[0].view_info();
}

void phu_thuoc::rut(double so_tien)
{
    double tmp = this->money;
    this->money -= so_tien;
    if (this->money < 0)
    {
        cout << "So du tai khoan khong du.\n";
        this->money = tmp;
    }
    else if (so_tien > 3000000)
    {
        cout << "Khong rut qua 3 trieu.\n";
        this->money = tmp;
    }
}
string phu_thuoc::get_namephuthuoc()
{
    return this->name_phuthuoc;
}
void phu_thuoc::nap(double so_tien)
{
    this->money += so_tien;
}
string account::get_name(){
    return name;
}
void bank::thaydoi_phuthuoc(phu_thuoc &a)
{
    for (auto it = list.begin(); it < list.end(); it++)
    {
        if (it->get_name() == a.get_namephuthuoc())
        {
            it->set_money(a.get_money());
        }
    }
}