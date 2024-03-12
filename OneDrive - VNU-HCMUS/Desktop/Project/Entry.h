#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Entry{
    protected:
        uint16_t modf_time;
        uint16_t modf_date;
        uint32_t data_size;
        uint16_t name_len;
        uint16_t pass_len;
        uint32_t data_offset;
        string name;
        string pass;
        
        bool isFolder;
        string FullPath;
    private:
        void initial();
        void update_path(Entry * parent);
    public:

};