/*
 * vim: set tabstop=4 syntax=c :
 *
 * Copyright (C) 2014-2017, Peter Haemmerlein (peterpawn@yourfritz.de)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program, please look for the file LICENSE.
 */

#ifndef OPTIONS_H

#define OPTIONS_H

// helper macros

#define altenv_options_long				{ "alt-env", required_argument, NULL, 'a' }

#define altenv_options_short			"a:"

#define check_altenv_options_short()	case 'a':\
											if ((altEnv = setAlternativeEnvironment(optarg)) == false)\
												return EXIT_FAILURE;\
											break

#define altenv_verbose_message()		if (altEnv)\
											verboseMessage("using alternative environment path '%s'\n", getEnvironmentPath())

#define width_options_long				{ "wrap-lines", optional_argument, NULL, 'w' }

#define width_options_short				"w::"

#define check_width_options_short()		case 'w':\
											if (setLineWidth(optarg, getopt_option_name()) == false)\
												return EXIT_FAILURE;\
											break

// function prototypes

bool									setAlternativeEnvironment(char * newEnvironment);
bool									setLineWidth(char * value, const char * option);
bool									checkLastArgumentIsInputFile(char * name);
void									warnAboutExtraArguments(char ** argv, int i);

#endif