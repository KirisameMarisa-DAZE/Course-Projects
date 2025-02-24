clear;
clc;
x=[0.1976
0.2133];
y=[2.277327935
2.344116268];
hold on;
scatter(x,y,'x','black');
y=1.4367 + 4.254*x;
plot(x,y);
legend('原始数据','回归直线h/t=1.4367 + 4.254 x');
title('实验数据处理');
xlabel('t(s)');
ylabel('h/t(m/s)');
hold off;

 4.5705*2