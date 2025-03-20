#include <iostream>
#define Point std::pair<int, int>

double area(Point p1, Point p2, Point p3){
    // p1을 시작점으로 벡터 두개 작성
    long long x1 = p2.first - p1.first;
    long long y1 = p2.second - p1.second;
    long long x2 = p3.first - p1.first;
    long long y2 = p3.second - p1.second;
    
    //외적으로 넓이 계산
    double result = (double)(x1*y2 - x2*y1) / 2.0;
    
    
    return result;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    std::cin >> N;
    
    Point point[N];
    for(int i = 0; i < N; i++){
        std::cin >> point[i].first >> point[i].second;
    }
    
    double result = 0;
    for(int i = 1; i < N-1; i++){
        result += area(point[0], point[i], point[i+1]);
    }
    
    if(result < 0){
        result *= -1;
    }
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << result << "\n";
    
    return 0;
}