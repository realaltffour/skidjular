#ifndef MODULE_SKIDS_H
#define MODULE_SKIDS_H

#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "data.h"
#include "log.h"
#include "module.h"

enum skidsActType { init, init_now, now, this_, set };
struct skids_args {
	skidsActType			 type;
	std::vector<std::string> action_param;

	DB* db;
};
struct skids_mod : skids_args, Module {};

skids_mod* skids_new();
void	   skids_init(skids_args args);
void	   skids_init_now(skids_args args);
void	   skids_now(skids_args args);
void	   skids_this(skids_args args);
void	   skids_set(skids_args args);
void	   skids_dispatch(const std::vector<std::string>& arguments);

#endif
