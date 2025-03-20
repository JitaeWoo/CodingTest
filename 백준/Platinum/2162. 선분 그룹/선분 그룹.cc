#include <iostream>

class Segment{
public:
    std::pair<int, int> point1;
    std::pair<int, int> point2;
    
    Segment(int x1, int y1, int x2, int y2){
        this->point1 = std::make_pair(x1, y1);
        this->point2 = std::make_pair(x2, y2);
        
        if(point1 > point2){
            std::pair<int, int> temp = point1;
            point1 = point2;
            point2 = temp;
        }
    }
};

int CCW(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int> p3){
    std::pair<int, int> v1 = std::make_pair(p2.first - p1.first, p2.second - p1.second);
    std::pair<int, int> v2 = std::make_pair(p3.first - p2.first, p3.second - p2.second);
    
    int result = v1.first*v2.second - v1.second*v2.first;
    
    if(result > 0){
        return 1;
    }else if(result == 0){
        return 0;
    }else{
        return -1;
    }
}

bool is_cross(Segment s1, Segment s2){
    int ccw1 = CCW(s1.point1, s1.point2, s2.point1) * CCW(s1.point1, s1.point2, s2.point2);
    int ccw2 = CCW(s2.point1, s2.point2, s1.point1) * CCW(s2.point1, s2.point2, s1.point2);
    
    // 두 선분이 일직선 상에 있으면
    if(ccw1 == 0 && ccw2 == 0){
        return s1.point1 <= s2.point2 && s2.point1 <= s1.point2;
    }
    
    return ccw1 <= 0 && ccw2 <= 0;
}

class Segment_union{
    int * parent;
    int * parent_count;
    int N;

public:
    Segment_union(int N){
        this->N = N;
        this->parent = new int[N];
        this->parent_count = new int[N];
        
        for(int i = 0; i < N; i++){
            parent[i] = i;
            parent_count[i] = 1;
        }
    }
    
    int find(int x){
        if(parent[x] != x){
            return parent[x] = find(parent[x]);
        }else{
            return x;
        }
    }
    
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        
        if(x == y) return;
        
        if(x > y){
            parent[x] = y;
            parent_count[y] += parent_count[x];
            parent_count[x] = 0;
        }else{
            parent[y] = x;
            parent_count[x] += parent_count[y];
            parent_count[y] = 0;
        }
    }
    
    int max_count(){
        int max = 0;
        for(int i = 0; i < N; i++){
            int pc = parent_count[i];
            if(max < pc){
                max = pc;
            }
        }
        
        return max;
    }
    
    int union_count(){
        int result = 0;
        for(int i = 0; i < N; i++){
            int pc = parent_count[i];
            if(pc != 0){
                result++;
            }
        }
        
        return result;
    }
};

int main(){
    int N = 0;
    std::cin >> N;
    
    Segment *sm[N];
    Segment_union sm_u = Segment_union(N);
    for(int i = 0; i < N; i++){
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        std::cin >> x1 >> y1 >> x2 >> y2;
        
        sm[i] = new Segment(x1, y1, x2, y2);
    }
    
    for(int i = 0; i < N - 1; i++){
        for(int j = i+1; j < N; j++){
            if(sm_u.find(i) != sm_u.find(j)){
                if(is_cross(*(sm[i]), *(sm[j]))){
                    sm_u.merge(i, j);
                }
            }
        }
    }
    
    std::cout << sm_u.union_count() << "\n";
    std::cout << sm_u.max_count() << "\n";
    
    return 0;
}