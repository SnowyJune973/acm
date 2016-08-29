    #include <cstdio>  
    #include <cstdlib>  
    #include <cstring>  
    #include <algorithm>  
    #include <iostream>  
    #include <stack>  
    #include <queue>  
    #include <deque>  
    #include <set>  
    #include <vector>  
    #include <map>  
    using namespace std;  
    #define int64 long long 
    #define lson l,m,rt<<1  
    #define rson m+1,r,rt<<1|1  
	#define I64d lld
    const int maxn = 200000;  
    struct node{  
        int64 l;  
        int64 r;  
        int64 sum;  
        bool laz;  
        //int64 mid(){  
        //  return (l+r)/2;  
        //}  
    };  
    struct node tree[maxn<<2];  
    set<int64> ss;  
    int64 f[10000];  
      
    void PushUp(int64 rt){  
        if(tree[rt<<1].laz==1 && tree[rt<<1|1].laz==1){//如果两个子节点都不需要更新，那么父节点也不需要跟新  
            tree[rt].laz = 1;  
        }  
        else{  
            tree[rt].laz = 0;  
        }  
    }  
    void getf(){  
        int i;  
        f[0] = 1;  
        f[1] = 1;  
        ss.insert(f[0]);  
        ss.insert(f[1]);  
        for(i=2;i<=73;i++){  
            f[i] = f[i-1]+f[i-2];  
            ss.insert(f[i]);  
        }  
    }  
      
    void build(int64 l,int64 r,int64 rt){  
        tree[rt].l = l;  
        tree[rt].r = r;  
        tree[rt].laz = 0;  
        if(tree[rt].l == tree[rt].r){  
            tree[rt].sum = 0;  
            return ;  
        }  
        int64 m = (tree[rt].l+tree[rt].r)/2;  
        build(lson);  
        build(rson);  
        tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;  
    }  
      
      
      
      
      
    void update(int64 a,int64 b,int64 rt){  
        if(tree[rt].l == tree[rt].r){  
            tree[rt].sum+=b;  
            tree[rt].laz = 0;  
            return ;  
        }  
        int64 m = (tree[rt].l+tree[rt].r)/2;  
        if(a <= m){  
            update(a,b,rt<<1);  
        }  
        else{  
            update(a,b,rt<<1|1);  
        }  
        tree[rt].sum = tree[rt<<1].sum+tree[rt<<1|1].sum;  
        PushUp(rt);  
    }  
      
    void update2(int64 L,int64 R,int64 rt){  
        if(tree[rt].laz == 1){  
            return ;  
        }  
        if(tree[rt].l == tree[rt].r){  
            tree[rt].laz = 1;  
            set<int64>::iterator it1,it2;  
            int64 l,r;  
            it2=it1=ss.lower_bound(tree[rt].sum);//获得》=tree[rt].sum这个数在斐波那契数列中的地址  
            l = *it2;  
            if(it1 != ss.begin()){  
                it1--;  
            }  
            r = *it1;  
            tree[rt].sum = (tree[rt].sum-*it1)>((*it2)-tree[rt].sum)?l:r;  
              
            return ;  
        }  
        int64 m = (tree[rt].l + tree[rt].r)/2;  
        if(L<=m){  
            update2(L,R,rt<<1);  
        }  
        if(R > m){  
            update2(L,R,rt<<1|1);  
        }  
        tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;  
        PushUp(rt);  
    }  
      
    int64 query(int64 L,int64 R,int64 rt){  
        if(L<=tree[rt].l && tree[rt].r<=R){  
            return tree[rt].sum;  
        }  
        int64 m = (tree[rt].l+tree[rt].r)/2;  
        int64 ret = 0;  
        if(L <= m){  
            ret+=query(L,R,rt<<1);  
        }  
        if(R > m){  
            ret+=query(L,R,rt<<1|1);  
        }  
        //else  
        //{  
        //  ret+=query(L,R,rt<<1);  
        //  ret+=query(L,R,rt<<1|1);  
        //}  
          
        return ret;  
    }  
      
    int main(){ 
		freopen("data","r",stdin);
		freopen("standard","w",stdout);
        int64 n,m;  
        int64 op,a,b;  
        ss.clear();  
        getf();  
          
        while(~scanf("%lld%lld",&n,&m)){  
            build(1,n,1);  
            while(m--){  
                scanf("%lld",&op);  
                if(op == 2){  
                    scanf("%lld%lld",&a,&b);  
                    printf("%lld\n",query(a,b,1));  
                }  
                else if(op == 1){  
                    scanf("%lld%lld",&a,&b);  
                    update(a,b,1);  
                }  
                else if(op == 3){  
                    scanf("%lld%lld",&a,&b);  
                    update2(a,b,1);  
                }  
            }  
              
        }  
          
        return 0;  
    }  
