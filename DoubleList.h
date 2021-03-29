#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED



#endif // DOUBLELIST_H_INCLUDED
typedef int ElemType;
typedef enum Status {
    ERROR,
    SUCCESS,
} Status;

typedef struct DuLNode {    //���Ľṹ��
    ElemType data;
    DuLNode *prior;
    DuLNode *next;
} DuLNode, *DuLinkedList;
typedef struct DuLNode *DuLinkedList;

Status InitList_DuL(DuLinkedList *L);//��ʼ��
Status AddList_DuL(DuLinkedList *L, ElemType e);//���Ԫ��
Status FindNode(DuLinkedList *L, int location, DuLinkedList *p);//Ѱ�ҽ���λ��
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);//��p���ǰ����q���
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);//��p�������q���
void visit(ElemType c);//�����������
Status TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType c));//����������ʾ����
Status DeleteList_DuL(DuLNode *p, ElemType *e);//ɾ��ָ��������һ�����
void DestroyList_DuL(DuLinkedList *L);//���ٸ�˫������
