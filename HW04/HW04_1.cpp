
#include "env.h"
#include <algorithm>

using namespace std;

vector<pair<int,int>> Connect(int N){
    vector<bool> visit(N,false);
    vector<pair<int,int>> result;
    vector<int> A1(N,-1),A2(N,-1),B1(N,-1),B2(N,-1);
    int a=-1,b=-1,c=-1,S;

    S = (N%2)?N-1:N-3;

    clean_wires();
    for(int i=0;i<S;i+=2){
        link_wire(i,i+1);
        A1[i]=i+1;
        A1[i+1]=i;
    }

    move_to_opposite();

    clean_wires();
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(check_connectivity(i,j)){
                B1[i]=j;
                B1[j]=i;
                visit[i]=visit[j]=true;
            }
        }
    }

    if(N%2){
        a=N-1;
        for(int i=0;i<N;i++){
            if(!visit[i]){
                b=i;
                break;
            }
        }
    }
    else{
        vector<int> unvisit;
        for(int i=0;i<N;i++){
            if(!visit[i]) unvisit.push_back(i);
        }
        b=unvisit[0];
        c=unvisit[1];
    }

    vector<int> B1_node;
    for(int i=0;i<N;i++){
        if(B1[i]!=-1 && i < B1[i]){
            B1_node.push_back(i);
        }
    }

    B2[b] = B1_node[0];
    link_wire(b,B1_node[0]);

    for(size_t i=0;i+1 < B1_node.size();i++){
        int u = B1[B1_node[i]];
        int v = B1_node[i+1];
        B2[u]=v;
        link_wire(u,v);
    }

    move_to_opposite();
    clean_wires();

    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(check_connectivity(i,j)){
                A2[i]=j;
                A2[j]=i;
            }
        }
    }
    if(N%2){
        result.emplace_back(a,b);
    }
    else{
        for(int i=N-2;i<=N-1;i++){
            for(int j=0;j<N;j++){
                if(i!=j && check_connectivity(i,j)){
                    result.emplace_back(i,b);
                    result.emplace_back((i == N - 2 ? N - 1 : N - 2), c);
                    a=i;
                    break;
                }
            }
        }
    }
    
    while(result.size() < static_cast<size_t>(N)){
        int l = A2[a];
        int r = B2[b];

        result.emplace_back(l,r);
        a=l; b=r;

        l=A1[a]; r=B1[b];

        result.emplace_back(l,r);
        a=l; b=r;
    }

    sort(result.begin(),result.end());
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    
    while (T--) {
        int N;
        std::cin >> N;

        vector<pair<int,int>> result = Connect(N);
        answer(result);
    }

    return 0;
}
