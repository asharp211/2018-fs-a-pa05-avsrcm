//circular double linked list
void get_identity(std::string my_id[])
{
    my_id[0] = "avsrcm";
    my_id[1] = "12449123";
}

template <typename T>
MyList<T>::MyList()
{
    m_sentinel = new Node<T>(NULL, nullptr, nullptr);
	m_sentinel->m_next = m_sentinel;
	m_sentinel->m_prev = m_sentinel;

    m_size = 0;
}

template <typename T>
MyList<T>::~MyList()
{
    Node<T> *nodePtr = m_sentinel;
    Node<T> *deleteNode = nodePtr;
    nodePtr = nodePtr->m_next;

    delete deleteNode;
}

template <typename T>
MyList<T> & MyList<T>::operator=(const MyList<T> &source)
{
    if(m_sentinel->m_next != m_sentinel)
    {
       Node<T> *temp = m_sentinel->m_next->m_next;
       delete temp;
    }
/*
m_sentinel = new Node<T>(NULL, nullptr, nullptr);

	m_sentinel->m_next = m_sentinel;
	m_sentinel->m_prev = m_sentinel;

    int m_size = 0;
*/
    Node<T> *temp = source.m_sentinel->m_next;

    for(int j = 0; j < source.m_size; j++)
    {
        push_back(temp->m_element);
        temp = temp->m_next;
    }

    return *this;
}

template <typename T>
MyList<T>::MyList(const MyList<T> &source)
{
	Node<T> *Temp;
	m_sentinel = Temp(source.m_sentinel);

	delete Temp;
}

template <typename T>
T & MyList<T>::front()
{
    return m_sentinel->m_next->m_element;
}

template <typename T>
T & MyList<T>::back()
{
    return m_sentinel->m_prev->m_element;
}

template <typename T>
void MyList<T>::assign(int count, const T &value)
{
    while(m_sentinel >= m_size)
    {
        *m_sentinel = value;
        m_sentinel++;
        count--;
    }
}
  // Default list size of 0, with one sentinel node, as above.
template<typename T>
void MyList<T>::clear()
{
	if(m_sentinel->m_next != nullptr)
    {
        m_size = 0;

        delete m_sentinel;
        m_sentinel = nullptr;
    }

}
//Insert the front element
template<typename T>
void MyList<T>::push_front(const T &x)
{
	Node<T> *fNode = m_sentinel->m_next;

    Node<T> *fPtr = new Node<T>(x, m_sentinel->m_next,m_sentinel);

    fNode->m_prev = fPtr;

    m_sentinel->m_next = fPtr;

    m_size++;
}
//Insert the last element
template<typename T>
void MyList<T>::push_back(const T &x)
{
    Node<T> *bNode = m_sentinel->m_prev;

	Node<T> *pPtr = new Node<T>(x, m_sentinel->m_prev, m_sentinel);

    bNode->m_next = pPtr;

    m_sentinel->m_prev = pPtr;

    m_size++;
}

//Removes the last element
template<typename T>
void MyList<T>::pop_back()
{
    if(!empty())
	{
		m_sentinel->m_prev->m_prev->m_next = m_sentinel;
		m_sentinel->m_prev = m_sentinel->m_prev->m_prev;
	}

    m_size--;
}

//Removes the front element
template <typename T>
void MyList<T>::pop_front()
{
    if(!empty())
    {
        m_sentinel->m_next->m_next->m_prev = m_sentinel;
		m_sentinel->m_next = m_sentinel->m_next->m_next;
    }

    m_size--;
}

	// Simplified version that only takes one int position.
	// Inserts before element at position i.
	// Not exactly like std::
template<typename T>
void MyList<T>::insert(int i, const T &x)
{
    Node<T> *iPtr = m_sentinel;

    for (int j = 0; j < i; j++)
    {
		iPtr = iPtr->m_next;
    }

	Node<T> *temp = new Node<T>(x,m_sentinel->m_prev,m_sentinel);
    temp->m_next->m_prev = temp;
	temp->m_prev->m_next = temp;

    m_size++;
}

template<typename T>
void MyList<T>::remove(T value)
{
    value->m_next->m_prev = value->m_next;
    value->m_prev->m_next = value->m_prev;
    delete value;
    m_size--;
}

// Removes element at position i.
template<typename T>
void MyList<T>::erase(int i)
{
	if(empty())
	{
        return;
    }

	if(m_size == 1)
	{
		m_sentinel->m_next = nullptr;
		m_sentinel->m_prev = nullptr;
		m_size = 1;
	}

	Node<T> *deletePtr;

	for (int j = m_size; j < i; j++)
	{
		deletePtr->m_sentinel->m_next = deletePtr->m_next;
		deletePtr->m_sentinel->m_prev = deletePtr->m_prev;

		m_size--;
	}
}

template<typename T>
void MyList<T>::reverse()
{
	Node<T> *temp;

	m_sentinel = m_sentinel->m_next;

    temp = m_sentinel->m_prev;

    m_sentinel->m_prev = m_sentinel->m_next;

    m_sentinel->m_next = temp;

    m_sentinel = m_sentinel->m_prev;
}

template<typename T>
bool MyList<T>::empty()
{
	if(m_sentinel->m_next == m_sentinel && m_sentinel->m_prev == m_sentinel)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
int MyList<T>::size()
{
	return m_size;
}
