clear;clc;

R=1;i=1;j=1;k=1;
Ex=zeros(5,5,5);
Ey=zeros(5,5,5);
Ez=zeros(5,5,5);
E=zeros(5,5,5);

for x=-2:1:2
    for y=-2:1:2
        for z=-2:1:2
            [ex,ey,ez,e]=Ee(R,x,y,z);
            Ex(i,j,k)=ex;
            Ey(i,j,k)=ey;
            Ez(i,j,k)=ez;
            E(i,j,k)=e;
            if (e>10e10)
                Ex(i,j,k)=0;
                Ey(i,j,k)=0;
                Ez(i,j,k)=0;
                E(i,j,k)=0;
            end
            disp(i)
            disp(j)
            disp(k)
            fprintf('\n');
            k=k+1;
        end
        j=j+1;
        k=1;
    end
    i=i+1;
    j=1;
    k=1;
end


x=[-2:1:2];
y=[-2:1:2];
z=[-2:1:2];
[X,Y,Z] = meshgrid(x,y,z);
hold on
quiver3(X,Y,Z,Ex,Ey,Ez);
grid on;
axis equal;

t=linspace(-0.5,0.5,40);
phi=linspace(0,2.*pi,40);
[T,Phi]=meshgrid(t,phi);
x=(1+T.*cos(Phi./2)).*cos(Phi);
y=(1+T.*cos(Phi./2)).*sin(Phi);
z=T.*sin(Phi./2);
surf(x,y,z);
colormap spring;

grid on;%网格线
xlabel('x');%x轴名称
ylabel('y');%y轴名称
zlabel('z');%z轴名称
hold off