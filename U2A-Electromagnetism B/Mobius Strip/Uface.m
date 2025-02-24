clear;clc;

R=1;i=1;j=1;k=1;

U=zeros(1,125);
for x=-2:1:2
    for y=-2:1:2
        for z=-2:1:2
            [u]=Uu(R,x,y,z);
            U((i-1)*25+(j-1)*5+k)=u;
%             if (e>10e10)
%                 Ex(i,j,k)=0;
%                 Ey(i,j,k)=0;
%                 Ez(i,j,k)=0;
%                 E(i,j,k)=0;
%             end
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

X=zeros(1,125);
Y=zeros(1,125);
Z=zeros(1,125);
for i=1:1:5
    for j=1:1:5
        for k=1:1:5
            X((i-1)*25+(j-1)*5+k)=i-3;
            Y((i-1)*25+(j-1)*5+k)=j-3;
            Z((i-1)*25+(j-1)*5+k)=k-3;
        end
    end
end


hold on
scatter3(X,Y,Z,U.*(10.^(-8.5)),U,'filled');
axis equal;

t=linspace(-0.5,0.5,40);
phi=linspace(0,2.*pi,40);
[T,Phi]=meshgrid(t,phi);
x=(1+T.*cos(Phi./2)).*cos(Phi);
y=(1+T.*cos(Phi./2)).*sin(Phi);
z=T.*sin(Phi./2);
surf(x,y,z);
colormap spring;


colorbar;%颜色栏图例
grid on;%网格线
xlabel('x');%x轴名称
ylabel('y');%y轴名称
zlabel('z');%z轴名称
hold off