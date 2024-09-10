#pragma once
#include <assert.h>

enum class NODE_TYPE
{
	PARENT,
	LCHILD,
	RCHILD,
	START,
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
	FPair<T1,T2>		pair;					//data	map에서는 pair로 불른다.

	//같은노드가 있기때문에 배열로 만들어서 관리하면 좋다 
	FBSTNode*			ArrNode[(int)NODE_TYPE::START];		//부모 자식둘을 관리하는 노드메모리
	//FBSTNode*			pParent;		//부모노드
	//FBSTNode*			pLeftChild;		//왼쪽자식노드
	//FBSTNode*			pRightChild;		//오른쪽자식 노드

public:
	bool IsRoot()
	{
		if (nullptr == ArrNode[(int)NODE_TYPE::PARENT])
		{
			return true;
		}
		return false;
	}

	bool IsLeftChild()
	{
		if (ArrNode[(int)NODE_TYPE::PARENT]->ArrNode[(int)NODE_TYPE::LCHILD] == this)
		{
			return true;
		}
		return false;
	}

	bool IsRightChild()
	{
		if (ArrNode[(int)NODE_TYPE::PARENT]->ArrNode[(int)NODE_TYPE::RCHILD] == this)
		{
			return true;
		}
		return false;
	}

public:
	FBSTNode():
		pair(),
		ArrNode{}
	{

	}

	FBSTNode(const FPair<T1, T2>& _pair, FBSTNode* _pParent, FBSTNode* _pLChild, FBSTNode* _pRChild) :
		pair(_pair),
		ArrNode{ _pParent, _pLChild, _pRChild }
	{

	}
};

template <typename T1, typename T2>
class CBST
{
private:
	FBSTNode<T1,T2>*	m_pRoot;		//root
	int					m_iCount;		//데이터개수



public:
	CBST() :
		m_pRoot(nullptr),
		m_iCount(0)
	{

	}

public:
	bool insert(const FPair<T1,T2>& _pair);
	FBSTNode<T1, T2>* GetInOrderSuccessor(FBSTNode<T1,T2>* _pNode);
	FBSTNode<T1, T2>* GetInOrderPredecessor(FBSTNode<T1, T2>* _pNode);
	
	FBSTNode<T1, T2>* GetParent(FBSTNode<T1, T2>* _pNode);


	class iterator;
public:
	iterator begin();
	iterator end();
	iterator find(const T1& _find);

public:
	class iterator
	{
	private:
		CBST<T1, T2>*		m_pBST;		//bst본체를 알고잇기 
		FBSTNode<T1, T2>*	m_pNode;	///특정 노드를 알기 

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
			//중위후속자를 찾는다
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
		

	};

};

template<typename T1, typename T2>
 bool CBST<T1, T2>::insert(const FPair<T1, T2>& _pair)
{
	 FBSTNode<T1, T2>* pNewNode = new FBSTNode < T1, T2>(_pair,nullptr,nullptr,nullptr);

	/*FBSTNode<T1, T2>* pNewNode = new FBSTNode < T1, T2>();

		pNewNode->pair = _pair;
		pNewNode->pParent = nullptr;
		pNewNode->pLeftChild = nullptr;
		pNewNode->pRightChild = nullptr;*/

	//rootnode
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		//2번째로 올때 root 노드 안에 pair.first에서 비교를 해야될거다 
		//root에서 시작해서 leaf노드가 될때까지 비교하면서 내려가야 될것이다 결국 반복문 사용...

		FBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE nodeType = NODE_TYPE::START;

		//root 보다 new가 커서 만약에 오른쪽으로 계속 내려가다가
		//new랑 이미들어잇는 데이터가 같을때는 어떡해야되나?
		//map같은경우에는 중복을 허용하지 않는다 그래서 항상 find함수를 사용해서 이미 동일한 key값을 예외처리를 내가 해줘야된다.
		// 근데 multmap은 허용을하고 새로운공간 옆에 계속 추가된다 근데 만약에 이런식으로 만들어지면 이진탐색트리에 효율이 떨어진다.

		while (true)
		{
			
#pragma region FIRST
			////오른쪽
			//if (pNode->pair.first < pNewNode->pair.first)
			//{
			//	nodeType = NODE_TYPE::RCHILD;

			//	//여기야
			//	if (nullptr == pNode->pRightChild)
			//	{
			//		pNode->pRightChild = pNewNode;
			//		pNewNode->pParent = pNode;
			//		break;

			//	}
			//	//node를 다시 갱신해라 
			//	else
			//	{
			//		pNode = pNode->pRightChild;
			//	}

			//}
			////왼쪾
			//else if (pNode->pair.first > pNewNode->pair.first)
			//{

			//	nodeType = NODE_TYPE::LCHILD;
			//	//여기야
			//	if (nullptr == pNode->pLeftChild)
			//	{
			//		pNode->pLeftChild = pNewNode;
			//		pNewNode->pParent = pNode;
			//		break;

			//	}
			//	//node를 다시 갱신해라 
			//	else
			//	{
			//		pNode = pNode->pLeftChild;
			//	}
			//}
			////같다
			//else
			//{
			//	return false;
			//}
#pragma endregion

			//오른쪽
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_TYPE::RCHILD;

			}

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				nodeType = NODE_TYPE::LCHILD;
			}
			
				//같다
			else
			{
				return false;
			}
			
			//여기야
			if (nullptr == pNode->ArrNode[(int)nodeType])
			{
				pNode->ArrNode[(int)nodeType] = pNewNode;
				pNewNode->ArrNode[(int)NODE_TYPE::PARENT] = pNode;
				break;

			}
			
			else
			{
				pNode = pNode->ArrNode[(int)nodeType];
			
			}

		

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
	 if (_pNode->ArrNode[(int)NODE_TYPE::RCHILD] != nullptr)
	 {
		 pSuccesor = _pNode->ArrNode[(int)NODE_TYPE::RCHILD];
		 
		 while (pSuccesor->ArrNode[(int)NODE_TYPE::LCHILD])
		 {
			 pSuccesor =  pSuccesor->ArrNode[(int)NODE_TYPE::LCHILD];
		 }
	 }

	 //2.오른쪽 자식이 없으면 부모로 부터 왼쪽 자식 일때 까지 위로 올라감 
	 //그때 부모가 후속자 
	 else
	 {
		 pSuccesor = _pNode;

		 while (pSuccesor != nullptr)	//true를 하지않는이유 무한루프를돌수잇는걸 방지하기 위해서
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
	 if (_pNode->ArrNode[(int)NODE_TYPE::LCHILD] != nullptr)
	 {
		 pPredecessor = _pNode->ArrNode[(int)NODE_TYPE::LCHILD];

		 while (pPredecessor->ArrNode[(int)NODE_TYPE::RCHILD])
		 {
			 pPredecessor = pPredecessor->ArrNode[(int)NODE_TYPE::RCHILD];
		 }
	 }

	 //2.왼쪽 자식이 없으면 부모로 부터 오른쪽 자식 일때 까지 위로 올라감 
	 //그때 부모가 선행자 
	 else
	 {
		 pPredecessor = _pNode;

		 while (pPredecessor != nullptr)
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
	 return _pNode->ArrNode[(int)NODE_TYPE::PARENT];;
 }

//반환타입이 본인 타입 이너클래스면 typename 적어줘야됨
template<typename T1, typename T2>
inline typename CBST<T1,T2>::iterator CBST<T1, T2>::begin()
{
	//바이너리 탐색 이진트리에서는 중위순회가 가장중요하고 그곳이 첫번째가 될 것이다.
	FBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->ArrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->ArrNode[(int)NODE_TYPE::LCHILD];
	}
	return iterator(this,pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	return iterator(this,nullptr);
}

template<typename T1, typename T2>
 typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{



	 FBSTNode<T1, T2>* pNode = m_pRoot;
	 NODE_TYPE nodeType = NODE_TYPE::START;

	
	 while (true)
	 {
		//오른쪽
		 if (pNode->pair.first < _find)
		 {
			 nodeType = NODE_TYPE::RCHILD;

		 }
		 //왼쪽
		 else if (pNode->pair.first > _find)
		 {
			 nodeType = NODE_TYPE::LCHILD;
		 }
		 //같다
		 else
		 {	
			 break;
			 
		 }

		 //찾지 못함
		 if (nullptr == pNode->ArrNode[(int)nodeType])
		 {
			 pNode = nullptr;
			 break;
			 

		 }
		 //더찾기
		 else
		 {
			 pNode = pNode->ArrNode[(int)nodeType];

		 }

	 }

	 return iterator(this, pNode);


	
}
