class Node{
    private:
        int val;
        Node *prev;
        Node *next;

    public:
        Node(int _val, Node *_prev, Node *_next){
            val = _val;
            prev = _prev;
            next = _next;
        }
        // deletes the node, and updates the next and previous nodes accordingly
        void deleteNode(){
            // update the "next" pointer for the previous node, if present
            if (next != NULL){
                next->setPrev(prev);
            }
            if (prev != NULL){
                prev->setNext(next);
            }
            // delete this node
            delete this;
        }
        // setter functions
        void setVal(int newVal){
            val = newVal;
        }
        void setNext(Node *node){
            next = node;
        }
        void setPrev(Node *node){
            prev = node;
        }
        // getter functions
        int getVal(){
            return val;
        }
        Node *getNext(){
            return next;
        }
        Node *getPrev(){
            return prev;
        }     
};
