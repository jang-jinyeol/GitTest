#include <iostream>
using namespace std;


struct node { //노드

	int data;
	node* right;
	node* left;

};

struct bst{

	node* root=NULL; //NULL로 초기화
private:
	void Find(node* root, int val) { //원소를 찾는 함수

		if (root->data > val) { //루트값 보다 작고
		if (root->left)// 왼쪽 노드가 비어있지 않다면
			Find(root->left, val);//왼쪽노드로 재귀 호출
		else//왼쪽 노드가 비었다면 할당
		root->left = new node{ val,NULL,NULL };
		
	}
		else {//위와 동일
			if (root->right)
				Find(root->right, val);
			else
			root->right = new node{ val,NULL,NULL };
		
		}
	}
	void _inorder(node* root) { //중위순회

		if (!root)
			return;
		_inorder(root->left);
		cout << root->data << " ";
		_inorder(root->right);
	}
public:
	void Insert(int val) {

		if (!root) { //초기값 동적할당
		
			root = new node{ val,NULL,NULL };
			
		}
		else

		Find(root, val);//두번째 값부터는 위치 선정을 위한 함수
		
	}
public:
	void inorder() {

		_inorder(root); //중위순회 private으로 호출
	}


	void Delete(int val) {

		if (!root)
			return;
		Delete2(root , val);
		
	}


	node* find(int num) {

		
		 return find2(root, num);//private으로 선언된 find2를 호출
	}

private:
	node* Delete3(node* root, int val) {//현재 노드보다 큰값중에 가장 작은 값을 찾는 함수

		auto current = root->right; //현재 값보다 큰 값을 current에 담는다
		while (current->left) { //그다음 가장 작은 값을 찾는다

			current = current->left;
		}

		return current; //자기보다 큰 값이 없으면 NULL값을 return하게 된다

	}

	node* Delete2(node* root,int val) {

		if (val < root->data) { //루트보다 작으면
			

			root->left = Delete2(root->left, val); //왼쪽 노드를 루트로 재귀족 호출
	
		}

		else if (val > root->data) {

			root->right = Delete2(root->right, val);
			
	
		}

		else { //지우려는 값을 찾았다면
			if (!root->left) {//왼쪽이 비었다면
				auto tmp = root->right; //오른쪽 노드 임시저장
				delete root; //기존 노드 지우고
				return tmp; //임시노드를 return해서 자리를 잡음
			}
			else if (!root->right) {
				auto tmp = root->right;
				delete root;
				return tmp;
			}

			auto current = Delete3(root, val); //양쪽 노드가 모두 있을때

			root->data = current->data; //현재 노드보다 큰값중에 가장 작은 값을 찾았으므로 저장

			root->right = Delete2(root->right, current->data);//현재노드보다 큰값을 저장했으므로 현재 노드보다 큰값을 호출하여 삭제할 값을 찾는다.
																//즉 current->data는 삭제할 값
		}


		return root;
	}
	
	node* find2(node* root, int num) {
		//중위순회로 찾고, 찾았다면 return
		if (!root)
			return NULL;
		if (root->data > num) {
			cout << root->data << "에서 왼쪽으로 이동 ";
			return find2(root->left, num);
		};
		if (num == root->data) {
			cout << root->data << "을(를) 찾았습니다.! ";
			return root;
		}
		if (root->data < num) {
			cout << root->data << "에서 오른쪽으로 이동 ";
			return find2(root->right, num);
		};
		

	}




};


int main() {
	int n;
	bst tree; //객체 생성
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
	tree.inorder(); //중위 순회

	tree.Delete(20);//20을 삭제
	cout <<endl<< "제거 후 순회" << endl;
	tree.inorder();

	cout <<endl<< "찾고싶은 값을 입력하세요 : ";
	cin >> n;
	if (tree.find(n)) {//중위순회로 찾는값이 있는지 확인하는 함수
		cout << endl << n << "은(는) 트리에 있습니다.!";//찾는 값이 있다면 출력
	}
	else {
		cout <<endl<< n<<"은(는) 트리에 없습니다.!";//찾는 값이 없다면 출력
	}

}
