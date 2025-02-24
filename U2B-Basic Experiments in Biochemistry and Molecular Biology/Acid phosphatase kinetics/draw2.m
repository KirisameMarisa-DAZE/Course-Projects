clear;
clc;
hold on;
x=[2.000000 	1.428571 	1.000000 	0.800000 	0.606061 	0.400000 ];
y1=[93.750000 	64.655172 	47.318612 	39.473684 	35.460993 	32.537961 ];
y2=[156.250000 	114.503817 	75.757576 	67.873303 	49.833887 	41.095890 ];
y3=[394.736842 	326.086957 	283.018868 	245.901639 	197.368421 	174.418605 ];

scatter(x,y1,'xk');%散点图
scatter(x,y2,'+k');
scatter(x,y3,'ok');

values1 = spcrv([[x(1) x x(end)];[y1(1) y1 y1(end)]],3);%为画平滑曲线进行插值（增加数据间推算的点）
values2 = spcrv([[x(1) x x(end)];[y2(1) y2 y2(end)]],3);
values3 = spcrv([[x(1) x x(end)];[y3(1) y3 y3(end)]],3);

plot(values1(1,:),values1(2,:),'-k');%画平滑曲线
plot(values2(1,:),values2(2,:),'--k');
plot(values3(1,:),values3(2,:),'-.k');

title('竞争性判断');
xlabel('1/[S]');
ylabel('1/v');
legend('无抑制剂','KH_2PO_4','NaF','无抑制剂','KH_2PO_4','NaF')

hold off;