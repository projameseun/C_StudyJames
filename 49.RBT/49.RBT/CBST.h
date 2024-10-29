#pragma once
#include <assert.h>

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
	T1		second;		//밸류
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
	NODE_COLOR m_NodeColor;



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
		if (NodePosition[(int)NODE_POS::PARENT] == nullptr)
		{
			return false;
		}
		if (NodePosition[(int)NODE_POS::PARENT]->NodePosition[(int)NODE_POS::LCHILD] == this)
		{
			return true;
		}
		return false;
	}

	bool IsRightChild()
	{
		if (NodePosition[(int)NODE_POS::PARENT] == nullptr)
		{
			return false;
		}

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





	NODE_COLOR GetRedColor()
	{
		return NODE_COLOR::RED;
	}

	NODE_COLOR GetBlackColor()
	{
		return NODE_COLOR::BLACK;
	}

	NODE_COLOR GetColor()
	{
		return m_NodeColor;
	}

	


public:
	//Default 생성자
	FBSTNode() :
		pair(),
		NodePosition{},
		m_NodeColor{}
	{

	}

	//초기화 생성자
	FBSTNode(const FPair<T1, T2>& _pair, FBSTNode* _pParent, FBSTNode* _pLChild, FBSTNode* _pRChild) :
		pair(_pair),
		NodePosition{ _pParent, _pLChild, _pRChild },
		m_NodeColor(NODE_COLOR::Default)
	{

	}
	//Nil노드 생성자
	FBSTNode(FBSTNode* _pParent, FBSTNode* _pLChild, FBSTNode* _pRChild) :
		pair(make_mypair(0, 0)),
		NodePosition{ _pParent, _pLChild, _pRChild },
		m_NodeColor(NODE_COLOR::Default)
	{

	}

};


//BST
template <typename T1, typename T2>
class CBST
{
private:
	FBSTNode<T1, T2>*	m_pRoot;		//root
	FBSTNode<T1, T2>*	m_pNil;
	int					m_iCount;		//데이터개수


public:
	CBST() :
		m_pRoot(nullptr),
		m_iCount(0),
		m_pNil(nullptr)

	{




	}

public:
	bool insert(const FPair<T1, T2>& _pair);
	FBSTNode<T1, T2>* GetInOrderSuccessor(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetInOrderPredecessor(FBSTNode<T1, T2>* _pNode);


	FBSTNode<T1, T2>* GetParent(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetGrandParent(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetUncle(FBSTNode<T1, T2>* _pNode);

	NODE_POS ChangeNodePos(FBSTNode<T1, T2>* _pNode,NODE_POS _pos);
	
	int GetCount()
	{
		return m_iCount;
	}

	
	


	class iterator;
public:
	iterator begin();
	iterator end();
	iterator find(const T1& _find);
	iterator erase(const iterator& _iter);
	iterator insert(const iterator& _iter, const FPair<T1, T2>& _pair);

	iterator GetNilNode();

private:
	FBSTNode<T1, T2>* CASE(FBSTNode<T1, T2>*_pNewNode);
	FBSTNode<T1, T2>* CASEONE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);
	FBSTNode<T1, T2>* CASETWO(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos);
	FBSTNode<T1, T2>* CASETHREE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _role);
	FBSTNode<T1, T2>* Rotation(FBSTNode<T1, T2>* _pNewNode,NODE_POS _pos, int _iNumer);

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
		iterator(CBST<T1, T2>* m_pBST, FBSTNode<T1, T2>* m_pNode) :
			m_pBST(m_pBST),
			m_pNode(m_pNode)
		
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
		m_pNil->m_NodeColor = m_pNil->GetBlackColor();

		nodeColor = pNewNode->GetBlackColor();
		pNewNode->m_NodeColor = nodeColor;
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
				pNewNode->m_NodeColor = nodeColor;

				break;

			}

			else
			{
				pNode = pNode->NodePosition[(int)nodeType];

			}



		}

		//RBT에서는 leafNode가 Nil노드 
		if (pNewNode->IsLeafNode())
		{
			pNewNode->NodePosition[(int)NODE_POS::LCHILD] = m_pNil;
			pNewNode->NodePosition[(int)NODE_POS::RCHILD] = m_pNil;
		}


		//case에 이제 해당이 된다면 Rot
		// red가 두번연속으로 일어낫다
		//자가균형 함수를 발동시킨다 

		//RBT 조건 유형
		//1.노드는 red 또는 black이여야 된다.
		//2.root 노드는 black 이다.
		//3.모든 리프노드(NIL)은 블랙이다.
		//4.레드가 연속적으로 일어날수는 없다.
		//레드노드의 자식양쪽은 언제나 블랙이여야 된다.
		//5.어떤 노드로부터 시작되어 그에 속한 하위 리프노드에 도달 하는경우 모든경로에는 자기자신을 제외하고
		//블랙의수는 항상같다.



		//RED 두개로 4번속성위반 
		if (pNewNode->NodePosition[(int)NODE_POS::PARENT]->m_NodeColor == NODE_COLOR::RED)
		{
			pNewNode =CASE(pNewNode);
		}

		


		

	}


	//모든 root노드는 다시 black으로 변경해 준다.
	if (m_pRoot->m_NodeColor != NODE_COLOR::BLACK)
	{
		m_pRoot->m_NodeColor = NODE_COLOR::BLACK;
	}

	++m_iCount;
	return true;
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::CASE(FBSTNode<T1, T2>* _pNewNode)
{

		std::cout << "Case 발생!" << std::endl;

		if (_pNewNode == nullptr) return nullptr;

		//회전할때 case상태 변수
		int iCase = 0;

		FBSTNode<T1, T2>* TempNode = nullptr;

		FBSTNode<T1, T2>* pNewNodeGradParent = pNewNodeGradParent = GetGrandParent(_pNewNode);
		FBSTNode<T1, T2>* pNewUncle = pNewUncle = GetUncle(_pNewNode);
		FBSTNode<T1, T2>* pNewNodeParent = pNewNodeParent = GetParent(_pNewNode);

		//단반향 역방향 체크포지션
		NODE_POS CheckPosition = NODE_POS::START;
		NODE_POS CheckPosition2 = NODE_POS::START;
	

		
		if (pNewNodeParent == nullptr || pNewNodeGradParent == nullptr)
		{
			return _pNewNode;
		}
		
		//NewNode와 NewNode의 부모의 값을 둘이 비교해서 어느방향인지 찾아낸다

		CheckPosition = ChangeNodePos(_pNewNode, CheckPosition);
		CheckPosition2 = ChangeNodePos(pNewNodeParent, CheckPosition2);

		if (CheckPosition == NODE_POS::START || CheckPosition2 == NODE_POS::START)
		{
			return _pNewNode;
		}
				

		//CASE를돌리고 와서 다시 문제가 있는지 CASE3체크를 재귀적으로 해줘야 된다.

		//부모와 삼촌이 레드인경우
		// 부모와 삼춘을 black로 변경하고 할아버지를 red로변경하고 할아버지에서 반드시 확인한다 
		//CASE 1 
		if (pNewNodeParent->m_NodeColor == NODE_COLOR::RED && pNewUncle->m_NodeColor == NODE_COLOR::RED)
		{

			CASEONE(_pNewNode, CheckPosition);
			//할아버지에서 다시 확인을 한다 .

			if (m_pRoot->m_NodeColor != NODE_COLOR::BLACK)
			{
				m_pRoot->m_NodeColor = NODE_COLOR::BLACK;
			}

	

			//할아버지에서 반드시 확인한다.
			return CASE(pNewNodeGradParent);

		} 
		 
		//역방향 
		//CASE 2 방향이 다르고 삼촌이 검정색인 경우
		else if (CheckPosition != CheckPosition2 && pNewUncle->m_NodeColor == NODE_COLOR::BLACK)
		{

			CASETWO(_pNewNode, CheckPosition);
			//부모를 기준으로 해당방향으로 회전을 한다 
			iCase = 2;
			_pNewNode = Rotation(_pNewNode, CheckPosition2, iCase);

			//회전을 하였기때문에 방향도 변경이 되었을거다 그러기 때문에 
			// Post를 다시 체크 
		
			//무조건 회전하고 3번으로 변경해줘야된다.

		

			return CASE(_pNewNode);
		}

		//단방향
		//CASE 3 방향이 같고 삼촌이 블랙인경우 
		else if (CheckPosition == CheckPosition2 && pNewUncle->m_NodeColor == NODE_COLOR::BLACK)
		{
			//std::cout << "단방향 입니다 case3이 발생 하였습니다" << std::endl;

			CASETHREE(_pNewNode, CheckPosition);

			//GetGrandParent(_pNewNode);
			iCase = 3;
			//할아버지 기준으로 회전을 해준다.

			if (CheckPosition2 != NODE_POS::LCHILD)
			{
				CheckPosition2 = NODE_POS::LCHILD;
			}

			else
			{
				CheckPosition2 = NODE_POS::RCHILD;

			}


			_pNewNode = Rotation(_pNewNode, CheckPosition2, iCase);

		}

		
	
	




	return _pNewNode;

	//재귀적으로 한번더 체크를 해준다.
	
	


	
	//CASE가 만약에 발생하지 않는다면 이제 회전을 해줘도 된다.
	
	


	
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::CASEONE(FBSTNode<T1, T2>* _pNewNode,NODE_POS _pos)
{
	//삼촌 부모 레드확정

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewGradParent = GetGrandParent(_pNewNode);
	FBSTNode<T1, T2>* pNewUncle = GetUncle(_pNewNode);

	pNewNodeParent->m_NodeColor = NODE_COLOR::BLACK;
	pNewUncle->m_NodeColor = NODE_COLOR::BLACK;
	pNewGradParent->m_NodeColor = NODE_COLOR::RED;
	
	//할아버지에서 다시 시작한다

	return pNewGradParent;
}

template<typename T1, typename T2>
 inline typename FBSTNode<T1, T2>* CBST<T1, T2>::CASETWO(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos)
{

	return _pNewNode;
}

template<typename T1, typename T2>
 typename FBSTNode<T1, T2>* CBST<T1, T2>::CASETHREE(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos)
{

	NODE_COLOR tempColor = NODE_COLOR::Default;

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewGradParent = GetGrandParent(_pNewNode);

	//회전
	//1.부모와 할아버지 색을 변경 
	tempColor = pNewNodeParent->m_NodeColor;
	pNewNodeParent->m_NodeColor = pNewGradParent->m_NodeColor;
	pNewGradParent->m_NodeColor = tempColor;

	

	//2.할아버지 기준으로 회전


	return _pNewNode;
}

template<typename T1, typename T2>
 typename FBSTNode<T1, T2>* CBST<T1, T2>::Rotation(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos,int _iNumer)
{
	 //어떤 케이스에 따라 회전이 조금 달라진다
	 //CASE1


	FBSTNode<T1, T2>* pNewNodeGradParent = pNewNodeGradParent = GetGrandParent(_pNewNode);
	FBSTNode<T1, T2>* pNewUncle = pNewUncle = GetUncle(_pNewNode);
	FBSTNode<T1, T2>* pNewNodeParent = pNewNodeParent = GetParent(_pNewNode);

	 FBSTNode<T1, T2>* TempNode = nullptr;
	 FBSTNode<T1, T2>* PosTempNode = nullptr;
	 if (pNewNodeParent == nullptr || pNewNodeGradParent == nullptr)
	 {
		 return _pNewNode;
	 }

	 NODE_POS CheckPosition = NODE_POS::START;


	

	
	 if (_iNumer == 2)
	 {
	
			   //1.부모를 저장할 임시노드
			   //2.부모의 반대 방향노드가 부모가된다.
			   //3.새로운 부모의 남는 포지션쪽에 예전부모를 연결시켜준다.
		 //부모가 왼쪽
		 if (_pos == NODE_POS::LCHILD)
		 {
			
				
			 TempNode = pNewNodeParent;
			 PosTempNode = _pNewNode->NodePosition[(int)NODE_POS::RCHILD];


			 pNewNodeParent = _pNewNode;
			 pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = TempNode->NodePosition[(int)::NODE_POS::PARENT];
			 pNewNodeParent->NodePosition[(int)NODE_POS::LCHILD] = TempNode;
			 pNewNodeGradParent->NodePosition[(int)::NODE_POS::LCHILD] = pNewNodeParent;

			 TempNode->NodePosition[(int)::NODE_POS::PARENT] = pNewNodeParent;
			

			TempNode->NodePosition[(int)::NODE_POS::RCHILD] = PosTempNode;
			PosTempNode->NodePosition[(int)::NODE_POS::PARENT] = TempNode;
			

			 pNewNodeGradParent->NodePosition[(int)::NODE_POS::LCHILD] = _pNewNode;

				
		 }
		 //부모가 오른쪽
		 else
		 {
			 TempNode = pNewNodeParent;
			 PosTempNode = _pNewNode->NodePosition[(int)NODE_POS::RCHILD];

			 pNewNodeParent = _pNewNode;
			 pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = TempNode->NodePosition[(int)::NODE_POS::PARENT];
			 pNewNodeParent->NodePosition[(int)NODE_POS::RCHILD] = TempNode;
			 pNewNodeGradParent->NodePosition[(int)::NODE_POS::RCHILD] = pNewNodeParent;

			 TempNode->NodePosition[(int)::NODE_POS::PARENT] = pNewNodeParent;
		
			TempNode->NodePosition[(int)::NODE_POS::LCHILD] = PosTempNode;
			PosTempNode->NodePosition[(int)::NODE_POS::PARENT] = TempNode;
			
			
		


			 pNewNodeGradParent->NodePosition[(int)::NODE_POS::RCHILD] = _pNewNode;

		 }
	 }
	 else if (_iNumer == 3)
	 {

		 FBSTNode<T1, T2>* pChangeParent = nullptr;

		

		 //할아버지 기준으로 회전한다.
		 if (_pos == NODE_POS::LCHILD)
		 {
			 
			

			 //70
			 TempNode = pNewNodeGradParent;
							//80
			PosTempNode = pNewNodeParent->NodePosition[(int)NODE_POS::LCHILD];

			  pChangeParent  = GetParent(TempNode);
			 if (pNewNodeGradParent == m_pRoot)
			 {
				 m_pRoot = pNewNodeParent;
			 }

			 pNewNodeGradParent = pNewNodeParent;
			 pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = TempNode->NodePosition[(int)NODE_POS::PARENT];

			 CheckPosition = ChangeNodePos(TempNode, CheckPosition);
		
			 if (CheckPosition != NODE_POS::START)
			 {
				 pChangeParent->NodePosition[(int)CheckPosition] = pNewNodeParent;
			 }

			 pNewNodeGradParent->NodePosition[(int)NODE_POS::LCHILD] = TempNode;

			 TempNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeParent;
			 
			 TempNode->NodePosition[(int)::NODE_POS::RCHILD] = PosTempNode;
			 PosTempNode->NodePosition[(int)::NODE_POS::PARENT] = TempNode;


		



		 }
		 //부모가 오른쪽
		 else
		 {
			 TempNode = pNewNodeGradParent;
			 PosTempNode = pNewNodeParent->NodePosition[(int)NODE_POS::RCHILD];

			 pChangeParent = GetParent(TempNode);

			 if (pNewNodeGradParent == m_pRoot)
			 {
				 m_pRoot = pNewNodeParent;
			 }
			 pNewNodeGradParent = pNewNodeParent;
			 pNewNodeParent->NodePosition[(int)NODE_POS::PARENT] = TempNode->NodePosition[(int)NODE_POS::PARENT];

			 CheckPosition = ChangeNodePos(TempNode, CheckPosition);

			 if (CheckPosition != NODE_POS::START)
			 {
				pChangeParent->NodePosition[(int)CheckPosition] = pNewNodeParent;

			 }
			


			 pNewNodeGradParent->NodePosition[(int)NODE_POS::RCHILD] = TempNode;

			 TempNode->NodePosition[(int)NODE_POS::PARENT] = pNewNodeParent;
			 TempNode->NodePosition[(int)::NODE_POS::LCHILD] = m_pNil;
			 

			 TempNode->NodePosition[(int)::NODE_POS::LCHILD] = PosTempNode;
			 PosTempNode->NodePosition[(int)::NODE_POS::PARENT] = TempNode;
		 }
	 }
	 else
	 {
		 std::cout << "어느 케이스에도 해당이 되지 않습니다" << std::endl;
	 }
	
	 _pNewNode = TempNode;
	


	return _pNewNode;
}



//중위 후속자
template<typename T1, typename T2>
FBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pSuccesor = nullptr;

	if (m_pNil == _pNode)
	{
		return pSuccesor;
	}

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

	if (m_pNil == _pNode)
	{
		return pPredecessor;
	}

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
 typename NODE_POS CBST<T1, T2> ::ChangeNodePos(FBSTNode<T1, T2>* _pNode, NODE_POS _pos)
{
	 
	 //단방향인지 역방향인지
	 if (_pNode->IsLeftChild())
	 {
		 std::cout << "자식과 부모의 왼쪽이 같다" << std::endl;
		 _pos = NODE_POS::LCHILD;
	 }

	 else if (_pNode->IsRightChild())
	 {
		 std::cout << "자식과 부모의 오른쪽이 같다" << std::endl;
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
	return iterator(this,pNode);

}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename CBST<T1,T2>::iterator CBST<T1, T2>::GetNilNode()
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
		if (nullptr == pNode->NodePosition[(int)nodeType])
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

	////1.삭제할 노드가 단말노드의 경우
	//if (_iter.m_pNode->IsLeafNode())
	//{
	   // //부모가 삭제 되는 자식의 노드의 주소를 null로 만들어 준다.
	   // if (_iter.m_pNode->IsLeftChild())
	   // {
	   //	 _iter.m_pNode->ArrNode[(int)NODE_TYPE::PARENT]->ArrNode[(int)NODE_TYPE::LCHILD] = nullptr;
	   // }
	   // else
	   // {
	   //	 _iter.m_pNode->ArrNode[(int)NODE_TYPE::PARENT]->ArrNode[(int)NODE_TYPE::RCHILD] = nullptr;
	   // }

	   // delete _iter.m_pNode;
	   // 
	//}




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
		m_pNil->m_NodeColor = m_pNil->GetBlackColor();

		nodeColor = pNewNode->GetBlackColor();
		pNewNode->m_NodeColor = nodeColor;
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
				pNewNode->m_NodeColor = nodeColor;

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

		if (pNewNode->NodePosition[(int)NODE_POS::PARENT]->NodeColor == nodeColor)
		{

		}
		pNewNode = CASE(pNewNode, nodeColor);


		return iterator(this,pNewNode);
	}
}




template<typename T1, typename T2>
inline FBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(FBSTNode<T1, T2>* _pDelNode)
{

	FBSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pDelNode);

	//1.삭제할 노드가 단말노드의 경우
	if (_pDelNode->IsLeafNode())
	{
		pSuccessor = GetInOrderSuccessor(_pDelNode);


		if (_pDelNode == m_pRoot)
		{
			m_pRoot = nullptr;

		}
		else
		{
			//부모가 삭제 되는 자식의 노드의 주소를 null로 만들어 준다.
			if (_pDelNode->IsLeftChild())
			{
				_pDelNode->NodePosition[(int)NODE_POS::PARENT]->ArrNode[(int)NODE_POS::LCHILD] = nullptr;
			}
			else
			{
				_pDelNode->NodePosition[(int)NODE_POS::PARENT]->ArrNode[(int)NODE_POS::RCHILD] = nullptr;
			}
		}

		--m_iCount;

		delete _pDelNode;

	}
	//3.삭제할 노드가 2개의 자식을 가진경우 (중위 선행자 ,중위 후속자가 와야된다 중요)
	else if (_pDelNode->IsFullNode())
	{

		//삭제를 할 자리에 중위 후속자의 값을 복사 시킨다.
		_pDelNode->pair = pSuccessor->pair;


		//중위 후속자 노드를 삭제 한다.
		DeleteNode(pSuccessor);


		//삭제할 노드가 중위후속자가 된다.
		pSuccessor = _pDelNode;

	}
	//2.삭제할 노드가 자식노드를 한개 가진경우 (자식이 부모로 연결해준다 )
	else
	{
		pSuccessor = GetInOrderSuccessor(_pDelNode); //후속자노드 미리찾기

		NODE_POS nodetype = NODE_POS::LCHILD;
		if (_pDelNode->NodePosition[(int)NODE_POS::RCHILD])
		{
			nodetype = NODE_POS::RCHILD;
		}

		//삭제할 노드가 루트라면
		if (_pDelNode == m_pRoot)
		{
			//왼쪽 자식인지 오른쪾 자신인지 알아야됨 
			m_pRoot = _pDelNode->NodePosition[(int)nodetype];
			_pDelNode->NodePosition[(int)nodetype]->ArrNode[(int)NODE_POS::PARENT] = nullptr;
		}
		else
		{
			//삭제될 노드의 부모와 삭제될 노드의 자식을 연결
			if (_pDelNode->IsLeftChild())
			{
				_pDelNode->NodePosition[(int)NODE_POS::PARENT]->ArrNode[(int)NODE_POS::LCHILD] = _pDelNode->NodePosition[(int)nodetype];
			}
			else
			{
				_pDelNode->NodePosition[(int)NODE_POS::PARENT]->ArrNode[(int)NODE_POS::RCHILD] = _pDelNode->NodePosition[(int)nodetype];
			}

			_pDelNode->NodePosition[(int)nodetype]->ArrNode[(int)NODE_POS::PARENT] = _pDelNode->NodePosition[(int)NODE_POS::PARENT];


		}

		--m_iCount;

		delete _pDelNode;
	}

	//--m_iCount;

	return pSuccessor;
}

