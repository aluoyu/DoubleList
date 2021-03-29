#include <iostream>
#include "DoubleList.h"
using namespace std;

//��ʼ��
Status InitList_DuL(DuLinkedList *L) {
    *L = new DuLNode;
    (*L)->next = NULL;    //��ʼ��ָ����
    (*L)->prior = NULL;
    cout << "��ʼ���ɹ�" << endl;
    return SUCCESS;
}

//���Ԫ��
Status AddList_DuL(DuLinkedList *L, ElemType e) {
    DuLinkedList point;
    point = new DuLNode;   //�����½��
    point->data = e;    //���½�㸳ֵ
    point->next = (*L)->next;
    if ((*L)->next != NULL) {    //(*L)->next��ָ����Ϊ��
        (*L)->next->prior = point;    //�ı���ָ���ָ���򣬶�(*L)->next��ָ����Ϊ��ʱ������ı�
    }
    (*L)->next = point;
    point->prior = (*L);
    return SUCCESS;
}

//Ѱ�ҽ���λ��
Status FindNode(DuLinkedList *L, int location, DuLinkedList *p) {
    int count_num;
    DuLinkedList temp_point = *L;
    for (count_num = 1; count_num < location && temp_point; count_num++)    //����Ѱ��
        temp_point = temp_point->next;
    if (!temp_point || count_num > location) {   //�ý�㲻����
        return ERROR;
    } else
        *p = temp_point->next;    //temp_point��ָ������ǰһ������ָ���Ľ��Ϊ��nextָ��ָ�������
    return SUCCESS;
}

//��p���ǰ����q���
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    q->prior = p->prior;
    q->next = p;
    p->prior->next = q;
    p->prior = q;
    cout << "����ɹ�" << endl;
    return SUCCESS;
}

//��p�������q���
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    q->next = p->next;
    if (p->next != NULL) {    //p->next��ָ����Ϊ�գ�Ҫ������̽���priorָ����
        p->next->prior = q;
    }
    p->next = q;    //p->next��ָ����Ϊ��
    q->prior = p;
    cout << "����ɹ�" << endl;
    return SUCCESS;
}

//�����������
void visit(ElemType c) {
    cout << c << '\t';
}

//����������ʾ����
Status TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType c)) {     //����ָ����Ϊ�β�
    DuLinkedList point;
    point = L->next;
    while (point) {
        visit(point->data);    //����������visit����
        point = point->next;
    }
    cout << endl;
    return SUCCESS;
}

//ɾ��ָ��������һ�����
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if (p->next == NULL) {  //�ж�ָ���Ľ���Ƿ�Ϊβ��㣬β����޺��
        e = NULL;
        return ERROR;
    }
    else {
        DuLinkedList point;
        point = p->next;
        p->next = point->next;
        *e = point->data;
        if (p->next != NULL)   //�ж�Ҫɾ���Ľ���Ƿ�Ϊβ���
            p->next->prior = p;    //���ǣ���Ҫ�������̽���priorָ����
        delete point;
        return SUCCESS;
    }
}

//���ٸ�˫������
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList point;
    while (*L) {    //��ͷ��㿪ʼ��һ�ͷ��ڴ�
        point = *L;
        *L = (*L)->next;
        delete point;
    }
    cout << "������";
}
