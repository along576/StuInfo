/*
	���ߣ�������
	ʱ�䣺2020.06.22
	��Ŀ���ƣ�ѧ����Ϣ����ͽ�ѧ������ϵͳ 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 30
//ѧ���ɼ�
typedef struct
{
    int sid = 0;
    char name[20];
    char _class[20];
    int proramming, weChat, SoftWare;
    int grade_sum;
    float avg;
} stu_Datas;
stu_Datas stu[MAXSIZE];

//�ļ�����
int count_num();
//¼��ѧ����Ϣ����
void input_stu_data(stu_Datas[]);
// ���ѧ����Ϣ
void insert_stu_data(stu_Datas[]);
void change_stu_data(stu_Datas[]);
//����������ѧ����Ϣ
void select_stu_data(stu_Datas[]);
//��ѧ��ɾ��ѧ����Ϣ
void delete_stu_data(stu_Datas[]);

//ƽ�����ܳɼ�
void stu_all(stu_Datas[]);
//output�������
void output_stu_data(stu_Datas[]);
//�ɼ���һ
int max_grade_sum(stu_Datas[]);
//ѧϰ���
void study_mode(stu_Datas[]);
//����ѧ��
void merit_stu(stu_Datas[]);
void menu();
void menu1();
void menu1()
{
    while (1)
    {
        printf("**********************ѧ����Ϣ����***************\n");
        printf("*\t\t\t*�˵�*\t\t\t*\n");
        printf("*\t\t��1��¼��ѧ����Ϣ \t\t*\n");
        printf("*\t\t��2�����ѧ����Ϣ \t\t*\n");
        printf("*\t\t��3��ɾ��ѧ����Ϣ \t\t*\n");
        printf("*\t\t��4���޸�ѧ����Ϣ \t\t*\n");
        printf("*\t\t��5������ѧ����Ϣ \t\t*\n");
        printf("*\t\t��6������ѧ����Ϣ \t\t*\n");
        printf("*\t\t��7���ܳɼ���ƽ����\t\t*\n");
        printf("*\t\t��0�� ������һ��   \t\t*\n");
        printf("*************************************************\n");
        int sNo;
        printf("������ѡ���:");
        scanf("%d", &sNo);
        switch (sNo)
        {
        case 1:
            input_stu_data(stu); //¼��ѧ����Ϣ
            break;
        case 2:
            insert_stu_data(stu); //���ѧ����Ϣ
            break;
        case 3:
            delete_stu_data(stu);
            break;
        case 4:
            change_stu_data(stu);
            break;
        case 5:
            select_stu_data(stu);
            break;
        case 6:
            output_stu_data(stu);
            break;
        case 7:
            stu_all(stu);
            break;
        case 0:
            menu();
            break;
        default:
            printf("�������,���������룡");
        }
    }
}
void menu2()
{

    while (1)
    {
        printf("************ѧ���ɼ��뽱ѧ������ϵͳ*************\n");
        printf("*\t\t      *�˵�*    \t\t*\n");
        printf("*\t\t��1��  ѧϰ��� \t\t*\n");
        printf("*\t\t��2��  ����ѧ�� \t\t*\n");
        printf("*\t\t��0��  ������һ��  \t\t*\n");
        printf("*************************************************\n");

        int Num;
        printf("������������:");
        scanf("%d", &Num);
        switch (Num)
        {
        case 0:
            menu();
            break;
        case 1:
            study_mode(stu);
            break;
        case 2:
            merit_stu(stu);
            break;
        default:
            printf("�������,����������\n");
            break;
        }
    }
}
void menu()
{
    while (1)
    {
        printf("************ѧ���ɼ��뽱ѧ������ϵͳ*************\n");
        printf("*\t\t      *�˵�*    \t\t*\n");
        printf("*\t\t��1��ѧ����Ϣ����\t\t*\n");
        printf("*\t\t��2�� ��ѧ������ \t\t*\n");
        printf("*\t\t��0��  �˳�ϵͳ  \t\t*\n");
        printf("*************************************************\n");
        int no;
        printf("�����������ţ�");
        scanf("%d", &no);
        switch (no)
        {
        case 0:
            printf("0  �˳�ϵͳ\n");
            exit(1);
            break;
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            printf("2��ѧ������\n");
            break;
        default:
            printf("�������,���������룡\n");
        }
    }
}
int main()
{
    menu(); //���ò˵��ļ�
    return 0;
}

int count_num()
{
    int flag = 0, count = 0;
    FILE *fp;
    if ((fp = fopen("stu.txt", "r")) == NULL)
    {
        printf("����\n");
    }
    while (!feof(fp))
    {
        flag = fgetc(fp);
        if (flag == '\n')
            count++;
    }
    return count;
    fclose(fp);
}
//¼��ѧ����Ϣ
void input_stu_data(stu_Datas stu[])
{
    int count = count_num();
    if (count < MAXSIZE) //����ļ������ﵽMAXSIZE��ֵ���������ѧ����Ϣ
    {
        FILE *fp;
        int res = MAXSIZE - count;
        int i;
        printf("����������Ҫ¼���ѧ������(����%d��,���%d��):", count, MAXSIZE);
        int n;
        scanf("%d", &n);
        if (n > res)
        {
            printf("�����������%d����\n", res);
        }
        else
        {
            printf("�������ʽ��ѧ�� ���� �༶ �������˼���뷽�� ΢��С���� �������\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &stu[i].sid);
                scanf("%s", &stu[i].name);
                scanf("%s", &stu[i]._class);
                scanf("%d%d%d", &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);
            }

            if ((fp = fopen("stu.txt", "a+")) == NULL)
            {
                printf("����\n");
                return;
            }
            for (i = 0; i < n; i++)
            {
                fprintf(fp, "%d %s %s %d %d %d\n", stu[i].sid, stu[i].name, stu[i]._class, stu[i].proramming, stu[i].weChat, stu[i].SoftWare);
            }
            fclose(fp);
        }
    }
    else
    {
        printf("ѧ�������Ѵﵽ%d��,���������!", MAXSIZE);
    }
}
//���ѧ����Ϣ
void insert_stu_data(stu_Datas stu[])
{
    int count = count_num();
    if (count < MAXSIZE) //����ļ������ﵽMAXSIZE��ֵ���������ѧ����Ϣ
    {
        printf("�����ʽ:��ѧ�� ���� �༶ �������˼���뷽�� ΢��С���� ������̡�\n");
        scanf("%d", &stu[1].sid);
        scanf("%s", &stu[1].name);
        scanf("%s", &stu[1]._class);
        scanf("%d%d%d", &stu[1].proramming, &stu[1].weChat, &stu[1].SoftWare);
        FILE *fp;
        if ((fp = fopen("stu.txt", "a+")) == NULL)
        {
            printf("����\n");
            return;
        }
        fprintf(fp, "%d %s %s %d %d %d\n", stu[1].sid, stu[1].name, stu[1]._class, stu[1].proramming, stu[1].weChat, stu[1].SoftWare);
        fclose(fp);
    }
    else
    {
        printf("ѧ�������Ѵﵽ%d��,���������!", MAXSIZE);
    }
}
//��ѧ��ɾ��ѧ����Ϣ
void delete_stu_data(stu_Datas stu[])
{
    int count = count_num();
    FILE *fw = fopen("stu.txt", "r");
    int i, j, k, res;
    int num;
    printf("��������Ҫɾ����Ϣ��ѧ��ѧ��:");
    scanf("%d", &num);
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);
    }
    for (j = 0; j < count; j++)
    {
        if (num == stu[j].sid)
        {
            res = j;
        }
    }
    fclose(fw);
    FILE *fp;
    if ((fp = fopen("stu.txt", "w")) == NULL)
    {
        printf("д���ļ�����\n");
        return;
    }
    for (k = 0; k < count; k++)
    {
        if (k == res)
        {
            printf("ɾ���ɹ�!\n");
            continue;
        }
        fprintf(fp, "%d %s %s %d %d %d\n", stu[k].sid, stu[k].name, stu[k]._class, stu[k].proramming, stu[k].weChat, stu[k].SoftWare);
    }
    fclose(fp);
}
//�޸�����Ϊ
void change_stu_data(stu_Datas stu[])
{
    int count = count_num();
    FILE *fw = fopen("stu.txt", "r");
    int i, j, k;
    int num;
    printf("��������Ҫ�޸�ѧ����Ϣ��ѧ��ѧ��:");
    scanf("%d", &num);
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);
    }
    for (j = 0; j < count; j++)
    {
        if (num == stu[j].sid)
        {
            printf("�޸�ǰ,ѧ��Ϊ%dѧ����ϢΪ:\n", stu[j].sid);
            printf("****************************************************************************************************\n");
            printf("ѧ��      ����      �༶      �������˼���뷽��      ΢��С����      �������\n");
            printf("%-10d%-10s%-15s%-22d%-17d%-11d\n", stu[j].sid, stu[j].name, &stu[j]._class, stu[j].proramming, stu[j].weChat, stu[j].SoftWare);
            printf("�����ʽΪ:������ �༶ �������˼���뷽�� ΢��С���� ������̡�\n");
            printf("������ѧ��Ϊ%dͬѧ����Ϣ:", stu[j].sid);
            scanf("%s %s %d %d %d", &stu[j].name, &stu[j]._class, &stu[j].proramming, &stu[j].weChat, &stu[j].SoftWare);
            printf("�޸ĺ�ѧ��Ϊ%dѧ����ϢΪ:\n", stu[j].sid);
            printf("****************************************************************************************************\n");
            printf("ѧ��      ����      �༶      �������˼���뷽��      ΢��С����      �������\n");
            printf("%-10d%-10s%-15s%-22d%-17d%-11d\n", stu[j].sid, stu[j].name, &stu[j]._class, stu[j].proramming, stu[j].weChat, stu[j].SoftWare);
            break;
        }
    }
    fclose(fw);
    FILE *fp;
    if ((fp = fopen("stu.txt", "w")) == NULL)
    {
        printf("����\n");
        return;
    }
    for (k = 0; k < count; k++)
    {
        fprintf(fp, "%d %s %s %d %d %d\n", stu[k].sid, stu[k].name, stu[k]._class, stu[k].proramming, stu[k].weChat, stu[k].SoftWare);
    }
    fclose(fp);
}
//��ѧ�Ų�ѯ�����ɼ�
void select_stu_data(stu_Datas stu[])
{
    int count = count_num();
    FILE *fw = fopen("stu.txt", "r");
    int i, j, k;
    int num;
    printf("��������Ҫ�޸�ѧ����Ϣ��ѧ��ѧ��:");
    scanf("%d", &num);
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);
    }
    for (j = 0; j < count; j++)
    {
        if (num == stu[j].sid)
        {
            printf("****************************************************************************************************\n");
            printf("ѧ��      ����      �༶      �������˼���뷽��      ΢��С����      �������\n");
            printf("%-10d%-10s%-15s%-22d%-17d%-11d\n", stu[j].sid, stu[j].name, &stu[j]._class, stu[j].proramming, stu[j].weChat, stu[j].SoftWare);
            break;
        }
    }
    fclose(fw);
}

//�鿴����ѧ����Ϣ
void output_stu_data(stu_Datas stu[])
{
    int count = count_num();
    printf("**********ȫ��ѧ���ɼ�***********\n");
    printf("ѧ��      ����      �༶      �������˼���뷽��      ΢��С����      �������\n");
    FILE *fw = fopen("stu.txt", "r");
    int i;
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);       //��ȡ�ļ��е����ݣ���ŵ��ṹ��
        printf("%-10d%-10s%-15s%-23d%-15d%-10d\n", stu[i].sid, stu[i].name, &stu[i]._class, stu[i].proramming, stu[i].weChat, stu[i].SoftWare); //���ļ���ӡ������
    }
    printf("\n");
    fclose(fw);
}
//ƽ���ֳɼ�
void stu_all(stu_Datas stu[])
{
    int count = count_num();
    printf("**********ȫ��ѧ���ɼ�***********\n");
    printf("ѧ��      ����      �༶      �������˼���뷽��      ΢��С����      �������       �ܷ�        ƽ����\n");
    FILE *fw = fopen("stu.txt", "r");
    int i;
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare);                                                //��ȡ�ļ��е����ݣ���ŵ��ṹ�塣
        stu[i].grade_sum = stu[i].proramming + stu[i].weChat + stu[i].SoftWare;                                                                                                          //�����ܷ�
        stu[i].avg = stu[i].grade_sum / 3.0;                                                                                                                                             //����ƽ����
        printf("%-10d%-10s%-15s%-22d%-17d%-11d%-12d%-9.2f\n", stu[i].sid, stu[i].name, &stu[i]._class, stu[i].proramming, stu[i].weChat, stu[i].SoftWare, stu[i].grade_sum, stu[i].avg); //���ļ���ӡ������
    }
    printf("\n");
    fclose(fw);
}
//ѧϰ���
void study_mode(stu_Datas stu[])
{
    int count = count_num();
    FILE *fw = fopen("stu.txt", "r");
    int i, j, k;
    int sum = 0;
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare); //��ȡ�ļ��е����ݣ���ŵ��ṹ�塣
        stu[i].grade_sum = stu[i].proramming + stu[i].weChat + stu[i].SoftWare;
    }
    for (j = 0; j < count; j++)
    {
        if ((stu[j].proramming >= 80) && (stu[j].weChat >= 80) && (stu[j].SoftWare >= 80))
        {
            if (stu[j].grade_sum > sum)
            {
                sum = stu[j].grade_sum;
                k = j;
            }
        }
    }
    printf("************************************\n");
    printf("*                                  *\n");
    printf("*        ѧϰ����ǡ�%s��        *\n", stu[k].name);
    printf("*                                  *\n");
    printf("************************************\n");
    fclose(fw);
}
void merit_stu(stu_Datas stu[])
{
    int count = count_num();
    FILE *fw = fopen("stu.txt", "r");
    int i, j, k;
    int sum = 0;
    for (i = 0; i < count; i++)
    {
        fscanf(fw, "%d %s %s %d %d %d", &stu[i].sid, &stu[i].name, &stu[i]._class, &stu[i].proramming, &stu[i].weChat, &stu[i].SoftWare); //��ȡ�ļ��е����ݣ���ŵ��ṹ�塣
        stu[i].grade_sum = stu[i].proramming + stu[i].weChat + stu[i].SoftWare;
    }
    int person = MAXSIZE * 0.1;
    for (j = 0; j < count; j++)
    {
        if ((stu[j].proramming >= 80) && (stu[j].weChat >= 80) && (stu[j].SoftWare >= 80))
        {
            if (stu[j].grade_sum > sum)
            {
                sum = stu[j].grade_sum;
                k = j;
            }
        }
    }
    int max[30] = {0};
    int l = 0;
    for (int x = 0; x < count; x++)
    {
        if ((stu[x].proramming >= 75) && (stu[x].weChat >= 75) && (stu[x].SoftWare >= 75))
        {
            if (sum == stu[x].grade_sum)
            {
                continue;
            }
            max[x] = stu[x].grade_sum;
        }
    }
    int t = 0;
    int aa, bb, cc = 0;
    for (aa = 0; aa < 29; aa++)
    {
        for (bb = aa + 1; bb < 30; bb++)
        {
            if (max[aa] < max[bb])
            {
                cc = max[aa];
                max[aa] = max[bb];
                max[bb] = cc;
            }
        }
    }
    printf("************************************\n");
    printf("*                                  *\n");
    for (int v = 0; v < count; v++)
    {
        for (int b = 0; b < person; b++)
        {
            if (max[b] == stu[v].grade_sum)
            {
                l++;
                printf("     ��%dλ����ѧ���ǡ�%3s��     \n", l, stu[v].name);
            }
        }
    }
    printf("*                                  *\n");
    printf("************************************\n");
    fclose(fw);
}

