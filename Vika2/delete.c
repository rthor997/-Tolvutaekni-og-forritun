/***************************************************************
  Beinagrind að lausn á dæmi 5 í heimadæmum 2 í Tölvutækni
  og forritun, haust 2022
  
  Sjá lýsingu verkefnis á dæmablaði 
****************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};


/* Prentar út stökin í tengdum list */
void printList(struct Node *h) {
	printf("Listi: ");
	while (h != NULL) {
		printf("%d", h->data);
		h = h->next;
        if (h != NULL) printf(" -> ");
	}
	printf("\n");
}


/* Eyðir hnúti númer k í tengda listanum sem head bendir á.
   Skilar bendi á fremsta hnút listans                     */
struct Node* delNode(struct Node* head, int k) {
    /* ef ekkert er að eyða*/
    if (head == NULL || k<1) return head;

    struct Node* temp = head;
    /* ef k er ein eyða fyrsta hnút*/
    if (k == 1) {
        head = head->next;
        free(temp);
        return head;
    }
    /* fara að hnútinum á undan honum sem á að eyða*/
    for (int i = 1; temp != NULL && i < k-1; i++) {
        temp = temp->next;
    }
    /* ef k er of stórt*/
    if (temp == NULL || temp->next == NULL) return head;

    /* Eyða hnútinum með að fara yfir hann og svo losa hann */
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    

    return head;
}
        

/* Býr til n-staka lista með slembigildum (0 til 99),
   skilar bendi á fremsta hnút, eða NULL ef n < 1 */
struct Node* createList(int n) {
    struct Node *head, *p;
    int i;

    /* Ef n er núll eða minna þá tómur listi */
    if (n < 1) return NULL;
    
    /* Búa til fyrsta hnútinn og láta head benda á hann */
    head = p = (struct Node *)malloc(sizeof(struct Node));
    head->data = rand()%100;
    head->next = NULL;
    
    /* Búa til restina af hnútunum */
    for(i=1; i<n; i++) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = rand()%100;
        p->next = head;
        head = p;
    }
    
    return head;
}


int main(int argc, char **argv) {
    struct Node *list;
	
    /* Búa til listann með 10 slembigildum */
    list = createList(10);
    printList(list);

    /* Eyða út nokkrum hnútum og skoða listann í hvert sinn */
    list = delNode(list, 1);
    printList(list);

    list = delNode(list, 3);
    printList(list);

    list = delNode(list, 20);
    printList(list);
    
    return 0;
}
