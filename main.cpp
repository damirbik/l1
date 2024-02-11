#include <bits/stdc++.h>

using namespace std;

#define ll long long

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

bool ch;

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

    vector<int> ans(){
        vector<int>vc;
        if(is_empty()) { return vc; }
        Node* t = first;
        while(t){
            if(t->n > 0){
                vc.push_back(t->n);
            }
            t = t->next;
        }
    }
};

int main(int argc, char *argv[]){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    Stck st;
    string s;
    if(argc > 1){
        s = "true";
    }
    else{
        s = argv[1];
    }
    if(s == "true"){
        ch = 1;
    }
    if(ch){ cout << "Input values:\n"; }
    int n, i = 1;
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
    vector<int> vc = st.ans();
    for (int j = 0; j < vc.size(); ++j) {
        if(ch){ cout << 'n' << j + 1 << " = "; }
        cout << vc[j] << '\n';
    }
    return 0;
}