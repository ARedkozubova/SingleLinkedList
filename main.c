/*
 * File: dl_list
 * Brief: TODO
 * Author: Anastasia Redkozubova
 * Created on: 18.11.2019
 * (c) MIPT
*/

#include "pch.h"
#include "dl_list.h"
#include "dl_tests.h"
#include <stdio.h>
#include <string.h>

void print_usage(char *prog_name)
{
	printf("%s <mode>", prog_name);
	printf("Modes:\n");
	printf("test\tRun all tests\n");
	printf("task\tRun task code\n");
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		print_usage(argv[0]);
		return -1;
	}

	if (!strcmp(argv[1], "test"))
	{
		run_all_tests();
		return 0;
	}


	return 0;
}