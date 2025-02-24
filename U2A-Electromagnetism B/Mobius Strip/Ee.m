function [Ex,Ey,Ez,E] = Ee(R,x0,y0,z0)
% 输入莫比乌斯带半径R及空间中某点坐标(x0,y0,z0)
% 输出该点场强E及其分量Ex,Ey,Ez

% 给出莫比乌斯带的参数方程
syms t phi;
x=(1+t.*cos(phi./2)).*cos(phi);
y=(1+t.*cos(phi./2)).*sin(phi);
z=t.*sin(phi./2);
% 给出空间中一点到面上某点的距离r
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
% 总场强需要积分的部分的积分
Fun=sqrt(Funx.^2+Funy.^2+Funz.^2);

% σ, ε_0
sigma=1;
epsilon_0=8.854187817e-12;

% 场强及其分量
Ex=sigma./(4.*pi.*epsilon_0).*Funx;
Ey=sigma./(4.*pi.*epsilon_0).*Funy;
Ez=sigma./(4.*pi.*epsilon_0).*Funz;
E=sigma./(4.*pi.*epsilon_0).*Fun;

end

