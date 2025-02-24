clear;
clc;

%作最终的 n - (-lg[L^{3-}]) 图
hold on
x=[0 1 2 3 4 5];
y=[0	0.083	0.172	0.252	0.339	0.448];
scatter(x,y,500,'x','LineWidth',3);%数据散点图

xx=0:0.05:6;
yy = 0.0882 * xx - 0.0049;%回归直线
plot(xx,yy);


yline(0.2725);%水平线
xline(3.14512);%竖直线

title('工作曲线','FontSize',25);
xlabel('c','FontSize',25);
ylabel('OD_{510}','FontSize',25);
legend('数据点','拟合直线y = 0.0882x - 0.0049','FontSize',25)
hold off