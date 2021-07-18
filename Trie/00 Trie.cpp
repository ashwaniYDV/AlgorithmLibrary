struct trie {
    bool isLeaf;
    unordered_map<char, trie*> map;
    trie(){
        isLeaf=false;
    }
};

trie* head = nullptr;

void insert(trie*& head, string str){
    if(head == nullptr){
        head = new trie();
    }
    trie* curr = head;
    for(char x: str){
        if(!curr->map[x]){
            curr->map[x] = new trie();
        }
        curr = curr->map[x];
    }
    curr->isLeaf  =true;
}

bool search(trie* head, string str){
    if(head == nullptr) return false;
    trie* curr = head;
    for(char x: str){
        if(curr==nullptr || !curr->map[x]){
            return false;
        }
        curr = curr->map[x];
    }
    return curr->isLeaf;
}

bool haveChildren(trie const* curr){
    for(auto it: curr->map){
        if(it.second != nullptr){
            return true;
        }
    }
    return false;
}

bool deletion(trie*& curr, char* str){
    if(curr == nullptr) return false;

    if(*str){
        if(curr!=nullptr && curr->map[(*str)] && deletion(curr->map[*str], str+1) && curr->isLeaf==false){
            if(!haveChildren(curr)){
                delete curr;
                curr=nullptr;
                return true;
            }else{
                return false;
            }
        }
    }
    if(*str=='\0' && curr->isLeaf){
        if(!haveChildren(curr)){
            delete curr;
            curr=nullptr;
            return true;
        }else{
            curr->isLeaf=false;
            return false;
        }
    }
    return false;
}


int32_t main()
{
    IOS
    ll t,k,x,y,z,p,q,u,v,ct=0,flag=0;
    cin>>n;
    string s;
    f(i,n){
        cin>>s;
        insert(head, s);
    }
    s="ashwani";
    cout<<(search(head, s)? "Found" : "Not Found")<<endl;
    deletion(head, const_cast<char*>(s.c_str()));
    cout<<(search(head, s)? "Found" : "Not Found")<<endl;
    s="killer";
    cout<<(search(head, s)? "Found" : "Not Found")<<endl;
    deletion(head, const_cast<char*>(s.c_str()));
    cout<<(search(head, s)? "Found" : "Not Found")<<endl;
}
