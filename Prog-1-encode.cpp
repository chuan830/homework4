#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node{
    char data;
    int freq;
    string code;
    Node *left;
    Node *right;

};

Node extractMin(int *freq)
{
    int i=0;
    int smallest;
    int s_index;
    int tmp;
    while(freq[i]>0){
        if(freq[i]<smallest){
            smallest=freq[i];
            s_index=i;
        }
        i++;
    }
    tmp=s_index;
    while(freq[tmp]>0){
        freq[tmp]=freq[tmp+1];
        tmp++;
    }
    return s_index;

}

Node getHuffmanCode(int *freq,int d_c)
{
    int flag=0;
    while(1){
        for(int i=0;i<dc;i++){
            if(freq[i]>0)
              flag++;
        }
        if(flag==0)
            break;
        else{
            Node *tempNode = new Node;
            Node *tempNode1 = new Node;
            Node *tempNode2 = new Node;
            tempNode1->freq=

        }
    }
}

int main(){
    Node A[10000];
    char tmp;
    int num_of_dif_char=0;
    int flag=0;
    int freq[9999];

    while(cin>>tmp){
        if(tmp=='x'){
            break;
        }
        for(int i=0;i<num_of_dif_char;i++){
            if(tmp==A[i].data){
                A[i].freq++;
                flag=1;
                break;
            }
        }
        if(flag==0){
            A[num_of_dif_char].data=tmp;
            A[num_of_dif_char].freq++;
            num_of_dif_char++;
        }
        else
            flag=0;
    }

    for(int i=0;i<num_of_dif_char;i++){
        freq[i]=A[i].freq;
    }


}
