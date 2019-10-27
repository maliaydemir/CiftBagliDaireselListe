#include "iostream"
using namespace std;
struct node
{
	int cc;
	int data;
	node *prev;
	node *next;
};

class liste
{
	node *root = NULL;

public:
	int count = 0;
	//ekle
	void ekle(int x) {
		count++;
		if (root == NULL)
		{
			root = new node;
			root->data = x;
			root->prev = root;
			root->next = root;

		}
		else
		{

			node *yrd = new node;
			yrd->data = x;
			yrd->prev = root->prev;
			yrd->next = root;

			root->prev->next = yrd;
			root->prev = yrd;

		}

	}
	void basaekle(int x) {
		count++;
		if (root == NULL)
		{
			ekle(x);
		}
		else
		{
			node *yrd = new node;
			yrd->data = x;
			yrd->next = root;
			yrd->prev = root->prev;

			root->prev->next = yrd;
			root->prev = yrd;
			root = yrd;
		}
	}
	void arayaekle(int indis, int x) {
		if (indis <= count&&indis>-1)
		{
			count++;
			node *yrd = getir(indis);
			node *tmp = new node;
			tmp->data = x;
			tmp->prev = yrd;
			tmp->next = yrd->next;

			yrd->next->prev = tmp;
			yrd->next = tmp;
		}

	}
	//verilen indis üzerinde iþlem yapar
	void sil(int indis) {
		node *yrd = NULL;
		if (indis <= count&&indis>-1)
		{
			yrd = getir(indis);
		}
		else
		{
			cout << "Yanlis indis degeri girildi.." << endl;
			return;
		}
		if (indis == 0)
		{
			//bastansil
			yrd->next->prev = yrd->prev;
			yrd->prev->next = yrd->next;
			root = root->next;
			delete yrd;

		}
		else
		{
			yrd->next->prev = yrd->prev;
			yrd->prev->next = yrd->next;
			delete yrd;
		}
		count--;
	}
	void guncelle(int indis, int x) {
		if (indis <= count&&indis>-1)
		{
			getir(indis)->data = x;
		}
	}

	//liste içinde aradýðýnýz int deðerinin indisini size verir
	int bul(int x) {
		//deðeri arar bulduðu indisi geri döndürür
		node *yrd = root;
		int indis = 0;
		while (yrd->next != root)
		{
			if (yrd->data == x)
			{
				return indis;
			}
			yrd = yrd->next;
			indis++;
		}
		if (yrd->data == x)
		{
			return indis + 1;
		}
		else
		{
			return -1;
		}

	}
	//diziyi küçükten büyüðe sýralar
	void sirala() {
		for (int i = 0; i<count; i++) {
			for (int j = i + 1; j<count; j++) {
				if (getir(i)->data>getir(j)->data) {
					degistir(i, j);
				}
			}
		}
	}
	//liste içinde indis numarasýný verdiðininz node yapýsýný size veriri
	node *getir(int indis) {
		node *yrd = root;
		int i = 0;
		if (indis <= count&&indis>-1)
		{
			for (int i = 0; i < indis; i++)
			{
				yrd = yrd->next;

			}
			return yrd;
		}
		else
		{
			cout << "Yanlis indis degeri girildi.." << endl;
			return NULL;
		}

	}
	//liste içinde 2 elemanýn yerini deðiþtirir
	void degistir(int indis1, int indis2) {
		if ((indis1>count&&indis1>-1) || (indis2>count&&indis2>-1))
		{
			cout << "Yanlis indis degeri girildi.." << endl;
			return;
		}
		node* yrd1 = getir(indis1);
		node* yrd2 = getir(indis2);

		int tmp = yrd1->data;
		yrd1->data = yrd2->data;
		yrd2->data = tmp;


	}
	//listenin tüm elemanlarýný yazdýrýr
	void yazdir() {
		node *yrd = root;
		while (yrd->next != root)
		{
			cout << yrd->data << " ";
			yrd = yrd->next;
		}

		cout << yrd->data << " ";
		yrd = yrd->next;
	}

};


void main() {
	liste l;
	for (int i = 0; i < 15; i++)
	{
		l.ekle(i);
	}
	l.basaekle(7);
	l.yazdir();
	system("pause");

	l.sirala();
	l.yazdir();
	system("pause");
	cout << l.bul(3);
	system("pause");

}