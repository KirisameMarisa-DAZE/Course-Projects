clear;
clc;
t=linspace(-0.5,0.5,40);
phi=linspace(0,2.*pi,40);
[T,Phi]=meshgrid(t,phi);
x=(1+T.*cos(Phi./2)).*cos(Phi);
y=(1+T.*cos(Phi./2)).*sin(Phi);
z=T.*sin(Phi./2);
surf(x,y,z);
colormap spring;

% clear;
% clc;
% rho=linspace(-0.5,0.5,40);
% theta=linspace(0,2.*pi,40);
% [Rho,Theta]=meshgrid(rho,theta);
% x=(1+Rho.*sin(Theta./2)).*cos(Theta);
% y=(1+Rho.*sin(Theta./2)).*sin(Theta);
% z=Rho.*coZ(Theta./2);
% surf(x,y,z);
% colormap spring;