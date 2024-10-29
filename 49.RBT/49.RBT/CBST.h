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
	FPair<T1, T2>		pair;					//data	map������ pair�� �Ҹ���.

	//������尡 �ֱ⶧���� �迭�� ���� �����ϸ� ���� 
	FBSTNode* NodePosition[(int)NODE_POS::START];		//�θ� �ڽĵ��� �����ϴ� ���޸�
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


	//�������
	bool IsLeafNode()
	{
		if (NodePosition[(int)NODE_POS::LCHILD] == nullptr && NodePosition[(int)NODE_POS::RCHILD] == nullptr)
		{
			return true;
		}

		return false;
	}
	bool IsFullNode()	//�ڽ��� �ٰ��� ����
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
	//Default ������
	FBSTNode() :
		pair(),
		NodePosition{},
		m_NodeColor{}
	{

	}

	//�ʱ�ȭ ������
	FBSTNode(const FPair<T1, T2>& _pair, FBSTNode* _pParent, FBSTNode* _pLChild, FBSTNode* _pRChild) :
		pair(_pair),
		NodePosition{ _pParent, _pLChild, _pRChild },
		m_NodeColor(NODE_COLOR::Default)
	{

	}
	//Nil��� ������
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
	int					m_iCount;		//�����Ͱ���


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
		CBST<T1, T2>* m_pBST;		//bst��ü�� �˰��ձ� 
		FBSTNode<T1, T2>* m_pNode;	///Ư�� ��带 �˱� 
	

			//���ͷ����� �񱳿�����
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
			//end iteartor üũ
			assert(m_pNode);

			return m_pNode->pair;
		}

		const FPair<T1, T2>* operator->()
		{
			//end iteartor üũ
			assert(m_pNode);

			return &m_pNode->pair;
		}

		

		//++ ������ȸ 
		iterator& operator ++()
		{
			//�����ļ��ڸ� ã�´�
			//m_pBST->GetInorderSuccessor(m_pNode);
		
			
				m_pNode = m_pBST->GetInOrderSuccessor(m_pNode);
				return *this;

		
			
			
		
		}

		//++ ������ȸ 
		iterator& operator --()
		{
			//���������ڸ� ã�´�
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


	//insert�� �⺻������ redĮ�� �־��ش�
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
		//2��°�� �ö� root ��� �ȿ� pair.first���� �񱳸� �ؾߵɰŴ� 
		//root���� �����ؼ� leaf��尡 �ɶ����� ���ϸ鼭 �������� �ɰ��̴� �ᱹ �ݺ��� ���...
		
		FBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_POS nodeType = NODE_POS::START;

		//root ���� new�� Ŀ�� ���࿡ ���������� ��� �������ٰ�
		//new�� �̵̹���մ� �����Ͱ� �������� ��ؾߵǳ�?
		//map������쿡�� �ߺ��� ������� �ʴ´� �׷��� �׻� find�Լ��� ����ؼ� �̹� ������ key���� ����ó���� ���� ����ߵȴ�.
		// �ٵ� multmap�� ������ϰ� ���ο���� ���� ��� �߰��ȴ� �ٵ� ���࿡ �̷������� ��������� ����Ž��Ʈ���� ȿ���� ��������.

		while (true)
		{


			//������
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_POS::RCHILD;

			}

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				nodeType = NODE_POS::LCHILD;
			}

			//����
			else
			{
				return false;
			}

			//�����
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

		//RBT������ leafNode�� Nil��� 
		if (pNewNode->IsLeafNode())
		{
			pNewNode->NodePosition[(int)NODE_POS::LCHILD] = m_pNil;
			pNewNode->NodePosition[(int)NODE_POS::RCHILD] = m_pNil;
		}


		//case�� ���� �ش��� �ȴٸ� Rot
		// red�� �ι��������� �Ͼ��
		//�ڰ����� �Լ��� �ߵ���Ų�� 

		//RBT ���� ����
		//1.���� red �Ǵ� black�̿��� �ȴ�.
		//2.root ���� black �̴�.
		//3.��� �������(NIL)�� ���̴�.
		//4.���尡 ���������� �Ͼ���� ����.
		//�������� �ڽľ����� ������ ���̿��� �ȴ�.
		//5.� ���κ��� ���۵Ǿ� �׿� ���� ���� ������忡 ���� �ϴ°�� ����ο��� �ڱ��ڽ��� �����ϰ�
		//���Ǽ��� �׻󰰴�.



		//RED �ΰ��� 4���Ӽ����� 
		if (pNewNode->NodePosition[(int)NODE_POS::PARENT]->m_NodeColor == NODE_COLOR::RED)
		{
			pNewNode =CASE(pNewNode);
		}

		


		

	}


	//��� root���� �ٽ� black���� ������ �ش�.
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

		std::cout << "Case �߻�!" << std::endl;

		if (_pNewNode == nullptr) return nullptr;

		//ȸ���Ҷ� case���� ����
		int iCase = 0;

		FBSTNode<T1, T2>* TempNode = nullptr;

		FBSTNode<T1, T2>* pNewNodeGradParent = pNewNodeGradParent = GetGrandParent(_pNewNode);
		FBSTNode<T1, T2>* pNewUncle = pNewUncle = GetUncle(_pNewNode);
		FBSTNode<T1, T2>* pNewNodeParent = pNewNodeParent = GetParent(_pNewNode);

		//�ܹ��� ������ üũ������
		NODE_POS CheckPosition = NODE_POS::START;
		NODE_POS CheckPosition2 = NODE_POS::START;
	

		
		if (pNewNodeParent == nullptr || pNewNodeGradParent == nullptr)
		{
			return _pNewNode;
		}
		
		//NewNode�� NewNode�� �θ��� ���� ���� ���ؼ� ����������� ã�Ƴ���

		CheckPosition = ChangeNodePos(_pNewNode, CheckPosition);
		CheckPosition2 = ChangeNodePos(pNewNodeParent, CheckPosition2);

		if (CheckPosition == NODE_POS::START || CheckPosition2 == NODE_POS::START)
		{
			return _pNewNode;
		}
				

		//CASE�������� �ͼ� �ٽ� ������ �ִ��� CASE3üũ�� ��������� ����� �ȴ�.

		//�θ�� ������ �����ΰ��
		// �θ�� ������ black�� �����ϰ� �Ҿƹ����� red�κ����ϰ� �Ҿƹ������� �ݵ�� Ȯ���Ѵ� 
		//CASE 1 
		if (pNewNodeParent->m_NodeColor == NODE_COLOR::RED && pNewUncle->m_NodeColor == NODE_COLOR::RED)
		{

			CASEONE(_pNewNode, CheckPosition);
			//�Ҿƹ������� �ٽ� Ȯ���� �Ѵ� .

			if (m_pRoot->m_NodeColor != NODE_COLOR::BLACK)
			{
				m_pRoot->m_NodeColor = NODE_COLOR::BLACK;
			}

	

			//�Ҿƹ������� �ݵ�� Ȯ���Ѵ�.
			return CASE(pNewNodeGradParent);

		} 
		 
		//������ 
		//CASE 2 ������ �ٸ��� ������ �������� ���
		else if (CheckPosition != CheckPosition2 && pNewUncle->m_NodeColor == NODE_COLOR::BLACK)
		{

			CASETWO(_pNewNode, CheckPosition);
			//�θ� �������� �ش�������� ȸ���� �Ѵ� 
			iCase = 2;
			_pNewNode = Rotation(_pNewNode, CheckPosition2, iCase);

			//ȸ���� �Ͽ��⶧���� ���⵵ ������ �Ǿ����Ŵ� �׷��� ������ 
			// Post�� �ٽ� üũ 
		
			//������ ȸ���ϰ� 3������ ��������ߵȴ�.

		

			return CASE(_pNewNode);
		}

		//�ܹ���
		//CASE 3 ������ ���� ������ ���ΰ�� 
		else if (CheckPosition == CheckPosition2 && pNewUncle->m_NodeColor == NODE_COLOR::BLACK)
		{
			//std::cout << "�ܹ��� �Դϴ� case3�� �߻� �Ͽ����ϴ�" << std::endl;

			CASETHREE(_pNewNode, CheckPosition);

			//GetGrandParent(_pNewNode);
			iCase = 3;
			//�Ҿƹ��� �������� ȸ���� ���ش�.

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

	//��������� �ѹ��� üũ�� ���ش�.
	
	


	
	//CASE�� ���࿡ �߻����� �ʴ´ٸ� ���� ȸ���� ���൵ �ȴ�.
	
	


	
}

template<typename T1, typename T2>
inline typename FBSTNode<T1, T2>* CBST<T1, T2>::CASEONE(FBSTNode<T1, T2>* _pNewNode,NODE_POS _pos)
{
	//���� �θ� ����Ȯ��

	FBSTNode<T1, T2>* pNewNodeParent = GetParent(_pNewNode);
	FBSTNode<T1, T2>* pNewGradParent = GetGrandParent(_pNewNode);
	FBSTNode<T1, T2>* pNewUncle = GetUncle(_pNewNode);

	pNewNodeParent->m_NodeColor = NODE_COLOR::BLACK;
	pNewUncle->m_NodeColor = NODE_COLOR::BLACK;
	pNewGradParent->m_NodeColor = NODE_COLOR::RED;
	
	//�Ҿƹ������� �ٽ� �����Ѵ�

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

	//ȸ��
	//1.�θ�� �Ҿƹ��� ���� ���� 
	tempColor = pNewNodeParent->m_NodeColor;
	pNewNodeParent->m_NodeColor = pNewGradParent->m_NodeColor;
	pNewGradParent->m_NodeColor = tempColor;

	

	//2.�Ҿƹ��� �������� ȸ��


	return _pNewNode;
}

template<typename T1, typename T2>
 typename FBSTNode<T1, T2>* CBST<T1, T2>::Rotation(FBSTNode<T1, T2>* _pNewNode, NODE_POS _pos,int _iNumer)
{
	 //� ���̽��� ���� ȸ���� ���� �޶�����
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
	
			   //1.�θ� ������ �ӽó��
			   //2.�θ��� �ݴ� �����尡 �θ𰡵ȴ�.
			   //3.���ο� �θ��� ���� �������ʿ� �����θ� ��������ش�.
		 //�θ� ����
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
		 //�θ� ������
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

		

		 //�Ҿƹ��� �������� ȸ���Ѵ�.
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
		 //�θ� ������
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
		 std::cout << "��� ���̽����� �ش��� ���� �ʽ��ϴ�" << std::endl;
	 }
	
	 _pNewNode = TempNode;
	


	return _pNewNode;
}



//���� �ļ���
template<typename T1, typename T2>
FBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pSuccesor = nullptr;

	if (m_pNil == _pNode)
	{
		return pSuccesor;
	}

	//1.������ �ڽ��� �ִ� ��� ������ �ڽ����ΰ���, ���� �ڽ��� ������ ���� ������ 
	if (_pNode->NodePosition[(int)NODE_POS::RCHILD] != m_pNil)
	{
		pSuccesor = _pNode->NodePosition[(int)NODE_POS::RCHILD];

		while (pSuccesor->NodePosition[(int)NODE_POS::LCHILD] != m_pNil)
		{
			pSuccesor = pSuccesor->NodePosition[(int)NODE_POS::LCHILD];
		}
	}

	//2.������ �ڽ��� ������ �θ�� ���� ���� �ڽ� �϶� ���� ���� �ö� 
	//�׶� �θ� �ļ��� 
	else
	{
		pSuccesor = _pNode;

		while (pSuccesor != m_pNil)	//true�� �����ʴ����� ���ѷ����������մ°� �����ϱ� ���ؼ�
		{

			if (pSuccesor->IsRoot())
			{
				return nullptr;
			}
			else
			{
				// ���� ��尡 �θ��� ���� �ڽ��� ��� �θ� �ļ���
				if (pSuccesor->IsLeftChild())
				{
					//�θ��ļ���
					pSuccesor = GetParent(pSuccesor);
					break;
				}
				else
				{
					// ������ �ڽ��� ���, �θ�� ��� �ö�
					pSuccesor = GetParent(pSuccesor);
				}
			}
		}




	}

	return pSuccesor;
}

//���� ������
template<typename T1, typename T2>
inline FBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(FBSTNode<T1, T2>* _pNode)
{
	FBSTNode<T1, T2>* pPredecessor = nullptr;

	if (m_pNil == _pNode)
	{
		return pPredecessor;
	}

	//1.���� �ڽ��� �ִ� ��� ���� �ڽ����ΰ���, ������ �ڽ��� ������ ���� ������ 
	if (_pNode->NodePosition[(int)NODE_POS::LCHILD] != m_pNil)
	{
		pPredecessor = _pNode->NodePosition[(int)NODE_POS::LCHILD];

		while (pPredecessor->NodePosition[(int)NODE_POS::RCHILD] != m_pNil)
		{
			pPredecessor = pPredecessor->NodePosition[(int)NODE_POS::RCHILD];
		}
	}

	//2.���� �ڽ��� ������ �θ�� ���� ������ �ڽ� �϶� ���� ���� �ö� 
	//�׶� �θ� ������ 
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
				//�������� üũ
				if (pPredecessor->IsRightChild())
				{
					//�θ�����
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
	 
	 //�ܹ������� ����������
	 if (_pNode->IsLeftChild())
	 {
		 std::cout << "�ڽİ� �θ��� ������ ����" << std::endl;
		 _pos = NODE_POS::LCHILD;
	 }

	 else if (_pNode->IsRightChild())
	 {
		 std::cout << "�ڽİ� �θ��� �������� ����" << std::endl;
		 _pos = NODE_POS::RCHILD;
	 }
	 else
	 {
		 std::cout << "�ٸ���" << std::endl;
	 }


	return _pos;
}





//��ȯŸ���� ���� Ÿ�� �̳�Ŭ������ typename ������ߵ�
template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	//���̳ʸ� Ž�� ����Ʈ�������� ������ȸ�� �����߿��ϰ� �װ��� ù��°�� �� ���̴�.
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
		//������
		if (pNode->pair.first < _find)
		{
			nodeType = NODE_POS::RCHILD;

		}
		//����
		else if (pNode->pair.first > _find)
		{
			nodeType = NODE_POS::LCHILD;
		}
		//����
		else
		{
			break;

		}

		//ã�� ����
		if (nullptr == pNode->NodePosition[(int)nodeType])
		{
			pNode = nullptr;
			break;


		}
		//��ã��
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




	//���� �ļ���, ���� �����ڴ� �ڽ����ϳ��ų� ���°�� �ۿ� ���� 

	assert(_iter.m_pBST == this);

	FBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode);

	////1.������ ��尡 �ܸ������ ���
	//if (_iter.m_pNode->IsLeafNode())
	//{
	   // //�θ� ���� �Ǵ� �ڽ��� ����� �ּҸ� null�� ����� �ش�.
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


	//insert�� �⺻������ redĮ�� �־��ش�
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
		//2��°�� �ö� root ��� �ȿ� pair.first���� �񱳸� �ؾߵɰŴ� 
		//root���� �����ؼ� leaf��尡 �ɶ����� ���ϸ鼭 �������� �ɰ��̴� �ᱹ �ݺ��� ���...

		FBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_POS nodeType = NODE_POS::START;

		//root ���� new�� Ŀ�� ���࿡ ���������� ��� �������ٰ�
		//new�� �̵̹���մ� �����Ͱ� �������� ��ؾߵǳ�?
		//map������쿡�� �ߺ��� ������� �ʴ´� �׷��� �׻� find�Լ��� ����ؼ� �̹� ������ key���� ����ó���� ���� ����ߵȴ�.
		// �ٵ� multmap�� ������ϰ� ���ο���� ���� ��� �߰��ȴ� �ٵ� ���࿡ �̷������� ��������� ����Ž��Ʈ���� ȿ���� ��������.

		while (true)
		{


			//������
			if (pNode->pair.first < pNewNode->pair.first)
			{
				nodeType = NODE_POS::RCHILD;

			}

			else if (pNode->pair.first > pNewNode->pair.first)
			{
				nodeType = NODE_POS::LCHILD;
			}

			//����
			else
			{
				return  iterator(nullptr, nullptr);
			}

			//�����
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

	//1.������ ��尡 �ܸ������ ���
	if (_pDelNode->IsLeafNode())
	{
		pSuccessor = GetInOrderSuccessor(_pDelNode);


		if (_pDelNode == m_pRoot)
		{
			m_pRoot = nullptr;

		}
		else
		{
			//�θ� ���� �Ǵ� �ڽ��� ����� �ּҸ� null�� ����� �ش�.
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
	//3.������ ��尡 2���� �ڽ��� ������� (���� ������ ,���� �ļ��ڰ� �;ߵȴ� �߿�)
	else if (_pDelNode->IsFullNode())
	{

		//������ �� �ڸ��� ���� �ļ����� ���� ���� ��Ų��.
		_pDelNode->pair = pSuccessor->pair;


		//���� �ļ��� ��带 ���� �Ѵ�.
		DeleteNode(pSuccessor);


		//������ ��尡 �����ļ��ڰ� �ȴ�.
		pSuccessor = _pDelNode;

	}
	//2.������ ��尡 �ڽĳ�带 �Ѱ� ������� (�ڽ��� �θ�� �������ش� )
	else
	{
		pSuccessor = GetInOrderSuccessor(_pDelNode); //�ļ��ڳ�� �̸�ã��

		NODE_POS nodetype = NODE_POS::LCHILD;
		if (_pDelNode->NodePosition[(int)NODE_POS::RCHILD])
		{
			nodetype = NODE_POS::RCHILD;
		}

		//������ ��尡 ��Ʈ���
		if (_pDelNode == m_pRoot)
		{
			//���� �ڽ����� �����U �ڽ����� �˾ƾߵ� 
			m_pRoot = _pDelNode->NodePosition[(int)nodetype];
			_pDelNode->NodePosition[(int)nodetype]->ArrNode[(int)NODE_POS::PARENT] = nullptr;
		}
		else
		{
			//������ ����� �θ�� ������ ����� �ڽ��� ����
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

