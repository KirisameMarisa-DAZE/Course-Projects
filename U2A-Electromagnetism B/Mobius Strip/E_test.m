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
x0=0;y0=0;z0=0;
r=sqrt((x-x0).^2+(y-y0).^2+(z-z0).^2);

% 面元dS的面积元素(E==1)
G=(-sin(phi)-0.5.*t.*sin(phi./2).*cos(phi)-t.*cos(phi./2).*sin(phi)).^2+(cos(phi)-0.5.*t.*sin(phi./2)+t.*cos(phi./2).*cos(phi)).^2+(0.5.*t.*cos(phi./2)).^2;
F=-0.5.*t.*sin(phi).*(cos(phi).^2);

% 各个分量的需要积分的部分
funx=sqrt(G-F.^2).*(x0-x)./(r.^3);
fx=matlabFunction(funx);% 参数化
funy=sqrt(G-F.^2).*(y0-y)./(r.^3);
fy=matlabFunction(funy);
funz=sqrt(G-F.^2).*(z0-z)./(r.^3);
fz=matlabFunction(funz);

% 各个分量需要积分的部分的积分
Funx=integral2(fx,-0.5,0.5,0,2.*pi);
Funy=integral2(fy,-0.5,0.5,0,2.*pi);
Funz=integral2(fz,-0.5,0.5,0,2.*pi);
Fun=sqrt(Funx.^2+Funy.^2+Funz.^2);

% σ, ε_0
sigma=1;
epsilon_0=8.854187817e-12;

% 场强及其分量
disp(sigma./(4.*pi.*epsilon_0).*Funx);% Ex
disp(sigma./(4.*pi.*epsilon_0).*Funy);% Ey
disp(sigma./(4.*pi.*epsilon_0).*Funz);% Ez
E=sigma./(4.*pi.*epsilon_0).*Fun;
fprintf('res=%s\n',E);