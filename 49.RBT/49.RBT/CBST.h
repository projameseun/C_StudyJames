#pragma once
#include <assert.h>

enum class NODE_ROLE
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
	FBSTNode* NodePosition[(int)NODE_ROLE::START];		//부모 자식둘을 관리하는 노드메모리
	NODE_COLOR NodeColor;



public:
	bool IsRoot()
	{
		if (nullptr == NodePosition[(int)NODE_ROLE::PARENT])
		{

			return true;
		}
		return false;
	}


	bool IsLeftChild()
	{
		if (NodePosition[(int)NODE_ROLE::PARENT]->NodePosition[(int)NODE_ROLE::LCHILD] == this)
		{
			return true;
		}
		return false;
	}

	bool IsRightChild()
	{
		if (NodePosition[(int)NODE_ROLE::PARENT]->NodePosition[(int)NODE_ROLE::RCHILD] == this)
		{
			return true;
		}
		return false;
	}


	//삭제기능
	bool IsLeafNode()
	{
		if (NodePosition[(int)NODE_ROLE::LCHILD] == nullptr && NodePosition[(int)NODE_ROLE::RCHILD] == nullptr)
		{
			return true;
		}

		return false;
	}
	bool IsFullNode()	//자식을 다가진 상태
	{
		if (NodePosition[(int)NODE_ROLE::LCHILD] && NodePosition[(int)NODE_ROLE::RCHILD])
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



public:
	//Default 생성자
	FBSTNode() :
		pair(),
		NodePosition{},
		NodeColor{}
	{

	}

	//초기화 생성자
	FBSTNode(const FPair<T1, T2>& _pair, FBSTNode* _pParent, FBSTNode* _pLChild, FBSTNode* _pRChild) :
		pair(_pair),
		NodePosition{ _pParent, _pLChild, _pRChild },
		NodeColor(NODE_COLOR::Default)
	{

	}
	//Nil노드 생성자
	FBSTNode(FBSTNode* _pParent, FBSTNode* _pLChild, FBSTNode* _pRChild) :
		pair(make_mypair(0, 0)),
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
	FBSTNode<T1, T2>*	m_pNill;
	int					m_iCount;		//데이터개수



public:
	CBST() :
		m_pRoot(nullptr),
		m_iCount(0)

	{




	}

public:
	bool insert(const FPair<T1, T2>& _pair);
	FBSTNode<T1, T2>* GetInOrderSuccessor(FBSTNode<T1, T2>* _pNode);
	FBSTNode<T1, T2>* GetInOrderPredecessor(FBSTNode<T1, T2>* _pNode);


	FBSTNode<T1, T2>* GetParent(FBSTNode<T1, T2>* _pNode);
	


	class iterator;
public:
	iterator begin();
	iterator end();
	iterator find(const T1& _find);
	iterator erase(const iterator& _iter);
	iterator insert(const iterator& _iter, const FPair<T1, T2>& _pair);

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
			m_pNode(nullptr),
			m_pBST(nullptr)
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
		m_pNill = pNewNillNode;
		m_pNill->NodeColor = m_pNill->GetBlackColor();

		nodeColor = pNewNode->GetBlackColor();
		pNewNode->NodeColor = nodeColor;
		m_pRoot = pNewNode;

		m_pRoot->NodePosition[(int)NODE_ROLE::PARENT] = m_pNill;

		m_pRoot->NodePosition[(int)NODE_ROLE::LCHILD] = m_pNill;
		m_pRoot->NodePosition[(int)NODE_ROLE::RCHILD] = m_pNill;

	}
	else 
	{
		//2번째로 올때 root 노드 안에 pair.first에서 비교를 해야될거다 
		//root에서 시작해서 leaf노드가 될때까지 비교하면서 내려가야 될것이다 결국 반복문 사용...
		
		FBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_ROLE nodeType = NODE_ROLE::START;

		//root 보다 new가 커서 만약에 오른쪽으로 계속 내려가다가
		//new랑 이미들어잇는 데이터가 같을때는 어떡해야되나?
		//map같은경우에는 중복을 허용하지 않는다 그래서 항상 find함수를 사용해서 이미 동일한 key값을 예외처리를 내가 해줘야된다.
		// 근데 multmap은 허용을하고 새로운공간 옆에 계속 추가된다 근데 만약에 이런식으로 만들어지면 이진탐색트리에 효율이 떨어진다.

		while (true)
		{


			//오른쪽
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_ROLE::RCHILD;

			}

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				nodeType = NODE_ROLE::LCHILD;
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
				pNewNode->NodePosition[(int)NODE_ROLE::PARENT] = pNode;
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
			pNewNode->NodePosition[(int)NODE_ROLE::LCHILD] = m_pNill;
			pNewNode->NodePosition[(int)NODE_ROLE::RCHILD] = m_pNill;
		}


		//case에 이제 해당이 된다면 Rot
		// red가 두번연속으로 일어낫다
		//자가균형 함수를 발동시킨다 

		if (pNewNode->NodePosition[(int)NODE_ROLE::PARENT]->NodeColor == nodeColor)
		{
			std::cout << "Case 발생!" << std::endl;
			
			
			
			NODE_ROLE CheckPosition = NODE_ROLE::START;
			NODE_ROLE CheckPosition2 = NODE_ROLE::START;

			FBSTNode<T1, T2>* pNewNodeParent = pNewNode->NodePosition[(int)NODE_ROLE::PARENT];

			

			//NewNode와 NewNode의 부모의 값을 둘이 비교해서 어느방향인지 찾아낸다
		
		/*	if (pNewNode->pair.first == pNewNodeParent->NodePosition[(int)nodeType]->Getpairfirst())
			{
				std::cout << "New자식 부모의 왼쪽이 같다" << std::endl;
				CheckPosition = NODE_ROLE::LCHILD;


			}*/
			
			if (pNewNode->IsLeftChild())
			{
				std::cout << "New자식 부모의 왼쪽이 같다" << std::endl;
				CheckPosition = NODE_ROLE::LCHILD;
			}
		
			else if (pNewNode->IsRightChild())
			{
				std::cout << "New자식 부모의 오른쪽이 같다" << std::endl;
				CheckPosition = NODE_ROLE::RCHILD;
			}
			else
			{
				std::cout << "다르다" << std::endl;
			}


			//pNewNodeParent와 pNewNodeParent의 부모(NewNodeㅇ할아버지)의 값을 둘이 비교해서 어느방향인지 찾아낸다
			if (pNewNodeParent->IsLeftChild())
			{
				std::cout << "New부모와 할아버지 왼쪽이 같다" << std::endl;
				CheckPosition2 = NODE_ROLE::LCHILD;


			}
			else if (pNewNodeParent->IsRightChild())
			{
				std::cout << "New부모와 할아버지 오른쪽이 같다" << std::endl;
				CheckPosition2 = NODE_ROLE::RCHILD;
			}
			else
			{
				std::cout << "다르다" << std::endl;
			}

			//CASE 1 

			//CASE 2

			//단방향
			//CASE 3
			if (CheckPosition == CheckPosition2)
			{
				std::cout << "단방향 입니다 case3이 발생 하였습니다" << std::endl;
			}
			else
			{
				std::cout << "꺾였습니다" << std::endl;
			}


			//회전

		}

	}

	++m_iCount;
	return true;
}

//중위 후속자
template<typename T1, typename T2>
FBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pSuccesor = nullptr;

	//1.오른쪽 자식이 있는 경우 오른쪽 자식으로가서, 왼쪽 자식이 없을때 까지 내려감 
	if (_pNode->NodePosition[(int)NODE_ROLE::RCHILD] != m_pNill)
	{
		pSuccesor = _pNode->NodePosition[(int)NODE_ROLE::RCHILD];

		while (pSuccesor->NodePosition[(int)NODE_ROLE::LCHILD])
		{
			pSuccesor = pSuccesor->NodePosition[(int)NODE_ROLE::LCHILD];
		}
	}

	//2.오른쪽 자식이 없으면 부모로 부터 왼쪽 자식 일때 까지 위로 올라감 
	//그때 부모가 후속자 
	else
	{
		pSuccesor = _pNode;

		while (pSuccesor != m_pNill)	//true를 하지않는이유 무한루프를돌수잇는걸 방지하기 위해서
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
	if (_pNode->NodePosition[(int)NODE_ROLE::LCHILD] != m_pNill)
	{
		pPredecessor = _pNode->NodePosition[(int)NODE_ROLE::LCHILD];

		while (pPredecessor->NodePosition[(int)NODE_ROLE::RCHILD])
		{
			pPredecessor = pPredecessor->NodePosition[(int)NODE_ROLE::RCHILD];
		}
	}

	//2.왼쪽 자식이 없으면 부모로 부터 오른쪽 자식 일때 까지 위로 올라감 
	//그때 부모가 선행자 
	else
	{
		pPredecessor = _pNode;

		while (pPredecessor != m_pNill)
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
inline FBSTNode<T1, T2>* CBST<T1, T2>::GetParent(FBSTNode<T1, T2>* _pNode)
{
	return _pNode->NodePosition[(int)NODE_ROLE::PARENT];
}



//반환타입이 본인 타입 이너클래스면 typename 적어줘야됨
template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	//바이너리 탐색 이진트리에서는 중위순회가 가장중요하고 그곳이 첫번째가 될 것이다.
	FBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->NodePosition[(int)NODE_ROLE::LCHILD] != m_pNill)
	{
		pNode = pNode->NodePosition[(int)NODE_ROLE::LCHILD];
		
		
	}
	return iterator(this,pNode);

}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{



	FBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_ROLE nodeType = NODE_ROLE::START;


	while (true)
	{
		//오른쪽
		if (pNode->pair.first < _find)
		{
			nodeType = NODE_ROLE::RCHILD;

		}
		//왼쪽
		else if (pNode->pair.first > _find)
		{
			nodeType = NODE_ROLE::LCHILD;
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
		m_pNill = pNewNillNode;
		m_pNill->NodeColor = m_pNill->GetBlackColor();

		nodeColor = pNewNode->GetBlackColor();
		pNewNode->NodeColor = nodeColor;
		m_pRoot = pNewNode;

		m_pRoot->NodePosition[(int)NODE_ROLE::PARENT] = m_pNill;

		m_pRoot->NodePosition[(int)NODE_ROLE::LCHILD] = m_pNill;
		m_pRoot->NodePosition[(int)NODE_ROLE::RCHILD] = m_pNill;

	}
	else
	{
		//2번째로 올때 root 노드 안에 pair.first에서 비교를 해야될거다 
		//root에서 시작해서 leaf노드가 될때까지 비교하면서 내려가야 될것이다 결국 반복문 사용...

		FBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_ROLE nodeType = NODE_ROLE::START;

		//root 보다 new가 커서 만약에 오른쪽으로 계속 내려가다가
		//new랑 이미들어잇는 데이터가 같을때는 어떡해야되나?
		//map같은경우에는 중복을 허용하지 않는다 그래서 항상 find함수를 사용해서 이미 동일한 key값을 예외처리를 내가 해줘야된다.
		// 근데 multmap은 허용을하고 새로운공간 옆에 계속 추가된다 근데 만약에 이런식으로 만들어지면 이진탐색트리에 효율이 떨어진다.

		while (true)
		{


			//오른쪽
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_ROLE::RCHILD;

			}

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				nodeType = NODE_ROLE::LCHILD;
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
				pNewNode->NodePosition[(int)NODE_ROLE::PARENT] = pNode;
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
			pNewNode->NodePosition[(int)NODE_ROLE::LCHILD] = m_pNill;
			pNewNode->NodePosition[(int)NODE_ROLE::RCHILD] = m_pNill;
		}


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
				_pDelNode->NodePosition[(int)NODE_ROLE::PARENT]->ArrNode[(int)NODE_ROLE::LCHILD] = nullptr;
			}
			else
			{
				_pDelNode->NodePosition[(int)NODE_ROLE::PARENT]->ArrNode[(int)NODE_ROLE::RCHILD] = nullptr;
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

		NODE_ROLE nodetype = NODE_ROLE::LCHILD;
		if (_pDelNode->NodePosition[(int)NODE_ROLE::RCHILD])
		{
			nodetype = NODE_ROLE::RCHILD;
		}

		//삭제할 노드가 루트라면
		if (_pDelNode == m_pRoot)
		{
			//왼쪽 자식인지 오른쪾 자신인지 알아야됨 
			m_pRoot = _pDelNode->NodePosition[(int)nodetype];
			_pDelNode->NodePosition[(int)nodetype]->ArrNode[(int)NODE_ROLE::PARENT] = nullptr;
		}
		else
		{
			//삭제될 노드의 부모와 삭제될 노드의 자식을 연결
			if (_pDelNode->IsLeftChild())
			{
				_pDelNode->NodePosition[(int)NODE_ROLE::PARENT]->ArrNode[(int)NODE_ROLE::LCHILD] = _pDelNode->NodePosition[(int)nodetype];
			}
			else
			{
				_pDelNode->NodePosition[(int)NODE_ROLE::PARENT]->ArrNode[(int)NODE_ROLE::RCHILD] = _pDelNode->NodePosition[(int)nodetype];
			}

			_pDelNode->NodePosition[(int)nodetype]->ArrNode[(int)NODE_ROLE::PARENT] = _pDelNode->NodePosition[(int)NODE_ROLE::PARENT];


		}

		--m_iCount;

		delete _pDelNode;
	}

	//--m_iCount;

	return pSuccessor;
}

