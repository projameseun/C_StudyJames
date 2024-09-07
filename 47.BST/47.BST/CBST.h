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
	T1		first;		//Ű��
	T1		second;		//���
};


//make pair ����
template<typename T1, typename T2>
FPair<T1, T2> make_mypair(const T1& _first, const T2& _second)
{
	return FPair<T1, T2>{_first, _second};
}

template<typename T1, typename T2>
struct FBSTNode
{
	FPair<T1,T2>		pair;					//data	map������ pair�� �Ҹ���.

	//������尡 �ֱ⶧���� �迭�� ���� �����ϸ� ���� 
	FBSTNode*			ArrNode[(int)NODE_TYPE::START];		//�θ� �ڽĵ��� �����ϴ� ���޸�
	//FBSTNode*			pParent;		//�θ���
	//FBSTNode*			pLeftChild;		//�����ڽĳ��
	//FBSTNode*			pRightChild;		//�������ڽ� ���

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
	int					m_iCount;		//�����Ͱ���

public:
	CBST() :
		m_pRoot(nullptr),
		m_iCount(0)
	{

	}

public:
	bool insert(const FPair<T1,T2>& _pair);

	class iterator;
public:
	iterator begin();
	iterator end();
	iterator find(const T1& _find);

public:
	class iterator
	{
	private:
		CBST<T1, T2>*		m_pBST;		//bst��ü�� �˰��ձ� 
		FBSTNode<T1, T2>*	m_pNode;	///Ư�� ��带 �˱� 

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
		//2��°�� �ö� root ��� �ȿ� pair.first���� �񱳸� �ؾߵɰŴ� 
		//root���� �����ؼ� leaf��尡 �ɶ����� ���ϸ鼭 �������� �ɰ��̴� �ᱹ �ݺ��� ���...

		FBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE nodeType = NODE_TYPE::START;

		//root ���� new�� Ŀ�� ���࿡ ���������� ��� �������ٰ�
		//new�� �̵̹���մ� �����Ͱ� �������� ��ؾߵǳ�?
		//map������쿡�� �ߺ��� ������� �ʴ´� �׷��� �׻� find�Լ��� ����ؼ� �̹� ������ key���� ����ó���� ���� ����ߵȴ�.
		// �ٵ� multmap�� ������ϰ� ���ο���� ���� ��� �߰��ȴ� �ٵ� ���࿡ �̷������� ��������� ����Ž��Ʈ���� ȿ���� ��������.

		while (true)
		{
			
#pragma region FIRST
			////������
			//if (pNode->pair.first < pNewNode->pair.first)
			//{
			//	nodeType = NODE_TYPE::RCHILD;

			//	//�����
			//	if (nullptr == pNode->pRightChild)
			//	{
			//		pNode->pRightChild = pNewNode;
			//		pNewNode->pParent = pNode;
			//		break;

			//	}
			//	//node�� �ٽ� �����ض� 
			//	else
			//	{
			//		pNode = pNode->pRightChild;
			//	}

			//}
			////�ަU
			//else if (pNode->pair.first > pNewNode->pair.first)
			//{

			//	nodeType = NODE_TYPE::LCHILD;
			//	//�����
			//	if (nullptr == pNode->pLeftChild)
			//	{
			//		pNode->pLeftChild = pNewNode;
			//		pNewNode->pParent = pNode;
			//		break;

			//	}
			//	//node�� �ٽ� �����ض� 
			//	else
			//	{
			//		pNode = pNode->pLeftChild;
			//	}
			//}
			////����
			//else
			//{
			//	return false;
			//}
#pragma endregion

			//������
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_TYPE::RCHILD;

			}

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				nodeType = NODE_TYPE::LCHILD;
			}
			
				//����
			else
			{
				return false;
			}
			
			//�����
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

//��ȯŸ���� ���� Ÿ�� �̳�Ŭ������ typename ������ߵ�
template<typename T1, typename T2>
inline typename CBST<T1,T2>::iterator CBST<T1, T2>::begin()
{
	//���̳ʸ� Ž�� ����Ʈ�������� ������ȸ�� �����߿��ϰ� �װ��� ù��°�� �� ���̴�.
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
		//������
		 if (pNode->pair.first < _find)
		 {
			 nodeType = NODE_TYPE::RCHILD;

		 }
		 //����
		 else if (pNode->pair.first > _find)
		 {
			 nodeType = NODE_TYPE::LCHILD;
		 }
		 //����
		 else
		 {	
			 break;
			 
		 }

		 //ã�� ����
		 if (nullptr == pNode->ArrNode[(int)nodeType])
		 {
			 pNode = nullptr;
			 break;
			 

		 }
		 //��ã��
		 else
		 {
			 pNode = pNode->ArrNode[(int)nodeType];

		 }

	 }

	 return iterator(this, pNode);


	
}
