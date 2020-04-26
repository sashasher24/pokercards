#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *mx_strcpy(char *dst, const char *src);

int mx_strcmp(const char *s1,const char *s2);

int mx_atoi(const char *str);

void mx_printint(int n);

bool mx_isspace(char c);

bool mx_isdigit(int c);

int mx_strlen(const char *s);

void mx_printerr(const char *s);

void mx_printstr(const char *s);

void mx_printchar(char c);
