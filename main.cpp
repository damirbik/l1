#include <bits/stdc++.h>

using namespace std;

#define ll long long

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct Node{
    int n;
    Node* next;
    Node(int _n) : n(_n), next(nullptr){}
};

struct Stck{
    Node* first;

    Stck() : first(nullptr) {}

    bool is_empty(){
        return first == nullptr;
    }

    void insert(int n){
        Node* t = new Node(n);
        t->next = first;
        first = t;
    }

    int top(){
        if(is_empty()) { cout << "error, stack is empty\n"; }
        Node* t = first;
        return t->n;
    }

    void pop(){
        if(is_empty()) { return; }
        Node* t = first;
        first = t->next;
        delete t;
    }
};

int main(int argc, char *argv[]){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    Stck st;
    string s;
    bool ch = 1;
    if(argc > 1){
        s = argv[1];
    }
    if(s == "false"){
        ch = 0;
    }
    if(ch){ cout << "Input values:\n"; }
    int n, i = 1, it = 1;
    while(1){
        if(ch){ cout << 'n' << i << " ="; }
        cin >> n;
        if(!n){
            break;
        }
        st.insert(n);
        i++;
    }
    if(ch){ cout << "Aanswer is:\n"; }
    for (int j = 0; j < i - 1; ++j) {
        int ans = st.top();
        if(ans > 0){
            if(ch){ cout << 'n' << it << " = "; }
            cout << ans << '\n';
        }
        st.pop();
    }
    return 0;
}
