#include<stdio.h>
int main(){
    int num,i,t=0;//num为学号,t为85分及以上的人数
    float avgscore[30],scr1,scr2,scr3,c;//avgscore为每人的平均分；scr1~3为3科各自的成绩，c是冒泡排序法中用来调换顺序的临时变量
    FILE *fp;
    fp = freopen("/Users/page/Documents/4-app/Homework/All_Homework_c/120501/120501/in.txt","r",stdin);//将"输入"重定向到文件"in.txt"
    /*
     <stdio.h>中的
     freopen("D:\\in.txt","r",stdin)的作用,
     就是把标准输入流stdin重定向到D:\\in.txt文件中，
     这样在用scanf(C语法)或是用cin(C++语法)输入时便不会从标准输入流读取数据,
     而是从in.txt文件中获取输入。（"输入"是指从外部文件中获取输入）
     只要把输入数据事先粘贴到in.txt中即可。
     
     类似的，
     freopen("D:\\out.txt","w",stdout)的作用,
     就是把stdout重定向到D:\\out.txt文件中(若有原文件，则抹除后输入；若无，则新建一个)，
     这样输出结果就可以通过打开out.txt文件查看。
     */
    for(i=0;(fscanf(fp,"%d%f%f%f",&num,&scr1,&scr2,&scr3)!=EOF)&&i<=29;i++){//四个数据为一组是一个人的数据
        /*fscanf(文件，提取对象，指针)意为从文件fp中依次提取一组符合要求的数据并存放到变量中*/
        avgscore[i]=(scr1+scr2+scr3)/3.0;//计算平均数并赋值给average[i]
    }//得到全班的平均分
    //冒泡排序法
    for(int j = 29; j > 0 ; j--) {
        for(int i = 30; i > 29 - j; i--) {
            if(avgscore[i] > avgscore[i - 1]) {
                c = avgscore[i];
                avgscore[i] = avgscore[i - 1];
                avgscore[i - 1] = c;
            }
            else{
                continue;
            }
        }
    }
    fclose(fp);//关闭定向输入
    for(int i = 0; i < 30; i++) {//输出排序后的平均值
        printf("第%d名：平均%f分\n",i+1, avgscore[i]) ;
        if(avgscore[i]>=85){
            t++;
        }
    }
    printf("\n平均分85分及以上共有%d人。\n",t);//输出85分及以上总人数
    return 0;
}
