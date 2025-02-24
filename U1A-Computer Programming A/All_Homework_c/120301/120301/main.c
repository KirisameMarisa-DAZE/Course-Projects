//
//  main.c
//  120301
//
//  Created by 李佩哲 on 2021/10/14.
//

#include <stdio.h>

int main() {
    int a = 2, b = 3, c = 4;
    float x = 3.5, y = 4.8;
    float a1, a2, a3, a4;
    int b1, b2, b3, b4, b5, c1, c2, c3, c4, c5, c6;
    //scanf("%d%d%d%f%f", &a, &b, &c,&x,&y);
    //printf("%d\n%d\n%d\n%f\n%f", a, b, c, x, y);
    a1 = (3.5 + 1/2 + 56 % 10);
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    a2 = (a++*1/3);
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    a3 = (x + a % 3*(int) (x + y)  % 2/4);
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    a4 = ((float) (a + b) /2 + (int) x % (int) y);
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    b1 = (b > c&&b == c);
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    b2 = (!(a > b) &&!c||1);
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    b3 = !(x = a) &&(y = b) &&0;
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    b4 = (!(a + b)  + c - 1&&b + c/2);
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    b5 = (1&&30 % 10 >= 0&&30 % 10 <= 3);
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    c1 = a += a + b;
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    c2 = a*= b % c;
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    c3 = a/= c - a;
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    c4 = a += a -= a*= a;
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    c5 = a = (a = ++b, a + 5, a/5);
    a = 2; b = 3; c = 4; x = 3.5; y = 4.8;
    c6 = (a >= b >= 2)  ? 1:0;
    printf("1\na=%f\nb=%f\nc=%f\nd=%f\n", a1, a2, a3, a4);
    printf("2\na=%f\nb=%f\nc=%f\nd=%f\ne=%f\n", b1, b2, b3, b4, b5);
    printf("3\na=%f\nb=%f\nc=%f\nd=%f\ne=%f\nf=%f\n", c1, c2, c3, c4, c5, c6);
    return 0;
}
