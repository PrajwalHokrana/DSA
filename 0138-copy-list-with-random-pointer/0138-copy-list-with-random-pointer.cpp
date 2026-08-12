/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return NULL;
        }
        unordered_map<Node*,Node*> m;

        Node*head1=new Node(head->val);
        m[head]=head1;
        Node*temp1=head->next;
        Node*temp2=head1;
        while(temp1!=NULL)
        {
            temp2->next=new Node(temp1->val);
            temp2=temp2->next;
            m[temp1]=temp2;
            temp1=temp1->next;
        }

        temp1=head;
        temp2=head1;

        while(temp1!=NULL)
        {
            temp2->random=m[temp1->random];
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return head1;
    }
};