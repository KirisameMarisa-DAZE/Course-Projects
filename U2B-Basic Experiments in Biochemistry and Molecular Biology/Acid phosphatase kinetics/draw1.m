clear;
clc;
hold on;
x=[1.000 	2.000 	3.000 	4.000 	5.000 ];
y1=[0.0041333333 	0.0092666667 	0.0154666667 	0.0214000000 	0.0270000000 ];
y2=[0.0072666667 	0.0112000000 	0.0158666667 	0.0202666667 	0.0234000000 ];
y3=[0.0028666667 	0.0048666667 	0.0066000000 	0.0082000000 	0.0088000000 ];

scatter(x,y1,'xk');%散点图
scatter(x,y2,'+k');
scatter(x,y3,'ok');

values1 = spcrv([[x(1) x x(end)];[y1(1) y1 y1(end)]],3);%为画平滑曲线进行插值（增加数据间推算的点）
values2 = spcrv([[x(1) x x(end)];[y2(1) y2 y2(end)]],3);
values3 = spcrv([[x(1) x x(end)];[y3(1) y3 y3(end)]],3);

plot(values1(1,:),values1(2,:),'-k');%画平滑曲线
plot(values2(1,:),values2(2,:),'--k');
plot(values3(1,:),values3(2,:),'-.k');

title('可逆性判断');
xlabel('[E]');
ylabel('v');
legend('无抑制剂','KH_2PO_4','NaF','无抑制剂','KH_2PO_4','NaF')

hold off;