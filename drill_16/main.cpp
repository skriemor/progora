#include "Lines_window.h"
#include "Graph.h"
/*
edited:
Lines_window.h,
Lines_window.cpp
*/

int main()
{

    Lines_window win{ Point{100,100}, 1920, 1080, "Lines" };
    
    return gui_main();

}
