#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class account
{
protected:
    string id;
    string name;
    double money;

public:
    account();
    account(string id, string name, double money);
    double get_money();
    string get_id();
    string get_name();
    void set_money(double money);
    virtual void nap(double so_tien);
    virtual void rut(double so_tien);
    void view_money();
    bool operator>(const account &other);
    bool operator<(const account &other);
    bool operator==(const account &other);
    bool operator<=(const account &other);
    bool operator>=(const account &other);
    void view_info();
};

class phu_thuoc : public account
{
private:
    string name_phuthuoc;

public:
    phu_thuoc() : account(), name_phuthuoc(""){};
    phu_thuoc(string id, string name, double money, string name_phuthuoc) : account(id, name, money), name_phuthuoc(name_phuthuoc){};
    void rut(double so_tien) override;
    void nap(double so_tien) override;
    string get_namephuthuoc();
};

bool dec_money(account a, account b);
class bank
{
private:
    string name;
    string addr;
    vector<account> list;

public:
    bank();

    ~bank();

    bank(string name, string addr);

    void add(const account &a);
    void update(account &a);
    void print_dec();
    void find_max();
    double sum_money();
    void thaydoi_phuthuoc(phu_thuoc &a);
};
