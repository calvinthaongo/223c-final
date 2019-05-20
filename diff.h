#ifndef DIFF_H
#define DIFF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGC_ERROR 1
#define TOOMANYFILES_ERROR 2
#define CONFLICTING_OUTPUT_OPTIONS 3
#define MAXSTRINGS 1024
#define MAXPARAS 4096
#define HASHLEN 200
#define BUFLEN 256
char buf[BUFLEN];
char *strings1[MAXSTRINGS], *strings2[MAXSTRINGS];
// FLAGS
int showversion = 0, showbrief = 0, ignorecase = 0, report_identical = 0, showsidebyside = 0;
int showleftcolumn = 0, showunified = 0, showcontext = 0, suppresscommon = 0, diffnormal = 0;
int count1 = 0, count2 = 0;
typedef struct para para;
struct para {
  char** base;
  int filesize;
  int start;
  int stop;
  char* firstline;   //debug
  char* secondline;
};
char* yesorno(int condition);
FILE* openfile(const char* filename, const char* openflags);
void printleft(const char* left);
void printright(const char* right);
void printboth(const char* left_right);
void printline(void);
para* para_make(char* base[], int size, int start, int stop);
para* para_first(char* base[], int size);
para* para_next(para* p);
size_t para_filesize(para* p);
size_t para_size(para* p);
char** para_base(para* p);
char* para_info(para* p);
int   para_equal(para* p, para* q);
void para_print(para* p, void (*fp)(const char*));
void para_lwr(para* p);
void para_printfile(char* base[], int count, void (*fp)(const char*));
void version(void);
void printleftmatch(const char* left);
void leftminus(const char* left);
void leftplus(const char* left);
void version(void);
void brief(para* p,para* q);
void back2back(para* p,para* q);
void identical(para* p,para* q);
void normal(para* p,para* q);
void checkoption(para* p,para* q);
void leftcolumn(para* p,para* q);
void unified(para* p,para* q);
void context(para* p,para* q);
void suppresscommonl(para* p,para* q);
void printchange1(const char* left);
void printchange2(const char* left);
void printboth2(const char* left_right);
void printleft_leftside(const char* left);
void print_context_plus(const char* right);
void print_context_delete(const char* right);
#endif
