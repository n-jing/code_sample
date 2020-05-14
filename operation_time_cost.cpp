#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <cstring>
using namespace std;

#define EXPR(CODE) {    \
    begin = clock();    \
    for (i = 0; i < n; i++) { CODE; }    \
    cout << #CODE << "\t\t" << \
    (clock() - begin) / CLOCKS_PER_SEC << endl;    \
}


const int n = 1000000000; //10^9

void fun1() { }
int fun2() { return 0; }
int fun3(int i) { return 0; }
int fun4(int a, int b, int c){ return 0; }


int main(int argc, char* argv[])
{
    int i = 0;

    int i1, i2, i3;
    float f1, f2, f3;
    double d1, d2, d3;

    i1 = i2 = i3 = 5000;
    f1 = f2 = f3 = 5000.0;
    d1 = d2 = d3 = 5000.0;

    double begin;

    cout << "\nBit Operations:" << endl;
    EXPR(i1>>1);
    EXPR(i1<<1);
    EXPR(i1>>3);

    cout << "\nInt Operations:" << endl;
    EXPR(i1++);
    EXPR(i1 = i2 + i3);
    EXPR(i1 = i2 - i3);
    EXPR(i1 = i2 * i3);
    EXPR(i1 = i2 / i3);
    EXPR(i1 = i2 % i3);


    cout << "\nFloat Operations:" << endl;
    EXPR(f1 = f2 + f3);
    EXPR(f1 = f2 - f3);
    EXPR(f1 = f2 * f3);
    EXPR(f1 = f2 / f3);


    cout << "\nDouble Operations:" << endl;
    EXPR(d1 = d2 + d3);
    EXPR(d1 = d2 - d3);
    EXPR(d1 = d2 * d3);
    EXPR(d1 = d2 / d3);


    cout << "\nNumeric Conversions:" << endl;
    EXPR(i1=(int)f1);
    EXPR(i1=(int)d1);
    EXPR(f1=(float)i1);


    cout << "\nMath Functions:" << endl;
    EXPR(i1 = rand());
    EXPR(f1 = log(f2));
    EXPR(f1 = exp(f2));
    EXPR(f1 = sin(f2));
    EXPR(f1 = cos(f2));
    EXPR(f1 = sqrt(f2));


    cout << "\nFun Call:" << endl;
    EXPR(fun1());
    EXPR(i1 = fun2());
    EXPR(i1 = fun3(i1));
    EXPR(i1 = fun4(i1, i2, i3));

    EXPR(if ( i1 == 5));
    EXPR(if ( i1 > 5));
    EXPR(if ( i1 != 5));

    cout << "\nMalloc:" << endl;
    EXPR(free(malloc(8)));

    char str1[] = "1234567890";
    char *str2;
    str2 = (char*)malloc(strlen(str1) + 1);
    strcpy(str2, str1);

    cout << "\nString Functinos:" << endl;
    EXPR(i1 = strlen(str1));
    EXPR(strcpy(str2, str1));
    EXPR(i1 = strcmp(str2, str1));

    char s[100];
    cout << "\nString/Number Conversions:" << endl;

    EXPR(i1 = atoi("12345"));
    EXPR(sscanf("12345", "%d", &i1));
    EXPR(sprintf(s, "%d", i));

    EXPR(f1 = atof("123.45"));
    EXPR(sscanf("123.45", "%f", &f1));
    EXPR(sprintf(s, "%6.2f", 123.45));


    cout << "\nInput/Ouput:" << endl;

    FILE *fp = fopen("source1", "w+");

    if (fp == NULL) { return -1; }
    EXPR(fprintf(fp, "%d\n", i1));
    EXPR(fscanf(fp, "%d", &i1));

    fclose(fp);

    fp = fopen("source2", "w+");
    if (fp == NULL) { return -1; }

    EXPR(fputs("hello", fp));
    EXPR(fgets(s, 100, fp));

    fclose(fp);

    return 0;
}
