#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
typedef struct chsystem//chat_system����д
{
	char name[15];//����
	char tel[20];//�ֻ�
	char tecent[15];//qq����
	char email[20];//����
}cs;//ͨѶ¼�ṹ��

typedef struct pcs
{
	cs chat;
	pcs* next;
}*ptcs;//ͨѶ¼�ڵ�
ptcs head=(ptcs)malloc(sizeof(pcs));//�ں�����ֻ�ܽ��б����������ʼ���������ܽ��в���
//����ֻ���ں������ڽ���

int menu_select()//����ѡ���
{
	char c;
	do
	{
		system("cls");
		printf("\n\t\t**********ͨѶ¼����ϵͳ**********\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��        1.�����ϵ��           ��\n");
		printf("\t\t��        2.��ѯ��ϵ��           ��\n");
		printf("\t\t��        3.ɾ����ϵ��           ��\n");
		printf("\t\t��        4.�޸���ϵ����Ϣ       ��\n");
		printf("\t\t��        5.�����ϵ���б�       ��\n");
		printf("\t\t��        6.����                 ��\n");
		printf("\t\t��        7.д���ļ�             ��\n");
		printf("\t\t��        8.��ȡ�ļ�             ��\n");
		printf("\t\t��        9.ͨ����¼             ��\n");
		printf("\t\t��        0.�˳�                 ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t����ѡ��(0-9):");    
		c=getchar(); 
	}while(c<'0'||c>'9');//��������Ƿ���Ϲ淶
	return(c-'0');//������΢���ӻ��ˣ�cֻҪ����Ϊint�ͣ����ֱ�ӷ���c������
}

int cala(char *p)//�����ַ�������
{
	int i,n=0;
	for(i=0;p[i]!='\0';i++)n++;
	return n;
}

int Addpeo()//�����ϵ��
{
	int t,n,a;
	char flag='y';
	ptcs p=head,q;
	while(p->next)p=p->next;
	while(flag!='n'&&flag!='N')
	{
		q=(ptcs)malloc(sizeof(pcs));
		p->next=q;
		p=q;
		q->next=NULL;
		printf("\n\t\t������:\n");
		printf("\t\t����:");//��������
		scanf("\t\t%s",q->chat.name);
		printf("\t\t�ֻ�����:");//�����ֻ���
		scanf("\t\t%s",q->chat.tel);
		do
		{
			n=0;
			if(cala(q->chat.tel)!=11)
			{					
				n=1;
				printf("\t\t��������ֻ������ʽ������,����������:");
				scanf("\t\t%s",q->chat.tel);
			}
			else 
			{
				for(t=0;t<11;t++)
				{
					if(q->chat.tel[t]<'0'||q->chat.tel[t]>'9')
					{
						n=1;
						printf("\t\t��������ֻ������ʽ������,����������:");
						scanf("\t\t%s",q->chat.tel);
						break;
					}
				}
			}
		}while(n);
		printf("\t\tQQ��:");//����QQ��
		scanf("\t\t%s",q->chat.tecent);
		do
		{
			n=0;
			if(cala(q->chat.tecent)>10)
			{					
				n=1;
				printf("\t\t�������QQ�����ʽ������,����������:");
				scanf("\t\t%s",q->chat.tecent);
			}
			else 
			{
				for(t=0;t<10;t++)
				{
					if(q->chat.tecent[t]<'0'||q->chat.tecent[t]>'9')
					{
						n=1;
						printf("\t\t�������QQ�����ʽ������,����������:");
						scanf("\t\t%s",q->chat.tecent);
						break;
					}
				}
			}
		}while(n);
		printf("\t\t��������:");//��������
		scanf("\t\t%s",q->chat.email);
		do
		{
			a=0;
			for(t=0;q->chat.email[t]!='\0';t++)
			{
				if(q->chat.email[t]=='@')
					a++;
			}
			if(a!=1)
			{
				printf("\t\t��������䲻��������������:");
				scanf("\t\t%s",q->chat.email);
			}
		}while(a!=1);
		printf("\n\t\t�Ƿ�������?(Y/N)");      
		scanf("\t\t%c",&flag);  
	}
	return 0;
}

int watch_over()//��ѯ��ϵ��
{
	int m,n;
	char flag='y';
	ptcs p=head->next;
	while(flag!='n'&&flag!='N')
	{
		printf("\n\t\t*************��ѯ��ʽ*************\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��          1.��������           ��\n");
		printf("\t\t��          2.�����ֻ���         ��\n");
		printf("\t\t��          3.����QQ����         ��\n");
		printf("\t\t��          4.����               ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\n\t\t��ѡ���ѯ��ʽ:");
		scanf("\t\t%d",&m);//ѡ���ѯ��ʽ
		do
		{
			n=0;
			if(m!=1&&m!=2&&m!=3&&m!=4)
			{	
				n=1;
				printf("\t\t������Ĳ�ѯ��ʽ������,����������:");
				scanf("\t\t%d",&m);//ѡ���ѯ��ʽ
			}
		}while(n);
		if(!p)
		{
			printf("\t\t��ͨѶ¼Ϊ��!\n");
			return 0;
		}
		if(1==m)
		{
			char nm[15];
			p=head->next;
			printf("\t\t��������Ҫ��ѯ����ϵ��:");
			scanf("\t\t%s",nm);
			while(p!=NULL&&strcmp(p->chat.name,nm)!=0)p=p->next;
			if(!p)
			{
				printf("\t\t��Ҫ��ѯ����ϵ�˲�����!\n");
				printf("\t\t�Ƿ������ѯ?(Y/N)");
				scanf("\t\t%c",&flag);
				return 0;
			}
			printf("\t\t�ֻ�����:%s\n",p->chat.tel);
			printf("\t\tqq��:%s\n",p->chat.tecent);
			printf("\t\t��������:%s\n",p->chat.email);
		}
		if(2==m)
		{
			char te[20];
			p=head->next;
			printf("\t\t��������Ҫ��ѯ���ֻ�����:");
			scanf("\t\t%s",te);
			while(p!=NULL&&strcmp(p->chat.tel,te)!=0)p=p->next;
			if(!p)
			{
				printf("\t\t��Ҫ��ѯ����ϵ�˲�����!\n");
				printf("\t\t�Ƿ������ѯ?(Y/N)");
				scanf("\t\t%c",&flag);
				return 0;
			}
			printf("\t\t����:%s\n",p->chat.name);
			printf("\t\tqq��:%s\n",p->chat.tecent);
			printf("\t\t��������:%s\n",p->chat.email);
		}
		if(3==m)
		{
			char qq[15];
			p=head->next;
			printf("\t\t��������Ҫ��ѯ��qq��:");
			scanf("\t\t%s",qq);
			while(p!=NULL&&strcmp(p->chat.tecent,qq)!=0)p=p->next;
			if(!p)
			{
				printf("\t\t��Ҫ��ѯ����ϵ�˲�����!\n");
				printf("\t\t�Ƿ������ѯ?(Y/N)");
				scanf("\t\t%c",&flag);
				return 0;
			}
			printf("\t\t����:%s\n",p->chat.name);
			printf("\t\t�ֻ���:%s\n",p->chat.tecent);
			printf("\t\t��������:%s\n",p->chat.email);
		}
		if(4==m)return 0;
		printf("\t\t�Ƿ������ѯ?(Y/N)");
		scanf("\t\t%c",&flag);
	}
	return 0;
}

int Delete()//ɾ��������Ϣ
{
	char nm[20];
	char flag='y';
	ptcs p=head->next,bh,pre;
	if(!p)
	{
		printf("\t\t��ͨѶ¼Ϊ��!\n");
		return 0;
	}
	while(flag!='n'&&flag!='N')
	{
		p=head->next;
		printf("\t\t��������Ҫɾ������ϵ������:");
		scanf("\t\t%s",nm);
		while(p!=NULL&&strcmp(p->chat.name,nm)!=0)
		{
			pre=p;
			p=p->next;
		}
		if(!p)
		{
			printf("\t\t����ϵ�˲�����!\n");
			printf("\t\t�Ƿ����ɾ��?(Y/N)");
			scanf("\t\t%c",&flag);
			return 0;
		}
		bh=p->next;
		if(p==head->next)head->next=bh;
		else pre->next=bh;
		printf("\t\t����ϵ����ɾ��!\n");
		printf("\t\t�Ƿ����ɾ��?(Y/N)");
		scanf("\t\t%c",&flag);
	}
	return 0;
}

int changeall(ptcs p)//�޸�ĳһ��ϵ�˵�������Ϣ
{
	int a,n,t;
	printf("\t\t����:");//��������
	scanf("\t\t%s",p->chat.name);
	printf("\t\t�ֻ�����:");//�����ֻ���
	scanf("\t\t%s",p->chat.tel);
	do
	{
		n=0;
		if(cala(p->chat.tel)!=11)
		{					
			n=1;
			printf("\t\t��������ֻ������ʽ������,����������:");
			scanf("\t\t%s",p->chat.tel);
		}
		else 
		{
			for(t=0;t<11;t++)
			{
				if(p->chat.tel[t]<'0'||p->chat.tel[t]>'9')
				{
					n=1;
					printf("\t\t��������ֻ������ʽ������,����������:");
					scanf("\t\t%s",p->chat.tel);
					break;
				}
			}
		}
	}while(n);
	printf("\t\tQQ��:");//����QQ��
	scanf("\t\t%s",p->chat.tecent);
	do
	{
		n=0;
		if(cala(p->chat.tecent)!=10)
		{					
			n=1;
			printf("\t\t�������QQ�����ʽ������,����������:");
			scanf("\t\t%s",p->chat.tecent);
		}
		else 
		{
			for(t=0;t<10;t++)
			{
				if(p->chat.tecent[t]<'0'||p->chat.tecent[t]>'9')
				{
					n=1;
					printf("\t\t�������QQ�����ʽ������,����������:");
					scanf("\t\t%s",p->chat.tecent);
					break;
				}
			}
		}
	}while(n);
	printf("\t\t��������:");//��������
	scanf("\t\t%s",p->chat.email);
	do
	{
		a=0;
		for(t=0;p->chat.email[t]!='\0';t++)
		{
			if(p->chat.email[t]=='@')
				a++;
		}
		if(a!=1)
		{
			printf("\t\t��������䲻��������������:");
			scanf("\t\t%s",p->chat.email);
		}
	}while(a!=1);
	return 0;
}

int changetel(ptcs p)//�޸��ֻ�������
{
	int n,t;
	scanf("\t\t%s",p->chat.tel);
	do
	{
		n=0;
		if(cala(p->chat.tel)!=11)
		{					
			n=1;
			printf("\t\t��������ֻ������ʽ������,����������:");
			scanf("\t\t%s",p->chat.tel);
		}
		else 
		{
			for(t=0;t<11;t++)
			{
				if(p->chat.tel[t]<'0'||p->chat.tel[t]>'9')
				{
					n=1;
					printf("\t\t��������ֻ������ʽ������,����������:");
					scanf("\t\t%s",p->chat.tel);
					break;
				}
			}
		}
	}while(n);
	return 0;
}

int changeQQ(ptcs p)//�޸�QQ����
{
	int n,t;
	scanf("%s",p->chat.tecent);
	do
	{
		n=0;
		if(cala(p->chat.tecent)!=10)
		{					
			n=1;
			printf("\t\t�������QQ�����ʽ������,����������:");
			scanf("\t\t%s",p->chat.tecent);
		}
		else 
		{
			for(t=0;t<10;t++)
			{
				if(p->chat.tecent[t]<'0'||p->chat.tecent[t]>'9')
				{
					n=1;
					printf("\t\t�������QQ�����ʽ������,����������:");
					scanf("\t\t%s",p->chat.tecent);
					break;
				}
			}
		}
	}while(n);
	return 0;
}

int changeEmail(ptcs p)//�޸ĵ�������
{
	int t,a;
	scanf("\t\t%s",p->chat.email);
	do
	{
		a=0;
		for(t=0;p->chat.email[t]!='\0';t++)
		{
			if(p->chat.email[t]=='@')
				a++;
		}
		if(a!=1)
		{
			printf("\t\t��������䲻��������������:");
			scanf("\t\t%s",p->chat.email);
		}
	}while(a==1);
	return 0;
}

int change()//�޸���ϵ����Ϣ
{
	char nm[20],flag='y';
	int m,n;
	ptcs p=head->next;
	if(!p)
	{
		printf("\t\t��ͨѶ¼Ϊ��!\n");
		return 0;
	}
	while(flag!='n'&&flag!='N')
	{
		p=head->next;
		printf("\n\t\t*******��������Ҫ�޸ĵ�����*******\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��       1.��ϵ��                ��\n");
		printf("\t\t��       2.�ֻ�����              ��\n");
		printf("\t\t��       3.QQ��                  ��\n");
		printf("\t\t��       4.��������              ��\n");
		printf("\t\t��       5.����                  ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\n\t\t��������Ҫ�޸ĵ�����:");
		scanf("\t\t%d",&m);
		do
		{
			n=0;
			if(m!=1&&m!=2&&m!=3&&m!=4&&m!=5)
			{	
				n=1;
				printf("\t\t��������޸����ݲ�����,����������:");
				scanf("\t\t%d",&m);//ѡ���޸�����
			}
		}while(n);
		if(5==m)return 0;
		printf("\t\t�����������޸���Ϣ����ϵ�˵�����:");
		scanf("\t\t%s",nm);
		while(p!=NULL&&strcmp(p->chat.name,nm)!=0)p=p->next;
		if(!p)
		{
			printf("\t\t����ϵ�˲�����!\n");
			return 0;
		}
		if(1==m)
		{
			printf("\t\t�����������޸�:\n");
			changeall(p);
		}
		if(2==m)
		{
			printf("\t\t������%s���ֻ�����:",p->chat.name);
			changetel(p);
		}
		if(3==m)
		{
			printf("\t\t������%s��QQ��:",p->chat.name);
			changeQQ(p);
		}
		if(4==m)
		{
			printf("\t\t������%s�ĵ�������:",p->chat.name);
			changeEmail(p);
		}
		printf("\t\t�Ƿ�����޸�?(Y/N)");
		scanf("\t\t%c",&flag);
	}
	return 0;
}

int display()//���ͨѶ¼�б�
{
	ptcs p=head->next;
	if(!p)
	{
		printf("\t\t��ͨѶ¼Ϊ��!\n");
		return 0;
	}
	printf("\n\t\t******************************ͨѶ¼�б�******************************\n");
	printf("\t\t����\t\t�ֻ�����\tQQ����\t\t��������\n");
	printf("\t\t----------------------------------------------------------------------\n");
	while(p)
	{
		printf("\t\t%-16s%-16s%-16s%-20s\n",p->chat.name,p->chat.tel,p->chat.tecent,p->chat.email);
		p=p->next;
		printf("\t\t----------------------------------------------------------------------\n");
	}
	return 0;
}

int cacu(ptcs p)//��������ĳ���
{
	int n=0;
	while(p)
	{
		p=p->next;
		n++;
	}
	return n;
}

int arrange()//��ͨѶ¼��������,���ﱾ����ð�ݷ�����,��΢��Щ����
{
	int i,n;
	ptcs pre=head,p=head->next,k,q;
	if(!p)
	{
		printf("\t\t��ͨѶ¼Ϊ��!\n");
		return 0;
	}
	n=cacu(p);
	for(i=0;i<n-1;i++)
	{
		for(p=head->next,pre=head;p->next->next!=NULL;pre=p,p=p->next);
		{
			k=p->next;
			q=k->next;
			if(strcmp(p->chat.name,k->chat.name)>0)
			{
				pre->next=k;
				k->next=p;
				p->next=q;
				p=k;
			}
		}
	}
	display();
	return 0;
}

int write()//������д���ļ�
{
	ptcs p=head->next;
	FILE* fp;
	char filename[30];
	if(!p)
	{
		printf("\t\t��ͨѶ¼Ϊ��!");
		return 0;
	}
	printf("\t\tд�뵽�ļ�!\n");
	printf("\t\t��������д����ļ���:");
	scanf("\t\t%s",filename);
	if((fp=fopen(filename,"a+"))==NULL)
	{
		printf("\t\t�޷����ļ�!\n");
		system("pause");
		return 0;
	}
	fprintf(fp,"******************************ͨѶ¼�б�******************************\n");
	fprintf(fp,"����\t\t�ֻ�����\tQQ����\t\t��������\n");
	fprintf(fp,"----------------------------------------------------------------------\n");
	while(p)
	{
		fprintf(fp,"%-16s%-16s%-16s%-20s\n",p->chat.name,p->chat.tel,p->chat.tecent,p->chat.email);
		p=p->next;
		fprintf(fp,"----------------------------------------------------------------------\n");
	}
	fprintf(fp,"\n******************************��%d����ϵ��******************************\n",cacu(head->next));
	fclose(fp);                                         //�ر��ļ�   
	printf("\t\tд��ɹ�!\n"); 
	return 0;
}

int read()//��ȡ�ļ�
{
	char str[100],char filename[30];
	FILE* fp;
	printf("\t\t��ȡ�ļ�!\n");
	printf("\t\t��������д����ļ���:");
	scanf("\t\t%s",filename);
	if((fp=fopen(filename,"a+"))==NULL)
	{
		printf("\t\t�޷����ļ�!\n");
		system("pause");
		return 0;
	}
	while((fgets(str,100,fp))!=NULL)  
    {  
		printf("\t\t%s",str);  
    }
	return 0;
}

int call()//���л򱻺���
{
	int n;
	ptcs p=head->next;
	srand((unsigned) time(NULL)); //��ʱ�����֣�ÿ�β����������һ��
	n=rand()%(cacu(p)+5)+1;
	return n;
}

int save(int n,char *filename)//����ͨ����
{
	FILE* fp;
	ptcs p=head->next;
	int i=1;
	if((fp=fopen(filename,"a+"))==NULL)
	{
		printf("\t\tͨ����¼��ʧȥ!\n");
		system("pause");
		return 0;
	}
	if(n<=cacu(p))
	{
		while(i<n)
		{
			p=p->next;
			i++;
		}
		fprintf(fp,"%-16s%-16s%-16s%-20s\n",p->chat.name,p->chat.tel,p->chat.tecent,p->chat.email);
		fprintf(fp,"----------------------------------------------------------------------\n");
	}
	else fprintf(fp,"δ֪����\n");
	fclose(fp); //�ر��ļ�   
	return 0;
}

int chat_record()//ͨ����¼
{
	int m,n,i;
	char flag='y';
	char cal[30]="call.txt",caled[30]="called.txt";
	while(flag!='n'&&flag!='N')
	{
	printf("\t\tģ��ͨ����ʼ!\n");
	printf("\t\t��ѡ��ͨ������(1.����(call) OR 2.������(called)):");
	scanf("\t\t%d",&m);
	do
	{
		i=0;
		if(m!=1&&m!=2)
		{	
			i=1;
			printf("\t\t��������Ų��ڱ�׼��,����������:");
			scanf("\t\t%d",&m);//ѡ���޸�����
		}
	}while(i);
	n=call();
	if(1==m)
		save(n,cal);
	else if(2==m)
		save(n,caled);
	printf("\t\t�Ƿ����ģ��?(Y/N)");
	scanf("\t\t%c",&flag);
	}
	return 0; 
}

int main()
{
	/*head->next=NULL;
	system("cls");
	printf("\n\t\t**********ͨѶ¼����ϵͳ**********\n");
	printf("\t\t��-------------------------------��\n");
	printf("\t\t��        1.�����ϵ��           ��\n");
	printf("\t\t��        2.��ѯ��ϵ��           ��\n");
	printf("\t\t��        3.ɾ����ϵ��           ��\n");
	printf("\t\t��        4.�޸���ϵ����Ϣ       ��\n");
	printf("\t\t��        5.�����ϵ���б�       ��\n");
	printf("\t\t��        6.����                 ��\n");
	printf("\t\t��        7.д���ļ�             ��\n");
	printf("\t\t��        8.��ȡ�ļ�             ��\n");
	printf("\t\t��        9.ͨ����¼             ��\n");
	printf("\t\t��        0.�˳�                 ��\n");
	printf("\t\t��-------------------------------��\n");
	printf("\t\t����ѡ��(0-9):"); 
	printf("\n\t\t******************************ͨѶ¼�б�******************************\n");
	printf("\t\t����\t\t�ֻ�����\tQQ����\t\t��������\n");*/
	head->next=NULL;
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			printf("\n\t\t��Ӽ�¼��ͨѶ¼\n"); //��Ӽ� ¼
			Addpeo();
			system("pause");
			break;
		case 2:
			printf("\n\t\t��ͨѶ¼�в�����ϵ��\n"); 
			watch_over();
			system("pause");
			break;
		case 3:
			printf("\n\t\t��ͨѶ¼��ɾ����ϵ��\n");
			Delete();
			system("pause");
			break;
		case 4:
			printf("\n\t\t�޸�ͨѶ¼�е���Ϣ\n");
			change();
			system("pause");
			break;
		case 5:
			printf("\n\t\t���ͨѶ¼�б�\n");
			display();
			system("pause");
			break;
		case 6:
			printf("\n\t\t����\n");
			arrange();
			system("pause");
			break;
		case 7:
			printf("\n\t\tд���ļ�\n");
			write();
			system("pause");
			break;
		case 8:
			printf("\n\t\t��ȡ�ļ�\n");
			read();
			system("pause");
			break;
		case 9:
			printf("\n\t\tģ��ͨ��\n");
			chat_record();
			system("pause");
			break;
		case 0:    
			printf("\n\t\tллʹ�ã��ټ�!\n");  //��������    
			printf("\n\t\t");    
			system("pause");    
			exit(0);    
		}
	}
	return 0;
}