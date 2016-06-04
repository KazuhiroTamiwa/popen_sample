#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <iostream>
#include <string>
#include <vector>
#define BUF 256
using namespace std;

int main (int argc, char *argv[])
{
	FILE *fp;
	char buf[BUF];
	string cmdline = "cd ~/tmp; ls | xargs -L 1 echo `pwd`/ | sed -e 's| ||g'";
	vector<string> v;

	if ( (fp = popen(cmdline.c_str(),"r")) == NULL) {
		err(EXIT_FAILURE, "%s", cmdline.c_str());
	}

	while(fgets(buf, BUF, fp) != NULL) {
		v.push_back(buf);
	}

	(void) pclose(fp);


	cout << v[0];

	exit (EXIT_SUCCESS);
}
