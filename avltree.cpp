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

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    Node* newNode = t->right;
    t->right = newNode->left;
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
    newNode->left = t;
    newNode->height = max(heightOrNeg1(newNode->left), heightOrNeg1(newNode->right))+1;
    t=newNode;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    Node* newNode = t->left;
    t->left = newNode->right;
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
    newNode->right = t;
    newNode->height = max(heightOrNeg1(newNode->left), heightOrNeg1(newNode->right))+1;
    t=newNode;	
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{	

	int balance = heightOrNeg1(subtree->left) - heightOrNeg1(subtree->right);
	if (balance>1){
		//left tree heavier than right
		if (heightOrNeg1(subtree->left->left) > heightOrNeg1(subtree->left->right)){
			//LeftLeft situation
			rotateRight(subtree);
		}
		if (heightOrNeg1(subtree->left->left) < heightOrNeg1(subtree->left->right)){
			//LeftRight situation
			rotateLeftRight(subtree);
		}
	}

	if (balance < -1){
		//right tree heavier than left
		if (heightOrNeg1(subtree->right->right) > heightOrNeg1(subtree->right->left)){
			//rightright situation
			rotateLeft(subtree);
		}
		if (heightOrNeg1(subtree->right->right) < heightOrNeg1(subtree->right->left)){
			//rightleft situation
			rotateRightLeft(subtree);
		}
	
	}

	subtree->height = 1 + max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
	if (subtree==NULL){
		subtree = new Node(key,value);
	}else{
		if (key < subtree->key){
			insert(subtree->left,key,value);
		}else{
			insert(subtree->right,key,value);
		}
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
    int res=0;
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        remove(subtree->right,key);
    } else {
        if (subtree->left == NULL || subtree->right == NULL) {
            /* no-child or one child remove */
            Node *temp = subtree->left ? subtree->left: subtree->right;
            if (temp == NULL){
                delete subtree; 
            }else{
                *subtree = *temp; 
                delete temp; 
            }
        }else{
            Node* temp = findMin(subtree->right);
            subtree->key = temp->key;
            subtree->value = temp->value;
            remove(subtree->right, temp->key);
        } 
	
    }

	rebalance(subtree);
}


