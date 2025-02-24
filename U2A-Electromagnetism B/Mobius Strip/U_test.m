% 清屏
% clc;
clear;

% 给出莫比乌斯带的参数方程
syms t phi;
R=1;
x=(R+t.*cos(phi./2)).*cos(phi);
y=(R+t.*cos(phi./2)).*sin(phi);
z=t.*sin(phi./2);
% 给出空间中一点到面上某点的距离r
syms x0 y0 z0
x0=1;y0=1;z0=1;
r=sqrt((x-x0).^2+(y-y0).^2+(z-z0).^2);

% 面元dS的面积元素(E==1)
G=(-sin(phi)-0.5.*t.*sin(phi./2).*cos(phi)-t.*cos(phi./2).*sin(phi)).^2+(cos(phi)-0.5.*t.*sin(phi./2)+t.*cos(phi./2).*cos(phi)).^2+(0.5.*t.*cos(phi./2)).^2;
F=-0.5.*t.*sin(phi).*(cos(phi).^2);

% 电势的需要积分的部分
fun=sqrt(G-F.^2)./r;
f=matlabFunction(fun);% 参数化

% 电势需要积分的部分的积分
Fun=integral2(f,-0.5,0.5,0,2.*pi);

% σ, ε_0
sigma=1;
epsilon_0=8.854187817e-12;

% 电势
U=-sigma./(4.*pi.*epsilon_0).*Fun;
disp(U)