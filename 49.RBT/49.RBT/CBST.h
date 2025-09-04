#pragma once
#include <assert.h>

//중위선택
enum class InorderSELECT
{
	SUCCESOR =100,
	PREDCESSOR = 200,
};



enum class NODE_POS
{
	PARENT,
	LCHILD,
	RCHILD,
	START,
};

enum class NODE_COLOR
{
	RED,
	BLACK,
	Default,
};



template<typename T1, typename T2>
struct FPair
{
	T1		first;		//키값
	T2		second;		//밸류
};


//make pair 생성
template<typename T1, typename T2>
FPair<T1, T2> make_mypair(const T1& _first, const T2& _second)
{
	return FPair<T1, T2>{_first, _second};
}


template<typename T1, typename T2>
struct FBSTNode
{
	FPair<T1, T2>		pair;					//data	map에서는 pair로 불른다.

	//같은노드가 있기때문에 배열로 만들어서 관리하면 좋다 
	FBSTNode* NodePosition[(int)NODE_POS::START];		//부모 자식둘을 관리하는 노드메모리
	NODE_COLOR	NodeColor;
	int			iExtraBlack = 0;		//extrablack 있는지 없는지 체크  1.이면 부여된거고 0이면 부여안된거 

public:
	bool IsRoot()
	{
		if (nullptr == NodePosition[(int)NODE_POS::PARENT])
		{

			return true;
		}
		return false;
	}


	bool IsLeftChild()
	{
		if (NodePosition[(int)NODE_POS::PARENT]->NodePosition[(int)NODE_POS::LCHILD] == this)
		{
			return true;
		}
		return false;
	}

	bool IsRightChild()
	{
		if (NodePosition[(int)NODE_POS::PARENT]->NodePosition[(int)NODE_POS::RCHILD] == this)
		{
			return true;
		}
		return false;
	}


	//삭제기능
	bool IsLeafNode()
	{
		if (NodePosition[(int)NODE_POS::LCHILD] == nullptr && NodePosition[(int)NODE_POS::RCHILD] == nullptr)
		{
			return true;
		}

		return false;
	}
	bool IsFullNode()	//자식을 다가진 상태
	{
		if (NodePosition[(int)NODE_POS::LCHILD] && NodePosition[(int)NODE_POS::RCHILD])
		{

			return true;
		}

		return false;
	}

	int  Getpairfirst()
	{
		return pair.first;
	}


public:


	NODE_COLOR GetRedColor()
	{
		return NODE_COLOR::RED;
	}

	NODE_COLOR GetBlackColor()
	{
		return NODE_COLOR::BLACK;
	}




public:
	//Default 생성자
	FBSTNode() :
		pair(),
		NodePosition{},
		NodeColor{}
	{
		//int a = 0;
	}

	//초기화 생성자
	FBSTNode(const FPair<T1, T2>& _pair, FBSTNode* _pParent, FBSTNode* _pLChild, FBSTNode* _pRChild) :
		pair(_pair),
		NodePosition{ _pParent, _pLChild, _pRChild },
		NodeColor(NODE_COLOR::Default)
	{

		int a = 0;
	}
	//Nil노드 생성자
	FBSTNode(FBSTNode* _pParent, FBSTNode* _pLChild, FBSTNode* _pRChild) :
		pair(),
		NodePosition{ _pParent, _pLChild, _pRChild },
		NodeColor(NODE_COLOR::Default)
	{

	}


};


//BST
template <typename T1, typename T2>
class CBST
{
private:
	FBSTNode<T1, T2>*	m_pRoot;		//root
	int					m_iCount;		//데이터개수
	FBSTNode<T1, T2>*	m_pNil;


public:
	CBST() :
		m_pRoot(nullptr),
		m_iCount(0),
		m_pNil(nullptr)
	{




	}
	~CBST() {
		Destroy(m_pRoot);
		delete m_pNil;   // NIL도 잊지 말고 해제
	}
private:
	void Destroy(FBSTNode<T1, T2>* node) {
		if (node == nullptr || node == m_pNil) return;
		Destroy(node->NodePosition[(int)NODE_POS::LCHILD]);
		Destroy(node->NodePosition[(int)NODE_POS::RCHILD]);
		delete node;
	}
	/*~CBST()
	{
		if (m_pRoot != nullptr)
		{
			delete m_pRoot;
			m_pRoot = nullptr;
		}
		if (m_pNil != nullptr)
		{
			delete  m_pNil;
			m_pNil = nullptr;
		}
	}*/
public:
	bool insert(const FPair<T1, T2>& _pair);
	FBSTNode<T1, T2>* GetInOrderSuccessor(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetInOrderPredecessor(FBSTNode<T1, T2>* _pNode);


	FBSTNode<T1, T2>* GetParent(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetGrandParent(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetUncle(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetSibling(FBSTNode<T1, T2>* _pNode);

	NODE_POS ChangeNodePos(FBSTNode<T1, T2>* _pNode, NODE_POS _pos);

	FBSTNode<T1, T2>* GetNILNODE()
	{
		return m_pNil;
	}

	class iterator;
public:
	iterator begin();
	iterator end();
	iterator GetNilNode();
	iterator find(const T1& _find);
	iterator erase(const iterator& _iter);
	iterator insert(const iterator& _iter, const FPair<T1, T2>& _pair);

private:

	//insertcase
	FBSTNode<T1, T2>* CASE(FBSTNode<T1, T2>* _pNewNode);
	FBSTNode<T1, T2>* CASEONE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);
	FBSTNode<T1, T2>* CASETWO(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);
	FBSTNode<T1, T2>* CASETHREE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _role);

	//삭제case
	FBSTNode<T1, T2>* DeleteCASE(FBSTNode<T1, T2>* _pNewNode, FBSTNode<T1, T2>* _pExNode,NODE_POS _CheckPos, NODE_POS _CheckPos2);
	FBSTNode<T1, T2>* DeleteCASEONE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);
	FBSTNode<T1, T2>* DeleteCASETWO(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);
	FBSTNode<T1, T2>* DeleteCASETHREE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);
	FBSTNode<T1, T2>* DeleteCASEFOUR(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);

	FBSTNode<T1, T2>* InsertRotation(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos, int _iNumber);
	FBSTNode<T1, T2>* DeleteRotation(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);

	//단말노드인경우
	void LeafNode(FBSTNode<T1, T2>* _pNewNode);
	//삭제할 노드자식이 한개인경우
	void ReplaceWithChild(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);


private:
	FBSTNode<T1, T2>* DeleteNode(FBSTNode<T1, T2>* _pDelNode);

public:
	class iterator
	{
	private:
		CBST<T1, T2>* m_pBST;		//bst본체를 알고잇기 
		FBSTNode<T1, T2>* m_pNode;	///특정 노드를 알기 

			//이터레이터 비교연산자
	public:
		bool operator == (const iterator& _other)
		{
			if (m_pBST == _other.m_pBST && m_pNode == _other.m_pNode)
			{
				return true;
			}

			return false;
		}

		bool operator != (const iterator& _other)
		{
			return !(*this == _other);
		}

		const FPair<T1, T2>& operator*()
		{
			//end iteartor 체크
			assert(m_pNode);

			return m_pNode->pair;
		}

		const FPair<T1, T2>* operator->()
		{
			//end iteartor 체크
			assert(m_pNode);

			return &m_pNode->pair;
		}

		//++ 중위순회 
		iterator& operator ++()
		{
			//중위후속자를 찾는다
			//m_pBST->GetInorderSuccessor(m_pNode);
			m_pNode = m_pBST->GetInOrderSuccessor(m_pNode);
			return *this;
		}

		//++ 중위순회 
		iterator& operator --()
		{
			//중위선행자를 찾는다
			//m_pBST->GetInorderSuccessor(m_pNode);
			m_pNode = m_pBST->GetInOrderPredecessor(m_pNode);
			return *this;
		}


	public:
		iterator() :
			m_pBST(nullptr),
			m_pNode(nullptr)
		{

		}
		iterator(CBST<T1, T2>* m_pBST, FBSTNode<T1, T2>* _m_pNode) :
			m_pBST(m_pBST),
			m_pNode(_m_pNode)
		{

		}
		
		


		friend class CBST<T1, T2>;


	};

};

template<typename T1, typename T2>
bool CBST<T1, T2>::insert(const FPair<T1, T2>& _pair)
{
	FBSTNode<T1, T2>* pNewNode = new FBSTNode < T1, T2>(_pair, nullptr, nullptr, nullptr);


	//insert는 기본적으로 red칼라를 넣어준다
	NODE_COLOR nodeColor = pNewNode->GetRedColor();


	//rootnode
	if (nullptr == m_pRoot)
	{
		//NillNode Init
		FBSTNode<T1, T2>* pNewNillNode = new FBSTNode < T1, T2>(nullptr, nullptr, nullptr);
		m_pNil = pNewNillNode;
		m_pNil->NodeColor = NODE_COLOR::BLACK;

		nodeColor = pNewNode->GetBlackColor();
		pNewNode->NodeColor = nodeColor;
		m_pRoot = pNewNode;

		m_pRoot->NodePosition[(int)NODE_POS::PARENT] = m_pNil;

		m_pRoot->NodePosition[(int)NODE_POS::LCHILD] = m_pNil;
		m_pRoot->NodePosition[(int)NODE_POS::RCHILD] = m_pNil;

	}
	else
	{
		//2번째로 올때 root 노드 안에 pair.first에서 비교를 해야될거다 
		//root에서 시작해서 leaf노드가 될때까지 비교하면서 내려가야 될것이다 결국 반복문 사용...

		FBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_POS nodeType = NODE_POS::START;

		//root 보다 new가 커서 만약에 오른쪽으로 계속 내려가다가
		//new랑 이미들어잇는 데이터가 같을때는 어떡해야되나?
		//map같은경우에는 중복을 허용하지 않는다 그래서 항상 find함수를 사용해서 이미 동일한 key값을 예외처리를 내가 해줘야된다.
		// 근데 multmap은 허용을하고 새로운공간 옆에 계속 추가된다 근데 만약에 이런식으로 만들어지면 이진탐색트리에 효율이 떨어진다.

		while (true)
		{


			//오른쪽
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_POS::RCHILD;

			}

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				nodeType = NODE_POS::LCHILD;
			}

			//같다
			else
			{
				return false;
			}

			//여기야
			if (pNode->NodePosition[(int)nodeType]->IsLeafNode())
			{

				pNode->NodePosition[(int)nodeType] = pNewNode;
				//pNode->NodeColor[(int)nodeColor] = pNewNode;
				pNewNode->NodePosition[(int)NODE_POS::PARENT] = pNode;
				pNewNode->NodeColor = nodeColor;

				break;

			}

			else
			{
				pNode = pNode->NodePosition[(int)nodeType];

			}



		}

		if (pNewNode->IsLeafNode())
		{
			pNewNode->NodePosition[(int)NODE_POS::LCHILD] = m_pNil;
			pNewNode->NodePosition[(int)NODE_POS::RCHILD] = m_pNil;
		}


		//RBT 조건 유형
	//1.노드는 red 또는 black이여야 한다.
	//2. root노드는 black이여야 된다.
	//3. 모든 리프노드(NIL)노드는 블랙이다.
	//4. 레드가 연속적으로 일어날수 없다. 
	//5. 어떤 노드로부터 시작이 되어 그에 속한 하위 리프노드에 도달 하는경우 모든 경로에는 자기자신을 제외하고 블랙의 수는 항상같다.




		//RED 두개로 4번속성위반 
		if (pNewNode->NodePosition[(int)NODE_POS::PARENT]->NodeColor == nodeColor)
		{
			CASE(pNewNode);
		}

	}

	//모든 root노드는 다시 black으로 변경해준다.
	if (m_pRoot->NodeColor != NODE_COLOR::BLACK)
	{
		m_pRoot->NodeColor = NODE_COLOR::BLACK;
		m_pRoot->NodePosition[(int)NODE_POS::PARENT] = m_pNil;
	}

	++m_iCount;
	return true;
}

template<typename T1, typename T2>
typename FBSTNode<T1, T2>* CBST<T1, T2>::CASE(FBSTNode<T1, T2>* _pNewNode)
{

	std::cout << "Case 발생!" << std::endl;


	if (_pNewNode == nullptr) return nullptr;


	NODE_POS CheckPosition = NODE_POS::START;
	NODE_POS CheckPosition2 = NODE_POS::START;

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewNodeGradParent = GetGrandParent(_pNewNode);
	FBSTNode<T1, T2>* pNewUncle = GetUncle(_pNewNode);


	//NewNode와 NewNode의 부모의 값을 둘이 비교해서 어느방향인지 찾아낸다

/*	if (pNewNode->pair.first == pNewNodeParent->NodePosition[(int)nodeType]->Getpairfirst())
	{
		std::cout << "New자식 부모의 왼쪽이 같다" << std::endl;
		CheckPosition = NODE_ROLE::LCHILD;


	}
	else
	{
		CheckPosition = NODE_ROLE::RCHILD;
	}*/


	if (pNewNodeParent == nullptr || pNewNodeGradParent == nullptr)
	{
		return _pNewNode;
	}


	//단방향인지 역방향인지 체크해주는 함수를 만든다.

	CheckPosition = ChangeNodePos(_pNewNode, CheckPosition);
	CheckPosition2 = ChangeNodePos(pNewNodeParent, CheckPosition2);

	if (CheckPosition == NODE_POS::START || CheckPosition2 == NODE_POS::START)
	{
		return _pNewNode;
	}



	//CASE 1 
	//부모,삼춘이 레드라면 black으로 변경한다 그리고 할아버지를 레드로 변경하고 
	//할아버지에서 반드시 체크를 한다.
	if (pNewNodeParent->NodeColor == NODE_COLOR::RED && pNewUncle->NodeColor == NODE_COLOR::RED)
	{
		CASEONE(_pNewNode, CheckPosition);

		if (m_pRoot->NodeColor != NODE_COLOR::BLACK)
		{
			m_pRoot->NodeColor = NODE_COLOR::BLACK;
		}
		//할아버지에서 다시 확인한다.
		return CASE(pNewNodeGradParent);

	}

	//CASE 2
	//역방향이고 삼촌이 블랙이라면 발생한다.
	//그렇다면 해당 부모의 기준으로 회전을 해서 CASE3번으로 만들어 준다.
	else if (CheckPosition != CheckPosition2 && pNewUncle->NodeColor == NODE_COLOR::BLACK && _pNewNode->NodeColor == NODE_COLOR::RED && pNewNodeParent->NodeColor == NODE_COLOR::RED)
	{
		CASETWO(_pNewNode, CheckPosition);

		//회전
		_pNewNode = InsertRotation(_pNewNode, CheckPosition2, 2);

		return CASE(_pNewNode);
	}


	//자식과 부모가 단방향이고 삼촌이 블랙일때 3번케이스 발생
	// 부모와 할아버지의 색을 변경한후 할아버지 기준으로 회전을 한다.
	//CASE 3
	else if (CheckPosition == CheckPosition2 && pNewUncle->NodeColor == NODE_COLOR::BLACK)
	{

		//부모와 할아버지 색을 변경
		CASETHREE(_pNewNode, CheckPosition);



		if (CheckPosition2 != NODE_POS::LCHILD)
		{
			CheckPosition2 = NODE_POS::LCHILD;
		}

		else
		{
			CheckPosition2 = NODE_POS::RCHILD;

		}


		_pNewNode = InsertRotation(_pNewNode, CheckPosition2, 3);


	}





	return _pNewNode;
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::CASEONE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos)
{
	//삼촌 부모 레드확정

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewGradParent = GetGrandParent(_pNewNode);
	FBSTNode<T1, T2>* pNewUncle = GetUncle(_pNewNode);

	pNewNodeParent->NodeColor = NODE_COLOR::BLACK;
	pNewUncle->NodeColor = NODE_COLOR::BLACK;
	pNewGradParent->NodeColor = NODE_COLOR::RED;



	return pNewGradParent;
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::CASETWO(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos)
{


	return _pNewNode;
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::CASETHREE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos)
{

	NODE_COLOR tempColor = NODE_COLOR::Default;

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewGradParent = GetGrandParent(_pNewNode);

	//회전
	//1.부모와 할아버지 색을 변경 
	tempColor = pNewNodeParent->NodeColor;
	pNewNodeParent->NodeColor = pNewGradParent->NodeColor;
	pNewGradParent->NodeColor = tempColor;



	//2.할아버지 기준으로 회전


	return _pNewNode;
}

template<typename T1, typename T2>
typename FBSTNode<T1, T2>* CBST<T1, T2>::DeleteCASE(FBSTNode<T1, T2>* _pSibling, FBSTNode<T1, T2>* _pExNode,NODE_POS _CheckPos, NODE_POS _CheckPos2)
{


	//extrablack에 black이 삭제됫을경우만 들어오게된다
	std::cout << "Delete Case 발생!" << std::endl;

	//이미 정해진 첫번째 extrablack이 들어와있다.
	FBSTNode<T1, T2>* pExNode = _pExNode;


	if (_pSibling == nullptr) return nullptr;
	if (pExNode == nullptr) return nullptr;

	NODE_POS CheckPosition = _CheckPos;
	NODE_POS CheckPosition2 = _CheckPos2;

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pSibling);
	FBSTNode<T1, T2>* pNewNodeGradParent = GetGrandParent(_pSibling);
	//FBSTNode<T1, T2>* pNewUncle = GetUncle(_pNewNode);





	if (pNewNodeParent == nullptr || pNewNodeGradParent == nullptr)
	{
		return _pSibling;
	}



	// case 함수를 하나만들어서 
	// 따로 관리하는게 좋다 
	//여기서 케이스 1~4번까지 로 나뉜다 

	//case1
	//1.오른쪽(왼쪽)형제가 red일때 
	//부모와 형제의 색을 바꾼다. 
	//부모의 기준으로 왼쪽(오른쪽)으로 회전한다.
	//다시 case2,3,4,중 하나로 해결한다

	if (_pSibling->NodeColor == NODE_COLOR::RED)
	{
		std::cout << "excase 1번 발생" << std::endl;
		DeleteCASEONE(_pSibling, CheckPosition);

		_pSibling = DeleteRotation(_pSibling, CheckPosition);

		DeleteCASE(_pSibling, pExNode, CheckPosition, CheckPosition2);

		
	}



	//case2
	//1. 형제가 black
	//2.그 형제의 자녀 모두 black일때 
	//기존 extrablack과 그형제의 블랙을 모아서 부모에게 전달해준다.(부모한테 extrablack을 부여가 된다)
	// 형제는 red로 변경해준다.
	//그리고 부모에서 extra black을 본다 
	if (_pSibling->NodeColor == NODE_COLOR::BLACK && pExNode->NodeColor == NODE_COLOR::BLACK &&
		_pSibling->NodePosition[(int)NODE_POS::LCHILD]->NodeColor == NODE_COLOR::BLACK && _pSibling->NodePosition[(int)NODE_POS::RCHILD]->NodeColor == NODE_COLOR::BLACK)
	{
		std::cout << "excase 2번 발생" << std::endl;
		DeleteCASETWO(_pSibling, CheckPosition);
		pExNode->iExtraBlack = 0;	//기존 엑스트라블랙을 없애준다

		pExNode = _pSibling->NodePosition[(int)NODE_POS::PARENT];
		pExNode->iExtraBlack = 1;

	
		if (pExNode->NodeColor == NODE_COLOR::RED)
		{
			pExNode->NodeColor = NODE_COLOR::BLACK;

		}
		//2. 블랙이라면 
		else if (pExNode->NodeColor == NODE_COLOR::BLACK)
		{

			if (_pSibling->NodePosition[(int)NODE_POS::PARENT] == m_pRoot)
			{
				_pSibling->NodePosition[(int)NODE_POS::PARENT]->NodeColor = NODE_COLOR::BLACK;
			}
			else
			{
				DeleteCASE(_pSibling, pExNode, CheckPosition, CheckPosition2);

			}



		}//else if (pExNode->NodeColor == NODE_COLOR::BLACK)

		
	}

	//case3 
	//1. 오른쪽(왼쪽) 형제가 black 
	//2. 왼쪽(오른쪽) 자녀가 red
	//3. 오른쪽(왼쪽) 자녀가 black
	//형제의 오른쪽(왼쪽) 자녀를 red가 되게 만들어서 case4번으로 다시 본다
	else if (_pSibling->NodeColor == NODE_COLOR::BLACK && _pSibling->NodePosition[(int)CheckPosition]->NodeColor == NODE_COLOR::RED &&
		_pSibling->NodePosition[(int)CheckPosition2]->NodeColor == NODE_COLOR::BLACK)
	{
		std::cout << "excase 3번 발생" << std::endl;
		DeleteCASETHREE(_pSibling, CheckPosition);
		_pSibling = DeleteRotation(_pSibling->NodePosition[(int)CheckPosition], CheckPosition2);
		

		DeleteCASE(_pSibling->NodePosition[(int)NODE_POS::PARENT], pExNode, CheckPosition, CheckPosition2);
	}

	//case4 
	//1. 오른쪽(왼쪽) 형제가 black
	//2. 오른쪽(왼쪽) 자녀가 red 
	else if (_pSibling->NodeColor == NODE_COLOR::BLACK && _pSibling->NodePosition[(int)CheckPosition2]->NodeColor == NODE_COLOR::RED)
	{
		std::cout << "excase 4번 발생" << std::endl;
		DeleteCASEFOUR(_pSibling, CheckPosition2);

		DeleteRotation(_pSibling, CheckPosition);

	}



	pExNode->iExtraBlack = 0;


	return _pSibling;
}

template<typename T1, typename T2>
typename FBSTNode<T1, T2>* CBST<T1, T2>::DeleteCASEONE(FBSTNode<T1, T2>* _pSibling, NODE_POS _pos)
{
	NODE_COLOR nodeColor = NODE_COLOR::Default;

	FBSTNode<T1, T2>* pParentNode = GetParent(_pSibling);

	nodeColor = _pSibling->NodeColor;

	_pSibling->NodeColor = pParentNode->NodeColor;
	pParentNode->NodeColor = nodeColor;
	

	return _pSibling;
}

template<typename T1, typename T2>
typename FBSTNode<T1, T2>* CBST<T1, T2>::DeleteCASETWO(FBSTNode<T1, T2>* _pSibling, NODE_POS _pos)
{
	_pSibling->NodeColor = NODE_COLOR::RED;
	
	return _pSibling;
}

template<typename T1, typename T2>
typename FBSTNode<T1, T2>* CBST<T1, T2>::DeleteCASETHREE(FBSTNode<T1, T2>* _pSibling, NODE_POS _pos)
{
	NODE_COLOR color = NODE_COLOR::Default;

	color = _pSibling->NodeColor;
	_pSibling->NodeColor = _pSibling->NodePosition[(int)_pos]->NodeColor;
	_pSibling->NodePosition[(int)_pos]->NodeColor = color;
	 
	return _pSibling;
}

template<typename T1, typename T2>
typename FBSTNode<T1, T2>* CBST<T1, T2>::DeleteCASEFOUR(FBSTNode<T1, T2>* _pSibling, NODE_POS _pos)
{
	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pSibling);
	//형제가 들어올거다
	_pSibling->NodeColor = pNewNodeParent->NodeColor;
	_pSibling->NodePosition[(int)_pos]->NodeColor = NODE_COLOR::BLACK;
	pNewNodeParent->NodeColor = NODE_COLOR::BLACK;
	return _pSibling;
}

template<typename T1, typename T2>
typename  FBSTNode<T1, T2>* CBST<T1, T2>::InsertRotation(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos, int _iCase)
{

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewNodeGradParent = GetGrandParent(_pNewNode);
	FBSTNode<T1, T2>* pNewUncle = GetUncle(_pNewNode);
	//FBSTNode<T1, T2>* pNewSibling = GetSibling(_pNewNode);


	//할아버지의 할아버지 조상
	FBSTNode<T1, T2>* pNewGGParent = GetParent(pNewNodeGradParent);



	NODE_POS CheckPosition = NODE_POS::START;

	//원래 있었던 노드에서 짤려서 새로운 노드에 자식이 입히는 노드
	FBSTNode<T1, T2>* pNewChildNode = nullptr;


	if (pNewNodeParent == nullptr || pNewNodeGradParent == nullptr || pNewGGParent == nullptr)
	{
		return _pNewNode;
	}

	if (_iCase == 2)
	{

		//회전을 부모기준으로 오른쪽으로 할지 왼쪽으로 할지를 정해줘야 된다.

		//1.부모를 tmep저장
		//2.부모자리에 자식이 들어간다
		//3.형제 자리에 부모가 간다.

		//부모의 자식이 왼쪽
		if (_pos == NODE_POS::LCHILD)
		{


			pNewChildNode = _pNewNode->NodePosition[(int)NODE_POS::LCHILD];

			_pNewNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeGradParent;
			_pNewNode->NodePosition[(int)NODE_POS::LCHILD] = pNewNodeParent;

			pNewNodeGradParent->NodePosition[(int)::NODE_POS::LCHILD] = _pNewNode;
			pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = _pNewNode;

			pNewNodeParent->NodePosition[(int)::NODE_POS::RCHILD] = pNewChildNode;





		}
		//부모의 자식이 오른쪽
		else if (_pos == NODE_POS::RCHILD)
		{
			pNewChildNode = _pNewNode->NodePosition[(int)NODE_POS::RCHILD];

			_pNewNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeGradParent;
			_pNewNode->NodePosition[(int)NODE_POS::RCHILD] = pNewNodeParent;

			pNewNodeGradParent->NodePosition[(int)::NODE_POS::RCHILD] = _pNewNode;
			pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = _pNewNode;

			pNewNodeParent->NodePosition[(int)::NODE_POS::LCHILD] = pNewChildNode;


		}


		if (pNewChildNode->NodePosition[(int)NODE_POS::PARENT] != nullptr)

		{
			pNewChildNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeParent;

		}


		return pNewNodeParent;

	}
	else if (_iCase == 3)
	{

		if (pNewNodeGradParent == m_pRoot)
		{
			m_pRoot = pNewNodeParent;
		}


		if (_pos == NODE_POS::LCHILD)
		{

			pNewChildNode = pNewNodeParent->NodePosition[(int)NODE_POS::LCHILD];
			pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = pNewGGParent;


			CheckPosition = ChangeNodePos(pNewNodeGradParent, CheckPosition);

			if (pNewGGParent != m_pNil || nullptr)
			{
				pNewGGParent->NodePosition[(int)CheckPosition] = pNewNodeParent;

			}

			pNewNodeParent->NodePosition[(int)NODE_POS::LCHILD] = pNewNodeGradParent;



			pNewNodeGradParent->NodePosition[(int)NODE_POS::PARENT] = pNewNodeParent;

			pNewNodeGradParent->NodePosition[(int)NODE_POS::RCHILD] = pNewChildNode;




		}
		else if (_pos == NODE_POS::RCHILD)
		{

			pNewChildNode = pNewNodeParent->NodePosition[(int)NODE_POS::RCHILD];

			pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = pNewGGParent;


			CheckPosition = ChangeNodePos(pNewNodeGradParent, CheckPosition);

			if (pNewGGParent != m_pNil || nullptr)
			{
				pNewGGParent->NodePosition[(int)CheckPosition] = pNewNodeParent;

			}

			pNewNodeParent->NodePosition[(int)NODE_POS::RCHILD] = pNewNodeGradParent;



			pNewNodeGradParent->NodePosition[(int)NODE_POS::PARENT] = pNewNodeParent;

			pNewNodeGradParent->NodePosition[(int)NODE_POS::LCHILD] = pNewChildNode;


		}


		if (pNewChildNode->NodePosition[(int)NODE_POS::PARENT] != nullptr)

		{
			pNewChildNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeGradParent;

		}


		_pNewNode = pNewNodeGradParent;
	}

	return _pNewNode;
}

template<typename T1, typename T2>
typename  FBSTNode<T1, T2>* CBST<T1, T2>::DeleteRotation(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos)
{
	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewNodeGradParent = GetGrandParent(_pNewNode);
	FBSTNode<T1, T2>* pNewUncle = GetUncle(_pNewNode);
	//FBSTNode<T1, T2>* pNewSibling = GetSibling(_pNewNode);


	//할아버지의 할아버지 조상
	FBSTNode<T1, T2>* pNewGGParent = GetParent(pNewNodeGradParent);



	NODE_POS CheckPosition = NODE_POS::START;
	NODE_POS SiblingPos = NODE_POS::START;


	SiblingPos = ChangeNodePos(pNewNodeParent, CheckPosition);

	//원래 있었던 노드에서 짤려서 새로운 노드에 자식이 입히는 노드
	FBSTNode<T1, T2>* pNewChildNode = nullptr;


	if (pNewNodeParent == nullptr || pNewNodeGradParent == nullptr || pNewGGParent == nullptr)
	{
		return _pNewNode;
	}


		//부모의 자식이 왼쪽
		if (_pos == NODE_POS::LCHILD)
		{


			pNewChildNode = _pNewNode->NodePosition[(int)NODE_POS::LCHILD];

			_pNewNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeGradParent;
			_pNewNode->NodePosition[(int)NODE_POS::LCHILD] = pNewNodeParent;

			if (SiblingPos == NODE_POS::LCHILD)
			{
				std::cout << "Left" << std::endl;
			}
			else if (SiblingPos == NODE_POS::RCHILD)
			{
				std::cout << "right" << std::endl;
			}
		
			pNewNodeGradParent->NodePosition[(int)SiblingPos] = _pNewNode;
			//pNewNodeGradParent->NodePosition[(int)::NODE_POS::LCHILD] = _pNewNode;
			pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = _pNewNode;

			pNewNodeParent->NodePosition[(int)::NODE_POS::RCHILD] = pNewChildNode;





		}
		//부모의 자식이 오른쪽
		else if (_pos == NODE_POS::RCHILD)
		{
			pNewChildNode = _pNewNode->NodePosition[(int)NODE_POS::RCHILD];

			_pNewNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeGradParent;
			_pNewNode->NodePosition[(int)NODE_POS::RCHILD] = pNewNodeParent;

			if (SiblingPos == NODE_POS::LCHILD)
			{
				std::cout << "Left" << std::endl;
			}
			else if (SiblingPos == NODE_POS::RCHILD)
			{
				std::cout << "right" << std::endl;
			}


			pNewNodeGradParent->NodePosition[(int)SiblingPos] = _pNewNode;
			//pNewNodeGradParent->NodePosition[(int)::NODE_POS::RCHILD] = _pNewNode;
			pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = _pNewNode;

			pNewNodeParent->NodePosition[(int)::NODE_POS::LCHILD] = pNewChildNode;


		}


		if (pNewChildNode->NodePosition[(int)NODE_POS::PARENT] != nullptr)

		{
			pNewChildNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeParent;
			return pNewChildNode;
		}

		return pNewNodeParent;
		

	
	

	//return _pNewNode;
}

template<typename T1, typename T2>
inline void CBST<T1, T2>::LeafNode(FBSTNode<T1, T2>* _pDelNode)
{
	if (_pDelNode == m_pRoot)
	{
		m_pRoot = m_pNil;

	}
	else
	{
		//부모가 삭제 되는 자식의 노드의 주소를 null로 만들어 준다.
		if (_pDelNode->IsLeftChild())
		{
			_pDelNode->NodePosition[(int)NODE_POS::PARENT]->NodePosition[(int)NODE_POS::LCHILD] = m_pNil;
		}
		else
		{
			_pDelNode->NodePosition[(int)NODE_POS::PARENT]->NodePosition[(int)NODE_POS::RCHILD] = m_pNil;
		}
	}

}

template<typename T1, typename T2>
inline void CBST<T1, T2>::ReplaceWithChild(FBSTNode<T1, T2>* _pDelNode, NODE_POS _pos)
{

	//삭제할 노드가 루트라면
	if (_pDelNode == m_pRoot)
	{
		//왼쪽 자식인지 오른쪾 자신인지 알아야됨 
		m_pRoot = _pDelNode->NodePosition[(int)_pos];
		_pDelNode->NodePosition[(int)_pos]->NodePosition[(int)NODE_POS::PARENT] = m_pNil;
	}
	else
	{
		//삭제될 노드의 부모와 삭제될 노드의 자식을 연결
		if (_pDelNode->IsLeftChild())
		{
			_pDelNode->NodePosition[(int)NODE_POS::PARENT]->NodePosition[(int)NODE_POS::LCHILD] = _pDelNode->NodePosition[(int)_pos];
		}
		else
		{
			_pDelNode->NodePosition[(int)NODE_POS::PARENT]->NodePosition[(int)NODE_POS::RCHILD] = _pDelNode->NodePosition[(int)_pos];
		}

		_pDelNode->NodePosition[(int)_pos]->NodePosition[(int)NODE_POS::PARENT] = _pDelNode->NodePosition[(int)NODE_POS::PARENT];



	}

}



//중위 후속자
template<typename T1, typename T2>
FBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pSuccesor = nullptr;

	//1.오른쪽 자식이 있는 경우 오른쪽 자식으로가서, 왼쪽 자식이 없을때 까지 내려감 
	if (_pNode->NodePosition[(int)NODE_POS::RCHILD] != m_pNil)
	{
		pSuccesor = _pNode->NodePosition[(int)NODE_POS::RCHILD];

		while (pSuccesor->NodePosition[(int)NODE_POS::LCHILD] != m_pNil)
		{
			pSuccesor = pSuccesor->NodePosition[(int)NODE_POS::LCHILD];
		}
	}

	//2.오른쪽 자식이 없으면 부모로 부터 왼쪽 자식 일때 까지 위로 올라감 
	//그때 부모가 후속자 
	else
	{
		pSuccesor = _pNode;


		while (pSuccesor != m_pNil)	//true를 하지않는이유 무한루프를돌수잇는걸 방지하기 위해서
		{

			if (pSuccesor->IsRoot())
			{
				return nullptr;
			}
			else
			{
				// 현재 노드가 부모의 왼쪽 자식인 경우 부모가 후속자
				if (pSuccesor->IsLeftChild())
				{
					//부모후속자
					pSuccesor = GetParent(pSuccesor);
					break;
				}
				else
				{
					// 오른쪽 자식인 경우, 부모로 계속 올라감
					pSuccesor = GetParent(pSuccesor);
				}
			}
		}




	}

	return pSuccesor;
}

//중위 선행자
template<typename T1, typename T2>
inline FBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pPredecessor = nullptr;

	//1.왼쪽 자식이 있는 경우 왼쪽 자식으로가서, 오른쪽 자식이 없을때 까지 내려감 
	if (_pNode->NodePosition[(int)NODE_POS::LCHILD] != m_pNil)
	{
		pPredecessor = _pNode->NodePosition[(int)NODE_POS::LCHILD];

		while (pPredecessor->NodePosition[(int)NODE_POS::RCHILD] != m_pNil)
		{
			pPredecessor = pPredecessor->NodePosition[(int)NODE_POS::RCHILD];
		}
	}

	//2.왼쪽 자식이 없으면 부모로 부터 오른쪽 자식 일때 까지 위로 올라감 
	//그때 부모가 선행자 
	else
	{
		pPredecessor = _pNode;

		while (pPredecessor != m_pNil)
		{

			if (pPredecessor->IsRoot())
			{
				return nullptr;
			}
			else
			{
				//왼쪽인지 체크
				if (pPredecessor->IsRightChild())
				{
					//부모선행자
					pPredecessor = GetParent(pPredecessor);
					break;
				}
				else
				{
					pPredecessor = GetParent(pPredecessor);
				}
			}
		}




	}

	return pPredecessor;
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::GetParent(FBSTNode<T1, T2>* _pNode)
{

	if (_pNode == m_pNil)
	{
		return _pNode;
	}
	return _pNode->NodePosition[(int)NODE_POS::PARENT];
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::GetGrandParent(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pNodeParent = _pNode->NodePosition[(int)NODE_POS::PARENT];
	return pNodeParent->NodePosition[(int)NODE_POS::PARENT];
}

template<typename T1, typename T2>
typename FBSTNode<T1, T2>* CBST<T1, T2>::GetUncle(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pNodeParent = _pNode->NodePosition[(int)NODE_POS::PARENT];
	FBSTNode<T1, T2>* pNodeGrandParent = pNodeParent->NodePosition[(int)NODE_POS::PARENT];
	NODE_POS UnclePos = NODE_POS::START;

	if (pNodeParent == nullptr)
	{
		return nullptr;
	}

	if (pNodeGrandParent == nullptr)
	{
		return nullptr;
	}
	if (pNodeParent->IsLeftChild())
	{
		UnclePos = NODE_POS::RCHILD;
	}
	else
	{
		UnclePos = NODE_POS::LCHILD;
	}




	return pNodeGrandParent->NodePosition[(int)UnclePos];
}

template<typename T1, typename T2>
typename FBSTNode<T1, T2>* CBST<T1, T2>::GetSibling(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pNodeParent = _pNode->NodePosition[(int)NODE_POS::PARENT];

	FBSTNode<T1, T2>* pNodeSibling = nullptr;
	if (pNodeParent == nullptr)
	{
		return nullptr;
	}

	//왼쪽자식
	if (_pNode->IsLeftChild())
	{

		pNodeSibling = pNodeParent->NodePosition[(int)NODE_POS::RCHILD];
		return pNodeSibling;
	}
	//오르쪽자식
	if (_pNode->IsRightChild())
	{
		pNodeSibling = pNodeParent->NodePosition[(int)NODE_POS::LCHILD];
		return pNodeSibling;
	}




}



template<typename T1, typename T2>
typename NODE_POS CBST<T1, T2>::ChangeNodePos(FBSTNode<T1, T2>* _pNode, NODE_POS _pos)
{

	if (_pNode == m_pNil)
	{
		return _pos;
	}
	//단방향인지 역방향인지
	if (_pNode->IsLeftChild())
	{

		_pos = NODE_POS::LCHILD;
	}

	else if (_pNode->IsRightChild())
	{

		_pos = NODE_POS::RCHILD;
	}
	else
	{

		std::cout << "다르다" << std::endl;
	}



	return _pos;
}



//반환타입이 본인 타입 이너클래스면 typename 적어줘야됨
template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	//바이너리 탐색 이진트리에서는 중위순회가 가장중요하고 그곳이 첫번째가 될 것이다.
	FBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->NodePosition[(int)NODE_POS::LCHILD] != m_pNil)
	{
		pNode = pNode->NodePosition[(int)NODE_POS::LCHILD];


	}
	return iterator(this, pNode);

}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename  CBST<T1, T2>::iterator CBST<T1, T2>::GetNilNode()
{
	FBSTNode<T1, T2>* pNode = m_pNil;
	return iterator(this, pNode);
}

template<typename T1, typename T2>
typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{



	FBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_POS nodeType = NODE_POS::START;


	while (true)
	{
		//오른쪽
		if (pNode->pair.first < _find)
		{
			nodeType = NODE_POS::RCHILD;

		}
		//왼쪽
		else if (pNode->pair.first > _find)
		{
			nodeType = NODE_POS::LCHILD;
		}
		//같다
		else
		{
			break;

		}

		//찾지 못함
		if (m_pNil == pNode->NodePosition[(int)nodeType])
		{
			pNode = nullptr;
			break;


		}
		//더찾기
		else
		{
			pNode = pNode->NodePosition[(int)nodeType];

		}

	}

	return iterator(this, pNode);



}

template<typename T1, typename T2>
typename CBST<T1, T2>::iterator CBST<T1, T2>::erase(const iterator& _iter)
{




	//중위 후속자, 중위 선행자는 자식이하나거나 없는경우 밖에 없다 

	assert(_iter.m_pBST == this);

	FBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode);




	return iterator(this, pSuccessor);
}

template<typename T1, typename T2>
typename CBST<T1, T2>::iterator CBST<T1, T2>::insert(const iterator& _iter, const FPair<T1, T2>& _pair)
{


	FBSTNode<T1, T2>* pNewNode = new FBSTNode < T1, T2>(_pair, nullptr, nullptr, nullptr);


	//insert는 기본적으로 red칼라를 넣어준다
	NODE_COLOR nodeColor = pNewNode->GetRedColor();


	//rootnode
	if (nullptr == m_pRoot)
	{
		//NillNode Init
		FBSTNode<T1, T2>* pNewNillNode = new FBSTNode < T1, T2>(nullptr, nullptr, nullptr);
		m_pNil = pNewNillNode;
		m_pNil->NodeColor = m_pNil->GetBlackColor();

		nodeColor = pNewNode->GetBlackColor();
		pNewNode->NodeColor = nodeColor;
		m_pRoot = pNewNode;

		m_pRoot->NodePosition[(int)NODE_POS::PARENT] = m_pNil;

		m_pRoot->NodePosition[(int)NODE_POS::LCHILD] = m_pNil;
		m_pRoot->NodePosition[(int)NODE_POS::RCHILD] = m_pNil;

	}
	else
	{
		//2번째로 올때 root 노드 안에 pair.first에서 비교를 해야될거다 
		//root에서 시작해서 leaf노드가 될때까지 비교하면서 내려가야 될것이다 결국 반복문 사용...

		FBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_POS nodeType = NODE_POS::START;

		//root 보다 new가 커서 만약에 오른쪽으로 계속 내려가다가
		//new랑 이미들어잇는 데이터가 같을때는 어떡해야되나?
		//map같은경우에는 중복을 허용하지 않는다 그래서 항상 find함수를 사용해서 이미 동일한 key값을 예외처리를 내가 해줘야된다.
		// 근데 multmap은 허용을하고 새로운공간 옆에 계속 추가된다 근데 만약에 이런식으로 만들어지면 이진탐색트리에 효율이 떨어진다.

		while (true)
		{


			//오른쪽
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_POS::RCHILD;

			}

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				nodeType = NODE_POS::LCHILD;
			}

			//같다
			else
			{
				return  iterator(nullptr, nullptr);
			}

			//여기야
			if (pNode->NodePosition[(int)nodeType]->IsLeafNode())
			{

				pNode->NodePosition[(int)nodeType] = pNewNode;
				//pNode->NodeColor[(int)nodeColor] = pNewNode;
				pNewNode->NodePosition[(int)NODE_POS::PARENT] = pNode;
				pNewNode->NodeColor = nodeColor;

				break;

			}

			else
			{
				pNode = pNode->NodePosition[(int)nodeType];

			}



		}

		if (pNewNode->IsLeafNode())
		{
			pNewNode->NodePosition[(int)NODE_POS::LCHILD] = m_pNil;
			pNewNode->NodePosition[(int)NODE_POS::RCHILD] = m_pNil;
		}




		return iterator(this, pNewNode);
	}
}



template<typename T1, typename T2>
inline FBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(FBSTNode<T1, T2>* _pDelNode)
{
	//후속자
	//FBSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pDelNode);

	int iSelect = (int)InorderSELECT::PREDCESSOR;;

	//기본은 선행자로 한다.
	FBSTNode<T1, T2>* pSuccessor = nullptr;
	FBSTNode<T1, T2>* pPredecessor = GetInOrderPredecessor(_pDelNode);


	//삭제되는색의 대체가 되는 노드(extrablack이 부여될ㄷ노드)
	FBSTNode<T1, T2>* pExNode = nullptr;
	FBSTNode<T1, T2>* pNewSibling = GetSibling(_pDelNode);


	if (_pDelNode->NodePosition[(int)NODE_POS::LCHILD] == m_pNil)
	{
		pSuccessor = GetInOrderSuccessor(_pDelNode);

		iSelect = (int)InorderSELECT::SUCCESOR;
	}
	

	if (_pDelNode == m_pRoot)
	{
	
		pNewSibling = m_pNil;

		
	}
	



	NODE_POS CheckPosition = NODE_POS::START;
	NODE_POS CheckPosition2 = NODE_POS::START;
	CheckPosition = ChangeNodePos(_pDelNode, CheckPosition);
	CheckPosition2 = ChangeNodePos(pNewSibling, CheckPosition2);




	if (pNewSibling == nullptr)
	{
		return _pDelNode;
	}


	//삭제되는 색 
	NODE_COLOR DeleteNodeColor = NODE_COLOR::Default;

	//1.삭제할 노드가 단말노드의 경우
	if (_pDelNode->NodePosition[(int)NODE_POS::LCHILD] == m_pNil && _pDelNode->NodePosition[(int)NODE_POS::RCHILD] == m_pNil)
	{
		//삭제가 단말노드인경우
		LeafNode(_pDelNode);

		//삭제되는 색의 대체되는 노드에 extranode를 하나 만들어준다 
		pExNode = m_pNil;

		--m_iCount;
	
		//삭제 될려는 노드가 단말노드이거나 자식이 한개인경우는 삭제되는 노드가 삭제되는 색이된다.
		DeleteNodeColor = _pDelNode->NodeColor;

		delete _pDelNode;



	

	}
	//3.삭제할 노드가 2개의 자식을 가진경우 (중위 선행자 ,중위 후속자가 와야된다 중요)
	else if (_pDelNode->NodePosition[(int)NODE_POS::LCHILD] != m_pNil && _pDelNode->NodePosition[(int)NODE_POS::RCHILD] != m_pNil)
	{

		//삭제를 할 자리에 중위 후속자의 값을 복사 시킨다.
		
			
			pExNode = _pDelNode;

		

		if (iSelect == (int)InorderSELECT::PREDCESSOR)
		{
			_pDelNode->pair = pPredecessor->pair;

			//중위 노드를 삭제 한다.
			DeleteNode(pPredecessor);

			

		}
		else if (iSelect == (int)InorderSELECT::SUCCESOR)
		{
			_pDelNode->pair = pSuccessor->pair;

			//중위  노드를 삭제 한다.
			DeleteNode(pSuccessor);

			
		}


	}
	//2.삭제할 노드가 자식노드를 한개 가진경우 (자식이 부모로 연결해준다 )
	else
	{

		NODE_POS nodetype = (_pDelNode->NodePosition[(int)NODE_POS::RCHILD] != m_pNil) ? NODE_POS::RCHILD : NODE_POS::LCHILD;

		if (iSelect == (int)InorderSELECT::PREDCESSOR)
		{
			pPredecessor = GetInOrderPredecessor(_pDelNode); //후속자노드 미리찾기
			pExNode = pPredecessor;

		}
		else if (iSelect == (int)InorderSELECT::SUCCESOR)
		{
			pSuccessor = GetInOrderSuccessor(_pDelNode); //후속자노드 미리찾기
			pExNode = pSuccessor;

		}

		ReplaceWithChild(_pDelNode, nodetype);
	
		--m_iCount;


		//삭제 될려는 노드가 단말노드이거나 자식이 한개인경우는 삭제되는 노드가 삭제되는 색이된다.
		DeleteNodeColor = _pDelNode->NodeColor;

		delete _pDelNode;
	}

	
	if (iSelect == (int)InorderSELECT::PREDCESSOR)
	{
		if (pPredecessor == m_pRoot)
		{
			pExNode->iExtraBlack = 0;

			return (iSelect == (int)InorderSELECT::PREDCESSOR) ? pPredecessor : pSuccessor;
		}

	}
	else if (iSelect == (int)InorderSELECT::SUCCESOR)
	{
		if (pSuccessor == m_pRoot)
		{
			pExNode->iExtraBlack = 0;

			return (iSelect == (int)InorderSELECT::PREDCESSOR) ? pPredecessor : pSuccessor;
			
		}

	}
	

	
	//삭제되는색이 검은색이라면 여기서 상황발생 
	if (DeleteNodeColor == NODE_COLOR::BLACK)
	{

		//해당노드는 이미 삭제가 되었기때문에 후속자를 넘긴다 
		std::cout << "블랙이 삭제되었습니다" << std::endl;

		

		//삭제되는색의 대체되는색이 extra black이 red 또는 black 
		pExNode->iExtraBlack = 1;
		//1. 레드라면
		if (pExNode->NodeColor == NODE_COLOR::RED)
		{
			pExNode->NodeColor = NODE_COLOR::BLACK;

		}
		//2. 블랙이라면 
		else if (pExNode->NodeColor == NODE_COLOR::BLACK)
		{

			DeleteCASE(pNewSibling,pExNode,CheckPosition,CheckPosition2);
			
			
		}//else if (pExNode->NodeColor == NODE_COLOR::BLACK)

		


	}


	//--m_iCount;

	//다하고 extrablack은 다시 원래대로 돌려준다
	pExNode->iExtraBlack = 0;

	
	return (iSelect == (int)InorderSELECT::PREDCESSOR) ? pPredecessor : pSuccessor;
	
}
