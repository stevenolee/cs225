/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

// return height of the subtree
template <class K, class V>
int AVLTree<K, V>::getHeight(Node* current){
	if (current == NULL){return -1;}
	if ((current->left == NULL) && (current->right == NULL)){
		return 0;
	}
	if (current->right == NULL){
		return getHeight(current->left) + 1;
	}
	if (current->left == NULL){
		return getHeight(current->right) + 1;
	}

	return max(getHeight(current->left)+1, getHeight(current->right)+1);
}


template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
	Node* stickLeft = root;
	Node* stickMid = stickLeft->right;
	stickLeft->right = stickMid->left;
	stickMid->left = stickLeft;
	root = stickMid;
}


template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
	Node* stickRight = root;
	Node* stickMid = stickRight->left;
cout << "_______________________" << stickMid->key << endl;
	stickRight->left = stickMid->right;
	stickMid->right = stickRight;
	root = stickMid;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
	rotateRight(t->right);
	rotateLeft(t);	
}



template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
cout << "REBALANCING " << subtree->key << endl;
	int heightLeft = getHeight(subtree->left);
	int heightRight = getHeight(subtree->right);
	int balance = heightRight - heightLeft;
	if (balance <= -2){
		if (getHeight(subtree->left->right) - getHeight(subtree->left->left) < 0){
			rotateRight(subtree);
		} else {
			rotateLeftRight(subtree);
		}
	} else if (balance >= 2){
		if (getHeight(subtree->right->right) - getHeight(subtree->right->left) > 0){
			rotateLeft(subtree);
		} else {
			rotateRightLeft(subtree);
		}
	}
	int height = getHeight(subtree);
	subtree->height = height;
//if (subtree->left != NULL){subtree->left->height = getHeight(subtree->left);}	
//if (subtree->right != NULL){subtree->right->height = getHeight(subtree->right);}	
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
// base case
	if (subtree == NULL){
		Node* child = new Node(key, value);
		subtree = child;
		subtree->height = 0;
//cout << "what the fuck did i just insert? key: " << subtree->key << " height: " << subtree->height << endl;
		return;
	}
// recursion
	if (key < subtree->key){
//if (subtree->left != NULL){cout << "THE RECURSION PATH______: " << subtree->key << "->" << subtree->left->key << endl;}
		insert(subtree->left, key, value);
	} else {
//if (subtree->right != NULL){cout << "THE RECURSION PATH______: " << subtree->key << "->" << subtree->right->key << endl;}
		insert(subtree->right, key, value);
	}
//cout << "RECURSION UNFOLDING :O!!!  " << subtree->key << endl;
// rebalance
//cout << "subtree left and right: " << subtree->left << " " << subtree->right << endl;
if (subtree->right != NULL){
//	cout << "subtree->right->key: " << subtree->right->key << endl;
}
	rebalance(subtree);


}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{

    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
		remove(subtree->left, key);
    } else if (key > subtree->key) {
        // your code here
		remove(subtree->right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            // no-child remove 
            // your code here
			delete subtree;
			subtree = NULL;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            // two-child remove 
            // your code here
// find IOP
			Node* IOP = subtree->left;
			while (IOP->right != NULL){
				IOP = IOP->right;
			}
			swap(IOP, subtree);
			remove(root, IOP->key);
        } else {
            // one-child remove 
            // your code here
			Node* del = subtree;
			if (subtree->left != NULL){
				subtree = subtree->left;
			} else {
				subtree = subtree->right;
			}
			delete del;
        }
        // your code here
		rebalance(subtree);
    }
}
