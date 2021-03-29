#include <iostream>
#include "DoubleList.h"
using namespace std;

//������
int main() {
    DuLinkedList head;
    InitList_DuL(&head);
    while (true) {
        cout << "--1.��� 2.���� 3.��� 4.ɾ�� 5.���� 6.�˳� --" << endl;
        int choice;
        cout << "������ѡ��" << endl;
        cin >> choice;
        ElemType element;
        switch (choice) {
            case (1):
                cout << "������Ҫ��ӵ�Ԫ��" << endl;
                cin >> element;
                AddList_DuL(&head, element);
                break;
            case (2):
                cout << "������ķ�����1-��ָ�����ǰ���� 2-��ָ���������" << endl;
                int method, address;
                cout << "�����������ķ���-" << endl;
                cin >> method;
                switch (method) {   //ѡ�����ķ���
                    case (1):
                        cout << "���������λ�ã�"<<endl;
                        cin >> address;
                        DuLNode *point;
                        Status situation;
                        situation=FindNode(&head, address, &point);
                        if (situation == ERROR || point == NULL) {    //���ú������ж�ָ������Ƿ����
                            cout << "�ý�㲻����" << endl;
                            break;
                        } else {
                            DuLNode *q;
                            q = new DuLNode;
                            cout << "�������½���ŵ�����-" << endl;
                            int num;
                            cin >> num;
                            q->data = num;
                            InsertBeforeList_DuL(point, q);     //��point���ǰ����q���
                            break;
                        }
                    case (2):
                        cout << "���������λ�ã�"<<endl;
                        cin >> address;
                        DuLNode *point_;
                        FindNode(&head, address, &point_);
                        if (FindNode(&head, address, &point_) == ERROR || point_ == NULL) {     //�жϽ���Ƿ����
                            cout << "�ý�㲻����" << endl;
                            break;
                        }
                        else {
                            DuLNode *q_;
                            q_ = new DuLNode;    //�����½��
                            cout << "�������½���ŵ�����-" << endl;
                            int num;
                            cin >> num;
                            q_->data = num;
                            cout << "�����Ѵ���½��" << endl;
                            InsertAfterList_DuL(point_, q_);     //��point�������q���
                            break;
                        }
                    default:
                        cout << "��������������" << endl;
                        break;
                }
                break;
            case (3):
            	cout<<endl;
                void (*point)(ElemType c);
                point = visit;
                TraverseList_DuL(head, point);
                break;
            case (4):
                cout << "ע�⣺ɾ���Ľ��Ϊָ��������һ�����" << endl;
                cout << "������ָ������λ��" << endl;
                cin >> address;
                DuLNode *p;
                FindNode(&head, address, &p);
                if (FindNode(&head, address, &p) == ERROR || p == NULL) {    //�жϽ���Ƿ����
                    cout << "�ý�㲻����" << endl;
                    break;
                }
                else {
                    ElemType e;
                    Status condition;
                    condition = DeleteList_DuL(p, &e);
                    if (condition == SUCCESS) {
                        cout << "ɾ���ɹ�" << endl;
                        cout << "��ɾ������е�����Ϊ��" << e << endl;
                    } else {
                        cout << "�ý��Ϊβ���,�����޽���ɾ" << endl;
                        break;
                    }
                }
                break;
            case (5):
                cout << "ȷ�����٣�" << endl;
                cout << "1-ȷ��  2-ȡ��" << endl;
                int number;
                cin >> number;
                if (number == 1) {
                    DestroyList_DuL(&head);
                    cout << "1.��ʼ������ 2.�˳�" << endl << "��ѡ��-" << endl;   //����֮��Ҫͨ����ʼ������֮����ܽ��в���Ȳ���
                    int choice_;
                    cin >> choice_;
                    switch (choice_) {
                        case (1):
                            InitList_DuL(&head);
                            break;
                        case (2):
                            exit(0);
                        default:
                            cout << "��������������" << endl;
                    }
                }
                break;
            case (6):
                exit(0);
            default:
                cout << "��������������" << endl;
                break;
        }
        system("pause");
	system("cls");
    }
}
