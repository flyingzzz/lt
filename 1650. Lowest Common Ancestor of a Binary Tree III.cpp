class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int len1 = 0, len2 = 0;
        Node* tmp1 = p; 
        Node* tmp2 = q;
        Node* lon = NULL;
        Node* sht = NULL;
        while(tmp1 != NULL) {
            len1++;
            tmp1 = tmp1->parent;
        }
        while(tmp2 != NULL) {
            len2++;
            tmp2 = tmp2->parent;
        }
        if(len1 > len2) {
            lon = p;
            sht = q;
        } else {
            lon = q;
            sht = p;
        }
        //move long first
        for(int i = 0; i < abs(len1 - len2); i++) {
            lon = lon->parent;
        }
        while(lon != sht) {
            lon = lon->parent;
            sht = sht->parent;
        }
        return lon;
    }
};
