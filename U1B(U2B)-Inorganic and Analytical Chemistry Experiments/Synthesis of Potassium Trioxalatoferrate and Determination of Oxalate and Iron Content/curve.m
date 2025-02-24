clear;
clc;

hold on;
%吸收曲线
lambda=[430	450	470	490	495	500	505	508	510	515	520	540	560	580	600];
OD=[0.265	0.306	0.363	0.397	0.402	0.408	0.417	0.42	0.422	0.418	0.403	0.234	0.08	0.033	0.016];
scatter(lambda,OD,500,'x','LineWidth',3);%数据散点图
values1 = spcrv([[lambda(1) lambda lambda(end)];[OD(1) OD OD(end)]],3);%为画平滑曲线进行插值（增加数据间推算的点）
plot(values1(1,:),values1(2,:),'-','LineWidth',3);%画平滑曲线

yline(0.422);%水平线
xline(510);%竖直线

title('吸收曲线','FontSize',25);
xlabel('\lambda /nm','FontSize',25);
ylabel('OD','FontSize',25);
legend('实验数据','吸收曲线','FontSize',25)

hold off;
