/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 void sum(int n1,int n2,int *carry,int *d){
    int resul = n1 + n2 + *carry;
    if(resul >= 10){
        *d = resul % 10;
        if(n1 == 9 && n2 == 0 || n2 == 9 && n1 == 0) *carry = 1;
        else
        *carry = resul / 10;
    }
    else{
        *d = resul;
        *carry = 0;
    }
 }
 void atras(int d,struct ListNode** l,struct ListNode** ult){
    struct ListNode *aux = (struct ListNode*)malloc(sizeof(struct ListNode));
    aux->val = d;
    aux->next = NULL;

    if(*l == NULL){
        *l = aux;
    }
    else {
        (*ult)->next = aux;
    }
    *ult = aux;
    
 }
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* fin = NULL;
    struct ListNode* ult = NULL;
    int carry = 0;
    int d = 0;
    while(l1 != NULL || l2 != NULL){
        if(l1 != NULL && l2 != NULL){
            sum(l1->val,l2->val,&carry,&d);
        }
        else {
            if(l1 != NULL && l2 == NULL) sum(l1->val,0,&carry,&d);
            else sum(0,l2->val,&carry,&d);
        }
        atras(d,&fin,&ult);
        if(l1 != NULL)
        l1 = l1->next;
        if(l2 != NULL)
        l2 = l2->next;
    }
    if(carry != 0){
        atras(carry,&fin,&ult);
        carry = 0;
    }
    return fin;
    
    
}
