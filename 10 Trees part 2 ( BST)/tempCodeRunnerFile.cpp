Node* curr = root;
    while(curr and curr->right != NULL){
        curr = curr->right;
    }
    return curr;