#pragma once

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
			

			//오른쪽
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_TYPE::RCHILD;

				//여기야
				if (nullptr == pNode->pRightChild)
				{
					pNode->pRightChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
					
				}
				//node를 다시 갱신해라 
				else
				{
					pNode = pNode->pRightChild;
				}

			}
			//왼쪾
			else if (pNode->pair.first > pNewNode->pair.first)
			{

				nodeType = NODE_TYPE::LCHILD;
				//여기야
				if (nullptr == pNode->pLeftChild)
				{
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
					break;

				}
				//node를 다시 갱신해라 
				else
				{
					pNode = pNode->pLeftChild;
				}
			}
			//같다
			else
			{
				return false;
			}

		}


		
	}

	++m_iCount;
	return true;
}
