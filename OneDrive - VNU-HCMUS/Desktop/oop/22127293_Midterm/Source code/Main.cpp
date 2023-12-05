#include <iostream>
#include "Bai.cpp"
using namespace std;
int main()
{
    bank ABC("ABC", "TP Ho Chi Minh,Viet Nam");
    account Huy("22127293", "Huy", 0.0);
    ABC.add(Huy);

    Huy.nap(1000000);
    Huy.rut(2000000);
    Huy.rut(500000);

    ABC.update(Huy);

    account Khanh("22127188", "Khanh", 0.0);
    ABC.add(Khanh);

    Khanh.nap(1000000);
    Khanh.nap(5000000);

    ABC.update(Khanh);

    ABC.print_dec();
    ABC.find_max();

    phu_thuoc Thu("22127283", "Thu", Huy.get_money(), "Huy");
    Thu.nap(200000);
    Thu.rut(300000);

    ABC.thaydoi_phuthuoc(Thu);

    

    return 0;
}