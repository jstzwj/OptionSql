#ifndef OPTIONSQL_SQL_OPTION_INIT_H
#define OPTIONSQL_SQL_OPTION_INIT_H

#include <thread>

#include <OptionSQL/runtime/platform.h>

namespace option
{
    void option_init();
    void option_manager_init();
    void handle_connections();
}


#endif