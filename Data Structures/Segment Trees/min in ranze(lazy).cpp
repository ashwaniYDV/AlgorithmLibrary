ll arr[N], tree[4 * N], lazy[4 * N];
 
void build(ll node, ll start, ll end) {
    if(start == end){
    	tree[node] = arr[start];
    	return;
    }
    ll mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}
 
void update(ll node, ll start, ll end, ll l, ll r, ll val){
    if(lazy[node] != 0){
    tree[node] += lazy[node];
    if(start != end){
        lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l>end || r<start || l>r) return;
    if(l<=start && end<=r){
        tree[node]+=val;
        if(start != end){
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        lazy[node]=0;
        return;
    }
    ll mid=(start+end)/2;
    update(2*node,start,mid,l,r,val);
    update(2*node+1,mid+1,end,l,r,val);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}
 
ll query(ll node, ll start, ll end, ll l, ll r){
    if(lazy[node] != 0){
	tree[node] += lazy[node];
	if(start != end){
		lazy[2*node] += lazy[node];
		lazy[2*node+1] += lazy[node];
	}
	lazy[node] = 0;
    }
    if(l>end || r<start || l>r)return INT_MAX;
    if(l<=start && end<=r) return tree[node];
    ll mid=(start+end)/2;
    return min(query(2*node,start,mid,l,r), query(2*node+1,mid+1,end,l,r));
}
