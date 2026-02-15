#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdint.h>
char pw[]="jeiguo.txt";
void putfengexian(int);
int caidan1(void);
int if1_1(void);
int get2(int);
int masjiao(int*,int);
int caidan1_1(void);
void putjiao(int*,int,int);
int suanwei(int);
void putk(int);
int caidan1_1_1(void);
int caidan1_1_2(void);
int if1_2(void);
int caidan1_2(void);
unsigned long long masc(int,int);
int maswei(unsigned long long);
void put2(unsigned long long,int);
int if1_3(void);
int suanwei2(int,int);
void masdashu(int,int,int,unsigned long long*);
int getmax5(int);
int mi(int,int);
int caidan1_3(void);
void putmas1(unsigned long long*,int,int,int);
int if1_4(void);
int main(void) {SetConsoleOutputCP(CP_UTF8);
	puts("这是一个算一些排列组合数的小工具(v1.0)");
    puts("这样当你寒假作业中遇到此类题目时就可以快速且优雅的解决(骗你的该不会还不会,会的不用还更快)");
    puts("可能有点小bug所以“zoumou2009@outlook.com”我的邮箱有bug可以发我十分感谢");
    puts("请选择你所需要的模式");
	{int a;
	while(1){
	put:a=caidan1();
    switch (a){
    case 1 :if(if1_1()==0)goto put;else goto out;break;
    case 2 :if(if1_2()==0)goto put;else goto out;break;
	case 3 :if(if1_3()==0)goto put;else goto out;break;
    case 4 :if(if1_4()==0)goto put;else goto out;break;
    default :goto out;break;
    }
	}}
	out:printf("感谢使用——qq%lld(骗你的我乱打的)\n",time(NULL));system("pause");return 0;
}
void putfengexian(int a){for (int i=0; i<a+1; i++)putchar('=');putchar('\n');}
int caidan1(void){
putfengexian(60);
puts("1 创建杨辉(帕斯卡)三角,最大30次幂");
puts("2 计算具体二项式系数(组合数),排列数,底数最大60");
puts("3 计算排列数,底数最大60");
puts("4 清空输出文件");
puts("5 关闭程序");
putfengexian(60);
int a;char c;
while(1){
c=getchar();a=c-'0';
if(a>=1&&a<=5&&getchar()=='\n')return a;
else if(c=='\n')puts("别闹了孩子");
else{puts("无法解析你所输入的指示,输入1,2,3,4,5好么");while (getchar() != '\n') continue;}
}}
int if1_1(void){    
int a,b,c;int*p;get:puts("这是一个生成二项式系数三角的程序,或称杨辉三角。");puts("请输入不超过30的非负数,太大int装不下,再说你要那么大的三角干嘛");a=get2(30);p=malloc((a+2)*(a+1)/2*sizeof(int));
if(p==NULL){fprintf(stderr,"错误,无法申请到所需内存,已关闭程序");system("pause");exit(EXIT_FAILURE);}
else{b=masjiao(p,a);printf("次数%d,元素量%d\n",a,b+1);
puts("已生成完毕，请选择相应模式");
put:c=caidan1_1();
switch (c){
case 1 :{int r;
if(a>10){puts("你这比10次大了就生成10次的哈,要完整版返回去选2选项");putjiao(p,10,65);}else putjiao(p,a,b);puts("已生成完毕，请选择相应模式");
r=caidan1_1_1();if(r==1){free(p);goto get;}if(r==2)goto put;if(r==3)goto out;}	
case 2 :{FILE*fp;fp=freopen(pw,"a",stdout);if(fp==NULL){fprintf(stderr,"错误,无法重定向为文件,已返回上级");goto put;}
else{printf("%llu  %d\n",time(NULL),a);putjiao(p,a,b);fp=freopen("CON","w",stdout);}if(fp==NULL){fprintf(stderr,"错误,无法重定向为控制台,已关闭程序");system("pause");exit(EXIT_FAILURE);}
puts("已生成完毕,请选择相应模式");int k;put1:k=caidan1_1_2();
if(k==1){free(p);goto get;}
if(k==2){int a;a=ShellExecuteA(NULL,"open",pw,NULL,NULL,SW_SHOWNORMAL);if(a>32){puts("已成功打开");goto put1;}else{puts("打开失败,请检查文件夹");goto put1;}}
if(k==3)goto put;
if(k==4)goto out;	
}
case 3 :free(p);return 0;
default :out:return 1;
}}}
int caidan1_1(void){
putfengexian(60);
puts("1 输出在屏幕(只显示10次以内)");
puts("2 输出在txt文件(在程序所在文件夹,且为UTF-8编码文件哦)");
puts("3 返回上级(将清除已算好的数据,无伤大雅只做说明)");
puts("4 关闭程序");
putfengexian(60);
int a;char c;
while(1){
c=getchar();a=c-'0';
if(a>=1&&a<=4&&getchar()=='\n')return a;
else if(c=='\n')puts("别闹了孩子");
else{puts("无法解析你所输入的指示,输入1,2,3,4好么");while (getchar() != '\n') continue;}
}}
void putjiao(int*p,int a,int b){int w,m,i,o;m=suanwei(p[b-a+a/2]);w=(2*a+1)*m;
putfengexian(w+2*m);
for(i=0;i<=a;i++){printf("%d",i);putk(m-suanwei(i));putk(m);putk((w-m*(2*i+1))/2);
for(o=0;o<=i;o++){
if(o==0)putchar('1');
else if(o==i){putk(m-1);putchar('1');}
else{putk(m-suanwei(p[((i+2)*(i+1)/2)-i-1+o]));printf("%d",p[(((i+2)*(i+1))/2)-i-1+o]);}
if(o!=i)putk(m);
}putchar('\n');}
putfengexian(w+2*m);}
int suanwei(int a){int e=0;if(a==0)return 1;while(a>0){a/=10;e++;}return e;}
void putk(int a){for(int i=0;i<a;i++)putchar(' ');}
int get2(int r) {
int a, b[2], i; char c[2];
while (1) {
for (i = 0; i < 2; i++) { c[i] = getchar(); b[i] = c[i] - '0'; }
if ((b[0] >= 0 && b[0] <= 9) && (c[1] == '\n')) { a = b[0];return a; }
else if ((((b[0] >= 0 && b[0] <= (r/10-1)) && (b[1] >= 0 && b[1] <= 9)) || (b[0]==r/10&&(b[1]>=0&&b[1]<=r%10)))&&(getchar()=='\n'))
{a = (10 * b[0] + b[1]);return a;}
else if(c[0]=='\n'&&c[1]=='\n')puts("别闹了孩子");
else if(c[0]=='\n'){puts("不要回车起手");while (getchar() != '\n') continue;}
else {printf("这还是小于或等于%d的非负数么\n",r);while (getchar() != '\n') continue;}
}}
int masjiao(int*p,int a){
int i,q,e;e=0;
for (i = 0; i < a+1; i++){for (q = 0; q < i+1; q++){
if(q==0||q==i)p[e]=1;
else p[e]=p[e-i]+p[e-i-1];
e++; 
}}
return e-1;
}
int caidan1_1_1(void){
putfengexian(60);
puts("1 输入新值");
puts("2 返回上级");
puts("3 关闭程序");
putfengexian(60);
int a;char c;
while(1){
c=getchar();a=c-'0';
if(a>=1&&a<=3&&getchar()=='\n')return a;
else if(c=='\n')puts("别闹了孩子");
else{puts("无法解析你所输入的指示,输入1,2,3好么");while (getchar() != '\n') continue;}
}}
int caidan1_1_2(void){
putfengexian(60);
puts("1 输入新值");
puts("2 打开文件");
puts("3 返回上级");
puts("4 关闭程序");
putfengexian(60);
int a;char c;
while(1){
c=getchar();a=c-'0';
if(a>=1&&a<=4&&getchar()=='\n')return a;
else if(c=='\n')puts("别闹了孩子");
else{puts("无法解析你所输入的指示,输入1,2,3,4好么");while (getchar() != '\n') continue;}
}}
int if1_2(void){int a,b,c,g;unsigned long long d;puts("这是计算下标60以内排列数的程序");
get:puts("请输入下标(不超过60的非负数)");a=getmax5(60);printf("下标%d\n",a);
puts("请输入上标(不超过下标的非负数)");b=getmax5(a);printf("上标%d\n",b);
d=masc(a,b);c=maswei(d);printf("计算完成结果为%d位数,请选择相应模式\n",c);
put:g=caidan1_2();switch (g)
{
case 1:{int w; put2(d,c);puts("输出成功,请选择相应模式");w=caidan1_1_1();
if(w==1)goto get;if(w==2)goto put;if(w==3)goto out;}
case 2:{FILE*fp;
fp=freopen(pw,"a",stdout);if(fp==NULL){fprintf(stderr,"错误,无法重定向为文件,已返回上级");goto put;}
printf("%llu   C(%d,%d)\n",time(NULL),a,b);put2(d,c);fp=freopen("CON","w",stdout);if(fp==NULL){fprintf(stderr,"错误,无法重定向为控制台,已关闭程序");system("pause");exit(EXIT_FAILURE);}
put1:puts("已生成完毕,请选择相应模式");int k=caidan1_1_2();
if(k==1)goto get;
if(k==2){int a;a=ShellExecuteA(NULL,"open",pw,NULL,NULL,SW_SHOWNORMAL);if(a>32){puts("已成功打开");goto put1;}else{puts("打开失败,请检查文件夹");goto put1;}}
if(k==3)goto put;
if(k==4)goto out;
}
case 3:return 0;
default:out:return 1;  
}}
int caidan1_2(void){
putfengexian(60);
puts("1 输出在屏幕");
puts("2 输出在txt文件(在程序所在文件夹,且为UTF-8编码文件哦)");
puts("3 返回上级(将清除已算好的数据,无伤大雅只做说明)");
puts("4 关闭程序");
putfengexian(60);
int a;char c;
while(1){
c=getchar();a=c-'0';
if(a>=1&&a<=4&&getchar()=='\n')return a;
else if(c=='\n')puts("别闹了孩子");
else{puts("无法解析你所输入的指示,输入1,2,3,4好么");while (getchar() != '\n') continue;}
}}
unsigned long long masc(int a,int b){if(a==0||b==0||a==b)return 1;
unsigned long long*p,*j;b=(a-b)>b?b:(a-b);int i,o;
p=malloc((b+1)*sizeof(unsigned long long));j=malloc((b+1)*sizeof(unsigned long long));if(p==NULL||j==NULL){fprintf(stderr,"错误,无法申请到所需内存,已关闭程序");system("pause");exit(EXIT_FAILURE);}
for(i=0;i<=a;i++){for(o=0;i<b?o<=i:o<=b;o++){
if(o==0||o==i)i%2==0?(p[o]=1):(j[o]=1);
else i%2==0?(p[o]=j[o]+j[o-1]):(j[o]=p[o]+p[o-1]);
}}i--;
if(i%2==0){unsigned long long k=p[b];free(p);free(j);return k;}
else{unsigned long long k=j[b];free(p);free(j);return k;}
}
int maswei(unsigned long long a){return (int)(log10((double)a)+1);}
void put2(unsigned long long a,int b){putfengexian(b-1);printf("%llu\n",a);putfengexian(b-1);}
int if1_3(void){int a,b,c,d;unsigned long long*p;puts("这是一个计算下标最大为60的排列数的程序");
get:puts("请输入下标(不超过60的非负数)");a=getmax5(60);printf("下标%d\n",a);
puts("请输入上标(不超过下标的非负数)");b=getmax5(a);printf("上标%d\n",b);
c=(suanwei2(a,b)/16*16!=suanwei2(a,b))?suanwei2(a,b)/16+1:suanwei2(a,b)/16;                         
p=malloc(c*sizeof(unsigned long long));if(p!=NULL)memset(p,0,c*sizeof(unsigned long long));else{fprintf(stderr,"错误,无法申请到所需内存,已关闭程序");system("pause");exit(EXIT_FAILURE);}masdashu(a,b,c,p);printf("计算完成为%d位数,请选择模式\n",suanwei2(a,b));                                               
put:d=caidan1_3();switch (d)
{
case 1:{int w;putmas1(p,a,b,c);puts("输出成功,请选择相应模式");w=caidan1_1_1();
if(w==1){free(p);goto get;}if(w==2)goto put;if(w==3)goto out;}
case 2:{FILE*fp;
fp=freopen(pw,"a",stdout);if(fp==NULL){fprintf(stderr,"错误,无法重定向为文件,已返回上级");goto put;}
printf("%llu   A(%d,%d)\n",time(NULL),a,b);putmas1(p,a,b,c);fp=freopen("CON","w",stdout);if(fp==NULL){fprintf(stderr,"错误,无法重定向为控制台,已关闭程序");system("pause");exit(EXIT_FAILURE);}
put1:puts("已生成完毕,请选择相应模式");int k=caidan1_1_2();
if(k==1){free(p);goto get;}
if(k==2){int a;a=ShellExecuteA(NULL,"open",pw,NULL,NULL,SW_SHOWNORMAL);if(a>32){puts("已成功打开");goto put1;}else{puts("打开失败,请检查文件夹");goto put1;}}
if(k==3)goto put;
if(k==4)goto out;	
}
case 3:free(p);return 0;
default:out:return 1;
}}
int suanwei2(int a,int b){double c=0.0;
for(b;b>0;a--,b--)c+=log10((double)a);
return (int)c+1;}
void masdashu(int a,int b,int c,unsigned long long*p){const unsigned long long d=10000000000000000LL;unsigned long long w=0ll;
if(a==0||b==0){p[0]=1;}	
else{int i=0,o=0,l=0;p[0]=1;
for(b;b>0;a--,b--){for(i=0;i<=o;i++){p[i]*=a;p[i]+=w;w=0;
if(p[i]>=d){w=p[i]/d;p[i]=p[i]%d;
}}i--;
if(w>0&&(i<(c-1))){p[i+1]=w;o++;}i=0;w=0;
}}}
int getmax5(int a){char c='0';int8_t m[5]={0};int i=0,g=0,o=0;
go:while(c!='\n'){
c=getchar();
if(i==suanwei(a)+1&&c=='\n'){printf("你这还是小于或等于%d的非负数么重来\n",a);i=0;c='0';for(int v=0;v<5;v++)m[v]=0;}
else if(i>suanwei(a)){printf("你这还是小于或等于%d的非负数么重来\n",a);i=0;c='0';for(int v=0;v<5;v++)m[v]=0;while(getchar()!='\n')continue;continue;}
else if(c=='0'&&i==0)continue;
else if(c-'0'>=0&&c-'0'<=9){m[i]=c-'0';i++;}
else if(c=='\n'&&m[0]==0)return 0;
else if(c=='\n')break;
else{printf("你这还是小于或等于%d的非负数么重来\n",a);i=0;for(int v=0;v<5;v++)m[v]=0;while(getchar()!='\n')continue;continue;}}
i--;
for(i;i>=0;i--,o++)g+=(int)m[i]*mi(10,o);
if(g>a){printf("你这还是小于或等于%d的非负数么重来\n",a);i=0;o=0;g=0;c='0';for(int v=0;v<5;v++)m[v]=0;goto go;}
else return g;
}
int mi(int a,int b){int c=1;if(b==0)return 1;else{for(b;b>0;b--)c*=a;return c;}}
int caidan1_3(void){
putfengexian(60);
puts("1 输出在屏幕");
puts("2 输出在txt文件(在程序所在文件夹,且为UTF-8编码文件哦)");
puts("3 返回上级(将清除已算好的数据,无伤大雅只做说明)");
puts("4 关闭程序");
putfengexian(60);
int a;char c;
while(1){
c=getchar();a=c-'0';
if(a>=1&&a<=4&&getchar()=='\n')return a;
else if(c=='\n')puts("别闹了孩子");
else{puts("无法解析你所输入的指示,输入1,2,3,4好么");while (getchar() != '\n') continue;}
}}
void putmas1(unsigned long long*p,int a,int b,int c){int i;putfengexian(suanwei2(a,b)-1);
for (i=c-1;i>=0;i--){if(i==0&&(c-1)==0)printf("%llu\n",p[i]);else if(i==c-1)printf("%llu",p[i]);else if(i==0)printf("%016llu\n",p[i]);else printf("%016llu",p[i]);}putfengexian(suanwei2(a,b)-1);}
int if1_4(void){FILE*fp=fopen(pw,"w");
if(fp==NULL){puts("打开失败,请检查文件夹");return 0;}
else{if(fclose(fp)==0){puts("成功清空");return 0;}else{fprintf(stderr,"错误,无法关闭文件,已关闭程序");system("pause");exit(EXIT_FAILURE);}}}