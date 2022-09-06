
#include<bits/stdc++.h>
using namespace std;

void heapify_bottom_to_root(vector <int> &tree,int at){
    int parent=at/2;
    if(parent==0) return;
    if(tree[at]>tree[parent]){
        swap(tree[at],tree[parent]);
        heapify_bottom_to_root(tree,parent);
    }
}

void insert(vector <int> &tree,int number){
    tree.push_back(number);
    heapify_bottom_to_root(tree,tree.size()-1);
}

void heapify_root_to_bottom(vector <int> &tree,int at){
    int left=2*at;
    int right=2*at+1;

    if(left<tree.size()&&tree[left]>=tree[right]&&tree[left]>tree[at]){
        swap(tree[left],tree[at]);
        heapify_root_to_bottom(tree,left);
    }else if(right<tree.size()&&tree[right]>tree[left]&&tree[right]>tree[at]){
        swap(tree[right],tree[at]);
        heapify_root_to_bottom(tree,right);
    }
}
int pop(vector <int> &tree){
    if(tree.size()==1) return -1;
    int max= tree[1];
    tree[1]=tree.back();
    tree.erase(tree.end()-1);
    heapify_root_to_bottom(tree,1);
    return max;
}

int top(vector <int> tree){
    if(tree.size()==1) return -1;
    return tree[1];
}

/*Main function*/
int main()
{
    vector <int> arr={2,7,19,25,26,17,1,90,3,36};
    vector <int> tree(1);

    int i=1;
    for(auto a:arr){
        insert(tree,a);
        ++i;
    }

    int top=0;
    while((top=pop(tree))!=-1){
        cout<<top<<endl;
    }
    return 0;
}
