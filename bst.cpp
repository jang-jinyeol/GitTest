#include <iostream>
using namespace std;


struct node { //���

	int data;
	node* right;
	node* left;

};

struct bst{

	node* root=NULL; //NULL�� �ʱ�ȭ
private:
	void Find(node* root, int val) { //���Ҹ� ã�� �Լ�

		if (root->data > val) { //��Ʈ�� ���� �۰�
		if (root->left)// ���� ��尡 ������� �ʴٸ�
			Find(root->left, val);//���ʳ��� ��� ȣ��
		else//���� ��尡 ����ٸ� �Ҵ�
		root->left = new node{ val,NULL,NULL };
		
	}
		else {//���� ����
			if (root->right)
				Find(root->right, val);
			else
			root->right = new node{ val,NULL,NULL };
		
		}
	}
	void _inorder(node* root) { //������ȸ

		if (!root)
			return;
		_inorder(root->left);
		cout << root->data << " ";
		_inorder(root->right);
	}
public:
	void Insert(int val) {

		if (!root) { //�ʱⰪ �����Ҵ�
		
			root = new node{ val,NULL,NULL };
			
		}
		else

		Find(root, val);//�ι�° �����ʹ� ��ġ ������ ���� �Լ�
		
	}
public:
	void inorder() {

		_inorder(root); //������ȸ private���� ȣ��
	}


	void Delete(int val) {

		if (!root)
			return;
		Delete2(root , val);
		
	}


	node* find(int num) {

		
		 return find2(root, num);//private���� ����� find2�� ȣ��
	}

private:
	node* Delete3(node* root, int val) {//���� ��庸�� ū���߿� ���� ���� ���� ã�� �Լ�

		auto current = root->right; //���� ������ ū ���� current�� ��´�
		while (current->left) { //�״��� ���� ���� ���� ã�´�

			current = current->left;
		}

		return current; //�ڱ⺸�� ū ���� ������ NULL���� return�ϰ� �ȴ�

	}

	node* Delete2(node* root,int val) {

		if (val < root->data) { //��Ʈ���� ������
			

			root->left = Delete2(root->left, val); //���� ��带 ��Ʈ�� ����� ȣ��
	
		}

		else if (val > root->data) {

			root->right = Delete2(root->right, val);
			
	
		}

		else { //������� ���� ã�Ҵٸ�
			if (!root->left) {//������ ����ٸ�
				auto tmp = root->right; //������ ��� �ӽ�����
				delete root; //���� ��� �����
				return tmp; //�ӽó�带 return�ؼ� �ڸ��� ����
			}
			else if (!root->right) {
				auto tmp = root->right;
				delete root;
				return tmp;
			}

			auto current = Delete3(root, val); //���� ��尡 ��� ������

			root->data = current->data; //���� ��庸�� ū���߿� ���� ���� ���� ã�����Ƿ� ����

			root->right = Delete2(root->right, current->data);//�����庸�� ū���� ���������Ƿ� ���� ��庸�� ū���� ȣ���Ͽ� ������ ���� ã�´�.
																//�� current->data�� ������ ��
		}


		return root;
	}
	
	node* find2(node* root, int num) {
		//������ȸ�� ã��, ã�Ҵٸ� return
		if (!root)
			return NULL;
		if (root->data > num) {
			cout << root->data << "���� �������� �̵� ";
			return find2(root->left, num);
		};
		if (num == root->data) {
			cout << root->data << "��(��) ã�ҽ��ϴ�.! ";
			return root;
		}
		if (root->data < num) {
			cout << root->data << "���� ���������� �̵� ";
			return find2(root->right, num);
		};
		

	}




};


int main() {
	int n;
	bst tree; //��ü ����
	tree.Insert(12);
	tree.Insert(10);

	tree.Insert(20);
	tree.Insert(8);

	tree.Insert(11);
	tree.Insert(28);
	tree.Insert(4);
	tree.Insert(2);
	tree.Insert(15);
	tree.Insert(30);
	tree.Insert(27);
	tree.inorder(); //���� ��ȸ

	tree.Delete(20);//20�� ����
	cout <<endl<< "���� �� ��ȸ" << endl;
	tree.inorder();

	cout <<endl<< "ã����� ���� �Է��ϼ��� : ";
	cin >> n;
	if (tree.find(n)) {//������ȸ�� ã�°��� �ִ��� Ȯ���ϴ� �Լ�
		cout << endl << n << "��(��) Ʈ���� �ֽ��ϴ�.!";//ã�� ���� �ִٸ� ���
	}
	else {
		cout <<endl<< n<<"��(��) Ʈ���� �����ϴ�.!";//ã�� ���� ���ٸ� ���
	}

}
