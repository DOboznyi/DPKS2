//
//  main.cpp
//  DPKS2
//
//  Created by Dmytro Oboznyi on 01.03.2020.
//  Copyright © 2020 Dmytro Oboznyi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/* Flag set by ‘--verbose’. */
static int verbose_flag;

void version(){
  puts ("Arg: Version\n");
}

void help(){
  puts ("Arg: Help\n");
}

void value(char* val){
  printf ("Arg: Value with value '%s'\n", val);
}

void list(char* lst){
  if (lst!=NULL){ 
    printf ("Arg: List with list of values '%s'\n", lst);
  }
  else {
    printf ("Arg: List\n");
  }
}

int
main (int argc, char **argv)
{
  int c;
  bool l = true;
  bool v = true;
  bool h = true;
  bool V = true;

  while (1)
    {
      static struct option long_options[] =
        {
          {"list",    optional_argument, 0, 'l'},
          {"version", no_argument,       0, 'v'},
          {"help",    no_argument,       0, 'h'},
          {"value",   required_argument, 0, 'V'},
          {"list",    optional_argument, 0, 'L'},
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "l::vhV:L::",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (c == -1)
        break;

      switch (c)
        {
        case 0:
          /* If this option set a flag, do nothing else now. */
          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        case 'l':
          if (l){
            list(optarg);
            l=!l;
          }
          break;

        case 'v':
          if (v){
            version();
            v=!v;
          }
          break;

        case 'h':
          if (h){
            help();
            h=!h;
          }
          break;

        case 'V':
          if (V){
            value(optarg);
            V=!V;
          }
          break;

        case 'L':
          if (l){
            list(optarg);
            l=!l;
          }
          break;

        case '?':
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
    }

  /* Print any remaining command line arguments (not options). */
  if (optind < argc)
  {
    exit(1);
  }

  exit (0);
}
