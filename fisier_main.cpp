//
// Copyright 2010 Ettus Research LLC
// Copyright 2018 Ettus Research, a National Instruments Company
//
// SPDX-License-Identifier: GPL-3.0-or-later
//

#include <uhd/device.hpp>
#include <uhd/utils/safe_main.hpp>
#include <boost/format.hpp>
#include <boost/program_options.hpp>
#include <cstdlib>
#include <iostream>
#include<unistd.h>
//#include<stdlib.h>
#include<string.h>
#include "stare_dispozitiv.h"

namespace po = boost::program_options;

int UHD_SAFE_MAIN(int argc, char* argv[])
{
	devices_found(argc, argv);
	

	pid_t pid;
     char *pathvar;
     char newpath[1000];

     pathvar = getenv("uhd/host/build/utils/");
     strcpy(newpath, pathvar);
     strcat(newpath, ":u/userid/bin");
     setenv("uhd/host/build/utils/", newpath,1);

     if ((pid = fork()) == -1)
        perror("fork error");
     else if (pid == 0) {
        execlp("uhd_usrp_probe", "uhd_usrp_probe", NULL);
        printf("Return not expected. Must be an execlp error.n");
	 }
	return 0;
}
