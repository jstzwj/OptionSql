#include <iostream>
#include <string>
#include <glog/logging.h>

#include <OptionSQL/sql/option_init.h>

int main(int argc, char** argv)
{
	// HOME_PATH
	std::string home = "./";
	// glog init
	google::InitGoogleLogging(argv[0]);
	std::string info_log = home + "master_info_";
	google::SetLogDestination(google::GLOG_INFO, info_log.c_str());
	std::string warning_log = home + "master_warning_";
	google::SetLogDestination(google::GLOG_WARNING, warning_log.c_str());
	std::string error_log = home + "master_error_";
	google::SetLogDestination(google::GLOG_ERROR, error_log.c_str());
	std::string fatal_log = home + "master_fatal_";
	google::SetLogDestination(google::GLOG_FATAL, fatal_log.c_str());

	LOG(INFO) << "server starting";
    option::option_init();
    option::option_manager_init();// create manager thread
    option::handle_connections();

	return 0;
}