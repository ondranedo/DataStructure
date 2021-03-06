#pragma once

using namespace ds;

template <class T>
LinkedList<T>::LinkedList() {
	m_size = 0;
	m_head = nullptr;
	m_tail = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
	this->clear();
}





template<class T>
T LinkedList<T>::popHead()
{
	if (m_head == nullptr) { return m_head->data; }
	T rval = m_head->data;
	node* del = m_head;

	if (m_head->next != nullptr) 
	{
		m_head = m_head->next;
		m_head->prev = nullptr;
	}
	else
	{
		m_head = nullptr;
		m_tail = nullptr;
	}
	
	delete del;
	m_size--;
	return rval;
}

template<class T>
T LinkedList<T>::popTail()
{
	if (m_head == nullptr) { return m_head->data; }
	T rval = m_tail->data;
	node* del = m_tail;

	m_tail = m_tail->prev;
	m_tail->next = nullptr;

	delete del;
	m_size--;
	return rval;
}

template<class T>
T LinkedList<T>::popIndex(size_t index)
{
	//kontroly
	if (m_head == nullptr) { return m_head->data;}
	if (index <= 1) { return popHead(); }
	if (index >= m_size) { return popTail(); }


	//hledani node pred indexovanou
	size_t counter = NULL;
	node* bef = m_tail;			//bef = before

	///horni polovina
	if (index > m_size / 2)
	{
		counter = m_size;
		bef = m_tail;
		while (counter > index - 1)
		{
			bef = bef->prev;
			counter--;
		}
	}

	///spodni polovina
	if (index <= m_size / 2)
	{
		counter = 1;
		bef = m_head;
		while (counter < index - 1)
		{
			bef = bef->next;
			counter++;
		}
	}
	node* del = bef->next;
	T rval = del->data;

	del->next->prev = bef;
	bef->next = del->next;

	m_size--;
	delete del;
	return rval;
}





template <class T>
void LinkedList<T>::pushHead(T data) {
	if (m_head == nullptr)
	{
		m_head = new node;
		m_head->next = nullptr;
		m_head->prev = nullptr;
		m_head->data = data;
		m_tail = m_head;
		m_size++;
		return;
	}

	node* tmp = new node;
	tmp->data = data;
	tmp->next = m_head;
	tmp->prev = nullptr;
	m_head->prev = tmp;
	m_head = tmp;
	m_size++;
	return;
}

template <class T>
void LinkedList<T>::pushTail(T data) {
	if (m_head == nullptr)
	{
		m_head = new node;
		m_head->next = nullptr;
		m_head->prev = nullptr;
		m_head->data = data;
		m_tail = m_head;
		m_size++;
		return;
	}

	node* tmp = new node;
	tmp->data = data;
	tmp->next = nullptr;
	tmp->prev = m_tail;
	m_tail->next = tmp;
	m_tail = tmp;
	m_size++;
	return;
}

template<class T>
void LinkedList<T>::pushIndex(size_t index, T data)
{
	//kontroly
	if (m_head == nullptr)
	{
		m_head = new node;
		m_head->next = nullptr;
		m_head->prev = nullptr;
		m_head->data = data;
		m_tail = m_head;
		m_size++;
		return;
	}
	if (index <= 1) { pushHead(data); return; }
	if (index > m_size) { pushTail(data); return; }
	if (index == m_size) {
		node* newn = new node;
		newn->data = data;
		newn->next = m_tail;
		newn->prev = m_tail->prev;;

		m_tail->prev->next = newn;
		m_tail->prev = newn;
		m_size++;
		return;
	}

	//hledani node pred indexovanou
	size_t counter = NULL;
	node* bef = m_tail;			//bef = before

	///horni polovina
	if (index > m_size / 2)
	{
		counter = m_size;
		bef = m_tail;
		while (counter > index - 1)
		{
			bef = bef->prev;
			counter--;
		}
	}

	///spodni polovina
	if (index <= m_size / 2)
	{
		counter = 1;
		bef = m_head;
		while (counter < index - 1)
		{
			bef = bef->next;
			counter++;
		}
	}
	node* newn = new node; //nova node

	//nastaveni nov. linku
	bef->next->prev = newn;
	newn->data = data;
	newn->next = bef->next;
	newn->prev = bef;
	bef->next = newn;
	newn->next->prev = newn;

	m_size++;
	return;
}





template<class T>
T LinkedList<T>::search(size_t index) const
{
	if (index <= 0) { return m_null; }
	if (index > m_size) { return m_null; }
	if (m_head == nullptr) { return m_null; }

	//hledani node pred indexovanou
	size_t counter = NULL;
	node* cur = m_tail;			//bef = before

	///horni polovina
	if (index > m_size / 2)
	{
		counter = m_size;
		cur = m_tail;
		while (counter > index)
		{
			cur = cur->prev;
			counter--;
		}
	}

	///spodni polovina
	if (index <= m_size / 2)
	{
		counter = 1;
		cur = m_head;
		while (counter < index)
		{
			cur = cur->next;
			counter++;
		}
	}

	return cur->data;
}

template<class T>
void LinkedList<T>::clear()
{
	if (m_head == nullptr) { return; }

	node* prev = nullptr;

	for (size_t i = 0; i < m_size; i++)
	{
		prev = m_head;
		m_head = m_head->next;
		delete prev;
	}

	m_tail = nullptr;
	m_size = 0;
	return;
}

template<class T>
size_t LinkedList<T>::size() const
{
	return m_size;
}
