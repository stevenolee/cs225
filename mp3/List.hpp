/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */


/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
#include <iostream>
using namespace std;

template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(tail_->next);
}

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <typename T>
List<T>::~List() {
  /// @todo Graded in MP3.1
	_destroy();
	length_ = 0;
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
// check if already empty
	if (head_ == NULL){
		return;
	}
// check if only head node
	ListNode* current = head_;
	if (head_->next == NULL){
		delete head_;
		head_ = NULL;
		return;
	}
// if multiple nodes
	current = current->next;
	ListNode* previous = current->prev;
	while (current -> next != NULL){
		delete previous;
		previous = NULL;
		current = current->next;
		previous = current->prev;
		length_--;
	}
// for the last case
previous = current->prev;
delete previous;
previous = NULL;
delete tail_;
tail_ = NULL;
}

/*
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
	ListNode* newNode = new ListNode(ndata);
// check if the list is already empty
	if (head_ == NULL){
		head_ = newNode;
		tail_ = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
		length_++;
		return;
	}
	newNode->next = head_;
	newNode->prev = NULL;
	head_->prev = newNode;
	head_ = newNode;
	length_++;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
// check if the list is empty
	ListNode* newNode = new ListNode(ndata);
	if (tail_ == NULL){
		head_ = newNode;
		tail_ = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
		length_++;
		return;
	}
	newNode->next = NULL;
	newNode->prev = tail_;
	tail_->next = newNode;
	tail_ =  newNode;
	length_++;	
}

/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.1
bool wasHead = false;
bool wasTail = false;

	if (startPoint == head_){
		wasHead = true;
	}
	if (endPoint == tail_){
		wasTail = true;
	}
// check if the interval exists?
	ListNode* current = endPoint;
	ListNode* previous = endPoint;
	ListNode* savedBefore = startPoint->prev;
	ListNode* saved = endPoint->next;
// reverse nodes
	while (current != startPoint){
// if it is the first case
		if (current == previous){
			current->next = current->prev;
			current->prev = startPoint->prev;
			current = current->next;
		} else {
			current->next = current->prev;
			current->prev = previous;
			current = current->next;
			previous = previous->next;
		}
	}
// last case
/*	if (saved == NULL){
	tail_ = current;
	}*/
	current->next = saved;
	current->prev = previous;

	if (wasHead && wasTail){
//		head_ = endPoint;
//		startPoint->next = saved;
		ListNode* temp = startPoint;
		startPoint = endPoint;
		endPoint = temp;
		head_ = startPoint;
		tail_ = endPoint;
		return;
	}

	if (!wasHead){
		savedBefore->next = endPoint;
		endPoint->prev = savedBefore;
	} else {
		head_ = endPoint;
		saved->prev = startPoint;
//		endPoint->prev = head_;
	}
	if (!wasTail){
		startPoint->next = saved;
		saved->prev = startPoint;
	} else {
		startPoint->next = saved;
	}

// switch start and endpoint	
	ListNode* temp = startPoint;
	startPoint = endPoint;
	endPoint = temp;
	if (wasHead){
		head_ = startPoint;
	}
	if (wasTail){
		tail_ = endPoint;
	}
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.1
// return reverse() if n is >= length of list
	if (n >= length_){
		reverse();
		return;
	}
	ListNode* first = head_;
	ListNode* last = head_;
	int len = length_ - n;
	while (len >= 0){
		for (int i = 0; i < (n - 1); i++){
			if (last->next == NULL){
				break;
			}
			last = last->next;
		}
		reverse(first, last);
		if (len == 0){
			return;
		}

		first = last->next;
		last = first;
		len = len - n;
	}
// if there are still things to reverse with length < n
		if (first == tail_){
			return;
		} 
		reverse(first, tail_);
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
	ListNode* prev = head_;
	ListNode* current = head_;
	bool alt = true;
	while (current->next != tail_){
		if (alt){
			current = current->next;
			prev = current->prev;
		}
// wrap previous and next node's pointers around current, excluding current from path
		ListNode* origNext = current->next;
		prev->next = current->next;
		current->next->prev = prev;
// change current node pointers		
		ListNode* tailNext = tail_->next;
		tail_->next = current;
		current->prev = tail_;
		current->next = tailNext;
// update pointers
		current = origNext;
		prev = origNext->prev;
		tail_ = tail_->next;
//this->print(cout);
	}


}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <typename T>
List<T> List<T>::split(int splitPoint) {
    if (splitPoint > length_)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode * secondHead = split(head_, splitPoint);

    int oldLength = length_;
    if (secondHead == head_) {
        // current list is going to be empty
        head_ = NULL;
        tail_ = NULL;
        length_ = 0;
    } else {
        // set up current list
        tail_ = head_;
        while (tail_ -> next != NULL)
            tail_ = tail_->next;
        length_ = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head_ = secondHead;
    ret.tail_ = secondHead;
    if (ret.tail_ != NULL) {
        while (ret.tail_->next != NULL)
            ret.tail_ = ret.tail_->next;
    }
    ret.length_ = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.2
	ListNode* newHead = start;
	int split = splitPoint;
// get the new head of the second linked list
	for (int i = 0; i < split; i++){
		newHead = newHead->next;
	}
	ListNode* newHeadPrev = newHead->prev;
	newHeadPrev->next = NULL;
	newHead->prev = NULL;
	return newHead;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
	if (second == NULL){return NULL;}
	ListNode* firstIterator = first;
	ListNode* firstPrev = first;
	ListNode* secondIterator = second;
	ListNode* secondPrev = second;
	while (1){
		while (1){
// if first run
			if (firstPrev == firstIterator){
//cout << "insert front " << endl;
//cout << "secondIterator->data: " << secondIterator->data << endl;
//cout << "firstIterator->data: " << firstIterator->data << endl;
// if inserting at front
				if (secondIterator->data < firstIterator->data){
					second = secondIterator->next;
					if (second != NULL){
					second->prev = NULL;
					}
					secondIterator->next = firstIterator;
					secondIterator->prev = NULL;
					first->prev = secondIterator;
					first = secondIterator;
//					first->length_++;
					break;
				}
			} else if (firstIterator != NULL){
//cout << "insert mid " << endl;
//cout << "secondIterator->data: " << secondIterator->data << endl;
//cout << "firstIterator->data: " << firstIterator->data << endl;
// if inserting in middle
				if (secondIterator->data < firstIterator->data){
					second = secondIterator->next;
					if (second != NULL){
						second->prev = NULL;
					}
					secondIterator->next = firstIterator;
					firstIterator->prev = secondIterator;
					firstPrev->next = secondIterator;
					secondIterator->prev = firstPrev;
//					first->length_++;
					break;
				}
			} else {
//cout << "insert end " << endl;
// inserting at the end
				second = secondIterator->next;
				if (second != NULL){
					second->prev = NULL;
				}
				firstPrev->next = secondIterator;
				secondIterator->prev = firstPrev;
				secondIterator->next = NULL;
//				first->length_++;
				break;
			}
// increment the firstIterator and firstPrev
			firstPrev = firstIterator;
			firstIterator = firstIterator->next;
//cout << "while 1 " << endl;
		}
//cout << "while 2" << endl;
// check if second NULL, reset firstIterator, firstPrev, secondIterator
	if (second == NULL){break;}
/*	secondPrev = second->prev;
	second = second->next;
	second->prev = NULL;
	if (secondPrev != NULL){
		secondPrev->next = NULL;
		secondPrev->prev = NULL;
	}*/
	firstIterator = first;
	firstPrev = firstIterator;
	secondIterator = second;
	}
  return first;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <typename T>
void List<T>::sort() {
    if (empty())
        return;
    head_ = mergesort(head_, length_);
    tail_ = head_;
    while (tail_->next != NULL)
        tail_ = tail_->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
	if (chainLength > 1){
// get endPoint
		ListNode* midPoint = start;
//		int odd = chainLength%2;
		int mid = chainLength / 2;
//		if (odd){mid+=1;}

		ListNode* secondHalf = split(start, mid);
cout << "mid: " << mid << endl;
cout << "start->data: " << start->data << endl;
cout << "secondHalf->data: " << secondHalf->data << endl;
		mergesort(start, mid);
		mergesort(secondHalf, chainLength - mid);
cout << "POST OP start->data: " << start->data << endl;
cout << "POST OP secondHalf->data: " << secondHalf->data << endl;
		merge(start, secondHalf);
	}
	return start;
}
