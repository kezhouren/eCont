#include <stdio.h>
#include <vector>
//#include "./include/define.h"
#include "./include/record.h"
#include "./include/view.h"
#include "./include/print.h"
//#include "./include/page.h"
#include "./include/operation.h"
//#include "./include/file.h"
//#include "./include/create_data.h"
//#include "./include/client.h"
//#include "./incude/server.h"

//using namespace std;
int main(int argc, char** argv)
{
    char key;
    std::vector<Record*> list;
    print_help(); 
    init_data(100, list);
    while(1)
    {
    }
    return 0;
}

